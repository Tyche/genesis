#ifndef cdc_config_h
#define cdc_config_h

#include "version.h"

#define pid_t int

#define SIZEOF_CHAR 1
#define SIZEOF_SHORT 2
#define SIZEOF_INT 4
#define SIZEOF_LONG 4
#define SIZEOF_LLONG 8
#define SIZEOF_FLOAT 4
#define SIZEOF_DOUBLE 8
#define SIZEOF_LDOUBLE 10

#define HAVE_MEMMOVE 1
#define HAVE_STRCSPN 1
#define HAVE_STRERROR 1

#undef RESTRICTIVE_FILES

#define CACHE_WIDTH 61
#define CACHE_DEPTH 10

#define DBM_H_FILE <ndbm.h>

#include "systype.h"

#ifndef __Win32__
#  define __Win32__
#  include <windows.h>
#endif

#ifdef __BORLANDC__
#undef strcmp
#endif

#endif
