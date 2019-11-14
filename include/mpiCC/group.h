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

class Group {

public:

  // construction
  inline Group() : mpi_group(MPI_GROUP_NULL) { }
  inline Group(const MPI_Group &i) : mpi_group(i) { }

  // copy
  inline Group(const Group& g) : mpi_group(g.mpi_group) { }

  inline virtual ~Group() {}

  inline Group& operator=(const Group& g) { mpi_group = g.mpi_group; return *this; }

  // comparison
  inline bool operator== (const Group &a) { return (bool)(mpi_group == a.mpi_group); }
  inline bool operator!= (const Group &a) { return (bool)!(*this == a); }

  // inter-language operability
  inline Group& operator= (const MPI_Group &i) { mpi_group = i; return *this; }
  inline operator MPI_Group () const { return mpi_group; }
  //  inline operator MPI_Group* () const { return (MPI_Group*)&mpi_group; }

  inline MPI_Group mpi() const { return mpi_group; }

  //
  // Groups, Contexts, and Communicators
  //

  virtual int Get_size() const;

  virtual int Get_rank() const;

  static void Translate_ranks (const Group& group1, int n, const int ranks1[],
			       const Group& group2, int ranks2[]);

  static int Compare(const Group& group1, const Group& group2);

  static Group Union(const Group &group1, const Group &group2);

  static Group Intersect(const Group &group1, const Group &group2);

  static Group Difference(const Group &group1, const Group &group2);

  virtual Group Incl(int n, const int ranks[]) const;

  virtual Group Excl(int n, const int ranks[]) const;

  virtual Group Range_incl(int n, const int ranges[][3]) const;

  virtual Group Range_excl(int n, const int ranges[][3]) const;

  virtual void Free();

protected:

  MPI_Group mpi_group;

};

