/******************************************************************************
 FILE:	 stdbool.h
 DESC:   The C Standard Library <stdbool.h> header.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#ifndef __JS_CFLOW_STDBOOL__
#define __JS_CFLOW_STDBOOL__

#define __bool_true_false_are_defined	1

#ifndef __cplusplus

#ifndef _Bool
#define _Bool unsigned char
#endif

#define bool	_Bool
#define false	0
#define true	1

#endif /* __cplusplus */

#endif /* __JS_CFLOW_STDBOOL__ */
