/*
 *
 *	Copyright IBM corp. 1983-2010, 2012-2016
 *      US Government Users Restricted Rights:
 *          Use, duplication or disclosure restricted
 *          by GSA ADP Schedule Contract with IBM Corp.
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
 *	  versions 6.0, 6.1
 *	  (c)Copyright 1995-1996 The Ohio State University
 *
 *	"@(#)IBM Platform MPI 09.01.04.03 [BASELINE_MPI_STREAM_REL_9.1.4.0_RTM_2015_06_15]  [] [] [] [] [] [] (02/06/2018) Linux x86-64"
 */

#ifndef _MPI_H
#define _MPI_H

#if defined(c_plusplus) || defined(__cplusplus)
extern "C" {
#endif

/*****************************************************************
 * MPI Constants definition.
 *****************************************************************/
/*
 * MPI version
 */
#define MPI_VERSION	2
#define MPI_SUBVERSION	2

#define PLATFORM_MPI	0x09010403
#define HP_MPI		203
#define HP_MPI_MINOR	1

/*
 * user-visible MPI object
 */
typedef struct {
	int		MPI_SOURCE;
	int		MPI_TAG;
	int		MPI_ERROR;
	int		st_cancel;		/* opaque to user */
	long long	st_count;		/* opaque to user */
	int		st_pad[2];
} MPI_Status;

/*
 * MPI defined constants
 */
#define MPI_PROC_NULL		-1		/* rank of null process */
#define MPI_ANY_SOURCE		-2		/* match any source rank */
#define MPI_ROOT		-3		/* calling process is root */
#define MPI_ANY_TAG		-1		/* match any message tag */
#define MPI_MAX_PROCESSOR_NAME	256		/* max proc. name length */
#define MPI_MAX_OBJECT_NAME     64              /* max object name length */
#define MPI_MAX_ERROR_STRING	256		/* max error message length */
#define MPI_MAX_PORT_NAME	64              /* max port name length */
#define MPI_MAX_DATAREP_STRING 128 /* max length of data rep */
#define MPI_UNDEFINED		-32766		/* undefined stuff */
#define MPI_GRAPH		1		/* graph topology */
#define MPI_CART		2		/* cartesian topology */
#define MPI_DIST_GRAPH	3		/* distributed graph topology */
#define MPI_KEYVAL_INVALID	-1		/* invalid key value */
#define MPI_BSEND_OVERHEAD	64		/* bsend packing overhead */
#define MPI_TYPECLASS_INTEGER	1		/* integer datatype class */
#define MPI_TYPECLASS_REAL	2		/* real datatype class */
#define MPI_TYPECLASS_COMPLEX	3		/* complex datatype class */

#define MPI_IDENT		0		/* comparison result */
#define MPI_CONGRUENT		1		/* comparison result */
#define MPI_SIMILAR		2		/* comparison result */
#define MPI_UNEQUAL		3		/* comparison result */
#define MPI_MAX_INFO_KEY	256		/* max info key length */
#define MPI_MAX_INFO_VAL	16384		/* max info value length */
#define MPI_LOCK_EXCLUSIVE	1		/* exclusive lock */
#define MPI_LOCK_SHARED		2		/* shared lock */

#define MPI_THREAD_SINGLE	0		/* one thread only */
#define MPI_THREAD_FUNNELED	1		/* mthreaded, main only */
#define MPI_THREAD_SERIALIZED	2		/* mthreaded, one at a time */
#define MPI_THREAD_MULTIPLE	3		/* mthreaded, unrestricted */

/*
 * Predefined attribute keys.
 */
#define MPI_TAG_UB		0		/* max tag value can be used */
#define MPI_HOST		1		/* the host rank if exits */
#define MPI_IO			2		/* which rank accept input */
#define MPI_WTIME_IS_GLOBAL	3		/* if world is on same host */
#define IMPI_CLIENT_SIZE	4		/* client size in this comm */
#define IMPI_CLIENT_COLOR	5		/* the color of my client */
#define IMPI_HOST_SIZE		6		/* host size in this comm */
#define IMPI_HOST_COLOR		7		/* the color of my host */
#define MPI_WIN_BASE		8		/* the window base buffer */
#define MPI_WIN_SIZE		9		/* the window buffer size */
#define MPI_WIN_DISP_UNIT	10		/* the displace unit */
#define MPI_WIN_CREATE_FLAVOR   11              /* how the window was created */
#define MPI_WIN_MODEL           12              /* memory model for window */
#define MPI_UNIVERSE_SIZE       13              /* universe size of job */
#define MPI_APPNUM              14              /* # of app. in the world */
#define MPI_LASTUSEDCODE        15              /* last used error code */

/*
 * Predefined reference constants
 */
/*
 * MPI_BOTTOM will depend on a flag (set via MPI_FLAGS=i), where the
 * default is to leave MPI_BOTTOM as "address zero" so we don't break
 * apps that depend on the old behavior, but if the MPI_FLAGS=i flag
 * is on, then it will instead use the same MPI_BOTTOM as fortran, to
 * allow language interoperability as required in section 4.12.10 of
 * the MPI-2 standard.
 */
extern int			hpmp_flinteroperate;
extern void			*hpmp_f_mpi_bottom;
extern void			*hpmp_f_mpi_in_place;
extern void			*MPI_F_STATUS_IGNORE;
extern void			*MPI_F_STATUSES_IGNORE;
#define MPI_BOTTOM  ((hpmp_flinteroperate)?(hpmp_f_mpi_bottom):((void *) 0))
#define MPI_STATUS_IGNORE	((MPI_Status *) 0)	/* status ignore */
#define MPI_STATUSES_IGNORE	((MPI_Status *) 0)	/* statuses ignore */
#define MPI_ERRCODES_IGNORE	((int *) 0)	/* error codes ignore */
#define MPI_ARGV_NULL		((char **) 0)	/* NULL spawn argument */
#define MPI_ARGVS_NULL		((char ***) 0)	/* NULL spawnmultiple arg */
#define MPI_IN_PLACE		(hpmp_f_mpi_in_place)/* collective in place */
#define MPI_UNWEIGHTED		((void*) 0)	/* NULL weight argument */
/*
 * error classes, also see file mpi_error.h & mperror.c
 */
#define MPI_SUCCESS		0		/* no errors */
#define MPI_ERR_BUFFER		1		/* invalid buffer */
#define MPI_ERR_COUNT		2		/* invalid count */
#define MPI_ERR_TYPE		3		/* invalid datatype */
#define MPI_ERR_TAG		4		/* invalid tag */
#define MPI_ERR_COMM		5		/* invalid communicator */
#define MPI_ERR_RANK		6		/* invalid rank */
#define MPI_ERR_ROOT		7		/* invalid root */
#define MPI_ERR_GROUP		8		/* invalid group */
#define MPI_ERR_OP		9		/* invalid operation */
#define MPI_ERR_TOPOLOGY	10		/* invalid topology */
#define MPI_ERR_DIMS		11		/* invalid dimension */
#define MPI_ERR_ARG		12		/* invalid argument */
#define MPI_ERR_UNKNOWN		13		/* unknown error */
#define MPI_ERR_TRUNCATE	14		/* message truncated */
#define MPI_ERR_OTHER		15		/* other known error */
#define MPI_ERR_INTERN		16		/* internal MPI error */
#define MPI_ERR_IN_STATUS	17		/* error code in status */
#define MPI_ERR_PENDING		18		/* pending request */
#define MPI_ERR_REQUEST		19		/* invalid request */
#define MPI_ERR_INFO		20		/* invalid info arg */
#define MPI_ERR_INFO_NOKEY	21		/* info key not defined */
#define MPI_ERR_INFO_KEY	22		/* invalid info key */
#define MPI_ERR_INFO_VALUE	23		/* invalid info value */
#define MPI_ERR_WIN		24		/* invalid window arg */
#define MPI_ERR_BASE		25		/* invalid window base */
#define MPI_ERR_SIZE		26		/* invalid window size */
#define MPI_ERR_DISP		27		/* invalid window unit disp. */
#define MPI_ERR_LOCKTYPE	28		/* invalid locktype arg */
#define MPI_ERR_ASSERT		29		/* invalid assert arg */
#define MPI_ERR_RMA_CONFLICT	30		/* conflicting access to win */
#define MPI_ERR_RMA_SYNC	31		/* invalid window sync */
#define MPI_ERR_NO_MEM		32		/* out of "special" memory */
#define MPI_ERR_KEYVAL		33		/* invalid key value */
#define MPI_ERR_SPAWN		34		/* spawn error */
#define MPI_ERR_PORT		51		/* invalid port name */
#define MPI_ERR_SERVICE		52		/* invalid service name */
#define MPI_ERR_NAME		53		/* nonexist service name */
#define MPI_ERR_EXITED		54		/* peer rank is exited */
#define MPI_ERR_CONNECT		55		/* OnDemand connect failed */
#define MPI_ERR_PROC_FAILED	56		/* target rank has exited */
#define MPI_ERR_REVOKED		57		/* Comm has been revoked */
#define MPI_ERR_LASTCODE	0x3FFFFFFF	/* last error code */

/*
 * one-sided assert flags
 */
#define MPI_MODE_NOCHECK	0x01		/* no synchronization check */
#define MPI_MODE_NOSTORE	0x02		/* no previous local stores */
#define MPI_MODE_NOPUT		0x04		/* no following put/acc. */
#define MPI_MODE_NOPRECEDE	0x08		/* no previous local RMA */
#define MPI_MODE_NOSUCCEED	0x10		/* no following local RMA */

#define MPI_COMM_TYPE_SHARED    0x20

/*
 * datatype decoding combiners
 */
#define MPI_COMBINER_NAMED		0	/* predefined datatype */
#define MPI_COMBINER_DUP		1	/* Type_dup */
#define MPI_COMBINER_CONTIGUOUS		2	/* Type_contiguous */
#define MPI_COMBINER_VECTOR		3	/* Type_vector */
#define MPI_COMBINER_HVECTOR_INTEGER	4	/* f77 Type_hvector */
#define MPI_COMBINER_HVECTOR		5	/* Type_hvector */
#define MPI_COMBINER_INDEXED		6	/* Type_indexed */
#define MPI_COMBINER_HINDEXED_INTEGER	7	/* f77 Type_hindexed */
#define MPI_COMBINER_HINDEXED		8	/* Type_hindexed */
#define MPI_COMBINER_INDEXED_BLOCK	9	/* Type_create_indexed_block */
#define MPI_COMBINER_STRUCT_INTEGER	10	/* f77 MPI_Type_struct */
#define MPI_COMBINER_STRUCT		11	/* Type_struct */
#define MPI_COMBINER_SUBARRAY		12	/* Type_create_subarray */
#define MPI_COMBINER_DARRAY		13	/* Type_create_darray */
#define MPI_COMBINER_F90_REAL		14	/* Type_create_f90_real */
#define MPI_COMBINER_F90_COMPLEX	15	/* Type_create_f90_complex */
#define MPI_COMBINER_F90_INTEGER	16	/* Type_create_f90_integer */
#define MPI_COMBINER_RESIZED		17	/* Type_create_resized */

/*****************************************************************
 * MPI Objects definition.
 *****************************************************************/
#if !defined(MPI_hpux) || defined(HPMP_BUILD_CXXBINDING)
    typedef void* voidptr;
#   define HPMP_COMM_T voidptr
#   define HPMP_DTYPE_T voidptr
#   define HPMP_GROUP_T voidptr
#   define HPMP_OP_T voidptr
#   define HPMP_ERR_T voidptr
#   define HPMP_REQ_T voidptr
#   define HPMP_INFO_T voidptr
#   define HPMP_WIN_T voidptr
#   define HPMP_MSG_T voidptr
#   define HPMP_REQC_T voidptr
#else
#   define HPMP_COMM_T struct hpmp_comm_s
#   define HPMP_DTYPE_T struct hpmp_dtype_s
#   define HPMP_GROUP_T struct hpmp_group_s
#   define HPMP_OP_T struct hpmp_op_s
#   define HPMP_REQ_T struct hpmp_req_s
#   define HPMP_ERR_T struct hpmp_err_s
#   define HPMP_INFO_T struct hpmp_info_s
#   define HPMP_WIN_T struct hpmp_win_s
#   define HPMP_MSG_T struct hpmp_message_s
#   define HPMP_REQC_T struct hpmp_greqx_class_s
#endif

/*
 * MPI object typedefs.
 */
typedef HPMP_COMM_T		*MPI_Comm;	/* communicator object */
typedef HPMP_DTYPE_T		*MPI_Datatype;	/* datatype object */
typedef HPMP_GROUP_T		*MPI_Group;	/* group object */
typedef HPMP_OP_T		*MPI_Op;	/* operation object */
typedef HPMP_REQ_T		*MPI_Request;	/* request object */
typedef HPMP_ERR_T		*MPI_Errhandler;/* error handler object */
typedef HPMP_INFO_T		*MPI_Info;	/* info object */
typedef HPMP_WIN_T		*MPI_Win;	/* window object */
typedef HPMP_MSG_T		*MPI_Message;	/* message object */
typedef long			MPI_Aint;	/* address-sized integer */
typedef int			MPI_Fint;	/* fortran integer */
typedef long long	MPI_Count;
typedef HPMP_REQC_T		*MPIX_Grequest_class; /* gen-req class */

/*
 * User function typedefs
 */
#if defined(__STDC__) || defined(c_plusplus) || defined(__cplusplus) || defined(_WIN32)
typedef int		(MPI_Copy_function)(MPI_Comm, int, void *,
						void *, void *, int *);
typedef int		(MPI_Delete_function)(MPI_Comm, int, void *, void *);
typedef void		(MPI_Handler_function)(MPI_Comm *, int *, ...);
typedef void		(MPI_User_function)(void *, void *, int *,
						MPI_Datatype *);
typedef void		(MPI_Comm_errhandler_function)(MPI_Comm *, int *, ...);
typedef int		(MPI_Comm_copy_attr_function)(MPI_Comm,
				int, void *, void *, void *, int *);
typedef int		(MPI_Comm_delete_attr_function)(MPI_Comm,
				int, void *, void *);
typedef int		(MPI_Grequest_query_function)(void *, MPI_Status*);
typedef int		(MPI_Grequest_free_function)(void *);
typedef int		(MPI_Grequest_cancel_function)(void *, int);
typedef int		(MPIX_Grequest_poll_fn)(void *, MPI_Status *);
typedef int		(MPIX_Grequest_wait_fn)(int,void*, double, MPI_Status*);
typedef void		(MPI_Win_errhandler_function)(MPI_Win *, int *, ...);
typedef int		(MPI_Win_copy_attr_function)(MPI_Win, int,
				void *, void *, void *, int *);
typedef int		(MPI_Win_delete_attr_function)(MPI_Win, int,
				void *, void *);
typedef int		(MPI_Type_copy_attr_function)(MPI_Datatype, int,
				void *, void *, void *, int *);
typedef int		(MPI_Type_delete_attr_function)(MPI_Datatype, int,
				void *, void *);
#else
typedef int		(MPI_Copy_function)();
typedef int		(MPI_Delete_function)();
typedef void		(MPI_Handler_function)();
typedef void		(MPI_User_function)();
typedef void		(MPI_Comm_errhandler_function)();
typedef int		(MPI_Comm_copy_attr_function)();
typedef int		(MPI_Comm_delete_attr_function)();
typedef int		(MPI_Grequest_query_function)();
typedef int		(MPI_Grequest_free_function)();
typedef int		(MPI_Grequest_cancel_function)();
typedef int		(MPIX_Grequest_poll_fn)();
typedef int		(MPIX_Grequest_wait_fn)();
typedef void		(MPI_Win_errhandler_function)();
typedef int		(MPI_Win_copy_attr_function)();
typedef int		(MPI_Win_delete_attr_function)();
typedef int		(MPI_Type_copy_attr_function)();
typedef int		(MPI_Type_delete_attr_function)();
#endif
/* names that were added in MPI-2.0 and deprecated in MPI-2.2 */
typedef MPI_Comm_errhandler_function MPI_Comm_errhandler_fn;
typedef MPI_Win_errhandler_function MPI_Win_errhandler_fn;
/*
 * NULL handles
 */
#define MPI_COMM_NULL		((MPI_Comm) 0)
#define MPI_DATATYPE_NULL	((MPI_Datatype) 0)
#define MPI_ERRHANDLER_NULL	((MPI_Errhandler) 0)
#define MPI_GROUP_NULL		((MPI_Group) 0)
#define MPI_OP_NULL		((MPI_Op) 0)
#define MPI_INFO_NULL		((MPI_Info) 0)
#define MPI_WIN_NULL		((MPI_Win) 0)
#define MPI_REQUEST_NULL	((MPI_Request) 0)
#define MPI_MESSAGE_NULL	((MPI_Message) 0)

#define MPI_NULL_COPY_FN	((MPI_Copy_function *) 0)
#define MPI_NULL_DELETE_FN	((MPI_Delete_function *) 0)
#define MPI_COMM_NULL_COPY_FN	((MPI_Comm_copy_attr_function *) 0)
#define MPI_COMM_NULL_DELETE_FN	((MPI_Comm_delete_attr_function *) 0)
#define MPI_WIN_NULL_COPY_FN	((MPI_Win_copy_attr_function *) 0)
#define MPI_WIN_NULL_DELETE_FN	((MPI_Win_delete_attr_function *) 0)
#define MPI_TYPE_NULL_COPY_FN	((MPI_Type_copy_attr_function *) 0)
#define MPI_TYPE_NULL_DELETE_FN	((MPI_Type_delete_attr_function *) 0)

/*
 * HP MPI global debugging variable
 */
extern volatile int		MPI_DEBUG_CONT;
extern volatile int		mpi_debug_cont;

/*
 * external variables
 */
extern HPMP_COMM_T	hpmp_comm_world, hpmp_comm_self;
extern HPMP_GROUP_T	hpmp_group_empty;

extern HPMP_OP_T	hpmp_max, hpmp_min, hpmp_sum, hpmp_prod;
extern HPMP_OP_T	hpmp_land, hpmp_band, hpmp_lor, hpmp_bor;
extern HPMP_OP_T	hpmp_lxor, hpmp_bxor, hpmp_maxloc, hpmp_minloc;
extern HPMP_OP_T	hpmp_replace;

extern HPMP_DTYPE_T	hpmp_ub, hpmp_lb;
extern HPMP_DTYPE_T	hpmp_packed, hpmp_byte;
extern HPMP_DTYPE_T	hpmp_char, hpmp_wchar;
extern HPMP_DTYPE_T	hpmp_signed_char, hpmp_unsigned_char;
extern HPMP_DTYPE_T	hpmp_short, hpmp_unsigned_short;
extern HPMP_DTYPE_T	hpmp_int, hpmp_unsigned;
extern HPMP_DTYPE_T	hpmp_long, hpmp_unsigned_long;
extern HPMP_DTYPE_T	hpmp_int8, hpmp_uint8;
extern HPMP_DTYPE_T	hpmp_float, hpmp_double, hpmp_long_double;
extern HPMP_DTYPE_T	hpmp_2int, hpmp_2float, hpmp_2double;
extern HPMP_DTYPE_T	hpmp_short_int, hpmp_long_int;
extern HPMP_DTYPE_T	hpmp_int8_int;
extern HPMP_DTYPE_T	hpmp_float_int, hpmp_double_int;
extern HPMP_DTYPE_T	hpmp_longdouble_int;
/*
	Datatypes introduced in mpi 2.2
*/
extern HPMP_DTYPE_T hpmp_aint;
extern HPMP_DTYPE_T hpmp_offset;
extern HPMP_DTYPE_T hpmp_bool;
extern HPMP_DTYPE_T hpmp_int8_t;
extern HPMP_DTYPE_T hpmp_int16_t;
extern HPMP_DTYPE_T hpmp_int32_t;
extern HPMP_DTYPE_T hpmp_int64_t;
extern HPMP_DTYPE_T hpmp_uint8_t;
extern HPMP_DTYPE_T hpmp_uint16_t;
extern HPMP_DTYPE_T hpmp_uint32_t;
extern HPMP_DTYPE_T hpmp_uint64_t;
extern HPMP_DTYPE_T hpmp_float_complex;
extern HPMP_DTYPE_T hpmp_double_complex;
extern HPMP_DTYPE_T hpmp_long_double_complex;

extern HPMP_DTYPE_T hpmp_real;
extern HPMP_DTYPE_T hpmp_integer;
extern HPMP_DTYPE_T hpmp_doubleprec;
extern HPMP_DTYPE_T hpmp_complex;
extern HPMP_DTYPE_T hpmp_logic;
extern HPMP_DTYPE_T hpmp_character;
extern HPMP_DTYPE_T hpmp_doublecomplex;
extern HPMP_DTYPE_T hpmp_integer1;
extern HPMP_DTYPE_T hpmp_integer2;
extern HPMP_DTYPE_T hpmp_integer4;
extern HPMP_DTYPE_T hpmp_integer8;
extern HPMP_DTYPE_T hpmp_real4;
extern HPMP_DTYPE_T hpmp_real8;
extern HPMP_DTYPE_T hpmp_real16;
extern HPMP_DTYPE_T hpmp_2integer;
extern HPMP_DTYPE_T hpmp_2real;
extern HPMP_DTYPE_T hpmp_2doubleprec;

extern HPMP_ERR_T	hpmp_errors_are_fatal;
extern HPMP_ERR_T	hpmp_errors_return;

/*
 * predefined communicator objects
 */
#define MPI_COMM_WORLD		((MPI_Comm) &hpmp_comm_world)
#define MPI_COMM_SELF		((MPI_Comm) &hpmp_comm_self)
#define MPI_GROUP_EMPTY		((MPI_Group) &hpmp_group_empty)

/*
 * Predefined operator objects.
 */
#define MPI_MAX			((MPI_Op) &hpmp_max)
#define MPI_MIN			((MPI_Op) &hpmp_min)
#define MPI_SUM			((MPI_Op) &hpmp_sum)
#define MPI_PROD		((MPI_Op) &hpmp_prod)
#define MPI_LAND		((MPI_Op) &hpmp_land)
#define MPI_BAND		((MPI_Op) &hpmp_band)
#define MPI_LOR			((MPI_Op) &hpmp_lor)
#define MPI_BOR			((MPI_Op) &hpmp_bor)
#define MPI_LXOR		((MPI_Op) &hpmp_lxor)
#define MPI_BXOR		((MPI_Op) &hpmp_bxor)
#define MPI_MAXLOC		((MPI_Op) &hpmp_maxloc)
#define MPI_MINLOC		((MPI_Op) &hpmp_minloc)
#define MPI_REPLACE		((MPI_Op) &hpmp_replace)

/*
 * Predefined datatype objects.
 */
#define MPI_LB			((MPI_Datatype) &hpmp_lb)
#define MPI_UB			((MPI_Datatype) &hpmp_ub)

#define MPI_PACKED		((MPI_Datatype) &hpmp_packed)
#define MPI_BYTE		((MPI_Datatype) &hpmp_byte)
#define MPI_CHAR		((MPI_Datatype) &hpmp_char)
#define MPI_WCHAR		((MPI_Datatype) &hpmp_wchar)
#define MPI_SIGNED_CHAR		((MPI_Datatype) &hpmp_signed_char)
#define MPI_SHORT		((MPI_Datatype) &hpmp_short)
#define MPI_INT			((MPI_Datatype) &hpmp_int)
#define MPI_INT4		MPI_INT
#define MPI_INT8		((MPI_Datatype) &hpmp_int8)
#define MPI_LONG		((MPI_Datatype) &hpmp_long)
#define MPI_LONG_LONG		MPI_INT8
#define MPI_LONG_LONG_INT	MPI_INT8
#define MPI_FLOAT		((MPI_Datatype) &hpmp_float)
#define MPI_DOUBLE		((MPI_Datatype) &hpmp_double)
#define MPI_LONG_DOUBLE		((MPI_Datatype) &hpmp_long_double)

#define MPI_UNSIGNED_CHAR	((MPI_Datatype) &hpmp_unsigned_char)
#define MPI_UNSIGNED_SHORT	((MPI_Datatype) &hpmp_unsigned_short)
#define MPI_UNSIGNED		((MPI_Datatype) &hpmp_unsigned)
#define MPI_UINT4		MPI_UNSIGNED
#define MPI_UINT8		((MPI_Datatype) &hpmp_uint8)
#define MPI_UNSIGNED_LONG	((MPI_Datatype) &hpmp_unsigned_long)
#define MPI_UNSIGNED_LONG_LONG	MPI_UINT8

#define MPI_2INT		((MPI_Datatype) &hpmp_2int)
#define MPI_2FLOAT		((MPI_Datatype) &hpmp_2float)
#define MPI_2DOUBLE		((MPI_Datatype) &hpmp_2double)

#define MPI_SHORT_INT		((MPI_Datatype) &hpmp_short_int)
#define MPI_INT_INT		MPI_2INT
#define MPI_LONG_INT		((MPI_Datatype) &hpmp_long_int)
#define MPI_INT8_INT		((MPI_Datatype) &hpmp_int8_int)
#define MPI_FLOAT_INT		((MPI_Datatype) &hpmp_float_int)
#define MPI_DOUBLE_INT		((MPI_Datatype) &hpmp_double_int)
#define MPI_LONG_DOUBLE_INT	((MPI_Datatype) &hpmp_longdouble_int)
/*
	Datatypes introduced in mpi 2.2
*/
#define MPI_AINT     ((MPI_Datatype) &hpmp_aint)
#define MPI_OFFSET   ((MPI_Datatype) &hpmp_offset)
#define MPI_C_BOOL   ((MPI_Datatype) &hpmp_bool)
#define MPI_INT8_T   ((MPI_Datatype) &hpmp_int8_t)
#define MPI_INT16_T  ((MPI_Datatype) &hpmp_int16_t)
#define MPI_INT32_T  ((MPI_Datatype) &hpmp_int32_t)
#define MPI_INT64_T  ((MPI_Datatype) &hpmp_int64_t)
#define MPI_UINT8_T  ((MPI_Datatype) &hpmp_uint8_t)
#define MPI_UINT16_T ((MPI_Datatype) &hpmp_uint16_t)
#define MPI_UINT32_T ((MPI_Datatype) &hpmp_uint32_t)
#define MPI_UINT64_T ((MPI_Datatype) &hpmp_uint64_t)
#define MPI_C_COMPLEX ((MPI_Datatype) &hpmp_float_complex)
#define MPI_C_FLOAT_COMPLEX MPI_C_COMPLEX
#define MPI_C_DOUBLE_COMPLEX ((MPI_Datatype) &hpmp_double_complex)
#define MPI_C_LONG_DOUBLE_COMPLEX ((MPI_Datatype) &hpmp_long_double_complex)

/*
 * Predefined error handlers
 */
#define MPI_ERRORS_ARE_FATAL	((MPI_Errhandler) &hpmp_errors_are_fatal)
#define MPI_ERRORS_RETURN	((MPI_Errhandler) &hpmp_errors_return)

/*
 * These Fortran datatypes are included
 * for GLOBUS compatability.    We provide macros named after
 * standard MPI types to provide transparent conversion from Fortran
 * (integer value) to usable 'C' datatypes.
 */
#define MPIF_INTEGER            15
#define MPIF_REAL               16
#define MPIF_DOUBLE_PRECISION   17
#define MPIF_COMPLEX            18
#define MPIF_LOGICAL            19
#define MPIF_CHARACTER          20
#define MPIF_BYTE               21
#define MPIF_PACKED             22
#define MPIF_UB                 23
#define MPIF_LB                 24
#define MPIF_2REAL              25
#define MPIF_2DOUBLE_PRECISION  26
#define MPIF_2INTEGER           27
#define MPIF_INTEGER1           28
#define MPIF_INTEGER2           29
#define MPIF_INTEGER4           30
#define MPIF_REAL4              31
#define MPIF_REAL8              32
#define MPIF_DOUBLE_COMPLEX     33

/*
 *  Make the fortran types directly available from C
 */
#define MPI_REAL		((MPI_Datatype) &hpmp_real)
#define MPI_INTEGER		((MPI_Datatype) &hpmp_integer)
#define MPI_DOUBLE_PRECISION	((MPI_Datatype) &hpmp_doubleprec)
#define MPI_COMPLEX		((MPI_Datatype) &hpmp_complex)
#define MPI_LOGICAL		((MPI_Datatype) &hpmp_logic)
#define MPI_CHARACTER		((MPI_Datatype) &hpmp_character)
#define MPI_DOUBLE_COMPLEX	((MPI_Datatype) &hpmp_doublecomplex)
#define MPI_INTEGER1		((MPI_Datatype) &hpmp_integer1)
#define MPI_INTEGER2		((MPI_Datatype) &hpmp_integer2)
#define MPI_INTEGER4		((MPI_Datatype) &hpmp_integer4)
#define MPI_INTEGER8		((MPI_Datatype) &hpmp_integer8)
#define MPI_REAL4		((MPI_Datatype) &hpmp_real4)
#define MPI_REAL8		((MPI_Datatype) &hpmp_real8)
#define MPI_REAL16		((MPI_Datatype) &hpmp_real16)
#define MPI_COMPLEX8		((MPI_Datatype) &hpmp_float_complex)
#define MPI_COMPLEX16		((MPI_Datatype) &hpmp_double_complex)
#define MPI_COMPLEX32		((MPI_Datatype) &hpmp_long_double_complex)
#define MPI_2INTEGER		((MPI_Datatype) &hpmp_2integer)
#define MPI_2REAL		((MPI_Datatype) &hpmp_2real)
#define MPI_2DOUBLE_PRECISION	((MPI_Datatype) &hpmp_2doubleprec)

/*****************************************************************
 * MPI function prototypes
 *****************************************************************/
#if defined(__STDC__) || defined(c_plusplus) || defined(__cplusplus)

#if !defined(MPI_hpux) || defined(HPMP_BUILD_CXXBINDING)

/*
 * Function prototype only for users.
 */
extern int MPI_Abort(MPI_Comm, int);
extern int MPI_Address(void *, MPI_Aint *);
extern int MPI_Allgather(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, MPI_Comm);
extern int MPI_Allgatherv(void *, int, MPI_Datatype, void *,
			int *, int *, MPI_Datatype, MPI_Comm);
extern int MPI_Allreduce(void *, void *, int, MPI_Datatype,
			MPI_Op, MPI_Comm);
extern int MPI_Alltoall(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, MPI_Comm);
extern int MPI_Alltoallv(void *, int *, int *, MPI_Datatype, void *,
			int *, int *, MPI_Datatype, MPI_Comm);
extern int MPI_Alltoallw(void *, int *, int *, MPI_Datatype*, void *,
			int *, int *, MPI_Datatype*, MPI_Comm);
extern int MPI_Attr_delete(MPI_Comm, int);
extern int MPI_Attr_get(MPI_Comm, int, void *, int *);
extern int MPI_Attr_put(MPI_Comm, int, void *);
extern int MPI_Barrier(MPI_Comm);
extern int MPI_Bcast(void *, int, MPI_Datatype, int, MPI_Comm);
extern int MPI_Bsend(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int MPI_Bsend_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int MPI_Buffer_attach(void *, int);
extern int MPI_Buffer_detach(void *, int *);
extern int MPI_Cancel(MPI_Request *);
extern int MPI_Cart_coords(MPI_Comm, int, int, int *);
extern int MPI_Cart_create(MPI_Comm, int, int *, int *,
			int, MPI_Comm *);
extern int MPI_Cart_get(MPI_Comm, int, int *, int *, int *);
extern int MPI_Cart_map(MPI_Comm, int, int *, int *, int *);
extern int MPI_Cart_rank(MPI_Comm, int *, int *);
extern int MPI_Cart_shift(MPI_Comm, int, int, int *, int *);
extern int MPI_Cart_sub(MPI_Comm, int *, MPI_Comm *);
extern int MPI_Cartdim_get(MPI_Comm, int *);
extern int MPI_Comm_compare(MPI_Comm, MPI_Comm, int *);
extern int MPI_Comm_create(MPI_Comm, MPI_Group, MPI_Comm *);
extern int MPI_Comm_create_group(MPI_Comm, MPI_Group, int, MPI_Comm *);
extern int MPI_Comm_dup(MPI_Comm, MPI_Comm *);
extern int MPI_Comm_free(MPI_Comm *);
extern int MPI_Comm_group(MPI_Comm, MPI_Group *);
extern int MPI_Comm_rank(MPI_Comm, int *);
extern int MPI_Comm_remote_group(MPI_Comm, MPI_Group *);
extern int MPI_Comm_remote_size(MPI_Comm, int *);
extern int MPI_Comm_size(MPI_Comm, int *);
extern int MPI_Comm_split(MPI_Comm, int, int, MPI_Comm *);
extern int MPI_Comm_split_type(MPI_Comm, int, int, MPI_Info, MPI_Comm *);
extern int MPI_Comm_test_inter(MPI_Comm, int *);
extern int MPI_Comm_dup_with_info(MPI_Comm, MPI_Info, MPI_Comm *);
extern int MPI_Comm_idup(MPI_Comm, MPI_Comm *, MPI_Request *);
extern int MPI_Comm_get_info(MPI_Comm, MPI_Info *);
extern int MPI_Comm_set_info(MPI_Comm, MPI_Info);
extern int MPI_Comm_get_parent(MPI_Comm *);
extern int MPI_Comm_spawn(char *, char **, int, MPI_Info, int,
			MPI_Comm, MPI_Comm *, int *);
extern int MPI_Comm_spawn_multiple(int, char **, char ***, int *,
			MPI_Info *, int, MPI_Comm, MPI_Comm *, int *);
extern int MPI_Comm_accept(char*, MPI_Info, int, MPI_Comm, MPI_Comm *);
extern int MPI_Comm_connect(char*, MPI_Info, int, MPI_Comm, MPI_Comm *);
extern int MPI_Comm_join(int, MPI_Comm *);
extern int MPI_Comm_disconnect(MPI_Comm *);
extern int MPI_Open_port(MPI_Info, char*);
extern int MPI_Close_port(char*);
extern int MPI_Publish_name(char*, MPI_Info, char*);
extern int MPI_Unpublish_name(char*, MPI_Info, char*);
extern int MPI_Lookup_name(char*, MPI_Info, char*);
extern int MPI_Dims_create(int, int, int *);
extern int MPI_Errhandler_create(MPI_Handler_function *,
			MPI_Errhandler *);
extern int MPI_Errhandler_free(MPI_Errhandler *);
extern int MPI_Errhandler_get(MPI_Comm, MPI_Errhandler *);
extern int MPI_Errhandler_set(MPI_Comm, MPI_Errhandler);
extern int MPI_Error_class(int, int *);
extern int MPI_Error_string(int, char *, int *);
extern int MPI_Add_error_class(int *);
extern int MPI_Add_error_code(int, int *);
extern int MPI_Add_error_string(int, char *);
extern int MPI_Finalize(void);
extern int MPI_Finalized(int *);
extern int MPI_Gather(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, int, MPI_Comm);
extern int MPI_Gatherv(void *, int, MPI_Datatype, void *, int *,
			int *, MPI_Datatype, int, MPI_Comm);
extern int MPI_Get_count(MPI_Status *, MPI_Datatype, int *);
extern int MPI_Get_elements(MPI_Status *, MPI_Datatype, int *);
extern int MPI_Get_elements_x(MPI_Status *, MPI_Datatype, MPI_Count *);
extern int MPI_Get_processor_name(char *, int *);
extern int MPI_Get_version(int *, int *);
extern int MPI_Get_library_version(char *, int *);
extern int MPI_Graph_create(MPI_Comm, int, int *, int *,
			int, MPI_Comm *);
extern int MPI_Graph_get(MPI_Comm, int, int, int *, int *);
extern int MPI_Graph_map(MPI_Comm, int, int *, int *, int *);
extern int MPI_Graph_neighbors(MPI_Comm, int, int, int *);
extern int MPI_Graph_neighbors_count(MPI_Comm, int, int *);
extern int MPI_Graphdims_get(MPI_Comm, int *, int *);
extern int MPI_Neighbor_allgather(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm);
extern int MPI_Neighbor_allgatherv(void *, int, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm);
extern int MPI_Neighbor_alltoall(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm);
extern int MPI_Neighbor_alltoallv(void *, int *, int *, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm);
extern int MPI_Neighbor_alltoallw(void *, int *, MPI_Aint *, MPI_Datatype *,
			void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm);
extern int MPI_Dist_graph_create(MPI_Comm, int, int*, int*,
			int*, int*,	MPI_Info, int, MPI_Comm*);
extern int MPI_Dist_graph_create_adjacent(MPI_Comm, int, int*, int*,
			int, int*, int*,	MPI_Info, int, MPI_Comm*);
extern int MPI_Dist_graph_neighbors_count(MPI_Comm, int*, int*, int*);
extern int MPI_Dist_graph_neighbors(MPI_Comm, int, int*, int*,
			int, int*, int*);
extern int MPI_Group_compare(MPI_Group, MPI_Group, int *);
extern int MPI_Group_difference(MPI_Group, MPI_Group, MPI_Group *);
extern int MPI_Group_excl(MPI_Group, int, int *, MPI_Group *);
extern int MPI_Group_free(MPI_Group *);
extern int MPI_Group_incl(MPI_Group, int, int *, MPI_Group *);
extern int MPI_Group_intersection(MPI_Group, MPI_Group, MPI_Group *);
extern int MPI_Group_range_excl(MPI_Group, int, int [][3], MPI_Group *);
extern int MPI_Group_range_incl(MPI_Group, int, int [][3], MPI_Group *);
extern int MPI_Group_rank(MPI_Group, int *);
extern int MPI_Group_size(MPI_Group, int *);
extern int MPI_Group_translate_ranks(MPI_Group, int, int *,
			MPI_Group, int *);
extern int MPI_Group_union(MPI_Group, MPI_Group, MPI_Group *);
extern int MPI_Ibsend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int MPI_Ineighbor_allgather(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int MPI_Ineighbor_allgatherv(void *, int, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int MPI_Ineighbor_alltoall(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int MPI_Ineighbor_alltoallv(void *, int *, int *, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int MPI_Ineighbor_alltoallw(void *, int *, MPI_Aint *, MPI_Datatype *,
			void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Request *);
extern int MPI_Init(int *, char ***);
extern int MPI_Initialized(int *);
extern int MPI_Intercomm_create(MPI_Comm, int, MPI_Comm, int,
			int, MPI_Comm *);
extern int MPI_Intercomm_merge(MPI_Comm, int, MPI_Comm *);
extern int MPI_Iprobe(int, int, MPI_Comm, int *, MPI_Status *);
extern int MPI_Irecv(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int MPI_Irsend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int MPI_Isend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int MPI_Issend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int MPI_Keyval_create(MPI_Copy_function *,
			MPI_Delete_function *, int *, void *);
extern int MPI_Keyval_free(int *);
extern int MPI_Op_create(MPI_User_function *, int, MPI_Op *);
extern int MPI_Op_free(MPI_Op *);
extern int MPI_Op_commutative(MPI_Op, int*);
extern int MPI_Pack(void *, int, MPI_Datatype, void *, int,
			int *, MPI_Comm);
extern int MPI_Pack_external(char *, void *, int, MPI_Datatype, void *,
                        MPI_Aint, MPI_Aint *);
extern int MPI_Pack_size(int, MPI_Datatype, MPI_Comm, int *);
extern int MPI_Pack_external_size(char *, int, MPI_Datatype, MPI_Aint *);
extern int MPI_Pcontrol(const int level, ...);
extern int MPI_Probe(int, int, MPI_Comm, MPI_Status *);
extern int MPI_Mprobe(int, int, MPI_Comm, MPI_Message *, MPI_Status *);
extern int MPI_Improbe(int, int, MPI_Comm, int *, MPI_Message *, MPI_Status *);
extern int MPI_Recv(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Status *);
extern int MPI_Recv_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int MPI_Reduce(void *, void *, int, MPI_Datatype,
			MPI_Op, int, MPI_Comm);
extern int MPI_Reduce_local(void *, void *, int, MPI_Datatype,
			MPI_Op);
extern int MPI_Reduce_scatter(void *, void *, int *,
			MPI_Datatype, MPI_Op, MPI_Comm);
extern int MPI_Reduce_scatter_block(void *, void *, int,
			MPI_Datatype, MPI_Op, MPI_Comm);
extern int MPI_Request_free(MPI_Request *);
extern int MPI_Request_get_status(MPI_Request, int *, MPI_Status *);
extern int MPI_Grequest_start(MPI_Grequest_query_function*,
			MPI_Grequest_free_function*,
			MPI_Grequest_cancel_function*, void*, MPI_Request*);
extern int MPI_Grequest_complete(MPI_Request);
extern int MPIX_Grequest_class_create(MPI_Grequest_query_function *,
			MPI_Grequest_free_function *,
			MPI_Grequest_cancel_function *, MPIX_Grequest_poll_fn *,
			MPIX_Grequest_wait_fn *, MPIX_Grequest_class *);
extern int MPIX_Grequest_class_allocate(MPIX_Grequest_class greq_class,
			void *extra_state, MPI_Request *request);
extern int MPI_Rsend(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int MPI_Rsend_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int MPI_Scan(void *, void *, int, MPI_Datatype,
			MPI_Op, MPI_Comm);
extern int MPI_Exscan(void *, void *, int, MPI_Datatype,
			MPI_Op, MPI_Comm);
extern int MPI_Scatter(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, int, MPI_Comm);
extern int MPI_Scatterv(void *, int *, int *, MPI_Datatype, void *,
			int, MPI_Datatype, int, MPI_Comm);
extern int MPI_Send(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int MPI_Send_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int MPI_Sendrecv(void *, int, MPI_Datatype, int, int,
			void *, int, MPI_Datatype, int, int,
			MPI_Comm, MPI_Status *);
extern int MPI_Sendrecv_replace(void *, int, MPI_Datatype, int, int,
			int, int, MPI_Comm, MPI_Status *);
extern int MPI_Ssend(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int MPI_Ssend_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int MPI_Start(MPI_Request *);
extern int MPI_Startall(int, MPI_Request *);
extern int MPI_Test(MPI_Request *, int *, MPI_Status *);
extern int MPI_Test_cancelled(MPI_Status *, int *);
extern int MPI_Testall(int, MPI_Request *, int *, MPI_Status *);
extern int MPI_Testany(int, MPI_Request *, int *, int *, MPI_Status *);
extern int MPI_Testsome(int, MPI_Request *, int *, int *, MPI_Status *);
extern int MPI_Topo_test(MPI_Comm, int *);
extern int MPI_Type_commit(MPI_Datatype *);
extern int MPI_Type_contiguous(int, MPI_Datatype, MPI_Datatype *);
extern int MPI_Type_extent(MPI_Datatype, MPI_Aint *);
extern int MPI_Type_free(MPI_Datatype *);
extern int MPI_Type_get_contents(MPI_Datatype, int, int, int,
			int [], MPI_Aint [], MPI_Datatype []);
extern int MPI_Type_get_envelope(MPI_Datatype, int *, int *,
			int *, int *);
extern int MPI_Type_get_extent(MPI_Datatype, MPI_Aint *, MPI_Aint *);
extern int MPI_Type_get_extent_x(MPI_Datatype, MPI_Count *, MPI_Count *);
extern int MPI_Type_get_true_extent(MPI_Datatype, MPI_Aint *,
			MPI_Aint *);
extern int MPI_Type_get_true_extent_x(MPI_Datatype, MPI_Count *,
			MPI_Count *);
extern int MPI_Type_hindexed(int, int *, MPI_Aint *,
			MPI_Datatype, MPI_Datatype *);
extern int MPI_Type_hvector(int, int, MPI_Aint, MPI_Datatype,
			MPI_Datatype *);
extern int MPI_Type_indexed(int, int *, int *, MPI_Datatype,
			MPI_Datatype *);
extern int MPI_Type_lb(MPI_Datatype, MPI_Aint *);
extern int MPI_Type_size(MPI_Datatype, int *);
extern int MPI_Type_size_x(MPI_Datatype, MPI_Count *);
extern int MPI_Type_struct(int, int *, MPI_Aint *,
			MPI_Datatype *, MPI_Datatype *);
extern int MPI_Type_ub(MPI_Datatype, MPI_Aint *);
extern int MPI_Type_vector(int, int, int, MPI_Datatype,
			MPI_Datatype *);
extern int MPI_Unpack(void *, int, int *, void *, int,
			MPI_Datatype, MPI_Comm);
extern int MPI_Unpack_external(char *, void *, MPI_Aint, MPI_Aint *,
                        void *, int, MPI_Datatype);
extern int MPI_Wait(MPI_Request *, MPI_Status *);
extern int MPI_Waitall(int, MPI_Request *, MPI_Status *);
extern int MPI_Waitany(int, MPI_Request *, int *, MPI_Status *);
extern int MPI_Waitsome(int, MPI_Request *, int *, int *, MPI_Status *);
extern double MPI_Wtick(void);
extern double MPI_Wtime(void);
extern int MPI_Mrecv(void *, int, MPI_Datatype,
			MPI_Message *, MPI_Status *);
extern int MPI_Imrecv(void *, int, MPI_Datatype,
			MPI_Message *, MPI_Request *);

extern int MPI_DUP_FN(MPI_Comm, int, void *, void *, void *, int*);
extern int MPI_COMM_DUP_FN(MPI_Comm, int, void *, void *, void *, int*);
extern int MPI_TYPE_DUP_FN(MPI_Datatype, int, void *, void *, void *, int*);
extern int MPI_WIN_DUP_FN(MPI_Win, int, void *, void *, void *, int*);

extern MPI_Comm MPI_Comm_f2c(MPI_Fint);
extern MPI_Datatype MPI_Type_f2c(MPI_Fint);
extern MPI_Group MPI_Group_f2c(MPI_Fint);
extern MPI_Op MPI_Op_f2c(MPI_Fint);
extern MPI_Request MPI_Request_f2c(MPI_Fint);
extern MPI_Win MPI_Win_f2c(MPI_Fint);
extern MPI_Info MPI_Info_f2c(MPI_Fint);
extern MPI_Errhandler MPI_Errhandler_f2c(MPI_Fint);

extern MPI_Fint MPI_Comm_c2f(MPI_Comm);
extern MPI_Fint MPI_Type_c2f(MPI_Datatype);
extern MPI_Fint MPI_Group_c2f(MPI_Group);
extern MPI_Fint MPI_Op_c2f(MPI_Op);
extern MPI_Fint MPI_Request_c2f(MPI_Request);
extern MPI_Fint MPI_Win_c2f(MPI_Win);
extern MPI_Fint MPI_Info_c2f(MPI_Info);
extern MPI_Fint MPI_Errhandler_c2f(MPI_Errhandler);

extern int MPI_Status_f2c(void *, MPI_Status *);
extern int MPI_Status_c2f(MPI_Status *, void *);
extern int MPI_Status_set_cancelled(MPI_Status *, int);
extern int MPI_Status_set_elements(MPI_Status *, MPI_Datatype, int);
extern int MPI_Status_set_elements_x(MPI_Status *, MPI_Datatype, MPI_Count);

extern int MPI_Info_create(MPI_Info *);
extern int MPI_Info_delete(MPI_Info, const char *);
extern int MPI_Info_dup(MPI_Info, MPI_Info *);
extern int MPI_Info_free(MPI_Info *);
extern int MPI_Info_get(MPI_Info, const char *, int, char *, int *);
extern int MPI_Info_get_nkeys(MPI_Info, int *);
extern int MPI_Info_get_nthkey(MPI_Info, int, char *);
extern int MPI_Info_get_valuelen(MPI_Info, const char *, int *, int *);
extern int MPI_Info_set(MPI_Info, const char *, const char *);

extern int MPI_Win_create(void *, MPI_Aint, int,
			MPI_Info, MPI_Comm, MPI_Win *);
extern int MPI_Win_allocate(MPI_Aint, int, MPI_Info,
			MPI_Comm, void *, MPI_Win *);
extern int MPI_Win_allocate_shared(MPI_Aint, int, MPI_Info,
			MPI_Comm, void *, MPI_Win *);
extern int MPI_Win_fence(int, MPI_Win);
extern int MPI_Win_free(MPI_Win *);
extern int MPI_Win_get_group(MPI_Win, MPI_Group *);
extern int MPI_Win_attach(MPI_Win, void *, MPI_Aint);
extern int MPI_Win_detach(MPI_Win, void *);
extern int MPI_Win_create_dynamic(MPI_Info, MPI_Comm, MPI_Win *);
extern int MPI_Win_flush(int, MPI_Win);
extern int MPI_Win_flush_all(MPI_Win);
extern int MPI_Win_flush_local(int, MPI_Win);
extern int MPI_Win_flush_local_all(MPI_Win);
extern int MPI_Win_get_info(MPI_Win, MPI_Info *);
extern int MPI_Win_set_info(MPI_Win, MPI_Info);
extern int MPI_Win_sync(MPI_Win);
extern int MPI_Win_lock(int, int, int, MPI_Win);
extern int MPI_Win_unlock(int, MPI_Win);
extern int MPI_Win_lock_all(int, MPI_Win);
extern int MPI_Win_unlock_all(MPI_Win);
extern int MPI_Win_shared_query(MPI_Win, int, MPI_Aint *, int *, void *);
extern int MPI_Win_start(MPI_Group, int, MPI_Win);
extern int MPI_Win_post(MPI_Group, int, MPI_Win);
extern int MPI_Win_complete(MPI_Win);
extern int MPI_Win_wait(MPI_Win);
extern int MPI_Win_test(MPI_Win, int *);
extern int MPI_Win_create_errhandler(MPI_Win_errhandler_function *,
			MPI_Errhandler *);
extern int MPI_Win_set_errhandler(MPI_Win, MPI_Errhandler);
extern int MPI_Win_get_errhandler(MPI_Win, MPI_Errhandler *);
extern int MPI_Win_call_errhandler(MPI_Win, int);
extern int MPI_Win_create_keyval(MPI_Win_copy_attr_function *,
			MPI_Win_delete_attr_function *, int *, void *);
extern int MPI_Win_free_keyval(int *);
extern int MPI_Win_set_attr(MPI_Win, int, void *);
extern int MPI_Win_get_attr(MPI_Win, int, void *, int *);
extern int MPI_Win_delete_attr(MPI_Win, int);
extern int MPI_Get(void *, int, MPI_Datatype, int, MPI_Aint,
			int, MPI_Datatype, MPI_Win);
extern int MPI_Put(void *, int, MPI_Datatype, int, MPI_Aint,
			int, MPI_Datatype, MPI_Win);
extern int MPI_Accumulate(void *, int, MPI_Datatype, int, MPI_Aint,
			int, MPI_Datatype, MPI_Op, MPI_Win);

extern int MPI_Compare_and_swap(void *, void *, void *,
			MPI_Datatype, int, MPI_Aint, MPI_Win);
extern int MPI_Fetch_and_op(void *, void *, MPI_Datatype,
			int, MPI_Aint, MPI_Op, MPI_Win);
extern int MPI_Get_accumulate(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype,
			MPI_Op, MPI_Win);
extern int MPI_Raccumulate(void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype,
			MPI_Op, MPI_Win, MPI_Request *);
extern int MPI_Rget_accumulate(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype,
			MPI_Op, MPI_Win, MPI_Request *);
extern int MPI_Rget(void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype, MPI_Win,
			MPI_Request *);
extern int MPI_Rput(void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype, MPI_Win,
			MPI_Request *);

extern int MPI_Alloc_mem(MPI_Aint, MPI_Info, void *);
extern int MPI_Free_mem(void *);

extern int MPI_Is_thread_main(int *flag);
extern int MPI_Init_thread(int *, char ***, int , int *);
extern int MPI_Query_thread(int *);

extern int MPI_Comm_set_name(MPI_Comm, char *);
extern int MPI_Comm_get_name(MPI_Comm, char *, int *);
extern int MPI_Type_set_name(MPI_Datatype, char *);
extern int MPI_Type_get_name(MPI_Datatype, char *, int *);
extern int MPI_Win_set_name(MPI_Win, char *);
extern int MPI_Win_get_name(MPI_Win, char *, int *);

extern int MPI_Comm_delete_attr(MPI_Comm, int);
extern int MPI_Comm_set_attr(MPI_Comm, int, void *);
extern int MPI_Comm_get_attr(MPI_Comm, int, void *, int *);
extern int MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *,
			MPI_Errhandler *);
extern int MPI_Comm_get_errhandler(MPI_Comm, MPI_Errhandler *);
extern int MPI_Comm_set_errhandler(MPI_Comm, MPI_Errhandler);
extern int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *,
			MPI_Comm_delete_attr_function *, int *, void *);
extern int MPI_Comm_free_keyval(int *);
extern int MPI_Comm_call_errhandler(MPI_Comm, int);
extern int MPI_Get_address(void *, MPI_Aint *);
extern int MPI_Type_create_indexed_block(int, int, int *,
			MPI_Datatype, MPI_Datatype *);
extern int MPI_Type_create_hindexed(int, int *, MPI_Aint *,
			MPI_Datatype, MPI_Datatype *);
extern int MPI_Type_create_hvector(int, int, MPI_Aint,
			MPI_Datatype, MPI_Datatype *);
extern int MPI_Type_create_struct(int, int *, MPI_Aint *,
			MPI_Datatype *, MPI_Datatype *);
extern int MPI_Type_dup(MPI_Datatype, MPI_Datatype *);
extern int MPI_Type_create_resized(MPI_Datatype, MPI_Aint, MPI_Aint,
			MPI_Datatype *);
extern int MPI_Type_create_keyval(MPI_Type_copy_attr_function *,
			MPI_Type_delete_attr_function *, int*, void*);
extern int MPI_Type_free_keyval(int *);
extern int MPI_Type_set_attr(MPI_Datatype, int, void *);
extern int MPI_Type_get_attr(MPI_Datatype, int, void *, int *);
extern int MPI_Type_delete_attr(MPI_Datatype, int);
extern int MPI_Type_create_f90_real(int, int, MPI_Datatype *);
extern int MPI_Type_create_f90_complex(int, int, MPI_Datatype *);
extern int MPI_Type_create_f90_integer(int, MPI_Datatype *);
extern int MPI_Type_match_size(int, int, MPI_Datatype *);

/*
 * HA features
 */
extern int MPIHA_Comm_failure_ack(MPI_Comm);
extern int MPIHA_Comm_failure_get_acked(MPI_Comm, MPI_Group*);
extern int MPIHA_Comm_revoke(MPI_Comm);
extern int MPIHA_Comm_shrink(MPI_Comm, MPI_Comm*);
extern int MPIHA_Comm_agree(MPI_Comm, int*);
extern int MPIHA_Comm_iagree(MPI_Comm, int*, MPI_Request *);

/*
 * HP MPI extensions
 */
extern int MPIHP_Comm_id(MPI_Comm, int *);
extern int MPIHP_Type_id(MPI_Datatype, int *);
extern int MPIHP_Trace_on(void);
extern int MPIHP_Trace_off(void);

extern int MPI_Ibcast(void *, int, MPI_Datatype, int,
		    MPI_Comm, MPI_Request *);
extern int MPI_Ibarrier(MPI_Comm, MPI_Request *);
extern int MPI_Igather(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int MPI_Igatherv(void *, int, MPI_Datatype, void *,
		    int *, int *, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int MPI_Iscatter(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int MPI_Iscatterv(void *, int *, int *, MPI_Datatype, void *,
		    int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int MPI_Iallgather(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int MPI_Iallgatherv(void *, int, MPI_Datatype, void *,
		    int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int MPI_Ialltoall(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int MPI_Ialltoallv(void *, int *, int *, MPI_Datatype, void *,
		    int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int MPI_Ialltoallw(void *, int *, int *, MPI_Datatype *, void *, int *,
		    int *, MPI_Datatype *, MPI_Comm, MPI_Request *);
extern int MPI_Ireduce(void *, void *, int, MPI_Datatype, MPI_Op,
		    int, MPI_Comm, MPI_Request *);
extern int MPI_Iallreduce(void *, void *, int, MPI_Datatype, MPI_Op,
		    MPI_Comm, MPI_Request *);
extern int MPI_Ireduce_scatter(void *, void *, int *,
		    MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);
extern int MPI_Ireduce_scatter_block(void *, void *, int,
		    MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);
extern int MPI_Iscan(void *, void *, int, MPI_Datatype, MPI_Op,
		    MPI_Comm, MPI_Request *);
extern int MPI_Iexscan(void *, void *, int, MPI_Datatype, MPI_Op,
		    MPI_Comm, MPI_Request *);

#endif /* !MPI_hpux */

#if !defined(MPI_hpux) || defined(HPMP_BUILD_DLIB) || defined(HPMP_BUILD_CXXBINDING)
/*
 * Profiling prototypes, for both users and internal building.
 */
extern int PMPI_Abort(MPI_Comm, int);
extern int PMPI_Address(void *, MPI_Aint *);
extern int PMPI_Allgather(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, MPI_Comm);
extern int PMPI_Allgatherv(void *, int, MPI_Datatype, void *,
			int *, int *, MPI_Datatype, MPI_Comm);
extern int PMPI_Allreduce(void *, void *, int, MPI_Datatype,
			MPI_Op, MPI_Comm);
extern int PMPI_Alltoall(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, MPI_Comm);
extern int PMPI_Alltoallv(void *, int *, int *, MPI_Datatype, void *,
			int *, int *, MPI_Datatype, MPI_Comm);
extern int PMPI_Alltoallw(void *, int *, int *, MPI_Datatype*, void *,
			int *, int *, MPI_Datatype*, MPI_Comm);
extern int PMPI_Attr_delete(MPI_Comm, int);
extern int PMPI_Attr_get(MPI_Comm, int, void *, int *);
extern int PMPI_Attr_put(MPI_Comm, int, void *);
extern int PMPI_Barrier(MPI_Comm);
extern int PMPI_Bcast(void *, int, MPI_Datatype, int, MPI_Comm);
extern int PMPI_Bsend(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int PMPI_Bsend_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int PMPI_Buffer_attach(void *, int);
extern int PMPI_Buffer_detach(void *, int *);
extern int PMPI_Cancel(MPI_Request *);
extern int PMPI_Cart_coords(MPI_Comm, int, int, int *);
extern int PMPI_Cart_create(MPI_Comm, int, int *, int *,
			int, MPI_Comm *);
extern int PMPI_Cart_get(MPI_Comm, int, int *, int *, int *);
extern int PMPI_Cart_map(MPI_Comm, int, int *, int *, int *);
extern int PMPI_Cart_rank(MPI_Comm, int *, int *);
extern int PMPI_Cart_shift(MPI_Comm, int, int, int *, int *);
extern int PMPI_Cart_sub(MPI_Comm, int *, MPI_Comm *);
extern int PMPI_Cartdim_get(MPI_Comm, int *);
extern int PMPI_Comm_compare(MPI_Comm, MPI_Comm, int *);
extern int PMPI_Comm_create(MPI_Comm, MPI_Group, MPI_Comm *);
extern int PMPI_Comm_create_group(MPI_Comm, MPI_Group, int, MPI_Comm *);
extern int PMPI_Comm_dup(MPI_Comm, MPI_Comm *);
extern int PMPI_Comm_free(MPI_Comm *);
extern int PMPI_Comm_group(MPI_Comm, MPI_Group *);
extern int PMPI_Comm_rank(MPI_Comm, int *);
extern int PMPI_Comm_remote_group(MPI_Comm, MPI_Group *);
extern int PMPI_Comm_remote_size(MPI_Comm, int *);
extern int PMPI_Comm_size(MPI_Comm, int *);
extern int PMPI_Comm_split(MPI_Comm, int, int, MPI_Comm *);
extern int PMPI_Comm_split_type(MPI_Comm, int, int, MPI_Info, MPI_Comm *);
extern int PMPI_Comm_test_inter(MPI_Comm, int *);
extern int PMPI_Comm_dup_with_info(MPI_Comm, MPI_Info, MPI_Comm *);
extern int PMPI_Comm_idup(MPI_Comm, MPI_Comm *, MPI_Request *);
extern int PMPI_Comm_get_info(MPI_Comm, MPI_Info *);
extern int PMPI_Comm_set_info(MPI_Comm, MPI_Info);
extern int PMPI_Comm_get_parent(MPI_Comm *);
extern int PMPI_Comm_spawn(char *, char **, int, MPI_Info, int,
			MPI_Comm, MPI_Comm *, int *);
extern int PMPI_Comm_spawn_multiple(int, char **, char ***, int *,
			MPI_Info *, int, MPI_Comm, MPI_Comm *, int *);
extern int PMPI_Comm_accept(char*, MPI_Info, int, MPI_Comm, MPI_Comm *);
extern int PMPI_Comm_connect(char*, MPI_Info, int, MPI_Comm, MPI_Comm *);
extern int PMPI_Comm_join(int, MPI_Comm *);
extern int PMPI_Comm_disconnect(MPI_Comm *);
extern int PMPI_Open_port(MPI_Info, char*);
extern int PMPI_Close_port(char*);
extern int PMPI_Publish_name(char*, MPI_Info, char*);
extern int PMPI_Unpublish_name(char*, MPI_Info, char*);
extern int PMPI_Lookup_name(char*, MPI_Info, char*);
extern int PMPI_Dims_create(int, int, int *);
extern int PMPI_Errhandler_create(MPI_Handler_function *,
			MPI_Errhandler *);
extern int PMPI_Errhandler_free(MPI_Errhandler *);
extern int PMPI_Errhandler_get(MPI_Comm, MPI_Errhandler *);
extern int PMPI_Errhandler_set(MPI_Comm, MPI_Errhandler);
extern int PMPI_Error_class(int, int *);
extern int PMPI_Error_string(int, char *, int *);
extern int PMPI_Add_error_class(int *);
extern int PMPI_Add_error_code(int, int *);
extern int PMPI_Add_error_string(int, char *);
extern int PMPI_Finalize(void);
extern int PMPI_Finalized(int *);
extern int PMPI_Gather(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, int, MPI_Comm);
extern int PMPI_Gatherv(void *, int, MPI_Datatype, void *,
			int *, int *, MPI_Datatype, int, MPI_Comm);
extern int PMPI_Get_count(MPI_Status *, MPI_Datatype, int *);
extern int PMPI_Get_elements(MPI_Status *, MPI_Datatype, int *);
extern int PMPI_Get_elements_x(MPI_Status *, MPI_Datatype, MPI_Count *);
extern int PMPI_Get_processor_name(char *, int *);
extern int PMPI_Get_version(int *, int *);
extern int PMPI_Get_library_version(char *, int *);
extern int PMPI_Graph_create(MPI_Comm, int, int *, int *,
			int, MPI_Comm *);
extern int PMPI_Graph_get(MPI_Comm, int, int, int *, int *);
extern int PMPI_Graph_map(MPI_Comm, int, int *, int *, int *);
extern int PMPI_Graph_neighbors(MPI_Comm, int, int, int *);
extern int PMPI_Graph_neighbors_count(MPI_Comm, int, int *);
extern int PMPI_Graphdims_get(MPI_Comm, int *, int *);
extern int PMPI_Neighbor_allgather(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm);
extern int PMPI_Neighbor_allgatherv(void *, int, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm);
extern int PMPI_Neighbor_alltoall(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm);
extern int PMPI_Neighbor_alltoallv(void *, int *, int *, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm);
extern int PMPI_Neighbor_alltoallw(void *, int *, MPI_Aint *, MPI_Datatype *,
			void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm);
extern int PMPI_Dist_graph_create(MPI_Comm, int, int*, int*,
			int*, int*,	MPI_Info, int, MPI_Comm*);
extern int PMPI_Dist_graph_create_adjacent(MPI_Comm, int, int*, int*,
			int, int*, int*,	MPI_Info, int, MPI_Comm*);
extern int PMPI_Dist_graph_neighbors_count(MPI_Comm, int*, int*, int*);
extern int PMPI_Dist_graph_neighbors(MPI_Comm, int, int*, int*,
			int, int*, int*);
extern int PMPI_Group_compare(MPI_Group, MPI_Group, int *);
extern int PMPI_Group_difference(MPI_Group, MPI_Group, MPI_Group *);
extern int PMPI_Group_excl(MPI_Group, int, int *, MPI_Group *);
extern int PMPI_Group_free(MPI_Group *);
extern int PMPI_Group_incl(MPI_Group, int, int *, MPI_Group *);
extern int PMPI_Group_intersection(MPI_Group, MPI_Group, MPI_Group *);
extern int PMPI_Group_range_excl(MPI_Group, int, int [][3], MPI_Group *);
extern int PMPI_Group_range_incl(MPI_Group, int, int [][3], MPI_Group *);
extern int PMPI_Group_rank(MPI_Group, int *);
extern int PMPI_Group_size(MPI_Group, int *);
extern int PMPI_Group_translate_ranks(MPI_Group, int, int *,
			MPI_Group, int *);
extern int PMPI_Group_union(MPI_Group, MPI_Group, MPI_Group *);
extern int PMPI_Ibsend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int PMPI_Ineighbor_allgather(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int PMPI_Ineighbor_allgatherv(void *, int, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int PMPI_Ineighbor_alltoall(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int PMPI_Ineighbor_alltoallv(void *, int *, int *, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int PMPI_Ineighbor_alltoallw(void *, int *, MPI_Aint *, MPI_Datatype *,
			void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Request *);
extern int PMPI_Init(int *, char ***);
extern int PMPI_Initialized(int *);
extern int PMPI_Intercomm_create(MPI_Comm, int, MPI_Comm, int,
			int, MPI_Comm *);
extern int PMPI_Intercomm_merge(MPI_Comm, int, MPI_Comm *);
extern int PMPI_Iprobe(int, int, MPI_Comm, int *, MPI_Status *);
extern int PMPI_Irecv(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int PMPI_Irsend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int PMPI_Isend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int PMPI_Issend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int PMPI_Keyval_create(MPI_Copy_function *,
			MPI_Delete_function *, int *, void *);
extern int PMPI_Keyval_free(int *);
extern int PMPI_Op_create(MPI_User_function *, int, MPI_Op *);
extern int PMPI_Op_free(MPI_Op *);
extern int PMPI_Op_commutative(MPI_Op, int*);
extern int PMPI_Pack(void *, int, MPI_Datatype, void *, int,
			int *, MPI_Comm);
extern int PMPI_Pack_external(char *, void *, int, MPI_Datatype, void *,
                        MPI_Aint, MPI_Aint *);
extern int PMPI_Pack_size(int, MPI_Datatype, MPI_Comm, int *);
extern int PMPI_Pack_external_size(char *, int, MPI_Datatype, MPI_Aint *);
extern int PMPI_Pcontrol(const int level, ...);
extern int PMPI_Probe(int, int, MPI_Comm, MPI_Status *);
extern int PMPI_Mprobe(int, int, MPI_Comm, MPI_Message *, MPI_Status *);
extern int PMPI_Improbe(int, int, MPI_Comm, int *, MPI_Message *, MPI_Status *);
extern int PMPI_Recv(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Status *);
extern int PMPI_Recv_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int PMPI_Reduce(void *, void *, int, MPI_Datatype,
			MPI_Op, int, MPI_Comm);
extern int PMPI_Reduce_local(void *, void *, int, MPI_Datatype,
			MPI_Op);
extern int PMPI_Reduce_scatter(void *, void *, int *,
			MPI_Datatype, MPI_Op, MPI_Comm);
extern int PMPI_Reduce_scatter_block(void *, void *, int,
			MPI_Datatype, MPI_Op, MPI_Comm);
extern int PMPI_Request_free(MPI_Request *);
extern int PMPI_Request_get_status(MPI_Request, int *, MPI_Status *);
extern int PMPI_Grequest_start(MPI_Grequest_query_function*,
			MPI_Grequest_free_function*,
			MPI_Grequest_cancel_function*, void*, MPI_Request*);
extern int PMPI_Grequest_complete(MPI_Request);
extern int PMPIX_Grequest_class_create(MPI_Grequest_query_function *,
			MPI_Grequest_free_function *,
			MPI_Grequest_cancel_function *, MPIX_Grequest_poll_fn *,
			MPIX_Grequest_wait_fn *, MPIX_Grequest_class *);
extern int PMPIX_Grequest_class_allocate(MPIX_Grequest_class greq_class,
			void *extra_state, MPI_Request *request);
extern int PMPI_Rsend(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int PMPI_Rsend_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int PMPI_Scan(void *, void *, int, MPI_Datatype,
			MPI_Op, MPI_Comm);
extern int PMPI_Exscan(void *, void *, int, MPI_Datatype,
			MPI_Op, MPI_Comm);
extern int PMPI_Scatter(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, int, MPI_Comm);
extern int PMPI_Scatterv(void *, int *, int *, MPI_Datatype, void *,
			int, MPI_Datatype, int, MPI_Comm);
extern int PMPI_Send(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int PMPI_Send_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int PMPI_Sendrecv(void *, int, MPI_Datatype, int, int,
			void *, int, MPI_Datatype, int, int,
			MPI_Comm, MPI_Status *);
extern int PMPI_Sendrecv_replace(void *, int, MPI_Datatype, int, int,
			int, int, MPI_Comm, MPI_Status *);
extern int PMPI_Ssend(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int PMPI_Ssend_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int PMPI_Start(MPI_Request *);
extern int PMPI_Startall(int, MPI_Request *);
extern int PMPI_Test(MPI_Request *, int *, MPI_Status *);
extern int PMPI_Test_cancelled(MPI_Status *, int *);
extern int PMPI_Testall(int, MPI_Request *, int *, MPI_Status *);
extern int PMPI_Testany(int, MPI_Request *, int *, int *, MPI_Status *);
extern int PMPI_Testsome(int, MPI_Request *, int *, int *, MPI_Status *);
extern int PMPI_Topo_test(MPI_Comm, int *);
extern int PMPI_Type_commit(MPI_Datatype *);
extern int PMPI_Type_contiguous(int, MPI_Datatype, MPI_Datatype *);
extern int PMPI_Type_extent(MPI_Datatype, MPI_Aint *);
extern int PMPI_Type_free(MPI_Datatype *);
extern int PMPI_Type_get_contents(MPI_Datatype, int, int, int,
			int [], MPI_Aint [], MPI_Datatype []);
extern int PMPI_Type_get_envelope(MPI_Datatype, int *, int *,
			int *, int *);
extern int PMPI_Type_get_extent(MPI_Datatype, MPI_Aint *, MPI_Aint *);
extern int PMPI_Type_get_extent_x(MPI_Datatype, MPI_Count *, MPI_Count *);
extern int PMPI_Type_get_true_extent(MPI_Datatype, MPI_Aint *,
			MPI_Aint *);
extern int PMPI_Type_get_true_extent_x(MPI_Datatype, MPI_Count *,
			MPI_Count *);
extern int PMPI_Type_hindexed(int, int *, MPI_Aint *,
			MPI_Datatype, MPI_Datatype *);
extern int PMPI_Type_hvector(int, int, MPI_Aint, MPI_Datatype,
			MPI_Datatype *);
extern int PMPI_Type_indexed(int, int *, int *, MPI_Datatype,
			MPI_Datatype *);
extern int PMPI_Type_lb(MPI_Datatype, MPI_Aint *);
extern int PMPI_Type_size(MPI_Datatype, int *);
extern int PMPI_Type_size_x(MPI_Datatype, MPI_Count *);
extern int PMPI_Type_struct(int, int *, MPI_Aint *,
			MPI_Datatype *, MPI_Datatype *);
extern int PMPI_Type_ub(MPI_Datatype, MPI_Aint *);
extern int PMPI_Type_vector(int, int, int, MPI_Datatype,
			MPI_Datatype *);
extern int PMPI_Unpack(void *, int, int *, void *, int,
			MPI_Datatype, MPI_Comm);
extern int PMPI_Unpack_external(char *, void *, MPI_Aint, MPI_Aint *,
                        void *, int, MPI_Datatype);
extern int PMPI_Wait(MPI_Request *, MPI_Status *);
extern int PMPI_Waitall(int, MPI_Request *, MPI_Status *);
extern int PMPI_Waitany(int, MPI_Request *, int *, MPI_Status *);
extern int PMPI_Waitsome(int, MPI_Request *, int *, int *, MPI_Status *);
extern double PMPI_Wtick(void);
extern double PMPI_Wtime(void);
extern int PMPI_Mrecv(void *, int, MPI_Datatype,
			MPI_Message *, MPI_Status *);
extern int PMPI_Imrecv(void *, int, MPI_Datatype,
			MPI_Message *, MPI_Request *);
extern int PMPIHA_Comm_failure_ack(MPI_Comm);
extern int PMPIHA_Comm_failure_get_acked(MPI_Comm, MPI_Group*);
extern int PMPIHA_Comm_revoke(MPI_Comm);
extern int PMPIHA_Comm_shrink(MPI_Comm, MPI_Comm*);
extern int PMPIHA_Comm_agree(MPI_Comm, int*);
extern int PMPIHA_Comm_iagree(MPI_Comm, int*, MPI_Request *);

extern MPI_Comm PMPI_Comm_f2c(MPI_Fint);
extern MPI_Datatype PMPI_Type_f2c(MPI_Fint);
extern MPI_Group PMPI_Group_f2c(MPI_Fint);
extern MPI_Op PMPI_Op_f2c(MPI_Fint);
extern MPI_Request PMPI_Request_f2c(MPI_Fint);
extern MPI_Win PMPI_Win_f2c(MPI_Fint);
extern MPI_Info PMPI_Info_f2c(MPI_Fint);
extern MPI_Errhandler PMPI_Errhandler_f2c(MPI_Fint);

extern MPI_Fint PMPI_Comm_c2f(MPI_Comm);
extern MPI_Fint PMPI_Type_c2f(MPI_Datatype);
extern MPI_Fint PMPI_Group_c2f(MPI_Group);
extern MPI_Fint PMPI_Op_c2f(MPI_Op);
extern MPI_Fint PMPI_Request_c2f(MPI_Request);
extern MPI_Fint PMPI_Win_c2f(MPI_Win);
extern MPI_Fint PMPI_Info_c2f(MPI_Info);
extern MPI_Fint PMPI_Errhandler_c2f(MPI_Errhandler);

extern int PMPI_Status_f2c(void *, MPI_Status *);
extern int PMPI_Status_c2f(MPI_Status *, void *);
extern int PMPI_Status_set_cancelled(MPI_Status *, int);
extern int PMPI_Status_set_elements(MPI_Status *, MPI_Datatype, int);
extern int PMPI_Status_set_elements_x(MPI_Status *, MPI_Datatype, MPI_Count);

extern int PMPI_Info_create(MPI_Info *);
extern int PMPI_Info_delete(MPI_Info, const char *);
extern int PMPI_Info_dup(MPI_Info, MPI_Info *);
extern int PMPI_Info_free(MPI_Info *);
extern int PMPI_Info_get(MPI_Info, const char *, int, char *, int *);
extern int PMPI_Info_get_nkeys(MPI_Info, int *);
extern int PMPI_Info_get_nthkey(MPI_Info, int, char *);
extern int PMPI_Info_get_valuelen(MPI_Info, const char *, int *, int *);
extern int PMPI_Info_set(MPI_Info, const char *, const char *);

extern int PMPI_Win_create(void *, MPI_Aint, int,
			MPI_Info, MPI_Comm, MPI_Win *);
extern int PMPI_Win_allocate(MPI_Aint, int, MPI_Info,
			MPI_Comm, void *, MPI_Win *);
extern int PMPI_Win_allocate_shared(MPI_Aint, int, MPI_Info,
			MPI_Comm, void *, MPI_Win *);
extern int PMPI_Win_fence(int, MPI_Win);
extern int PMPI_Win_free(MPI_Win *);
extern int PMPI_Win_get_group(MPI_Win, MPI_Group *);
extern int PMPI_Win_attach(MPI_Win, void *, MPI_Aint);
extern int PMPI_Win_detach(MPI_Win, void *);
extern int PMPI_Win_create_dynamic(MPI_Info, MPI_Comm, MPI_Win *);
extern int PMPI_Win_flush(int, MPI_Win);
extern int PMPI_Win_flush_all(MPI_Win);
extern int PMPI_Win_flush_local(int, MPI_Win);
extern int PMPI_Win_flush_local_all(MPI_Win);
extern int PMPI_Win_get_info(MPI_Win, MPI_Info *);
extern int PMPI_Win_set_info(MPI_Win, MPI_Info);
extern int PMPI_Win_sync(MPI_Win);
extern int PMPI_Win_lock(int, int, int, MPI_Win);
extern int PMPI_Win_unlock(int, MPI_Win);
extern int PMPI_Win_lock_all(int, MPI_Win);
extern int PMPI_Win_unlock_all(MPI_Win);
extern int PMPI_Win_shared_query(MPI_Win, int, MPI_Aint *, int *, void *);
extern int PMPI_Win_start(MPI_Group, int, MPI_Win);
extern int PMPI_Win_post(MPI_Group, int, MPI_Win);
extern int PMPI_Win_complete(MPI_Win);
extern int PMPI_Win_wait(MPI_Win);
extern int PMPI_Win_test(MPI_Win, int *);
extern int PMPI_Win_create_errhandler(MPI_Win_errhandler_function *,
			MPI_Errhandler *);
extern int PMPI_Win_set_errhandler(MPI_Win, MPI_Errhandler);
extern int PMPI_Win_get_errhandler(MPI_Win, MPI_Errhandler *);
extern int PMPI_Win_call_errhandler(MPI_Win, int);
extern int PMPI_Win_create_keyval(MPI_Win_copy_attr_function *,
			MPI_Win_delete_attr_function *, int *, void *);
extern int PMPI_Win_free_keyval(int *);
extern int PMPI_Win_set_attr(MPI_Win, int, void *);
extern int PMPI_Win_get_attr(MPI_Win, int, void *, int *);
extern int PMPI_Win_delete_attr(MPI_Win, int);
extern int PMPI_Get(void *, int, MPI_Datatype, int, MPI_Aint,
			int, MPI_Datatype, MPI_Win);
extern int PMPI_Put(void *, int, MPI_Datatype, int, MPI_Aint,
			int, MPI_Datatype, MPI_Win);
extern int PMPI_Accumulate(void *, int, MPI_Datatype, int, MPI_Aint,
			int, MPI_Datatype, MPI_Op, MPI_Win);

extern int PMPI_Compare_and_swap(void *, void *, void *,
			MPI_Datatype, int, MPI_Aint, MPI_Win);
extern int PMPI_Fetch_and_op(void *, void *, MPI_Datatype,
			int, MPI_Aint, MPI_Op, MPI_Win);
extern int PMPI_Get_accumulate(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype,
			MPI_Op, MPI_Win);
extern int PMPI_Raccumulate(void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype,
			MPI_Op, MPI_Win, MPI_Request *);
extern int PMPI_Rget_accumulate(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype,
			MPI_Op, MPI_Win, MPI_Request *);
extern int PMPI_Rget(void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype, MPI_Win,
			MPI_Request *);
extern int PMPI_Rput(void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype, MPI_Win,
			MPI_Request *);

extern int PMPI_Alloc_mem(MPI_Aint, MPI_Info, void *);
extern int PMPI_Free_mem(void *);

extern int PMPI_Is_thread_main(int *flag);
extern int PMPI_Init_thread(int *, char ***, int , int *);
extern int PMPI_Query_thread(int *);

extern int PMPI_Comm_set_name(MPI_Comm, char *);
extern int PMPI_Comm_get_name(MPI_Comm, char *, int *);
extern int PMPI_Type_set_name(MPI_Datatype, char *);
extern int PMPI_Type_get_name(MPI_Datatype, char *, int *);
extern int PMPI_Win_set_name(MPI_Win, char *);
extern int PMPI_Win_get_name(MPI_Win, char *, int *);

extern int PMPI_Comm_delete_attr(MPI_Comm, int);
extern int PMPI_Comm_set_attr(MPI_Comm, int, void *);
extern int PMPI_Comm_get_attr(MPI_Comm, int, void *, int *);
extern int PMPI_Comm_create_errhandler(MPI_Comm_errhandler_function *,
			MPI_Errhandler *);
extern int PMPI_Comm_get_errhandler(MPI_Comm, MPI_Errhandler *);
extern int PMPI_Comm_set_errhandler(MPI_Comm, MPI_Errhandler);
extern int PMPI_Comm_create_keyval(MPI_Comm_copy_attr_function *,
			MPI_Comm_delete_attr_function *, int *, void *);
extern int PMPI_Comm_free_keyval(int *);
extern int PMPI_Comm_call_errhandler(MPI_Comm, int);
extern int PMPI_Get_address(void *, MPI_Aint *);
extern int PMPI_Type_create_indexed_block(int, int, int *,
			MPI_Datatype, MPI_Datatype *);
extern int PMPI_Type_create_hindexed(int, int *, MPI_Aint *,
			MPI_Datatype, MPI_Datatype *);
extern int PMPI_Type_create_hvector(int, int, MPI_Aint,
			MPI_Datatype, MPI_Datatype *);
extern int PMPI_Type_create_struct(int, int *, MPI_Aint *,
			MPI_Datatype *, MPI_Datatype *);
extern int PMPI_Type_dup(MPI_Datatype, MPI_Datatype *);
extern int PMPI_Type_create_resized(MPI_Datatype, MPI_Aint, MPI_Aint,
			MPI_Datatype *);
extern int PMPI_Type_create_keyval(MPI_Type_copy_attr_function *,
			MPI_Type_delete_attr_function *, int*, void*);
extern int PMPI_Type_free_keyval(int *);
extern int PMPI_Type_set_attr(MPI_Datatype, int, void *);
extern int PMPI_Type_get_attr(MPI_Datatype, int, void *, int *);
extern int PMPI_Type_delete_attr(MPI_Datatype, int);
extern int PMPI_Type_create_f90_real(int, int, MPI_Datatype *);
extern int PMPI_Type_create_f90_complex(int, int, MPI_Datatype *);
extern int PMPI_Type_create_f90_integer(int, MPI_Datatype *);
extern int PMPI_Type_match_size(int, int, MPI_Datatype *);

extern int PMPI_Ibcast(void *, int, MPI_Datatype, int,
		    MPI_Comm, MPI_Request *);
extern int PMPI_Ibarrier(MPI_Comm, MPI_Request *);
extern int PMPI_Igather(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int PMPI_Igatherv(void *, int, MPI_Datatype, void *,
		    int *, int *, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int PMPI_Iscatter(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int PMPI_Iscatterv(void *, int *, int *, MPI_Datatype, void *,
		    int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int PMPI_Iallgather(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int PMPI_Iallgatherv(void *, int, MPI_Datatype, void *,
		    int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int PMPI_Ialltoall(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int PMPI_Ialltoallv(void *, int *, int *, MPI_Datatype, void *,
		    int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int PMPI_Ialltoallw(void *, int *, int *, MPI_Datatype *, void *, int *,
		    int *, MPI_Datatype *, MPI_Comm, MPI_Request *);
extern int PMPI_Ireduce(void *, void *, int, MPI_Datatype, MPI_Op,
		    int, MPI_Comm, MPI_Request *);
extern int PMPI_Iallreduce(void *, void *, int, MPI_Datatype, MPI_Op,
		    MPI_Comm, MPI_Request *);
extern int PMPI_Ireduce_scatter(void *, void *, int *,
		    MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);
extern int PMPI_Ireduce_scatter_block(void *, void *, int,
		    MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);
extern int PMPI_Iscan(void *, void *, int, MPI_Datatype, MPI_Op,
		    MPI_Comm, MPI_Request *);
extern int PMPI_Iexscan(void *, void *, int, MPI_Datatype, MPI_Op,
		    MPI_Comm, MPI_Request *);

#endif /* !MPI_hpux || HPMP_BUILD_DLIB */

/*
 * Prototypes, for HPMPI entrypoints, only needed
 * for internal building.
 */
extern int HPMPI_Abort(MPI_Comm, int);
extern int HPMPI_Address(void *, MPI_Aint *);
extern int HPMPI_Allgather(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, MPI_Comm);
extern int HPMPI_Allgatherv(void *, int, MPI_Datatype, void *,
			int *, int *, MPI_Datatype, MPI_Comm);
extern int HPMPI_Allreduce(void *, void *, int, MPI_Datatype,
			MPI_Op, MPI_Comm);
extern int HPMPI_Alltoall(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, MPI_Comm);
extern int HPMPI_Alltoallv(void *, int *, int *, MPI_Datatype, void *,
			int *, int *, MPI_Datatype, MPI_Comm);
extern int HPMPI_Alltoallw(void *, int *, int *, MPI_Datatype*, void *,
			int *, int *, MPI_Datatype*, MPI_Comm);
extern int HPMPI_Attr_delete(MPI_Comm, int);
extern int HPMPI_Attr_get(MPI_Comm, int, void *, int *);
extern int HPMPI_Attr_put(MPI_Comm, int, void *);
extern int HPMPI_Barrier(MPI_Comm);
extern int HPMPI_Bcast(void *, int, MPI_Datatype, int, MPI_Comm);
extern int HPMPI_Bsend(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int HPMPI_Bsend_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int HPMPI_Buffer_attach(void *, int);
extern int HPMPI_Buffer_detach(void *, int *);
extern int HPMPI_Cancel(MPI_Request *);
extern int HPMPI_Cart_coords(MPI_Comm, int, int, int *);
extern int HPMPI_Cart_create(MPI_Comm, int, int *, int *,
			int, MPI_Comm *);
extern int HPMPI_Cart_get(MPI_Comm, int, int *, int *, int *);
extern int HPMPI_Cart_map(MPI_Comm, int, int *, int *, int *);
extern int HPMPI_Cart_rank(MPI_Comm, int *, int *);
extern int HPMPI_Cart_shift(MPI_Comm, int, int, int *, int *);
extern int HPMPI_Cart_sub(MPI_Comm, int *, MPI_Comm *);
extern int HPMPI_Cartdim_get(MPI_Comm, int *);
extern int HPMPI_Comm_compare(MPI_Comm, MPI_Comm, int *);
extern int HPMPI_Comm_create(MPI_Comm, MPI_Group, MPI_Comm *);
extern int HPMPI_Comm_create_group(MPI_Comm, MPI_Group, int, MPI_Comm *);
extern int HPMPI_Comm_dup(MPI_Comm, MPI_Comm *);
extern int HPMPI_Comm_free(MPI_Comm *);
extern int HPMPI_Comm_group(MPI_Comm, MPI_Group *);
extern int HPMPI_Comm_rank(MPI_Comm, int *);
extern int HPMPI_Comm_remote_group(MPI_Comm, MPI_Group *);
extern int HPMPI_Comm_remote_size(MPI_Comm, int *);
extern int HPMPI_Comm_size(MPI_Comm, int *);
extern int HPMPI_Comm_split(MPI_Comm, int, int, MPI_Comm *);
extern int HPMPI_Comm_split_type(MPI_Comm, int, int, MPI_Info, MPI_Comm *);
extern int HPMPI_Comm_test_inter(MPI_Comm, int *);
extern int HPMPI_Comm_dup_with_info(MPI_Comm, MPI_Info, MPI_Comm *);
extern int HPMPI_Comm_idup(MPI_Comm, MPI_Comm *, MPI_Request *);
extern int HPMPI_Comm_get_info(MPI_Comm, MPI_Info *);
extern int HPMPI_Comm_set_info(MPI_Comm, MPI_Info);
extern int HPMPI_Comm_get_parent(MPI_Comm *);
extern int HPMPI_Comm_spawn(char *, char **, int, MPI_Info, int,
			MPI_Comm, MPI_Comm *, int *);
extern int HPMPI_Comm_spawn_multiple(int, char **, char ***, int *,
			MPI_Info *, int, MPI_Comm, MPI_Comm *, int *);
extern int HPMPI_Comm_accept(char*, MPI_Info, int, MPI_Comm, MPI_Comm *);
extern int HPMPI_Comm_connect(char*, MPI_Info, int, MPI_Comm, MPI_Comm *);
extern int HPMPI_Comm_join(int, MPI_Comm *);
extern int HPMPI_Comm_disconnect(MPI_Comm *);
extern int HPMPI_Open_port(MPI_Info, char*);
extern int HPMPI_Close_port(char*);
extern int HPMPI_Publish_name(char*, MPI_Info, char*);
extern int HPMPI_Unpublish_name(char*, MPI_Info, char*);
extern int HPMPI_Lookup_name(char*, MPI_Info, char*);
extern int HPMPI_Dims_create(int, int, int *);
extern int HPMPI_Errhandler_create(MPI_Handler_function *,
			MPI_Errhandler *);
extern int HPMPI_Errhandler_free(MPI_Errhandler *);
extern int HPMPI_Errhandler_get(MPI_Comm, MPI_Errhandler *);
extern int HPMPI_Errhandler_set(MPI_Comm, MPI_Errhandler);
extern int HPMPI_Error_class(int, int *);
extern int HPMPI_Error_string(int, char *, int *);
extern int HPMPI_Add_error_class(int *);
extern int HPMPI_Add_error_code(int, int *);
extern int HPMPI_Add_error_string(int, char *);
extern int HPMPI_Finalize(void);
extern int HPMPI_Finalized(int *);
extern int HPMPI_Gather(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, int, MPI_Comm);
extern int HPMPI_Gatherv(void *, int, MPI_Datatype, void *,
			int *, int *, MPI_Datatype, int, MPI_Comm);
extern int HPMPI_Get_count(MPI_Status *, MPI_Datatype, int *);
extern int HPMPI_Get_elements(MPI_Status *, MPI_Datatype, int *);
extern int HPMPI_Get_elements_x(MPI_Status *, MPI_Datatype, MPI_Count *);
extern int HPMPI_Get_processor_name(char *, int *);
extern int HPMPI_Get_version(int *, int *);
extern int HPMPI_Get_library_version(char *, int *);
extern int HPMPI_Graph_create(MPI_Comm, int, int *, int *,
			int, MPI_Comm *);
extern int HPMPI_Graph_get(MPI_Comm, int, int, int *, int *);
extern int HPMPI_Graph_map(MPI_Comm, int, int *, int *, int *);
extern int HPMPI_Graph_neighbors(MPI_Comm, int, int, int *);
extern int HPMPI_Graph_neighbors_count(MPI_Comm, int, int *);
extern int HPMPI_Graphdims_get(MPI_Comm, int *, int *);
extern int HPMPI_Neighbor_allgather(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm);
extern int HPMPI_Neighbor_allgatherv(void *, int, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm);
extern int HPMPI_Neighbor_alltoall(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm);
extern int HPMPI_Neighbor_alltoallv(void *, int *, int *, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm);
extern int HPMPI_Neighbor_alltoallw(void *, int *, MPI_Aint *, MPI_Datatype *,
			void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm);
extern int HPMPI_Dist_graph_create(MPI_Comm, int, int*, int*,
			int*, int*,	MPI_Info, int, MPI_Comm*);
extern int HPMPI_Dist_graph_create_adjacent(MPI_Comm, int, int*, int*,
			int, int*, int*,	MPI_Info, int, MPI_Comm*);
extern int HPMPI_Dist_graph_neighbors_count(MPI_Comm, int*, int*, int*);
extern int HPMPI_Dist_graph_neighbors(MPI_Comm, int, int*, int*,
			int, int*, int*);
extern int HPMPI_Group_compare(MPI_Group, MPI_Group, int *);
extern int HPMPI_Group_difference(MPI_Group, MPI_Group, MPI_Group *);
extern int HPMPI_Group_excl(MPI_Group, int, int *, MPI_Group *);
extern int HPMPI_Group_free(MPI_Group *);
extern int HPMPI_Group_incl(MPI_Group, int, int *, MPI_Group *);
extern int HPMPI_Group_intersection(MPI_Group, MPI_Group, MPI_Group *);
extern int HPMPI_Group_range_excl(MPI_Group, int, int [][3], MPI_Group *);
extern int HPMPI_Group_range_incl(MPI_Group, int, int [][3], MPI_Group *);
extern int HPMPI_Group_rank(MPI_Group, int *);
extern int HPMPI_Group_size(MPI_Group, int *);
extern int HPMPI_Group_translate_ranks(MPI_Group, int, int *,
			MPI_Group, int *);
extern int HPMPI_Group_union(MPI_Group, MPI_Group, MPI_Group *);
extern int HPMPI_Ibsend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int HPMPI_Ineighbor_allgather(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int HPMPI_Ineighbor_allgatherv(void *, int, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int HPMPI_Ineighbor_alltoall(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int HPMPI_Ineighbor_alltoallv(void *, int *, int *, MPI_Datatype,
			void *, int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int HPMPI_Ineighbor_alltoallw(void *, int *, MPI_Aint *, MPI_Datatype *,
			void *, int *, MPI_Aint *, MPI_Datatype *, MPI_Comm, MPI_Request *);
extern int HPMPI_Init(int *, char ***);
extern int HPMPI_Initialized(int *);
extern int HPMPI_Intercomm_create(MPI_Comm, int, MPI_Comm, int,
			int, MPI_Comm *);
extern int HPMPI_Intercomm_merge(MPI_Comm, int, MPI_Comm *);
extern int HPMPI_Iprobe(int, int, MPI_Comm, int *, MPI_Status *);
extern int HPMPI_Irecv(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int HPMPI_Irsend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int HPMPI_Isend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int HPMPI_Issend(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int HPMPI_Keyval_create(MPI_Copy_function *,
			MPI_Delete_function *, int *, void *);
extern int HPMPI_Keyval_free(int *);
extern int HPMPI_Op_create(MPI_User_function *, int, MPI_Op *);
extern int HPMPI_Op_free(MPI_Op *);
extern int HPMPI_Op_commutative(MPI_Op, int*);
extern int HPMPI_Pack(void *, int, MPI_Datatype, void *, int,
			int *, MPI_Comm);
extern int HPMPI_Pack_external(char *, void *, int, MPI_Datatype, void *,
                        MPI_Aint, MPI_Aint *);
extern int HPMPI_Pack_size(int, MPI_Datatype, MPI_Comm, int *);
extern int HPMPI_Pack_external_size(char *, int, MPI_Datatype, MPI_Aint *);
extern int HPMPI_Pcontrol(const int level, ...);
extern int HPMPI_Probe(int, int, MPI_Comm, MPI_Status *);
extern int HPMPI_Mprobe(int, int, MPI_Comm, MPI_Message *, MPI_Status *);
extern int HPMPI_Improbe(int, int, MPI_Comm, int *, MPI_Message *, MPI_Status *);
extern int HPMPI_Recv(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Status *);
extern int HPMPI_Recv_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int HPMPI_Reduce(void *, void *, int, MPI_Datatype,
			MPI_Op, int, MPI_Comm);
extern int HPMPI_Reduce_local(void *, void *, int, MPI_Datatype,
			MPI_Op);
extern int HPMPI_Reduce_scatter(void *, void *, int *,
			MPI_Datatype, MPI_Op, MPI_Comm);
extern int HPMPI_Reduce_scatter_block(void *, void *, int,
			MPI_Datatype, MPI_Op, MPI_Comm);
extern int HPMPI_Request_free(MPI_Request *);
extern int HPMPI_Request_get_status(MPI_Request, int *, MPI_Status *);
extern int HPMPI_Grequest_start(MPI_Grequest_query_function*,
			MPI_Grequest_free_function*,
			MPI_Grequest_cancel_function*, void*, MPI_Request*);
extern int HPMPI_Grequest_complete(MPI_Request);
extern int HPMPIX_Grequest_class_create(MPI_Grequest_query_function *,
			MPI_Grequest_free_function *,
			MPI_Grequest_cancel_function *, MPIX_Grequest_poll_fn *,
			MPIX_Grequest_wait_fn *, MPIX_Grequest_class *);
extern int HPMPIX_Grequest_class_allocate(MPIX_Grequest_class greq_class,
			void *extra_state, MPI_Request *request);
extern int HPMPI_Rsend(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int HPMPI_Rsend_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int HPMPI_Scan(void *, void *, int, MPI_Datatype,
			MPI_Op, MPI_Comm);
extern int HPMPI_Exscan(void *, void *, int, MPI_Datatype,
			MPI_Op, MPI_Comm);
extern int HPMPI_Scatter(void *, int, MPI_Datatype, void *,
			int, MPI_Datatype, int, MPI_Comm);
extern int HPMPI_Scatterv(void *, int *, int *, MPI_Datatype, void *,
			int, MPI_Datatype, int, MPI_Comm);
extern int HPMPI_Send(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int HPMPI_Send_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int HPMPI_Sendrecv(void *, int, MPI_Datatype, int, int,
			void *, int, MPI_Datatype, int, int,
			MPI_Comm, MPI_Status *);
extern int HPMPI_Sendrecv_replace(void *, int, MPI_Datatype, int, int,
			int, int, MPI_Comm, MPI_Status *);
extern int HPMPI_Ssend(void *, int, MPI_Datatype, int, int, MPI_Comm);
extern int HPMPI_Ssend_init(void *, int, MPI_Datatype, int,
			int, MPI_Comm, MPI_Request *);
extern int HPMPI_Start(MPI_Request *);
extern int HPMPI_Startall(int, MPI_Request *);
extern int HPMPI_Test(MPI_Request *, int *, MPI_Status *);
extern int HPMPI_Test_cancelled(MPI_Status *, int *);
extern int HPMPI_Testall(int, MPI_Request *, int *, MPI_Status *);
extern int HPMPI_Testany(int, MPI_Request *, int *, int *, MPI_Status *);
extern int HPMPI_Testsome(int, MPI_Request *, int *, int *, MPI_Status *);
extern int HPMPI_Topo_test(MPI_Comm, int *);
extern int HPMPI_Type_commit(MPI_Datatype *);
extern int HPMPI_Type_contiguous(int, MPI_Datatype, MPI_Datatype *);
extern int HPMPI_Type_extent(MPI_Datatype, MPI_Aint *);
extern int HPMPI_Type_free(MPI_Datatype *);
extern int HPMPI_Type_get_contents(MPI_Datatype, int, int, int,
			int [], MPI_Aint [], MPI_Datatype []);
extern int HPMPI_Type_get_envelope(MPI_Datatype, int *, int *,
			int *, int *);
extern int HPMPI_Type_get_extent(MPI_Datatype, MPI_Aint *, MPI_Aint *);
extern int HPMPI_Type_get_extent_x(MPI_Datatype, MPI_Count *, MPI_Count *);
extern int HPMPI_Type_get_true_extent(MPI_Datatype, MPI_Aint *,
			MPI_Aint *);
extern int HPMPI_Type_get_true_extent_x(MPI_Datatype, MPI_Count *,
			MPI_Count *);
extern int HPMPI_Type_hindexed(int, int *, MPI_Aint *,
			MPI_Datatype, MPI_Datatype *);
extern int HPMPI_Type_hvector(int, int, MPI_Aint, MPI_Datatype,
			MPI_Datatype *);
extern int HPMPI_Type_indexed(int, int *, int *, MPI_Datatype,
			MPI_Datatype *);
extern int HPMPI_Type_lb(MPI_Datatype, MPI_Aint *);
extern int HPMPI_Type_size(MPI_Datatype, int *);
extern int HPMPI_Type_size_x(MPI_Datatype, MPI_Count *);
extern int HPMPI_Type_struct(int, int *, MPI_Aint *,
			MPI_Datatype *, MPI_Datatype *);
extern int HPMPI_Type_ub(MPI_Datatype, MPI_Aint *);
extern int HPMPI_Type_vector(int, int, int, MPI_Datatype,
			MPI_Datatype *);
extern int HPMPI_Unpack(void *, int, int *, void *, int,
			MPI_Datatype, MPI_Comm);
extern int HPMPI_Unpack_external(char *, void *, MPI_Aint, MPI_Aint *,
                        void *, int, MPI_Datatype);
extern int HPMPI_Wait(MPI_Request *, MPI_Status *);
extern int HPMPI_Waitall(int, MPI_Request *, MPI_Status *);
extern int HPMPI_Waitany(int, MPI_Request *, int *, MPI_Status *);
extern int HPMPI_Waitsome(int, MPI_Request *, int *, int *, MPI_Status *);
extern double HPMPI_Wtick(void);
extern double HPMPI_Wtime(void);
extern int HPMPI_Mrecv(void *, int, MPI_Datatype,
			MPI_Message *, MPI_Status *);
extern int HPMPI_Imrecv(void *, int, MPI_Datatype,
			MPI_Message *, MPI_Request *);
extern int HPMPIHA_Comm_failure_ack(MPI_Comm);
extern int HPMPIHA_Comm_failure_get_acked(MPI_Comm, MPI_Group*);
extern int HPMPIHA_Comm_revoke(MPI_Comm);
extern int HPMPIHA_Comm_shrink(MPI_Comm, MPI_Comm*);
extern int HPMPIHA_Comm_agree(MPI_Comm, int*);
extern int HPMPIHA_Comm_iagree(MPI_Comm, int*, MPI_Request *);

extern MPI_Comm HPMPI_Comm_f2c(MPI_Fint);
extern MPI_Datatype HPMPI_Type_f2c(MPI_Fint);
extern MPI_Group HPMPI_Group_f2c(MPI_Fint);
extern MPI_Op HPMPI_Op_f2c(MPI_Fint);
extern MPI_Request HPMPI_Request_f2c(MPI_Fint);
extern MPI_Win HPMPI_Win_f2c(MPI_Fint);
extern MPI_Info HPMPI_Info_f2c(MPI_Fint);
extern MPI_Errhandler HPMPI_Errhandler_f2c(MPI_Fint);

extern MPI_Fint HPMPI_Comm_c2f(MPI_Comm);
extern MPI_Fint HPMPI_Type_c2f(MPI_Datatype);
extern MPI_Fint HPMPI_Group_c2f(MPI_Group);
extern MPI_Fint HPMPI_Op_c2f(MPI_Op);
extern MPI_Fint HPMPI_Request_c2f(MPI_Request);
extern MPI_Fint HPMPI_Win_c2f(MPI_Win);
extern MPI_Fint HPMPI_Info_c2f(MPI_Info);
extern MPI_Fint HPMPI_Errhandler_c2f(MPI_Errhandler);

extern int HPMPI_Status_f2c(void *, MPI_Status *);
extern int HPMPI_Status_c2f(MPI_Status *, void *);
extern int HPMPI_Status_set_cancelled(MPI_Status *, int);
extern int HPMPI_Status_set_elements(MPI_Status *, MPI_Datatype, int);
extern int HPMPI_Status_set_elements_x(MPI_Status *, MPI_Datatype, MPI_Count);

extern int HPMPI_Info_create(MPI_Info *);
extern int HPMPI_Info_delete(MPI_Info, const char *);
extern int HPMPI_Info_dup(MPI_Info, MPI_Info *);
extern int HPMPI_Info_free(MPI_Info *);
extern int HPMPI_Info_get(MPI_Info, const char *, int, char *, int *);
extern int HPMPI_Info_get_nkeys(MPI_Info, int *);
extern int HPMPI_Info_get_nthkey(MPI_Info, int, char *);
extern int HPMPI_Info_get_valuelen(MPI_Info, const char *, int *, int *);
extern int HPMPI_Info_set(MPI_Info, const char *, const char *);

extern int HPMPI_Win_create(void *, MPI_Aint, int,
			MPI_Info, MPI_Comm, MPI_Win *);
extern int HPMPI_Win_allocate(MPI_Aint, int, MPI_Info,
			MPI_Comm, void *, MPI_Win *);
extern int HPMPI_Win_allocate_shared(MPI_Aint, int, MPI_Info,
			MPI_Comm, void *, MPI_Win *);
extern int HPMPI_Win_fence(int, MPI_Win);
extern int HPMPI_Win_free(MPI_Win *);
extern int HPMPI_Win_get_group(MPI_Win, MPI_Group *);
extern int HPMPI_Win_attach(MPI_Win, void *, MPI_Aint);
extern int HPMPI_Win_detach(MPI_Win, void *);
extern int HPMPI_Win_create_dynamic(MPI_Info, MPI_Comm, MPI_Win *);
extern int HPMPI_Win_flush(int, MPI_Win);
extern int HPMPI_Win_flush_all(MPI_Win);
extern int HPMPI_Win_flush_local(int, MPI_Win);
extern int HPMPI_Win_flush_local_all(MPI_Win);
extern int HPMPI_Win_get_info(MPI_Win, MPI_Info *);
extern int HPMPI_Win_set_info(MPI_Win, MPI_Info);
extern int HPMPI_Win_sync(MPI_Win);
extern int HPMPI_Win_lock(int, int, int, MPI_Win);
extern int HPMPI_Win_unlock(int, MPI_Win);
extern int HPMPI_Win_lock_all(int, MPI_Win);
extern int HPMPI_Win_unlock_all(MPI_Win);
extern int HPMPI_Win_shared_query(MPI_Win, int, MPI_Aint *, int *, void *);
extern int HPMPI_Win_start(MPI_Group, int, MPI_Win);
extern int HPMPI_Win_post(MPI_Group, int, MPI_Win);
extern int HPMPI_Win_complete(MPI_Win);
extern int HPMPI_Win_wait(MPI_Win);
extern int HPMPI_Win_test(MPI_Win, int *);
extern int HPMPI_Win_create_errhandler(MPI_Win_errhandler_function *,
			MPI_Errhandler *);
extern int HPMPI_Win_set_errhandler(MPI_Win, MPI_Errhandler);
extern int HPMPI_Win_get_errhandler(MPI_Win, MPI_Errhandler *);
extern int HPMPI_Win_call_errhandler(MPI_Win, int);
extern int HPMPI_Win_create_keyval(MPI_Win_copy_attr_function *,
			MPI_Win_delete_attr_function *, int *, void *);
extern int HPMPI_Win_free_keyval(int *);
extern int HPMPI_Win_set_attr(MPI_Win, int, void *);
extern int HPMPI_Win_get_attr(MPI_Win, int, void *, int *);
extern int HPMPI_Win_delete_attr(MPI_Win, int);
extern int HPMPI_Get(void *, int, MPI_Datatype, int, MPI_Aint,
			int, MPI_Datatype, MPI_Win);
extern int HPMPI_Put(void *, int, MPI_Datatype, int, MPI_Aint,
			int, MPI_Datatype, MPI_Win);
extern int HPMPI_Accumulate(void *, int, MPI_Datatype, int, MPI_Aint,
			int, MPI_Datatype, MPI_Op, MPI_Win);

extern int HPMPI_Compare_and_swap(void *, void *, void *,
			MPI_Datatype, int, MPI_Aint, MPI_Win);
extern int HPMPI_Fetch_and_op(void *, void *, MPI_Datatype,
			int, MPI_Aint, MPI_Op, MPI_Win);
extern int HPMPI_Get_accumulate(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype,
			MPI_Op, MPI_Win);
extern int HPMPI_Raccumulate(void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype,
			MPI_Op, MPI_Win, MPI_Request *);
extern int HPMPI_Rget_accumulate(void *, int, MPI_Datatype,
			void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype,
			MPI_Op, MPI_Win, MPI_Request *);
extern int HPMPI_Rget(void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype, MPI_Win,
			MPI_Request *);
extern int HPMPI_Rput(void *, int, MPI_Datatype,
			int, MPI_Aint, int, MPI_Datatype, MPI_Win,
			MPI_Request *);

extern int HPMPI_Alloc_mem(MPI_Aint, MPI_Info, void *);
extern int HPMPI_Free_mem(void *);

extern int HPMPI_Is_thread_main(int *flag);
extern int HPMPI_Init_thread(int *, char ***, int , int *);
extern int HPMPI_Query_thread(int *);

extern int HPMPI_Comm_set_name(MPI_Comm, char *);
extern int HPMPI_Comm_get_name(MPI_Comm, char *, int *);
extern int HPMPI_Type_set_name(MPI_Datatype, char *);
extern int HPMPI_Type_get_name(MPI_Datatype, char *, int *);
extern int HPMPI_Win_set_name(MPI_Win, char *);
extern int HPMPI_Win_get_name(MPI_Win, char *, int *);

extern int HPMPI_Comm_delete_attr(MPI_Comm, int);
extern int HPMPI_Comm_set_attr(MPI_Comm, int, void *);
extern int HPMPI_Comm_get_attr(MPI_Comm, int, void *, int *);
extern int HPMPI_Comm_create_errhandler(MPI_Comm_errhandler_function *,
			MPI_Errhandler *);
extern int HPMPI_Comm_get_errhandler(MPI_Comm, MPI_Errhandler *);
extern int HPMPI_Comm_set_errhandler(MPI_Comm, MPI_Errhandler);
extern int HPMPI_Comm_create_keyval(MPI_Comm_copy_attr_function *,
			MPI_Comm_delete_attr_function *, int *, void *);
extern int HPMPI_Comm_free_keyval(int *);
extern int HPMPI_Comm_call_errhandler(MPI_Comm, int);
extern int HPMPI_Get_address(void *, MPI_Aint *);
extern int HPMPI_Type_create_indexed_block(int, int, int *,
			MPI_Datatype, MPI_Datatype *);
extern int HPMPI_Type_create_hindexed(int, int *, MPI_Aint *,
			MPI_Datatype, MPI_Datatype *);
extern int HPMPI_Type_create_hvector(int, int, MPI_Aint,
			MPI_Datatype, MPI_Datatype *);
extern int HPMPI_Type_create_struct(int, int *, MPI_Aint *,
			MPI_Datatype *, MPI_Datatype *);
extern int HPMPI_Type_dup(MPI_Datatype, MPI_Datatype *);
extern int HPMPI_Type_create_resized(MPI_Datatype, MPI_Aint, MPI_Aint,
			MPI_Datatype *);
extern int HPMPI_Type_create_keyval(MPI_Type_copy_attr_function *,
			MPI_Type_delete_attr_function *, int*, void*);
extern int HPMPI_Type_free_keyval(int *);
extern int HPMPI_Type_set_attr(MPI_Datatype, int, void *);
extern int HPMPI_Type_get_attr(MPI_Datatype, int, void *, int *);
extern int HPMPI_Type_delete_attr(MPI_Datatype, int);
extern int HPMPI_Type_create_f90_real(int, int, MPI_Datatype *);
extern int HPMPI_Type_create_f90_complex(int, int, MPI_Datatype *);
extern int HPMPI_Type_create_f90_integer(int, MPI_Datatype *);
extern int HPMPI_Type_match_size(int, int, MPI_Datatype *);

/*
 * HP MPI extensions
 */
extern int PMPIHP_Comm_id(MPI_Comm, int *);
extern int PMPIHP_Type_id(MPI_Datatype, int *);
extern int PMPIHP_Trace_on(void);
extern int PMPIHP_Trace_off(void);

extern int HPMPI_Ibcast(void *, int, MPI_Datatype, int,
		    MPI_Comm, MPI_Request *);
extern int HPMPI_Ibarrier(MPI_Comm, MPI_Request *);
extern int HPMPI_Igather(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int HPMPI_Igatherv(void *, int, MPI_Datatype, void *,
		    int *, int *, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int HPMPI_Iscatter(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int HPMPI_Iscatterv(void *, int *, int *, MPI_Datatype, void *,
		    int, MPI_Datatype, int, MPI_Comm, MPI_Request *);
extern int HPMPI_Iallgather(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int HPMPI_Iallgatherv(void *, int, MPI_Datatype, void *,
		    int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int HPMPI_Ialltoall(void *, int, MPI_Datatype, void *,
		    int, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int HPMPI_Ialltoallv(void *, int *, int *, MPI_Datatype, void *,
		    int *, int *, MPI_Datatype, MPI_Comm, MPI_Request *);
extern int HPMPI_Ialltoallw(void *, int *, int *, MPI_Datatype *, void *, int *,
		    int *, MPI_Datatype *, MPI_Comm, MPI_Request *);
extern int HPMPI_Ireduce(void *, void *, int, MPI_Datatype, MPI_Op,
		    int, MPI_Comm, MPI_Request *);
extern int HPMPI_Iallreduce(void *, void *, int, MPI_Datatype, MPI_Op,
		    MPI_Comm, MPI_Request *);
extern int HPMPI_Ireduce_scatter(void *, void *, int *,
		    MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);
extern int HPMPI_Ireduce_scatter_block(void *, void *, int,
		    MPI_Datatype, MPI_Op, MPI_Comm, MPI_Request *);
extern int HPMPI_Iscan(void *, void *, int, MPI_Datatype, MPI_Op,
		    MPI_Comm, MPI_Request *);
extern int HPMPI_Iexscan(void *, void *, int, MPI_Datatype, MPI_Op,
		    MPI_Comm, MPI_Request *);

#else /* !defined(__STDC__) && !defined(c_plusplus) && !defined(__cplusplus) */

/*
 * All functions DO NOT return an integer.
 */

#if !defined(MPI_hpux) || defined(HPMP_BUILD_CXXBINDING)

/*
 * Function prototype only for users.
 */
extern double MPI_Wtick();
extern double MPI_Wtime();

extern MPI_Comm MPI_Comm_f2c();
extern MPI_Datatype MPI_Type_f2c();
extern MPI_Group MPI_Group_f2c();
extern MPI_Op MPI_Op_f2c();
extern MPI_Request MPI_Request_f2c();
extern MPI_Win MPI_Win_f2c();
extern MPI_Info MPI_Info_f2c();
extern MPI_Errhandler MPI_Errhandler_f2c();

extern MPI_Fint MPI_Comm_c2f();
extern MPI_Fint MPI_Type_c2f();
extern MPI_Fint MPI_Group_c2f();
extern MPI_Fint MPI_Op_c2f();
extern MPI_Fint MPI_Request_c2f();
extern MPI_Fint MPI_Win_c2f();
extern MPI_Fint MPI_Info_c2f();
extern MPI_Fint MPI_Errhandler_c2f();

#endif /* MPI_hpux */

/*
 * Profiling prototypes, for both users and internal building.
 */
extern double PMPI_Wtick();
extern double PMPI_Wtime();

extern MPI_Comm PMPI_Comm_f2c();
extern MPI_Datatype PMPI_Type_f2c();
extern MPI_Group PMPI_Group_f2c();
extern MPI_Op PMPI_Op_f2c();
extern MPI_Request PMPI_Request_f2c();
extern MPI_Win PMPI_Win_f2c();
extern MPI_Info PMPI_Info_f2c();
extern MPI_Errhandler PMPI_Errhandler_f2c();

extern MPI_Fint PMPI_Comm_c2f();
extern MPI_Fint PMPI_Type_c2f();
extern MPI_Fint PMPI_Group_c2f();
extern MPI_Fint PMPI_Op_c2f();
extern MPI_Fint PMPI_Request_c2f();
extern MPI_Fint PMPI_Win_c2f();
extern MPI_Fint PMPI_Info_c2f();
extern MPI_Fint PMPI_Errhandler_c2f();

#endif /* defined(__STDC__) || defined(c_plusplus) || defined(__cplusplus) */

#ifndef HP_MPI_NOIO
#include <mpio.h>
#endif	/* HP_MPI_NOIO */

#ifdef HPMPI_LONG_EXTENTIONS
#ifdef MPI_hpux
/* internal building */
#include <mpiLONG.h>
#else
#include <mpiL.h>
#endif
#endif

#if defined(c_plusplus) || defined(__cplusplus)
}
#endif

#if defined(c_plusplus) || defined(__cplusplus)
#include <mpiCC.h>
#endif

#endif	/* _MPI_H */
