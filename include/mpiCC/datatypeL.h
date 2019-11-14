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

  virtual Datatype Create_contiguousL(Aint count) const;

  virtual Datatype Create_vectorL(Aint count, Aint blocklength,
				 Aint stride) const;

  virtual Datatype Create_indexedL(Aint count,
				  const Aint array_of_blocklengths[],
				  const Aint array_of_displacements[]) const;

  static Datatype Create_structL(Aint count, const Aint array_of_blocklengths[],
				const Aint array_of_displacements[],
				const Datatype array_if_types[]);

  virtual Datatype Create_hindexedL(Aint count,
				   const Aint array_of_blocklengths[],
				   const Aint array_of_displacements[]) const;

  virtual Datatype Create_hvectorL(Aint count, Aint blocklength,
				   Aint stride) const;

  virtual Datatype Create_indexed_blockL(Aint count, Aint blocklength,
                    const Aint array_of_blocklengths[]) const;

  virtual Aint Get_sizeL() const;

  virtual void PackL(const void* inbuf, Aint incount, void *outbuf,
		    Aint outsize, Aint& position, const Comm &comm) const;

  virtual void Pack_externalL(const char* datarep, const void* inbuf,
                   Aint incount, void *outbuf, Aint outsize,
                   Aint& position) const;

  virtual void UnpackL(const void* inbuf, Aint insize, void *outbuf,
		      Aint outcount, Aint& position, const Comm& comm) const;

  virtual void Unpack_externalL(const char* datarep, const void* inbuf,
                   Aint insize, Aint& position,  void *outbuf,
                   Aint outcount) const;

  virtual Aint Pack_sizeL(Aint incount, const Comm& comm) const;

  virtual Aint Pack_external_sizeL(const char* datarep, Aint incount) const;

  //
  // External Interfaces
  //

  // virtual void Get_contentsL(int max_integers, int max_addresses,
  //                          int max_datatypes, int array_of_integers[],
  //                          Aint array_of_addresses[],
  //                          Datatype array_of_datatypes[]) const;

  // virtual void Get_envelopeL(int& num_integers, int& num_addresses,
  //                          int& num_datatypes, int& combiner) const;

#endif
