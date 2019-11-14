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

class Intracomm : public Comm {
public:

  // construction
  Intracomm() { }
  // copy
  Intracomm(const Comm_Null& data) : Comm(data) { }
  // inter-language operability

  Intracomm(const Intracomm& data) : Comm(data.mpi_comm) { }

  /*inline*/ Intracomm(const MPI_Comm& data);

  // assignment
  Intracomm& operator=(const Intracomm& data) {
    mpi_comm = data.mpi_comm; return *this;
  }

  Intracomm& operator=(const Comm_Null& data) {
    mpi_comm = data; return *this;
  }

  // inter-language operability
  Intracomm& operator=(const MPI_Comm& data) {
    mpi_comm = data; return *this; }

  Intracomm
  Dup() const;

  virtual Intracomm& Clone() const;

  virtual Intracomm
  Create(const Group& group) const;

  virtual Intracomm
  Split(int color, int key) const;

  virtual Intercomm
  Create_intercomm(int local_leader, const Comm& peer_comm,
		   int remote_leader, int tag) const;

  virtual Cartcomm
  Create_cart(int ndims, const int dims[],
	      const bool periods[], bool reorder) const;

  virtual Graphcomm
  Create_graph(int nnodes, const int index[],
	       const int edges[], bool reorder) const;

  virtual Distgraphcomm
  Dist_graph_create(int n, const int sources[], const int degrees[],
	       const int destinations[], const int weights[],
	       MPI::Info& info, bool reorder) const;
  virtual Distgraphcomm
  Dist_graph_create(int n, const int sources[], const int degrees[],
	       const int destinations[], MPI::Info& info, bool reorder) const;
  virtual Distgraphcomm
  Dist_graph_create_adjacent(int indegree, const int sources[], const int sourceweights[],
	       int outdegree, const int destinations[], const int destweights[],
	       MPI::Info& info, bool reorder) const;
  virtual Distgraphcomm
  Dist_graph_create_adjacent(int indegree, const int sources[],
	       int outdegree, const int destinations[],
	       MPI::Info& info, bool reorder) const;
  //
  // Process Creation and Management
  //

  virtual Intercomm Accept(const char* port_name, const Info& info, int root)
    const;

  virtual Intercomm Connect(const char* port_name, const Info& info, int root)
    const;

  virtual Intercomm Spawn(const char* command, const char* argv[],
                          int maxprocs, const Info& info, int root) const;

  virtual Intercomm Spawn(const char* command, const char* argv[],
                          int maxprocs, const Info& info,
                          int root, int array_of_errcodes[]) const;

  virtual Intercomm Spawn_multiple(int count, const char* array_of_commands[],
                                   const char** array_of_argv[],
                                   const int array_of_maxprocs[],
                                   const Info array_of_info[], int root);

  virtual Intercomm Spawn_multiple(int count, const char* array_of_commands[],
                                   const char** array_of_argv[],
                                   const int array_of_maxprocs[],
                                   const Info array_of_info[], int root,
                                   int array_of_errcodes[]);

};
