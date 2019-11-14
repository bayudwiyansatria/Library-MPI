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
//   ========   Cartcomm member functions  ========
//

inline
_REAL_MPI_::Cartcomm::Cartcomm(const MPI_Comm& data) {
  int status;
  if (MPI::Is_initialized() && (data != MPI_COMM_NULL)) {
    (void)MPI_Topo_test(data, &status) ;
    if (status == MPI_CART)
      mpi_comm = data;
    else
      mpi_comm = MPI_COMM_NULL;
  }
  else {
    mpi_comm = data;
  }
  if (mpi_comm != MPI_COMM_NULL) {
    comm_pair_t* comm_type = new comm_pair_t((Comm*) this, eCartcomm);
    _REAL_MPI_::Comm::mpi_comm_map[mpi_comm] = comm_type;
  }
}

//
// Groups, Contexts, and Communicators
//

inline _REAL_MPI_::Cartcomm
_REAL_MPI_::Cartcomm::Dup() const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_dup(mpi_comm, &newcomm);
  return newcomm;
}

//
//  Process Topologies
//

inline int
_REAL_MPI_::Cartcomm::Get_dim() const
{
  int ndims;
  (void)MPI_Cartdim_get(mpi_comm, &ndims);
  return ndims;
}

inline void
_REAL_MPI_::Cartcomm::Get_topo(int maxdims, int dims[], bool periods[],
			       int coords[]) const
{
  int *int_periods = new int [maxdims];
  int i;
  for (i=0; i<maxdims; i++) {
    int_periods[i] = (int)periods[i];
  }
  (void)MPI_Cart_get(mpi_comm, maxdims, dims, int_periods, coords);
  for (i=0; i<maxdims; i++) {
    periods[i] = (bool)int_periods[i];
  }
  delete [] int_periods;
}

inline int
_REAL_MPI_::Cartcomm::Get_cart_rank(const int coords[]) const
{
  int rank;
  (void)MPI_Cart_rank(mpi_comm, (int*)coords, &rank);
  return rank;
}

inline void
_REAL_MPI_::Cartcomm::Get_coords(int rank, int maxdims, int coords[]) const
{
  (void)MPI_Cart_coords(mpi_comm, rank, maxdims, coords);
}

inline void
_REAL_MPI_::Cartcomm::Shift(int direction, int disp,
			    int &rank_source, int &rank_dest) const
{
  (void)MPI_Cart_shift(mpi_comm, direction, disp, &rank_source, &rank_dest);
}

inline _REAL_MPI_::Cartcomm
_REAL_MPI_::Cartcomm::Sub(const bool remain_dims[])
{
  int ndims;
  MPI_Cartdim_get(mpi_comm, &ndims);
  int* int_remain_dims = new int[ndims];
  for (int i=0; i<ndims; i++) {
    int_remain_dims[i] = (int)remain_dims[i];
  }
  MPI_Comm newcomm;
  (void)MPI_Cart_sub(mpi_comm, int_remain_dims, &newcomm);
  delete [] int_remain_dims;
  return newcomm;
}

inline int
_REAL_MPI_::Cartcomm::Map(int ndims, const int dims[], const bool periods[]) const
{
  int *int_periods = new int [ndims];
  for (int i=0; i<ndims; i++) {
    int_periods[i] = (int) periods[i];
  }
  int newrank;
  (void)MPI_Cart_map(mpi_comm, ndims, (int*)dims, int_periods, &newrank);
  delete [] int_periods;
  return newrank;
}

inline _REAL_MPI_::Cartcomm&
_REAL_MPI_::Cartcomm::Clone() const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_dup(mpi_comm, &newcomm);
  _REAL_MPI_::Cartcomm* dup = new _REAL_MPI_::Cartcomm(newcomm);
  return *dup;
}

//
//   ========   Graphcomm member functions  ========
//

