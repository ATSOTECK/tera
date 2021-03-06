/*
 * VGDE - Video Game Development Environment
 * Copyright (c) 2020-2021 Skyler Burwell
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

#ifndef __VGDE_CONFIG_H__
#define __VGDE_CONFIG_H__

#include <cassert>
#include <cstdint>
#include <Windows.h>

#ifndef NDEBUG
#   define VDEBUG
#endif

#if defined(WIN32) || defined(_WIN32)
#   define VWIN
#   include <Windows.h>
#endif

#if defined(__APPLE__)
#   define VMAC
#endif

#define IS_MSVC _MSC_VER && !__INTEL_COMPILER

#if IS_MSVC
#   define MSVC_HACK(FUNC, ARGS) FUNC ARGS
#   define APPLY(FUNC, ...) MSVC_HACK(FUNC, (__VA_ARGS__))
#   define VA_LENGTH(...) APPLY(VA_LENGTH_, 0, ## __VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#else
#   define VA_LENGTH(...) VA_LENGTH_(0, ## __VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#endif

#define VA_LENGTH_(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, N, ...) N
#define vexec(Func, ...) Func(VA_LENGTH(__VA_ARGS__), __VA_ARGS__)

#define null nullptr //Yes I know this is a bad idea.
#define var auto
#define keep [[nodiscard]]
#define until(x) while(!(x))

#define vcatimpl(x,y) x##y
#define vcat(x,y) vcatimpl(x,y)

typedef int8_t  int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef int32   bool32;

typedef uint8_t			   uint8;
typedef unsigned char	   uchar;
typedef unsigned short	   ushort;
typedef uint16_t		   uint16;
typedef uint32_t		   uint32;
typedef unsigned int	   uint;
typedef unsigned long	   ulong;
typedef unsigned long long ullong;
typedef uint64_t		   uint64;

typedef int16  char16;
typedef int32  char32;
typedef int64  char64;
typedef uint16 uchar16;
typedef uint32 uchar32;
typedef uint64 uchar64;

#define staticCast(x, y)	  static_cast<x>(y)
#define staticCasti(x)		  static_cast<int>(x)
#define staticCasti8(x)		  static_cast<int8>(x)
#define staticCasti16(x)	  static_cast<int16>(x)
#define staticCasti32(x)	  static_cast<int32>(x)
#define staticCasti64(x)	  static_cast<int64>(x)
#define staticCastu(x)		  static_cast<uint>(x)
#define staticCastu8(x)		  static_cast<uint8>(x)
#define staticCastu16(x)	  static_cast<uint16>(x)
#define staticCastu32(x)	  static_cast<uint32>(x)
#define staticCastu64(x)	  static_cast<uint64>(x)
#define staticCastf(x)		  static_cast<float>(x)
#define staticCast_t(x)		  static_cast<size_t>(x)
#define staticCastl(x)        static_cast<long>(x)
#define staticCastul(x)		  static_cast<ulong>(x)
#define staticCastc(x)		  static_cast<char>(x)
#define dynamicCast(x, y)	  dynamic_cast<x>(y)
#define reinterpretCast(x, y) reinterpret_cast<x>(y)
#define constCast(x, y)		  const_cast<x>(y)

#define here std::cout << "here" << __COUNTER__ << " line #" << __LINE__ << " " __FILE__ << std::endl;

#define vgderr(x)\
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); \
std::cerr << "Error: '" << x << "' on line #" << __LINE__ << " in " __FILE__ << std::endl; \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  \
assert(false)

#define verr(x)\
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); \
std::cerr << "Error: " << x << std::endl; \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); \
assert(false)

#define vgdewarn(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); \
std::cerr << "Warning: '" << x << "' on line #" << __LINE__ << " in " __FILE__ << std::endl; \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)

#define db(x) std::cout << x << std::endl
#define dbq(x) std::cout << "'" << x << "'" << std::endl
#define dbQ(x) std::cout << "\"" << x << "\"" << std::endl
#define dbln std::cout << std::endl;
#define vtrace(x) std::cerr << __FILE__ << ", L" << __LINE__ << ": " << x << std::endl
#define vtracemsg std::cerr << __FILE__ << ", L" << __LINE__ << ": "

#ifdef VDEBUG
#define TODO(name, msg) std::cerr << "TODO(" << name << "): " << msg << std::endl\
<< "\t-> line " << __LINE__ << " in " << __FILE__ << std::endl
#else
#define TODO(name, msg)
#endif

#endif //__VGDE_CONFIG_H__
