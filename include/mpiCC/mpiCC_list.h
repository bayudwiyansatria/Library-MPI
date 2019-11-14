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

#ifndef _MPICC_LIST_H
#define _MPICC_LIST_H

class mpi2cppList {
public:
  typedef void* Data;
  class iter;

  class Link {
    friend class mpi2cppList;
    friend class iter;
    Data data;
    Link *next;
    Link *prev;
    Link() { }
    Link(Data d, Link* p, Link* n) : data(d), next(n), prev(p) { }
  };

  class iter {
    friend class mpi2cppList;
    Link* node;
  public:
    iter(Link* n) : node(n) { }
    iter& operator++() { node = node->next; return *this; }
    iter operator++(int) { iter tmp = *this; ++(*this); return tmp; }
    Data& operator*() const { return node->data; }
    bool operator==(const iter& x) const { return (bool)(node == x.node); }
    bool operator!=(const iter& x) const { return (bool)(node != x.node); }
  };

  mpi2cppList() { _end.prev = &_end; _end.next = &_end; }
  virtual ~mpi2cppList() {
    for (iter i = begin(); i != end(); ) {
      Link* garbage = i.node; i++;
      delete garbage;
    }
  }
  virtual iter begin() { return _end.next; }
  virtual iter end() { return &_end; }
  virtual iter insert(iter p, Data d) {
    iter pos(p);
    Link* n = new Link(d, pos.node->prev, pos.node);
    pos.node->prev->next = n;
    pos.node->prev = n;
    return n;
  }
  void erase(iter pos) {
    pos.node->prev->next = pos.node->next;
    pos.node->next->prev = pos.node->prev;
    delete pos.node;
  }

protected:
  Link _end;
};

#endif // _MPICC_LIST_H

