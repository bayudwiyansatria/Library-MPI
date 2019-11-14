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

class Datatype {

public:

  // construction / destruction
  inline Datatype() : mpi_datatype(MPI_DATATYPE_NULL) { }
  inline virtual ~Datatype() {}
  // inter-language operability
  inline Datatype(const MPI_Datatype &i) : mpi_datatype(i) { }

  // copy / assignment
  inline Datatype(const Datatype& dt) : mpi_datatype(dt.mpi_datatype) { }
  inline Datatype& operator=(const Datatype& dt) {
    mpi_datatype = dt.mpi_datatype; return *this; }

  // comparison
  inline bool operator== (const Datatype &a) const
    { return (bool) (mpi_datatype == a.mpi_datatype); }

  inline bool operator!= (const Datatype &a) const
    { return (bool) !(*this == a); }

  // inter-language operability
  inline Datatype& operator= (const MPI_Datatype &i)
    { mpi_datatype = i; return *this; }

  inline operator MPI_Datatype () const { return mpi_datatype; }
  // inline operator MPI_Datatype* () { return &mpi_datatype; }

  //
  // User Defined Functions
  //
  typedef int Copy_attr_function(const Datatype& oldtype,
						int type_keyval,
						void* extra_state,
						void* attribute_val_in,
						void* attribute_val_out,
						bool& flag);

  typedef int Delete_attr_function(Datatype& type, int type_keyval,
				   void* attribute_val, void* extra_state);

  // These functions are *not* part of MPI-2 but are provided
  // because we have them for the C routines.
  static int NULL_COPY_FN(const Datatype& oldtype,
                          int type_keyval,
                          void* extra_state,
                          void* attribute_val_in,
                          void* attribute_val_out,
                          bool& flag);

  static int DUP_FN(const Datatype& oldtype,
                    int type_keyval,
                    void* extra_state,
                    void* attribute_val_in,
                    void* attribute_val_out,
                    bool& flag);

  static int NULL_DELETE_FN(Datatype& type,
                            int comm_keyval,
                            void* attribute_val,
                            void* extra_state);

  //
  // Point-to-Point Communication
  //

  virtual Datatype Create_contiguous(int count) const;

  virtual Datatype Create_vector(int count, int blocklength,
				 int stride) const;

  virtual Datatype Create_indexed(int count,
				  const int array_of_blocklengths[],
				  const int array_of_displacements[]) const;

  static Datatype Create_struct(int count, const int array_of_blocklengths[],
				const Aint array_of_displacements[],
				const Datatype array_if_types[]);

  virtual Datatype Create_hindexed(int count, const int array_of_blocklengths[],
				   const Aint array_of_displacements[]) const;

  virtual Datatype Create_hvector(int count, int blocklength, Aint stride) const;

  virtual Datatype Create_indexed_block(int count, int blocklength,
                    const int array_of_blocklengths[]) const;

  virtual Datatype Create_resized(const Aint lb, const Aint extent) const;

  virtual int Get_size() const;

  virtual void Get_extent(Aint& lb, Aint& extent) const;

  virtual void Get_true_extent(Aint&, Aint&) const;

  virtual void Commit();

  virtual void Free();

  virtual void Pack(const void* inbuf, int incount, void *outbuf,
		    int outsize, int& position, const Comm &comm) const;

  virtual void Pack_external(const char* datarep, const void* inbuf,
		    int incount, void *outbuf, Aint outsize,
		    Aint& position) const;

  virtual void Unpack(const void* inbuf, int insize, void *outbuf, int outcount,
		      int& position, const Comm& comm) const;

  virtual void Unpack_external(const char* datarep, const void* inbuf,
		    Aint insize, Aint& position,  void *outbuf,
		    int outcount) const;

  virtual int Pack_size(int incount, const Comm& comm) const;

  virtual Aint Pack_external_size(const char* datarep, int incount) const;

  //
  // Miscellany
  //
#ifndef HP_MPI_NOIO
  virtual Datatype Create_subarray(int ndims, const int array_of_sizes[],
				   const int array_of_subsizes[],
				   const int array_of_starts[], int order)
    const;
#endif

  //
  // External Interfaces
  //

  virtual Datatype Dup() const;

  static int Create_keyval(Copy_attr_function* type_copy_attr_fn,
                           Delete_attr_function* type_delete_attr_fn,
                           void* extra_state);

  virtual void Delete_attr(int type_keyval);

  static void Free_keyval(int& type_keyval);

  virtual bool Get_attr(int type_keyval, void* attribute_val) const;

  virtual void Get_contents(int max_integers, int max_addresses,
                            int max_datatypes, int array_of_integers[],
                            Aint array_of_addresses[],
                            Datatype array_of_datatypes[]) const;

  virtual void Get_envelope(int& num_integers, int& num_addresses,
                            int& num_datatypes, int& combiner) const;

  virtual void Get_name(char* type_name, int& resultlen) const;

  virtual void Set_attr(int type_keyval, const void* attribute_val);

  virtual void Set_name(const char* type_name);

  static Datatype Create_f90_integer(int r);
  static Datatype Create_f90_real(int p, int r);
  static Datatype Create_f90_complex(int p, int r);
  static Datatype Match_size(int typeclass, int size);

#ifdef HPMPI_LONG_EXTENTIONS
#include "mpiCC/datatypeL.h"
#endif

protected:
  MPI_Datatype mpi_datatype;

};

