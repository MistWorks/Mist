#include "mist.h"

void __attribute__((section(".text.start"), noreturn)) main(void) {
    clear();
    logo();
    print_str("\nStarting...");

    if (!pmminit()) {
        print_str("\n[FAIL] PMM initialization");
        print_str("\n[WARN] System halted. Reboot required");
        for (;;) __asm__ volatile("hlt");
    } else {
        print_str("\n[ OK ] PMM initialization");
    }

    if (!vmminit()) {
        print_str("\n[FAIL] VMM initialization");
        print_str("\n[WARN] System halted. Reboot required");
        for (;;) __asm__ volatile("hlt");
    } else {
        print_str("\n[ OK ] VMM initialization");
    }

    if (!idtinit()) {
        print_str("\n[FAIL] IDT initialization");
        print_str("\n[WARN] System halted. Reboot required");
        for (;;) __asm__ volatile("hlt");
    } else {
        print_str("\n[ OK ] IDT initialization");
    }

    kbdinit();

    print_str("\n -- Welcome to Mist!");
    
    __asm__ volatile("sti");
    shell_init();

    for (;;) __asm__ volatile("hlt");
}
