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
} JsCFlowResult;


W2X_EXTERN_C JS_CFLOW_API
JsCFlowResult js_cflow_start(const char *_js_file_path);


#endif /* __JS_CFLOW_H__ */