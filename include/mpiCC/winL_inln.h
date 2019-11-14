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

#ifdef HPMPI_LONG_EXTENTIONS

//
// One sided communication
//

inline void
_REAL_MPI_::Win::AccumulateL(const void* origin_addr, _REAL_MPI_::Aint origin_count,
	       	const _REAL_MPI_::Datatype& origin_datatype, int target_rank,
	       	_REAL_MPI_::Aint target_disp, _REAL_MPI_::Aint target_count,
	       	const _REAL_MPI_::Datatype& target_datatype,
	       	const _REAL_MPI_::Op& op) const
{
  (void) MPI_AccumulateL((void*) origin_addr, origin_count, origin_datatype,
			target_rank, target_disp, target_count,
			target_datatype, op, mpi_win);

}

inline  _REAL_MPI_::Win
_REAL_MPI_::Win::CreateL(const void* base, _REAL_MPI_::Aint size,
			_REAL_MPI_::Aint disp_unit, const _REAL_MPI_::Info& info,
			const _REAL_MPI_::Intracomm& comm)
{
  MPI_Win newwin;
  (void) MPI_Win_createL((void *)base, size, disp_unit, info, comm, &newwin);
  return newwin;
}

inline void
_REAL_MPI_::Win::GetL(const void *origin_addr, _REAL_MPI_::Aint origin_count,
		     const _REAL_MPI_::Datatype& origin_datatype,
		     int target_rank, _REAL_MPI_::Aint target_disp,
		     _REAL_MPI_::Aint target_count,
		     const _REAL_MPI_::Datatype& target_datatype) const
{
  (void) MPI_GetL((void*) origin_addr, origin_count, origin_datatype,
		     target_rank, target_disp,
		     target_count, target_datatype, mpi_win);

}

inline void
_REAL_MPI_::Win::PutL(const void* origin_addr, _REAL_MPI_::Aint origin_count,
		     const _REAL_MPI_::Datatype& origin_datatype,
		     int target_rank, _REAL_MPI_::Aint target_disp,
		     _REAL_MPI_::Aint target_count,
		     const _REAL_MPI_::Datatype& target_datatype) const
{
  (void) MPI_PutL((void*) origin_addr, origin_count, origin_datatype,
		 target_rank, target_disp, target_count,
		 target_datatype, mpi_win);

}

#endif
