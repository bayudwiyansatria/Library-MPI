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
 *	"@(#)IBM Platform MPI 09.01.04.03 [BASELINE_MPI_STREAM_REL_9.1.4.0_RTM_2015_06_15]  [] [] [] [] [] [] (02/06/2018) Linux x86-64"
 */
class Comm_Null {

public:

  // All REMOVE-FD lines are to be removed for release.
  // These are left here for possible future development.

  // construction
  inline Comm_Null() : mpi_comm(MPI_COMM_NULL) { }
  // copy
  inline Comm_Null(const Comm_Null& data) : mpi_comm(data.mpi_comm) { }
  // inter-language operability
  inline Comm_Null(const MPI_Comm& data) : mpi_comm(data) { }

  // destruction
  virtual inline ~Comm_Null() { }

  // comparison
  inline bool operator==(const Comm_Null& data) const {
    return (bool) (mpi_comm == data.mpi_comm); }

  inline bool operator!=(const Comm_Null& data) const {
    return (bool) !(*this == data);}

  // inter-language operability (conversion operators)
  inline operator MPI_Comm() const { return mpi_comm; }
  inline operator MPI_Comm*() { return &mpi_comm; }

  inline Comm_Null& operator=(const Comm_Null& data) {
    mpi_comm = data.mpi_comm;
    return *this;
  }

  inline Comm_Null& operator=(const MPI_Comm& data)
           { mpi_comm = data;  return *this; }

protected:

  MPI_Comm mpi_comm;

};

class Comm : public Comm_Null {
public:

  typedef void Errhandler_fn(Comm&, int*, ...);
  typedef int Copy_attr_function(const Comm& oldcomm, int comm_keyval,
				 void* extra_state, void* attribute_val_in,
				 void* attribute_val_out,
				 bool& flag);
  typedef int Delete_attr_function(Comm& comm, int comm_keyval,
				   void* attribute_val,
				   void* extra_state);

  // construction
  Comm() { }

  // copy
  Comm(const Comm_Null& data) : Comm_Null(data) { }

  Comm(const Comm& data) : Comm_Null(data.mpi_comm) { }
  // inter-language operability
  Comm(const MPI_Comm& data) : Comm_Null(data) { }

  //
  // Point-to-Point
  //

  virtual void Send(const void *buf, int count,
		    const Datatype & datatype, int dest, int tag) const;

  virtual void Recv(void *buf, int count, const Datatype & datatype,
		    int source, int tag, Status & status) const;

  virtual void Recv(void *buf, int count, const Datatype & datatype,
		    int source, int tag) const;

  virtual void Bsend(const void *buf, int count,
		     const Datatype & datatype, int dest, int tag) const;

  virtual void Ssend(const void *buf, int count,
		     const Datatype & datatype, int dest, int tag) const ;

  virtual void Rsend(const void *buf, int count,
		     const Datatype & datatype, int dest, int tag) const;

  virtual Request Isend(const void *buf, int count,
			const Datatype & datatype, int dest, int tag) const;

  virtual Request Ibsend(const void *buf, int count, const
			 Datatype & datatype, int dest, int tag) const;

  virtual Request Issend(const void *buf, int count,
			 const Datatype & datatype, int dest, int tag) const;

  virtual Request Irsend(const void *buf, int count,
			 const Datatype & datatype, int dest, int tag) const;

  virtual Request Irecv(void *buf, int count,
			const Datatype & datatype, int source, int tag) const;

  virtual bool Iprobe(int source, int tag, Status & status) const;

  virtual bool Iprobe(int source, int tag) const;

  virtual void Probe(int source, int tag, Status & status) const;

  virtual void Probe(int source, int tag) const;

  virtual Prequest Send_init(const void *buf, int count,
			     const Datatype & datatype, int dest,
			     int tag) const;

  virtual Prequest Bsend_init(const void *buf, int count,
			      const Datatype & datatype, int dest,
			      int tag) const;

  virtual Prequest Ssend_init(const void *buf, int count,
			      const Datatype & datatype, int dest,
			      int tag) const;

  virtual Prequest Rsend_init(const void *buf, int count,
			      const Datatype & datatype, int dest,
			      int tag) const;

  virtual Prequest Recv_init(void *buf, int count,
			     const Datatype & datatype, int source,
			     int tag) const;

  virtual void Sendrecv(const void *sendbuf, int sendcount,
			const Datatype & sendtype, int dest, int sendtag,
			void *recvbuf, int recvcount,
			const Datatype & recvtype, int source,
			int recvtag, Status & status) const;

  virtual void Sendrecv(const void *sendbuf, int sendcount,
			const Datatype & sendtype, int dest, int sendtag,
			void *recvbuf, int recvcount,
			const Datatype & recvtype, int source,
			int recvtag) const;

  virtual void Sendrecv_replace(void *buf, int count,
				const Datatype & datatype, int dest,
				int sendtag, int source,
				int recvtag, Status & status) const;

  virtual void Sendrecv_replace(void *buf, int count,
				const Datatype & datatype, int dest,
				int sendtag, int source,
				int recvtag) const;

  //
  // Groups, Contexts, and Communicators
  //

  virtual Group Get_group() const;

  virtual int Get_size() const;

  virtual int Get_rank() const;

  static int Compare(const Comm & comm1, const Comm & comm2);

  virtual Comm& Clone() const = 0;

  virtual void Free(void);

  virtual bool Is_inter() const;

  //
  // Collective Communication
  //

  virtual void
  Barrier() const;

  virtual void
  Bcast(void *buffer, int count,
	const Datatype& datatype, int root) const;

