/******************************************************************************
 FILE:	 file_sys.h
 DESC:   File system operation functions.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#include "file_sys.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#if defined(_WINDOWS)
#  include <io.h>
#else
#  include <sys/stat.h>
#endif /* _WINDOWS */


JsCFlowResult js_cflow_path_exists(const char *_path)
{
#if !defined(_WINDOWS)
	struct stat filestat = {0};
#endif

	assert(_path);
	if (NULL == _path) {
		return kJsCFlowResultInvalidArguments;
	}

	assert('\0' != _path[0]);
	if ('\0' == _path[0]) {
		return kJsCFlowResultInvalidArguments;
	}

#if defined(_WINDOWS)
	if (0 != _access(_path, 0)) {
#else
	if (0 != stat(_path, &filestat)) {
#endif
		return kJsCFlowResultPathNotExist;
	}

	return kJsCFlowResultSucceed;
}


JsCFlowResult js_cflow_read_file_content(void **_file_content, const char *_file_path)
{
	long file_bytes = 0;
	FILE *file = NULL;
	BYTE *content = NULL;
	JsCFlowResult result = kJsCFlowResultSucceed;

	assert(_file_content);
	assert(_file_path);
	if (NULL == _file_content || NULL == _file_path) {
		return kJsCFlowResultInvalidArguments;
	}

	*_file_content = NULL;

	assert('\0' != _file_path[0]);
	if ('\0' == _file_path[0]) {
		return kJsCFlowResultInvalidArguments;
	}

	file = fopen(_file_path, "rb");
	assert(file);
	if (NULL == file) {
		return kJsCFlowResultFileOpenError;
	}

	fseek(file, 0, SEEK_END);
	file_bytes = ftell(file);
	fseek(file, 0, SEEK_SET);

	if (0 == file_bytes) {
		fclose(file);
		return kJsCFlowResultSucceed;
	}

	// 考虑到字符串最后的 NULL 结尾, 所以外加 1 字节
	content = (BYTE *)malloc(file_bytes + 1);
	assert(content);
	if (NULL == content) {
		fclose(file);
		return kJsCFlowResultAllocMemoryError;
	}
	memset(content, 0, file_bytes + 1);

	if (1 != fread(content, file_bytes, 1, file)) {
		assert(false);
		fclose(file);
		free(content);
		return kJsCFlowResultFileReadError;
	}

	fclose(file);

	*_file_content = content;

	return kJsCFlowResultSucceed;
}


void js_cflow_free_file_content(void *_file_content)
{
	if (NULL != _file_content) {
		free(_file_content);
	}
}

