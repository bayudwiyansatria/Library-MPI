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

class Errhandler {
public:

  // construction / destruction
  inline Errhandler()
    : mpi_errhandler(MPI_ERRHANDLER_NULL) {}

  inline virtual ~Errhandler() { }

  inline Errhandler(const MPI_Errhandler &i)
    : mpi_errhandler(i) {}

 // copy / assignment
  inline Errhandler(const Errhandler& e)
    : handler_fn(e.handler_fn), mpi_errhandler(e.mpi_errhandler) { }

  inline Errhandler& operator=(const Errhandler& e)
  {
    mpi_errhandler = e.mpi_errhandler;
    handler_fn = e.handler_fn;
    return *this;
  }

  // comparison
  inline bool operator==(const Errhandler &a) {
    return (bool)(mpi_errhandler == a.mpi_errhandler); }

  inline bool operator!=(const Errhandler &a) {
    return (bool)!(*this == a); }

  // inter-language operability
  inline Errhandler& operator= (const MPI_Errhandler &i) {
    mpi_errhandler = i; return *this; }

  inline operator MPI_Errhandler() const { return mpi_errhandler; }

  //  inline operator MPI_Errhandler*() { return &mpi_errhandler; }

  //
  // Errhandler access functions
  //

  virtual void Free();

  Comm::Errhandler_fn* handler_fn;

protected:

  MPI_Errhandler mpi_errhandler;

public:
  // took out the friend decls
  //private:

  //this is for ERRORS_THROW_EXCEPTIONS
  //this is called from MPI::Real_init
  inline void init() const {

    // $%%@#%# AIX/POE 2.3.0.0 makes us put in this cast here
    (void)MPI_Errhandler_create((MPI_Handler_function*) &throw_excptn_fctn,
				(MPI_Errhandler *) &mpi_errhandler);

  }

  //this is for ERRORS_THROW_EXCEPTIONS
  //this is called from MPI::Finalize
  inline void free() const {

    (void)MPI_Errhandler_free((MPI_Errhandler *) &mpi_errhandler);

  }
};
