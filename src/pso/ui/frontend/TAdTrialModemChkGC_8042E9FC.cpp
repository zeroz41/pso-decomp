#include "types.h"
#include "pso/unk/SharedMemory.h"
#include "pso/unk/ResetConnectParam.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/network/eth.h"
#include <stdio.h>
#include <string.h>
#include "pso/network/ModemRuntime.h"

// ntUtl library banner; init_shared_memory publishes it in shared_memory_version.
// inferred: name from the string.
static const char *const ntutl_version = "\nntUtl Ver 1.16.00 Build:Jul  8 2002 11:37:47\n";

// The shared-memory pointers set up by init_shared_memory (SharedMemory.h).
LaunchDolContext *launch_dol_context;
const char *shared_memory_version;
SharedMemoryDiscMessages *shared_memory_disc_messages;
u8 *lbl_805D7CBC;
SharedMemory *shared_memory_block;
SharedMemoryConnectParam *shared_memory_connect_param;

extern "C" {
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
// symbol stays local, as the original object declares it.  Only CodeWarrior's
// object holds the words: nothing reaches them, so no other compiler needs them.
#ifdef __MWERKS__
#pragma push
#pragma force_active on
static asm void pad_03_8042E9FC_text(void) {
#include "orig_asm/pso/ui/frontend/TAdTrialModemChkGC_8042E9FC/pad_03_8042E9FC_text.inc"
}
#pragma pop
#endif

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 init_modem_check_params() {
    return reset_connect_param("Shared Memory Connect Parameter");
}
#pragma pop

}

// Dead-stripped from the DOL: no code of it survives, only its strings
// (0x80480290-0x80480403 of this unit's string pool, between
// init_modem_check_params' and launch_iwanaga_dol's): the ISAO trial service's
// access number and domain and its file:/isao/caseN pages (no case3). What it
// did with them is not known, so this body only hands them out in pool order.
// inferred: name from the strings.
void get_isao_trial_params(const char **number, const char **domain, const char **pages) {
    *number = "0120-53-5850";
    *domain = "isao.net";
    pages[0] = "file:/isao/case1/cid_rst.htm";
    pages[1] = "file:/isao/case2/cidselct.htm";
    pages[2] = "file:/isao/case4s/menu.htm";
    pages[3] = "file:/isao/case4/menu.htm";
    pages[4] = "file:/isao/case5/menu.htm";
    pages[5] = "file:/isao/case6/menu.htm";
    pages[6] = "file:/isao/case7/menu.htm";
    pages[7] = "file:/isao/case8s/menu.htm";
    pages[8] = "file:/isao/case8/menu.htm";
    pages[9] = "file:/isao/case9/menu.htm";
    pages[10] = "file:/isao/case10/menu.htm";
    pages[11] = "file:/isao/case11/menu.htm";
}

#pragma push
#pragma optimize_for_size off
s32 set_shared_memory_data(u8 *src, u32 size) {
    u8 *dst;
    u32 i;
    if ((s32) shared_memory_ready == 0) {
        return -1;
    }
    if (size > 0x800U) {
        return -2;
    }
    dst = shared_memory_block->data;
    for (i = size; i != 0; i--) {
        *dst++ = *src++;
    }
    shared_memory_block->data_size = size;
    shared_memory_block->flags |= SHARED_MEMORY_DATA_SET;
    return 0;
}
#pragma pop

#pragma push
#pragma optimize_for_size off
void launch_iwanaga_dol(DolHeader *dol_image, s32 param) {
    strcpy(launch_dol_context->dol_name, "iwanaga.dol");
    launch_dol_context->unk_100 = param;
    launch_dol_context->dol_image = dol_image;
    launch_dol_context->keep_size = sizeof(SharedMemory);
    LaunchDol(launch_dol_context);
}
#pragma pop

