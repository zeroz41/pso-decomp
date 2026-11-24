#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/render/ColorLineList.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/ControllerInput.h"
#include "pso/render/Draw2D.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowCtrlClipOut.h"
#include "pso/ui/window/TWindowCtrlSub.h"
#include "pso/ui/window/TWindowCtrlScreen.h"
#include "pso/ui/window/TWindowCtrlPlayer.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowChoiceSetting_80249610.h"
#include "pso/unk/WindowControlState.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/ui/window/TWindowCtrlMain_8024EEF8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMainMenu1P.h"
#include "pso/ui/window/TWindowMainMenu4P.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/window/TWindowSubEquip.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/object/TObjLuker.h"
#include "pso/unk/text_80269FE8.h"
#include "pso/unk/text_80271400.h"

#include "pso/ui/window/TWindowDD.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowCtrl_8024A1A8.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/player/PlayerSlots.h"
const char *TWindowCtrlMain__name = "TWindowCtrlMain";
const char *TWindowCtrlScreen__name = "TWindowCtrlScreen";
const char *TWindowCtrlSub__name = "TWindowCtrlSub";
const char *TWindowCtrlClipOut__name = "TWindowCtrlClipOut";
const char *TWindowCtrlPlayer__name = "TWindowCtrlPlayer";

// width, height of the player message window (TLobby__sub_80269DA4 stores it as the window size)
const f32 lbl_8044EC4C[2] = {255.0f, 120.0f};
s32 TWindowCtrlMain__display_flags;
TObject *TWindowCtrlMain__instance;
TObject *TWindowCtrlMain__window_task_root;
TWindowCtrlScreen *TWindowCtrlMain__screen_controller;
TWindowCtrlSub *TWindowCtrlMain__sub_controller;
TWindowCtrlClipOut *window_clip_out_instance;
f32 window_depth_order_cursor;
extern TObject *tl_01;
extern TObject *tl_window;
extern TObject *tl_clipout;
extern TObject *tl_fadeafter;
struct VObj_8024C820 {
    char pad[0x18];
    virtual void m0(int);
};
extern "C" void TWindowCtrlMain__sub_8024D2A4(s32 viewport_index);
struct Ent_8024CCDC { u8 p0[8]; f32 f8; f32 fC; u8 p10[0xC]; };
extern "C" {
WindowControlState TWindowCtrlMain__viewport_states[6];
struct Poly_8024CE68 {
    NJS_POINT2 *verts;
    u32 *colors;
    s32 flags;
    s32 count;
};
struct Quad_8024CE68 { f32 x0, y0, x1, y1, u0, v0, u1, v1; };
void TWindowCtrlMain__sub_8024CB7C();
void TWindowCtrlMain__sub_8024CB8C();
s32 TWindowMainMenu__sub_8024E3D4(void *);
int open_submenu__15TWindowSubEquipFll(void*);
int append_line__14TWindowMessageFii(void*);
int try_open_battle_menu__15TWindowMainMenuFs(void*);
void TWindowCtrlMain__sub_8024D838(void);
}
void load_hud_palette_textures(void);
struct WBase_8024DCE8 { u8 pad[0x18]; };
struct W_8024DCE8 : WBase_8024DCE8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};
extern "C" {
s32 bind_target__13TWindowLockOnFUs(void *, s32);
u32 create_for_target__13TWindowLockOnFlUs(int, s32);
s32 fn_8002AE08(void *p);
int TWindowMainMenu__sub_8024E3F4(void *p);
s32 TWindowMainMenu__sub_8024E3E0(void *);
saddr get_window_layout_position(s32);
}
struct Ctl_8024E2A8 {
    s32 f0;
    u8 pad4[0x18 - 4];
    s32 *vt;
    s16 f1c, f1e, f20;
    s32 f24;
    void *f28;
    void *f2c;
    void *f30;
    void *f34;
    void *f38;
    void *f3c;
};