inline
_REAL_MPI_::Graphcomm::Graphcomm(const MPI_Comm& data) {
  int status;
  if (MPI::Is_initialized() && (data != MPI_COMM_NULL)) {
    (void)MPI_Topo_test(data, &status) ;
    if (status == MPI_GRAPH)
      mpi_comm = data;
    else
      mpi_comm = MPI_COMM_NULL;
  }
  else {
    mpi_comm = data;
  }
  if (mpi_comm != MPI_COMM_NULL) {
    comm_pair_t* comm_type = new comm_pair_t((Comm*) this, eGraphcomm);
    _REAL_MPI_::Comm::mpi_comm_map[mpi_comm] = comm_type;
  }
}

//
// Groups, Contexts, and Communicators
//

inline _REAL_MPI_::Graphcomm
_REAL_MPI_::Graphcomm::Dup() const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_dup(mpi_comm, &newcomm);
  return newcomm;
}

//
//  Process Topologies
//

inline void
_REAL_MPI_::Graphcomm::Get_dims(int nnodes[], int nedges[]) const
{
  (void)MPI_Graphdims_get(mpi_comm, nnodes, nedges);
}

inline void
_REAL_MPI_::Graphcomm::Get_topo(int maxindex, int maxedges, int index[],
	 int edges[]) const
{
  (void)MPI_Graph_get(mpi_comm, maxindex, maxedges, index, edges);
}

inline int
_REAL_MPI_::Graphcomm::Get_neighbors_count(int rank) const
{
  int nneighbors;
  (void)MPI_Graph_neighbors_count(mpi_comm, rank, &nneighbors);
  return nneighbors;
}

inline void
_REAL_MPI_::Graphcomm::Get_neighbors(int rank, int maxneighbors,
	      int neighbors[]) const
{
  (void)MPI_Graph_neighbors(mpi_comm, rank, maxneighbors, neighbors);
}

inline int
_REAL_MPI_::Graphcomm::Map(int nnodes, const int index[],
    const int edges[]) const
{
  int newrank;
  (void)MPI_Graph_map(mpi_comm, nnodes, (int*)index, (int*)edges, &newrank);
  return newrank;
}

inline _REAL_MPI_::Graphcomm&
_REAL_MPI_::Graphcomm::Clone() const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_dup(mpi_comm, &newcomm);
  _REAL_MPI_::Graphcomm* dup = new _REAL_MPI_::Graphcomm(newcomm);
  return *dup;
}
//
//   ========   Distgraphcomm member functions  ========
//

inline
_REAL_MPI_::Distgraphcomm::Distgraphcomm(const MPI_Comm& data) {
  int status;
  if (MPI::Is_initialized() && (data != MPI_COMM_NULL)) {
    (void)MPI_Topo_test(data, &status) ;
    if (status == MPI_DIST_GRAPH)
      mpi_comm = data;
    else
      mpi_comm = MPI_COMM_NULL;
  }
  else {
    mpi_comm = data;
  }
  if (mpi_comm != MPI_COMM_NULL) {
    comm_pair_t* comm_type = new comm_pair_t((Comm*) this, eDistgraphcomm);
    _REAL_MPI_::Comm::mpi_comm_map[mpi_comm] = comm_type;
  }
}

//
// Groups, Contexts, and Communicators
//

inline _REAL_MPI_::Distgraphcomm
_REAL_MPI_::Distgraphcomm::Dup() const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_dup(mpi_comm, &newcomm);
  return newcomm;
}

//
//  Process Topologies
//

inline void
_REAL_MPI_::Distgraphcomm::Get_dist_neighbors_count(int rank,
		  int indegree[],int outdegree[], bool& weighted) const
{
  int w;
  (void)MPI_Dist_graph_neighbors_count(mpi_comm, indegree, outdegree, &w);
  weighted = (bool) w;
}

inline void
_REAL_MPI_::Distgraphcomm::Get_dist_neighbors(int maxindegree, int sources[], int sourceweights[],
		  int maxoutdegree, int destinations[], int destweights[]) const
{
  (void)MPI_Dist_graph_neighbors(mpi_comm, maxindegree, sources, sourceweights,
		  maxoutdegree, destinations, destweights);
}

inline _REAL_MPI_::Distgraphcomm&
_REAL_MPI_::Distgraphcomm::Clone() const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_dup(mpi_comm, &newcomm);
  _REAL_MPI_::Distgraphcomm* dup = new _REAL_MPI_::Distgraphcomm(newcomm);
  return *dup;
}
