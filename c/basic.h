#ifndef R3_COMMONS_BASIC_H_
#define R3_COMMONS_BASIC_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define null ((void*)0)

#define lenof(A) (sizeof(A) / sizeof((A)[0]))

// Usage:
// for( Vector(int) x = { arr, n }; x.len > 0; stepVector(x) ) ...;
#define Vector(T) struct { T* p; size_t len; }
#define stepVector(V) (++(V).p, --(V).len)

inline void mfree(void** ptr) { free(*ptr); *ptr = 0; }

typedef long long bigint;
inline bigint minI(bigint lhs, bigint rhs) { return lhs < rhs ? lhs : rhs; }
inline bigint maxI(bigint lhs, bigint rhs) { return lhs > rhs ? lhs : rhs; }
inline double minF(double lhs, double rhs) { return lhs < rhs ? lhs : rhs; }
inline double maxF(double lhs, double rhs) { return lhs > rhs ? lhs : rhs; }
#define min(LHS, RHS) _Generic(\
    (LHS),                     \
    int: minI,                 \
    bigint: minI,              \
    float: minF,               \
    double: minF)              \
  (LHS, RHS)
#define max(LHS, RHS) _Generic(\
    (LHS),                     \
    int: maxI,                 \
    bigint: maxI,              \
    float: maxF,               \
    double: maxF)              \
  (LHS, RHS)


#endif  // R3_COMMONS_BASIC_H_
