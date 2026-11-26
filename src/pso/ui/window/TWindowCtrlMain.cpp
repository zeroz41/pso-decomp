#include "pso/ui/window/WindowDrawContext.h"
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
#include "pso/ui/window/TWindowMessageInfomation.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
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
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/window/TWindowSubEquip.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/object/TObjLuker.h"
#include "pso/unk/text_80269FE8.h"
#include "pso/unk/text_80271400.h"

#include "pso/ui/window/TWindowDD.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/window/TWindowCtrl_8024A1A8.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/WindowLayout.h"
const char *window_ctrl_main_class_name = "TWindowCtrlMain";
const char *window_ctrl_screen_class_name = "TWindowCtrlScreen";
const char *window_ctrl_sub_class_name = "TWindowCtrlSub";
const char *window_ctrl_clip_out_class_name = "TWindowCtrlClipOut";
const char *window_ctrl_player_class_name = "TWindowCtrlPlayer";

// width, height of the player message window (set_message_window_size stores it as the window size)
const f32 lbl_8044EC4C[2] = {255.0f, 120.0f};
s32 TWindowCtrlMain::display_flags;
TObject *TWindowCtrlMain::instance;
TObject *TWindowCtrlMain::window_task_root;
TWindowCtrlScreen *TWindowCtrlMain::screen_controller;
TWindowCtrlSub *TWindowCtrlMain::sub_controller;
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
extern "C" void draw_viewport_fill(s32 viewport_index);
WindowControlState TWindowCtrlMain::viewport_states[6];
extern "C" {
struct Poly_8024CE68 {
    NJS_POINT2 *verts;
    u32 *colors;
    s32 flags;
    s32 count;
};
}
extern "C" s32 fn_8002AE08(s32 client_id);

TWindowCtrlPlayer::TWindowCtrlPlayer(TObject *parent, s32 client_id) : TObject(parent) {
    m_name = window_ctrl_player_class_name;
    flags = 0;
    open_timer = 0;
    countdown = 0;
    this->client_id = client_id;
    main_menu = NULL;
    message_information = NULL;
    simple_status = NULL;
    action_palette = NULL;
    lock_on_window = NULL;
    short_list = NULL;
    if (is_split_screen() != 0) {
        main_menu = new TWindowMainMenu4P(this, this->client_id);
    } else {
        main_menu = new TWindowMainMenu1P(this, this->client_id);
    }
    message_information = (TWindowMessageInfomation *)create_message_information_window(get_window_layout_position(0x20), (saddr)lbl_8044EC4C, this->client_id);
    simple_status = create_status_window(this->client_id);
    simple_status->suspend_update();
    action_palette = new TWindowActionPalette(this->client_id);
    action_palette->suspend_update();
}

TWindowCtrlPlayer::~TWindowCtrlPlayer() {
    if (short_list != NULL) { short_list->queue_destruction(); short_list = NULL; }
    if (lock_on_window != NULL) { lock_on_window->close(); lock_on_window = NULL; }
    if (action_palette != NULL) { action_palette->close(); action_palette = NULL; }
    if (simple_status != NULL) { simple_status->close(); simple_status = NULL; }
    if (message_information != NULL) { message_information->close(); message_information = NULL; }
    if (main_menu != NULL) { main_menu->queue_destruction(); main_menu = NULL; }
}

void TWindowCtrlPlayer::run_task() { update_open_sequence(); run_all_updates(); }

void TWindowCtrlPlayer::render() {  }

#pragma push
#pragma scheduling off
void TWindowCtrlPlayer::update_open_sequence() {
    switch (open_timer) {
    case 18:
        if (simple_status != NULL) {
            simple_status->clear_update_suspension();
        }
        break;
    case 38:
        if (is_current_area_item_enabled() != 0) {
            if (action_palette != NULL) {
                action_palette->clear_update_suspension();
            }
        }
        break;
    }
    if (open_timer > 0x7530) {
        open_timer -= 0x2710;
    }
    open_timer++;
}
#pragma pop

