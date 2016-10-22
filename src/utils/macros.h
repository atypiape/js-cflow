/******************************************************************************
 FILE:	 macros.h
 DESC:   Define some helper macros.
 AUTHOR: Atypiape
 E-MAIL: atypiape@163.com
 ******************************************************************************/

#ifndef __W2X_MACROS_H__
#define __W2X_MACROS_H__


// call free() to release memory and set point to NULL
#define W2X_SAFE_FREE(_ptr_) \
	do { if (NULL != (_ptr_)) { free((_ptr_)); (_ptr_) = NULL; } } while(0)


// call fclose() to close file and set point to NULLs
#define W2X_SAFE_FCLOSE(_file_ptr_) \
	do { if (NULL != (_file_ptr_)) { fclose((_file_ptr_)); (_file_ptr_) = NULL; } } while(0)


#endif // __W2X_MACROS_H__
