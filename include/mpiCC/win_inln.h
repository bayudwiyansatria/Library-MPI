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
// Miscellany
//

inline _REAL_MPI_::Errhandler
_REAL_MPI_::Win::Create_errhandler(_REAL_MPI_::Win::Errhandler_fn* function)
{
  MPI_Errhandler errhandler;
  (void) MPI_Win_create_errhandler((MPI_Win_errhandler_function *)function,
				   &errhandler);
  return errhandler;
}

inline _REAL_MPI_::Errhandler
_REAL_MPI_::Win:: Get_errhandler() const
{
   MPI_Errhandler errhandler;
   (void) MPI_Win_get_errhandler(mpi_win, &errhandler);
   return errhandler;
}

inline void
_REAL_MPI_::Win::Set_errhandler(const _REAL_MPI_::Errhandler& errhandler)
{
  (void) MPI_Win_set_errhandler(mpi_win, errhandler);
}

//
// One sided communication
//

inline void
_REAL_MPI_::Win::Accumulate(const void* origin_addr, int origin_count,
	       	const _REAL_MPI_::Datatype& origin_datatype, int target_rank,
	       	_REAL_MPI_::Aint target_disp, int target_count,
	       	const _REAL_MPI_::Datatype& target_datatype,
	       	const _REAL_MPI_::Op& op) const
{
  (void) MPI_Accumulate((void*) origin_addr, origin_count, origin_datatype,
			target_rank, target_disp, target_count,
			target_datatype, op, mpi_win);

}

inline void
_REAL_MPI_::Win::Complete() const
{
  (void) MPI_Win_complete(mpi_win);
}

inline  _REAL_MPI_::Win
_REAL_MPI_::Win::Create(const void* base, _REAL_MPI_::Aint size,
			int disp_unit, const _REAL_MPI_::Info& info,
			const _REAL_MPI_::Intracomm& comm)
{
  MPI_Win newwin;
  (void) MPI_Win_create((void *)base, size, disp_unit, info, comm, &newwin);
  return newwin;
}

inline void
_REAL_MPI_::Win::Fence(int assert) const
{
  (void) MPI_Win_fence(assert, mpi_win);
}

inline void
_REAL_MPI_::Win::Free()
{
  (void) MPI_Win_free(&mpi_win);
}

inline void
_REAL_MPI_::Win::Get(const void *origin_addr, int origin_count,
		     const _REAL_MPI_::Datatype& origin_datatype,
		     int target_rank, _REAL_MPI_::Aint target_disp,
		     int target_count,
		     const _REAL_MPI_::Datatype& target_datatype) const
{
  (void) MPI_Get((void*) origin_addr, origin_count, origin_datatype,
		     target_rank, target_disp,
		     target_count, target_datatype, mpi_win);

}

inline _REAL_MPI_::Group
_REAL_MPI_::Win::Get_group() const
{
  MPI_Group mpi_group;
  (void) MPI_Win_get_group(mpi_win, &mpi_group);
  return mpi_group;
}

inline void
_REAL_MPI_::Win::Lock(int lock_type, int rank, int assert) const
{
  (void) MPI_Win_lock(lock_type, rank, assert, mpi_win);
}

inline void
_REAL_MPI_::Win::Post(const _REAL_MPI_::Group& group, int assert) const
{
  (void) MPI_Win_post(group, assert, mpi_win);
}

inline void
_REAL_MPI_::Win::Put(const void* origin_addr, int origin_count,
		     const _REAL_MPI_::Datatype& origin_datatype,
		     int target_rank, _REAL_MPI_::Aint target_disp,
		     int target_count,
		     const _REAL_MPI_::Datatype& target_datatype) const
{
  (void) MPI_Put((void*) origin_addr, origin_count, origin_datatype,
		 target_rank, target_disp, target_count,
		 target_datatype, mpi_win);

}

inline void
_REAL_MPI_::Win::Start(const _REAL_MPI_::Group& group, int assert) const
{
  (void) MPI_Win_start(group, assert, mpi_win);
}

inline bool
_REAL_MPI_::Win::Test() const
{
  int flag;
  MPI_Win_test(mpi_win, &flag);
  return (bool) flag;

}

inline void
_REAL_MPI_::Win::Unlock(int rank) const
{
  (void) MPI_Win_unlock(rank, mpi_win);
}

inline void
_REAL_MPI_::Win::Wait() const
{
  (void) MPI_Win_wait(mpi_win);
}

#ifdef HPMPI_LONG_EXTENTIONS
#include "mpiCC/winL_inln.h"
#endif

//
// External Interfaces
//

inline void
_REAL_MPI_::Win::Call_errhandler(int errorcode) const
{
  (void) MPI_Win_call_errhandler(mpi_win, errorcode);
}

