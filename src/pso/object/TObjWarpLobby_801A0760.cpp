#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TPlyJoinLobbyEntry.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObjWarpLobby_801A0760.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/object/TObjWarpLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjWarpLobby_801A0A34.h"

struct WarpLobbyBase_801A07F8 { char pad[0x18]; };
struct WarpLobbyVObj_801A07F8 : WarpLobbyBase_801A07F8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct VB_801A0894 { char pad[0x18]; };

struct VO_801A0894 : VB_801A0894 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13();
    virtual s32 m14();
};

extern "C" {
void request_active_window_close(void);
s32 align_menu_entry_positions(s32);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(f32 *, s32, f32);
extern s32 warp_lobby_directory_label_table[];

s32 queue_destruction__7TObjectFv(u32);
s32 is_idle__6TLobbyFv();
u32 find_warp_player_in_range(void *, u16, f32);
extern s32 local_client_id;

void run_task__13TObjWarpLobbyFv(VO_801A0894 *arg0);
s32 post_translate_matrix(void *);
s32 draw_ginja_model_with_motion(s32, s32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __dl__7TObjectFPv(void *);
u8 *__dt__12TObjAreaWarpFv(u8 *arg0, s16 arg1);

extern u8 *TObjWarpLobby__instance;
extern s32 lbl_805D5CCC;

void TObjWarpLobby::open_lobby_menu() {
    f32 sp[2];
    s32 i;
    sp[0] = 4.5e+02f;
    sp[1] = 1e+02f;
    this->m_cc = check_room_seq_4__16TAdChrSelASlotGCFl(sp, 0xF, 4.5e+02f);
    for (i = 0; i < 0xF; i++) {
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)this->m_cc, (int)warp_lobby_directory_label_table[i], 6, (int)i);
    }
    ((TWindowSubComCard *)(this->m_cc))->calc_window_size();
    align_menu_entry_positions(this->m_cc);
    ((TWindowSubComCardList *)(this->m_cc))->set_flag70_bit10();
    request_active_window_close();
}

void TObjWarpLobby::render() {
    u8 *arg0 = (u8 *)this;
    if (((s32) *(s32 *)((s8 *)arg0 + 0xCC) != 0) && (((WarpLobbyVObj_801A07F8*)arg0)->m8(4e+02f, 2e+01f) != 0)) {
        TObjFish::set_global_param(lbl_805D5CCC);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(*(s32 *)((s8 *)(*(void **)((s8 *)TObjWarpLobby__instance + 0x42C)) + 8), *(s32 *)((s8 *)(*(void **)((s8 *)TObjWarpLobby__instance + 0x430)) + 4), this->m_c8);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

extern s32 __vt__13TObjWarpLobby[];

void run_task__13TObjWarpLobbyFv(VO_801A0894 *arg0) {
    s32 selected_menu_value;
    ((TObjWarpLobby *)arg0)->m_c8 += 4.0f;
    if ((f32) (*(u32 *)((s8 *)(*(void **)((s8 *)arg0 + 0xD8)) + 4) - 1) < ((TObjWarpLobby *)arg0)->m_c8) {
        ((TObjWarpLobby *)arg0)->m_c8 = (f32) 0.0f;
    }
    *(f32 *)((s8 *)arg0 + 0xC4) += 336.0f;
    if ((find_warp_player_in_range(arg0, (u16) local_client_id, *(f32 *)((s8 *)arg0 + 0xAC)) != 0U) && (arg0->m14() != 0)) {
        if (((u32) ((TObjWarpLobby *)arg0)->m_cc == 0U) && (is_idle__6TLobbyFv() != 0)) {
            ((TObjWarpLobby *)arg0)->open_lobby_menu();
        }
        if (((u32) ((TObjWarpLobby *)arg0)->m_cc != 0U) && (((TWindowMenu *)(((TObjWarpLobby *)arg0)->m_cc))->is_decided() != 0)) {
            selected_menu_value = ((TWindowMenu *)(((TObjWarpLobby *)arg0)->m_cc))->get_selected_value();
            if (((TObjWarpLobby *)arg0)->m_cc != 0U) {
                queue_destruction__7TObjectFv(((TObjWarpLobby *)arg0)->m_cc);
                ((TObjWarpLobby *)arg0)->m_cc = 0U;
                TWindowCtrl::clear_flag();
            }
            send_room_change__6TLobbyFi(selected_menu_value);
        }
    } else if ((u32) ((TObjWarpLobby *)arg0)->m_cc != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0xB0)))->close();
        ((TObjWarpLobby *)arg0)->m_cc = 0U;
        TWindowCtrl::clear_flag();
    }
}

void *__dt__13TObjWarpLobbyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TObjWarpLobby;
        __dt__12TObjAreaWarpFv((u8 *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

extern "C" {

s32 TObjAreaWarp__ct();

extern s32 __vt__13TObjWarpLobby[];
extern s32 lbl_805D34A0;

void *TObjWarpLobby__ct(TObjWarpLobby *warp_lobby) {

    TObjAreaWarp__ct();
    *(s32 **)((s8 *)warp_lobby + 0x18) = __vt__13TObjWarpLobby;
    *(s32 *)((s8 *)warp_lobby + 0) = (s32) lbl_805D34A0;
    warp_lobby->m_c8 = (f32) 0.0f;
    *(f32 *)((s8 *)warp_lobby + 0xC4) = (f32) 0.0f;
    warp_lobby->m_cc = 0;
    *(s32 *)((s8 *)warp_lobby + 0xD0) = 0;
    *(s32 *)((s8 *)warp_lobby + 0xD4) = 0;
    *(s32 *)((s8 *)warp_lobby + 0xD8) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)TObjWarpLobby__instance + 0x430)) + 4);
    *(s32 *)((s8 *)warp_lobby + 0xDC) = 0;
    if ((s32) *(s32 *)((s8 *)warp_lobby + 0x88) < 0) {
        *(s32 *)((s8 *)warp_lobby + 0x88) = 0;
    }
    if ((s32) *(s32 *)((s8 *)warp_lobby + 0x88) > 1) {
        *(s32 *)((s8 *)warp_lobby + 0x88) = 1;
    }
    switch (*(s32 *)((s8 *)warp_lobby + 0x88)) {
    case 0:
        *(s32 *)((s8 *)warp_lobby + 0xCC) = 1;
        break;
    case 1:
        *(s32 *)((s8 *)warp_lobby + 0xCC) = 0;
        break;
    default:
        *(s32 *)((s8 *)warp_lobby + 0xCC) = 1;
        break;
    }
    return warp_lobby;
}

}
