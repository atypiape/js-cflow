/******************************************************************************
 FILE:	 module.h
 DESC:   Load module and wrap it for JavaScript.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#include "module.h"
#include <assert.h>
#include "3rd/duktape/duktape.h"
#include "utils/file_sys.h"


typedef void * (*FARPROC_0)();
typedef void * (*FARPROC_1)(void *);
typedef void * (*FARPROC_2)(void *, void *);
typedef void * (*FARPROC_3)(void *, void *, void *);
typedef void * (*FARPROC_4)(void *, void *, void *, void *);
typedef void * (*FARPROC_5)(void *, void *, void *, void *, void *);
typedef void * (*FARPROC_6)(void *, void *, void *, void *, void *, void *);
typedef void * (*FARPROC_7)(void *, void *, void *, void *, void *, void *, void *);
typedef void * (*FARPROC_8)(void *, void *, void *, void *, void *, void *, void *, void *);
typedef void * (*FARPROC_9)(void *, void *, void *, void *, void *, void *, void *, void *, void *);


static void * js_cflow_require_arg(duk_context *_duk_ctx, duk_idx_t _index)
{
	void *argval = NULL;

	switch (duk_get_type(_duk_ctx, _index)) {
	case DUK_TYPE_NONE:
	case DUK_TYPE_NULL:
	case DUK_TYPE_UNDEFINED:
		break;

	case DUK_TYPE_BOOLEAN:
		argval = (void *)duk_require_boolean(_duk_ctx, _index);
		break;

	case DUK_TYPE_NUMBER:
		argval = (void *)duk_require_int(_duk_ctx, _index);
		break;

	case DUK_TYPE_STRING:
		argval = (void *)duk_require_string(_duk_ctx, _index);
		break;

	case DUK_TYPE_OBJECT:
	case DUK_TYPE_BUFFER:
	case DUK_TYPE_POINTER:
	case DUK_TYPE_LIGHTFUNC:
		argval = (void *)duk_require_pointer(_duk_ctx, _index);
		break;

	default:
		assert(0);
		break;
	}

	return argval;
}


duk_ret_t js_cflow_call_api(
	duk_context *_duk_ctx, const char *_dll_name,
	const char *_api_name, duk_int_t _retval_type,
	duk_idx_t _api_argc, duk_idx_t _base_index)
{
 	JsCFlowModule module = {0};
	FARPROC api_address = NULL;
	void *retval = 0;

	JsCFlowResult result = js_cflow_load_module(&module, _dll_name);
	if (JsCFlowFailed(result)) {
		return DUK_RET_INTERNAL_ERROR;
	}

	result = js_cflow_load_module_api(&module, _api_name, &api_address);
	if (JsCFlowFailed(result)) {
		js_cflow_unload_module(&module);
		return DUK_RET_INTERNAL_ERROR;
	}

	switch (_api_argc) {
	case 0:
		retval = (*(FARPROC_0)api_address)();
		break;

	case 1:
		retval = (*(FARPROC_1)api_address)(
			js_cflow_require_arg(_duk_ctx, _base_index + 0));
		break;

	case 2:
		retval = ((FARPROC_2)api_address)(
			js_cflow_require_arg(_duk_ctx, _base_index + 0),
			js_cflow_require_arg(_duk_ctx, _base_index + 1));
		break;

	case 3:
		retval = (*(FARPROC_3)api_address)(
			js_cflow_require_arg(_duk_ctx, _base_index + 0),
			js_cflow_require_arg(_duk_ctx, _base_index + 1),
			js_cflow_require_arg(_duk_ctx, _base_index + 2));
		break;
	case 4:
		retval = (*(FARPROC_4)api_address)(
			js_cflow_require_arg(_duk_ctx, _base_index + 0),
			js_cflow_require_arg(_duk_ctx, _base_index + 1),
			js_cflow_require_arg(_duk_ctx, _base_index + 2),
			js_cflow_require_arg(_duk_ctx, _base_index + 3));
		break;

	case 5:
		retval = (*(FARPROC_5)api_address)(
			js_cflow_require_arg(_duk_ctx, _base_index + 0),
			js_cflow_require_arg(_duk_ctx, _base_index + 1),
			js_cflow_require_arg(_duk_ctx, _base_index + 2),
			js_cflow_require_arg(_duk_ctx, _base_index + 3),
			js_cflow_require_arg(_duk_ctx, _base_index + 4));
		break;

	case 6:
		retval = (*(FARPROC_6)api_address)(
			js_cflow_require_arg(_duk_ctx, _base_index + 0),
			js_cflow_require_arg(_duk_ctx, _base_index + 1),
			js_cflow_require_arg(_duk_ctx, _base_index + 2),
			js_cflow_require_arg(_duk_ctx, _base_index + 3),
			js_cflow_require_arg(_duk_ctx, _base_index + 4),
			js_cflow_require_arg(_duk_ctx, _base_index + 5));
		break;

	case 7:
		retval = (*(FARPROC_7)api_address)(
			js_cflow_require_arg(_duk_ctx, _base_index + 0),
			js_cflow_require_arg(_duk_ctx, _base_index + 1),
			js_cflow_require_arg(_duk_ctx, _base_index + 2),
			js_cflow_require_arg(_duk_ctx, _base_index + 3),
			js_cflow_require_arg(_duk_ctx, _base_index + 4),
			js_cflow_require_arg(_duk_ctx, _base_index + 5),
			js_cflow_require_arg(_duk_ctx, _base_index + 6));
		break;

	case 8:
		retval = (*(FARPROC_8)api_address)(
			js_cflow_require_arg(_duk_ctx, _base_index + 0),
			js_cflow_require_arg(_duk_ctx, _base_index + 1),
			js_cflow_require_arg(_duk_ctx, _base_index + 2),
			js_cflow_require_arg(_duk_ctx, _base_index + 3),
			js_cflow_require_arg(_duk_ctx, _base_index + 4),
			js_cflow_require_arg(_duk_ctx, _base_index + 5),
			js_cflow_require_arg(_duk_ctx, _base_index + 6),
			js_cflow_require_arg(_duk_ctx, _base_index + 7));
		break;

	case 9:
		retval = (*(FARPROC_9)api_address)(
			js_cflow_require_arg(_duk_ctx, _base_index + 0),
			js_cflow_require_arg(_duk_ctx, _base_index + 1),
			js_cflow_require_arg(_duk_ctx, _base_index + 2),
			js_cflow_require_arg(_duk_ctx, _base_index + 3),
			js_cflow_require_arg(_duk_ctx, _base_index + 4),
			js_cflow_require_arg(_duk_ctx, _base_index + 5),
			js_cflow_require_arg(_duk_ctx, _base_index + 6),
			js_cflow_require_arg(_duk_ctx, _base_index + 7),
			js_cflow_require_arg(_duk_ctx, _base_index + 8));
		break;

	default:
		assert(0);
		break;
	}
	
	js_cflow_unload_module(&module);

	switch (_retval_type) {
	case DUK_TYPE_NONE:
	case DUK_TYPE_UNDEFINED:
	case DUK_TYPE_NULL:
		return 0;

	case DUK_TYPE_BOOLEAN:
		duk_push_boolean(_duk_ctx, (duk_bool_t)retval);
		return 1;

	case DUK_TYPE_NUMBER:
		duk_push_int(_duk_ctx, (duk_int_t)retval);
		return 1;

	case DUK_TYPE_STRING:
		duk_push_string(_duk_ctx, (const char *)retval);
		return 1;

	case DUK_TYPE_OBJECT:
	case DUK_TYPE_BUFFER:
	case DUK_TYPE_POINTER:
	case DUK_TYPE_LIGHTFUNC:
		duk_push_pointer(_duk_ctx, (void *)retval);
		return 1;
	}
	
	return 0;
}


JsCFlowResult js_cflow_load_module(JsCFlowModule *_module, const char *_path)
{
	HMODULE handle = NULL;
	JsCFlowResult result = kJsCFlowResultSucceed;

	assert(_module);
	if (NULL == _module) {
		return kJsCFlowResultInvalidArguments;
	}
	if (NULL != _module->handle) {
		handle = (HMODULE)(_module->handle);
		assert(NULL == handle);
		if (NULL != handle) {
			FreeLibrary(handle);
			handle = NULL;
			_module->handle = NULL;
		}
	}

	assert(_path);
	if (NULL == _path) {
		return kJsCFlowResultInvalidArguments;
	}

	result = js_cflow_path_exists(_path);
	JsCFlowAssert(result);
	if (JsCFlowFailed(result)) {
		return result;
	}

	handle = LoadLibraryA(_path);
	assert(handle);
	if (NULL == handle) {
		return kJsCFlowResultSystemCallError;
	}

	_module->handle = (void *)handle;

	return kJsCFlowResultSucceed;
}


JsCFlowResult js_cflow_unload_module(JsCFlowModule *_module)
{
	assert(_module);
	if (NULL == _module) {
		return kJsCFlowResultInvalidArguments;
	}

	if (NULL != _module->handle) {
		FreeLibrary((HMODULE)(_module->handle));
		_module->handle = NULL;
	}

	return kJsCFlowResultSucceed;
}


JsCFlowResult js_cflow_load_module_api(
	JsCFlowModule *_module, const char *_api_name, FARPROC *_api_address)
{
	assert(_api_address);
	if (NULL == _api_address) {
		return kJsCFlowResultInvalidArguments;
	}
	*_api_address = GetProcAddress((HMODULE)(_module->handle), _api_name);
	assert(*_api_address);
	if (NULL == *_api_address) {
		return kJsCFlowResultSystemCallError;
	}

	return kJsCFlowResultSucceed;
}