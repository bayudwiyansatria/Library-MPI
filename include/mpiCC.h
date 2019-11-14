/*
 *	Copyright Platform Computing Inc., an IBM company, 1983-2010, 2012-2016
 *
 *	$Revision$
 *
 *	Function:	- MPI header file
 *
 *	Notice:		- IBM Platform MPI is based in parts on the contributions
 *			  of the following groups:
 *
 *	- MPICH (Argonne National Laboratory, Mississippi State University)
 *	  versions 1.0.11, 1.0.12
 *	  (c)Copyright 1993 University of Chicago
 *	  (c)Copyright 1993 Mississippi State University
 *
 *	- LAM (Ohio Supercomputer Center)
 *	  versions 6.0, 6.1, 7.1.1
 *	  (c)Copyright 1995-1996 The Ohio State University
 *
 *  - Copyright (c) 2001-2003 The Trustees of Indiana University.
 *                            All rights reserved.
 *    Copyright (c) 1998-2001 University of Notre Dame.
 *                            All rights reserved.
 *    Copyright (c) 1994-1998 The Ohio State University.
 *
 *	"@(#)IBM Platform MPI 09.01.04.03 [BASELINE_MPI_STREAM_REL_9.1.4.0_RTM_2015_06_15]  [] [] [] [] [] [] (02/06/2018) Linux x86-64"
 */

#ifndef _MPICC_H
#define _MPICC_H
#ifdef __DEPRECATED
#warning The entire set of C++ language bindings have been deprecated in mpi 2.2 \
To disable this warning use -Wno-deprecated.
#endif
//
// Let's ensure that we're really in C++, and some errant programmer
// hasn't included <mpiCC.h> just "for completeness"
//

#if defined(__cplusplus) || defined(c_plusplus)

// Defined for features we don't support yet.
// #define HPMPI_NAME_PUBLISHING

// For the product build, use mpio and the usual user-level
// view of mpi.h (undef MPI_hpux)
#ifdef MPI_hpux
#  undef HP_MPI_NOIO
#  undef MPI_hpux
#endif

#define _REAL_MPI_ MPI

#include <mpi.h>

#include <stdarg.h>
#include "mpiCC/mpiCC_map.h"

extern "C" void
op_intercept(void *invec, void *outvec, int *len, MPI_Datatype *datatype);

#ifdef HPMPI_LONG_EXTENTIONS
  extern "C" void
  op_interceptl(void *invec, void *outvec, MPI_Aint *len, MPI_Datatype *datatype);
#endif

// This is used as the MPI_Handler_function for
// the mpi_errhandler in ERRORS_THROW_EXCEPTIONS
extern "C" void
throw_excptn_fctn(MPI_Comm* comm, int* errcode, ...);

extern "C" void
errhandler_intercept(MPI_Comm * mpi_comm, int * err, ...);

//used for attr intercept functions
enum CommType { eIntracomm, eIntercomm, eCartcomm, eGraphcomm, eDistgraphcomm};

extern "C" int
copy_attr_intercept(MPI_Comm oldcomm, int keyval,
		    void *extra_state, void *attribute_val_in,
		    void *attribute_val_out, int *flag);

extern "C" int
delete_attr_intercept(MPI_Comm comm, int keyval,
		      void *attribute_val, void *extra_state);

//
// MPI generalized request intercepts
//

extern "C" int
grequest_query_fn_intercept(void *state, MPI_Status *status);
extern "C" int
grequest_free_fn_intercept(void *state);
extern "C" int
grequest_cancel_fn_intercept(void *state, int canceled);

namespace MPI {
  class Comm_Null;
  class Comm;
  class Intracomm;
  class Intercomm;
  class Graphcomm;
  class Cartcomm;
  class Distgraphcomm;
  class Datatype;
  class Errhandler;
  class Group;
  class Op;
  class Request;
  class Status;
  class Info;
  class Win;
#ifndef HP_MPI_NOIO
  class File;
#endif

  typedef MPI_Fint Fint;
  typedef MPI_Aint Aint;

#ifndef HP_MPI_NOIO
  typedef MPI_Offset Offset; //VPS: for romio
#endif

#include "mpiCC/constants.h"
#include "mpiCC/functions.h"
#include "mpiCC/datatype.h"

  typedef void User_function(const void* invec, void* inoutvec, int len,
			     const Datatype& datatype);
#ifdef HPMPI_LONG_EXTENTIONS
  typedef void User_functionL(const void* invec, void* inoutvec, MPI_Aint len,
			     const Datatype& datatype);
#endif

#include "mpiCC/exception.h"
#include "mpiCC/op.h"
#include "mpiCC/status.h"
#include "mpiCC/request.h"   //includes class Prequest
#include "mpiCC/group.h"
#include "mpiCC/comm.h"
#include "mpiCC/errhandler.h"
#include "mpiCC/intracomm.h"
#include "mpiCC/topology.h"  //includes Cartcomm and Graphcomm
#include "mpiCC/intercomm.h"
#include "mpiCC/info.h"
#include "mpiCC/win.h"

#ifndef HP_MPI_NOIO
#include "mpiCC/file.h" //VPS: included file.h for MPI::File binding
#endif

}

//
// These are the "real" functions, whether prototyping is enabled
// or not. These functions are assigned to either the MPI::XXX class
// or the PMPI::XXX class based on the value of the macro _REAL_MPI_
// which is set in mpi2cxx_config.h.
// If prototyping is enabled, there is a top layer that calls these
// PMPI functions, and this top layer is in the XXX.cc files.
//

#include "mpiCC/datatype_inln.h"
#include "mpiCC/functions_inln.h"
#include "mpiCC/request_inln.h"
#include "mpiCC/comm_inln.h"
#include "mpiCC/intracomm_inln.h"
#include "mpiCC/topology_inln.h"
#include "mpiCC/intercomm_inln.h"
#include "mpiCC/group_inln.h"
#include "mpiCC/op_inln.h"
#include "mpiCC/errhandler_inln.h"
#include "mpiCC/status_inln.h"
#include "mpiCC/info_inln.h"
#include "mpiCC/win_inln.h"

#ifndef HP_MPI_NOIO
#include "mpiCC/file_inln.h"  //VPS: included for MPI::File binding
#endif

#endif // #if defined(__cplusplus) || defined(c_plusplus)
#endif // #ifndef _MPICC_H
