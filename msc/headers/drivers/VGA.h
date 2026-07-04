#pragma once
#include "types.h"

void vgaclear(void);
void vgaput(u16 x, u16 y, char c);
void vgascrollup();
char vgaget(u16 x, u16 y);
