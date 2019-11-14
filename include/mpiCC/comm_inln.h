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
// Point-to-Point
//

inline void
_REAL_MPI_::Comm::Send(const void *buf, int count,
		const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  (void)MPI_Send((void *)buf, count, datatype, dest, tag, mpi_comm);
}

inline void
_REAL_MPI_::Comm::Recv(void *buf, int count, const _REAL_MPI_::Datatype & datatype,
		int source, int tag, _REAL_MPI_::Status & status) const
{
  (void)MPI_Recv(buf, count, datatype, source, tag, mpi_comm,
                 &status.mpi_status);
}

inline void
_REAL_MPI_::Comm::Recv(void *buf, int count, const _REAL_MPI_::Datatype & datatype,
				    int source, int tag) const
{
  (void)MPI_Recv(buf, count, datatype, source,
		 tag, mpi_comm, MPI_STATUS_IGNORE);
}

inline void
_REAL_MPI_::Comm::Bsend(const void *buf, int count,
		 const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  (void)MPI_Bsend((void *)buf, count, datatype,
		  dest, tag, mpi_comm);
}

inline void
_REAL_MPI_::Comm::Ssend(const void *buf, int count,
		 const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  (void)MPI_Ssend((void *)buf, count,  datatype, dest,
		  tag, mpi_comm);
}

inline void
_REAL_MPI_::Comm::Rsend(const void *buf, int count,
		 const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  (void)MPI_Rsend((void *)buf, count, datatype,
		  dest, tag, mpi_comm);
}

