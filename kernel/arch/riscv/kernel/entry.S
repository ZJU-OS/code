#include "private_kdefs.h"
    .section .text.entry
    .align 2
    .globl _traps
_traps:

    /* Lab1 Task3 */

    call trap_handler

    /* Lab1 Task3 */

    sret