TWindowCtrlPlayer::TWindowCtrlPlayer(TObject *parent, s32 arg2) : TObject(parent) {
    m_name = TWindowCtrlPlayer__name;
    ((struct Ctl_8024E2A8 *)this)->f1c = 0;
    ((struct Ctl_8024E2A8 *)this)->f1e = 0;
    ((struct Ctl_8024E2A8 *)this)->f20 = 0;
    ((struct Ctl_8024E2A8 *)this)->f24 = arg2;
    ((struct Ctl_8024E2A8 *)this)->f28 = 0;
    ((struct Ctl_8024E2A8 *)this)->f2c = 0;
    ((struct Ctl_8024E2A8 *)this)->f30 = 0;
    ((struct Ctl_8024E2A8 *)this)->f34 = 0;
    ((struct Ctl_8024E2A8 *)this)->f38 = 0;
    ((struct Ctl_8024E2A8 *)this)->f3c = 0;
    if (is_split_screen() != 0) {
        ((struct Ctl_8024E2A8 *)this)->f28 = new TWindowMainMenu4P(this, ((struct Ctl_8024E2A8 *)this)->f24);
    } else {
        ((struct Ctl_8024E2A8 *)this)->f28 = new TWindowMainMenu1P(this, ((struct Ctl_8024E2A8 *)this)->f24);
    }
    ((struct Ctl_8024E2A8 *)this)->f2c = (void *)create_message_information_window((s32)(get_window_layout_position(0x20)), (saddr)lbl_8044EC4C, (s32)(((struct Ctl_8024E2A8 *)this)->f24));
    ((struct Ctl_8024E2A8 *)this)->f30 = (void *)create_status_window(((struct Ctl_8024E2A8 *)this)->f24);
    ((TObject *)(((struct Ctl_8024E2A8 *)this)->f30))->suspend_update();
    ((struct Ctl_8024E2A8 *)this)->f34 = new TWindowActionPalette(((struct Ctl_8024E2A8 *)this)->f24);
    ((TObject *)(((struct Ctl_8024E2A8 *)this)->f34))->suspend_update();
}

TWindowCtrlPlayer::~TWindowCtrlPlayer() {
    if (*(void **)((s8 *)this + 0x3C) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x3C)))->queue_destruction(); this->m_3c = 0; }
    if (*(void **)((s8 *)this + 0x38) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x38)))->close(); this->lock_on_window = 0; }
    if (*(void **)((s8 *)this + 0x34) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x34)))->close(); this->m_34 = 0; }
    if (*(void **)((s8 *)this + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x30)))->close(); this->simple_status = 0; }
    if (*(void **)((s8 *)this + 0x2C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x2C)))->close(); this->message_information = 0; }
    if (*(void **)((s8 *)this + 0x28) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x28)))->queue_destruction(); this->m_28 = 0; }
}

void TWindowCtrlPlayer::run_task() { sub_8024E0F0(); ((TWindowCtrl *)this)->run_all_updates(); }

void TWindowCtrlPlayer::render() {  }

#pragma push
#pragma scheduling off
void TWindowCtrlPlayer::sub_8024E0F0() {
    s16 temp_r3_3;
    uaddr simple_status;
    uaddr temp_r3_2;
    switch (*(s16 *)&this->m_1e) {
    case 18:
        simple_status = reinterpret_cast<uaddr>(this->simple_status);
        if (simple_status != 0U) {
            ((TObject *)simple_status)->clear_update_suspension();
        }
        break;
    case 38:
        if (is_current_area_item_enabled() != 0) {
            temp_r3_2 = reinterpret_cast<uaddr>(this->m_34);
            if (temp_r3_2 != 0U) {
                ((TObject *)temp_r3_2)->clear_update_suspension();
            }
        }
        break;
    }
    temp_r3_3 = *(s16 *)&this->m_1e;
    if (temp_r3_3 > 0x7530) {
        *(s16 *)&this->m_1e = (temp_r3_3 - 0x2710);
    }
    *(s16 *)&this->m_1e = (s16) (*(s16 *)&this->m_1e + 1);
}
#pragma pop

void TWindowCtrl::run_all_updates() { update_trade_window_visibility(); update_child_window_visibility(); update_target_info_window(); update_main_menu_request(); show_active_window(); update_short_list_request(); update_countdown(); }

void TWindowCtrl::update_trade_window_visibility() {
    u8 *arg0 = (u8 *)this;
    if ((this->m_30 != NULL) && (((TWindowCtrl *)((void *) this->m_30))->is_flag_2_set() == 0)) {
        if ((get_player_by_client_id(this->m_24) == NULL) || (((TWindowCtrl *)arg0)->is_visible() != 0) || (is_status_window_hidden() != 0) || ((is_split_screen() != 0) && (get_active_menu() != 0))) {
            ((TWindowLockOn *)(this->m_30))->request_close();
            return;
        }
        window_request_show((void *)this->m_30);
    }
}

