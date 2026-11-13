#include "types.h"
#include "pso/unk/SharedMemory.h"
#include "pso/unk/ResetConnectParam.h"
#include "pso/unk/text_8042EE4C.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/unk/text_8042EAD4.h"
#include "pso/network/TLobby_80429598.h"
#include <stdio.h>
#include <string.h>

// The shared-memory pointers set up by TAdTrialModemChkGC__sub_8042EC14 (SharedMemory.h).
LaunchDolContext *lbl_805D7CB0;
u32 lbl_805D7CB4;
SharedMemoryDiscMessages *lbl_805D7CB8;
u8 *lbl_805D7CBC;
SharedMemory *lbl_805D7CC0;
SharedMemoryConnectParam *lbl_805D7CC4;

extern "C" {
extern char lbl_80480270[];

// pad_03_8042E9FC_text: the frame-restore epilogue of the reset relocator
// fn_8042E8C4 (previous unit).  That function leaves through an epilogue-free
// computed jump (lwz r0,0xE0(r26); isync; mtlr r0; blr), but the compiler
// still emitted the lmw/mtlr/addi/blr restore after it; the split boundary at
// 0x8042E9FC drops those 5 words into this unit as an unclaimed code gap.  No
// C construct can produce an epilogue with no prologue: probed every installed
// MWCC in build/compilers/GC/ (20 versions, unit profile -O4,p -inline off
// -use_lmw_stmw on -lang=c++): an empty function gives `blr` (0x4), a
// callee-register-hungry function gives prologue+stmw+epilogue (0x50), and
// statement-level asm is wrapped in its own frame (0x28..0x30).  0/20 emit the
// 20 bytes; the function-level asm body (generated from the original
// disassembly by tools/orig_asm.py) is byte-exact on 20/20.  force_active: nothing
// calls it, so the linker would strip it.  `static` so the
// symbol stays local, as the original object declares it.
#pragma push
#pragma force_active on
static asm void pad_03_8042E9FC_text(void) {
#include "orig_asm/pso/ui/frontend/TAdTrialModemChkGC_8042E9FC/pad_03_8042E9FC_text.inc"
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TAdTrialModemChkGC::init_modem_check_params() {
    return reset_connect_param(lbl_80480270);
}
#pragma pop

}

extern "C" {
extern char lbl_80480404[];
s32 fn_8042E8B8(void);
extern char lbl_80480240[];
extern const s32 lbl_805E11F0;

#pragma push
#pragma optimize_for_size off
s32 fn_8042EAD4(u8 *arg0, u32 arg1) {
    u8 *dst;
    u32 i;
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    if (arg1 > 0x800U) {
        return -2;
    }
    dst = lbl_805D7CC0->data;
    for (i = arg1; i != 0; i--) {
        *dst++ = *arg0++;
    }
    lbl_805D7CC0->data_size = arg1;
    lbl_805D7CC0->flags |= SHARED_MEMORY_DATA_SET;
    return 0;
}
#pragma pop

#pragma push
#pragma optimize_for_size off
void fn_8042EBA4(DolHeader *dol_image, s32 arg1) {
    strcpy(lbl_805D7CB0->dol_name, lbl_80480404);
    lbl_805D7CB0->unk_100 = arg1;
    lbl_805D7CB0->dol_image = dol_image;
    lbl_805D7CB0->keep_size = sizeof(SharedMemory);
    LaunchDol(lbl_805D7CB0);
}
#pragma pop

#pragma push
#pragma optimize_for_size off
#pragma dont_inline off
#pragma inline_depth(4)
void TAdTrialModemChkGC__sub_8042EC14(void) {
    SharedMemory *p;
    char *msgs = lbl_80480240;
    lbl_805D7CB4 = lbl_805E11F0;
    if ((s32) lbl_805D7CA8 == 0) {
        lbl_805D7CB0 = (LaunchDolContext *) fn_8042E8B8();
        p = &(*(LaunchDolContext *volatile *) &lbl_805D7CB0)->shared_memory;
        lbl_805D7CA8 = 1;
        lbl_805D7CC0 = p;
        lbl_805D7CC4 = &p->connect_param;
        lbl_805D7CBC = p->unk_6820;
        lbl_805D7CB8 = &p->disc_messages;
        if (p->magic == SHARED_MEMORY_MAGIC) {
            return;
        }
        memset(p, 0, sizeof(SharedMemory));
        lbl_805D7CC0->magic = SHARED_MEMORY_MAGIC;
        lbl_805D7CC0->flags = 0x40;
        reset_connect_param(msgs + 0x30);
        fn_8042ED98(0, msgs + 0x1D0);
        fn_8042ED98(1, msgs + 0x220);
        fn_8042ED98(2, msgs + 0x25C);
        fn_8042ED98(3, msgs + 0x2E0);
        fn_8042ED98(4, msgs + 0x324);
    }
}
#pragma pop

#pragma push
#pragma optimize_for_size off
s32 fn_8042ED98(s32 arg0, const char *arg1) {
    s32 ret = 0;
    if (lbl_805D7CA8 == 0) {
        return -1;
    }
    if (arg0 < 0 || arg0 > 4) {
        return -2;
    }
    memset(lbl_805D7CB8->message[arg0], 0, sizeof(lbl_805D7CB8->message[arg0]));
    strncpy(lbl_805D7CB8->message[arg0], arg1, sizeof(lbl_805D7CB8->message[arg0]) - 1);
    if (strlen(arg1) >= 0x100) {
        ret = -2;
    }
    return ret;
}
#pragma pop

}

extern "C" {
s32 EXIGetType(int, int, void *);
u32 lbl_805D7CC8;

s32 TLobby__sub_8042EE4C(s32 *arg0) {
    s32 sp8;
    if ((u32) lbl_805D7CC8 == 2U) {
        *arg0 = 2;
        goto block_18;
    }
    if ((u32) lbl_805D7CC8 == 5U) {
        *arg0 = 5;
        goto block_18;
    }
    if (EXIGetType(0, 2, &sp8) != 0) {
        switch (sp8) {
        case -1:
            *arg0 = 0;
            break;
        case 33685504:
            *arg0 = 2;
            lbl_805D7CC8 = 2U;
            break;
        case 67240448:
            if (exi_read_status_byte() == 0U) {
                *arg0 = 5;
                lbl_805D7CC8 = 5U;
            } else {
                *arg0 = 1;
            }
            break;
        default:
            *arg0 = 1;
            break;
        }
    } else {
        return -5;
    }
block_18:
    return 0;
}

s32 fn_8042EF48(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CB8->unk_000 = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_DISC_MESSAGES_SET;
    return 0;
}
}

s32 set_modem_check_param_360(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->check_param_360 = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_param(s16 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->modem_param = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_check_char(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->check_char = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_flag(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->modem_flag = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_check_param(s32 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->check_param = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 TAdTrialModemChkGC__sub_8042F080(s16 arg0) {
    lbl_805D7CC4->unk_1C2 = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_trial_param(s16 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->trial_param = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 TAdTrialModemChkGC__sub_8042F0D4(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->unk_13D = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 TAdPlayerLoadGC__sub_8042F108(s8 arg0) {
    if ((s32) lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CC4->unk_13C = arg0;
    lbl_805D7CC0->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}