void TWindowCtrlPlayer::run_all_updates() { update_trade_window_visibility(); update_child_window_visibility(); update_target_info_window(); update_main_menu_request(); show_active_window(); update_short_list_request(); update_countdown(); }

void TWindowCtrlPlayer::update_trade_window_visibility() {
    if ((simple_status != NULL) && (((TWindowCtrl *)(void *)simple_status)->is_flag_2_set() == 0)) {
        if ((get_player_by_client_id(client_id) == NULL) || (is_suppressed() != 0) || (is_status_window_hidden() != 0) || ((is_split_screen() != 0) && (is_main_menu_open() != 0))) {
            simple_status->request_close();
            return;
        }
        window_request_show(simple_status);
    }
}

void TWindowCtrlPlayer::update_child_window_visibility() {
    TObjPlayer *player;
    if ((action_palette != NULL) && (((TWindowCtrl *)(void *)action_palette)->is_flag_2_set() == 0)) {
        player = get_player_by_client_id(client_id);
        if ((is_main_menu_open() != 0) || (is_suppressed() != 0) || (is_keyboard_held() != 0) || (player == NULL)) {
            action_palette->request_close();
            return;
        }
        window_request_show(action_palette);
    }
}

#pragma push
#pragma fp_contract on
void TWindowCtrlPlayer::update_target_info_window() {
    if ((lock_on_window != NULL) && ((lock_on_window->all_parents_unqueued_for_destruction() == 0) || (lock_on_window->is_open_and_unblocked() == 0))) {
        lock_on_window = NULL;
    }
    if ((is_lock_on_window_hidden() != 0) || (is_main_menu_open() != 0) || (is_suppressed() != 0) || (has_short_list() != 0) || (TWindowCtrl__sub_8024A314() != 0)) {
        if (lock_on_window != NULL) {
            lock_on_window->close();
            lock_on_window = NULL;
        }
    } else {
        u16 id = TObjPlayer::get_battle_ctrl_id(client_id);
        if (id != 0xFFFF) {
            TWindowLockOn *w = lock_on_window;
            if (w == NULL) {
                lock_on_window = TWindowLockOn::create_for_target(client_id, id);
            } else {
                w->bind_target(id);
            }
        }
    }
}
#pragma pop

void TWindowCtrlPlayer::update_main_menu_request() {
    TObjPlayer *player;
    s16 key;
    if (main_menu == NULL) {
        return;
    }
    player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return;
    }
    if (player->is_inactive() == 0) {
        return;
    }
    if (is_suppressed() != 0 || is_main_menu_disabled() != 0) {
        main_menu->close_main_menu();
        return;
    }
    {
        s32 idx = is_player_input_active(client_id);
        key = TKeyBoardControl::get_function_key_menu(this);
        if (test_pressed_buttons_packed(&controller_input_state.controllers[idx], 0x108) == 0 && key == 0x1F) {
            return;
        }
    }
    if (is_main_menu_open() != 0) {
        if (is_main_menu_locked() == 0) {
            main_menu->close_main_menu();
        }
        return;
    }
    if (short_list != NULL) {
        short_list->queue_destruction();
        short_list = NULL;
        return;
    }
    if (TWindowCtrl::get_active_sub() != 0) {
        TWindowCtrl::update_focused();
        return;
    }
    if ((u32)player->is_action_active() != 0) {
        return;
    }
    if (key == 0x1F) {
        main_menu->open_main_menu();
        return;
    }
    main_menu->try_open_battle_menu(key);
}

void TWindowCtrlPlayer::show_active_window() {
    if (message_information != NULL) {
        if (is_suppressed() != 0) {
            message_information->request_close();
            return;
        }
        window_request_show(message_information);
        if (is_main_menu_open() != 0) {
            message_information->set_position((f32 *)get_window_layout_position(0x21));
            return;
        }
        message_information->set_position((f32 *)get_window_layout_position(0x20));
    }
}

