/******************************************************************************
 FILE:	 js-cflow.h
 DESC:   JS-CFlow command shell.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/


#include "../js-cflow.h"
#include <stdio.h>
#include <shlwapi.h>


enum {
	kArgIndexJsFile	= 1,
	kArgCount		= 2
};


void ShowUsage(void)
{
	const char *app_name = PathFindFileNameA((const char *)__argv[0]);

	printf("Usage:\n");
	printf("    %s <js_file>\n", app_name);
}


int main(int argc, char *argv[])
{
	const char *app_name = PathFindFileName(argv[0]);
	const char *js_file = NULL;

	if (kArgCount > argc) {
		ShowUsage();
		return EXIT_FAILURE;
	}

	js_file = argv[kArgIndexJsFile];
	if (kJsCFlowResultSucceed != js_cflow_start(js_file)) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}