void TWindowCtrl::update_child_window_visibility() {
    u8 *arg0 = (u8 *)this;
    u32 player;
    if ((this->m_34 != NULL) && (((TWindowCtrl *)((void *) this->m_34))->is_flag_2_set() == 0)) {
        player = (uaddr)get_player_by_client_id(this->m_24);
        if ((get_active_menu() != 0) || (((TWindowCtrl *)arg0)->is_visible() != 0) || (((TWindowCtrl *)arg0)->is_enabled() != 0) || (player == 0U)) {
            ((TWindowLockOn *)(this->m_34))->request_close();
            return;
        }
        window_request_show((void *)this->m_34);
    }
}

#pragma push
#pragma fp_contract on
void TWindowCtrl::update_target_info_window() {
    u8 *arg0 = (u8 *)this;
    if ((*(void **)((s8 *)arg0 + 0x38) != NULL) && ((((TObject *)(*(void **)((s8 *)arg0 + 0x38)))->all_parents_unqueued_for_destruction() == 0) || (((TWindowBase *)(*(uaddr *)((s8 *)arg0 + 0x38)))->sub_80244994() == 0))) {
        *(u32 *)((s8 *)arg0 + 0x38) = 0U;
    }
    if ((is_lock_on_window_hidden() != 0) || (get_active_menu() != 0) || (((TWindowCtrl *)arg0)->is_visible() != 0) || (has_get_com_card_window() != 0) || (TWindowCtrl__sub_8024A314() != 0)) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x38) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x38)))->close();
            *(u32 *)((s8 *)arg0 + 0x38) = 0U;
        }
    } else {
        s32 id = TObjPlayer::get_battle_ctrl_id((int) ((u16) *(s32 *)((s8 *)arg0 + 0x24)));
        if ((u16) id != 0xFFFF) {
            void *w = *(void **)((s8 *)arg0 + 0x38);
            if (w == NULL) {
                *(u32 *)((s8 *)arg0 + 0x38) = create_for_target__13TWindowLockOnFlUs((int) (*(s32 *)((s8 *)arg0 + 0x24)), id);
            } else {
                bind_target__13TWindowLockOnFUs(w, id);
            }
        }
    }
}
#pragma pop

void TWindowCtrl::update_main_menu_request() {
    uaddr p;
    s16 key;
    if (*(void **)((s8 *)this + 0x28) == NULL) {
        return;
    }
    p = (uaddr)get_player_by_client_id(this->m_24);
    if (p == 0) {
        return;
    }
    if (((TObjPlayer *)p)->is_inactive() == 0) {
        return;
    }
    if (is_visible() != 0 || is_main_menu_disabled() != 0) {
        (*(W_8024DCE8 **)((s8 *)this + 0x28))->m6();
        return;
    }
    {
        s32 idx = is_player_input_active(this->m_24);
        key = ((s16 (*)(void *))TKeyBoardControl::get_function_key_menu)(this);
        if (test_pressed_buttons_packed(&controller_input_state.controllers[idx], 0x108) == 0 && key == 0x1F) {
            return;
        }
    }
    if (get_active_menu() != 0) {
        if (TWindowMainMenu__sub_8024E3F4(this) == 0) {
            (*(W_8024DCE8 **)((s8 *)this + 0x28))->m6();
        }
        return;
    }
    if (*(void **)((s8 *)this + 0x3C) != NULL) {
        ((TObject *)(*(void **)((s8 *)this + 0x3C)))->queue_destruction();
        *(void **)((s8 *)this + 0x3C) = NULL;
        return;
    }
    if (TWindowCtrl::get_active_sub() != 0) {
        TWindowCtrl::update_focused();
        return;
    }
    if ((u32)((TObjPlayer *)p)->is_action_active() != 0) {
        return;
    }
    if (key == 0x1F) {
        (*(W_8024DCE8 **)((s8 *)this + 0x28))->m4();
        return;
    }
    ((TWindowMainMenu *)(*(void **)((s8 *)this + 0x28)))->try_open_battle_menu(key);
}

void TWindowCtrl::show_active_window() {
    if ((u32) this->m_2c != 0U) {
        if (is_visible() != 0) {
            ((TWindowLockOn *)(this->m_2c))->request_close();
            return;
        }
        window_request_show((void *)this->m_2c);
        if (get_active_menu() != 0) {
            ((TWindowBase *)(this->m_2c))->set_position((f32 *)(get_window_layout_position(0x21)));
            return;
        }
        ((TWindowBase *)(this->m_2c))->set_position((f32 *)(get_window_layout_position(0x20)));
    }
}

