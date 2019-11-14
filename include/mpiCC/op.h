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

class Op {
public:

  // construction
  Op();
  Op(const MPI_Op &i);
  Op(const Op& op);

  // destruction
  virtual ~Op();

  // assignment
  Op& operator=(const Op& op);
  Op& operator= (const MPI_Op &i);

  // comparison
  inline bool operator== (const Op &a);
  inline bool operator!= (const Op &a);

  // conversion functions for inter-language operability
  inline operator MPI_Op () const;

  inline operator MPI_Op* ();

  // Collective Communication
  virtual void Init(User_function *func, bool commute);
  virtual void Free();
  virtual void
  Reduce_local(const void *sendbuf, void *recvbuf, int count,
	 const Datatype & datatype) const;
  virtual bool
	 Is_commutative(void) const;
#ifdef HPMPI_LONG_EXTENTIONS
  /* User_functionL defined in mpiL.h, included by mpi.h */
  virtual void InitL(User_functionL *func, bool commute);
  virtual void
  Reduce_localL(const void *sendbuf, void *recvbuf, _REAL_MPI_::Aint count,
	 const Datatype & datatype) const;
#endif

  User_function *op_user_function;  /* This can point to User_functionL's as well */
protected:
  MPI_Op mpi_op;

};