void TWindowCtrlPlayer::update_short_list_request() {
    s32 idx;
    u16 id;
    ControllerInputContext *btn;
    if (short_list != NULL && short_list->all_parents_unqueued_for_destruction() == 0) {
        short_list = NULL;
    }
    if (action_palette != NULL && ((TWindowCtrl *)(void *)action_palette)->is_flag_2_set() == 0) {
        if (get_player_by_client_id(client_id) == NULL) {
            if (short_list != NULL) {
                short_list->queue_destruction();
                short_list = NULL;
            }
        } else {
            idx = is_player_input_active(client_id);
            id = TObjPlayer::get_current_target_id();
            if (is_main_menu_open() != 0 || is_suppressed() != 0 ||
                (id != 0xFFFF && id != client_id) || is_main_menu_disabled() != 0 ||
                TWindowCtrl::get_display_flag() != 0) {
                if (short_list != NULL) {
                    short_list->queue_destruction();
                    short_list = NULL;
                }
            } else if (short_list == NULL && is_keyboard_held() == 0) {
                if (test_previous_buttons_packed(btn = &controller_input_state.controllers[idx], fn_8002AE08(client_id)) != 0 &&
                    test_pressed_buttons_packed(btn, 0x200) != 0) {
                    short_list = new TWindowShortListCtrl(this, client_id);
                }
            }
        }
    }
}

void TWindowCtrlPlayer::update_countdown() {
    if (countdown > 0) {
        countdown--;
    }
}

s16 TKeyBoardControl::get_function_key_menu(void *menu) {
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
    if (TKeyBoardControl::is_key_down(0x4B) != 0) {
        return 0;
    }
    return 0x1F;
}

s32 TWindowCtrlPlayer::is_main_menu_open() {
    TWindowMainMenu *menu = main_menu;
    if (menu == NULL) {
        return 0;
    }
    return menu->is_open();
}

s32 TWindowCtrlPlayer::is_log_active() {
    TWindowMainMenu *menu = main_menu;
    if (menu == NULL) {
        return 0;
    }
    return menu->is_log_active();
}

void TWindowCtrlPlayer::try_open_battle_menu(s16 key) {
    if (main_menu != NULL) {
        main_menu->try_open_battle_menu(key);
    }
}

void TWindowCtrlPlayer::replace_submenu(s16 id) {
    if (main_menu != NULL) {
        main_menu->replace_submenu(id);
    }
}

void TWindowCtrlPlayer::spawn_palette_slot_light(s32 kind) {
    if (action_palette != NULL) {
        spawn_action_palette_slot_light(action_palette, kind);
    }
}

void TWindowCtrlPlayer::append_message_line(const char *text, s32 mode) {
    if (message_information != NULL) {
        message_information->append_line((saddr)text, mode);
    }
}

s32 TWindowCtrlPlayer::is_countdown_done() {
    return this->countdown <= 0 ? 1 : 0;
}

void TWindowCtrlPlayer::start_countdown() { this->countdown = 60; }

void TWindowCtrlMain::reset_windows(void) { TWindowCtrlMain::reset_all((void*)((void*)(0))); }

void TWindowCtrlMain::reset_all(void* _w0) {
    s32 i;
    load_hud_palette_textures();
    clear_shared_window_draw_context();
    WindowDrawContext::get_or_create_instance();
    TWindowCtrlMain::display_flags = 0;
    TWindowCtrlMain::window_task_root = NULL;
    TWindowCtrlMain::screen_controller = NULL;
    TWindowCtrlMain::sub_controller = NULL;
    window_clip_out_instance = NULL;
    TWindowCtrlMain::instance = NULL;
    window_depth_order_cursor = -1.5999999f;
    for (i = 0; i < 6; i++) {
        TWindowCtrlMain::viewport_states[i].init();
    }
}

