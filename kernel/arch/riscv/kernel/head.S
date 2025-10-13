#include "private_kdefs.h"

    .section .text.init
    .globl _start
_start:

    /* Lab1 Task1 */

    # init memory
    call mm_init

    /* Lab1 Task3 */

    call test_list

    /* Lab2 Task2 */
    # init task
    call task_init

    tail start_kernel

    .section .bss.stack
    .space PGSIZE
