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

class Win {

  friend class MPI::Comm; //so I can access pmpi_win data member in comm.cc
  friend class MPI::Request; //and also from request.cc

public:

  Win() { }
  // copy
  Win(const Win& data) : mpi_win(data.mpi_win) { }

  Win(const MPI_Win &i) : mpi_win(i) { }

  virtual ~Win() { }

  Win& operator=(const Win& data) {
    mpi_win = data.mpi_win; return *this; }

  // comparison, don't need for win

  // inter-language operability
  Win& operator= (const MPI_Win &i) {
    mpi_win = i; return *this; }
  operator MPI_Win () const { return mpi_win; }
  //  operator MPI_Win* () const { return (MPI_Win*)&mpi_win; }

  //
  // User defined functions
  //
  typedef int Copy_attr_function(const Win& oldwin, int win_keyval,
				 void* extra_state, void* attribute_val_in,
				 void* attribute_val_out, bool& flag);

  typedef int Delete_attr_function(Win& win, int win_keyval,
				   void* attribute_val, void* extra_state);

  typedef void Errhandler_fn(Win &, int *, ... );

  //
  // Miscellany
  //
  static MPI::Errhandler Create_errhandler(Errhandler_fn* function);
  virtual MPI::Errhandler Get_errhandler() const;
  virtual void Set_errhandler(const MPI::Errhandler& errhandler);

  //
  // One sided communication
  //
  virtual void Accumulate(const void* origin_addr, int origin_count,
			  const MPI::Datatype& origin_datatype,
			  int target_rank, MPI::Aint target_disp,
			  int target_count,
			  const MPI::Datatype& target_datatype,
			  const MPI::Op& op) const;

  virtual void Complete() const;

  static  Win Create(const void* base, MPI::Aint size, int disp_unit,
		     const MPI::Info& info, const MPI::Intracomm& comm);

  virtual void Fence(int assert) const;

  virtual void Free();

  virtual void Get(const void *origin_addr, int origin_count,
		   const MPI::Datatype& origin_datatype, int target_rank,
		   MPI::Aint target_disp, int target_count,
		   const MPI::Datatype& target_datatype) const;

  virtual MPI::Group Get_group() const;

  virtual void Lock(int lock_type, int rank, int assert) const;

  virtual void Post(const MPI::Group& group, int assert) const;

  virtual void Put(const void* origin_addr, int origin_count,
		   const MPI::Datatype& origin_datatype, int target_rank,
		   MPI::Aint target_disp, int target_count,
		   const MPI::Datatype& target_datatype) const;

  virtual void Start(const MPI::Group& group, int assert) const;

  virtual bool Test() const;

  virtual void Unlock(int rank) const;

  virtual void Wait() const;

#ifdef HPMPI_LONG_EXTENTIONS
#include "mpiCC/winL.h"
#endif

  //
  // External Interfaces
  //

  virtual void Call_errhandler(int errorcode) const;

  static int Create_keyval(Copy_attr_function* win_copy_attr_fn,
			   Delete_attr_function* win_delete_attr_fn,
			   void* extra_state);

  virtual void Delete_attr(int win_keyval);

  static void Free_keyval(int& win_keyval);

  bool Get_attr(int win_keyval,
		void* attribute_val) const;

  bool Get_attr(const Win& win, int win_keyval,
		void* attribute_val) const;

  virtual void Get_name(char* win_name, int& resultlen) const;

  virtual void Set_attr(int win_keyval, const void* attribute_val);

  virtual void Set_name(const char* win_name);

  // These functions are *not* part of MPI-2 but are provided
  // because we have them for the C routines.
  static int NULL_COPY_FN(const Win& oldwin,
                          int win_keyval,
                          void* extra_state,
                          void* attribute_val_in,
                          void* attribute_val_out,
                          bool& flag);

  static int DUP_FN(const Win& oldwin,
                    int win_keyval,
                    void* extra_state,
                    void* attribute_val_in,
                    void* attribute_val_out,
                    bool& flag);

  static int NULL_DELETE_FN(Win& win,
                            int win_keyval,
                            void* attribute_val,
                            void* extra_state);

protected:

  MPI_Win mpi_win;

};
