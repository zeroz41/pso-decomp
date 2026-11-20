#include "types.h"
#include "versions.h"
#include "pso/unk/SharedMemory.h"
#include "pso/unk/ResetConnectParam.h"
#include "pso/unk/text_8042EE4C.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"
#include "pso/unk/text_8042EAD4.h"
#include "pso/network/TLobby_80429598.h"
#include <stdio.h>
#include <string.h>

// ntUtl library banner; TAdTrialModemChkGC__sub_8042EC14 publishes it in lbl_805D7CB4.
// inferred: name from the string.
#if VERSION == VERSION_GPOP8P
static const char *const ntutl_version = "\nntUtl Ver 1.20.01 Build:Dec 10 2002 16:40:01\n";
#else
static const char *const ntutl_version = "\nntUtl Ver 1.16.00 Build:Jul  8 2002 11:37:47\n";
#endif

// The shared-memory pointers set up by TAdTrialModemChkGC__sub_8042EC14 (SharedMemory.h).
LaunchDolContext *lbl_805D7CB0;
const char *lbl_805D7CB4;
SharedMemoryDiscMessages *lbl_805D7CB8;
u8 *lbl_805D7CBC;
SharedMemory *lbl_805D7CC0;
SharedMemoryConnectParam *lbl_805D7CC4;

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
// symbol stays local, as the original object declares it.
#if VERSION == VERSION_GPOP8P
#define pad_03_8042E9FC_text pad_03_8042DA08_text
#endif
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
    return reset_connect_param("Shared Memory Connect Parameter");
}
#pragma pop

}

// Dead-stripped from the DOL: no code of it survives, only its strings
// (0x80480290-0x80480403 of this unit's string pool, between
// init_modem_check_params' and fn_8042EBA4's): the ISAO trial service's
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

extern "C" {
s32 fn_8042E8B8(void);

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
    strcpy(lbl_805D7CB0->dol_name, "iwanaga.dol");
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
    lbl_805D7CB4 = ntutl_version;
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
        reset_connect_param("Shared Memory Connect Parameter");
        // "The disc cover is open. To continue the game, close the disc cover."
        fn_8042ED98(0, "\x83" "f\x83" "B\x83X\x83N\x83J\x83o\x81[\x82\xAA\x8AJ\x82\xA2\x82\xC4\x82\xA2\x82\xDC\x82\xB7\n"
                       "\x83Q\x81[\x83\x80\x82\xF0\x91\xB1\x82\xAF\x82\xE9\x8F\xEA\x8D\x87\x82\xCD\x83" "f\x83" "B\x83X\x83N\x83J\x83o\x81[\x82\xF0\x95\xC2\x82\xDF\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2");
        // "Please insert the <set the game name> disc."
        fn_8042ED98(1, "<\x83Q\x81[\x83\x80\x96\xBC\x82\xF0\x90\xDD\x92\xE8\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2>\n"
                       "\x82\xCC\x83" "f\x83" "B\x83X\x83N\x82\xF0\x83Z\x83" "b\x83g\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2");
        // "This disc is not the <set the game name> disc. Please insert the <set the game name> disc."
        fn_8042ED98(2, "\x82\xB1\x82\xCC\x83" "f\x83" "B\x83X\x83N\x82\xCD\n"
                       "<\x83Q\x81[\x83\x80\x96\xBC\x82\xF0\x90\xDD\x92\xE8\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2>\n"
                       "\x82\xCC\x83" "f\x83" "B\x83X\x83N\x82\xC5\x82\xCD\x82\xA0\x82\xE8\x82\xDC\x82\xB9\x82\xF1\n"
                       "<\x83Q\x81[\x83\x80\x96\xBC\x82\xF0\x90\xDD\x92\xE8\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2>\n"
                       "\x82\xCC\x83" "f\x83" "B\x83X\x83N\x82\xF0\x83Z\x83" "b\x83g\x82\xB5\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2");
        // "The disc could not be read. See the console's instruction manual for details."
        fn_8042ED98(3, "\x83" "f\x83" "B\x83X\x83N\x82\xF0\x93\xC7\x82\xDF\x82\xDC\x82\xB9\x82\xF1\x82\xC5\x82\xB5\x82\xBD\n"
                       "\x8F\xDA\x82\xB5\x82\xAD\x82\xCD\x96{\x91\xCC\x82\xCC\x8E\xE6\x88\xB5\x90\xE0\x96\xBE\x8F\x91\x82\xF0\x82\xA8\x93\xC7\x82\xDD\x82\xAD\x82\xBE\x82\xB3\x82\xA2");
        // "An error has occurred. Press the power button to turn the power OFF and follow the console's instruction manual."
        fn_8042ED98(4, "\x83G\x83\x89\x81[\x82\xAA\x94\xAD\x90\xB6\x82\xB5\x82\xDC\x82\xB5\x82\xBD\n"
                       "\x96{\x91\xCC\x82\xCC\x83p\x83\x8F\x81[\x83{\x83^\x83\x93\x82\xF0\x89\x9F\x82\xB5\x82\xC4\x93" "d\x8C\xB9\x82\xF0OFF\x82\xC9\x82\xB5\n"
                       "\x96{\x91\xCC\x82\xCC\x8E\xE6\x88\xB5\x90\xE0\x96\xBE\x8F\x91\x82\xCC\x8Ew\x8E\xA6\x82\xC9\x8F]\x82\xC1\x82\xC4\x82\xAD\x82\xBE\x82\xB3\x82\xA2");
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

#if VERSION == VERSION_GPOP8P
}
#else
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

