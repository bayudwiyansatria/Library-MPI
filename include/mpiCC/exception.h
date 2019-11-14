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

class Exception {
public:

  inline Exception(int ec) : error_code(ec), error_string(0), error_class(-1) {
    (void)MPI_Error_class(error_code, &error_class);
    int resultlen;
    error_string = new char[MAX_ERROR_STRING];
    (void)MPI_Error_string(error_code, error_string, &resultlen);
  }
  inline ~Exception() {
    delete[] error_string;
  }
  // Better put in a copy constructor here since we have a string;
  // copy by value (from the default copy constructor) would be
  // disasterous.
  inline Exception(const Exception& a)
    : error_code(a.error_code), error_class(a.error_class)
  {
    error_string = new char[MAX_ERROR_STRING];
    // Rather that force an include of <string.h>, especially this
    // late in the game (recall that this file is included deep in
    // other .h files), we'll just do the copy ourselves.
    for (int i = 0; i < MAX_ERROR_STRING; i++)
      error_string[i] = a.error_string[i];
  }

  inline int Get_error_code() const { return error_code; }

  inline int Get_error_class() const { return error_class; }

  inline const char* Get_error_string() const { return error_string; }

protected:

  int error_code;
  char* error_string;
  int error_class;

};
