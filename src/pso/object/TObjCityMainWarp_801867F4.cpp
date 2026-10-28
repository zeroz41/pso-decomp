#include "types.h"
#include "pso/object/TObjCityMainWarpChallenge.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby_80207644.h"

struct RecoveredGlobal_80186AF4_lbl_804FF800 {
    s32 value;
    u8 remaining[0x1C];
};

struct Obj_80186B34 { u8 pad[0x38]; u8 pos[0xAC - 0x38]; f32 range; };
struct Bits_80186A3C { s32 v[36]; };

extern "C" {
s32 get_current_floor();
f32 xz_distance_squared(s32, s32);
void *get_player_by_client_id(s32 i);
extern s32 local_client_id;
s32 get_main_phase();
extern s32 lbl_805D55C0;
extern RecoveredGlobal_80186AF4_lbl_804FF800 lobby_name_string_buffer;
s32 *TObjCityMainWarp__sub_80186AF4(void);
s32 is_split_screen();
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_warp_flags_from_story__16TObjCityMainWarpFv();
s32 init_visible_mask__16TObjCityMainWarpFv();
}
extern const Bits_80186A3C city_main_warp_floor_bit_table;
s32 is_warp_excluded_area(s32);
s32 get_story_flag(s32);
extern s32 TObjCityMainWarp__enabled_destinations;
extern s32 TObjCityMainWarp__visible_destination_mask;
extern "C" {
void update_main_warp_visible_mask(s32 arg0);
void TObjCityMainWarp__sub_80186AB8(void);
void clear_enabled_main_warps(void);

void TObjCityMainWarp::update_unlock_flags() {
    s32 var_r31;
    s32 var_r30;
    s32 flag;

    TObjCityMainWarp__visible_destination_mask |= 1;
    if ((is_main_phase_15__9TObjEneDDFv() != 0) || (is_split_screen() != 0)) {
        flag = 0x4C;
        var_r31 = 0x4F;
        var_r30 = 0x52;
    } else {
        flag = 0x4D;
        var_r31 = 0x50;
        var_r30 = 0x53;
    }
    if (get_story_flag(flag) != 0) {
        TObjCityMainWarp__visible_destination_mask |= 4;
    }
    if (get_story_flag(var_r31) != 0) {
        TObjCityMainWarp__visible_destination_mask |= 0x10;
    }
    if (get_story_flag(var_r30) != 0) {
        TObjCityMainWarp__visible_destination_mask |= 0x200;
    }
}

void update_main_warp_visible_mask(s32 arg0) {
    s32 b;
    s32 c;
    s32 a;
    s32 i;
    TObjCityMainWarp__visible_destination_mask = TObjCityMainWarp__enabled_destinations;
    if (TLobby::get_instance() == 0) {
        TObjCityMainWarp__visible_destination_mask |= 1;
        if ((is_main_phase_15__9TObjEneDDFv() != 0) || (is_split_screen() != 0)) {
            a = 0x17;
            b = 0x20;
            c = 0x2A;
        } else {
            a = 0x18;
            b = 0x21;
            c = 0x30;
        }
        if (get_story_flag(a) != 0) {
            TObjCityMainWarp__visible_destination_mask |= 4;
        }
        if (get_story_flag(b) != 0) {
            TObjCityMainWarp__visible_destination_mask |= 0x20;
        }
        if (get_story_flag(c) != 0) {
            TObjCityMainWarp__visible_destination_mask |= 0x80;
        }
        for (i = 10; i < 17; i++) {
            TObjCityMainWarp__visible_destination_mask &= ~(1 << i);
        }
        return;
    }
    switch (arg0) {
    case 0:
        TObjCityMainWarp::update_unlock_flags();
        break;
    case 1:
        init_visible_mask__16TObjCityMainWarpFv();
        break;
    case 2:
        update_warp_flags_from_story__16TObjCityMainWarpFv();
        break;
    }
    for (i = 11; i < 15; i++) {
        TObjCityMainWarp__visible_destination_mask &= ~(1 << i);
    }
}

void TObjCityMainWarp::set_active_bit(s32 _w0) {
    s32 floor_warp_bit;

    floor_warp_bit = TObjCityMainWarp::get_floor_warp_bit(_w0);
    if (floor_warp_bit >= 0) {
        TObjCityMainWarp__enabled_destinations |= 1 << floor_warp_bit;
    }
}

s32 TObjCityMainWarp::get_floor_warp_bit(s32 floor) {
    s32 bit = -1;
    Bits_80186A3C bits = city_main_warp_floor_bit_table;
    if (is_warp_excluded_area(get_floor_area(floor)) == 0) {
        bit = bits.v[floor];
    }
    return bit;
}

void TObjCityMainWarp__sub_80186AB8(void) {  }
void TObjCityMainWarp::reset() { clear_enabled_main_warps(); update_main_warp_visible_mask(0); }
void TWindowSubComCardList::set_flag70_bit10() { this->m_70 |= 0x10; }

typedef char RecoveredGlobal_80186AF4_lbl_804FF800_size[sizeof(RecoveredGlobal_80186AF4_lbl_804FF800) == 0x20 ? 1 : -1];
s32 *TObjCityMainWarp__sub_80186AF4(void) {
    return &lobby_name_string_buffer.value;
}

s32 TObjCityMainWarp::get_phase_flag() {
    return ((get_main_phase() - 0xF) == 0) ? lbl_805D55C0 : 0;
}

s32 TObjCityMainWarpChallenge::are_all_players_in_range() {
    Obj_80186B34 *arg0 = (Obj_80186B34 *)this;
    s32 r;
    s32 i;
    u8 *p;
    r = 1;
    for (i = 0; i < 4; i++) {
        p = (u8 *)get_player_by_client_id(i);
        if (p != 0) {
            if (((TObjPlayer *)p)->get_field_3e4() != get_current_floor() || ((f32 (*)(void *, void *))xz_distance_squared)(p + 0x38, arg0->pos) > arg0->range * arg0->range) {
                r = 0;
            }
        }
    }
    return r;
}

#pragma push
#pragma fp_contract on
s32 TObjCityMainWarp::find_local_player_in_range(f32 farg0) {
    s32 arg0 = (s32)this;
    s32 player;
    s32 current_floor;
    s32 temp_r3b;
    player = (s32)get_player_by_client_id(local_client_id);
    if (player != 0) {
        current_floor = get_current_floor();
        temp_r3b = ((TObjPlayer *)player)->get_field_3e4();
        if ((temp_r3b == current_floor) && (xz_distance_squared(arg0 + 0x38, player + 0x38) < (farg0 * farg0))) {
            return player;
        }
    }
    return 0;
}
}
#pragma pop
