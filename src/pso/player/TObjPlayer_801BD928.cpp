#include "pso/system/task/TObject.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/PlayerState.h"
#include "types.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayerSet.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

extern "C" {

s32 TObjPlayer__sub_801BCA14(void *, void *);
s32 TObjPlayer__sub_801C1A00(void *);
s32 init_player_telepipe_record(void *);
u8 get_byte_157(void *);
u8 get_byte_13b(void *);
u8 get_byte_11f(void *);
u8 get_byte_103(void *);
u8 get_byte_e7(void *);

extern const char *lbl_805D3530;

TObjPlayer::TObjPlayer(TObject *parent, s32 slot, s32 role, TPlyCharData *record) : TObjChara(parent) {
    ((TObjPlayer *)(((u8 *)this) + 0x608))->set_vec4_const_wrapper();
    ((TObjPlayer *)(((u8 *)this) + 0x634))->wrap_update();
    battle_music.reset_and_clear();
    ((TObjPlayer *)(((u8 *)this) + 0x644))->construct_hurt_timer();
    stick_escape_detector.reset_fields();
    ((TObjPlayer *)(((u8 *)this) + 0x658))->reset_scale_vector();
    ((TObjPlayer *)(((u8 *)this) + 0x66C))->set_vec3_const_wrapper();
    npc_control.reset();
    ((TObjPlayer *)(((u8 *)this) + 0x6AC))->forward_release();
    movement_hold.init();
    ((TObjPlayer *)(((u8 *)this) + 0x744))->init_vec_record();
    ((TObjPlayer *)(((u8 *)this) + 0x754))->init_sub_objects();
    TObjPlayer::init_partial((saddr)((((u8 *)this) + 0x7C4)));
    ((TObjPlayer *)(((u8 *)this) + 0x7C8))->clear_base();
    ((TObjPlayer *)(((u8 *)this) + 0x7CC))->init();
    TObjPlayer__sub_801C1A00((void *) (((u8 *)this) + 0x828));
    init_player_telepipe_record((void *) (((u8 *)this) + 0x830));
    TObjPlayer__sub_801BFB4C(&m_84c);
    __ct__8FlagWordFv((((u8 *)this) + 0x858));
    TObjPlayer::reset_and_return((saddr)((((u8 *)this) + 0xD04)));
    ((TObjPlayer *)(((u8 *)this) + 0xDAC))->clear_header_struct();
    m_name = lbl_805D3530;
    this->init_action_provider();
    this->entity_id = slot;
    this->setup_control_role(role);
    update_body_parts(&record->m_disp_part2);
    sub_801BEE2C(record->m_inventory.m_hp_materials_used);
    sub_801BEE24(record->m_inventory.m_tp_materials_used);
    this->set_field_374(get_byte_e7(record));
    this->set_field_374_state(get_byte_103(record));
    this->set_inventory_state(get_byte_11f(record));
    this->set_equip_flags(get_byte_13b(record));
    this->set_luck_materials_used(get_byte_157(record));
    this->init_player_data(&record->m_stats);
    this->create_lockon_cursor();
    this->sub_801BD318();
    this->init_control_mode(role);
    TObjPlayer__sub_801BCA14(this, record);
    init_player_substructs(reinterpret_cast<u8 *>(&record->m_config));
    this->load_character_state(record);
    this->update_if_active();
    assign_owner_ids();
    this->setup_fresh_player_state((u8 *)record);
    this->sub_801BB8B0((u8 *)record);
    TObjPlayer::set_com_card_window((saddr)((this->get_entity_id())));
}

}

struct VBase_18_dac7f3
{
  char pad[0x18];
};

struct VObj_18_dac7f3 : VBase_18_dac7f3 {
    virtual s32 m0(s32);
};

struct E_801BDC98 { u8 b[0x42C]; };

extern "C" {
struct TObjPlayerCharDataArray { s32 value; u8 remaining[0x320C]; };
extern TObjPlayerCharDataArray TObjPlayer__char_data_array;
void create__10TObjPlayerFUll(u16, void *);
typedef struct VBase_18_dac7f3 VBase_18_dac7f3;
typedef struct VObj_18_dac7f3 VObj_18_dac7f3;
#pragma opt_pointer_analysis on
#define PSO_VCALL_VObj_18_dac7f3_m0(_self, _arg0) (((VObj_18_dac7f3 *)(_self))->m0((_arg0)))

extern const char *TObjPlayer__player_set_class_name;

TObjPlayerSet *find_player_arrival_set(TObjPlayer *player, s32 slot) {
    TObjPlayerSet *set;
    s32 side;

    side = player->get_entrance_id();
    if (side != -1) {
        player->reset_entrance_id();
    } else {
        switch (select_area_entrance(&floor_transition_state)) {
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
        if (set->check_value_equals(TObjPlayer__player_set_class_name) != 0 &&
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
  s32 i;
  u8 *player;
  s32 *var_r29;
  i = 0;
  var_r29 = &TObjPlayer__char_data_array.value;
  do
  {
    ((TObjPlayer *)var_r29)->init_select_txt();
    player = (u8 *) get_player_by_client_id(i);
    if (player != 0)
    {
      if (TObjPlayer::is_locally_controlled(player) != 0)
      {
        ((TObjPlayer *)var_r29)->copy_lobby_header((saddr) player);
      }
      if (player != 0)
      {
        PSO_VCALL_VObj_18_dac7f3_m0(player, 1);
      }
    }
    i += 1;
    var_r29 = (s32 *) (((u8 *) var_r29) + 0x42C);
  }
  while (i < 0xC);
}

}
