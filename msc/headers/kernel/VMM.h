#pragma once
#include "types.h"

#define PG_PRESENT (1ULL << 0)
#define PG_WRITE (1ULL << 1)
#define PG_USER (1ULL << 2)
#define PG_PS (1ULL << 7)

bool vmminit(void);
int vmmproc(void);
void ptswitch(int ptid);
void vmmmap(int ptid, u64 virt, u64 phys, u64 flags);