  virtual void
  Gather(const void *sendbuf, int sendcount,
	 const Datatype & sendtype,
	 void *recvbuf, int recvcount,
	 const Datatype & recvtype, int root) const;

  virtual void
  Gatherv(const void *sendbuf, int sendcount,
	  const Datatype & sendtype, void *recvbuf,
	  const int recvcounts[], const int displs[],
	  const Datatype & recvtype, int root) const;

  virtual void
  Scatter(const void *sendbuf, int sendcount,
	  const Datatype & sendtype,
	  void *recvbuf, int recvcount,
	  const Datatype & recvtype, int root) const;

  virtual void
  Scatterv(const void *sendbuf, const int sendcounts[],
	   const int displs[], const Datatype & sendtype,
	   void *recvbuf, int recvcount,
	   const Datatype & recvtype, int root) const;

  virtual void
  Allgather(const void *sendbuf, int sendcount,
	    const Datatype & sendtype, void *recvbuf,
	    int recvcount, const Datatype & recvtype) const;

  virtual void
  Allgatherv(const void *sendbuf, int sendcount,
	     const Datatype & sendtype, void *recvbuf,
	     const int recvcounts[], const int displs[],
	     const Datatype & recvtype) const;

  virtual void
  Alltoall(const void *sendbuf, int sendcount,
	   const Datatype & sendtype, void *recvbuf,
	   int recvcount, const Datatype & recvtype) const;

  virtual void
  Alltoallv(const void *sendbuf, const int sendcounts[],
	    const int sdispls[], const Datatype & sendtype,
	    void *recvbuf, const int recvcounts[],
	    const int rdispls[], const Datatype & recvtype) const;

  virtual void
  Alltoallw(const void *sendbuf, const int sendcounts[],
            const int sdispls[], const Datatype sendtypes[],
            void *recvbuf, const int recvcounts[],
            const int rdispls[], const Datatype recvtypes[]) const;

  virtual void
  Reduce(const void *sendbuf, void *recvbuf, int count,
	 const Datatype & datatype, const Op & op,
	 int root) const;

  virtual void
  Allreduce(const void *sendbuf, void *recvbuf, int count,
	    const Datatype & datatype, const Op & op) const;

  virtual void
  Reduce_scatter(const void *sendbuf, void *recvbuf,
		 int recvcounts[],
		 const Datatype & datatype,
		 const Op & op) const;
  virtual void
  Reduce_scatter_block(const void *sendbuf, void *recvbuf,
		 int recvcount,
		 const Datatype & datatype,
		 const Op & op) const;

  virtual void
  Scan(const void *sendbuf, void *recvbuf, int count,
       const Datatype & datatype, const Op & op) const;

  virtual void
  Exscan(const void *sendbuf, void *recvbuf, int count,
	 const Datatype & datatype, const Op & op) const;

#ifdef HPMPI_LONG_EXTENTIONS
#include "mpiCC/commL.h"
#endif

  //
  // Process Creation
  //

  virtual void Disconnect();

  static Intercomm Get_parent();

  static Intercomm Join(const int fd);

  //
  //External Interfaces
  //

  virtual void Get_name(char * comm_name, int& resultlen) const;

  virtual void Set_name(const char* comm_name);

  //
  //Process Topologies
  //

  virtual int Get_topology() const;

  //
  // Environmental Inquiry
  //

  virtual void Abort(int errorcode);

  //
  // Errhandler
  //

  virtual void Set_errhandler(const Errhandler& errhandler);

  virtual Errhandler Get_errhandler() const;

  static Errhandler Create_errhandler(Comm::Errhandler_fn* function);

  virtual void Call_errhandler(int errorcode) const;

  //
  // Keys and Attributes
  //

  static int Create_keyval(Copy_attr_function* comm_copy_attr_fn,
			   Delete_attr_function* comm_delete_attr_fn,
			   void* extra_state);

  static void Free_keyval(int& comm_keyval);

  virtual void Set_attr(int comm_keyval, const void* attribute_val) const;

  virtual bool Get_attr(int comm_keyval, void* attribute_val) const;

  virtual void Delete_attr(int comm_keyval);

  static int NULL_COPY_FN(const Comm& oldcomm,
                          int comm_keyval,
                          void* extra_state,
                          void* attribute_val_in,
                          void* attribute_val_out,
                          bool& flag);

  static int DUP_FN(const Comm& oldcomm,
                    int comm_keyval,
                    void* extra_state,
                    void* attribute_val_in,
                    void* attribute_val_out,
                    bool& flag);

  static int NULL_DELETE_FN(Comm& comm,
                            int comm_keyval,
                            void* attribute_val,
                            void* extra_state);

public:

  static Op* current_op;

private:

public:
  Errhandler* my_errhandler;

  typedef mpi2cppMap<Comm*, CommType>::Pair comm_pair_t;
  typedef mpi2cppMap<MPI_Comm, comm_pair_t*> mpi_comm_map_t;
  static mpi_comm_map_t mpi_comm_map;

  typedef mpi2cppMap<MPI_Comm, Comm*> mpi_err_map_t;
  static mpi_err_map_t mpi_err_map;

  typedef mpi2cppMap<Comm::Copy_attr_function*,
                     Comm::Delete_attr_function*>::
                           Pair key_pair_t;
  typedef mpi2cppMap<int, key_pair_t*> key_fn_map_t;
  typedef mpi2cppMap<int, int> key_ref_map_t;
  static key_fn_map_t key_fn_map;
  static key_ref_map_t key_ref_map;

  void init() {
    my_errhandler = (Errhandler*)0;
  }

};
