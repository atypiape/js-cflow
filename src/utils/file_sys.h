/******************************************************************************
 FILE:	 file_sys.h
 DESC:   File system operation functions.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#ifndef __JS_CFLOW_FILE_SYS_H__
#define __JS_CFLOW_FILE_SYS_H__

#include "config.h"
#include "js-cflow.h"


JsCFlowResult js_cflow_path_exists(const char *_path);

JsCFlowResult js_cflow_read_file_content(void **_file_content, const char *_file_path);

void js_cflow_free_file_content(void *_file_content);


#endif // __JS_CFLOW_FILE_SYS_H__
