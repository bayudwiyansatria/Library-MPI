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

void
Attach_buffer(void* buffer, int size);

int
Detach_buffer(void*& buffer);

#ifdef HPMPI_LONG_EXTENTIONS
#include "mpiCC/functionsL.h"
#endif

//
// Process Topologies
//

void
Compute_dims(int nnodes, int ndims, int dims[]);

//
// Environmental Inquiry
//

void
Get_processor_name(char* name, int& resultlen);

void
Get_error_string(int errorcode, char* string, int& resultlen);

int
Get_error_class(int errorcode);

int
Add_error_class();

int
Add_error_code(int errorclass);

void
Add_error_string(int errorcode, const char* string);

double
Wtime();

double
Wtick();

void
Init(int& argc, char**& argv);

void
Init();

void
Real_init();

void
Finalize();

bool
Is_initialized();

bool
Is_finalized();
//
// External Interfaces
//

int
Init_thread(int &argc, char**&argv, int required);

int
Init_thread(int required);

bool
Is_thread_main();

int
Query_thread();

//
// Miscellany
//

void*
Alloc_mem(Aint size, const Info& info);

void
Free_mem(void* base);

//
// Process Creation
//

void
Close_port(const char* port_name);

void
Lookup_name(const char* service_name, const Info& info, char* port_name);

void
Open_port(const Info& info, char* port_name);

void
Publish_name(const char* service_name, const Info& info,
	     const char* port_name);

void
Unpublish_name(const char* service_name, const Info& info,
	       const char* port_name);

//
// Profiling
//

void
Pcontrol(const int level, ...);

void
Get_version(int& version, int& subversion);

_REAL_MPI_::Aint
Get_address(void* location);

