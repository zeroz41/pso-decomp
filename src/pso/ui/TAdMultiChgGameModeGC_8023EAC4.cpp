#include "types.h"
#include "pso/misc/TWindowShortListCtrl_801A4FC0.h"
#include "pso/ui/TAdSelectGameModeGC_802C4748.h"
#include "pso/TAdMultiChgGameModeGC.h"

extern "C" {
void *__nw__7TObjectFUl(u32);
u8 *get_or_create__22TAdMultiPlyChrSelectGCFii(s32 arg0, s32 arg1);
void *TAdEnterPPPPassGC__ct(void *, s32);
void *TAdEnterPasswordGC__ct(void *, s32);
void *TAdEnterSerialAccessGC__ct(void *, s32);
void *TAdEp3Exist__ct(void *, s32);
void *TAdExNetConfirmGC__ct(void *, s32);
void *TAdLicAgreementGC__ct(void *, s32);
void *__ct__13TUnk_804F3A20FP7TObject(void *, s32);
void *__ct__17TAdMultiConfirmGCFP7TObject(void *, s32);
void *TAdMultiSaveGC__ct(void *, s32);
void *TAdPsoPassSaveGC__ct(void *, s32);
u8 *TAdSinglePlyChrSelectGC__ct(u8 *arg0, void *parent);
void *TAdSnAkPassConfirmGC__ct(void *, s32);
void *TAdTimeSetGC__ct(void *, s32);
void *TAdTrialAgreementGC__ct(void *, s32);
void *TAdTrialModemChkGC__ct(void *, s32);
void *TAdVIConfigGC__ct(void *, s32);
void *construct_title_scene__13TUnk_804EEF64Fv(void *, s32);
void *__ct__12TLevelSelectFv(void *);
void *__ct__16TAdStorySelectGCFv(void *, s32);
void *__ct__21TAdMultiChgGameModeGCFv(void *, s32);
void *__ct__21TAdMultiSelGameModeGCFv(void *, s32, s32);
void *__ct__5TLogoFv(void *, s32);
extern s32 multi_chg_game_mode_state;
extern s32 tl_01;
extern s32 tl_02;
extern s32 game_mode_scene_instance;
extern s32 lbl_805D63C8;

void TAdMultiChgGameModeGC::reset_mode_state() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xF;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::set_mode_state_0e() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xE;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::set_mode_state_0d() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xD;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::set_state_0xc() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xC;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::begin_change_game_mode() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xB;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::begin_transition() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0xA;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::set_state_0x9() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 9;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::request_scene_change() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 8;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::set_change_game_mode() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 7;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::set_game_mode() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 6;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::set_game_mode_state() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 5;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::set_game_mode_changed() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 4;
    lbl_805D63C8 = 1;
}

