#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_80104860.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

extern "C" {
s32 item_identity_matches(u8 *arg0, u8 *arg1);
s32 get_weapon_special_type_amount(u8, s16 *, s16 *);
}
s32 compare_item_data_masked(void *arg0, void *arg1, s32 arg2);
extern "C" {

extern s32 local_client_id;
}

s32 is_local_player_off_current_floor() {
    TObjPlayer *player;
    s32 floor;

    if (is_split_screen() != 0) {
        return 0;
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        floor = get_current_floor();
        return floor - player->get_field_3e4() ? 1 : 0;
    }
    return 0;
}

extern "C" {

u8 TObjPlayer::find_adjacent_matching_slot(u8 arg0) {
    s16 spC;
    s16 spA;
    s16 sp8;
    int temp_r31;

    temp_r31 = (u8) arg0 - 1;
    get_weapon_special_type_amount((u8) temp_r31, &spC, &sp8);
    get_weapon_special_type_amount(arg0, &spA, &sp8);
    if ((spC != -1) && (spA != -1)) {
        if (spC == spA) {
            return (u8) temp_r31;
        }
        return arg0;
    }
    return arg0;
}

u8 TObjPlayer::get_next_matching_special_index(u8 arg0) {
    s16 spC;
    s16 spA;
    s16 sp8;
    int next;
    get_weapon_special_type_amount(arg0, &spC, &sp8);
    next = (u8)arg0 + 1;
    get_weapon_special_type_amount((u8)next, &spA, &sp8);
    if ((spC != -1) && (spA != -1)) {
        if (spC == spA) {
            return (u8)next;
        }
        return arg0;
    }
    return arg0;
}

s32 item_identity_matches(u8 *arg0, u8 *arg1) {
  s32 var_r3;
  u8 var_r5;
  u8 var_r6;
  if ((((((u32) arg0) != 0) && (((u32) arg1) != 0)) && ((var_r5 = *((u8 *) (((s8 *) arg0) + 0)), (var_r5 == ((u8) (*((u8 *) (((s8 *) arg1) + 0))))) != 0))) && ((var_r6 = *((u8 *) (((s8 *) arg0) + 1)), (var_r6 == ((u8) (*((u8 *) (((s8 *) arg1) + 1))))) != 0)))
  {
    switch ((s32) var_r5)
    {
      case 0:
        var_r5 = 0x41;
        return compare_item_data_masked(arg0, arg1, 0x41);
      case 1:
        var_r5 = 1;
        return compare_item_data_masked(arg0, arg1, 1);
      case 2:
        var_r5 = 0;
        return compare_item_data_masked(arg0, arg1, 0);
      case 3:
        if (var_r6 == 2)
      {
        var_r5 = 0x41;
        return compare_item_data_masked(arg0, arg1, 0x41);
      }
        var_r5 = 1;
        return compare_item_data_masked(arg0, arg1, 1);
      case 4:
        var_r5 = 0;
        return compare_item_data_masked(arg0, arg1, 0);
    }
  }
  else
  {
    var_r3 = 0;
  }
  return 0;
}
}
s32 compare_item_data_masked(void *arg0, void *arg1, s32 arg2) {
    u8 *a = (u8 *)arg0;
    u8 *b = (u8 *)arg1;
    s32 r;
    s32 m;
    s32 t;
    s32 m2;
    s32 t2;
    r = 0;
    if (a[0] == b[0] && a[1] == b[1]) {
        r = 1;
        if (arg2 & 7) {
            t = 0;
            if (arg2 & 1) {
                t = (u8)(a[2] == b[2]);
            }
            m = arg2 & 2;
            if (m != 0 && !(arg2 & 4)) {
                t |= a[2] < b[2];
            }
            if (m == 0 && (arg2 & 4)) {
                t |= a[2] > b[2];
            }
            if (m != 0 && (arg2 & 4)) {
                t |= (u8)(a[2] != b[2]);
            }
        } else {
            t = 1;
        }
        r &= t;
        if (arg2 & 0x38) {
            t2 = 0;
            if (arg2 & 8) {
                t2 = a[3] == b[3];
            }
            m2 = arg2 & 0x10;
            if (m2 != 0 && !(arg2 & 0x20)) {
                t2 |= a[3] < b[3];
            }
            if (m2 == 0 && (arg2 & 0x20)) {
                t2 |= a[3] > b[3];
            }
            if (m2 != 0 && (arg2 & 0x20)) {
                t2 |= (u8)(a[3] != b[3]);
            }
        } else {
            t2 = 1;
        }
        r &= t2;
        if (arg2 & 0x40) {
            t = a[4] == b[4];
        } else {
            t = 1;
        }
        r &= t;
    }
    return r;
}
