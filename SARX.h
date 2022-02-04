#ifndef SARX_INCLUDED
#define SARX_INCLUDED

#include "stdint.h"

typedef struct SARXB_struct {
    uint64_t val[4];
} SARXB;

inline SARXB SARX_hash(const SARXB block, const uint64_t rounds);
SARXB SARX_hash(const SARXB block, const uint64_t rounds) {
    #define MIX(a, b, c, s) a += b; c ^= a; c = (c << s) | (c >> (64 - s))
    SARXB mix = block;
    for (uint64_t i = 0; i < rounds; i++) {
        uint64_t* x = mix.val;
        MIX(x[0], x[1], x[2],  2);
        MIX(x[1], x[2], x[3],  3);
        MIX(x[2], x[3], x[0],  5);
        MIX(x[3], x[0], x[1],  7);
        MIX(x[0], x[1], x[2], 11);
        MIX(x[1], x[2], x[3], 13);
        MIX(x[2], x[3], x[0], 17);
        MIX(x[3], x[0], x[1], 19);
        MIX(x[0], x[1], x[2], 23);
        MIX(x[1], x[2], x[3], 29);
        MIX(x[2], x[3], x[0], 31);
        MIX(x[3], x[0], x[1], 37);
        MIX(x[0], x[1], x[2], 41);
        MIX(x[1], x[2], x[3], 43);
        MIX(x[2], x[3], x[0], 47);
        MIX(x[3], x[0], x[1], 53);
        MIX(x[0], x[1], x[2], 59);
        MIX(x[1], x[2], x[3], 61);
    }
    mix.val[0] ^= block.val[0];
    mix.val[1] ^= block.val[1];
    mix.val[2] ^= block.val[2];
    mix.val[3] ^= block.val[3];
    return mix;
}

#endif
