/******************************************************************************
 FILE:	 js-cflow.c
 DESC:   JS-CFlow main source file.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#include "js-cflow.h"
#include <assert.h>
#include "3rd/duktape/duktape.h"
#include "utils/file_sys.h"
#include "utils/text_list.h"


struct {
	JsCFlowTextList *js_files;
} js_cflow_global = {0};


static JsCFlowResult js_cflow_execute_js(const char *_js_file);
static JsCFlowResult js_cflow_push_api(duk_context *_duk_ctx);
static duk_ret_t js_cflow_on_import_scripts(duk_context *_duk_ctx);


EXTERN_C JS_CFLOW_API
JsCFlowResult js_cflow_start(const char *_js_file)
{
	JsCFlowResult result = js_cflow_path_exists(_js_file);
	if (kJsCFlowResultSucceed != result) {
		return result;
	}

	if (false == js_cflow_text_list_create(&(js_cflow_global.js_files))) {
		return kJsCFlowResultAllocMemoryError;
	}

	js_cflow_text_list_add(js_cflow_global.js_files, _js_file);

	result = js_cflow_execute_js(_js_file);

	js_cflow_text_list_destory(&(js_cflow_global.js_files));

	return kJsCFlowResultSucceed;
}


static JsCFlowResult js_cflow_execute_js(const char *_js_file)
{
	char *js_str = NULL;
	JsCFlowResult result = kJsCFlowResultSucceed;

	duk_context *duk_ctx = duk_create_heap_default();
	assert(duk_ctx);
	if (NULL == duk_ctx) {
		return kJsCFlowResultHeapCreateFailed;
	}

	result = js_cflow_push_api(duk_ctx);
	if (JsCFlowFailed(result)) {
		duk_destroy_heap(duk_ctx);
		return result;
	}

	result = js_cflow_read_file_content((void **)&js_str, _js_file);
	if (JsCFlowFailed(result)) {
		return result;
	}
	if (NULL == js_str) {
		return result;
	}

	if (0 != duk_peval_string(duk_ctx, js_str)) {
		js_cflow_free_file_content(js_str);
		perror(duk_safe_to_string(duk_ctx, -1));
		return kJsCFlowResultScriptError;
	}
	duk_pop(duk_ctx);
	js_cflow_free_file_content(js_str);

	duk_destroy_heap(duk_ctx);

	return kJsCFlowResultSucceed;
}


static JsCFlowResult js_cflow_push_api(duk_context *_duk_ctx)
{
	duk_push_c_function(_duk_ctx, js_cflow_on_import_scripts, DUK_VARARGS);
	duk_put_global_string(_duk_ctx, "importScripts");

	return kJsCFlowResultSucceed;
}


static duk_ret_t js_cflow_on_import_scripts(duk_context *_duk_ctx)
{
	char *js_str = NULL;
	const char *file_path = NULL;
	char (*file_pathes)[MAX_PATH] = NULL;
	JsCFlowResult result = kJsCFlowResultSucceed;

	duk_idx_t i = 0;
	duk_idx_t argc = duk_get_top(_duk_ctx);
	if (0 == argc) {
		return kJsCFlowResultInvalidArguments;
	}

	file_pathes = (char (*)[MAX_PATH])malloc(argc * MAX_PATH);
	for (i = 0; i < argc; ++i) {
		file_path = duk_require_string(_duk_ctx, i);
		strcpy(file_pathes[i], file_path);
	}
	duk_pop(_duk_ctx);

	for (i = 0; i < argc; ++i) {
		file_path = file_pathes[i];
		if (js_cflow_text_list_has(js_cflow_global.js_files, file_path)) {
			continue; // ignore self
		}
		js_cflow_text_list_add(js_cflow_global.js_files, file_path);

		result = js_cflow_read_file_content((void **)&js_str, file_path);
		if (JsCFlowFailed(result)) {
			continue;
		}

		if (0 != duk_peval_string(_duk_ctx, js_str)) {
			js_cflow_free_file_content(js_str);
			perror(duk_safe_to_string(_duk_ctx, -1));
			continue;
		}
		duk_pop(_duk_ctx);
		js_cflow_free_file_content(js_str);
	}

	free(file_pathes);
	return 0;
}


