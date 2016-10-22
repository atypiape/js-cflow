/******************************************************************************
 FILE:	 js-cflow.c
 DESC:   JS-CFlow main source file.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#include "js-cflow.h"
#include <assert.h>


W2X_EXTERN_C JS_CFLOW_API
JsCFlowResult js_cflow_start(const char *_js_file_path)
{
	assert(_js_file_path);
	if (NULL == _js_file_path) {
		return kJsCFlowResultInvalidArguments;
	}

	return kJsCFlowResultSucceed;
}
