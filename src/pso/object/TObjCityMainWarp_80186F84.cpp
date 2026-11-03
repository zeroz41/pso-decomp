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

void initialize_option_dialog(void *dialog, s32 message, s32 position, f32 width);

struct Warp_80187438 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0xAC - 0x44];
    f32 radius;
    u8 padb0[0xBC - 0xB0];
    s32 fbc;
    u8 padc0[0xE4 - 0xC0];
    char names[4][0x18];
    s32 inside[4];
    s32 count;
    s32 n_inside;
    s32 f15c;
    u8 pad160[4];
    u32 window;
};

struct Player_80187438 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0x85C - 0x44];
    char name[0x18];
};

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
extern void *city_common_model_archive;
s32 get_main_phase();
extern s32 city_main_warp_destination_id;

void TObjCityMainWarp::update_state() {
    s32 temp_r0_2;
    s32 temp_r3;

    switch (*(s16 *)((s8 *)this + 0xE0)) {
    case 0:
        *(s32 *)((s8 *)this + 0x17C) = 0x96;
        *(s16 *)((s8 *)this + 0xE0) = 1;
        *(s16 *)((s8 *)this + 0xE2) = (s16) (*(s16 *)((s8 *)this + 0xE2) | 1);
        *(s32 *)((s8 *)this + 0xD0) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)city_common_model_archive + 0x42C)) + 8);
        *(s32 *)((s8 *)this + 0xD4) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)city_common_model_archive + 0x430)) + 0x2C);
        return;
    case 1:
        if (TObjCityMainWarp::get_phase_flag() == 0) {
            temp_r3 = find_local_player_in_range__16TObjCityMainWarpFf(this, *(f32 *)((s8 *)this + 0xAC));
            if (temp_r3 != 0) {
                TObjCityMainWarp::notify_player_warp(this, local_client_id);
                *(s32 *)((s8 *)this + 0xBC) = (s32) city_main_warp_destination_id;
                this->confirm_area_transfer(temp_r3);
                *(s16 *)((s8 *)this + 0xE0) = 2;
            }
        }
        temp_r0_2 = *(s32 *)((s8 *)this + 0x17C) - 1;
        *(s32 *)((s8 *)this + 0x17C) = temp_r0_2;
        if (temp_r0_2 <= 0) {
            *(s16 *)((s8 *)this + 0xE0) = 2;
        }
    case -1:
        break;
    case 2:
        *(s16 *)((s8 *)this + 0xE2) = (s16) (*(s16 *)((s8 *)this + 0xE2) & 0xFFFFFFFE);
        *(s16 *)((s8 *)this + 0xDC) = 3;
        break;
    }
}

void TObjCityMainWarp::update_warp_sequence() {
    u8 *arg0 = (u8 *)this;
    s32 r;
    switch (this->m_e0) {
    case 0:
        *(s32 *)((s8 *)arg0 + 0x160) = 0x12C;
        play_sound_effect(0x40003205, (u8 *)&this->position, 0, 0);
        this->m_e0 = 1;
        this->m_d0 = *(s32 *)((s8 *)(*(void **)((s8 *)city_common_model_archive + 0x42C)) + 8);
        *(s32 *)((s8 *)arg0 + 0xD4) = *(s32 *)((s8 *)(*(void **)((s8 *)city_common_model_archive + 0x430)) + 0x2C);
        break;
    case 1:
        if (((u32 (*)(f32))find_local_player_in_range__16TObjCityMainWarpFf)(*(f32 *)((s8 *)arg0 + 0xAC)) != 0) {
            TObjCityMainWarp__sub_801875F8((TObjCityMainWarpChallenge *)arg0);
            if (*(s32 *)((s8 *)arg0 + 0x170) == 0) {
                ((TObjCityMainWarpChallenge *)arg0)->trigger_warp_effect(local_client_id);
                *(s32 *)((s8 *)arg0 + 0x170) = 1;
            }
        }
        if (TWindowSubTradeMain::get_warp_state() != 0) {
            if (is_local_client_floor_leader((*(s32 *)((s8 *)arg0 + 0x160))--) != 0) {
                if (*(s32 *)((s8 *)arg0 + 0x160) <= 0) {
                    r = 1;
                } else {
                    r = ((TObjCityMainWarpChallenge *)arg0)->are_all_players_in_range();
                }
                if (r != 0) {
                    ((TObjCityMainWarpChallenge *)arg0)->send_6x6A_set_boss_warp_flags(2);
                    this->m_e0 = 2;
                }
            }
        }
        break;
    case 2:
        break;
    case -1:
        close_windows__25TObjCityMainWarpChallengeFv();
        break;
    }
}

}
