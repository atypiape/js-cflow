/******************************************************************************
 FILE:	 js-cflow.h
 DESC:   JS-CFlow main header file.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#ifndef __JS_CFLOW_H__
#define __JS_CFLOW_H__

#include "config.h"


typedef enum {
	kJsCFlowResultSucceed			= 0,
	kJsCFlowResultInvalidArguments	= 1,
	kJsCFlowResultPathNotExist		= 2,
	kJsCFlowResultFileOpenError		= 3,
	kJsCFlowResultFileReadError		= 4,
	kJsCFlowResultHeapCreateFailed	= 5,
	kJsCFlowResultAllocMemoryError	= 6,
	kJsCFlowResultScriptError		= 7,
} JsCFlowResult;


#define JsCFlowFailed(_result) (kJsCFlowResultSucceed != (_result))
#define JsCFlowAssert(_result) assert(kJsCFlowResultSucceed == (_result))

/**
 * Use JavaScript to take over the main control flow.
 *
 * @param _js_file	path of js file.
 */
EXTERN_C JS_CFLOW_API
JsCFlowResult js_cflow_start(const char *_js_file);


#endif /* __JS_CFLOW_H__ */