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

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Intercomm::Dup() const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_dup(mpi_comm, &newcomm);
  return newcomm;
}

inline _REAL_MPI_::Intercomm&
_REAL_MPI_::Intercomm::Clone() const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_dup(mpi_comm, &newcomm);
  _REAL_MPI_::Intercomm* dup = new _REAL_MPI_::Intercomm(newcomm);
  return *dup;
}

inline int
_REAL_MPI_::Intercomm::Get_remote_size() const
{
  int size;
  (void)MPI_Comm_remote_size(mpi_comm, &size);
  return size;
}

inline _REAL_MPI_::Group
_REAL_MPI_::Intercomm::Get_remote_group() const
{
  MPI_Group group;
  (void)MPI_Comm_remote_group(mpi_comm, &group);
  return group;
}

inline _REAL_MPI_::Intracomm
_REAL_MPI_::Intercomm::Merge(bool high)
{
  MPI_Comm newcomm;
  (void)MPI_Intercomm_merge(mpi_comm, (int)high, &newcomm);
  return newcomm;
}

//
// Extended Collective Operations
//

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Intercomm::Create(const Group& group) const
{
  MPI_Comm newcomm;
  (void) MPI_Comm_create(mpi_comm, (MPI_Group) group, &newcomm);
  return newcomm;
}

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Intercomm::Split(int color, int key) const
{
  MPI_Comm newcomm;
  (void) MPI_Comm_split(mpi_comm, color, key, &newcomm);
  return newcomm;
}
