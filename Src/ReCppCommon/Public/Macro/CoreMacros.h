#pragma once
#include <cassert>
#include <type_traits>


#define PURE_VIRTUAL(RETURN) \
	{ assert(false); RETURN }

#define PURE_VIRTUAL_VOID() \
	{ assert(false); }

#define PURE_VIRTUAL_DEFAULT(T) \
	{ \
		assert(false); \
		static T Default{}; \
		return Default; \
	}


#define DEPRECATED(Version, Message) [[deprecated(Message " Please update your code to the new API before upgrading to the next release, otherwise your project will no longer compile.")]]

#define UNUSED(EXPR_) \
    do { if (false) (void)(EXPR_); } while(0)

#define PP_WRAP_CODE(CODE_) \
    do { CODE_; } while (0)

#define PP_EMPTY_STATEMENT \
    do { } while (0)

#define RE_INNER_STR(STR) #STR
#define RE_STR(STR) RE_INNER_STR(STR)

#define CONCAT2(A, B) A##B
#define CONCAT3(A, B, C) A##B##C
#define CONCAT4(A, B, C, D) A##B##C##D
#define CONCAT5(A, B, C, D, E) A##B##C##D##E

#define INLINE inline

#ifndef FORCE_INLINE
#if COMPILED_BY_CLANG
    #define FORCE_INLINE inline
#elif COMPILED_BY_MSVC
    #if (_MSC_VER >= 1200)
    #define FORCE_INLINE __forceinline
    #else
    #define FORCE_INLINE __inline
    #endif
#elif COMPILED_BY_GUN
    #define FORCE_INLINE __attribute__((always_inline))
#else
    #error "not supported for current compiler"
#endif
#endif

#ifndef NODISCARD
#define NODISCARD [[nodiscard]]
#endif