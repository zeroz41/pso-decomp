#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TFontSmallLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayerSet.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/misc/TLobby_80227A2C.h"
#include "pso/TMainTask.h"

extern "C" {

s32 TFontSmallLobby__sub_801C0164(void *);
s32 __ct__9TObjCharaFP7TObject();
s32 init_player_substructs__10TObjPlayerFv(void *, void *);
s32 TObjPlayer__sub_801BC8F0(void *);
s32 TObjPlayer__sub_801BCA14(void *, void *);
s32 init_player_data__10TObjPlayerFv(void *, void *);
s32 TObjPlayer__sub_801BEB68(void *, void *);
s32 get_quest_status__10TObjPlayerFv(void *, void *);
s32 TObjPlayer__sub_801BEC78(void *);
s32 sub_801BEE24__10TObjPlayerFs(void *, int);
s32 sub_801BEE2C__10TObjPlayerFs(void *, int);
s32 TObjPlayer__sub_801BF660(void *);
s32 TObjPlayer__sub_801BFB4C(void *);
s32 init_state__10TObjPlayerFi(void *);
s32 TObjPlayer__sub_801C1A00(void *);
s32 init_player_telepipe_record(void *);
s32 TObjPlayer__sub_801C221C(void *);
s32 TObjPlayer__sub_801C2224(void *);
s32 TObjPlayer__sub_801C222C(void *);
s32 TObjPlayer__sub_801C2234(void *);
s32 TObjPlayer__sub_801C223C(void *);
s32 TObjPlayer__sub_80309E9C(void *);
s32 TObjPlayer__sub_803374C4(void *);
s32 TObjPlayer__sub_80351974(void *);
s32 __ct__14TPlyDispConfigFv(void *);
s32 get_field_0x374__10TObjPlayerFv(void *, void *);
u16 get_entity_id(void *);
s32 query_field374__10TObjPlayerFv(void *, void *);
s32 query_flags_374__10TObjPlayerFv(void *, void *);
s32 update_body_parts__10TObjPlayerFv(void *, void *);

extern s32 __vt__10TObjPlayer[];
extern s32 lbl_805D3530;

u8 *TObjPlayer::construct_player_instance(s32 arg1, s16 arg2, s32 role, u8 *arg4) {
    __ct__9TObjCharaFP7TObject();
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = __vt__10TObjPlayer;
    ((TObjPlayer *)(((u8 *)this) + 0x340))->init_subobject();
    ((TObjPlayer *)(((u8 *)this) + 0x34C))->setup_ctrl();
    init_state__10TObjPlayerFi((void *) (((u8 *)this) + 0x360));
    TObjPlayer__sub_803374C4((void *) (((u8 *)this) + 0x374));
    TObjPlayer__sub_80309E9C((void *) (((u8 *)this) + 0x384));
    __ct__8FlagWordFv((((u8 *)this) + 0x41C));
    TFontSmallLobby__sub_801C0164((void *) (((u8 *)this) + 0x428));
    ((TFontSmallLobby *)(((u8 *)this) + 0x4AC))->construct_pb_controller();
    __ct__14TPlyDispConfigFv((void *) (((u8 *)this) + 0x500));
    TObjPlayer__sub_80351974((void *) (((u8 *)this) + 0x550));
    ((TObjPlayer *)(((u8 *)this) + 0x5B0))->init_subobjects();
    ((TObjPlayer *)(((u8 *)this) + 0x5E0))->init_sub();
    ((TObjPlayer *)(((u8 *)this) + 0x5F0))->init_wrapper();
    ((TObjPlayer *)(((u8 *)this) + 0x5FC))->init_members();
    ((TObjPlayer *)(((u8 *)this) + 0x608))->set_vec4_const_wrapper();
    ((TObjPlayer *)(((u8 *)this) + 0x634))->wrap_update();
    ((TObjPlayer *)(((u8 *)this) + 0x63C))->reset_and_clear();
    ((TObjPlayer *)(((u8 *)this) + 0x644))->construct_hurt_timer();
    ((TObjPlayer *)(((u8 *)this) + 0x64C))->reset_fields();
    ((TObjPlayer *)(((u8 *)this) + 0x658))->reset_scale_vector();
    ((TObjPlayer *)(((u8 *)this) + 0x66C))->set_vec3_const_wrapper();
    TObjPlayer__sub_801BEC78((void *) (((u8 *)this) + 0x678));
    ((TObjPlayer *)(((u8 *)this) + 0x6AC))->forward_release();
    TObjPlayer__sub_801BF660((void *) (((u8 *)this) + 0x730));
    ((TObjPlayer *)(((u8 *)this) + 0x744))->init_vec_record();
    ((TObjPlayer *)(((u8 *)this) + 0x754))->init_sub_objects();
    TObjPlayer::init_partial((s32)((void *) (((u8 *)this) + 0x7C4)));
    ((TObjPlayer *)(((u8 *)this) + 0x7C8))->clear_base();
    ((TObjPlayer *)(((u8 *)this) + 0x7CC))->init();
    TObjPlayer__sub_801C1A00((void *) (((u8 *)this) + 0x828));
    init_player_telepipe_record((void *) (((u8 *)this) + 0x830));
    TObjPlayer__sub_801BFB4C((void *) (((u8 *)this) + 0x84C));
    __ct__8FlagWordFv((((u8 *)this) + 0x858));
    TObjPlayer::reset_and_return((s32)((void *) (((u8 *)this) + 0xD04)));
    ((TObjPlayer *)(((u8 *)this) + 0xDAC))->clear_header_struct();
    *(s32 *)((s8 *)((u8 *)this) + 0) = (s32) lbl_805D3530;
    this->init_action_provider();
    this->entity_id = arg2;
    this->setup_control_role(role);
    update_body_parts__10TObjPlayerFv(this, arg4 + 0x370);
    sub_801BEE2C__10TObjPlayerFs(this, (int) (*(u8 *)((s8 *)arg4 + 1)));
    sub_801BEE24__10TObjPlayerFs(this, (int) (*(u8 *)((s8 *)arg4 + 2)));
    get_field_0x374__10TObjPlayerFv(this, (void *) (TObjPlayer__sub_801C223C(arg4)));
    get_quest_status__10TObjPlayerFv(this, (void *) (TObjPlayer__sub_801C2234(arg4)));
    query_flags_374__10TObjPlayerFv(this, (void *) (TObjPlayer__sub_801C222C(arg4)));
    query_field374__10TObjPlayerFv(this, (void *) (TObjPlayer__sub_801C2224(arg4)));
    TObjPlayer__sub_801BEB68(this, (void *) (TObjPlayer__sub_801C221C(arg4)));
    init_player_data__10TObjPlayerFv(this, arg4 + 0x34C);
    this->create_lockon_cursor();
    this->sub_801BD318();
    this->init_control_mode(role);
    TObjPlayer__sub_801BCA14(this, arg4);
    init_player_substructs__10TObjPlayerFv(this, arg4 + 0x3C0);
    this->load_character_state((u8 *)arg4);
    this->update_if_active();
    TObjPlayer__sub_801BC8F0(this);
    this->setup_fresh_player_state((u8 *)arg4);
    this->sub_801BB8B0((u8 *)arg4);
    TObjPlayer::set_com_card_window((s32)((void *) (get_entity_id(this))));
    return ((u8 *)this);
}

}

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
