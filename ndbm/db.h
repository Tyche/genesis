/*-
 * Copyright (c) 1990, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)db.h	8.7 (Berkeley) 6/16/94
 */

#ifndef _DB_H_
#define	_DB_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#ifndef WIN32
#include <unistd.h>
#else
#ifndef __BORLANDC__
typedef int mode_t;
#endif
#endif

#if defined _MSC_VER
#define stat _stat
#define close _close
#define read _read
#define open _open
#define write _write
#define lseek _lseek
#define unlink _unlink
#define getpid _getpid
#endif


#ifndef MAXPATHLEN
#ifdef WIN32
#include <io.h>
#endif
#ifdef MAXPATH
#define MAXPATHLEN MAXPATH
#else
#define MAXPATHLEN 260
#endif
#endif

#ifndef O_ACCMODE
#define O_ACCMODE   3       /* mask for file access modes - not defined in Visual C */
#endif

#ifndef S_ISDIR
#define S_ISDIR(m)  ((m) & S_IFDIR)
#endif

#ifndef NSIG
#define NSIG   23      /* highest defined signal no. + 1 */
#endif

/*
 * If your system doesn't have an include file with the appropriate
 * byte order set, make sure you specify the correct one.
 */
#ifndef BYTE_ORDER
#define	LITTLE_ENDIAN	1234		/* LSB first: i386, vax */
#define	BIG_ENDIAN	4321		/* MSB first: 68000, ibm, net */
#define	BYTE_ORDER	BIG_ENDIAN	/* Set for your system. */
#endif

#ifndef EFTYPE
#define	EFTYPE		EINVAL		/* POSIX 1003.1 format errno. */
#endif

#ifndef	STDERR_FILENO
#define	STDIN_FILENO	0		/* ANSI C #defines */
#define	STDOUT_FILENO	1
#define	STDERR_FILENO	2
#endif

#ifndef	MAX				/* Usually found in <sys/param.h>. */
#define	MAX(_a,_b)	((_a)<(_b)?(_b):(_a))
#endif
#ifndef	MIN				/* Usually found in <sys/param.h>. */
#define	MIN(_a,_b)	((_a)<(_b)?(_a):(_b))
#endif

#if (_MSC_VER >= 1400) || (__BORLANDC__ >= 0x0630) // VC 8.0+ 2005 | Embarcadero C++ Builder XE
#include <stdint.h>
#else
typedef	signed char		int8_t;
typedef	unsigned char	uint8_t;
typedef	short			int16_t;
typedef	unsigned short	uint16_t;
typedef	int			    int32_t;
typedef	unsigned int    uint32_t;
#endif

#define	MAX_PAGE_NUMBER	0xffffffff	/* >= # of pages in a file */
typedef uint32_t	pgno_t;
#define	MAX_PAGE_OFFSET	65535		/* >= # of bytes in a page */
typedef uint16_t	indx_t;

/* Key/data structure -- a Data-Base Thang. */
typedef struct {
	void	*data;			/* data */
	size_t	 size;			/* data length */
} DBT;

/* Routine flags. */
#define	R_CURSOR	1		/* del, put, seq */
#define	R_FIRST		3		/* seq */
#define	R_NEXT		7		/* seq */
#define	R_NOOVERWRITE	8		/* put */

typedef enum { DB_BTREE, DB_HASH, DB_RECNO } DBTYPE;

/* Access method description structure. */
typedef struct __db {
	DBTYPE type;			/* Underlying db type. */
	int (*close)	(struct __db *);
	int (*del)	(const struct __db *, const DBT *, uint32_t);
	int (*get)	(const struct __db *, const DBT *, DBT *, uint32_t);
	int (*put)	(const struct __db *, DBT *, const DBT *, uint32_t);
	int (*seq)	(const struct __db *, DBT *, DBT *, uint32_t);
	int (*sync)	(const struct __db *, uint32_t);
	void *internal;			/* Access method private. */
	int (*fd)	(const struct __db *);
} DB;

#define	HASHMAGIC	0x061561
#define	HASHVERSION	2

/* Structure used to pass parameters to the hashing routines. */
typedef struct {
	uint32_t	bsize;		/* bucket size */
	uint32_t	ffactor;	/* fill factor */
	uint32_t	nelem;		/* number of elements */
	uint32_t	cachesize;	/* bytes to cache */
	uint32_t		/* hash function */
		(*hash) (const void *, size_t);
	int	lorder;		/* byte order */
} HASHINFO;

/*
 * Little endian <==> big endian 32-bit swap macros.
 *	M_32_SWAP	swap a memory location
 *	P_32_SWAP	swap a referenced memory location
 *	P_32_COPY	swap from one location to another
 */
#define	M_32_SWAP(a) {							\
	uint32_t _tmp = a;						\
	((char *)&a)[0] = ((char *)&_tmp)[3];				\
	((char *)&a)[1] = ((char *)&_tmp)[2];				\
	((char *)&a)[2] = ((char *)&_tmp)[1];				\
	((char *)&a)[3] = ((char *)&_tmp)[0];				\
}
#define	P_32_SWAP(a) {							\
	uint32_t _tmp = *(uint32_t *)a;				\
	((char *)a)[0] = ((char *)&_tmp)[3];				\
	((char *)a)[1] = ((char *)&_tmp)[2];				\
	((char *)a)[2] = ((char *)&_tmp)[1];				\
	((char *)a)[3] = ((char *)&_tmp)[0];				\
}
#define	P_32_COPY(a, b) {						\
	((char *)&(b))[0] = ((char *)&(a))[3];				\
	((char *)&(b))[1] = ((char *)&(a))[2];				\
	((char *)&(b))[2] = ((char *)&(a))[1];				\
	((char *)&(b))[3] = ((char *)&(a))[0];				\
}

/*
 * Little endian <==> big endian 16-bit swap macros.
 *	M_16_SWAP	swap a memory location
 *	P_16_SWAP	swap a referenced memory location
 *	P_16_COPY	swap from one location to another
 */
#define	M_16_SWAP(a) {							\
	uint16_t _tmp = a;						\
	((char *)&a)[0] = ((char *)&_tmp)[1];				\
	((char *)&a)[1] = ((char *)&_tmp)[0];				\
}
#define	P_16_SWAP(a) {							\
	uint16_t _tmp = *(uint16_t *)a;				\
	((char *)a)[0] = ((char *)&_tmp)[1];				\
	((char *)a)[1] = ((char *)&_tmp)[0];				\
}
#define	P_16_COPY(a, b) {						\
	((char *)&(b))[0] = ((char *)&(a))[1];				\
	((char *)&(b))[1] = ((char *)&(a))[0];				\
}

#if defined(__cplusplus)
extern "C" {
#endif
DB	*__hash_open (const char *, int, int, const HASHINFO *);
#if defined(__cplusplus)
};
#endif

#endif /* !_DB_H_ */
