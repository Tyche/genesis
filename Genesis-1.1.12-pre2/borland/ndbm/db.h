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

#if defined(__cplusplus)
#define	__BEGIN_DECLS	extern "C" {
#define	__END_DECLS	};
#else
#define	__BEGIN_DECLS
#define	__END_DECLS
#endif

#define	__P(protos)	protos		/* full-blown ANSI C */

#ifndef MAXPATHLEN
#include <io.h>
#ifdef MAXPATH
#define MAXPATHLEN MAXPATH
#else
#define MAXPATHLEN 260
#endif
#endif

#define NSIG   23      /* highest defined signal no. + 1 */

/*
 * If your system doesn't typedef u_long, u_short, or u_char, change
 * the 0 to a 1.
 */
#if 1
typedef unsigned char	u_char;		/* 4.[34]BSD names. */
typedef unsigned int	u_int;
typedef unsigned long	u_long;
typedef unsigned short	u_short;
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

/*
 * 32-bit machine.  The db routines are theoretically independent of
 * the size of u_shorts and u_longs, but I don't know that anyone has
 * ever actually tried it.  At a minimum, change the following #define's
 * if you are trying to compile on a different type of system.
 */
#ifndef USHRT_MAX
#define	USHRT_MAX		0xFFFF
#define	ULONG_MAX		0xFFFFFFFF
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

#ifndef	__BIT_TYPES_DEFINED__
#define	__BIT_TYPES_DEFINED__
typedef	signed char		   int8_t;
typedef	unsigned char		 u_int8_t;
typedef	short			  int16_t;
typedef	unsigned short		u_int16_t;
typedef	int			  int32_t;
typedef	unsigned int		u_int32_t;
#endif

#define	MAX_PAGE_NUMBER	0xffffffff	/* >= # of pages in a file */
typedef u_int32_t	pgno_t;
#define	MAX_PAGE_OFFSET	65535		/* >= # of bytes in a page */
typedef u_int16_t	indx_t;
#define	MAX_REC_NUMBER	0xffffffff	/* >= # of records in a tree */
typedef u_int32_t	recno_t;

/* Key/data structure -- a Data-Base Thang. */
typedef struct {
	void	*data;			/* data */
	size_t	 size;			/* data length */
} DBT;

/* Routine flags. */
#define	R_CURSOR	1		/* del, put, seq */
#define	__R_UNUSED	2		/* UNUSED */
#define	R_FIRST		3		/* seq */
#define	R_NEXT		7		/* seq */
#define	R_NOOVERWRITE	8		/* put */

typedef enum { DB_BTREE, DB_HASH, DB_RECNO } DBTYPE;

/* Access method description structure. */
typedef struct __db {
	DBTYPE type;			/* Underlying db type. */
	int (*close)	__P((struct __db *));
	int (*del)	__P((const struct __db *, const DBT *, u_int));
	int (*get)	__P((const struct __db *, const DBT *, DBT *, u_int));
	int (*put)	__P((const struct __db *, DBT *, const DBT *, u_int));
	int (*seq)	__P((const struct __db *, DBT *, DBT *, u_int));
	int (*sync)	__P((const struct __db *, u_int));
	void *internal;			/* Access method private. */
	int (*fd)	__P((const struct __db *));
} DB;

#define	HASHMAGIC	0x061561
#define	HASHVERSION	2

/* Structure used to pass parameters to the hashing routines. */
typedef struct {
	u_int	bsize;		/* bucket size */
	u_int	ffactor;	/* fill factor */
	u_int	nelem;		/* number of elements */
	u_int	cachesize;	/* bytes to cache */
	u_int32_t		/* hash function */
		(*hash) __P((const void *, size_t));
	int	lorder;		/* byte order */
} HASHINFO;

/*
 * Little endian <==> big endian 32-bit swap macros.
 *	M_32_SWAP	swap a memory location
 *	P_32_SWAP	swap a referenced memory location
 *	P_32_COPY	swap from one location to another
 */
#define	M_32_SWAP(a) {							\
	u_int32_t _tmp = a;						\
	((char *)&a)[0] = ((char *)&_tmp)[3];				\
	((char *)&a)[1] = ((char *)&_tmp)[2];				\
	((char *)&a)[2] = ((char *)&_tmp)[1];				\
	((char *)&a)[3] = ((char *)&_tmp)[0];				\
}
#define	P_32_SWAP(a) {							\
	u_int32_t _tmp = *(u_int32_t *)a;				\
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
	u_int16_t _tmp = a;						\
	((char *)&a)[0] = ((char *)&_tmp)[1];				\
	((char *)&a)[1] = ((char *)&_tmp)[0];				\
}
#define	P_16_SWAP(a) {							\
	u_int16_t _tmp = *(u_int16_t *)a;				\
	((char *)a)[0] = ((char *)&_tmp)[1];				\
	((char *)a)[1] = ((char *)&_tmp)[0];				\
}
#define	P_16_COPY(a, b) {						\
	((char *)&(b))[0] = ((char *)&(a))[1];				\
	((char *)&(b))[1] = ((char *)&(a))[0];				\
}

__BEGIN_DECLS
DB	*__hash_open __P((const char *, int, int, const HASHINFO *, int));
__END_DECLS

#endif /* !_DB_H_ */
