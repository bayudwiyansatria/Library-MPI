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

// construction
inline
MPI::Op::Op() : mpi_op(MPI_OP_NULL) { }

inline
MPI::Op::Op(const MPI_Op &i) : mpi_op(i) { }

inline
MPI::Op::Op(const MPI::Op& op)
  : op_user_function(op.op_user_function), mpi_op(op.mpi_op) { }

inline
MPI::Op::~Op()
{
#if _MPIPP_DEBUG_
  mpi_op = MPI_OP_NULL;
  op_user_function = 0;
#endif
}

inline MPI::Op&
MPI::Op::operator=(const MPI::Op& op) {
  mpi_op = op.mpi_op;
  op_user_function = op.op_user_function;
  return *this;
}

// comparison
inline bool
MPI::Op::operator== (const MPI::Op &a) { return (bool)(mpi_op == a.mpi_op); }

inline bool
MPI::Op::operator!= (const MPI::Op &a) { return (bool)!(*this == a); }

// inter-language operability
inline MPI::Op&
MPI::Op::operator= (const MPI_Op &i) { mpi_op = i; return *this; }

inline
MPI::Op::operator MPI_Op () const { return mpi_op; }

inline
MPI::Op::operator MPI_Op* () { return &mpi_op; }

inline void
_REAL_MPI_::Op::Init(_REAL_MPI_::User_function *func, bool commute)
{
  (void)MPI_Op_create(op_intercept , (int) commute, &mpi_op);
  op_user_function = (User_function*)func;
}

inline void
_REAL_MPI_::Op::Free()
{
  (void)MPI_Op_free(&mpi_op);
}

#ifdef HPMPI_LONG_EXTENTIONS
#include "mpiCC/opL_inln.h"
#endif