void TWindowCtrl::update_short_list_request() {
    s32 idx;
    u16 id;
    ControllerInputContext *btn;
    if (*(void **)((s8 *)this + 0x3C) != NULL && ((TObject *)(*(void **)((s8 *)this + 0x3C)))->all_parents_unqueued_for_destruction() == 0) {
        *(void **)((s8 *)this + 0x3C) = NULL;
    }
    if (*(void **)((s8 *)this + 0x34) != NULL && ((TWindowCtrl *)(*(void **)((s8 *)this + 0x34)))->is_flag_2_set() == 0) {
        if (get_player_by_client_id(*(s32 *)&this->m_24) == NULL) {
            if (*(void **)((s8 *)this + 0x3C) != NULL) {
                ((TObject *)(*(void **)((s8 *)this + 0x3C)))->queue_destruction();
                *(void **)((s8 *)this + 0x3C) = NULL;
            }
        } else {
            idx = is_player_input_active(*(s32 *)&this->m_24);
            id = TObjPlayer::get_current_target_id();
            if (get_active_menu() != 0 || is_visible() != 0 ||
                (id != 0xFFFF && id != *(s32 *)&this->m_24) || is_main_menu_disabled() != 0 ||
                TWindowCtrl::get_display_flag() != 0) {
                if (*(void **)((s8 *)this + 0x3C) != NULL) {
                    ((TObject *)(*(void **)((s8 *)this + 0x3C)))->queue_destruction();
                    *(void **)((s8 *)this + 0x3C) = NULL;
                }
            } else if (*(void **)((s8 *)this + 0x3C) == NULL && is_enabled() == 0) {
                if (test_previous_buttons_packed(btn = &controller_input_state.controllers[idx], fn_8002AE08((void *)(*(saddr *)&this->m_24))) != 0 &&
                    test_pressed_buttons_packed(btn, 0x200) != 0) {
                    *(void **)((s8 *)this + 0x3C) = new TWindowShortListCtrl(this, *(s32 *)&this->m_24);
                }
            }
        }
    }
}

void TWindowCtrl::update_countdown() {
    if (countdown > 0) {
        countdown--;
    }
}

s32 TKeyBoardControl::get_function_key_menu(void *arg0) {
    if (is_split_screen() != 0) {
        return 0x1F;
    }
    if (TKeyBoardControl__sub_801A58B0() != 0) {
        return 0x1F;
    }
    if (TKeyBoardControl__sub_801A58D8() == 0) {
        return 0x1F;
    }
    if (TKeyBoardControl::is_key_down(0x44) != 0) {
        return 0x13;
    }
    if (TKeyBoardControl::is_key_down(0x45) != 0) {
        return 0x15;
    }
    if (TKeyBoardControl::is_key_down(0x46) != 0) {
        return 0xE;
    }
    if (TKeyBoardControl::is_key_down(0x47) != 0) {
        return 0x1A;
    }
    if (TKeyBoardControl::is_key_down(0x48) != 0) {
        return 0x17;
    }
    if (TKeyBoardControl::is_key_down(0x49) != 0) {
        return 0xC;
    }
    if (TKeyBoardControl::is_key_down(0x4A) != 0) {
        return 0xB;
    }
    return (TKeyBoardControl::is_key_down(0x4B) != 0) ? 0 : 0x1F;
}

s32 TWindowCtrl::get_active_menu() {
    void *p = *(void **)((s8 *)this + 0x28);
    if (p == 0) {
        return 0;
    }
    return TWindowMainMenu__sub_8024E3E0(p);
}

s32 TWindowCtrlMain::get_main_menu_message() {
    void *p = *(void **)((s8 *)this + 0x28);
    if (p == 0) {
        return 0;
    }
    return TWindowMainMenu__sub_8024E3D4(p);
}

void TWindowCtrlMain::free_member() { void* m = *(void**)((char*)this + 0x28); if (m) try_open_battle_menu__15TWindowMainMenuFs(m); }

void TWindowCtrlMain::update_field28() { void* m = *(void**)((char*)this + 0x28); if (m) open_submenu__15TWindowSubEquipFll(m); }

