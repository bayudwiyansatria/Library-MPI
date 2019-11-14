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

inline
_REAL_MPI_::Intracomm::Intracomm(const MPI_Comm& data) {
  int flag;
  if (MPI::Is_initialized() && (data != MPI_COMM_NULL)) {
    (void)MPI_Comm_test_inter(data, &flag);
    if (flag)
      mpi_comm = MPI_COMM_NULL;
    else
      mpi_comm = data;
  }
  else {
    mpi_comm = data;
  }
  if (mpi_comm != MPI_COMM_NULL &&
  mpi_comm != MPI_COMM_WORLD && mpi_comm != MPI_COMM_SELF) {
    comm_pair_t* comm_type = new comm_pair_t((Comm*) this, eIntracomm);
    _REAL_MPI_::Comm::mpi_comm_map[mpi_comm] = comm_type;
  }
}

inline _REAL_MPI_::Intracomm
_REAL_MPI_::Intracomm::Dup() const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_dup(mpi_comm, &newcomm);
  return newcomm;
}

inline _REAL_MPI_::Intracomm&
_REAL_MPI_::Intracomm::Clone() const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_dup(mpi_comm, &newcomm);
  _REAL_MPI_::Intracomm* dup = new _REAL_MPI_::Intracomm(newcomm);
  return *dup;
}

inline _REAL_MPI_::Intracomm
_REAL_MPI_::Intracomm::Create(const _REAL_MPI_::Group& group) const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_create(mpi_comm, group, &newcomm);
  return newcomm;
}

inline _REAL_MPI_::Intracomm
_REAL_MPI_::Intracomm::Split(int color, int key) const
{
  MPI_Comm newcomm;
  (void)MPI_Comm_split(mpi_comm, color, key, &newcomm);
  return newcomm;
}

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Intracomm::Create_intercomm(int local_leader,
					const _REAL_MPI_::Comm& peer_comm,
					int remote_leader, int tag) const
{
  MPI_Comm newintercomm;
  (void)MPI_Intercomm_create(mpi_comm, local_leader, peer_comm,
			     remote_leader, tag, &newintercomm);
  return newintercomm;
}

inline _REAL_MPI_::Cartcomm
_REAL_MPI_::Intracomm::Create_cart(int ndims, const int dims[],
				   const bool periods[], bool reorder) const
{
  int *int_periods = new int [ndims];
  for (int i=0; i<ndims; i++)
    int_periods[i] = (int) periods[i];

  MPI_Comm newcomm;
  (void)MPI_Cart_create(mpi_comm, ndims, (int*)dims,
		      int_periods, (int)reorder, &newcomm);
  delete [] int_periods;
  return newcomm;
}

inline _REAL_MPI_::Graphcomm
_REAL_MPI_::Intracomm::Create_graph(int nnodes, const int index[],
				    const int edges[], bool reorder) const
{
  MPI_Comm newcomm;
  (void)MPI_Graph_create(mpi_comm, nnodes, (int*)index,
		       (int*)edges, (int)reorder, &newcomm);
  return newcomm;
}

