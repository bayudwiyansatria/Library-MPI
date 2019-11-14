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
// Point-to-Point Communication
//

inline void
_REAL_MPI_::Request::Wait(_REAL_MPI_::Status &status)
{
  (void)MPI_Wait(&mpi_request, &status.mpi_status);
}

inline void
_REAL_MPI_::Request::Wait()
{
  (void)MPI_Wait(&mpi_request, MPI_STATUS_IGNORE);
}

inline void
_REAL_MPI_::Request::Free()
{
  (void)MPI_Request_free(&mpi_request);
}

inline bool
_REAL_MPI_::Request::Test(_REAL_MPI_::Status &status)
{
  int t;
  (void)MPI_Test(&mpi_request, &t, &status.mpi_status);
  return (bool) t;
}

inline bool
_REAL_MPI_::Request::Test()
{
  int t;
  (void)MPI_Test(&mpi_request, &t, MPI_STATUS_IGNORE);
  return (bool) t;
}

inline int
_REAL_MPI_::Request::Waitany(int count, _REAL_MPI_::Request array[],
			     _REAL_MPI_::Status& status)
{
  int index, i;
  MPI_Request* array_of_requests = new MPI_Request[count];
  for (i=0; i < count; i++)
    array_of_requests[i] = array[i];
  (void)MPI_Waitany(count, array_of_requests, &index, &status.mpi_status);
  for (i=0; i < count; i++)
    array[i] = array_of_requests[i];
  delete [] array_of_requests;
  return index;
}

inline int
_REAL_MPI_::Request::Waitany(int count, _REAL_MPI_::Request array[])
{
  int index, i;
  MPI_Request* array_of_requests = new MPI_Request[count];
  for (i=0; i < count; i++)
    array_of_requests[i] = array[i];
  (void)MPI_Waitany(count, array_of_requests, &index, MPI_STATUS_IGNORE);
  for (i=0; i < count; i++)
    array[i] = array_of_requests[i];
  delete [] array_of_requests;
  return index;
}

inline bool
_REAL_MPI_::Request::Testany(int count, _REAL_MPI_::Request array[],
			     int& index, _REAL_MPI_::Status& status)
{
  int i, flag;
  MPI_Request* array_of_requests = new MPI_Request[count];
  for (i=0; i < count; i++)
    array_of_requests[i] = array[i];
  (void)MPI_Testany(count, array_of_requests, &index, &flag, &status.mpi_status);
  for (i=0; i < count; i++)
    array[i] = array_of_requests[i];
  delete [] array_of_requests;
  return (bool)flag;
}

inline bool
_REAL_MPI_::Request::Testany(int count, _REAL_MPI_::Request array[], int& index)
{
  int i, flag;
  MPI_Request* array_of_requests = new MPI_Request[count];
  for (i=0; i < count; i++)
    array_of_requests[i] = array[i];
  (void)MPI_Testany(count, array_of_requests, &index, &flag,
		    MPI_STATUS_IGNORE);
  for (i=0; i < count; i++)
    array[i] = array_of_requests[i];
  delete [] array_of_requests;
  return (bool)flag;
}

inline void
_REAL_MPI_::Request::Waitall(int count, _REAL_MPI_::Request req_array[],
			     _REAL_MPI_::Status stat_array[])
{
  int i;
  MPI_Request* array_of_requests = new MPI_Request[count];
  MPI_Status* array_of_statuses = new MPI_Status[count];
  for (i=0; i < count; i++)
    array_of_requests[i] = req_array[i];
  (void)MPI_Waitall(count, array_of_requests, array_of_statuses);
  for (i=0; i < count; i++)
    req_array[i] = array_of_requests[i];
  for (i=0; i < count; i++)
    stat_array[i] = array_of_statuses[i];
  delete [] array_of_requests;
  delete [] array_of_statuses;
}

inline void
_REAL_MPI_::Request::Waitall(int count, _REAL_MPI_::Request req_array[])
{
  int i;
  MPI_Request* array_of_requests = new MPI_Request[count];

  for (i=0; i < count; i++)
    array_of_requests[i] = req_array[i];
  (void)MPI_Waitall(count, array_of_requests, MPI_STATUSES_IGNORE);

  for (i=0; i < count; i++)
    req_array[i] = array_of_requests[i];

  delete [] array_of_requests;
}

inline bool
_REAL_MPI_::Request::Testall(int count, _REAL_MPI_::Request req_array[],
			     _REAL_MPI_::Status stat_array[])
{
  int i, flag;
  MPI_Request* array_of_requests = new MPI_Request[count];
  MPI_Status* array_of_statuses = new MPI_Status[count];
  for (i=0; i < count; i++)
    array_of_requests[i] = req_array[i];
  (void)MPI_Testall(count, array_of_requests, &flag, array_of_statuses);
  for (i=0; i < count; i++)
    req_array[i] = array_of_requests[i];
  for (i=0; i < count; i++)
    stat_array[i] = array_of_statuses[i];
  delete [] array_of_requests;
  delete [] array_of_statuses;
  return (bool) flag;
}

inline bool
_REAL_MPI_::Request::Testall(int count, _REAL_MPI_::Request req_array[])
{
  int i, flag;
  MPI_Request* array_of_requests = new MPI_Request[count];

  for (i=0; i < count; i++)
    array_of_requests[i] = req_array[i];
  (void)MPI_Testall(count, array_of_requests, &flag, MPI_STATUSES_IGNORE);

  for (i=0; i < count; i++)
    req_array[i] = array_of_requests[i];
  delete [] array_of_requests;

  return (bool) flag;
}

