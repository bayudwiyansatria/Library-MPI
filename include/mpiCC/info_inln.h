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

inline _REAL_MPI_::Info
_REAL_MPI_::Info::Create()
{
  MPI_Info newinfo;
  (void) MPI_Info_create(&newinfo);
  return newinfo;
}

inline void
_REAL_MPI_::Info::Delete(const char* key)
{
   (void)MPI_Info_delete(mpi_info, (char*)key);
}

inline _REAL_MPI_::Info
_REAL_MPI_::Info::Dup() const
{
  MPI_Info newinfo;
  (void)MPI_Info_dup(mpi_info, &newinfo);
  return newinfo;
}

inline void
_REAL_MPI_::Info::Free()
{
  (void) MPI_Info_free(&mpi_info);
}

inline bool
_REAL_MPI_::Info::Get(const char* key, int valuelen, char* value) const
{
  int flag;
  (void)MPI_Info_get(mpi_info, (char*)key, valuelen, value, &flag);
  return (bool) flag;
}

inline int
_REAL_MPI_::Info::Get_nkeys() const
{
  int nkeys;
  MPI_Info_get_nkeys(mpi_info, &nkeys);
  return nkeys;
}

inline void
_REAL_MPI_::Info::Get_nthkey(int n, char* key) const
{
  (void) MPI_Info_get_nthkey(mpi_info, n, key);
}

inline bool
_REAL_MPI_::Info::Get_valuelen(const char* key, int& valuelen) const
{
  int flag;
  (void) MPI_Info_get_valuelen(mpi_info, (char*)key, &valuelen, &flag);
  return (bool) flag;
}

inline void
_REAL_MPI_::Info::Set(const char* key, const char* value)
{
  (void) MPI_Info_set(mpi_info, (char*)key, (char*)value);
}
