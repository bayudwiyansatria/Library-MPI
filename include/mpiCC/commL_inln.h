/*
 *	Copyright Platform Computing Inc., an IBM company, 1983-2010, 2012
 *
 *	$Revision: 7316 $
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

#ifdef HPMPI_LONG_EXTENTIONS

//
// Point-to-Point
//

inline void
_REAL_MPI_::Comm::SendL(const void *buf, _REAL_MPI_::Aint count,
		const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  (void)MPI_SendL((void *)buf, count, datatype, dest, tag, mpi_comm);
}

inline void
_REAL_MPI_::Comm::RecvL(void *buf, _REAL_MPI_::Aint count,
		const _REAL_MPI_::Datatype & datatype, int source, int tag,
		_REAL_MPI_::Status & status) const
{
  (void)MPI_RecvL(buf, count, datatype, source, tag, mpi_comm,
                 &status.mpi_status);
}

inline void
_REAL_MPI_::Comm::RecvL(void *buf, _REAL_MPI_::Aint count,
		const _REAL_MPI_::Datatype & datatype,
		int source, int tag) const
{
  (void)MPI_RecvL(buf, count, datatype, source,
		 tag, mpi_comm, MPI_STATUS_IGNORE);
}

inline void
_REAL_MPI_::Comm::BsendL(const void *buf, _REAL_MPI_::Aint count,
		 const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  (void)MPI_BsendL((void *)buf, count, datatype,
		  dest, tag, mpi_comm);
}

inline void
_REAL_MPI_::Comm::SsendL(const void *buf, _REAL_MPI_::Aint count,
		 const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  (void)MPI_SsendL((void *)buf, count,  datatype, dest,
		  tag, mpi_comm);
}

inline void
_REAL_MPI_::Comm::RsendL(const void *buf, _REAL_MPI_::Aint count,
		 const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  (void)MPI_RsendL((void *)buf, count, datatype,
		  dest, tag, mpi_comm);
}

inline _REAL_MPI_::Request
_REAL_MPI_::Comm::IsendL(const void *buf, _REAL_MPI_::Aint count,
		 const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_IsendL((void *)buf, count, datatype,
		  dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Request
_REAL_MPI_::Comm::IbsendL(const void *buf, _REAL_MPI_::Aint count,
		  const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_IbsendL((void *)buf, count, datatype,
		   dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Request
_REAL_MPI_::Comm::IssendL(const void *buf, _REAL_MPI_::Aint count,
		  const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_IssendL((void *)buf, count, datatype,
		   dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Request
_REAL_MPI_::Comm::IrsendL(const void *buf, _REAL_MPI_::Aint count,
		  const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_IrsendL((void *) buf, count, datatype,
		   dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Request
_REAL_MPI_::Comm::IrecvL(void *buf, _REAL_MPI_::Aint count,
		 const _REAL_MPI_::Datatype & datatype, int source, int tag) const
{
  MPI_Request request;
  (void)MPI_IrecvL(buf, count, datatype, source,
		  tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Prequest
_REAL_MPI_::Comm::Send_initL(const void *buf, _REAL_MPI_::Aint count,
		     const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Send_initL((void *)buf, count, datatype,
		      dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Prequest
_REAL_MPI_::Comm::Bsend_initL(const void *buf, _REAL_MPI_::Aint count,
		      const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Bsend_initL((void *)buf, count, datatype,
		       dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Prequest
_REAL_MPI_::Comm::Ssend_initL(const void *buf, _REAL_MPI_::Aint count,
		      const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Ssend_initL((void *)buf, count, datatype,
		       dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Prequest
_REAL_MPI_::Comm::Rsend_initL(const void *buf, _REAL_MPI_::Aint count,
		      const _REAL_MPI_::Datatype & datatype, int dest, int tag) const
{
  MPI_Request request;
  (void)MPI_Rsend_initL((void *)buf, count,  datatype,
		       dest, tag, mpi_comm, &request);
  return request;
}

inline _REAL_MPI_::Prequest
_REAL_MPI_::Comm::Recv_initL(void *buf, _REAL_MPI_::Aint count,
		     const _REAL_MPI_::Datatype & datatype, int source, int tag) const
{
  MPI_Request request;
  (void)MPI_Recv_initL(buf, count, datatype, source,
		      tag, mpi_comm, &request);
  return request;
}

inline void
_REAL_MPI_::Comm::SendrecvL(const void *sendbuf, _REAL_MPI_::Aint sendcount,
		    const _REAL_MPI_::Datatype & sendtype, int dest, int sendtag,
		    void *recvbuf, _REAL_MPI_::Aint recvcount,
		    const _REAL_MPI_::Datatype & recvtype, int source,
		    int recvtag, _REAL_MPI_::Status & status) const
{
  (void)MPI_SendrecvL((void *)sendbuf, sendcount,
		     sendtype,
		     dest, sendtag, recvbuf, recvcount,
		     recvtype,
		     source, recvtag, mpi_comm, &status.mpi_status);
}

inline void
_REAL_MPI_::Comm::SendrecvL(const void *sendbuf, _REAL_MPI_::Aint sendcount,
		    const _REAL_MPI_::Datatype & sendtype, int dest, int sendtag,
		    void *recvbuf, _REAL_MPI_::Aint recvcount,
		    const _REAL_MPI_::Datatype & recvtype, int source,
		    int recvtag) const
{
  (void)MPI_SendrecvL((void *)sendbuf, sendcount,
		     sendtype,
		     dest, sendtag, recvbuf, recvcount,
		     recvtype,
		     source, recvtag, mpi_comm, MPI_STATUS_IGNORE);
}

inline void
_REAL_MPI_::Comm::Sendrecv_replaceL(void *buf, _REAL_MPI_::Aint count,
			    const _REAL_MPI_::Datatype & datatype, int dest,
			    int sendtag, int source,
			    int recvtag, _REAL_MPI_::Status & status) const
{
  (void)MPI_Sendrecv_replaceL(buf, count, datatype, dest,
			     sendtag, source, recvtag, mpi_comm,
			     &status.mpi_status);
}

inline void
_REAL_MPI_::Comm::Sendrecv_replaceL(void *buf, _REAL_MPI_::Aint count,
			    const _REAL_MPI_::Datatype & datatype, int dest,
			    int sendtag, int source,
			    int recvtag) const
{
  (void)MPI_Sendrecv_replaceL(buf, count, datatype, dest,
			     sendtag, source, recvtag, mpi_comm,
			     MPI_STATUS_IGNORE);
}

inline void
_REAL_MPI_::Comm::BcastL(void *buffer, _REAL_MPI_::Aint count,
      const _REAL_MPI_::Datatype& datatype, int root) const
{
  (void)MPI_BcastL(buffer, count, datatype, root, mpi_comm);
}

inline void
_REAL_MPI_::Comm::GatherL(const void *sendbuf, _REAL_MPI_::Aint sendcount,
			      const _REAL_MPI_::Datatype & sendtype,
			      void *recvbuf, _REAL_MPI_::Aint recvcount,
			      const _REAL_MPI_::Datatype & recvtype, int root) const
{
  (void)MPI_GatherL((void *)sendbuf, sendcount, sendtype,
		   recvbuf, recvcount, recvtype, root, mpi_comm);
}

inline void
_REAL_MPI_::Comm::GathervL(const void *sendbuf, _REAL_MPI_::Aint sendcount,
	const _REAL_MPI_::Datatype & sendtype, void *recvbuf,
	const _REAL_MPI_::Aint recvcounts[],
	const _REAL_MPI_::Aint displs[],
	const _REAL_MPI_::Datatype & recvtype, int root) const
{
  (void)MPI_GathervL((void *)sendbuf, sendcount,  sendtype, recvbuf,
			(_REAL_MPI_::Aint *)recvcounts,
			(_REAL_MPI_::Aint *)displs,
			recvtype, root, mpi_comm);
}

inline void
_REAL_MPI_::Comm::ScatterL(const void *sendbuf, _REAL_MPI_::Aint sendcount,
	const _REAL_MPI_::Datatype & sendtype,
	void *recvbuf, _REAL_MPI_::Aint recvcount,
	const _REAL_MPI_::Datatype & recvtype, int root) const
{
  (void)MPI_ScatterL((void *)sendbuf, sendcount, sendtype,
		    recvbuf, recvcount, recvtype, root, mpi_comm);
}

inline void
_REAL_MPI_::Comm::ScattervL(const void *sendbuf,
		const _REAL_MPI_::Aint sendcounts[],
	 	const _REAL_MPI_::Aint displs[],
		const _REAL_MPI_::Datatype & sendtype,
	 	void *recvbuf, _REAL_MPI_::Aint recvcount,
	 	const _REAL_MPI_::Datatype & recvtype, int root) const
{
  (void)MPI_ScattervL((void *)sendbuf, (_REAL_MPI_::Aint *) sendcounts,
		     (_REAL_MPI_::Aint *) displs, sendtype,
		     recvbuf, recvcount, recvtype,
		     root, mpi_comm);
}

inline void
_REAL_MPI_::Comm::AllgatherL(const void *sendbuf, _REAL_MPI_::Aint sendcount,
	  const _REAL_MPI_::Datatype & sendtype, void *recvbuf,
	  _REAL_MPI_::Aint recvcount,
	  const _REAL_MPI_::Datatype & recvtype) const
{
  (void)MPI_AllgatherL((void *) sendbuf, sendcount,
		      sendtype, recvbuf, recvcount,
		      recvtype, mpi_comm);
}

inline void
_REAL_MPI_::Comm::AllgathervL(const void *sendbuf,
		_REAL_MPI_::Aint sendcount,
	   	const _REAL_MPI_::Datatype & sendtype, void *recvbuf,
	   	const _REAL_MPI_::Aint recvcounts[],
		const _REAL_MPI_::Aint displs[],
	   	const _REAL_MPI_::Datatype & recvtype) const
{
  (void)MPI_AllgathervL((void *)sendbuf, sendcount,
			sendtype, recvbuf,
			(_REAL_MPI_::Aint *) recvcounts,
			(_REAL_MPI_::Aint *) displs,
			recvtype, mpi_comm);
}

inline void
_REAL_MPI_::Comm::AlltoallL(const void *sendbuf, _REAL_MPI_::Aint sendcount,
	const _REAL_MPI_::Datatype & sendtype, void *recvbuf,
	_REAL_MPI_::Aint recvcount,
	const _REAL_MPI_::Datatype & recvtype) const
{
  (void)MPI_AlltoallL((void *) sendbuf, sendcount,
		     sendtype, recvbuf, recvcount,
		     recvtype, mpi_comm);
}

inline void
_REAL_MPI_::Comm::AlltoallvL(const void *sendbuf,
		const _REAL_MPI_::Aint sendcounts[],
	  	const _REAL_MPI_::Aint sdispls[],
		const _REAL_MPI_::Datatype & sendtype,
	  	void *recvbuf, const _REAL_MPI_::Aint recvcounts[],
	  	const _REAL_MPI_::Aint rdispls[],
		const _REAL_MPI_::Datatype & recvtype) const
{
    (void)MPI_AlltoallvL((void *) sendbuf, (_REAL_MPI_::Aint *) sendcounts,
			(_REAL_MPI_::Aint *) sdispls, sendtype, recvbuf,
			(_REAL_MPI_::Aint *) recvcounts,
			(_REAL_MPI_::Aint *) rdispls,
			recvtype,mpi_comm);
}

inline void
_REAL_MPI_::Comm::AlltoallwL(const void *sendbuf,
	const _REAL_MPI_::Aint sendcounts[],
	const _REAL_MPI_::Aint sdispls[],
	const _REAL_MPI_::Datatype sendtypes[],
	void *recvbuf, const _REAL_MPI_::Aint recvcounts[],
	const _REAL_MPI_::Aint rdispls[],
	const _REAL_MPI_::Datatype recvtypes[]) const
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

    (void)MPI_AlltoallwL((void *) sendbuf, (_REAL_MPI_::Aint *) sendcounts,
		(_REAL_MPI_::Aint *) sdispls, sendtypes_array, recvbuf,
		(_REAL_MPI_::Aint *) recvcounts,
		(_REAL_MPI_::Aint *) rdispls,
		recvtypes_array, mpi_comm);
}

inline void
_REAL_MPI_::Comm::ReduceL(const void *sendbuf, void *recvbuf,
	_REAL_MPI_::Aint count,
       const _REAL_MPI_::Datatype & datatype, const _REAL_MPI_::Op& op,
       int root) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_ReduceL((void*)sendbuf, recvbuf, count, datatype, op, root, mpi_comm);
  current_op = (Op*)0;
}

inline void
_REAL_MPI_::Comm::AllreduceL(const void *sendbuf, void *recvbuf,
	_REAL_MPI_::Aint count, const _REAL_MPI_::Datatype & datatype,
	const _REAL_MPI_::Op& op) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_AllreduceL((void*)sendbuf, recvbuf, count, datatype,  op, mpi_comm);
  current_op = (Op*)0;
}

inline void
_REAL_MPI_::Comm::Reduce_scatterL(const void *sendbuf, void *recvbuf,
	       _REAL_MPI_::Aint recvcounts[],
	       const _REAL_MPI_::Datatype & datatype,
	       const _REAL_MPI_::Op& op) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_Reduce_scatterL((void*)sendbuf, recvbuf, recvcounts,
			   datatype, op, mpi_comm);
  current_op = (Op*)0;
}

inline void
_REAL_MPI_::Comm::Reduce_scatter_blockL(const void *sendbuf, void *recvbuf,
	       _REAL_MPI_::Aint recvcount,
	       const _REAL_MPI_::Datatype & datatype,
	       const _REAL_MPI_::Op& op) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_Reduce_scatter_blockL((void*)sendbuf, recvbuf, recvcount,
			   datatype, op, mpi_comm);
  current_op = (Op*)0;
}
inline void
_REAL_MPI_::Comm::ScanL(const void *sendbuf, void *recvbuf,
		_REAL_MPI_::Aint count,
		const _REAL_MPI_::Datatype & datatype,
		const _REAL_MPI_::Op& op) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_ScanL((void *)sendbuf, recvbuf, count, datatype, op, mpi_comm);
  current_op = (Op*)0;
}

inline void
_REAL_MPI_::Comm::ExscanL(const void *sendbuf, void *recvbuf,
		_REAL_MPI_::Aint count,
		const _REAL_MPI_::Datatype & datatype,
		const _REAL_MPI_::Op& op) const
{
  current_op = (_REAL_MPI_::Op*)&op;
  (void)MPI_ExscanL((void *)sendbuf, recvbuf, count, datatype, op, mpi_comm);
  current_op = (Op*)0;
}

#endif
