#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayerSet.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/misc/TLobby_80227A2C.h"
#include "pso/TMainTask.h"

struct VBase_18_dac7f3
{
  char pad[0x18];
};

struct VObj_18_dac7f3 : VBase_18_dac7f3 {
    virtual s32 m0(s32);
};

struct RecoveredGlobal_801BDCF8_TObjPlayer__data_8050EA70
{
  s32 value;
  u8 remaining[0x320C];
};

struct E_801BDC98 { u8 b[0x42C]; };

extern "C" {
s32 is_locally_controlled__10TObjPlayerFPv();
void *get_player_by_client_id(s32 i);
extern RecoveredGlobal_801BDCF8_TObjPlayer__data_8050EA70 TObjPlayer__char_data_array;
void create__10TObjPlayerFUll(u16, void *);
typedef struct RecoveredGlobal_801BDCF8_TObjPlayer__data_8050EA70 RecoveredGlobal_801BDCF8_TObjPlayer__data_8050EA70;
typedef struct VBase_18_dac7f3 VBase_18_dac7f3;
typedef struct VObj_18_dac7f3 VObj_18_dac7f3;
#pragma opt_pointer_analysis on
typedef char RecoveredGlobal_801BDCF8_TObjPlayer__data_8050EA70_size[((sizeof(RecoveredGlobal_801BDCF8_TObjPlayer__data_8050EA70)) == 0x3210) ? (1) : (-1)];
#define PSO_VCALL_VObj_18_dac7f3_m0(_self, _arg0) (((VObj_18_dac7f3 *)(_self))->m0((_arg0)))

extern s32 lbl_80515BA0[];
extern const char *TObjPlayer__player_set_class_name;
extern "C" s32 check_value_equals__13TUnk_804B6C24Fl(void *self, const char *name);

TObjPlayerSet *find_player_arrival_set(TObjPlayer *player, s32 slot) {
    TObjPlayerSet *set;
    s32 side;

    side = player->get_entrance_id();
    if (side != -1) {
        player->reset_entrance_id();
    } else {
        switch (select_area_entrance(lbl_80515BA0)) {
        case 0:
            side = 1;
            break;
        case 1:
        case 2:
            side = 0;
            break;
        case 4:
        default:
            side = 1;
            break;
        }
    }
    for (set = (TObjPlayerSet *)tl_06->m_down; set != NULL; set = (TObjPlayerSet *)set->m_next) {
        if (check_value_equals__13TUnk_804B6C24Fl(set, TObjPlayer__player_set_class_name) != 0 &&
            slot == (s32)set->scale.x && set->set_params[0] == side) {
            return set;
        }
    }
    return NULL;
}

void TObjPlayer::create_active_players() {
    s32 i;
    E_801BDC98 *p;
    i = 0;
    p = ((E_801BDC98 *)&TObjPlayer__char_data_array);
    do {
        if (((TObjPlayer *)p)->check_flag_at_428() != 0) {
            create__10TObjPlayerFUll(i, p);
        }
        i++;
        p++;
    } while (i < 12);
}

void TObjPlayer::refresh_player_lobby_headers() {
  s32 var_r31;
  u8 *player;
  s32 *var_r29;
  var_r31 = 0;
  var_r29 = &TObjPlayer__char_data_array.value;
  do
  {
    ((TObjPlayer *)var_r29)->init_select_txt();
    player = (u8 *) get_player_by_client_id(var_r31);
    if (player != 0)
    {
      if (is_locally_controlled__10TObjPlayerFPv() != 0)
      {
        ((TObjPlayer *)var_r29)->copy_lobby_header((int) player);
      }
      if (player != 0)
      {
        PSO_VCALL_VObj_18_dac7f3_m0(player, 1);
      }
    }
    var_r31 += 1;
    var_r29 = (s32 *) (((u8 *) var_r29) + 0x42C);
  }
  while (var_r31 < 0xC);
}

}
