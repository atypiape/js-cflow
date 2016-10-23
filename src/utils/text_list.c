/******************************************************************************
 FILE:	 text_list.c
 DESC:   Simple linked list for text node.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#include "text_list.h"
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>


bool js_cflow_text_list_create(JsCFlowTextList **_list)
{
	assert(_list);
	if (NULL == _list) {
		return false;
	}

	*_list = malloc(sizeof(JsCFlowTextList));
	assert(*_list);
	if (NULL == *_list) {
		return false;
	}

	memset(*_list, 0x0, sizeof(JsCFlowTextList));

	return true;
}


void js_cflow_text_list_destory(JsCFlowTextList **_list)
{
	JsCFlowTextList *curr_node = NULL;
	JsCFlowTextList *next_node = NULL;

	assert(_list);
	if (NULL == _list || NULL == *_list) {
		return;
	}

	curr_node = *_list;
	*_list = NULL;
	while (curr_node) {
		if (NULL != curr_node->text) {
			free(curr_node->text);
		}
		next_node = curr_node->next;
		free(curr_node);
		curr_node = next_node;
	}
}


bool js_cflow_text_list_add(JsCFlowTextList *_list, const char *_text)
{
	size_t bytes = 0;

	assert(_list);
	assert(_text);
	if (NULL == _list || NULL == _text) {
		return false;
	}

	assert('\0' != _text[0]);
	if ('\0' == _text[0]) {
		return false;
	}
	
	if (NULL != _list->text) {
		while (NULL != _list->next) {
			_list = _list->next;
		}
		_list->next = (JsCFlowTextList *)malloc(sizeof(JsCFlowTextList));
		assert(_list->next);
		if (NULL == _list->next) {
			return false;
		}
		_list = _list->next;
		memset(_list, 0x0, sizeof(JsCFlowTextList));
	}

	bytes = strlen(_text) + 1;
	_list->text = (char *)malloc(bytes);
	assert(_list->text);
	if (NULL == _list->text) {
		free(_list);
		return false;
	}
	memcpy(_list->text, _text, bytes);

	return true;
}


bool js_cflow_text_list_has(const JsCFlowTextList *_list, const char *_text)
{
	assert(_list);
	assert(_text);
	if (NULL == _list || NULL == _text) {
		return false;
	}

	while (_list) {
		if (NULL == _list->text) {
			continue;
		}
		if (0 == _stricmp(_list->text, _text)) {
			return true;
		}
		_list = _list->next;
	}

	return false;
}