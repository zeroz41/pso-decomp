static int fragmentID = -2;

extern char* GetR2(void);

#ifdef __cplusplus
extern "C" {
#endif

#include "PowerPC_EABI_Support/Runtime/Inc/__ppc_eabi_linker.h"

__declspec(section ".init") extern __eti_init_info _eti_init_info[];

extern void __init_cpp_exceptions(void);
extern void __fini_cpp_exceptions(void);
extern void suspend(void);
extern void __unregister_fragment(int fragmentID);
extern int __register_fragment(void* _eti_init_info, char* TOC);
extern void __destroy_global_chain(void);

#ifdef __cplusplus
}
#endif

extern void __init_cpp_exceptions(void) {
    if (fragmentID == -2) {
        fragmentID = __register_fragment(&_eti_init_info, GetR2());
    }
}

extern void __fini_cpp_exceptions(void) {
    if (fragmentID != -2) {
        __unregister_fragment(fragmentID);
        fragmentID = -2;
    }
}

asm char* GetR2(void) {
#include "orig_asm/PowerPC_EABI_Support/Runtime/Src/__init_cpp_exceptions/GetR2__Fv.inc"
}

__declspec(section ".ctors") extern void* const __init_cpp_exceptions_reference = __init_cpp_exceptions;
__declspec(section ".dtors") extern void* const __destroy_global_chain_reference = __destroy_global_chain;
__declspec(section ".dtors") extern void* const __fini_cpp_exceptions_reference = __fini_cpp_exceptions;
