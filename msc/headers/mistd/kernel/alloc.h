#pragma once

typedef struct header {
    u64 size;
    u32 is_free;
    u32 magic;
    struct header* next;
    struct header* prev;
} header;
