#ifndef PSO_SDK_COMPACT_MATH
#define PSO_SDK_COMPACT_MATH 1
#endif

#include "PowerPC_EABI_Support/MetroTRK/trk.h"

#define EXCEPTIONMASK_ADDR 0x80000044

static u32 lc_base;

static u32 TRK_ISR_OFFSETS[15] = { PPC_SystemReset,
	                               PPC_MachineCheck,
	                               PPC_DataStorage,
	                               PPC_InstructionStorage,
	                               PPC_ExternalInterrupt,
	                               PPC_Alignment,
	                               PPC_Program,
	                               PPC_FloatingPointUnavaiable,
	                               PPC_Decrementer,
	                               PPC_SystemCall,
	                               PPC_Trace,
	                               PPC_PerformanceMonitor,
	                               PPC_InstructionAddressBreakpoint,
	                               PPC_SystemManagementInterrupt,
	                               PPC_ThermalManagementInterrupt };

__declspec(section ".init") void __TRK_reset()
{
	__TRK_copy_vectors();
}

asm void InitMetroTRK() {
#include "orig_asm/TRK_MINNOW_DOLPHIN/dolphin_trk/InitMetroTRK.inc"
}

void EnableMetroTRKInterrupts(void)
{
	EnableEXI2Interrupts();
}

u32 TRKTargetTranslate(u32 addr)
{
	if (addr >= lc_base) {
		if ((addr < lc_base + 0x4000) && ((gTRKCPUState.Extended1.DBAT3U_ & 3) != 0)) {
			return addr;
		}
	}

	return addr & 0x3FFFFFFF | 0x80000000;
}

void TRK_copy_vector(u32 offset)
{
	void* destPtr = (void*)TRKTargetTranslate(offset);
	TRK_memcpy(destPtr, gTRKInterruptVectorTable + offset, 0x100);
	TRK_flush_cache(destPtr, 0x100);
}

void __TRK_copy_vectors(void)
{
	int i;
	u32 mask;

	mask = *(u32*)TRKTargetTranslate(0x44);

	for (i = 0; i <= 14; ++i) {
		if (mask & (1 << i)) {
			TRK_copy_vector(TRK_ISR_OFFSETS[i]);
		}
	}
}

DSError TRKInitializeTarget()
{
	gTRKState.isStopped = TRUE;
	gTRKState.msr       = __TRK_get_MSR();
	lc_base             = 0xE0000000;
	return DS_NoError;
}
