/******************************************************************************
 FILE:	 module.h
 DESC:   Load module and wrap it for JavaScript.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#ifndef __JS_CFLOW_MODULE_H__
#define __JS_CFLOW_MODULE_H__

#include "config.h"
#include "js-cflow.h"
#include "3rd/duktape/duktape.h"
#include "utils/text_list.h"

typedef enum  {
	kJsCFlowTypeBool	= 0,
	kJsCFlowTypeVoid	= 1,
	kJsCFlowTypeString	= 2,
	kJsCFlowTypeNumber	= 3,
	kJsCFlowTypePoint	= 4,
} JsCFlowType;


typedef struct {
	void *handle;
} JsCFlowModule;


typedef struct {
	void *api_address;
	const char *api_name;
	JsCFlowType return_type;
	JsCFlowTextList args_list;
} JsCFlowModuleAPI;


JsCFlowResult js_cflow_load_module(JsCFlowModule *_module, const char *_path);

JsCFlowResult js_cflow_unload_module(JsCFlowModule *_module);

JsCFlowResult js_cflow_load_module_api(JsCFlowModule *_module, const char *_api_name, FARPROC *_api_address);

duk_ret_t js_cflow_call_api(
	duk_context *_duk_ctx,
	const char *_dll_name,
	const char *_api_name,
	duk_int_t _retval_type,
	duk_idx_t _api_argc,
	duk_idx_t _base_index
	);

#endif /* __JS_CFLOW_MODULE_H__ */