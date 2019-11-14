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
// Groups, Contexts, and Communicators
//

inline int
_REAL_MPI_::Group::Get_size() const
{
  int size;
  (void)MPI_Group_size(mpi_group, &size);
  return size;
}

inline int
_REAL_MPI_::Group::Get_rank() const
{
  int rank;
  (void)MPI_Group_rank(mpi_group, &rank);
  return rank;
}

inline void
_REAL_MPI_::Group::Translate_ranks (const _REAL_MPI_::Group& group1, int n,
				    const int ranks1[],
				    const _REAL_MPI_::Group& group2, int ranks2[])
{
  (void)MPI_Group_translate_ranks(group1, n, (int*)ranks1, group2, (int*)ranks2);
}

inline int
_REAL_MPI_::Group::Compare(const _REAL_MPI_::Group& group1, const _REAL_MPI_::Group& group2)
{
  int result;
  (void)MPI_Group_compare(group1, group2, &result);
  return result;
}

inline _REAL_MPI_::Group
_REAL_MPI_::Group::Union(const _REAL_MPI_::Group &group1, const _REAL_MPI_::Group &group2)
{
  MPI_Group newgroup;
  (void)MPI_Group_union(group1, group2, &newgroup);
  return newgroup;
}

inline _REAL_MPI_::Group
_REAL_MPI_::Group::Intersect(const _REAL_MPI_::Group &group1, const _REAL_MPI_::Group &group2)
{
  MPI_Group newgroup;
  (void)MPI_Group_intersection( group1,  group2, &newgroup);
  return newgroup;
}

inline _REAL_MPI_::Group
_REAL_MPI_::Group::Difference(const _REAL_MPI_::Group &group1, const _REAL_MPI_::Group &group2)
{
  MPI_Group newgroup;
  (void)MPI_Group_difference(group1, group2, &newgroup);
  return newgroup;
}

inline _REAL_MPI_::Group
_REAL_MPI_::Group::Incl(int n, const int ranks[]) const
{
  MPI_Group newgroup;
  (void)MPI_Group_incl(mpi_group, n, (int*)ranks, &newgroup);
  return newgroup;
}

inline _REAL_MPI_::Group
_REAL_MPI_::Group::Excl(int n, const int ranks[]) const
{
  MPI_Group newgroup;
  (void)MPI_Group_excl(mpi_group, n, (int*)ranks, &newgroup);
  return newgroup;
}

inline _REAL_MPI_::Group
_REAL_MPI_::Group::Range_incl(int n, const int ranges[][3]) const
{
  MPI_Group newgroup;
  (void)MPI_Group_range_incl(mpi_group, n, (int(*)[3])ranges, &newgroup);
  return newgroup;
}

inline _REAL_MPI_::Group
_REAL_MPI_::Group::Range_excl(int n, const int ranges[][3]) const
{
  MPI_Group newgroup;
  (void)MPI_Group_range_excl(mpi_group, n, (int(*)[3])ranges, &newgroup);
  return newgroup;
}

inline void
_REAL_MPI_::Group::Free()
{
  (void)MPI_Group_free(&mpi_group);
}