void TAdMultiChgGameModeGC::init_change_mode() {
    TAdMultiChgGameModeGC::sync_mode_state();
    multi_chg_game_mode_state = 0;
    lbl_805D63C8 = 1;
}
void TAdMultiChgGameModeGC::create_mode_scene() {
    void *p;
    switch (multi_chg_game_mode_state) {
    case 0:
    case 8:
    case 9:
    case 18:
    case 19:
    case 21:
    case 22:
    case 23:
    case 27:
        break;
    default:
        TAdMultiChgGameModeGC::apply_bgm_col_ctrl((s32)"advr.adx");
        break;
    }
    switch (multi_chg_game_mode_state) {
    case 0:
        p = __nw__7TObjectFUl(0x4C);
        if (p != NULL) {
            p = construct_title_scene__13TUnk_804EEF64Fv(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 4:
        p = __nw__7TObjectFUl(0x24);
        if (p != NULL) {
            p = __ct__16TAdStorySelectGCFv(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 5:
        p = __nw__7TObjectFUl(0x24);
        if (p != NULL) {
            p = __ct__19TAdSelectGameModeGCFv((u8 *)p, (void *)tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 6:
        p = __nw__7TObjectFUl(0x60);
        if (p != NULL) {
            p = TAdSinglePlyChrSelectGC__ct((u8 *)p, (void *)tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 7:
        game_mode_scene_instance = (s32)get_or_create__22TAdMultiPlyChrSelectGCFii(tl_01, 0);
        break;
    case 8:
        p = __nw__7TObjectFUl(0x468);
        if (p != NULL) {
            p = TAdTimeSetGC__ct(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 9:
        p = __nw__7TObjectFUl(0x34);
        if (p != NULL) {
            p = TAdMultiSaveGC__ct(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 10:
        p = __nw__7TObjectFUl(0x4C);
        if (p != NULL) {
            p = __ct__17TAdMultiConfirmGCFP7TObject(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 11:
        p = __nw__7TObjectFUl(0x30);
        if (p != NULL) {
            p = __ct__21TAdMultiChgGameModeGCFv(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 12:
        p = __nw__7TObjectFUl(0x44);
        if (p != NULL) {
            p = __ct__21TAdMultiSelGameModeGCFv(p, tl_01, 0);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 13:
        p = __nw__7TObjectFUl(0x44);
        if (p != NULL) {
            p = __ct__21TAdMultiSelGameModeGCFv(p, tl_01, 1);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 14:
        game_mode_scene_instance = (s32)get_or_create__22TAdMultiPlyChrSelectGCFii(tl_01, 1);
        break;
    case 15:
        p = __nw__7TObjectFUl(0x68);
        if (p != NULL) {
            p = TAdEnterSerialAccessGC__ct(p, tl_02);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 16:
        p = __nw__7TObjectFUl(0x44);
        if (p != NULL) {
            p = TAdEnterPasswordGC__ct(p, tl_02);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 17:
        p = __nw__7TObjectFUl(0x3C);
        if (p != NULL) {
            p = TAdLicAgreementGC__ct(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 18:
        p = __nw__7TObjectFUl(0x4C);
        if (p != NULL) {
            p = TAdVIConfigGC__ct(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 19:
        p = __nw__7TObjectFUl(0x38);
        if (p != NULL) {
            p = __ct__5TLogoFv(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 20:
        p = __nw__7TObjectFUl(0x4C);
        if (p != NULL) {
            p = TAdSnAkPassConfirmGC__ct(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 21:
        p = __nw__7TObjectFUl(0x30);
        if (p != NULL) {
            p = TAdExNetConfirmGC__ct(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 22:
        p = __nw__7TObjectFUl(0x30);
        if (p != NULL) {
            p = TAdTrialModemChkGC__ct(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 23:
        p = __nw__7TObjectFUl(0x3C);
        if (p != NULL) {
            p = TAdTrialAgreementGC__ct(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 24:
        game_mode_scene_instance = (s32)get_or_create__22TAdMultiPlyChrSelectGCFii(tl_01, 2);
        break;
    case 25:
        p = __nw__7TObjectFUl(0x44);
        if (p != NULL) {
            p = TAdEnterPPPPassGC__ct(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 26:
        p = __nw__7TObjectFUl(0x48);
        if (p != NULL) {
            p = TAdPsoPassSaveGC__ct(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 27:
        p = __nw__7TObjectFUl(0x38);
        if (p != NULL) {
            p = __ct__13TUnk_804F3A20FP7TObject(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 28:
        p = __nw__7TObjectFUl(0x38);
        if (p != NULL) {
            p = TAdEp3Exist__ct(p, tl_01);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 1:
        p = __nw__7TObjectFUl(0x28);
        if (p != NULL) {
            p = __ct__12TLevelSelectFv(p);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 3:
        p = __nw__7TObjectFUl(0x30);
        if (p != NULL) {
            p = __ct__13TUnk_804C2298Fv(p);
        }
        game_mode_scene_instance = (s32)p;
        break;
    case 29:
        break;
    }
}

}
