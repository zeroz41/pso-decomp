#include "pso/map/FloorResourceCallbacks.h"
#include "pso/misc/TLobby_8007B858.h"
#include "pso/misc/TLanguage.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/TSetManager.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TQuestColCtrl.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TScene.h"
#include "pso/misc/TSceneSora.h"
#include "pso/TSwitch.h"
#include "pso/player/TUnk_8048E5F4.h"

#include "types.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_8007BA98_lbl_8048D4C0 {
    s32 value;
    u8 remaining[0xE4];
};

struct RecoveredGlobal_8007BA98_lbl_8048D5A8 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_8007BA20_lbl_8048D4C0 {
    s32 value;
    u8 remaining[0xE4];
};

struct RecoveredGlobal_8007BA20_lbl_8048D5A8 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
void TLobby__sub_802A5154(void);
}
void load_obj_lobby_main(void);
extern "C" {
s32 run_load_callback_table(void *, int);
extern RecoveredGlobal_8007BA98_lbl_8048D4C0 lbl_8048D4C0;
extern RecoveredGlobal_8007BA98_lbl_8048D5A8 lbl_8048D5A8;
void call_funcs_reverse__6TLobbyFPvUi(s32, u32);
void fn_80198E84(void);
void TLobby__sub_8035202C(void);
s32 __ct__9TCineCtrlFv(u32, s32);
s32 create_area_fog_ctrl();
s32 THunterGuildSeqOnlineTask__ct(u32, s32);
s32 activate_triggered_floor_events();
s32 cleanup_game_objects__9TMainTaskFv();
s32 restore_floor_telepipes();
s32 __ct__15TWindowCtrlMainFv();
s32 TWindowCtrl__ct(u32, s32);
s32 __ct__8TTecCtrlFv(u32, s32);
u32 __nw__7TObjectFUl(s32);
s32 ct_register__6TLobbyFv(u32, s32);
s32 TWindowTimer__sub_80198D98();
s32 TLobby__sub_8032BDC4(u32, s32);
s32 TLobby__sub_8033ED24(u32, s32);
s32 TLobby__sub_80351F3C();
s32 get_main_phase();
s32 is_split_screen();

extern s32 tl_00;
extern s32 tl_01;
extern s32 tl_06;
extern s32 tl_particlemodel;
extern s32 tl_fade;

void TLobby::create_tasks() {
    u32 tmp;
    create_area_fog_ctrl();
    if (is_split_screen() == 0) {
        tmp = __nw__7TObjectFUl(0x20);
        if (tmp != 0U) {
            ((TUnk_8048E5F4 *)tmp)->init_subobject((void *)tl_particlemodel, (void *)1);
        }
        tmp = __nw__7TObjectFUl(0x20);
        if (tmp != 0U) {
            ((TUnk_8048E5F4 *)tmp)->init_subobject((void *)tl_particlemodel, (void *)0);
        }
        tmp = __nw__7TObjectFUl(0x84);
        if (tmp != 0U) {
            TLobby__sub_8032BDC4(tmp, tl_particlemodel);
        }
        tmp = __nw__7TObjectFUl(0x24);
        if (tmp != 0U) {
            TLobby__sub_8033ED24(tmp, tl_particlemodel);
        }
    }
    cleanup_game_objects__9TMainTaskFv();
    TScene::create();
    TSceneSora::create_instance();
    TSetManager::create();
    activate_triggered_floor_events();
    tmp = __nw__7TObjectFUl(0x1C);
    if (tmp != 0U) {
        __ct__15TWindowCtrlMainFv();
    }
    tmp = __nw__7TObjectFUl(0xE8);
    if (tmp != 0U) {
        TWindowCtrl__ct(tmp, tl_00);
    }
    tmp = __nw__7TObjectFUl(0x2C);
    if (tmp != 0U) {
        ct_register__6TLobbyFv(tmp, tl_fade);
    }
    TLobby::set_fade_params(0);
    tmp = __nw__7TObjectFUl(0x30);
    if (tmp != 0U) {
        __ct__9TCineCtrlFv(tmp, tl_00);
    }
    TRaderMapCore::create();
    restore_floor_telepipes();
    tmp = __nw__7TObjectFUl(0x20);
    if (tmp != 0U) {
        ((TNpcPlayer *)tmp)->construct_party_area((void *)tl_06);
    }
    new TSwitch((TObject *)tl_00);
    TQuestColCtrl::init();
    if (get_current_area() == 0xF) {
        TLobby__sub_80351F3C();
    }
    if ((get_current_area() == 0xF) && (TLobby::is_scene_ready() != 0)) {
        TWindowTimer__sub_80198D98();
    }
    if ((get_main_phase() == 0xF) && ((get_current_area() == 0) || (get_current_area() == 0x12))) {
        tmp = __nw__7TObjectFUl(0x1C);
        if (tmp != 0U) {
            THunterGuildSeqOnlineTask__ct(tmp, tl_01);
        }
    }
    tmp = __nw__7TObjectFUl(0x24);
    if (tmp != 0U) {
        __ct__8TTecCtrlFv(tmp, tl_01);
    }
}
typedef char RecoveredGlobal_8007BA98_lbl_8048D4C0_size[sizeof(RecoveredGlobal_8007BA98_lbl_8048D4C0) == 0xE8 ? 1 : -1];
typedef char RecoveredGlobal_8007BA98_lbl_8048D5A8_size[sizeof(RecoveredGlobal_8007BA98_lbl_8048D5A8) == 0x20 ? 1 : -1];

typedef char RecoveredGlobal_8007BA20_lbl_8048D4C0_size[sizeof(RecoveredGlobal_8007BA20_lbl_8048D4C0) == 0xE8 ? 1 : -1];
typedef char RecoveredGlobal_8007BA20_lbl_8048D5A8_size[sizeof(RecoveredGlobal_8007BA20_lbl_8048D5A8) == 0x20 ? 1 : -1];
void TLobby::clear_session_buffers() {
    if (get_current_area() == 0xF) {
        TLobby::free_dialing_gc();
        fn_80198E84();
        TLobby__sub_8035202C();
    }
    if ((get_current_area() != 0) && (get_current_area() != 0xF) && (get_current_area() != 0x12)) {
        call_funcs_reverse__6TLobbyFPvUi((s32) &(*(RecoveredGlobal_8007BA20_lbl_8048D5A8 *)&lbl_8048D5A8).value, 0x20U);
    }
    call_funcs_reverse__6TLobbyFPvUi((s32) &(*(RecoveredGlobal_8007BA20_lbl_8048D4C0 *)&lbl_8048D4C0).value, 0xE8U);
}

s32 TLobby::run_lobby_load_tables() {
    s32 temp_r3;
    s32 temp_r3_2;
    temp_r3_2 = run_load_callback_table(&lbl_8048D4C0.value, 0xE8);
    if (temp_r3_2 == 0) {
        return temp_r3_2;
    }
    if ((get_current_area() != 0) && (get_current_area() != 0xF) && (get_current_area() != 0x12)) {
        temp_r3 = run_load_callback_table(&lbl_8048D5A8.value, 0x20);
        if (temp_r3 == 0) {
            return temp_r3;
        }
    }
    if (get_current_area() == 0xF) {
        load_obj_lobby_main();
        TLanguage::load_lobby_textures();
        TLobby__sub_802A5154();
    }
    return 1;
}

s32 is_area_transfer_pending();
s32 apply_phase_keyboard_mode();
s32 load_area_gsl();
s32 close_gsl_archive();
s32 update_key_machine__6TLobbyFv();

s32 TLobby::check_disconnect_conditions() {
    apply_phase_keyboard_mode();
    if (TLobby::run_lobby_load_tables() == 0) {
        TLobby::reset_and_invoke();
        return 1;
    }
    load_area_gsl();
    if (update_key_machine__6TLobbyFv() == 0) {
        close_gsl_archive();
        TLobby::reset_and_invoke();
        return 1;
    }
    if (load_current_floor_resources() == 0) {
        close_gsl_archive();
        TLobby::reset_and_invoke();
        return 1;
    }
    close_gsl_archive();
    if (is_area_transfer_pending() != 0) {
        TLobby::reset_and_invoke();
        return 1;
    }
    TLobby::clear_callback_and_reset_keyboard();
    return 0;
}
void TLobby::reset_and_invoke() { TLobby::reset_keyboard_state(); TLobby::invoke_callback(); TLobby::clear_callback_and_reset_keyboard(); }
}

