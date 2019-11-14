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
// Point-to-Point Communication
//

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_contiguousL(_REAL_MPI_::Aint count) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_contiguousL(count, mpi_datatype, &newtype);
  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_vectorL(_REAL_MPI_::Aint count,
	_REAL_MPI_::Aint blocklength, _REAL_MPI_::Aint stride) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_vectorL(count, blocklength, stride, mpi_datatype, &newtype);
  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_indexedL(_REAL_MPI_::Aint count,
		     const _REAL_MPI_::Aint array_of_blocklengths[],
		     const _REAL_MPI_::Aint array_of_displacements[]) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_indexedL(count, (_REAL_MPI_::Aint *) array_of_blocklengths,
			(_REAL_MPI_::Aint *) array_of_displacements,
			mpi_datatype, &newtype);
  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_structL(_REAL_MPI_::Aint count,
		const _REAL_MPI_::Aint array_of_blocklengths[],
		const _REAL_MPI_::Aint array_of_displacements[],
		const _REAL_MPI_::Datatype array_of_types[])
{
  MPI_Datatype newtype;
  _REAL_MPI_::Aint i;
  MPI_Datatype* type_array = new MPI_Datatype[count];
  for (i=0; i < count; i++)
    type_array[i] = array_of_types[i];

  (void)MPI_Type_create_structL(count,
		(MPI_Aint*)array_of_blocklengths,
		(MPI_Aint*)array_of_displacements,
                type_array, &newtype);
  delete[] type_array;
  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_hindexedL(_REAL_MPI_::Aint count,
		const _REAL_MPI_::Aint array_of_blocklengths[],
		const _REAL_MPI_::Aint array_of_displacements[]) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_create_hindexedL(count,
		(MPI_Aint*)array_of_blocklengths,
                (MPI_Aint*)array_of_displacements,
                mpi_datatype, &newtype) ;
  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_hvectorL(_REAL_MPI_::Aint count,
		_REAL_MPI_::Aint blocklength,
		_REAL_MPI_::Aint stride) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_create_hvectorL(count, blocklength, (MPI_Aint)stride,
                                mpi_datatype, &newtype);

  return newtype;
}

inline _REAL_MPI_::Datatype
_REAL_MPI_::Datatype::Create_indexed_blockL(_REAL_MPI_::Aint count,
		_REAL_MPI_::Aint blocklength,
                const _REAL_MPI_::Aint array_of_displacements[]) const
{
  MPI_Datatype newtype;
  (void)MPI_Type_create_indexed_blockL(count, blocklength,
                                 (MPI_Aint *)array_of_displacements,
                                 mpi_datatype, &newtype);
  return newtype;
}

inline _REAL_MPI_::Aint
_REAL_MPI_::Datatype::Get_sizeL() const
{
  _REAL_MPI_::Aint size;
  (void)MPI_Type_sizeL(mpi_datatype, &size);
  return size;
}

inline void
_REAL_MPI_::Datatype::PackL(const void* inbuf, _REAL_MPI_::Aint incount,
			   void *outbuf, _REAL_MPI_::Aint outsize,
			   _REAL_MPI_::Aint& position,
			   const _REAL_MPI_::Comm &comm) const
{
  (void)MPI_PackL((void *) inbuf, incount,  mpi_datatype, outbuf,
		 outsize, &position, comm);
}

inline void
_REAL_MPI_::Datatype::Pack_externalL(const char* datarep, const void* inbuf,
                   _REAL_MPI_::Aint incount, void *outbuf,
		   _REAL_MPI_::Aint outsize, _REAL_MPI_::Aint& position) const
{
  (void)MPI_Pack_externalL((char *)datarep, (void *)inbuf, incount,
                   mpi_datatype, outbuf, outsize, &position);
}

inline void
_REAL_MPI_::Datatype::UnpackL(const void* inbuf, _REAL_MPI_::Aint insize,
			     void *outbuf, _REAL_MPI_::Aint outcount,
			     _REAL_MPI_::Aint& position,
			     const _REAL_MPI_::Comm& comm) const
{
  (void)MPI_UnpackL((void *) inbuf, insize, &position,
		   outbuf, outcount, mpi_datatype, comm);
}

inline void
_REAL_MPI_::Datatype::Unpack_externalL(const char* datarep, const void* inbuf,
                   _REAL_MPI_::Aint insize, _REAL_MPI_::Aint& position,
		   void *outbuf, _REAL_MPI_::Aint outcount) const
{
  (void)MPI_Unpack_externalL((char *)datarep, (void *)inbuf, insize,
		   &position, outbuf, outcount, mpi_datatype);
}

inline _REAL_MPI_::Aint
_REAL_MPI_::Datatype::Pack_sizeL(_REAL_MPI_::Aint incount,
				const _REAL_MPI_::Comm& comm) const
{
  _REAL_MPI_::Aint size;
  (void)MPI_Pack_sizeL(incount, mpi_datatype, comm, &size);
  return size;
}

inline _REAL_MPI_::Aint
_REAL_MPI_::Datatype::Pack_external_sizeL(const char* datarep,
				_REAL_MPI_::Aint incount) const
{
  _REAL_MPI_::Aint size;
  (void)MPI_Pack_external_sizeL((char *)datarep, incount, mpi_datatype, &size);
  return size;
}

#endif