inline int
_REAL_MPI_::Win::Create_keyval(_REAL_MPI_::Win::Copy_attr_function*
			       win_copy_attr_fn,
			       _REAL_MPI_::Win::Delete_attr_function*
			       win_delete_attr_fn, void* extra_state)
{
  int val;
  (void) MPI_Win_create_keyval((MPI_Win_copy_attr_function *)win_copy_attr_fn,
			       (MPI_Win_delete_attr_function *)
			       win_delete_attr_fn, &val,extra_state);
  return val;
}

inline void
_REAL_MPI_::Win::Delete_attr(int win_keyval)
{
  (void) MPI_Win_delete_attr(mpi_win, win_keyval);
}

inline void
_REAL_MPI_::Win::Free_keyval(int& win_keyval)
{
  (void) MPI_Win_free_keyval(&win_keyval);
}

inline bool
_REAL_MPI_::Win::Get_attr(int win_keyval, void* attribute_val) const
{
  int ret;
  (void) MPI_Win_get_attr(mpi_win, win_keyval, attribute_val, &ret);
  return (bool) ret;
}

inline bool
_REAL_MPI_::Win::Get_attr(const Win& win, int win_keyval,
			  void* attribute_val) const
{
  int ret;
  (void) MPI_Win_get_attr(win, win_keyval, attribute_val, &ret);
  return (bool) ret;
}

inline void
_REAL_MPI_::Win::Get_name(char* win_name, int& resultlen) const
{
  (void) MPI_Win_get_name(mpi_win, win_name, &resultlen);
}

inline void
_REAL_MPI_::Win::Set_attr(int win_keyval, const void* attribute_val)
{
  (void) MPI_Win_set_attr(mpi_win, win_keyval,(void *) attribute_val);
}

inline void
_REAL_MPI_::Win::Set_name(const char* win_name)
{
  (void) MPI_Win_set_name(mpi_win, (char *)win_name);
}

inline int
_REAL_MPI_::Win::NULL_COPY_FN(const _REAL_MPI_::Win& oldwin,
                              int win_keyval,
                              void* extra_state,
                              void* attribute_val_in,
                              void* attribute_val_out,
                              bool& flag)
{
  int f = (int)flag;
  int ret;
  if (MPI_WIN_NULL_COPY_FN != 0) {

    // Portland pgCC 5.0-2 has a bug that we have to workaround here.
    // MPI_NULL_COPY_FN is actually a #define for ((MPI_Copy_function
    // *) 0).  If we try to invoke it, such as:
    //   ret = MPI_NULL_COPY_FN(...);
    // the preprocessor will resolve this to:
    //   ret = ((MPI_Copy_function *) 0)(...);
    // which should be fine.  But unfortunately, pgCC 5.0-2 makes this
    // into a real symbol that will refuse to link.  The workaround is
    // to assign this into a temp variable and then invoke through the
    // function pointer.  This shouldn't be necessary.  :-(

    MPI_Win_copy_attr_function *stupid_compiler = MPI_WIN_NULL_COPY_FN;
    ret = stupid_compiler(oldwin, win_keyval, extra_state, attribute_val_in,
                          attribute_val_out, &f);
    flag = (bool)f;
  } else {
    ret = MPI_SUCCESS;
    flag = false;
  }
  return ret;
}

inline int
_REAL_MPI_::Win::DUP_FN(const _REAL_MPI_::Win& oldwin,
                        int win_keyval,
                        void* extra_state,
                        void* attribute_val_in,
                        void* attribute_val_out,
                        bool& flag)
{
  int f = (int)flag;
  int ret;
  ret = MPI_WIN_DUP_FN(oldwin, win_keyval, extra_state, attribute_val_in,
		   attribute_val_out, &f);
  flag = (bool) f;
  return ret;
}

inline int
_REAL_MPI_::Win::NULL_DELETE_FN(_REAL_MPI_::Win& win,
                                int win_keyval,
                                void* attribute_val,
                                void* extra_state)
{
  if (MPI_NULL_DELETE_FN != 0) {

    // See note in MPI_NULL_COPY_FN.

    MPI_Win_delete_attr_function *stupid_compiler = MPI_WIN_NULL_DELETE_FN;
    return stupid_compiler(win, win_keyval, attribute_val, extra_state);
  } else
    return MPI_SUCCESS;
}

#if 0
//
// User defined functions
//

typedef int _REAL_MPI_::Win::Copy_attr_function(const Win& oldwin,
						int win_keyval,
						void* extra_state,
						void* attribute_val_in,
						void* attribute_val_out,
						bool& flag);

typedef int _REAL_MPI_::Win::Delete_attr_function(&win, int win_keyval,
						  void* attribute_val,
						  void* extra_state);

typedef void _REAL_MPI_::Win::Errhandler_fn(Win &, int *, ... );

#endif
