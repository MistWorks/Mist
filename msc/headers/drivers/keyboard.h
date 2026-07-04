#pragma once
extern char* letter_buffer;

void kbdinit(void);
void kbdhandle(u64 error_code);
char kbdget(void);
