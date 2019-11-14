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
// Point-to-Point Communication
//

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_contiguous(int count) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_contiguous(count, mpi_datatype, &newtype);
  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_vector(int count, int blocklength,
			     int stride) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_vector(count, blocklength, stride, mpi_datatype, &newtype);
  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_indexed(int count,
				     const int array_of_blocklengths[],
				     const int array_of_displacements[]) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_indexed(count, (int *) array_of_blocklengths,
			 (int *) array_of_displacements, mpi_datatype, &newtype);
  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_struct(int count, const int array_of_blocklengths[],
				    const _REAL_MPI_::Aint array_of_displacements[],
				    const _REAL_MPI_::Datatype array_of_types[])
{
  MPI_Datatype newtype;
  int i;
  MPI_Datatype* type_array = new MPI_Datatype[count];
  for (i=0; i < count; i++)
    type_array[i] = array_of_types[i];

  (void)MPI_Type_create_struct(count, (int*)array_of_blocklengths,
                               (MPI_Aint*)array_of_displacements,
                               type_array, &newtype);
  delete[] type_array;
  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_hindexed(int count, const int array_of_blocklengths[],
				      const _REAL_MPI_::Aint array_of_displacements[]) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_create_hindexed(count, (int*)array_of_blocklengths,
                                 (MPI_Aint*)array_of_displacements,
                                 mpi_datatype, &newtype) ;
  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_hvector(int count, int blocklength,
				     _REAL_MPI_::Aint stride) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_create_hvector(count, blocklength, (MPI_Aint)stride,
                                mpi_datatype, &newtype);

  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_indexed_block(int count, int blocklength,
                    const int array_of_displacements[]) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_create_indexed_block(count, blocklength,
                                 const_cast<int *>(array_of_displacements),
                                 mpi_datatype, &newtype);
  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_resized(const _REAL_MPI_::Aint lb, const _REAL_MPI_::Aint extent) const
{
    MPI_Datatype newtype;

    (void) MPI_Type_create_resized(mpi_datatype, lb, extent, &newtype);
    return(newtype);
}

inline int
_REAL_MPI_::Datatype::Get_size() const
{
  int size;
  (void)MPI_Type_size(mpi_datatype, &size);
  return size;
}

inline void
_REAL_MPI_::Datatype::Get_extent(_REAL_MPI_::Aint& lb, _REAL_MPI_::Aint& extent) const
{
  (void)MPI_Type_get_extent(mpi_datatype, &lb, &extent);
}

inline void
_REAL_MPI_::Datatype::Get_true_extent(_REAL_MPI_::Aint& lb, _REAL_MPI_::Aint& extent) const
{
    (void) MPI_Type_get_true_extent(mpi_datatype, &lb, &extent);
}

inline void
_REAL_MPI_::Datatype::Commit()
{
  (void)MPI_Type_commit(&mpi_datatype);
}

inline void
_REAL_MPI_::Datatype::Free()
{
  (void)MPI_Type_free(&mpi_datatype);
}

inline void
_REAL_MPI_::Datatype::Pack(const void* inbuf, int incount,
			   void *outbuf, int outsize,
			   int& position, const _REAL_MPI_::Comm &comm) const
{
  (void)MPI_Pack((void *) inbuf, incount,  mpi_datatype, outbuf,
		 outsize, &position, comm);
}

inline void
_REAL_MPI_::Datatype::Pack_external(const char* datarep, const void* inbuf,
                    int incount, void *outbuf, _REAL_MPI_::Aint outsize,
                    _REAL_MPI_::Aint& position) const
{
  (void)MPI_Pack_external((char*)datarep, (void*)inbuf, incount, mpi_datatype,
 		    outbuf, (MPI_Aint)outsize, (MPI_Aint*)&position);
}

inline void
_REAL_MPI_::Datatype::Unpack(const void* inbuf, int insize,
			     void *outbuf, int outcount, int& position,
			     const _REAL_MPI_::Comm& comm) const
{
  (void)MPI_Unpack((void *) inbuf, insize, &position,
		   outbuf, outcount, mpi_datatype, comm);
}

inline void
_REAL_MPI_::Datatype::Unpack_external(const char* datarep, const void* inbuf,
                    _REAL_MPI_::Aint insize, _REAL_MPI_::Aint& position,
		    void *outbuf, int outcount) const
{
   (void)MPI_Unpack_external((char *)datarep, (void *)inbuf, (MPI_Aint)insize,
		    (MPI_Aint*) &position, outbuf, outcount, mpi_datatype);
}

inline int
_REAL_MPI_::Datatype::Pack_size(int incount, const _REAL_MPI_::Comm& comm) const
{
  int size;
  (void)MPI_Pack_size(incount, mpi_datatype, comm, &size);
  return size;
}

inline _REAL_MPI_::Aint
_REAL_MPI_::Datatype::Pack_external_size(const char* datarep,
		    int incount) const
{
  _REAL_MPI_::Aint size;
  (void)MPI_Pack_external_size((char *)datarep, incount, mpi_datatype,
		    (MPI_Aint*)&size);
  return size;
}

//
// Miscalleny
//

#ifndef HP_MPI_NOIO
inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_subarray(int ndims, const int array_of_sizes[],
				      const int array_of_subsizes[],
				      const int array_of_starts[], int order)
  const
{
  MPI_Datatype type;
  (void) MPI_Type_create_subarray(ndims, (int *) array_of_sizes,
			   (int *) array_of_subsizes, (int *) array_of_starts,
			   order, mpi_datatype, &type);
  return type;
}
#endif

//
// External Interfaces
//

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Dup() const
{
  MPI_Datatype type;
  (void) MPI_Type_dup(mpi_datatype, &type);
  return type;
}

inline int
_REAL_MPI_::Datatype::Create_keyval(
           _REAL_MPI_::Datatype::Copy_attr_function*
                               type_copy_attr_fn,
           _REAL_MPI_::Datatype::Delete_attr_function*
                               type_delete_attr_fn, void* extra_state)
{
  int key;
  (void) MPI_Type_create_keyval((MPI_Type_copy_attr_function *)
				type_copy_attr_fn,
				(MPI_Type_delete_attr_function *)
				type_delete_attr_fn, &key, extra_state);
  return key;
}

inline void
_REAL_MPI_::Datatype::Delete_attr(int type_keyval)
{
  (void) MPI_Type_delete_attr(mpi_datatype, type_keyval);
}

inline void
_REAL_MPI_::Datatype::Free_keyval(int& type_keyval)
{
  (void) MPI_Type_free_keyval(&type_keyval);
}

inline bool
_REAL_MPI_::Datatype::Get_attr(int type_keyval,
                          void* attribute_val) const
{
  int ret;
  (void) MPI_Type_get_attr(mpi_datatype, type_keyval, attribute_val, &ret);
  return (bool) ret;
}

inline void
_REAL_MPI_::Datatype::Get_contents(int max_integers, int max_addresses,
				   int max_datatypes, int array_of_integers[],
				   _REAL_MPI_::Aint array_of_addresses[],
				   _REAL_MPI_::Datatype array_of_datatypes[])
  const
{
  int i;
  MPI_Datatype* type_array = new MPI_Datatype[max_datatypes];

  // Because array_of_datatypes is an out parameter, no need to copy
  // parameter to temp 'type_array'.  But do need to copy it back before
  // returning.

  (void) MPI_Type_get_contents(mpi_datatype, max_integers, max_addresses,
			       max_datatypes, (int *)array_of_integers,
			       (MPI_Aint*) array_of_addresses,
			       type_array);
  for (i=0; i < max_datatypes; i++)
     array_of_datatypes[i] = type_array[i];
  delete[] type_array;
}

inline void
_REAL_MPI_::Datatype::Get_envelope(int& num_integers, int& num_addresses,
			  int& num_datatypes, int& combiner) const
{
  (void) MPI_Type_get_envelope(mpi_datatype, &num_integers, &num_addresses,
				&num_datatypes, &combiner);
}

inline void
_REAL_MPI_::Datatype::Get_name(char* type_name, int& resultlen) const
{
  (void) MPI_Type_get_name(mpi_datatype, type_name, &resultlen);
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_f90_integer(int r)
{
    MPI_Datatype dt;
    (void) MPI_Type_create_f90_integer(r, &dt);
    return dt;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_f90_real(int p, int r)
{
    MPI_Datatype dt;
    (void) MPI_Type_create_f90_real(p, r, &dt);
    return dt;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_f90_complex(int p, int r)
{
    MPI_Datatype dt;
    (void) MPI_Type_create_f90_complex(p, r, &dt);
    return dt;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Match_size(int typeclass, int size)
{
    MPI_Datatype dt;
    (void) MPI_Type_match_size(typeclass, size, &dt);
    return dt;
}

inline void
_REAL_MPI_::Datatype::Set_attr(int type_keyval, const void* attribute_val)
{
  (void) MPI_Type_set_attr(mpi_datatype, type_keyval, (void *) attribute_val);
}

inline void
_REAL_MPI_::Datatype::Set_name(const char* type_name)
{
  (void) MPI_Type_set_name(mpi_datatype, (char *)type_name);
}

inline int
_REAL_MPI_::Datatype::NULL_COPY_FN(const _REAL_MPI_::Datatype& oldtype,
                                   int type_keyval,
                                   void* extra_state,
                                   void* attribute_val_in,
                                   void* attribute_val_out,
                                   bool& flag)
{
  int f = (int)flag;
  int ret;
  if (MPI_TYPE_NULL_COPY_FN != 0) {

    // Portland pgCC 5.0-2 has a bug that we have to workaround here.
    // MPI_NULL_COPY_FN is actually a #define for ((MPI_Copy_function
    // *) 0).  If we try to invoke it, such as:
    //   ret = MPI_NULL_COPY_FN(...);
    // the preprocessor will resolve this to:
    //   ret = ((MPI_Copy_function *) 0)(...);
    // which should be fine.  But unfortunately, pgCC 5.0-2 makes this
    // into a real symbol that will refuse to link.  The workaround is
    // to assign this into a temp variable and then invoke through the
    // function pointer.  This shouldn't be necessary.  :-(

    MPI_Type_copy_attr_function *stupid_compiler = MPI_TYPE_NULL_COPY_FN;
    ret = stupid_compiler(oldtype, type_keyval, extra_state,
                          attribute_val_in, attribute_val_out, &f);
    flag = (bool)f;
  } else {
    ret = MPI_SUCCESS;
    flag = false;
  }
  return ret;
}

inline int
_REAL_MPI_::Datatype::DUP_FN(const _REAL_MPI_::Datatype& oldtype,
                         int type_keyval,
                         void* extra_state,
                         void* attribute_val_in,
                         void* attribute_val_out,
                         bool& flag)
{
  int f = (int)flag;
  int ret;
  ret = MPI_TYPE_DUP_FN(oldtype, type_keyval, extra_state,
                        attribute_val_in, attribute_val_out, &f);
  flag = (bool) f;
  return ret;
}

inline int
_REAL_MPI_::Datatype::NULL_DELETE_FN(_REAL_MPI_::Datatype& type,
                                 int type_keyval,
                                 void* attribute_val,
                                 void* extra_state)
{
  if (MPI_NULL_DELETE_FN != 0) {

    // See note in MPI_NULL_COPY_FN.

    MPI_Type_delete_attr_function *stupid_compiler = MPI_TYPE_NULL_DELETE_FN;
    return stupid_compiler(type, type_keyval, attribute_val, extra_state);
  } else
    return MPI_SUCCESS;
}

#ifdef HPMPI_LONG_EXTENTIONS
#include "mpiCC/datatypeL_inln.h"
#endif

