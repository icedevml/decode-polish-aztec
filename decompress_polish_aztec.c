/* decompress_polish_aztec.c -- decompress data from Polish vehicle AZTEC code

   this file is an explicit modification of the following file from libucl1-dev:

   simple.c -- the annotated simple example program for the UCL library

   This file is part of the UCL data compression library.

   Copyright (C) 1996-2004 Markus Franz Xaver Johannes Oberhumer
   All Rights Reserved.

   The UCL library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   The UCL library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with the UCL library; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   Markus F.X.J. Oberhumer
   <markus@oberhumer.com>
   http://www.oberhumer.com/opensource/ucl/
 */

#include <ucl/ucl.h>
#if defined(UCL_USE_ASM)
#  include <ucl/ucl_asm.h>
#endif

/* portability layer */
#define WANT_UCL_MALLOC 1
#include "portab.h"

#include <unistd.h>

int __acc_cdecl_main main(int argc, char *argv[])
{
    int r;
    ucl_bytep in;
    ucl_bytep out;
    ucl_uint in_len;
    ucl_uint out_len;
    ucl_uint new_len;
    int level = 5;                  /* compression level (1-10) */

    if (argc < 0 && argv == NULL)   /* avoid warning about unused args */
        return 0;

    fprintf(stderr, "\nUCL data compression library (v%s, %s).\n",
            ucl_version_string(), ucl_version_date());
    fprintf(stderr, "Copyright (C) 1996-2004 Markus Franz Xaver Johannes Oberhumer\n");
    fprintf(stderr, "http://www.oberhumer.com/opensource/ucl/\n\n");


/*
 * Step 1: initialize the UCL library
 */
    if (ucl_init() != UCL_E_OK)
    {
        fprintf(stderr, "internal error - ucl_init() failed !!!\n");
        fprintf(stderr, "(this usually indicates a compiler bug - try recompiling\nwithout optimizations, and enable `-DUCL_DEBUG' for diagnostics)\n");
        return 1;
    }


/*
 * Step 2: setup memory
 *
 * We want to compress the data block at `in' with length `in_len' to
 * the block at `out'. Because the input block may be incompressible,
 * we must provide a little more output space in case that compression
 * is not possible.
 */
    in_len = 256 * 1024L;
    out_len = 256 * 1024L;

    in = (ucl_bytep) ucl_malloc(in_len);
    out = (ucl_bytep) ucl_malloc(out_len);
    if (in == NULL || out == NULL)
    {
        fprintf(stderr, "out of memory\n");
        return 2;
    }

    ucl_uint rout_len = 0;
    rout_len = read(STDIN_FILENO, out, out_len);

/*
 * Step 5: decompress again, now going back from `out' to `in'
 */
    new_len = out_len;
    r = ucl_nrv2e_decompress_8(out+4,rout_len-4,in,&new_len,NULL);

    if (r == UCL_E_OK)
        for (int i = 0; i < new_len; i++) {
            printf("%c", in[i]);
        }
    else
    {
        /* this should NEVER happen */
        fprintf(stderr, "internal error - decompression failed: %d\n", r);
        return 5;
    }

    ucl_free(out);
    ucl_free(in);
    return 0;
}

/*
vi:ts=4:et
*/

