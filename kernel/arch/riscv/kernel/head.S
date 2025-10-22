#include "private_kdefs.h"

    .section .text.init
    .globl _start
_start:
    # log 需要使用 tp，但 init_task 的 tp 又是动态分配的这会儿没法加载
    # 这里会指向 OpenSBI 的 task local stack，因此置为 0 值
    # 下一年应该和 Linux 一样把 init_task 写成静态，一开始就加载
    mv tp, x0

    /* Lab1 Task1 */

    /* Lab1 Task3 */

    /* Lab3 Task1 */
    call setup_vm
    call relocate

    # init memory
    call mm_init

    /* Lab3 Task2 */
    call setup_vm_final

    /* Lab2 Test1 */
    call test_list

    /* Lab2 Task2 */
    # init task
    call task_init

    tail start_kernel

relocate:
    /* Lab3 Task1 */

    ret

    .section .bss.stack
    .space PGSIZE
