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

class Cartcomm : public Intracomm {
public:

  // construction
  Cartcomm() { }
  // copy
  Cartcomm(const Comm_Null& data) : Intracomm(data) { }
  // inter-language operability
  inline Cartcomm(const MPI_Comm& data);

  Cartcomm(const Cartcomm& data) : Intracomm(data.mpi_comm) { }
  // assignment
  Cartcomm& operator=(const Cartcomm& data) {
    mpi_comm = data.mpi_comm; return *this; }
  Cartcomm& operator=(const Comm_Null& data) {
    mpi_comm = data; return *this; }
  // inter-language operability
  Cartcomm& operator=(const MPI_Comm& data) {
    mpi_comm = data; return *this; }

  //
  // Groups, Contexts, and Communicators
  //

  Cartcomm Dup() const;

  virtual Cartcomm& Clone() const;

  //
  // Groups, Contexts, and Communicators
  //

  virtual int Get_dim() const;

  virtual void Get_topo(int maxdims, int dims[], bool periods[],
			int coords[]) const;

  virtual int Get_cart_rank(const int coords[]) const;

  virtual void Get_coords(int rank, int maxdims, int coords[]) const;

  virtual void Shift(int direction, int disp,
		     int &rank_source, int &rank_dest) const;

  virtual Cartcomm Sub(const bool remain_dims[]);

  virtual int Map(int ndims, const int dims[], const bool periods[]) const;

};

//===================================================================
//                    Class Graphcomm
//===================================================================

class Graphcomm : public Intracomm {
public:

  // construction
  Graphcomm() { }
  // copy
  Graphcomm(const Comm_Null& data) : Intracomm(data) { }
  // inter-language operability
  inline Graphcomm(const MPI_Comm& data);

  Graphcomm(const Graphcomm& data) : Intracomm(data.mpi_comm) { }
  // assignment
  Graphcomm& operator=(const Graphcomm& data) {
    mpi_comm = data.mpi_comm; return *this; }
  Graphcomm& operator=(const Comm_Null& data) {
    mpi_comm = data; return *this; }
  // inter-language operability
  Graphcomm& operator=(const MPI_Comm& data) {
    mpi_comm = data; return *this; }

  //
  // Groups, Contexts, and Communicators
  //

  Graphcomm Dup() const;

  virtual Graphcomm& Clone() const;

  //
  //  Process Topologies
  //

  virtual void Get_dims(int nnodes[], int nedges[]) const;

  virtual void Get_topo(int maxindex, int maxedges, int index[],
			int edges[]) const;

  virtual int Get_neighbors_count(int rank) const;

  virtual void Get_neighbors(int rank, int maxneighbors,
			     int neighbors[]) const;

  virtual int Map(int nnodes, const int index[],
		  const int edges[]) const;

};

//===================================================================
//                    Class Distgraphcomm
//===================================================================

class Distgraphcomm : public Intracomm {
public:

  // construction
  Distgraphcomm() { }
  // copy
  Distgraphcomm(const Comm_Null& data) : Intracomm(data) { }
  // inter-language operability
  inline Distgraphcomm(const MPI_Comm& data);

  Distgraphcomm(const Distgraphcomm& data) : Intracomm(data.mpi_comm) { }
  // assignment
  Distgraphcomm& operator=(const Distgraphcomm& data) {
    mpi_comm = data.mpi_comm; return *this; }
  Distgraphcomm& operator=(const Comm_Null& data) {
    mpi_comm = data; return *this; }
  // inter-language operability
  Distgraphcomm& operator=(const MPI_Comm& data) {
    mpi_comm = data; return *this; }

  //
  // Groups, Contexts, and Communicators
  //

  Distgraphcomm Dup() const;

  virtual Distgraphcomm& Clone() const;

  //
  //  Process Topologies
  //

    virtual void Get_dist_neighbors_count(int rank,
		  int indegree[],int outdegree[], bool& weighted) const;

  virtual void Get_dist_neighbors(int maxindegree, int sources[], int sourceweights[],
		  int maxoutdegree, int destinations[], int destweights[]) const;

};

