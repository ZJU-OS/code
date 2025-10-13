#include "private_kdefs.h"
#include "csr.h"
#include "proc.h"
    .section .text.entry
    .align 2
    .globl _traps
_traps:

    /* Lab1 Task3 */

    call trap_handler

    /* Lab1 Task3 */

    sret

    .globl __switch_to
__switch_to:
    sd ra, OFFSETOF_TS_THREAD+0*8(a0)
    sd sp, OFFSETOF_TS_THREAD+1*8(a0)
    sd s0, OFFSETOF_TS_THREAD+2*8(a0)
    sd s1, OFFSETOF_TS_THREAD+3*8(a0)
    sd s2, OFFSETOF_TS_THREAD+4*8(a0)
    sd s3, OFFSETOF_TS_THREAD+5*8(a0)
    sd s4, OFFSETOF_TS_THREAD+6*8(a0)
    sd s5, OFFSETOF_TS_THREAD+7*8(a0)
    sd s6, OFFSETOF_TS_THREAD+8*8(a0)
    sd s7, OFFSETOF_TS_THREAD+9*8(a0)
    sd s8, OFFSETOF_TS_THREAD+10*8(a0)
    sd s9, OFFSETOF_TS_THREAD+11*8(a0)
    sd s10, OFFSETOF_TS_THREAD+12*8(a0)
    sd s11, OFFSETOF_TS_THREAD+13*8(a0)

    ld s11, OFFSETOF_TS_THREAD+13*8(a1)
    ld s10, OFFSETOF_TS_THREAD+12*8(a1)
    ld s9, OFFSETOF_TS_THREAD+11*8(a1)
    ld s8, OFFSETOF_TS_THREAD+10*8(a1)
    ld s7, OFFSETOF_TS_THREAD+9*8(a1)
    ld s6, OFFSETOF_TS_THREAD+8*8(a1)
    ld s5, OFFSETOF_TS_THREAD+7*8(a1)
    ld s4, OFFSETOF_TS_THREAD+6*8(a1)
    ld s3, OFFSETOF_TS_THREAD+5*8(a1)
    ld s2, OFFSETOF_TS_THREAD+4*8(a1)
    ld s1, OFFSETOF_TS_THREAD+3*8(a1)
    ld s0, OFFSETOF_TS_THREAD+2*8(a1)
    ld sp, OFFSETOF_TS_THREAD+1*8(a1)
    ld ra, OFFSETOF_TS_THREAD+0*8(a1)
    
    mv tp, a1

    ret

    .globl __kthread
__kthread:
    csrs sstatus, SSTATUS_SIE
    mv ra, s0
    mv a0, s1
    ret
