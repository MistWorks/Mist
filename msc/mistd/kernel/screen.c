#include "mist.h"

u16 cursor_x = 0;
u16 cursor_y = 0;

void cursync(void) {
    u16 pos = cursor_y * 80 + cursor_x;
    outb(0x3D4, 14); outb(0x3D5, pos >> 8);
    outb(0x3D4, 15); outb(0x3D5, pos & 0xFF);
}

void cursupd(int x, int y) {
    cursor_x = x;
    cursor_y = y;
    cursync();
}

void clear(void) {
    vgaclear();
    cursupd(0, 0);
}

void putchar(char c) {
    if (c == '\n') {
        cursupd(0, ++cursor_y);
    } else {
        vgaput(cursor_x, cursor_y, c);
        cursupd(++cursor_x, cursor_y);
        if (cursor_x >= 80) {
            cursupd(0, ++cursor_y);
        }
    }
    if (cursor_y >= 25) {
        vgascrollup();
        cursupd(cursor_x, 24);
    }
}

void delchar(void) {
    if ((cursor_x == 0) && (cursor_y == 0)) {
        return;
    } else if (cursor_x == 0) {
        vgaput(79, --cursor_y, 0);
        cursupd(79, cursor_y);
        cursync();
    } else {
        vgaput(--cursor_x, cursor_y, 0);
        cursync();
    }
}

void print_str(const char* c) {
    while (*c) {
        putchar(*c);
        c++;
    }
}

void print_num(u64 i, int base) {
    char* string = format(i, example_str, base);
    print_str(string);
}

void logo(void) {
    print_str("\n ________    ________    ___");
    print_str("\n/        \\  /        \\  /   \\                  ___");
    print_str("\n|         \\/         |  \\___/   _______       /   \\");
    print_str("\n|                    |   ___   /       \\   ___|   |___");
    print_str("\n|     |\\      /|     |  /   \\  |   ____/  /           \\");
    print_str("\n|     | \\    / |     |  |   |  \\    \\     \\___     ___/");
    print_str("\n|     |  \\__/  |     |  |   |    \\    \\       |   |");
    print_str("\n|     |        |     |  |   |   ___\\   |      |   |_");
    print_str("\n|     |        |     |  |   |  /       |      |     \\ ");
    print_str("\n\\_____/        \\_____/  \\___/  \\_______/      \\_____/");

}
