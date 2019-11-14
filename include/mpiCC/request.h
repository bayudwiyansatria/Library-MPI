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

class Request {

#ifndef HP_MPI_NOIO
    friend class MPI::File;
#endif
public:

  // construction / destruction
  Request() { mpi_request = MPI_REQUEST_NULL; }
  virtual ~Request() {}
  Request(const MPI_Request &i) : mpi_request(i) { }

  // copy / assignment
  Request(const Request& r) : mpi_request(r.mpi_request) { }

  Request& operator=(const Request& r) {
    mpi_request = r.mpi_request; return *this; }

  // comparison
  bool operator== (const Request &a)
  { return (bool)(mpi_request == a.mpi_request); }
  bool operator!= (const Request &a)
  { return (bool)!(*this == a); }

  // inter-language operability
  Request& operator= (const MPI_Request &i) {
    mpi_request = i; return *this; }
  operator MPI_Request () const { return mpi_request; }
  //  operator MPI_Request* () const { return (MPI_Request*)&mpi_request; }

  //
  // Point-to-Point Communication
  //

  virtual void Wait(Status &status);

  virtual void Wait();

  virtual bool Test(Status &status);

  virtual bool Test();

  virtual void Free(void);

  static int Waitany(int count, Request array[], Status& status);

  static int Waitany(int count, Request array[]);

  static bool Testany(int count, Request array[], int& index, Status& status);

  static bool Testany(int count, Request array[], int& index);

  static void Waitall(int count, Request req_array[], Status stat_array[]);

  static void Waitall(int count, Request req_array[]);

  static bool Testall(int count, Request req_array[], Status stat_array[]);

  static bool Testall(int count, Request req_array[]);

  static int Waitsome(int incount, Request req_array[],
			     int array_of_indices[], Status stat_array[]) ;

  static int Waitsome(int incount, Request req_array[],
			     int array_of_indices[]);

  static int Testsome(int incount, Request req_array[],
			     int array_of_indices[], Status stat_array[]);

  static int Testsome(int incount, Request req_array[],
			     int array_of_indices[]);

  virtual void Cancel(void) const;

  virtual bool Get_status(Status& status) const;

  virtual bool Get_status() const;

protected:

  MPI_Request mpi_request;

};

class Prequest : public Request {

public:

  Prequest() { }

  Prequest(const Request& p) : Request(p) { }

  Prequest(const MPI_Request &i) : Request(i) { }

  virtual ~Prequest() { }

 // Not included because ambigous overload w/ next operator= for NULL case.
 //  Prequest& operator=(const MPI_Request& r) {
 //    mpi_request = r; return *this; }

  Prequest& operator=(const Prequest& r) {
    mpi_request = r.mpi_request; return *this; }

  virtual void Start();

  static void Startall(int count, Prequest array_of_requests[]);

};

//
// Generalized requests
//
class Grequest : public MPI::Request {
  public:
    typedef int Query_function(void *, Status&);
    typedef int Free_function(void *);
    typedef int Cancel_function(void *, bool);

    Grequest() {}
    Grequest(const Request& req) : Request(req) {}
    Grequest(const MPI_Request &req) : Request(req) {}
    virtual ~Grequest() {}

    Grequest& operator=(const MPI_Request& req) {
        mpi_request = req; return(*this);
    }

    Grequest& operator=(const Grequest& req) {
        mpi_request = req.mpi_request; return(*this);
    }

    static Grequest Start(Query_function *, Free_function *,
            Cancel_function *, void *);

    virtual void Complete();
};

//
// Type used for intercepting Generalized requests in the C++ layer so
// that the type can be converted to C++ types before invoking the
// user-specified C++ callbacks.
//
struct Grequest_intercept_t {
    void *git_extra;
    Grequest::Query_function *git_cxx_query_fn;
    Grequest::Free_function *git_cxx_free_fn;
    Grequest::Cancel_function *git_cxx_cancel_fn;
};
