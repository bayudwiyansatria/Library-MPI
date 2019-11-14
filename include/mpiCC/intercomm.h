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

class Intercomm : public Comm {

public:

  // construction
  Intercomm() : Comm(MPI_COMM_NULL) { }
  // copy
  Intercomm(const Comm_Null& data) : Comm(data) { }
  // inter-language operability
  Intercomm(const MPI_Comm& data) : Comm(data) { }

  // copy
  Intercomm(const Intercomm& data) : Comm(data.mpi_comm) { }
  // assignment
  Intercomm& operator=(const Intercomm& data) {
    mpi_comm = data.mpi_comm; return *this; }
  Intercomm& operator=(const Comm_Null& data) {
    mpi_comm = data; return *this; }
  // inter-language operability
  Intercomm& operator=(const MPI_Comm& data) {
    mpi_comm = data; return *this; }

  //
  // Groups, Contexts, and Communicators
  //

  Intercomm Dup() const;

  virtual Intercomm& Clone() const;

  virtual int Get_remote_size() const;

  virtual Group Get_remote_group() const;

  virtual Intracomm Merge(bool high);

  //
  // Extended Collective Operations
  //

  virtual Intercomm Create(const Group& group) const;

  virtual Intercomm Split(int color, int key) const;

};