inline _REAL_MPI_::Request
_REAL_MPI_::Comm::Isend(const void *buf, int count,
		 const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Isend((void *)buf, count, datatype,
		  dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Request
_REAL_MPI_::Comm::Ibsend(const void *buf, int count,
		  const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Ibsend((void *)buf, count, datatype,
		   dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Request
_REAL_MPI_::Comm::Issend(const void *buf, int count,
		  const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Issend((void *)buf, count, datatype,
		   dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Request
_REAL_MPI_::Comm::Irsend(const void *buf, int count,
		  const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Irsend((void *) buf, count, datatype,
		   dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Request
_REAL_MPI_::Comm::Irecv(void *buf, int count,
		 const _REAL_MPI_::Datatype & datatype, int source, int tag) const
{
  MPI_Request request;
  (void)MPI_Irecv(buf, count, datatype, source,
		  tag, mpi_comm, &request);
  return request;
}

inline bool
_REAL_MPI_::Comm::Iprobe(int source, int tag, _REAL_MPI_::Status & status) const
{
  int t;
  (void)MPI_Iprobe(source, tag, mpi_comm, &t, &status.mpi_status);
  return (bool) t;
}

inline bool
_REAL_MPI_::Comm::Iprobe(int source, int tag) const
{
  int t;
  (void)MPI_Iprobe(source, tag, mpi_comm, &t, MPI_STATUS_IGNORE);
  return (bool) t;
}

inline void
_REAL_MPI_::Comm::Probe(int source, int tag, _REAL_MPI_::Status & status) const
{
  (void)MPI_Probe(source, tag, mpi_comm, &status.mpi_status);
}

inline void
_REAL_MPI_::Comm::Probe(int source, int tag) const
{
  (void)MPI_Probe(source, tag, mpi_comm, MPI_STATUS_IGNORE);
}

inline _REAL_MPI_::Prequest
_REAL_MPI_::Comm::Send_init(const void *buf, int count,
		     const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Send_init((void *)buf, count, datatype,
		      dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Prequest
_REAL_MPI_::Comm::Bsend_init(const void *buf, int count,
		      const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Bsend_init((void *)buf, count, datatype,
		       dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Prequest
_REAL_MPI_::Comm::Ssend_init(const void *buf, int count,
		      const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Ssend_init((void *)buf, count, datatype,
		       dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Prequest
_REAL_MPI_::Comm::Rsend_init(const void *buf, int count,
		      const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Rsend_init((void *)buf, count,  datatype,
		       dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Prequest
_REAL_MPI_::Comm::Recv_init(void *buf, int count,
		     const _REAL_MPI_::Datatype & datatype, int source, int tag) const
{
  MPI_Request request;
  (void)MPI_Recv_init(buf, count, datatype, source,
		      tag, mpi_comm, &request);
  return request;
}

inline void
_REAL_MPI_::Comm::Sendrecv(const void *sendbuf, int sendcount,
		    const _REAL_MPI_::Datatype & sendtype, int dest, int sendtag,
		    void *recvbuf, int recvcount,
		    const _REAL_MPI_::Datatype & recvtype, int source,
		    int recvtag, _REAL_MPI_::Status & status) const
{
  (void)MPI_Sendrecv((void *)sendbuf, sendcount,
		     sendtype,
		     dest, sendtag, recvbuf, recvcount,
		     recvtype,
		     source, recvtag, mpi_comm, &status.mpi_status);
}

inline void
_REAL_MPI_::Comm::Sendrecv(const void *sendbuf, int sendcount,
		    const _REAL_MPI_::Datatype & sendtype, int dest, int sendtag,
		    void *recvbuf, int recvcount,
		    const _REAL_MPI_::Datatype & recvtype, int source,
		    int recvtag) const
{
  (void)MPI_Sendrecv((void *)sendbuf, sendcount,
		     sendtype,
		     dest, sendtag, recvbuf, recvcount,
		     recvtype,
		     source, recvtag, mpi_comm, MPI_STATUS_IGNORE);
}

inline void
_REAL_MPI_::Comm::Sendrecv_replace(void *buf, int count,
			    const _REAL_MPI_::Datatype & datatype, int dest,
			    int sendtag, int source,
			    int recvtag, _REAL_MPI_::Status & status) const
{
  (void)MPI_Sendrecv_replace(buf, count, datatype, dest,
			     sendtag, source, recvtag, mpi_comm,
			     &status.mpi_status);
}

inline void
_REAL_MPI_::Comm::Sendrecv_replace(void *buf, int count,
			    const _REAL_MPI_::Datatype & datatype, int dest,
			    int sendtag, int source,
			    int recvtag) const
{
  (void)MPI_Sendrecv_replace(buf, count, datatype, dest,
			     sendtag, source, recvtag, mpi_comm,
			     MPI_STATUS_IGNORE);
}

//
// Groups, Contexts, and Communicators
//

inline _REAL_MPI_::Group
_REAL_MPI_::Comm::Get_group() const
{
  MPI_Group group;
  (void)MPI_Comm_group(mpi_comm, &group);
  return group;
}

inline int
_REAL_MPI_::Comm::Get_size() const
{
  int size;
  (void)MPI_Comm_size (mpi_comm, &size);
  return size;
}

inline int
_REAL_MPI_::Comm::Get_rank() const
{
  int rank;
  (void)MPI_Comm_rank (mpi_comm, &rank);
  return rank;
}

inline int
_REAL_MPI_::Comm::Compare(const _REAL_MPI_::Comm & comm1,
		   const _REAL_MPI_::Comm & comm2)
{
  int result;
  (void)MPI_Comm_compare(comm1, comm2, &result);
  return result;
}

inline void
_REAL_MPI_::Comm::Free(void)
{
  MPI_Comm save = mpi_comm;
  (void)MPI_Comm_free(&mpi_comm);

  if (_REAL_MPI_::Comm::mpi_comm_map[save] != 0)
    delete _REAL_MPI_::Comm::mpi_comm_map[save];
  _REAL_MPI_::Comm::mpi_comm_map.erase(save);
}

inline bool
_REAL_MPI_::Comm::Is_inter() const
{
  int t;
  (void)MPI_Comm_test_inter(mpi_comm, &t);
  return (bool) t;
}

//
// Collective Communication
//

inline void
_REAL_MPI_::Comm::Barrier() const
{
  (void)MPI_Barrier(mpi_comm);
}

inline void
_REAL_MPI_::Comm::Bcast(void *buffer, int count,
      const _REAL_MPI_::Datatype& datatype, int root) const
{
  (void)MPI_Bcast(buffer, count, datatype, root, mpi_comm);
}

inline void
_REAL_MPI_::Comm::Gather(const void *sendbuf, int sendcount,
			      const _REAL_MPI_::Datatype & sendtype,
			      void *recvbuf, int recvcount,
			      const _REAL_MPI_::Datatype & recvtype, int root) const
{
  (void)MPI_Gather((void *)sendbuf, sendcount, sendtype,
		   recvbuf, recvcount, recvtype, root, mpi_comm);
}

inline void
_REAL_MPI_::Comm::Gatherv(const void *sendbuf, int sendcount,
	const _REAL_MPI_::Datatype & sendtype, void *recvbuf,
	const int recvcounts[], const int displs[],
	const _REAL_MPI_::Datatype & recvtype, int root) const
{
  (void)MPI_Gatherv((void *)sendbuf, sendcount,  sendtype,
		    recvbuf, (int *)recvcounts, (int *)displs,
		    recvtype, root, mpi_comm);
}

inline void
_REAL_MPI_::Comm::Scatter(const void *sendbuf, int sendcount,
	const _REAL_MPI_::Datatype & sendtype,
	void *recvbuf, int recvcount,
	const _REAL_MPI_::Datatype & recvtype, int root) const
{
  (void)MPI_Scatter((void *)sendbuf, sendcount, sendtype,
		    recvbuf, recvcount, recvtype, root, mpi_comm);
}

inline void
_REAL_MPI_::Comm::Scatterv(const void *sendbuf, const int sendcounts[],
	 const int displs[], const _REAL_MPI_::Datatype & sendtype,
	 void *recvbuf, int recvcount,
	 const _REAL_MPI_::Datatype & recvtype, int root) const
{
  (void)MPI_Scatterv((void *)sendbuf, (int *) sendcounts,
		     (int *) displs, sendtype,
		     recvbuf, recvcount, recvtype,
		     root, mpi_comm);
}

inline void
_REAL_MPI_::Comm::Allgather(const void *sendbuf, int sendcount,
	  const _REAL_MPI_::Datatype & sendtype, void *recvbuf,
	  int recvcount, const _REAL_MPI_::Datatype & recvtype) const
{
  (void)MPI_Allgather((void *) sendbuf, sendcount,
		      sendtype, recvbuf, recvcount,
		      recvtype, mpi_comm);
}

inline void
_REAL_MPI_::Comm::Allgatherv(const void *sendbuf, int sendcount,
	   const _REAL_MPI_::Datatype & sendtype, void *recvbuf,
	   const int recvcounts[], const int displs[],
	   const _REAL_MPI_::Datatype & recvtype) const
{
  (void)MPI_Allgatherv((void *)sendbuf, sendcount,
		       sendtype, recvbuf,
		       (int *) recvcounts, (int *) displs,
		       recvtype, mpi_comm);
}

inline void
_REAL_MPI_::Comm::Alltoall(const void *sendbuf, int sendcount,
	 const _REAL_MPI_::Datatype & sendtype, void *recvbuf,
	 int recvcount, const _REAL_MPI_::Datatype & recvtype) const
{
  (void)MPI_Alltoall((void *) sendbuf, sendcount,
		     sendtype, recvbuf, recvcount,
		     recvtype, mpi_comm);
}

inline void
_REAL_MPI_::Comm::Alltoallv(const void *sendbuf, const int sendcounts[],
	  const int sdispls[], const _REAL_MPI_::Datatype & sendtype,
	  void *recvbuf, const int recvcounts[],
	  const int rdispls[], const _REAL_MPI_::Datatype & recvtype) const
{
    (void)MPI_Alltoallv((void *) sendbuf, (int *) sendcounts,
			(int *) sdispls, sendtype, recvbuf,
			(int *) recvcounts, (int *) rdispls,
			recvtype,mpi_comm);
}

inline void
_REAL_MPI_::Comm::Alltoallw(const void *sendbuf, const int sendcounts[],
	const int sdispls[], const _REAL_MPI_::Datatype sendtypes[],
	void *recvbuf, const int recvcounts[],
	const int rdispls[], const _REAL_MPI_::Datatype recvtypes[]) const
{
    int i;
    int size;
    MPI_Comm_size(mpi_comm, &size);
    MPI_Datatype* sendtypes_array = new MPI_Datatype[size];
    MPI_Datatype* recvtypes_array = new MPI_Datatype[size];
    for (i = 0; i < size; i++) {
        sendtypes_array[i] = sendtypes[i];
        recvtypes_array[i] = recvtypes[i];
    }

    (void)MPI_Alltoallw((void *) sendbuf, (int *) sendcounts,
		      (int *) sdispls, sendtypes_array, recvbuf,
		      (int *) recvcounts, (int *) rdispls,
		      recvtypes_array, mpi_comm);

}

inline void
_REAL_MPI_::Comm::Reduce(const void *sendbuf, void *recvbuf, int count,
       const _REAL_MPI_::Datatype & datatype, const _REAL_MPI_::Op& op,
       int root) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_Reduce((void*)sendbuf, recvbuf, count, datatype, op, root, mpi_comm);
  current_op = (Op*)0;
}

inline void
_REAL_MPI_::Comm::Allreduce(const void *sendbuf, void *recvbuf, int count,
	  const _REAL_MPI_::Datatype & datatype, const _REAL_MPI_::Op& op) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_Allreduce ((void*)sendbuf, recvbuf, count, datatype,  op, mpi_comm);
  current_op = (Op*)0;
}

inline void
_REAL_MPI_::Comm::Reduce_scatter(const void *sendbuf, void *recvbuf,
	       int recvcounts[],
	       const _REAL_MPI_::Datatype & datatype,
	       const _REAL_MPI_::Op& op) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_Reduce_scatter((void*)sendbuf, recvbuf, recvcounts,
			   datatype, op, mpi_comm);
  current_op = (Op*)0;
}
inline void
_REAL_MPI_::Comm::Reduce_scatter_block(const void *sendbuf, void *recvbuf,
	       int recvcount,
	       const _REAL_MPI_::Datatype & datatype,
	       const _REAL_MPI_::Op& op) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_Reduce_scatter_block((void*)sendbuf, recvbuf, recvcount,
			   datatype, op, mpi_comm);
  current_op = (Op*)0;
}

inline void
_REAL_MPI_::Comm::Scan(const void *sendbuf, void *recvbuf, int count,
     const _REAL_MPI_::Datatype & datatype, const _REAL_MPI_::Op& op) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_Scan((void *)sendbuf, recvbuf, count, datatype, op, mpi_comm);
  current_op = (Op*)0;
}

inline void
_REAL_MPI_::Comm::Exscan(const void *sendbuf, void *recvbuf, int count,
			      const _REAL_MPI_::Datatype & datatype,
			      const _REAL_MPI_::Op& op) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_Exscan((void *)sendbuf, recvbuf, count, datatype, op, mpi_comm);
  current_op = (Op*)0;
}

//
// Process Creation and Managemnt
//

inline void
_REAL_MPI_::Comm::Disconnect()
{
  (void) MPI_Comm_disconnect(&mpi_comm);
}

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Comm::Get_parent()
{
  MPI_Comm parent;
  MPI_Comm_get_parent(&parent);
  return parent;
}

inline _REAL_MPI_::Intercomm
_REAL_MPI_::Comm::Join(const int fd)
{
  MPI_Comm newcomm;
  (void) MPI_Comm_join((int) fd, &newcomm);
  return newcomm;
}

//
// External Interfaces
//

inline void
_REAL_MPI_::Comm::Get_name(char* comm_name, int& resultlen) const
{
  (void) MPI_Comm_get_name(mpi_comm, comm_name, &resultlen);
}

inline void
_REAL_MPI_::Comm::Set_name(const char* comm_name)
{
  (void) MPI_Comm_set_name(mpi_comm, (char *)comm_name);
}

//
//Process Topologies
//

inline int
_REAL_MPI_::Comm::Get_topology() const
{
  int status;
  (void)MPI_Topo_test(mpi_comm, &status);
  return status;
}

//
// Environmental Inquiry
//

inline void
_REAL_MPI_::Comm::Abort(int errorcode)
{
  (void)MPI_Abort(mpi_comm, errorcode);
}

//
//  These C++ bindings are for MPI-2.
//  The MPI-1.2 functions called below are all
//  going to be deprecated and replaced in MPI-2.
//

inline void
_REAL_MPI_::Comm::Set_errhandler(const _REAL_MPI_::Errhandler& errhandler)
{
  my_errhandler = (_REAL_MPI_::Errhandler *)&errhandler;
  _REAL_MPI_::Comm::mpi_err_map[mpi_comm] = this;
  (void)MPI_Errhandler_set(mpi_comm, errhandler);
}

inline _REAL_MPI_::Errhandler
_REAL_MPI_::Comm::Get_errhandler() const
{
  return *my_errhandler;
}

inline _REAL_MPI_::Errhandler
_REAL_MPI_::Comm::Create_errhandler(_REAL_MPI_::Comm::Errhandler_fn* function)
{
  MPI_Errhandler errhandler;
  // $%%@#%# AIX/POE 2.3.0.0 makes us put in this cast here
  (void)MPI_Errhandler_create((MPI_Handler_function*) errhandler_intercept,
			      &errhandler);
  _REAL_MPI_::Errhandler temp(errhandler);
  temp.handler_fn = (void(*)(_REAL_MPI_::Comm&, int*, ...))function;
  return temp;
}

inline void
_REAL_MPI_::Comm::Call_errhandler(int errorcode) const
{
  (void) MPI_Comm_call_errhandler(mpi_comm, errorcode);
}

inline int
_REAL_MPI_::Comm::Create_keyval(
         _REAL_MPI_::Comm::Copy_attr_function* comm_copy_attr_fn,
         _REAL_MPI_::Comm::Delete_attr_function* comm_delete_attr_fn,
         void* extra_state)
{
  int keyval;
  (void)MPI_Keyval_create(copy_attr_intercept, delete_attr_intercept,
			  &keyval, extra_state);
  key_pair_t* copy_and_delete =
    new key_pair_t(comm_copy_attr_fn, comm_delete_attr_fn);
  _REAL_MPI_::Comm::key_fn_map[keyval] = copy_and_delete;
  _REAL_MPI_::Comm::key_ref_map[keyval] = 1;
  return keyval;
}

inline void
_REAL_MPI_::Comm::Free_keyval(int& comm_keyval)
{
  int save = comm_keyval;
  (void)MPI_Keyval_free(&comm_keyval);

  _REAL_MPI_::Comm::key_ref_map[save]--;
  if (_REAL_MPI_::Comm::key_ref_map[save] == 0) {
	  if (_REAL_MPI_::Comm::key_fn_map[save] != 0)
 		   delete _REAL_MPI_::Comm::key_fn_map[save];
	  _REAL_MPI_::Comm::key_fn_map.erase(save);
	  _REAL_MPI_::Comm::key_ref_map.erase(save);
  }
}

inline void
_REAL_MPI_::Comm::Set_attr(int comm_keyval, const void* attribute_val) const
{
  if (_REAL_MPI_::Comm::mpi_comm_map[mpi_comm] == 0) {
     CommType type;
     int status;

     (void)MPI_Comm_test_inter(mpi_comm, &status);
     if (status) {
       type = eIntercomm;
     }
     else {
       (void)MPI_Topo_test(mpi_comm, &status);
       if (status == MPI_CART)
         type = eCartcomm;
       else if (status == MPI_GRAPH)
         type = eGraphcomm;
       else
         type = eIntracomm;
     }
     comm_pair_t* comm_type = new comm_pair_t((Comm*) this, type);
     _REAL_MPI_::Comm::mpi_comm_map[mpi_comm] = comm_type;
  }
  _REAL_MPI_::Comm::key_ref_map[comm_keyval]++;
  (void)MPI_Attr_put(mpi_comm, comm_keyval, (void*) attribute_val);
}

inline bool
_REAL_MPI_::Comm::Get_attr(int comm_keyval, void* attribute_val) const
{
  int flag;
  (void)MPI_Attr_get(mpi_comm, comm_keyval, attribute_val, &flag);
  return (bool)flag;
}

inline void
_REAL_MPI_::Comm::Delete_attr(int comm_keyval)
{
  (void)MPI_Attr_delete(mpi_comm, comm_keyval);
}

inline int
_REAL_MPI_::Comm::NULL_COPY_FN(const _REAL_MPI_::Comm& /*oldcomm*/,
                               int   /*comm_keyval*/,
                               void* /*extra_state*/,
                               void* /*attribute_val_in*/,
                               void* /*attribute_val_out*/,
                               bool& flag)
{

    flag = false;
    return MPI_SUCCESS;

}

inline int
_REAL_MPI_::Comm::DUP_FN(const _REAL_MPI_::Comm& oldcomm, int comm_keyval,
			 void* extra_state, void* attribute_val_in,
			 void* attribute_val_out, bool& flag)
{
  int f = (int)flag;
  int ret;
  ret = MPI_DUP_FN(oldcomm, comm_keyval, extra_state, attribute_val_in,
		   attribute_val_out, &f);
  flag = (bool) f;
  return ret;
}

inline int
_REAL_MPI_::Comm::NULL_DELETE_FN(_REAL_MPI_::Comm& comm, int comm_keyval, void* attribute_val,
				 void* extra_state)
{
    return MPI_SUCCESS;

}

#ifdef HPMPI_LONG_EXTENTIONS
#include "mpiCC/commL_inln.h"
#endif
