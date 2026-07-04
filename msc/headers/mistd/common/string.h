#pragma once

static char* example_str;

usize strlen(const char* str);
int striseq(const char* a, const char* b);
void strcopy(const char* a, char* b);
char* format(u64 val, char* buf, u8 base);
