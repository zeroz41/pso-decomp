typedef struct PTMF {
	long this_delta;
	long v_offset;
	union {
		void* f_addr;
		long ve_offset;
	} f_data;
} PTMF;

const PTMF __ptmf_null = { 0, 0, 0 };

long __ptmf_test(PTMF* ptmf);
void __ptmf_scall(...);

asm long __ptmf_test(register PTMF* ptmf) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/ptmf/__ptmf_test.inc"
}

asm void __ptmf_scall(...) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/ptmf/__ptmf_scall.inc"
}