#pragma push
#pragma optimize_for_size off
#pragma dont_inline off
#pragma inline_depth(4)
void init_shared_memory(void) {
    SharedMemory *p;
    shared_memory_version = ntutl_version;
    if ((s32) shared_memory_ready == 0) {
        launch_dol_context = get_launch_dol_context();
        p = &(*(LaunchDolContext *volatile *) &launch_dol_context)->shared_memory;
        shared_memory_ready = 1;
        shared_memory_block = p;
        shared_memory_connect_param = &p->connect_param;
        lbl_805D7CBC = p->unk_6820;
        shared_memory_disc_messages = &p->disc_messages;
        if (p->magic == SHARED_MEMORY_MAGIC) {
            return;
        }
        memset(p, 0, sizeof(SharedMemory));
        shared_memory_block->magic = SHARED_MEMORY_MAGIC;
        shared_memory_block->flags = 0x40;
        reset_connect_param("Shared Memory Connect Parameter");
        // "The disc cover is open. To continue the game, close the disc cover."
        set_disc_error_message(0, "\x83" "f\x83" "B\x83X\x83N\x83J\x83o\x81[\x82\xAA\x8AJ\x82\xA2\x82\xC4\x82\xA2\x82\xDC\x82\xB7\n"
                       "\x83Q\x81[\x83\x80\x82\xF0\x91\xB1\x82\xAF\x82\xE9\x8F\xEA\x8D\x87\x82\xCD\x83" "f\x83" "B\x83X\x83N\x83J\x83o\x81[\x82\xF0\x95\xC2\x82\xDF\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2");
        // "Please insert the <set the game name> disc."
        set_disc_error_message(1, "<\x83Q\x81[\x83\x80\x96\xBC\x82\xF0\x90\xDD\x92\xE8\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2>\n"
                       "\x82\xCC\x83" "f\x83" "B\x83X\x83N\x82\xF0\x83Z\x83" "b\x83g\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2");
        // "This disc is not the <set the game name> disc. Please insert the <set the game name> disc."
        set_disc_error_message(2, "\x82\xB1\x82\xCC\x83" "f\x83" "B\x83X\x83N\x82\xCD\n"
                       "<\x83Q\x81[\x83\x80\x96\xBC\x82\xF0\x90\xDD\x92\xE8\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2>\n"
                       "\x82\xCC\x83" "f\x83" "B\x83X\x83N\x82\xC5\x82\xCD\x82\xA0\x82\xE8\x82\xDC\x82\xB9\x82\xF1\n"
                       "<\x83Q\x81[\x83\x80\x96\xBC\x82\xF0\x90\xDD\x92\xE8\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2>\n"
                       "\x82\xCC\x83" "f\x83" "B\x83X\x83N\x82\xF0\x83Z\x83" "b\x83g\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2");
        // "The disc could not be read. See the console's instruction manual for details."
        set_disc_error_message(3, "\x83" "f\x83" "B\x83X\x83N\x82\xF0\x93\xC7\x82\xDF\x82\xDC\x82\xB9\x82\xF1\x82\xC5\x82\xB5\x82\xBD\n"
                       "\x8F\xDA\x82\xB5\x82\xAD\x82\xCD\x96{\x91\xCC\x82\xCC\x8E\xE6\x88\xB5\x90\xE0\x96\xBE\x8F\x91\x82\xF0\x82\xA8\x93\xC7\x82\xDD\x82\xAD\x82\xBE\x82\xB3\x82\xA2");
        // "An error has occurred. Press the power button to turn the power OFF and follow the console's instruction manual."
        set_disc_error_message(4, "\x83G\x83\x89\x81[\x82\xAA\x94\xAD\x90\xB6\x82\xB5\x82\xDC\x82\xB5\x82\xBD\n"
                       "\x96{\x91\xCC\x82\xCC\x83p\x83\x8F\x81[\x83{\x83^\x83\x93\x82\xF0\x89\x9F\x82\xB5\x82\xC4\x93" "d\x8C\xB9\x82\xF0OFF\x82\xC9\x82\xB5\n"
                       "\x96{\x91\xCC\x82\xCC\x8E\xE6\x88\xB5\x90\xE0\x96\xBE\x8F\x91\x82\xCC\x8Ew\x8E\xA6\x82\xC9\x8F]\x82\xC1\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2");
    }
}
#pragma pop

