#ifndef __VM_H__
#define __VM_H__

/** PTE 位 */
#define PTE_V 0x001
#define PTE_R 0x002
#define PTE_W 0x004
#define PTE_X 0x008
#define PTE_U 0x010
#define PTE_G 0x020
#define PTE_A 0x040
#define PTE_D 0x080
#define PTE_S 0x100
#define PTE_PPN 0x003FFFFFFFFFFC00
#define PTE_PPN2 0x003FFFFFF0000000
#define PTE_PPN1 0x000000000FF80000
#define PTE_PPN0 0x000000000007FC00

#ifndef __ASSEMBLER__

#include <private_kdefs.h>
#include <stdint.h>
/** 虚拟/物理 地址转换 */
#define VA2PA(x) ((uint64_t)(x) - PA2VA_OFFSET)
#define PA2VA(x) ((uint64_t)(x) + PA2VA_OFFSET)
/** 虚拟 地址/页帧 转换 */
#define VA2VPN0(va) (((uint64_t)(va) >> 12) & 0x1ff)
#define VA2VPN1(va) (((uint64_t)(va) >> 21) & 0x1ff)
#define VA2VPN2(va) (((uint64_t)(va) >> 30) & 0x1ff)
/** 物理 地址/页帧 转换 */
#define SATP_PA2PPN(pa) (((uint64_t)(pa) >> 12))
#define PTE_PA2PPN(pa) (((uint64_t)(pa) >> 2) & PTE_PPN)
#define PTE_PA2PPN2(pa) (((uint64_t)(pa) >> 2) & PTE_PPN2)
#define PTE_PA2PPN1(pa) (((uint64_t)(pa) >> 2) & PTE_PPN1)
#define PTE_PA2PPN0(pa) (((uint64_t)(pa) >> 2) & PTE_PPN0)

/**
 * @brief 设置 early_pg_dir 页表
 *
 * @return 待设置的 SATP 值
 */
uint64_t setup_vm(void);

/**
 * @brief 设置 swapper_pg_dir 页表
 *
 * @return 待设置的 SATP 值
 */
uint64_t setup_vm_final(void);

/**
 * @brief 创建多级页表映射关系
 *
 * 在指定的一段虚拟内存 va 创建映射关系，将其映射到物理内存 pa
 *
 * @param pgtbl 根页表的基地址
 * @param va 虚拟地址
 * @param pa 物理地址
 * @param sz 映射的大小
 * @param perm 映射的读写权限
 */
void create_mapping(uint64_t pgtbl[static PGSIZE / 8], void *va, void *pa,
		    uint64_t sz, uint64_t perm);

#endif // __ASSEMBLER__

#endif
