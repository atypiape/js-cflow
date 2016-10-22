/******************************************************************************
 FILE:	 platform.h
 DESC:   Help to realize cross-platform.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#ifndef __JS_CFLOW_PLATFORM_H__
#define __JS_CFLOW_PLATFORM_H__


#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64) \
     || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#  if !defined(_WINDOWS)
#    define _WINDOWS
#  endif
#endif


#if !defined(EXTERN_C)
#  if defined(__cplusplus)
#    define EXTERN_C extern "C"
#  else
#    define EXTERN_C extern
#  endif
#endif


#if defined(_WINDOWS)

#  include <sdkddkver.h>

#  define WIN32_LEAN_AND_MEAN
#  include <wtypes.h>

#if (_MSC_VER && 1700 > _MSC_VER)
#  include "stdbool.h"
#endif

#else /* !_WINDOWS */

#  include <stdbool.h>

#  define _getcwd   getcwd
#  define _chdir	chdir
#  define _popen	popen
#  define _pclose	pclose
#  define _stricmp	stricmp

#endif /* _WINDOWS */


#include <stdint.h>


#if !defined(BOOL)
#  define BOOL	bool
#endif

#if !defined(FALSE)
#  define FALSE	false
#endif

#if !defined(TRUE)
#  define TRUE	true
#endif


#if !defined(MAX_PATH)
#  include <limits.h>
#  define MAX_PATH	PATH_MAX
#endif


#if !defined(BYTE)
#define BYTE	unsigned char
#endif


#if !defined(WORD)
#define WORD	uint16_t
#endif


#if !defined(DWORD)
#define DWORD	uint32_t
#endif


#endif /* __JS_CFLOW_PLATFORM_H__ */
