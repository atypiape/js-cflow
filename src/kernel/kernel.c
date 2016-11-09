/******************************************************************************
FILE:	kernel.h
DESC:   The kernel module for Js-CFlow.
AUTHOR: Atypiape
E-MAIL: atypiape@163.com
*******************************************************************************/

#include "kernel.h"
#include <stdio.h>

EXTERN_C JS_CFLOW_API
void * js_cflow_kernel_fopen(const char *_file_name, const char *_mode)
{
	return fopen(_file_name, _mode);
}