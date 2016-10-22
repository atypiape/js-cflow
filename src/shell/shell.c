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


void show_usage(void)
{
	const char *app_name = PathFindFileNameA((const char *)__argv[0]);

	printf("Usage:\n");
	printf("    %s <js_file>\n", app_name);
}


void show_result(JsCFlowResult _result)
{
	const char *error_string = NULL;
	if (kJsCFlowResultSucceed == _result) {
		puts("success");
		return;
	}

	switch (_result) {
	case kJsCFlowResultInvalidArguments:
		error_string = "invalid arguments";
		break;

	case kJsCFlowResultPathNotExist:
		error_string = "path not exist";
		break;

	default:
		error_string = "unknow";
		break;
	}

	fprintf_s(stderr, "error(%d): %s\n", _result, error_string);
}


int main(int argc, char *argv[])
{
	const char *app_name = PathFindFileName(argv[0]);
	const char *js_file = NULL;
	JsCFlowResult result = kJsCFlowResultSucceed;

	if (kArgCount > argc) {
		show_usage();
		return EXIT_FAILURE;
	}

	js_file = argv[kArgIndexJsFile];

	result = js_cflow_start(js_file);
	show_result(result);

	if (kJsCFlowResultSucceed != result) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}