#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct L_8007BC5C { u8 pad0; u8 count; u8 pad2[2]; s32 ids[30]; };

    extern short quest_collision_next_id;
void TLobby__sub_8007BBEC(void) { quest_collision_next_id = 0; }

void TLobby__sub_8007BBF8(void) { quest_collision_next_id = 0; }

extern s32 TLobby__protocol_instance;

s32 TWindowSubComCard::get_card_slot(s32 arg0) {
    s32 state;
    s32 var_r31;
    s32 var_r3;
    var_r31 = arg0;
    if (var_r31 < 0) {
        var_r3 = 0;
        return 0;
    }
    if (var_r31 >= 0x1C) {
        var_r3 = 0;
        return 0;
    }
    state = TAdSinglePlyChrSelectGC::get_state();
    var_r3 = state + 0x10000;
    var_r3 = state + 0xD2C4;
    var_r3 += var_r31 * 0x90;
    return var_r3;
}

void TLobby::collect_active_card_ids() {
    L_8007BC5C *arg0 = (L_8007BC5C *)this;
    u8 *card;
    s32 *p;
    s32 i;
    s32 n;
    card = (u8 *)TWindowSubComCard::get_card_slot(0);
    p = arg0->ids;
    n = 0;
    i = 0;
    do {
        if (((TWindowSubComCard *)card)->is_active() == 0) {
            break;
        }
        *p++ = ((TWindowSubComCard *)card)->get_card_id();
        i++;
        n++;
        card += 0x90;
    } while (i < 0x1c);
    arg0->count = n;
    for (i = n; i < 0x1e; i++) {
        *p++ = 0;
    }
}

void TLobby::send_status_packet() {
    char lobby[0x84];

    ((TLobby *)lobby)->collect_active_card_ids();
    ((TLobby *)TLobby__protocol_instance)->send_c6_packet((s32 *) lobby);
}
