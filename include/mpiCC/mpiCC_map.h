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

#ifndef _MPICC_MAP_H
#define _MPICC_MAP_H

#include "mpiCC/mpiCC_list.h"
typedef mpi2cppList mpi2cppContainer;

template <class TYPE1, class TYPE2>
class mpi2cppMap {
  mpi2cppContainer c;
public:

  typedef TYPE1 key_t;
  typedef TYPE2 value_t;
  typedef mpi2cppList::iter iter;

  struct Pair {
    Pair(key_t f, value_t s) : first(f), second(s) {}
    Pair() : first((key_t) 0), second((value_t) 0) { }
    key_t first;
    value_t second;
  };

  mpi2cppMap() { }

  ~mpi2cppMap() {
    for (iter i = c.begin(); i != c.end(); i++) {
      delete (Pair*)(*i);
    }
  }

  Pair* begin();
  Pair* end();

  value_t& operator[](key_t key)
  {
    value_t* found = (value_t*)0;
    for (iter i = c.begin(); i != c.end(); i++) {
      if (((Pair*)*i)->first == key)
	found = &((Pair*)*i)->second;
    }
    if (! found) {
      iter tmp = c.insert(c.begin(), new Pair(key, (value_t) 0));
      found = &((Pair*)*tmp)->second;
    }
    return *found;
  }

  void erase(key_t key)
  {
    for (iter i = c.begin(); i != c.end(); i++) {
      if (((Pair*)*i)->first == key) {
	delete (Pair*)*i;
	c.erase(i); break;
      }
    }
  }
};

#endif // _MPICC_MAP_H

