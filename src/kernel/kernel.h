/******************************************************************************
FILE:	kernel.h
DESC:   The kernel module for Js-CFlow.
AUTHOR: Atypiape
E-MAIL: atypiape@163.com
*******************************************************************************/

#ifndef __JS_CFLOW_KERNEL_H__
#define __JS_CFLOW_KERNEL_H__

#include "../config.h"

EXTERN_C JS_CFLOW_API
void * js_cflow_kernel_fopen(const char *_file_name, const char *_mode);

#endif /* __JS_CFLOW_KERNEL_H__ */