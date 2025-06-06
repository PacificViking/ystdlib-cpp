#ifndef YSTDLIB_WRAPPED_FACADE_HEADERS_SYS_TYPES_HPP
#define YSTDLIB_WRAPPED_FACADE_HEADERS_SYS_TYPES_HPP

// clang-format off
// IWYU pragma: begin_exports
#include <sys/types.h>

#if defined(__APPLE__)
#include <sys/_types/_u_char.h>
#include <sys/_types/_u_short.h>
#include <sys/_types/_u_int.h>
#include <sys/_types/_fsid_t.h>
#include <sys/_types/_ino_t.h>
#include <sys/_types/_ino64_t.h>
#include <sys/_types/_dev_t.h>
#include <sys/_types/_gid_t.h>
#include <sys/_types/_mode_t.h>
#include <sys/_types/_nlink_t.h>
#include <sys/_types/_uid_t.h>
#include <sys/_types/_off_t.h>
#include <sys/_types/_pid_t.h>
#include <sys/_types/_id_t.h>
#include <sys/_types/_ssize_t.h>
#include <sys/_types/_caddr_t.h>
#include <sys/_types/_key_t.h>
#include <sys/_types/_useconds_t.h>
#include <sys/_types/_suseconds_t.h>
#include <sys/_types/_u_int8_t.h>
#include <sys/_types/_u_int16_t.h>
#include <sys/_types/_u_int32_t.h>
#include <sys/_types/_u_int64_t.h>
#include <sys/_types/_blksize_t.h>
#include <sys/_types/_blkcnt_t.h>
#include <sys/_types/_fsblkcnt_t.h>
#include <sys/_types/_fsfilcnt_t.h>
#endif
// IWYU pragma: end_exports
// clang-format on

#endif  // YSTDLIB_WRAPPED_FACADE_HEADERS_SYS_TYPES_HPP
