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

//
// Point-to-Point Communication
//

inline int
_REAL_MPI_::Status::Get_count(const _REAL_MPI_::Datatype& datatype) const
{
  int count;
  //(MPI_Status*) is to cast away the const
  (void)MPI_Get_count((MPI_Status*)&mpi_status, datatype, &count);
  return count;
}

inline bool
_REAL_MPI_::Status::Is_cancelled() const
{
  int t;
  (void)MPI_Test_cancelled((MPI_Status*)&mpi_status, &t);
  return (bool) t;
}

inline int
_REAL_MPI_::Status::Get_elements(const _REAL_MPI_::Datatype& datatype) const
{
  int count;
  (void)MPI_Get_elements((MPI_Status*)&mpi_status, datatype, &count);
  return count;
}

//
// Status Access
//
inline int
_REAL_MPI_::Status::Get_source() const
{
  int source;
  source = mpi_status.MPI_SOURCE;
  return source;
}

inline void
_REAL_MPI_::Status::Set_source(int source)
{
  mpi_status.MPI_SOURCE = source;
}

inline int
_REAL_MPI_::Status::Get_tag() const
{
  int tag;
  tag = mpi_status.MPI_TAG;
  return tag;
}

inline void
_REAL_MPI_::Status::Set_tag(int tag)
{
  mpi_status.MPI_TAG = tag;
}

inline int
_REAL_MPI_::Status::Get_error() const
{
  int error;
  error = mpi_status.MPI_ERROR;
  return error;
}

inline void
_REAL_MPI_::Status::Set_error(int error)
{
  mpi_status.MPI_ERROR = error;
}

inline void
_REAL_MPI_::Status::Set_elements(const _REAL_MPI_::Datatype& datatype, int count)
{
    MPI_Status_set_elements(&mpi_status, datatype, count);
}

inline void
_REAL_MPI_::Status::Set_cancelled(bool flag)
{
    MPI_Status_set_cancelled(&mpi_status, (int) flag);
}

#ifdef HPMPI_LONG_EXTENTIONS
#include "mpiCC/statusL_inln.h"
#endif

