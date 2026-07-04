# Kernel
I don't know what to say here. This is Mist's kernel

## Tools
Now here is:
- PMM
- VMM
- IDT

### PMM
They are in PMM.c:

|Name                                         |What it does                                                                  |
|:-------------------------------------------:|:-----------------------------------------------------------------------------|
|`pmminit()`                                 |Inits the PMM                                                                 |
|`pmmalloc()`                                    |Gives addresses of free page with lowest address                              |
|`pmmfree(addr of page)`                     |Clear status of given page                                                    |

## VMM
They are in VMM.c:

|Name                                              |What it does                                                    |
|:------------------------------------------------:|:---------------------------------------------------------------|
|`vmminit()`                                      |Initializes VMM, reads kernel PML4 from `CR3`, reserves slot `0`|
|`vmmproc()`                            |Creates new PML4 for process, copies kernel mappings, returns ID|
|`vmmmap(int id, u64 virt, u64 phys, u64 flags)`|Maps virtual page to physical frame, creates tables if needed   |
|`ptswitch(int ptid)`                             |Switches address space by loading PML4 into `CR3`               |

## IDT
They are in IDT.c:

|Name                                                     |What it does                         |
|:-------------------------------------------------------:|:------------------------------------|
|`idtinit(void)`                                         |Initializes IDT                      |
|`isrhandler(u8 vector, u64 error_code)`                 |Handles interrupts with given vector |
|`idtgate(u8 vector, void* handler, u8 type, u8 dpl)`|Sets up a handler with standard type |
|Entire `isr_stub.asm`                                    |Provides assembly stubs for every ISR|