#pragma push
#pragma optimize_for_size off
s32 set_disc_error_message(s32 index, const char *message) {
    s32 ret = 0;
    if (shared_memory_ready == 0) {
        return -1;
    }
    if (index < 0 || index > 4) {
        return -2;
    }
    memset(shared_memory_disc_messages->message[index], 0, sizeof(shared_memory_disc_messages->message[index]));
    strncpy(shared_memory_disc_messages->message[index], message, sizeof(shared_memory_disc_messages->message[index]) - 1);
    if (strlen(message) >= 0x100) {
        ret = -2;
    }
    return ret;
}
#pragma pop
extern "C" {

s32 EXIGetType(int, int, void *);
}
u32 lbl_805D7CC8;

s32 get_network_adapter_type(s32 *out_type) {
    s32 adapter_type;
    if (lbl_805D7CC8 == 2U) {
        *out_type = 2;
        goto block_18;
    }
    if (lbl_805D7CC8 == 5U) {
        *out_type = 5;
        goto block_18;
    }
    if (EXIGetType(0, 2, &adapter_type) != 0) {
        switch (adapter_type) {
        case -1:
            *out_type = 0;
            break;
        case 33685504:
            *out_type = 2;
            lbl_805D7CC8 = 2U;
            break;
        case 67240448:
            if (exi_read_status_byte() == 0U) {
                *out_type = 5;
                lbl_805D7CC8 = 5U;
            } else {
                *out_type = 1;
            }
            break;
        default:
            *out_type = 1;
            break;
        }
    } else {
        return -5;
    }
block_18:
    return 0;
}


s32 fn_8042EF48(s8 value) {
    if ((s32) shared_memory_ready == 0) {
        return -1;
    }
    shared_memory_disc_messages->unk_000 = value;
    shared_memory_block->flags |= SHARED_MEMORY_DISC_MESSAGES_SET;
    return 0;
}

s32 set_modem_check_param_360(s8 value) {
    if ((s32) shared_memory_ready == 0) {
        return -1;
    }
    shared_memory_connect_param->check_param_360 = value;
    shared_memory_block->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_param(s16 value) {
    if ((s32) shared_memory_ready == 0) {
        return -1;
    }
    shared_memory_connect_param->modem_param = value;
    shared_memory_block->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_check_char(s8 value) {
    if ((s32) shared_memory_ready == 0) {
        return -1;
    }
    shared_memory_connect_param->check_char = value;
    shared_memory_block->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_flag(s8 value) {
    if ((s32) shared_memory_ready == 0) {
        return -1;
    }
    shared_memory_connect_param->modem_flag = value;
    shared_memory_block->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_check_param(s32 value) {
    if ((s32) shared_memory_ready == 0) {
        return -1;
    }
    shared_memory_connect_param->check_param = value;
    shared_memory_block->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 TAdTrialModemChkGC__sub_8042F080(s16 value) {
    shared_memory_connect_param->unk_1C2 = value;
    shared_memory_block->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 set_modem_trial_param(s16 value) {
    if ((s32) shared_memory_ready == 0) {
        return -1;
    }
    shared_memory_connect_param->trial_param = value;
    shared_memory_block->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 TAdTrialModemChkGC__sub_8042F0D4(s8 value) {
    if ((s32) shared_memory_ready == 0) {
        return -1;
    }
    shared_memory_connect_param->unk_13D = value;
    shared_memory_block->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}

s32 ntUtlExSetDialType(s8 value) {
    if ((s32) shared_memory_ready == 0) {
        return -1;
    }
    shared_memory_connect_param->dial_type = value;
    shared_memory_block->flags |= SHARED_MEMORY_CONNECT_PARAM_SET;
    return 0;
}