void TWindowCtrlMain::spawn_palette_slot_light(s32 kind) { void* m = *(void**)((char*)this + 0x34); if (m) spawn_action_palette_slot_light(static_cast<TWindowActionPalette *>(m), kind); }

void TWindowCtrlMain::update_child_2c() { void* m = *(void**)((char*)this + 0x2c); if (m) append_line__14TWindowMessageFii(m); }

s32 TWindowCtrl::is_countdown_done() {
    return this->countdown <= 0 ? 1 : 0;
}

void TWindowCtrl::start_countdown() { this->countdown = 60; }

void TWindowCtrlMain__sub_8024D838(void) { TWindowCtrlMain::reset_all((void*)((void*)(0))); }

void TWindowCtrlMain::reset_all(void* _w0) {
    s32 i;
    load_hud_palette_textures();
    TWindowCtrlMain__sub_8024EF30();
    WindowDrawContext::get_or_create_instance();
    TWindowCtrlMain__display_flags = 0;
    TWindowCtrlMain__window_task_root = NULL;
    TWindowCtrlMain__screen_controller = NULL;
    TWindowCtrlMain__sub_controller = NULL;
    window_clip_out_instance = NULL;
    TWindowCtrlMain__instance = NULL;
    window_depth_order_cursor = -1.5999999f;
    for (i = 0; i < 6; i++) {
        ((TWindowCtrlMain *)(&TWindowCtrlMain__viewport_states[i]))->init_fields();
    }
}

void TWindowCtrlMain::free_all_windows() {
    TObject *root;
    s32 i;
    root = TWindowCtrlMain__window_task_root;
    TWindowCtrlMain__window_task_root = NULL;
    if (window_clip_out_instance != NULL) {
        delete window_clip_out_instance;
        window_clip_out_instance = NULL;
    }
    if (TWindowCtrlMain__sub_controller != NULL) {
        delete TWindowCtrlMain__sub_controller;
        TWindowCtrlMain__sub_controller = NULL;
    }
    if (TWindowCtrlMain__screen_controller != NULL) {
        delete TWindowCtrlMain__screen_controller;
        TWindowCtrlMain__screen_controller = NULL;
    }
    for (i = 5; i >= 0; i--) {
        TWindowCtrlMain::release_ptr((void **)&TWindowCtrlMain__viewport_states[i].window_root);
    }
    if (TWindowCtrlMain__instance != NULL) {
        delete TWindowCtrlMain__instance;
        TWindowCtrlMain__instance = NULL;
    }
    if (root != NULL) {
        delete root;
    }
    TWindowCtrlMain::free_shared_draw_context();
    TWindowCtrlMain::free_window();
}

TWindowCtrlMain::TWindowCtrlMain() : TObject(tl_fadeafter) {
    WindowControlState *e;
    s32 i;
    m_name = TWindowCtrlMain__name;
    if (TWindowCtrlMain__window_task_root == NULL) {
        TWindowCtrlMain__window_task_root = new TObject(NULL);
    }
    if (TWindowCtrlMain__instance == NULL) {
        TWindowCtrlMain__instance = new TObject(TWindowCtrlMain__window_task_root);
    }
    for (i = 0; i < 6; i++) {
        e = &TWindowCtrlMain__viewport_states[i];
        ((TWindowCtrlMain *)e)->init_fields();
        e->window_root = new TObject(TWindowCtrlMain__window_task_root);
    }
    if (TWindowCtrlMain__screen_controller == NULL) {
        TWindowCtrlMain__screen_controller = new TWindowCtrlScreen(tl_window);
    }
    if (TWindowCtrlMain__sub_controller == NULL) {
        TWindowCtrlMain__sub_controller = new TWindowCtrlSub(tl_01);
    }
    if (window_clip_out_instance == NULL) {
        window_clip_out_instance = new TWindowCtrlClipOut(tl_clipout);
    }
}

