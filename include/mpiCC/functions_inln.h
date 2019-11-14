/*
 *	Copyright Platform Computing Inc., an IBM company, 1983-2010, 2012
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
 * "@(#)IBM Platform MPI 09.01.04.03 [BASELINE_MPI_STREAM_REL_9.1.4.0_RTM_2015_06_15]  [] [] [] [] [] [] (02/06/2018) Linux x86-64"
 */

#include <string.h>

//
// Point-to-Point Communication
//

inline void
_REAL_MPI_::Attach_buffer(void* buffer, int size)
{
  (void)MPI_Buffer_attach(buffer, size);
}

inline int
_REAL_MPI_::Detach_buffer(void*& buffer)
{
  int size;
  (void)MPI_Buffer_detach(&buffer, &size);
  return size;
}

#ifdef HPMPI_LONG_EXTENTIONS
#include "mpiCC/functionsL_inln.h"
#endif

//
// Process Topologies
//

inline void
_REAL_MPI_::Compute_dims(int nnodes, int ndims, int dims[])
{
  (void)MPI_Dims_create(nnodes, ndims, dims);
}

//
// Environmental Inquiry
//

inline void
_REAL_MPI_::Get_processor_name(char* name, int& resultlen)
{
  (void)MPI_Get_processor_name(name, &resultlen);
}

inline void
_REAL_MPI_::Get_error_string(int errorcode, char* string, int& resultlen)
{
  (void)MPI_Error_string(errorcode, string, &resultlen);
}

inline int
_REAL_MPI_::Get_error_class(int errorcode)
{
  int errorclass;
  (void)MPI_Error_class(errorcode, &errorclass);
  return errorclass;
}

inline int
_REAL_MPI_::Add_error_class()
{
  int ret_errorclass;
  (void)MPI_Add_error_class( &ret_errorclass);
  return ret_errorclass;
}

inline int
_REAL_MPI_::Add_error_code(int errorclass)
{
  int ret_errorclass;
  (void)MPI_Add_error_code(errorclass, &ret_errorclass);
  return ret_errorclass;
}

inline void
_REAL_MPI_::Add_error_string(int errorcode, const char* string)
{
  MPI_Add_error_string(errorcode, (char *)string);
}

inline double
_REAL_MPI_::Wtime()
{
  return (MPI_Wtime());
}

inline double
_REAL_MPI_::Wtick()
{
  return (MPI_Wtick());
}

inline void
_REAL_MPI_::Real_init()
{
  // This is here even though ERRORS_THROW_EXCEPTIONS is a const
  // function; there's no way around this.  :-(
  MPI::ERRORS_THROW_EXCEPTIONS.init();
}

inline void
_REAL_MPI_::Init(int& argc, char**& argv)
{
  (void)MPI_Init(&argc, &argv);
  Real_init();
}

inline void
_REAL_MPI_::Init()
{
  (void)MPI_Init(0, 0);
  Real_init();
}

inline void
_REAL_MPI_::Finalize()
{
  // Prevent a memory leak by calling this hidden "free" function here
  // (even though ERRORS_THROW_EXCEPTIONS is a const object)
  MPI::ERRORS_THROW_EXCEPTIONS.free();
  (void)MPI_Finalize();
}
inline bool
_REAL_MPI_::Is_initialized()
{
  int t;
  (void)MPI_Initialized(&t);
  return (bool) t;
}

inline bool
_REAL_MPI_::Is_finalized()
{
  int t;
  (void)MPI_Finalized(&t);
  return (bool) t;
}

//
// External Interfaces
//

inline int
_REAL_MPI_::Init_thread(int required)
{
  int provided;
  (void) MPI_Init_thread(0, NULL, required, &provided);
  Real_init();
  return provided;
}

inline int
_REAL_MPI_::Init_thread(int& argc, char**& argv, int required)
{
  int provided;
  (void) MPI_Init_thread(&argc, &argv, required, &provided);
  Real_init();
  return provided;
}

inline bool
_REAL_MPI_::Is_thread_main()
{
  int flag;
  (void) MPI_Is_thread_main(&flag);
  return ((flag == 1) ? true : false);
}

inline int
_REAL_MPI_::Query_thread()
{
  int provided;
  (void) MPI_Query_thread(&provided);
  return provided;
}

//
// Miscellany
//

inline void*
_REAL_MPI_::Alloc_mem(_REAL_MPI_::Aint size, const _REAL_MPI_::Info& info)
{
  void* baseptr;
  (void) MPI_Alloc_mem(size, info, &baseptr);
  return baseptr;
}

inline void
_REAL_MPI_::Free_mem(void* base)
{
  (void) MPI_Free_mem(base);
}

//
// Process Creation
//

inline void
_REAL_MPI_::Close_port(const char* port_name)
{
  (void) MPI_Close_port((char *) port_name);
}

inline void
_REAL_MPI_::Lookup_name(const char * service_name,
			const _REAL_MPI_::Info& info,
			char* port_name)
{
  (void) MPI_Lookup_name((char *) service_name, info, port_name);
}

inline void
_REAL_MPI_::Open_port(const _REAL_MPI_::Info& info, char* port_name)
{
  (void) MPI_Open_port(info, port_name);
}

inline void
_REAL_MPI_::Publish_name(const char* service_name,
			 const _REAL_MPI_::Info& info,
			 const char* port_name)
{
  (void) MPI_Publish_name((char *) service_name, info,
			 (char *) port_name);
}

inline void
_REAL_MPI_::Unpublish_name(const char* service_name,
			   const _REAL_MPI_::Info& info,
			   const char* port_name)
{
  (void)MPI_Unpublish_name((char *) service_name, info,
                         (char *) port_name);
}

//
// Profiling
//

inline void
_REAL_MPI_::Pcontrol(const int level, ...)
{
  va_list ap;
  va_start(ap, level);

  (void)MPI_Pcontrol(level, ap);
  va_end(ap);
}

inline void
_REAL_MPI_::Get_version(int& version, int& subversion)
{
  (void)MPI_Get_version(&version, &subversion);
}

inline _REAL_MPI_::Aint
_REAL_MPI_::Get_address(void* location)
{
  _REAL_MPI_::Aint ret;
  MPI_Get_address(location, &ret);
  return ret;
}
