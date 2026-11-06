#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/object/TObjWarpBossMulti.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/object/TObjCityMainWarpChallenge.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjFish.h"
#include "pso/map/FloorArea.h"

void initialize_option_dialog(void *dialog, s32 message, s32 position, f32 width);

struct Warp_80187438 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0xAC - 0x44];
    f32 radius;
    u8 padb0[0xBC - 0xB0];
    s32 dest_floor;
    u8 padc0[0xE4 - 0xC0];
    char names[4][0x18];
    s32 inside[4];
    s32 count;
    s32 n_inside;
    s32 player_on_dest_floor;
    u8 pad160[4];
    u32 player_list_window;
};

struct Player_80187438 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0x85C - 0x44];
    char name[0x18];
};

struct CityMainWarpChalBase_80187824 { char pad[0x18]; };
struct CityMainWarpChalVObj_80187824 : CityMainWarpChalBase_80187824 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Warp_80187B50 { u8 pad[0x144]; s32 arr[4]; };

extern "C" {
s32 get_current_floor(void);
f32 xz_distance_squared(void *, void *);
void *get_player_by_client_id(s32 i);
char *strcpy(char *, const char *);
extern s32 local_client_id;
s32 is_local_client_floor_leader(s32);
s32 find_local_player_in_range__16TObjCityMainWarpFf(void *, f32);
s32 close_windows__25TObjCityMainWarpChallengeFv();
void TObjCityMainWarp__sub_801875F8(TObjCityMainWarpChallenge *self);
s32 fn_80248994(void *, u32, int);
void request_active_window_close(void);
void begin_player_keyboard_hold(s32 arg0);
s32 get_window_layout_position(s32);
s32 free_member__17TWindowSubComCardFv(void *, int);
s32 forward_slot_selection__16TAdChrSelASlotGCFPvPv(void *, s32, s32, f32);
s32 play_sound_effect(s32, void *, s32, s32);
s32 get_main_phase();
extern s32 city_main_warp_destination_id;
s32 register_entity_by_id(void *, int, f32);
s32 TObjAreaWarp__ct();
extern s32 __vt__25TObjCityMainWarpChallenge[];
extern s32 lbl_805D32B8;
extern u8 *city_common_model_archive;
void debug_printf_at(s32 id, const char *fmt, ...);
extern char lbl_80444A44[];
extern char lbl_80444A58[];
s32 post_translate_matrix(void *);
s32 update_floor_switch_state__16TObjCityMainWarpFv();
s32 update_warp_sequence__16TObjCityMainWarpFv();
s32 draw_ginja_model_with_motion(s32, s32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 __dl__7TObjectFPv(void *);
u8 *__dt__12TObjAreaWarpFv(u8 *arg0, s16 arg1);
s32 update_challenge_warp_window();
s32 update_state__16TObjCityMainWarpFv();
extern s32 camera_ctrl_instance;
extern s32 city_common_texture_list;

u8 *TObjCityMainWarpChallenge__ct(u8 *city_main_warp_challenge) {
    s32 var_r3;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r4;
    s32 var_ctr;
    TObjAreaWarp__ct();
    *(s32 **)((s8 *)city_main_warp_challenge + 0x18) = __vt__25TObjCityMainWarpChallenge;
    *(s32 *)((s8 *)city_main_warp_challenge + 0) = (s32) lbl_805D32B8;
    *(f32 *)((s8 *)city_main_warp_challenge + 0xC4) = 0.0f;
    *(f32 *)((s8 *)city_main_warp_challenge + 0xAC) = 19.0f;
    *(s32 *)((s8 *)city_main_warp_challenge + 0xBC) = (s32) ((TObjCityMainWarpChallenge *)city_main_warp_challenge)->set_params[0];
    temp_r4 = *(s32 *)((s8 *)city_main_warp_challenge + 0xBC);
    city_main_warp_destination_id = temp_r4;
    *(s32 *)((s8 *)city_main_warp_challenge + 0xA4) = 0;
    register_entity_by_id(city_main_warp_challenge, temp_r4, 0.0f);
    *(s32 *)((s8 *)city_main_warp_challenge + 0x164) = 0;
    *(s32 *)((s8 *)city_main_warp_challenge + 0x168) = 0;
    if (get_current_floor_area() == AREA_PIONEER2_EP1) {
        *(s32 *)((s8 *)city_main_warp_challenge + 0x16C) = -1;
    } else {
        temp_r0 = *(s32 *)((s8 *)city_main_warp_challenge + 0x88);
        if ((temp_r0 < 0) || (temp_r0 > 0xFF)) {
            *(s32 *)((s8 *)city_main_warp_challenge + 0x16C) = -1;
        } else {
            *(s32 *)((s8 *)city_main_warp_challenge + 0x16C) = temp_r0;
        }
    }
    if ((s32) *(s32 *)((s8 *)city_main_warp_challenge + 0x16C) >= 0) {
        *(s16 *)((s8 *)city_main_warp_challenge + 0xDC) = 4;
        *(s16 *)((s8 *)city_main_warp_challenge + 0xDE) = 4;
    } else {
        *(s16 *)((s8 *)city_main_warp_challenge + 0xDC) = 0;
        *(s16 *)((s8 *)city_main_warp_challenge + 0xDE) = 0;
    }
    *(s16 *)((s8 *)city_main_warp_challenge + 0xE0) = 0;
    *(s16 *)((s8 *)city_main_warp_challenge + 0xE2) = 0;
    *(s32 *)((s8 *)city_main_warp_challenge + 0xD0) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)city_common_model_archive + 0x42C)) + 8);
    *(s32 *)((s8 *)city_main_warp_challenge + 0xD4) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)city_common_model_archive + 0x430)) + 0x2C);
    if ((u32) ((TObjCityMainWarpChallenge *)city_main_warp_challenge)->m_b4 != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)city_main_warp_challenge + 0xB4));
        ((TObjCityMainWarpChallenge *)city_main_warp_challenge)->m_b4 = 0U;
    }
    for (var_ctr = 0; var_ctr < 4; var_ctr++) {
        ((Warp_80187B50 *)city_main_warp_challenge)->arr[var_ctr] = 0;
    }
    return city_main_warp_challenge;
}

