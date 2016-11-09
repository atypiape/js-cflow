/******************************************************************************
 FILE:	 platform.h
 DESC:   Project config.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#ifndef __JS_CFLOW_CONFIG_H__
#define __JS_CFLOW_CONFIG_H__

#include "platform.h"


/* build dynamic library */
#if !defined(JS_CFLOW_STATIC_LIB) && defined(_WINDOWS)
#  if defined(JS_CFLOW_EXPORTS)
#    define JS_CFLOW_API __declspec(dllexport)
#  else
#    define JS_CFLOW_API __declspec(dllimport)
#  endif
/* build static library */
#else
#  define JS_CFLOW_API
#endif


#endif /* __JS_CFLOW_CONFIG_H__ */
