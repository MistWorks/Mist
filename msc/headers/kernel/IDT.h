#pragma once

extern volatile u8 kbd_scancode;
extern volatile bool kbd_ready;

bool idtinit(void);
void isrhandler(u8 vector, u64 error_code, u64 rip);
void idtgate(u8 vector, void* handler, u8 type, u8 dpl);
