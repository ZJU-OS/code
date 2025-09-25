#include <stdint.h>
#include <printk.h>
#include <sbi.h>
#include <private_kdefs.h>

// convenient macro to generate scause
#define __SCAUSE(is_intr, code) \
	((uint64_t)(is_intr) << (8 * sizeof(uint64_t) - 1) | (code))

// Supervisor software interrupt
#define SCAUSE_SSI __SCAUSE(1, 1)
// Supervisor timer interrupt
#define SCAUSE_STI __SCAUSE(1, 5)
// Supervisor external interrupt
#define SCAUSE_SEI __SCAUSE(1, 9)

// Instruction address misaligned
#define SCAUSE_IADDR_MISALIGNED __SCAUSE(0, 0)
// Instruction access fault
#define SCAUSE_IADDR_FAULT __SCAUSE(0, 1)
// Illegal instruction
#define SCAUSE_II __SCAUSE(0, 2)
// Breakpoint
#define SCAUSE_BREAKPOINT __SCAUSE(0, 3)
// Load address misaligned
#define SCAUSE_LADDR_MISALIGNED __SCAUSE(0, 4)
// Load access fault
#define SCAUSE_LADDR_FAULT __SCAUSE(0, 5)
// Store/AMO address misaligned
#define SCAUSE_SADDR_MISALIGNED __SCAUSE(0, 6)
// Store/AMO access fault
#define SCAUSE_SADDR_FAULT __SCAUSE(0, 7)
// Environment call from U-mode
#define SCAUSE_ECALL_U __SCAUSE(0, 8)
// Environment call from S-mode
#define SCAUSE_ECALL_S __SCAUSE(0, 9)
// Instruction page fault
#define SCAUSE_IPF __SCAUSE(0, 12)
// Load page fault
#define SCAUSE_LPF __SCAUSE(0, 13)
// Store/AMO page fault
#define SCAUSE_SPF __SCAUSE(0, 15)

static const char *scause_str(uint64_t scause)
{
	switch (scause) {
	case SCAUSE_SSI:
		return "Supervisor software interrupt";
	case SCAUSE_STI:
		return "Supervisor timer interrupt";
	case SCAUSE_SEI:
		return "Supervisor external interrupt";
	case SCAUSE_IADDR_MISALIGNED:
		return "Instruction address misaligned";
	case SCAUSE_IADDR_FAULT:
		return "Instruction access fault";
	case SCAUSE_II:
		return "Illegal instruction";
	case SCAUSE_BREAKPOINT:
		return "Breakpoint";
	case SCAUSE_LADDR_MISALIGNED:
		return "Load address misaligned";
	case SCAUSE_LADDR_FAULT:
		return "Load access fault";
	case SCAUSE_SADDR_MISALIGNED:
		return "Store/AMO address misaligned";
	case SCAUSE_SADDR_FAULT:
		return "Store/AMO access fault";
	case SCAUSE_ECALL_U:
		return "Environment call from U-mode";
	case SCAUSE_ECALL_S:
		return "Environment call from S-mode";
	case SCAUSE_IPF:
		return "Instruction page fault";
	case SCAUSE_LPF:
		return "Load page fault";
	case SCAUSE_SPF:
		return "Store/AMO page fault";
	default:
		return "Unknown";
	}
}

void clock_set_next_event(void) {
	/* Lab1 Task4 */
};

void clear_ssip(void)
{
	/* Lab1 Task3 */
}

void trap_handler(uint64_t sepc, uint64_t scause, uint64_t stval)
{
	switch (scause) {
	/* Lab1 Task4 */
	default:
		printk("\x1b[45m[S]\x1b[1;31;49m Unhandled trap: scause = \x1b[33m%s (0x%" PRIx64
		       ")\x1b[31m, "
		       "sepc = \x1b[33m0x%" PRIx64
		       "\x1b[31m, stval = \x1b[33m0x%" PRIx64 "\x1b[0m\n",
		       scause_str(scause), scause, sepc, stval);
		/* sbi_system_reset(SBI_SRST_RESET_TYPE_SHUTDOWN,
				 SBI_SRST_RESET_REASON_SYSTEM_FAILURE); */
	}
}
