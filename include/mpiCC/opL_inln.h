/*
 *	Copyright Platform Computing Inc., an IBM company, 1983-2010, 2012
 *
 *	$Revision: 7316 $
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
inline void
_REAL_MPI_::Op::Reduce_local(const void *sendbuf, void *recvbuf, int count,
       const _REAL_MPI_::Datatype & datatype) const
{
  (void)MPI_Reduce_local((void*)sendbuf, recvbuf, count, datatype, mpi_op);
}
inline bool
_REAL_MPI_::Op::Is_commutative(void) const
{
	int flag;
  (void)MPI_Op_commutative(mpi_op, &flag);
  return flag != 0;
}

#ifdef HPMPI_LONG_EXTENTIONS

inline void
_REAL_MPI_::Op::InitL(_REAL_MPI_::User_functionL *func, bool commute)
{
  (void)MPI_Op_createL(op_interceptl , (int) commute, &mpi_op);
  op_user_function = (User_function*)func;
}

inline void
_REAL_MPI_::Op::Reduce_localL(const void *sendbuf, void *recvbuf,
	_REAL_MPI_::Aint count,
       const _REAL_MPI_::Datatype & datatype) const
{
  (void)MPI_Reduce_localL((void*)sendbuf, recvbuf, count, datatype, mpi_op);
}

#endif