inline _REAL_MPI_::Distgraphcomm
_REAL_MPI_::Intracomm::Dist_graph_create(int n, const int sources[], const int degrees[],
	       const int destinations[], const int weights[],
	       MPI::Info& info, bool reorder) const
{
  MPI_Comm newcomm;
  (void)MPI_Dist_graph_create(mpi_comm, n, (int*)sources, (int*)degrees,
		       (int*)destinations, (int*)weights, info, (int)reorder, &newcomm);
  return newcomm;
}
inline _REAL_MPI_::Distgraphcomm
_REAL_MPI_::Intracomm::Dist_graph_create(int n, const int sources[], const int degrees[],
	       const int destinations[], MPI::Info& info, bool reorder) const
{
  MPI_Comm newcomm;
  (void)MPI_Dist_graph_create(mpi_comm, n, (int*)sources, (int*)degrees,
		       (int*)destinations, (int*)MPI_UNWEIGHTED, info, (int)reorder, &newcomm);
  return newcomm;
}
inline _REAL_MPI_::Distgraphcomm
_REAL_MPI_::Intracomm::Dist_graph_create_adjacent(int indegree, const int sources[], const int sourceweights[],
	       int outdegree, const int destinations[], const int destweights[],
	       MPI::Info& info, bool reorder) const
{
  MPI_Comm newcomm;
  (void)MPI_Dist_graph_create_adjacent(mpi_comm, indegree, (int*)sources, (int*)sourceweights,
		       outdegree, (int*)destinations, (int*)destweights, info, (int)reorder, &newcomm);
  return newcomm;
}
inline _REAL_MPI_::Distgraphcomm
_REAL_MPI_::Intracomm::Dist_graph_create_adjacent(int indegree, const int sources[],
	       int outdegree, const int destinations[],
	       MPI::Info& info, bool reorder) const
{
  MPI_Comm newcomm;
  (void)MPI_Dist_graph_create_adjacent(mpi_comm, indegree, (int*)sources, (int*)MPI_UNWEIGHTED,
		       outdegree, (int*)destinations, (int*)MPI_UNWEIGHTED, info, (int)reorder, &newcomm);
  return newcomm;
}
//
// Process Creation and Management
//

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Intracomm::Accept(const char* port_name,
			      const _REAL_MPI_::Info& info,
			      int root) const
{
  MPI_Comm newcomm;
  (void) MPI_Comm_accept((char *) port_name, info, root, mpi_comm,
			 &newcomm);
  return newcomm;
}

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Intracomm::Connect(const char* port_name,
			       const _REAL_MPI_::Info& info,
			       int root) const
{
  MPI_Comm newcomm;
  (void) MPI_Comm_connect((char *) port_name, info, root, mpi_comm,
			  &newcomm);
  return newcomm;
}

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Intracomm::Spawn(const char* command, const char* argv[],
			     int maxprocs, const _REAL_MPI_::Info& info,
			     int root) const
{
  MPI_Comm newcomm;
  (void) MPI_Comm_spawn((char *) command, (char **) argv, maxprocs,
			info, root, mpi_comm, &newcomm,
			(int *)MPI_ERRCODES_IGNORE);
  return newcomm;
}

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Intracomm::Spawn(const char* command, const char* argv[],
                             int maxprocs, const _REAL_MPI_::Info& info,
                             int root, int array_of_errcodes[]) const
{
  MPI_Comm newcomm;
  (void) MPI_Comm_spawn((char *) command, (char **) argv, maxprocs,
                        info, root, mpi_comm, &newcomm,
			array_of_errcodes);
  return newcomm;
}

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Intracomm::Spawn_multiple(int count,
				      const char* array_of_commands[],
				      const char** array_of_argv[],
				      const int array_of_maxprocs[],
				      const _REAL_MPI_::Info array_of_info[], int root)
{
  MPI_Comm newcomm;
  MPI_Info* info_array = new MPI_Info[count];
  int i;
  for (i = 0; i < count; i++)
	info_array[i] = array_of_info[i];

  MPI_Comm_spawn_multiple(count, (char **) array_of_commands,
			  (char ***) array_of_argv, (int *) array_of_maxprocs,
			  info_array, root,
			  mpi_comm, &newcomm, (int *)MPI_ERRCODES_IGNORE);
  return newcomm;
}

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Intracomm::Spawn_multiple(int count,
                                      const char* array_of_commands[],
                                      const char** array_of_argv[],
                                      const int array_of_maxprocs[],
                                      const _REAL_MPI_::Info array_of_info[], int root,
				      int array_of_errcodes[])
{
  MPI_Comm newcomm;
  MPI_Info* info_array = new MPI_Info[count];
  int i;
  for (i = 0; i < count; i++)
	info_array[i] = array_of_info[i];

  MPI_Comm_spawn_multiple(count, (char **) array_of_commands,
                          (char ***) array_of_argv, (int *) array_of_maxprocs,
                          info_array, root,
                          mpi_comm, &newcomm, array_of_errcodes);
  return newcomm;
}

