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

class Info {

  friend class MPI::Comm; //so I can access pmpi_info data member in comm.cc
  friend class MPI::Request; //and also from request.cc

public:

  Info() { }
  // copy
  Info(const Info& data) : mpi_info(data.mpi_info) { }

  Info(const MPI_Info &i) : mpi_info(i) { }

  virtual ~Info() {}

  Info& operator=(const Info& data) {
    mpi_info = data.mpi_info; return *this; }

  // comparison, don't need for info

  // inter-language operability
  Info& operator= (const MPI_Info &i) {
    mpi_info = i; return *this; }
  operator MPI_Info () const { return mpi_info; }
  //  operator MPI_Info* () const { return (MPI_Info*)&mpi_info; }

  static Info Create();

  virtual void Delete(const char* key);

  virtual Info Dup() const;

  virtual void Free();

  virtual bool Get(const char* key, int valuelen, char* value) const;

  virtual int Get_nkeys() const;

  virtual void Get_nthkey(int n, char* key) const;

  virtual bool Get_valuelen(const char* key, int& valuelen) const;

  virtual void Set(const char* key, const char* value);

protected:

  MPI_Info mpi_info;

};