TWindowCtrlMain::~TWindowCtrlMain() {
    TObject *root;
    s32 i;
    root = TWindowCtrlMain__window_task_root;
    TWindowCtrlMain__window_task_root = NULL;
    if (window_clip_out_instance != NULL) {
        delete window_clip_out_instance;
        window_clip_out_instance = NULL;
    }
    if (TWindowCtrlMain__sub_controller != NULL) {
        delete TWindowCtrlMain__sub_controller;
        TWindowCtrlMain__sub_controller = NULL;
    }
    if (TWindowCtrlMain__screen_controller != NULL) {
        delete TWindowCtrlMain__screen_controller;
        TWindowCtrlMain__screen_controller = NULL;
    }
    for (i = 5; i >= 0; i--) {
        TWindowCtrlMain::release_ptr((void **)&TWindowCtrlMain__viewport_states[i].window_root);
    }
    if (TWindowCtrlMain__instance != NULL) {
        delete TWindowCtrlMain__instance;
        TWindowCtrlMain__instance = NULL;
    }
    if (root != NULL) {
        delete root;
    }
}

void TWindowCtrlMain::run_task() { { (void)(((TWindowDD *)this)->update_com_card()); return; } }

void TWindowCtrlMain::render() {
    set_default_alpha_blend();
    TParticleCtrl::begin_effect_render();
    TCameraCtrl::restore_full_screen_view();
    TWindowCtrlMain__sub_8024CE24()->render_nodes();
    TCameraCtrl::restore_saved_view();
    TParticleCtrl::end_effect_render();
}

void TWindowCtrlMain__sub_8024D2A4(s32 viewport_index) {
    NJS_POINT2 verts[4];
    Poly_8024CE68 poly;
    u32 colors[4];
    u32 color;

    color = get_window_control_state(viewport_index)->field04;
    if (color == 0) {
        return;
    }
    poly.verts = verts;
    poly.colors = colors;
    poly.flags = 0;
    poly.count = 4;
    poly.verts[0].x = 0.0f;
    poly.verts[0].y = 0.0f;
    poly.colors[0] = color;
    poly.verts[1].x = 640.0f;
    poly.verts[1].y = 0.0f;
    poly.colors[1] = color;
    poly.verts[2].x = 640.0f;
    poly.verts[2].y = 480.0f;
    poly.colors[2] = color;
    poly.verts[3].x = 0.0f;
    poly.verts[3].y = 480.0f;
    poly.colors[3] = color;
    draw_polygon_2d((NJS_POINT2COL *)&poly, 4, 0x16, -10.0f);
}

