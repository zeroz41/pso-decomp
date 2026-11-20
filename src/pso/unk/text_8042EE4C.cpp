#include "types.h"
#include "pso/unk/SharedMemory.h"
#include "pso/unk/text_8042EE4C.h"
#include "pso/unk/text_8042EAD4.h"
#include "pso/network/TLobby_80429598.h"

// The European ntUtl builds the EXI probe, the disc messages and the modem setters as a file of
// their own (the disc messages are addressed from this file's .rodata start); the US build has
// them at the end of TAdTrialModemChkGC_8042E9FC.cpp.

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