inline int
_REAL_MPI_::Request::Waitsome(int incount, _REAL_MPI_::Request req_array[],
			      int array_of_indices[], _REAL_MPI_::Status stat_array[])
{
  int i, outcount;
  MPI_Request* array_of_requests = new MPI_Request[incount];
  MPI_Status* array_of_statuses = new MPI_Status[incount];
  for (i=0; i < incount; i++)
    array_of_requests[i] = req_array[i];
  (void)MPI_Waitsome(incount, array_of_requests, &outcount,
		     array_of_indices, array_of_statuses);
  for (i=0; i < incount; i++)
    req_array[i] = array_of_requests[i];
  for (i=0; i < incount; i++)
    stat_array[i] = array_of_statuses[i];
  delete [] array_of_requests;
  delete [] array_of_statuses;
  return outcount;
}

inline int
_REAL_MPI_::Request::Waitsome(int incount, _REAL_MPI_::Request req_array[],
			      int array_of_indices[])
{
  int i, outcount;
  MPI_Request* array_of_requests = new MPI_Request[incount];

  for (i=0; i < incount; i++)
    array_of_requests[i] = req_array[i];
  (void)MPI_Waitsome(incount, array_of_requests, &outcount,
		     array_of_indices, MPI_STATUSES_IGNORE);

  for (i=0; i < incount; i++)
    req_array[i] = array_of_requests[i];
  delete [] array_of_requests;

  return outcount;
}

inline int
_REAL_MPI_::Request::Testsome(int incount, _REAL_MPI_::Request req_array[],
			      int array_of_indices[], _REAL_MPI_::Status stat_array[])
{
  int i, outcount;
  MPI_Request* array_of_requests = new MPI_Request[incount];
  MPI_Status* array_of_statuses = new MPI_Status[incount];
  for (i=0; i < incount; i++)
    array_of_requests[i] = req_array[i];
  (void)MPI_Testsome(incount, array_of_requests, &outcount,
		     array_of_indices, array_of_statuses);
  for (i=0; i < incount; i++)
    req_array[i] = array_of_requests[i];
  for (i=0; i < incount; i++)
    stat_array[i] = array_of_statuses[i];
  delete [] array_of_requests;
  delete [] array_of_statuses;
  return outcount;
}

inline int
_REAL_MPI_::Request::Testsome(int incount, _REAL_MPI_::Request req_array[],
			      int array_of_indices[])
{
  int i, outcount;
  MPI_Request* array_of_requests = new MPI_Request[incount];

  for (i=0; i < incount; i++)
    array_of_requests[i] = req_array[i];
  (void)MPI_Testsome(incount, array_of_requests, &outcount,
		     array_of_indices, MPI_STATUSES_IGNORE);

  for (i=0; i < incount; i++)
    req_array[i] = array_of_requests[i];
  delete [] array_of_requests;

  return outcount;
}

inline void
_REAL_MPI_::Request::Cancel(void) const
{
  (void)MPI_Cancel((MPI_Request*)&mpi_request);
}

inline void
_REAL_MPI_::Prequest::Start()
{
  (void)MPI_Start(&mpi_request);
}

inline void
_REAL_MPI_::Prequest::Startall(int count, _REAL_MPI_:: Prequest array_of_requests[])
{
  //convert the array of Prequests to an array of MPI_requests
  MPI_Request* mpi_requests = new MPI_Request[count];
  int i;
  for (i=0; i < count; i++) {
    mpi_requests[i] = array_of_requests[i];
  }
  (void)MPI_Startall(count, mpi_requests);
  for (i=0; i < count; i++)
    array_of_requests[i].mpi_request = mpi_requests[i] ;
  delete [] mpi_requests;
}

inline bool _REAL_MPI_::Request::Get_status(_REAL_MPI_::Status& status) const
{
    int flag = 0;
    MPI_Status c_status;

    // Call the underlying MPI function rather than simply returning
    // status.mpi_status because we may have to invoke the generalized
    // request query function
    (void)MPI_Request_get_status(mpi_request, &flag, &c_status);
    if (flag) {
        status = c_status;
    }
    return (bool)(flag);
}

inline bool _REAL_MPI_::Request::Get_status() const
{
    int flag;

    // Call the underlying MPI function rather than simply returning
    // status.mpi_status because we may have to invoke the generalized
    // request query function
    (void)MPI_Request_get_status(mpi_request, &flag, MPI_STATUS_IGNORE);
    return (bool)(flag);
}

inline _REAL_MPI_::Grequest
_REAL_MPI_::Grequest::Start(Query_function *query_fn, Free_function *free_fn,
    Cancel_function *cancel_fn, void *extra)
{
    MPI_Request grequest = 0;
    struct Grequest_intercept_t *new_extra =
        new MPI::Grequest_intercept_t;

    new_extra->git_extra = extra;
    new_extra->git_cxx_query_fn = query_fn;
    new_extra->git_cxx_free_fn = free_fn;
    new_extra->git_cxx_cancel_fn = cancel_fn;
    (void) MPI_Grequest_start(grequest_query_fn_intercept,
                              grequest_free_fn_intercept,
                              grequest_cancel_fn_intercept,
                              new_extra, &grequest);

    return(grequest);
}

inline void
_REAL_MPI_::Grequest::Complete()
{
    (void) MPI_Grequest_complete(mpi_request);
}

