#include "mist.h"

u16 shell_y = 0;

char buffer[64];
u8 buf_pos = 0;

void exec(char* buffer) {
    if (iseq(buffer, "help", 4)) {
        print_str("\nCommands:\n - help:        shows available commands\n - clear:       clears the screen\n - reboot:      rebooting the system (Off on QEMU. Because QEMU can't restart)\n - say <input>: echo your input\n - info:        shows systems information");
    } else if (iseq(buffer, "clear", 5)) {
        clear();
    } else if (iseq(buffer, "say ", 4)) {
        putchar('\n');
        print_str(buffer + 4);
    } else if (iseq(buffer, "reboot", 6)) {
        outb(0x64, 0xFE);
    } else if (iseq(buffer, "info", 4)) {
        logo();
        print_str("\nMist v0.9");
    } else {
        print_str("\n[FAIL]: Wrong command. Type \"help\" to show all available commands");
    }
}

void shell_init(void) {
    print_str("\n> ");
    while (1) {
        char c = kbdget();
        if (c == '\b') {
            if ((shell_y == 0) && (cursor_x >= 3)) {
                delchar();
            } else if (shell_y > 0) {
                if (cursor_x == 0) {
                    delchar();
                    shell_y--;
                } else {
                    delchar();
                }
            }
            if (buf_pos >= 1) {
                buffer[buf_pos] = 0;
                buf_pos--;
                buffer[buf_pos] = '\0';
            } else {
                buffer[buf_pos] = 0;
            }
        } else if (c == '\n') {
            shell_y = 0;
            if (buf_pos != 0) {
                exec(buffer);
            }
            fill(buffer, 0, sizeof(buffer));
            buf_pos = 0;
            print_str("\n> ");
        } else if (c >= 0x20 && c <= 0x7E) {
            if (buf_pos < 64) {
                buffer[buf_pos] = c;
                buf_pos++;
                buffer[buf_pos] = '\0';
                putchar(c);
            } else {
                print_str("\n[FAIL]: Buffer overflow");
                fill(buffer, 0, sizeof(buffer));
                buf_pos = 0;
                shell_y = 0;
                print_str("\n> ");
            }
            if (cursor_x == 0) {
                shell_y++;
            }
        }
    }
}
