/* ====================================================================
 * Copyright (c) 1995-2000 Carnegie Mellon University.  All rights 
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * This work was supported in part by funding from the Defense Advanced 
 * Research Projects Agency and the National Science Foundation of the 
 * United States of America, and the CMU Sphinx Speech Consortium.
 *
 * THIS SOFTWARE IS PROVIDED BY CARNEGIE MELLON UNIVERSITY ``AS IS'' AND 
 * ANY EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL CARNEGIE MELLON UNIVERSITY
 * NOR ITS EMPLOYEES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ====================================================================
 *
 */
/*********************************************************************
 *
 * File: gauden_io.h
 * 
 * Description: 
 * 
 * Author: 
 * 	Eric H. Thayer (eht@cs.cmu.edu)
 *********************************************************************/

#ifndef GAUDEN_IO_H
#define GAUDEN_IO_H

#ifdef __cplusplus
extern "C" {
#endif
#if 0
}
#endif

#include <sphinxbase/prim_type.h>
#include <s3/s3.h>
#include <s3/common.h>

#define GAUDEN_PARAM_VERSION	"0.1"
#define GAUDEN_COUNTS_VERSION	"0.3"
#define GAUDEN_DCOUNTS_VERSION	"0.1"

int32
gauden_bundle(const char *dir,
	      const char *ext,
	      vector_t ****out_param,
	      uint32 n_mgau,
	      uint32 *out_n_feat,
	      uint32 *out_n_density,
	      const uint32 **veclen);

int32
gauden_unbundle(const char *dir,
		const char *ext,
		vector_t ***out,
		uint32 n_mgau,
		uint32 n_feat,
		uint32 n_density,
		const uint32 *veclen);

int32
gauden_write(const char *file_name,
	     const char *comment,
	     vector_t ***out,
	     uint32 n_mgau,
	     uint32 n_feat,
	     uint32 n_density,
	     const uint32 *veclen);

int32
gauden_read(const char **out_comment,
	    vector_t ****out_param,
	    uint32 *out_n_mgau,
	    uint32 *out_n_feat,
	    uint32 *out_n_density,
	    uint32 **out_veclen,
	    const char *file_name);

int32
gauden_counts_write(const char *file_name,
		    const char *comment,
		    vector_t ***wt_mean,
		    vector_t ***wt_var,
		    int32 pass2var,
		    float32 ***dnom,
		    uint32 n_mgau,
		    uint32 n_feat,
		    uint32 n_density,
		    const uint32 *veclen);

int32
gauden_counts_read(const char **out_comment,
		   vector_t ****out_wt_mean,
		   vector_t ****out_wt_var,
		   int32 *pass2var,
		   float32 ****out_dnom,
		   uint32 *out_n_mgau,
		   uint32 *out_n_feat,
		   uint32 *out_n_density,
		   uint32 **out_veclen,
		   const char *file_name);

int32
gauden_dcount_read(const char **out_comment,
		   float32 ****out_dnom,
		   uint32 *out_n_mgau,
		   uint32 *out_n_feat,
		   uint32 *out_n_density,
		   const char *file_name);

int32
gauden_dcount_write(const char *file_name,
		    const char *comment,
		    float32 ***dnom,
		    uint32 n_mgau,
		    uint32 n_feat,
		    uint32 n_density);

#ifdef __cplusplus
}
#endif
#endif /* GAUDEN_IO_H */ 


/*
 * Log record.  Maintained by RCS.
 *
 * $Log$
 * Revision 1.4  2004/07/21  17:46:09  egouvea
 * Changed the license terms to make it the same as sphinx2 and sphinx3.
 * 
 * Revision 1.3  2001/04/05 20:02:30  awb
 * *** empty log message ***
 *
 * Revision 1.2  2000/09/29 22:35:12  awb
 * *** empty log message ***
 *
 * Revision 1.1  2000/09/24 21:38:30  awb
 * *** empty log message ***
 *
 * Revision 1.6  97/07/16  11:39:10  eht
 * *** empty log message ***
 * 
 * Revision 1.5  1996/07/29  16:33:40  eht
 * added const attrib
 * added bundle/unbundle functions
 *
 * Revision 1.4  1996/06/20  17:41:50  eht
 * Changed make string constant include "const" in the function definition/declaration
 *
 * Revision 1.3  1996/01/26  17:55:01  eht
 * Use the const specification for the veclen (it shouldn't be written to inside this module)
 *
 * Revision 1.2  1995/10/10  13:10:34  eht
 * Changed to use <sphinxbase/prim_type.h>
 *
 * Revision 1.1  1995/08/15  13:46:15  eht
 * Initial revision
 *
 *
 */
