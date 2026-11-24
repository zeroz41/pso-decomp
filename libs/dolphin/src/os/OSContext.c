#include <dolphin/dolphin.h>
#include <dolphin/os.h>

#include "os/__os.h"


#define HID2 920

volatile OSContext* __OSCurrentContext AT_ADDRESS(OS_BASE_CACHED | 0x00D4);
volatile OSContext* __OSFPUContext AT_ADDRESS(OS_BASE_CACHED | 0x00D8);

#ifdef __GEKKO__
static asm void __OSLoadFPUContext(__REGISTER u32 dummy, __REGISTER OSContext* fpucontext) {
#include "orig_asm/os/OSContext/__OSLoadFPUContext.inc"
}

static asm void __OSSaveFPUContext(__REGISTER u32 dummy1, __REGISTER u32 dummy2, __REGISTER OSContext* fpucontext) {
#include "orig_asm/os/OSContext/__OSSaveFPUContext.inc"
}

asm void OSSetCurrentContext(__REGISTER OSContext* context) {
#include "orig_asm/os/OSContext/OSSetCurrentContext.inc"
}
#endif

OSContext* OSGetCurrentContext(void) {
    return (OSContext*)__OSCurrentContext;
}

#ifdef __GEKKO__
asm u32 OSSaveContext(__REGISTER OSContext* context) {
#include "orig_asm/os/OSContext/OSSaveContext.inc"
}

asm void OSLoadContext(__REGISTER OSContext* context) {
#include "orig_asm/os/OSContext/OSLoadContext.inc"
}

asm u32 OSGetStackPointer() {
#include "orig_asm/os/OSContext/OSGetStackPointer.inc"
}

#endif

void OSClearContext(__REGISTER OSContext* context) {
    context->mode = 0;
    context->state = 0;
    if (context == __OSFPUContext)
        __OSFPUContext = NULL;
}

#ifdef __GEKKO__
asm void OSInitContext(__REGISTER OSContext* context, __REGISTER u32 pc, __REGISTER u32 newsp) {
#include "orig_asm/os/OSContext/OSInitContext.inc"
}
#endif

void OSDumpContext(OSContext* context) {
    u32 i;
    u32* p;

    OSReport("------------------------- Context 0x%08x -------------------------\n", context);

    for (i = 0; i < 16; ++i) {
        OSReport("r%-2d  = 0x%08x (%14d)  r%-2d  = 0x%08x (%14d)\n", i, context->gpr[i],
                context->gpr[i], i + 16, context->gpr[i + 16], context->gpr[i + 16]);
    }

    OSReport("LR   = 0x%08x                   CR   = 0x%08x\n", context->lr, context->cr);
    OSReport("SRR0 = 0x%08x                   SRR1 = 0x%08x\n", context->srr0, context->srr1);

    OSReport("\nGQRs----------\n");
    for (i = 0; i < 4; ++i) {
        OSReport("gqr%d = 0x%08x \t gqr%d = 0x%08x\n", i, context->gqr[i], i + 4, context->gqr[i + 4]);
    }

    if (context->state & OS_CONTEXT_STATE_FPSAVED) {
        OSContext* currentContext;
        OSContext fpucontext;
        BOOL enabled;

        enabled = OSDisableInterrupts();
        currentContext = OSGetCurrentContext();
        OSClearContext(&fpucontext);
        OSSetCurrentContext(&fpucontext);

        OSReport("\n\nFPRs----------\n");
        for (i = 0; i < 32; i += 2) {
            OSReport("fr%d \t= %d \t fr%d \t= %d\n", i, (u32)context->fpr[i], i + 1,
                    (u32)context->fpr[i + 1]);
        }
        OSReport("\n\nPSFs----------\n");
        for (i = 0; i < 32; i += 2) {
            OSReport("ps%d \t= 0x%x \t ps%d \t= 0x%x\n", i, (u32)context->psf[i], i + 1,
                    (u32)context->psf[i + 1]);
        }

        OSClearContext(&fpucontext);
        OSSetCurrentContext(currentContext);
        OSRestoreInterrupts(enabled);
    }

    OSReport("\nAddress:      Back Chain    LR Save\n");
    for (i = 0, p = (u32*)context->gpr[1]; p && (u32)p != 0xffffffff && i++ < 16; p = (u32*)*p) {
        OSReport("0x%08x:   0x%08x    0x%08x\n", p, p[0], p[1]);
    }
}

#ifdef __GEKKO__
static asm void OSSwitchFPUContext(__REGISTER __OSException exception, __REGISTER OSContext* context) {
#include "orig_asm/os/OSContext/OSSwitchFPUContext.inc"
}
#endif

void __OSContextInit(void) {
    __OSSetExceptionHandler(__OS_EXCEPTION_FLOATING_POINT, OSSwitchFPUContext);
    __OSFPUContext = NULL;
    DBPrintf("FPU-unavailable handler installed\n");
}