#if VERSION == VERSION_GPOP8P
#pragma push
#pragma readonly_strings on
s32 fn_8042DF54(s32 v) {
    if (lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CB8->unk_001[1] = v;
    switch ((u8)v) {
    case 0x90:
        fn_8042ED98(0, "\203f\203B\203X\203N\203J\203o\201[\202\252\212J\202\242\202\304\202\242\202\334\202\267\n\203Q\201[\203\200\202\360\221\261\202\257\202\351\217\352\215\207\202\315\203f\203B\203X\203N\203J\203o\201[\202\360\225\302\202\337\202\304\202\255\202\276\202\263\202\242");
        fn_8042ED98(1, "<\203Q\201[\203\200\226\274\202\360\220\335\222\350\202\265\202\304\202\255\202\276\202\263\202\242>\n\202\314\203f\203B\203X\203N\202\360\203Z\203b\203g\202\265\202\304\202\255\202\276\202\263\202\242");
        fn_8042ED98(2, "\202\261\202\314\203f\203B\203X\203N\202\315\n<\203Q\201[\203\200\226\274\202\360\220\335\222\350\202\265\202\304\202\255\202\276\202\263\202\242>\n\202\314\203f\203B\203X\203N\202\305\202\315\202\240\202\350\202\334\202\271\202\361\n<\203Q\201[\203\200\226\274\202\360\220\335\222\350\202\265\202\304\202\255\202\276\202\263\202\242>\n\202\314\203f\203B\203X\203N\202\360\203Z\203b\203g\202\265\202\304\202\255\202\276\202\263\202\242");
        fn_8042ED98(3, "\203f\203B\203X\203N\202\360\223\307\202\337\202\334\202\271\202\361\202\305\202\265\202\275\n\217\332\202\265\202\255\202\315\226{\221\314\202\314\216\346\210\265\220\340\226\276\217\221\202\360\202\250\223\307\202\335\202\255\202\276\202\263\202\242");
        fn_8042ED98(4, "\203G\203\211\201[\202\252\224\255\220\266\202\265\202\334\202\265\202\275\n\226{\221\314\202\314\203p\203\217\201[\203{\203^\203\223\202\360\211\237\202\265\202\304\223d\214\271\202\360OFF\202\311\202\265\n\226{\221\314\202\314\216\346\210\265\220\340\226\276\217\221\202\314\216w\216\246\202\311\217]\202\301\202\304\202\255\202\276\202\263\202\242");
        break;
    case 0x80:
        fn_8042ED98(0, "The Disc Cover is open.\nIf you want to continue the game,\nplease close the Disc Cover.");
        fn_8042ED98(1, "Please insert the Game Disc.");
        fn_8042ED98(2, "Please insert the Game Disc.");
        fn_8042ED98(3, "The Game Disc could not be read. Please read \nthe Nintendo GameCube Instruction Booklet \nfor more information.");
        fn_8042ED98(4, "An error has occurred. \nTurn the power off and refer to \nthe Nintendo GameCube Instruction Booklet \nfor more information.");
        break;
    case 0:
        fn_8042ED98(0, "The Disc Cover is open.\nIf you want to continue the game,\nplease close the Disc Cover.");
        fn_8042ED98(1, "Please insert the Game Disc.");
        fn_8042ED98(2, "Please insert the Game Disc.");
        fn_8042ED98(3, "The Game Disc could not be read. Please read \nthe Nintendo GameCube Instruction Booklet \nfor more information.");
        fn_8042ED98(4, "An error has occurred. \nTurn the power off and refer to \nthe Nintendo GameCube Instruction Booklet \nfor more information.");
        break;
    case 2:
        fn_8042ED98(0, "Veuillez fermer le couvercle.");
        fn_8042ED98(1, "Veuillez ins\351rer le disque: <Game Title>.");
        fn_8042ED98(2, "Veuillez ins\351rer le disque: <Game Title>.");
        fn_8042ED98(3, "La lecture du disque a \351chou\351. \nVeuillez vous r\351f\351rer au manuel \nd'instructions Nintendo Gamecube \npour de plus amples informations.");
        fn_8042ED98(4, "Une erreur s'est produite. \n\311teignez la console et r\351f\351rez-vous \nau manuel d'instructions Nintendo \nGamecube pour de plus amples informations.");
        break;
    case 1:
        fn_8042ED98(0, "Bitte den Disc-Deckel schlie\337en.");
        fn_8042ED98(1, "Bitte legen Sie die <Game Title> Game Disc ein.");
        fn_8042ED98(2, "Bitte legen Sie die <Game Title> Game Disc ein.");
        fn_8042ED98(3, "Diese Game Disc kann nicht gelesen werden. \nBitte lesen Sie die Bedienungsanleitung, \num weitere Informationen zu erhalten.");
        fn_8042ED98(4, "Ein Fehler ist aufgetreten. \nBitte schalten Sie den NINTENDO GAMECUBE \naus und lesen Sie die Bedienungsanleitung, \num weitere Informationen zu erhalten.");
        break;
    case 3:
        fn_8042ED98(0, "Cierra la tapa.");
        fn_8042ED98(1, "Coloca el disco de <Game Title>.");
        fn_8042ED98(2, "Coloca el disco de <Game Title>.");
        fn_8042ED98(3, "No se puede leer el disco. \nConsulta el manual de instrucciones de \nNINTENDO GAMECUBE para \nobtener m\341s informaci\363n.");
        fn_8042ED98(4, "Se ha producido un error. \nApaga la consola y consulta el manual \nde instrucciones de NINTENDO GAMECUBE \npara obtener m\341s informaci\363n.");
        break;
    case 4:
        fn_8042ED98(0, "Chiudere il coperchio disco.");
        fn_8042ED98(1, "Inserisci il disco di gioco <Titolo di gioco>.");
        fn_8042ED98(2, "Inserisci il disco di gioco <Titolo di gioco>.");
        fn_8042ED98(3, "Impossibile leggere il disco \ndi gioco. Consulta il manuale \nd'istruzioni del NINTENDO GAMECUBE \nper ulteriori indicazioni.");
        fn_8042ED98(4, "Si \350 verificato un errore. \nSpegni (OFF) e controlla il manuale \nd'istruzioni del NINTENDO GAMECUBE \nper ulteriori indicazioni.");
        break;
    case 5:
        fn_8042ED98(0, "The Disc Cover is open.\nIf you want to continue the game,\nplease close the Disc Cover.");
        fn_8042ED98(1, "Please insert the Game Disc.");
        fn_8042ED98(2, "Please insert the Game Disc.");
        fn_8042ED98(3, "The Game Disc could not be read. Please read \nthe Nintendo GameCube Instruction Booklet \nfor more information.");
        fn_8042ED98(4, "An error has occurred. \nTurn the power off and refer to \nthe Nintendo GameCube Instruction Booklet \nfor more information.");
        break;
    }
    return 0;
}

s32 fn_8042E1EC(s32 v) {
    if (lbl_805D7CA8 == 0) {
        return -1;
    }
    lbl_805D7CB8->unk_000 = v;
    return 0;
}
#pragma pop
#endif

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
#endif
