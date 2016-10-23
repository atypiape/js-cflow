/******************************************************************************
 FILE:	 text_list.h
 DESC:   Simple linked list for text node.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#ifndef __JS_CFLOW_TEXT_LIST_H__
#define __JS_CFLOW_TEXT_LIST_H__

#include "../config.h"


struct JsCFlowTextList {
	char *text;
	struct JsCFlowTextList *next;
};
typedef struct JsCFlowTextList JsCFlowTextList;


bool js_cflow_text_list_create(JsCFlowTextList **_list);

void js_cflow_text_list_destory(JsCFlowTextList **_list);

bool js_cflow_text_list_add(JsCFlowTextList *_list, const char *_text);

bool js_cflow_text_list_has(const JsCFlowTextList *_list, const char *_text);


#endif /* __JS_CFLOW_TEXT_LIST_H__ */