TObjCityMainWarpChallenge::~TObjCityMainWarpChallenge() {
    unregister_object_by_id();
    close_windows();
}

void TObjCityMainWarpChallenge::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() != 1) {
        if (!(*(s16 *)((s8 *)arg0 + 0xE2) & 1) && ((s16) *(s16 *)((s8 *)arg0 + 0xDE) != (s16) *(s16 *)((s8 *)arg0 + 0xDC))) {
            if ((s16) *(s16 *)((s8 *)arg0 + 0xE0) != -1) {
                *(s16 *)((s8 *)arg0 + 0xE0) = -1;
                update_state();
            }
            *(s16 *)((s8 *)arg0 + 0xDE) = (s16) *(s16 *)((s8 *)arg0 + 0xDC);
            *(s16 *)((s8 *)arg0 + 0xE0) = 0;
        }
        ((TObjCityMainWarpChallenge *)arg0)->count_players_in_warp_radius();
        update_state();
        if ((void *) *(u8 **)((s8 *)arg0 + 0xD4) != NULL) {
            *(f32 *)((s8 *)arg0 + 0xC4) += 4.0f;
            if ((1.0f + *(f32 *)((s8 *)arg0 + 0xC4)) >= (f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xD4)) + 4)) {
                *(f32 *)((s8 *)arg0 + 0xC4) = 0.0f;
            }
        }
    }
}

