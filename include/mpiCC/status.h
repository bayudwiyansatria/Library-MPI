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

class Status {

  friend class MPI::Comm; //so I can access pmpi_status data member in comm.cc
  friend class MPI::Request; //and also from request.cc
#ifndef HP_MPI_NOIO
  friend class MPI::File; //and also from request.cc
#endif

public:

  Status() { }
  // copy
  Status(const Status& data) : mpi_status(data.mpi_status) { }

  Status(const MPI_Status &i) : mpi_status(i) { }

  virtual ~Status() {}

  Status& operator=(const Status& data) {
    mpi_status = data.mpi_status; return *this; }

  // comparison, don't need for status

  // inter-language operability
  Status& operator= (const MPI_Status &i) {
    mpi_status = i; return *this; }
  operator MPI_Status () const { return mpi_status; }
  //  operator MPI_Status* () const { return (MPI_Status*)&mpi_status; }

  //
  // Point-to-Point Communication
  //

  virtual int Get_count(const Datatype& datatype) const;

  virtual bool Is_cancelled() const;

  virtual int Get_elements(const Datatype& datatype) const;

  //
  // Status Access
  //
  virtual int Get_source() const;

  virtual void Set_source(int source);

  virtual int Get_tag() const;

  virtual void Set_tag(int tag);

  virtual int Get_error() const;

  virtual void Set_error(int error);

  virtual void Set_elements(const MPI::Datatype& datatype, int count);

  virtual void Set_cancelled(bool flag);

#ifdef HPMPI_LONG_EXTENTIONS
#include "mpiCC/statusL.h"
#endif

protected:

  MPI_Status mpi_status;

};
