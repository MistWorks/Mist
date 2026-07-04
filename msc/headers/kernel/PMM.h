#pragma once
#include "types.h"

bool pmminit(void);
u64 pmmalloc(void);
void pmmfree(u64 addr);