void TObjCityMainWarpChallenge::render() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)&this->dest_floor == 0xE) {
        if (xz_distance_squared((void *)(camera_ctrl_instance + 0x178), (u8 *)&this->position) > 160000.0f) {
            return;
        }
        goto block_4;
    }
    if (((CityMainWarpChalVObj_80187824*)arg0)->m8(400.0f, 40.0f) != 0) {
block_4:
        TObjFish::set_global_param(city_common_texture_list);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)city_common_model_archive + 0x42C)) + 0xC8)));
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(*(s32 *)((s8 *)(*(void **)((s8 *)city_common_model_archive + 0x42C)) + 8), *(s32 *)((s8 *)(*(void **)((s8 *)city_common_model_archive + 0x430)) + 0x2C), *(f32 *)((s8 *)arg0 + 0xC4));
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TObjCityMainWarpChallenge::debug_print_area_num() {
    s32 v = *(s32 *)((u8 *)this + 0x88);
    if (v < 0 || v > 0xFF) {
        *(s32 *)((u8 *)this + 0x16C) = -1;
    } else {
        *(s32 *)((u8 *)this + 0x16C) = v;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if (get_current_floor_area() == AREA_PIONEER2_EP1) {
        debug_printf_at(0x130020, lbl_80444A44, *(s32 *)((u8 *)this + 0x84));
    }
    debug_printf_at(0x130021, lbl_80444A58, *(s32 *)((u8 *)this + 0x16C));
}

void TObjCityMainWarpChallenge::update_state() {

    switch (*(s16 *)((s8 *)this + 0xDE)) {
    case 0:
        update_challenge_state();
        return;
    case 1:
        update_warp_sequence__16TObjCityMainWarpFv();
        return;
    case 2:
        update_state__16TObjCityMainWarpFv();
        return;
    case 3:
        update_challenge_warp_window();
        return;
    case 4:
        update_floor_switch_state__16TObjCityMainWarpFv();
        return;
    }
}

void TObjCityMainWarp__sub_801875F8(TObjCityMainWarpChallenge *self) {
    s32 i;
    s32 j;
    u32 color;
    TLobby *player;
    f32 pos[2];

    switch (self->state) {
    case 0:
        if (self->yes_no_window == 0) {
            self->yes_no_window = TWindowMessageYesNo::create(self, (void *)local_client_id, (void *)0, (void *)0);
            if (self->yes_no_window != 0) {
                forward_slot_selection__16TAdChrSelASlotGCFPvPv(self->yes_no_window, (s32)TWindowSubStatusDisp::get_message_10(0x41), get_window_layout_position(0x36), 368.0f);
                free_member__17TWindowSubComCardFv(self->yes_no_window, 1);
                ((TWindowSubShortMail *)self->yes_no_window)->notify_warp_flag70();
                begin_player_keyboard_hold(local_client_id);
                request_active_window_close();
                ((TWindowCtrl *)local_client_id)->suppress_slot();
            }
        }
        break;
    case 1:
        if (self->yes_no_window == 0) {
            self->yes_no_window = TWindowMessageYesNo::create(self, (void *)local_client_id, (void *)0, (void *)0);
            if (self->yes_no_window != 0) {
                initialize_option_dialog(self->yes_no_window, (s32)TWindowSubStatusDisp::get_message_10(0x42), get_window_layout_position(0x36), 368.0f);
            }
        }
        break;
    }
    if (self->player_list_window == 0) {
        pos[0] = 229.0f;
        pos[1] = 104.0f;
        self->player_list_window = TWindowSubStatusDisp::refresh_with_default_list(get_window_layout_position(0x34), (s32)pos);
        if (self->player_list_window != 0) {
            ((TWindowSubTradeMain *)self->player_list_window)->set_visible();
            ((TWindowSubTradeMain *)self->player_list_window)->set_close_flag();
            for (i = 0; i < self->player_count; i++) {
                TWindowSubStatusDisp::dispatch_without_flags((s32)self->player_list_window, (s32)self->player_names[i], i);
            }
        }
        request_active_window_close();
    }
    if (self->player_list_window != 0) {
        for (j = 0; j < self->player_count; j++) {
            ((THunterGuildSeqOffline *)self->player_list_window)->advance_matching_entries(self->player_in_range[j] != 0, j);
            color = 0xF0F0F0FF;
            if (self->state == 1 && (player = (TLobby *)get_player_by_client_id(j)) != NULL &&
                player->check_player_flag1() != 0) {
                color = 0xFFFF00FF;
            }
            fn_80248994(self->player_list_window, color, j);
        }
    }
}

void TObjCityMainWarpChallenge::count_players_in_warp_radius() {
    u8 *arg0 = (u8 *)this;
    Warp_80187438 *self = (Warp_80187438 *)arg0;
    s32 i;
    s32 inside;
    Player_80187438 *pl;
    s32 room;
    s32 old;
    Player_80187438 *pl2;
    old = self->count;
    self->count = 0;
    self->n_inside = 0;
    self->player_on_dest_floor = 0;
    for (i = 0; i < 4; i++) {
        pl = (Player_80187438 *)get_player_by_client_id(i);
        if (pl != NULL) {
            room = ((TObjPlayer *)pl)->get_floor();
            if (room == self->dest_floor) {
                self->player_on_dest_floor = 1;
            }
            inside = 0;
            if (room == get_current_floor()) {
                if (xz_distance_squared(pl->pos, self->pos) <= self->radius * self->radius) {
                    inside = 1;
                    self->n_inside++;
                }
            }
            self->inside[self->count] = inside;
            strcpy(self->names[self->count], pl->name);
            self->count++;
        }
    }
    for (i = self->count; i < 4; i++) {
        self->names[i][0] = 0;
    }
    if (old != self->count && self->player_list_window != 0) {
        ((TWindowBase *)self->player_list_window)->close();
        self->player_list_window = 0;
    }
    pl2 = (Player_80187438 *)get_player_by_client_id(local_client_id);
    if (pl2 != NULL && ((TObjPlayer *)pl2)->get_floor() == get_current_floor()) {
        if (xz_distance_squared(pl2->pos, self->pos) <= (25.0f + self->radius) * (25.0f + self->radius)) {
            if (TObjWarpBossMulti::is_flag_clear(pl2) != 0) {
                ((TObjPlayer *)pl2)->check_technique_flag();
            }
        } else if (TObjWarpBossMulti::is_flag_clear(pl2) == 0) {
            ((TObjPlayer *)pl2)->has_item_flag_4096();
        }
    }
}

void TObjCityMainWarpChallenge::update_challenge_state() {
    u8 *arg0 = (u8 *)this;
    s32 r;
    if (*(s32 *)((s8 *)arg0 + 0x15C) == 1) {
        *(s16 *)((s8 *)arg0 + 0xDC) = 3;
        return;
    }
    switch (*(s16 *)((s8 *)arg0 + 0xE0)) {
    case 0:
        *(s32 *)((s8 *)arg0 + 0x170) = 0;
        *(s32 *)((s8 *)arg0 + 0x174) = 0;
        *(s16 *)((s8 *)arg0 + 0xE0) = 1;
        *(s32 *)((s8 *)arg0 + 0xD0) = *(s32 *)((s8 *)(*(void **)((s8 *)city_common_model_archive + 0x42C)) + 8);
        *(s32 *)((s8 *)arg0 + 0xD4) = *(s32 *)((s8 *)(*(void **)((s8 *)city_common_model_archive + 0x430)) + 0x2C);
        break;
    case 1:
        if (((u32 (*)(f32))find_local_player_in_range__16TObjCityMainWarpFf)(*(f32 *)((s8 *)arg0 + 0xAC)) != 0) {
            TObjCityMainWarp__sub_801875F8(this);
            ((TObjCityMainWarpChallenge *)arg0)->trigger_warp_effect(local_client_id);
            *(s16 *)((s8 *)arg0 + 0xE0) = 2;
            break;
        }
        if (*(u32 *)((s8 *)arg0 + 0xB0) != 0) {
            ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0xB0)))->close();
            *(u32 *)((s8 *)arg0 + 0xB0) = 0;
        }
        if (*(u32 *)((s8 *)arg0 + 0x164) != 0) {
            ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x164)))->close();
            *(u32 *)((s8 *)arg0 + 0x164) = 0;
        }
        break;
    case 2:
        TObjCityMainWarp__sub_801875F8(this);
        if (*(u32 *)((s8 *)arg0 + 0x168) != 0) {
            if (((TWindowSubComCard *)(*(u32 *)((s8 *)arg0 + 0x168)))->get_card_data() != 0) {
                *(s16 *)((s8 *)arg0 + 0xE0) = 3;
            } else if (((TWindowMessageYesNo *)(*(u32 *)((s8 *)arg0 + 0x168)))->is_child_visible() != 0) {
                r = ((TWindowSubComCard *)(*(u32 *)((s8 *)arg0 + 0x168)))->get_slot_or_neg1();
                if (r == 0) {
                    ((TObjCityMainWarpChallenge *)arg0)->trigger_warp_effect(local_client_id);
                    *(s32 *)((s8 *)arg0 + 0x170) = 1;
                    ((TObjCityMainWarpChallenge *)arg0)->send_6x6A_set_boss_warp_flags(1);
                    *(s16 *)((s8 *)arg0 + 0xE0) = 5;
                } else if (r == 1) {
                    *(s16 *)((s8 *)arg0 + 0xE0) = 3;
                }
            }
        }
        if (TWindowSubTradeMain::get_warp_state() != 0 && get_main_phase() == 0xF &&
            ((s32 (*)())is_local_client_floor_leader)() != 0 && ((TObjCityMainWarpChallenge *)arg0)->are_all_players_in_range() != 0) {
            ((TObjCityMainWarpChallenge *)arg0)->send_6x6A_set_boss_warp_flags(2);
            *(s16 *)((s8 *)arg0 + 0xE0) = 5;
        }
        if (*(s16 *)((s8 *)arg0 + 0xE0) != 2) {
            ((s32 (*)(void *))close_windows__25TObjCityMainWarpChallengeFv)(arg0);
        }
        break;
    case 3:
        TObjCityMainWarp::notify_player_warp(arg0, local_client_id);
        *(s16 *)((s8 *)arg0 + 0xE0) = 4;
        break;
    case 4:
        if (((u32 (*)(f32))find_local_player_in_range__16TObjCityMainWarpFf)(*(f32 *)((s8 *)arg0 + 0xAC)) == 0) {
            *(s16 *)((s8 *)arg0 + 0xE0) = 1;
            break;
        }
        if (TWindowSubTradeMain::get_warp_state() != 0 && get_main_phase() == 0xF &&
            ((s32 (*)())is_local_client_floor_leader)() != 0 && ((TObjCityMainWarpChallenge *)arg0)->are_all_players_in_range() != 0) {
            ((TObjCityMainWarpChallenge *)arg0)->send_6x6A_set_boss_warp_flags(2);
            *(s16 *)((s8 *)arg0 + 0xE0) = 5;
        }
        break;
    case 5:
        break;
    case -1:
        close_windows__25TObjCityMainWarpChallengeFv();
        break;
    }
}

}