void TWindowCtrlMain::free_all_windows() {
    TObject *root;
    s32 i;
    root = TWindowCtrlMain::window_task_root;
    TWindowCtrlMain::window_task_root = NULL;
    if (window_clip_out_instance != NULL) {
        delete window_clip_out_instance;
        window_clip_out_instance = NULL;
    }
    if (TWindowCtrlMain::sub_controller != NULL) {
        delete TWindowCtrlMain::sub_controller;
        TWindowCtrlMain::sub_controller = NULL;
    }
    if (TWindowCtrlMain::screen_controller != NULL) {
        delete TWindowCtrlMain::screen_controller;
        TWindowCtrlMain::screen_controller = NULL;
    }
    for (i = 5; i >= 0; i--) {
        TWindowCtrlMain::release_ptr((void **)&TWindowCtrlMain::viewport_states[i].window_root);
    }
    if (TWindowCtrlMain::instance != NULL) {
        delete TWindowCtrlMain::instance;
        TWindowCtrlMain::instance = NULL;
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
    m_name = window_ctrl_main_class_name;
    if (TWindowCtrlMain::window_task_root == NULL) {
        TWindowCtrlMain::window_task_root = new TObject(NULL);
    }
    if (TWindowCtrlMain::instance == NULL) {
        TWindowCtrlMain::instance = new TObject(TWindowCtrlMain::window_task_root);
    }
    for (i = 0; i < 6; i++) {
        e = &TWindowCtrlMain::viewport_states[i];
        e->init();
        e->window_root = new TObject(TWindowCtrlMain::window_task_root);
    }
    if (TWindowCtrlMain::screen_controller == NULL) {
        TWindowCtrlMain::screen_controller = new TWindowCtrlScreen(tl_window);
    }
    if (TWindowCtrlMain::sub_controller == NULL) {
        TWindowCtrlMain::sub_controller = new TWindowCtrlSub(tl_01);
    }
    if (window_clip_out_instance == NULL) {
        window_clip_out_instance = new TWindowCtrlClipOut(tl_clipout);
    }
}

TWindowCtrlMain::~TWindowCtrlMain() {
    TObject *root;
    s32 i;
    root = TWindowCtrlMain::window_task_root;
    TWindowCtrlMain::window_task_root = NULL;
    if (window_clip_out_instance != NULL) {
        delete window_clip_out_instance;
        window_clip_out_instance = NULL;
    }
    if (TWindowCtrlMain::sub_controller != NULL) {
        delete TWindowCtrlMain::sub_controller;
        TWindowCtrlMain::sub_controller = NULL;
    }
    if (TWindowCtrlMain::screen_controller != NULL) {
        delete TWindowCtrlMain::screen_controller;
        TWindowCtrlMain::screen_controller = NULL;
    }
    for (i = 5; i >= 0; i--) {
        TWindowCtrlMain::release_ptr((void **)&TWindowCtrlMain::viewport_states[i].window_root);
    }
    if (TWindowCtrlMain::instance != NULL) {
        delete TWindowCtrlMain::instance;
        TWindowCtrlMain::instance = NULL;
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
    get_main_window_root()->render_nodes();
    TCameraCtrl::restore_saved_view();
    TParticleCtrl::end_effect_render();
}

void draw_viewport_fill(s32 viewport_index) {
    NJS_POINT2 verts[4];
    Poly_8024CE68 poly;
    u32 colors[4];
    u32 color;

    color = get_window_control_state(viewport_index)->fill_color;
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
    TexturedQuad q;
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
    alpha = s->backdrop_alpha;
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
    verts[1].x = 0.5f * s->left;
    verts[1].y = 0.0f;
    verts[2].x = 0.5f * s->left;
    verts[2].y = 480.0f;
    verts[3].x = 0.0f;
    verts[3].y = 480.0f;
    reinterpret_cast<ColorLineList *>(&poly)->draw_strip_swap_color(4, 22, -10.0f);

    verts[0].x = 0.5f * s->left;
    verts[0].y = 480.0f - 0.5f * (480.0f - s->bottom);
    verts[1].x = 640.0f;
    verts[1].y = 480.0f - 0.5f * (480.0f - s->bottom);
    verts[2].x = 640.0f;
    verts[2].y = 480.0f;
    verts[3].x = 0.5f * s->left;
    verts[3].y = 480.0f;
    reinterpret_cast<ColorLineList *>(&poly)->draw_strip_swap_color(4, 22, -10.0f);

    colors[2] = 0;
    colors[3] = 0;
    verts[0].x = 0.5f * s->left;
    verts[0].y = 0.0f;
    verts[1].x = 0.5f * s->left;
    verts[1].y = 480.0f - 0.5f * (480.0f - s->bottom);
    verts[2].x = s->left;
    verts[2].y = 480.0f - 0.5f * (480.0f - s->bottom);
    verts[3].x = s->left;
    verts[3].y = 0.0f;
    reinterpret_cast<ColorLineList *>(&poly)->draw_strip_swap_color(4, 22, -10.0f);

    verts[0].x = 0.5f * s->left;
    verts[0].y = 480.0f - 0.5f * (480.0f - s->bottom);
    verts[1].x = 640.0f;
    verts[1].y = 480.0f - 0.5f * (480.0f - s->bottom);
    verts[2].x = 640.0f;
    verts[2].y = s->bottom;
    verts[3].x = 0.5f * s->left;
    verts[3].y = s->bottom;
    reinterpret_cast<ColorLineList *>(&poly)->draw_strip_swap_color(4, 22, -10.0f);

    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    a = (s32)(255.0f * alpha) << 24;
    set_draw_texture_and_color(11, a | 0xFFFFFF);

    for (y = s->bottom; y > 0.0f; y -= 16.0f) {
        q.x0 = 0.0f;
        q.y0 = y - 16.0f;
        q.x1 = s->left;
        q.y1 = y;
        q.u0 = 0.07421875f;
        q.v0 = 0.93359375f;
        q.u1 = 0.13671875f;
        q.v1 = 0.99609375f;
        draw_textured_quad_at_depth((f32 *)&q, 0.1f);
    }
    for (y = s->bottom; y < 480.0f; y += 16.0f) {
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
    q.x0 = s->left;
    q.y0 = s->bottom - 16.0f;
    q.x1 = 16.0f + s->left;
    q.y1 = s->bottom;
    q.u0 = 0.00390625f;
    q.v0 = 0.93359375f;
    q.u1 = 0.06640625f;
    q.v1 = 0.99609375f;
    draw_textured_quad_at_depth((f32 *)&q, 0.1f);
    end_screen_draw();

    line.verts = lverts;
    line.colors = lcolors;
    line.tex = NULL;
    line.count = 2;
    lcolors[1] = lcolors[0] = a | 0xEDFF;
    lverts[0].x = s->left;
    lverts[0].y = s->top;
    lverts[1].x = s->left;
    lverts[1].y = s->bottom - 16.0f;
    draw_color_lines(&line, 2, 4, -10.0f);
    lverts[0].x = 16.0f + s->left;
    lverts[0].y = s->bottom;
    lverts[1].x = s->right;
    lverts[1].y = s->bottom;
    draw_color_lines(&line, 2, 4, -10.0f);
}
#pragma pop

s32 has_window_task_root(void) {
    return TWindowCtrlMain::window_task_root != NULL ? 1 : 0;
}

s32 is_window_display_enabled(void) {
    if (TWindowCtrlMain::display_flags & 1) return 0;
    return 1;
}

TObject *get_clip_out_window_root(void) {
    return TWindowCtrlMain::viewport_states[4].window_root;
}

TObject *get_main_window_root(void) {
    return TWindowCtrlMain::viewport_states[5].window_root;
}

TObject *get_viewport_window_root(s32 viewport_index) {
    if (is_split_screen() != 0) {
        return TWindowCtrlMain::viewport_states[viewport_index].window_root;
    }
    return TWindowCtrlMain::viewport_states[0].window_root;
}

TObject *TWindowCtrlMain__sub_8024CDB0(void* p) { return get_viewport_window_root((saddr)p); }

void TWindowCtrlMain::set_fill_color(s32 viewport_index, s32 color) {
    get_window_control_state(viewport_index)->fill_color = color;
}

s32 get_viewport_fill_color(s32 viewport_index) {
    return get_window_control_state(viewport_index)->fill_color;
}

void TWindowCtrlMain::update_fade_alphas() {
    s32 i;
    for (i = 0; i < 4; i++) {
        WindowControlState *e = &TWindowCtrlMain::viewport_states[i];
        f32 *q;
        if (e->left >= 0.1f) {
            e->backdrop_alpha += 0.09f;
        } else {
            e->backdrop_alpha -= 0.09f;
        }
        q = &e->backdrop_alpha;
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
        return &TWindowCtrlMain::viewport_states[viewport_index];
    }
    return TWindowCtrlMain::viewport_states;
}

void TWindowCtrlMain::set_left(f32 value, s32 viewport_index) {
    get_window_control_state(viewport_index)->left = value;
}

void TWindowCtrlMain::set_bottom(f32 value, s32 viewport_index) {
    get_window_control_state(viewport_index)->bottom = value;
}

f32 TWindowCtrlMain::get_left(s32 viewport_index) {
    return get_window_control_state(viewport_index)->left;
}

f32 TWindowCtrlMain::get_top(s32 viewport_index) {
    return get_window_control_state(viewport_index)->top;
}

f32 TWindowCtrlMain::get_right(s32 viewport_index) {
    return get_window_control_state(viewport_index)->right;
}

f32 TWindowCtrlMain::get_bottom(s32 viewport_index) {
    return get_window_control_state(viewport_index)->bottom;
}

void TWindowCtrlMain::enable_display() {
    TWindowCtrlMain::display_flags &= ~1;
}

void TWindowCtrlMain::disable_display() {
    TWindowCtrlMain::display_flags |= 1;
}

f32 TWindowCtrlMain::get_scale() {
    return window_depth_order_cursor;
}

TWindowCtrlScreen::TWindowCtrlScreen(TObject *parent) : TObject(parent) {
    m_name = window_ctrl_screen_class_name;
}

TWindowCtrlScreen::~TWindowCtrlScreen() {
    TWindowCtrlMain::screen_controller = NULL;
}

void TWindowCtrlScreen::render() {
    u16 viewport_index;
    if (is_window_display_enabled() != 0) {
        viewport_index = (s32)TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_no());
        set_default_alpha_blend();
        TParticleCtrl::begin_effect_render();
        TWindowCtrlMain::instance->render_nodes();
        draw_viewport_fill(viewport_index);
        TCameraCtrl::restore_full_screen_view();
        draw_menu_backdrop_gradients(viewport_index);
        get_viewport_window_root(viewport_index)->render_nodes();
        TCameraCtrl::restore_saved_view();
        TParticleCtrl::end_effect_render();
    }
}

TWindowCtrlSub::TWindowCtrlSub(TObject *parent) : TObject(parent) {
    m_name = window_ctrl_sub_class_name;
}

TWindowCtrlSub::~TWindowCtrlSub() {
    TWindowCtrlMain::sub_controller = NULL;
}

void TWindowCtrlSub::run_task() {
    resolve_chat_balloon_overlaps();
    TWindowCtrlMain::update_fade_alphas();
    TWindowCtrlMain::window_task_root->run_tasks();
}

TWindowCtrlClipOut::TWindowCtrlClipOut(TObject *parent) : TObject(parent) {
    m_name = window_ctrl_clip_out_class_name;
}

TWindowCtrlClipOut::~TWindowCtrlClipOut() {
    window_clip_out_instance = NULL;
}

void TWindowCtrlClipOut::render() {
    if (is_window_display_enabled() != 0) {
        set_default_alpha_blend();
        TParticleCtrl::begin_effect_render();
        TCameraCtrl::restore_full_screen_view();
        get_clip_out_window_root()->render_nodes();
        TCameraCtrl::restore_saved_view();
        TParticleCtrl::end_effect_render();
    }
}

void WindowControlState::init() {
    window_root = NULL;
    fill_color = 0;
    backdrop_alpha = 0.0f;
    left = 0.0f;
    top = 0.0f;
    right = 640.0f;
    bottom = 480.0f;
}

void TWindowCtrlMain::release_ptr(void **ptr) {
    VObj_8024C820 *obj = (VObj_8024C820 *)*ptr;
    if (obj) {
        if (obj) {
            obj->m0(1);
        }
        *ptr = NULL;
    }
}
