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

  virtual void SendL(const void *buf, MPI::Aint count,
		    const Datatype & datatype, int dest, int tag) const;

  virtual void RecvL(void *buf, MPI::Aint count, const Datatype & datatype,
		    int source, int tag, Status & status) const;

  virtual void RecvL(void *buf, MPI::Aint count, const Datatype & datatype,
		    int source, int tag) const;

  virtual void BsendL(const void *buf, MPI::Aint count,
		     const Datatype & datatype, int dest, int tag) const;

  virtual void SsendL(const void *buf, MPI::Aint count,
		     const Datatype & datatype, int dest, int tag) const ;

  virtual void RsendL(const void *buf, MPI::Aint count,
		     const Datatype & datatype, int dest, int tag) const;

  virtual Request IsendL(const void *buf, MPI::Aint count,
			const Datatype & datatype, int dest, int tag) const;

  virtual Request IbsendL(const void *buf, MPI::Aint count, const
			 Datatype & datatype, int dest, int tag) const;

  virtual Request IssendL(const void *buf, MPI::Aint count,
			 const Datatype & datatype, int dest, int tag) const;

  virtual Request IrsendL(const void *buf, MPI::Aint count,
			 const Datatype & datatype, int dest, int tag) const;

  virtual Request IrecvL(void *buf, MPI::Aint count,
			const Datatype & datatype, int source, int tag) const;

  virtual Prequest Send_initL(const void *buf, MPI::Aint count,
			     const Datatype & datatype, int dest,
			     int tag) const;

  virtual Prequest Bsend_initL(const void *buf, MPI::Aint count,
			      const Datatype & datatype, int dest,
			      int tag) const;

  virtual Prequest Ssend_initL(const void *buf, MPI::Aint count,
			      const Datatype & datatype, int dest,
			      int tag) const;

  virtual Prequest Rsend_initL(const void *buf, MPI::Aint count,
			      const Datatype & datatype, int dest,
			      int tag) const;

  virtual Prequest Recv_initL(void *buf, MPI::Aint count,
			     const Datatype & datatype, int source,
			     int tag) const;

  virtual void SendrecvL(const void *sendbuf, MPI::Aint sendcount,
			const Datatype & sendtype, int dest, int sendtag,
			void *recvbuf, MPI::Aint recvcount,
			const Datatype & recvtype, int source,
			int recvtag, Status & status) const;

  virtual void SendrecvL(const void *sendbuf, MPI::Aint sendcount,
			const Datatype & sendtype, int dest, int sendtag,
			void *recvbuf, MPI::Aint recvcount,
			const Datatype & recvtype, int source,
			int recvtag) const;

  virtual void Sendrecv_replaceL(void *buf, MPI::Aint count,
				const Datatype & datatype, int dest,
				int sendtag, int source,
				int recvtag, Status & status) const;
  virtual void Sendrecv_replaceL(void *buf, MPI::Aint count,
				const Datatype & datatype, int dest,
				int sendtag, int source,
				int recvtag) const;

  // Collective Communication
  //

  virtual void
  BcastL(void *buffer, MPI::Aint count,
	const Datatype& datatype, int root) const;

  virtual void
  GatherL(const void *sendbuf, MPI::Aint sendcount,
	 const Datatype & sendtype,
	 void *recvbuf, MPI::Aint recvcount,
	 const Datatype & recvtype, int root) const;

  virtual void
  GathervL(const void *sendbuf, MPI::Aint sendcount,
	  const Datatype & sendtype, void *recvbuf,
	  const MPI::Aint recvcounts[], const MPI::Aint displs[],
	  const Datatype & recvtype, int root) const;

  virtual void
  ScatterL(const void *sendbuf, MPI::Aint sendcount,
	  const Datatype & sendtype,
	  void *recvbuf, MPI::Aint recvcount,
	  const Datatype & recvtype, int root) const;

  virtual void
  ScattervL(const void *sendbuf, const MPI::Aint sendcounts[],
	   const MPI::Aint displs[], const Datatype & sendtype,
	   void *recvbuf, MPI::Aint recvcount,
	   const Datatype & recvtype, int root) const;

  virtual void
  AllgatherL(const void *sendbuf, MPI::Aint sendcount,
	    const Datatype & sendtype, void *recvbuf,
	    MPI::Aint recvcount, const Datatype & recvtype) const;

  virtual void
  AllgathervL(const void *sendbuf, MPI::Aint sendcount,
	     const Datatype & sendtype, void *recvbuf,
	     const MPI::Aint recvcounts[], const MPI::Aint displs[],
	     const Datatype & recvtype) const;

  virtual void
  AlltoallL(const void *sendbuf, MPI::Aint sendcount,
	   const Datatype & sendtype, void *recvbuf,
	   MPI::Aint recvcount, const Datatype & recvtype) const;

  virtual void
  AlltoallvL(const void *sendbuf, const MPI::Aint sendcounts[],
	    const MPI::Aint sdispls[], const Datatype & sendtype,
	    void *recvbuf, const MPI::Aint recvcounts[],
	    const MPI::Aint rdispls[], const Datatype & recvtype) const;

  virtual void
  AlltoallwL(const void *sendbuf, const MPI::Aint sendcounts[],
            const MPI::Aint sdispls[], const Datatype sendtypes[],
            void *recvbuf, const MPI::Aint recvcounts[],
            const MPI::Aint rdispls[], const Datatype recvtypes[]) const;

  virtual void
  ReduceL(const void *sendbuf, void *recvbuf, MPI::Aint count,
	 const Datatype & datatype, const Op & op,
	 int root) const;

  virtual void
  AllreduceL(const void *sendbuf, void *recvbuf, MPI::Aint count,
	    const Datatype & datatype, const Op & op) const;

  virtual void
  Reduce_scatterL(const void *sendbuf, void *recvbuf,
		 MPI::Aint recvcounts[],
		 const Datatype & datatype,
		 const Op & op) const;

  virtual void
  Reduce_scatter_blockL(const void *sendbuf, void *recvbuf,
		 MPI::Aint recvcount,
		 const Datatype & datatype,
		 const Op & op) const;
  virtual void
  ScanL(const void *sendbuf, void *recvbuf, MPI::Aint count,
       const Datatype & datatype, const Op & op) const;

  virtual void
  ExscanL(const void *sendbuf, void *recvbuf, MPI::Aint count,
	 const Datatype & datatype, const Op & op) const;

#endif