#pragma push
#pragma fp_contract on
void draw_menu_backdrop_gradients(s32 viewport_index) {
    NJS_POINT2 verts[4];
    Quad_8024CE68 q;
    Poly_8024CE68 poly;
    u32 colors[4];
    ColorLineList line;
    ColorLineVertex lverts[2];
    u32 lcolors[2];
    WindowControlState *s;
    f32 alpha;
    s32 a;
    f32 y;
    u32 c;

    s = get_window_control_state(viewport_index);
    alpha = s->field08;
    if (alpha <= 0.0f) {
        return;
    }
    poly.verts = verts;
    poly.colors = colors;
    poly.flags = 0;
    poly.count = 4;
    colors[0] = 0xFF000000;
    colors[1] = 0xFF000000;
    colors[2] = 0xFF000000;
    colors[3] = 0xFF000000;
    verts[0].x = 0.0f;
    verts[0].y = 0.0f;
    verts[1].x = 0.5f * s->field0C;
    verts[1].y = 0.0f;
    verts[2].x = 0.5f * s->field0C;
    verts[2].y = 480.0f;
    verts[3].x = 0.0f;
    verts[3].y = 480.0f;
    reinterpret_cast<ColorLineList *>(&poly)->draw_strip_swap_color(4, 22, -10.0f);

    verts[0].x = 0.5f * s->field0C;
    verts[0].y = 480.0f - 0.5f * (480.0f - s->field18);
    verts[1].x = 640.0f;
    verts[1].y = 480.0f - 0.5f * (480.0f - s->field18);
    verts[2].x = 640.0f;
    verts[2].y = 480.0f;
    verts[3].x = 0.5f * s->field0C;
    verts[3].y = 480.0f;
    reinterpret_cast<ColorLineList *>(&poly)->draw_strip_swap_color(4, 22, -10.0f);

    colors[2] = 0;
    colors[3] = 0;
    verts[0].x = 0.5f * s->field0C;
    verts[0].y = 0.0f;
    verts[1].x = 0.5f * s->field0C;
    verts[1].y = 480.0f - 0.5f * (480.0f - s->field18);
    verts[2].x = s->field0C;
    verts[2].y = 480.0f - 0.5f * (480.0f - s->field18);
    verts[3].x = s->field0C;
    verts[3].y = 0.0f;
    reinterpret_cast<ColorLineList *>(&poly)->draw_strip_swap_color(4, 22, -10.0f);

    verts[0].x = 0.5f * s->field0C;
    verts[0].y = 480.0f - 0.5f * (480.0f - s->field18);
    verts[1].x = 640.0f;
    verts[1].y = 480.0f - 0.5f * (480.0f - s->field18);
    verts[2].x = 640.0f;
    verts[2].y = s->field18;
    verts[3].x = 0.5f * s->field0C;
    verts[3].y = s->field18;
    reinterpret_cast<ColorLineList *>(&poly)->draw_strip_swap_color(4, 22, -10.0f);

    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    a = (s32)(255.0f * alpha) << 24;
    set_draw_texture_and_color(11, a | 0xFFFFFF);

    for (y = s->field18; y > 0.0f; y -= 16.0f) {
        q.x0 = 0.0f;
        q.y0 = y - 16.0f;
        q.x1 = s->field0C;
        q.y1 = y;
        q.u0 = 0.07421875f;
        q.v0 = 0.93359375f;
        q.u1 = 0.13671875f;
        q.v1 = 0.99609375f;
        draw_textured_quad_at_depth((f32 *)&q, 0.1f);
    }
    for (y = s->field18; y < 480.0f; y += 16.0f) {
        q.x0 = 0.0f;
        q.y0 = y;
        q.x1 = 640.0f;
        q.y1 = 16.0f + y;
        q.u0 = 0.07421875f;
        q.v0 = 0.93359375f;
        q.u1 = 0.13671875f;
        q.v1 = 0.99609375f;
        draw_textured_quad_at_depth((f32 *)&q, 0.1f);
    }
    q.x0 = s->field0C;
    q.y0 = s->field18 - 16.0f;
    q.x1 = 16.0f + s->field0C;
    q.y1 = s->field18;
    q.u0 = 0.00390625f;
    q.v0 = 0.93359375f;
    q.u1 = 0.06640625f;
    q.v1 = 0.99609375f;
    draw_textured_quad_at_depth((f32 *)&q, 0.1f);
    TWindowSubStatusDisp::get_player();

    line.verts = lverts;
    line.colors = lcolors;
    line.tex = NULL;
    line.count = 2;
    lcolors[1] = lcolors[0] = a | 0xEDFF;
    lverts[0].x = s->field0C;
    lverts[0].y = s->field10;
    lverts[1].x = s->field0C;
    lverts[1].y = s->field18 - 16.0f;
    draw_color_lines(&line, 2, 4, -10.0f);
    lverts[0].x = 16.0f + s->field0C;
    lverts[0].y = s->field18;
    lverts[1].x = s->field14;
    lverts[1].y = s->field18;
    draw_color_lines(&line, 2, 4, -10.0f);
}
#pragma pop

s32 has_window_task_root(void) {
    return TWindowCtrlMain__window_task_root != NULL ? 1 : 0;
}

s32 is_window_display_enabled(void) {
    if (TWindowCtrlMain__display_flags & 1) return 0;
    return 1;
}

TObject *TWindowCtrlMain__sub_8024CE34(void) {
    return TWindowCtrlMain__viewport_states[4].window_root;
}

TObject *TWindowCtrlMain__sub_8024CE24(void) {
    return TWindowCtrlMain__viewport_states[5].window_root;
}

TObject *get_viewport_window_root(s32 viewport_index) {
    if (is_split_screen() != 0) {
        return TWindowCtrlMain__viewport_states[viewport_index].window_root;
    }
    return TWindowCtrlMain__viewport_states[0].window_root;
}

TObject *TWindowCtrlMain__sub_8024CDB0(void* p) { return get_viewport_window_root((saddr)p); }

void TWindowCtrlMain::set_value(s32 viewport_index, s32 arg1) {
    get_window_control_state(viewport_index)->field04 = arg1;
}

s32 TWindowCtrlMain__sub_8024CD5C(s32 viewport_index) {
    return get_window_control_state(viewport_index)->field04;
}

void TWindowCtrlMain::update_fade_alphas() {
    s32 i;
    for (i = 0; i < 4; i++) {
        Ent_8024CCDC *e = &((Ent_8024CCDC *)&TWindowCtrlMain__viewport_states)[i];
        f32 *q;
        if (e->fC >= 0.1f) {
            e->f8 += 0.09f;
        } else {
            e->f8 -= 0.09f;
        }
        q = &e->f8;
        if (*q > 1.0f) {
            *q = 1.0f;
        }
        if (*q < 0.0f) {
            *q = 0.0f;
        }
    }
}

