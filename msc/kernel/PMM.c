#include "types.h"

static u64 bitmap[2];
u64 pmmalloc(void);
void pmmfree(u64 addr);

bool pmminit(void) {
    for (int c = 0; c < 2; c++) {
        for (int i = 0; i < 64; i++) {
            if ((c == 0) && ( (i == 0) || (i == 1))) {
                bitmap[c] = bitmap[c] | (1ULL << i);
            } else {
                bitmap[c] &= ~(1ULL << i);
            }
        }
    }

    u64 pmm_test = pmmalloc();
    if (pmm_test == 0) {
        return false;
    }
    pmmfree(pmm_test);
    return true;
}

u64 pmmalloc(void) {
    for (int c = 0; c < 128; c++) {
        if ((bitmap[c/64] & (1ULL << (c%64))) == 0) {
            bitmap[c/64] = bitmap[c/64] | (1ULL << (c%64));
            return c << 21;
        }
    }
    return 0;
}

void pmmfree(u64 addr) {
    bitmap[(addr >> 21)/64] &= ~(1ULL << ((addr >> 21)%64));
}