WindowControlState* get_window_control_state(s32 viewport_index) {
    if (is_split_screen()) {
        return &TWindowCtrlMain__viewport_states[viewport_index];
    }
    return TWindowCtrlMain__viewport_states;
}

void TWindowCtrlMain::set_depth(f32 value, s32 viewport_index) {
    get_window_control_state(viewport_index)->field0C = value;
}

void TWindowCtrlMain::set_field18(f32 value, s32 viewport_index) {
    get_window_control_state(viewport_index)->field18 = value;
}

f32 TWindowCtrlMain::get_position_z(s32 viewport_index) {
    return get_window_control_state(viewport_index)->field0C;
}

f32 TWindowCtrlMain::get_field10(s32 viewport_index) {
    return get_window_control_state(viewport_index)->field10;
}

f32 TWindowCtrlMain::get_ctrl_field14(s32 viewport_index) {
    return get_window_control_state(viewport_index)->field14;
}

f32 TWindowCtrlMain::get_field_18(s32 viewport_index) {
    return get_window_control_state(viewport_index)->field18;
}

void TWindowCtrlMain__sub_8024CB8C() {
    TWindowCtrlMain__display_flags &= ~1;
}

void TWindowCtrlMain__sub_8024CB7C() {
    TWindowCtrlMain__display_flags |= 1;
}

f32 TWindowCtrlMain::get_scale() {
    return window_depth_order_cursor;
}

TWindowCtrlScreen::TWindowCtrlScreen(TObject *parent) : TObject(parent) {
    m_name = TWindowCtrlScreen__name;
}

TWindowCtrlScreen::~TWindowCtrlScreen() {
    TWindowCtrlMain__screen_controller = NULL;
}

void TWindowCtrlScreen::render() {
    u16 viewport_index;
    if (is_window_display_enabled() != 0) {
        viewport_index = (s32)TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_no());
        set_default_alpha_blend();
        TParticleCtrl::begin_effect_render();
        TWindowCtrlMain__instance->render_nodes();
        TWindowCtrlMain__sub_8024D2A4(viewport_index);
        TCameraCtrl::restore_full_screen_view();
        draw_menu_backdrop_gradients(viewport_index);
        get_viewport_window_root(viewport_index)->render_nodes();
        TCameraCtrl::restore_saved_view();
        TParticleCtrl::end_effect_render();
    }
}

TWindowCtrlSub::TWindowCtrlSub(TObject *parent) : TObject(parent) {
    m_name = TWindowCtrlSub__name;
}

TWindowCtrlSub::~TWindowCtrlSub() {
    TWindowCtrlMain__sub_controller = NULL;
}

void TWindowCtrlSub::run_task() {
    resolve_chat_balloon_overlaps();
    TWindowCtrlMain::update_fade_alphas();
    TWindowCtrlMain__window_task_root->run_tasks();
}

TWindowCtrlClipOut::TWindowCtrlClipOut(TObject *parent) : TObject(parent) {
    m_name = TWindowCtrlClipOut__name;
}

TWindowCtrlClipOut::~TWindowCtrlClipOut() {
    window_clip_out_instance = NULL;
}

void TWindowCtrlClipOut::render() {
    if (is_window_display_enabled() != 0) {
        set_default_alpha_blend();
        TParticleCtrl::begin_effect_render();
        TCameraCtrl::restore_full_screen_view();
        TWindowCtrlMain__sub_8024CE34()->render_nodes();
        TCameraCtrl::restore_saved_view();
        TParticleCtrl::end_effect_render();
    }
}

void TWindowCtrlMain::init_fields() { *(int *)&this->m_name = 0; *(int *)&this->m_flags = 0; *(float *)&this->m_prev = 0.0f; *(float *)&this->m_next = 0.0f; *(float *)&this->m_up = 0.0f; *(float *)&this->m_down = 640.0f; *(float*)((char*)this + 0x18) = 480.0f; }

void TWindowCtrlMain::release_ptr(void **arg0) {
    VObj_8024C820 *obj = (VObj_8024C820 *)*arg0;
    if (obj) {
        if (obj) {
            obj->m0(1);
        }
        *arg0 = NULL;
    }
}
