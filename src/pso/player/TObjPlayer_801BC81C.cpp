#include "pso/player/PlayerState.h"
#include "pso/player/PlayerRequirementStats.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_801BC81C.h"
#include "pso/player/TObjPlayer_801BE778.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801BCC30.h"
#include "pso/object/base/TObjChara.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer_801BCD28.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TPlyDispData.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/TWindowActionPalette_801C1890.h"
#include "pso/player/TObjPlayer_801C1FF8.h"


extern "C" {

void TObjPlayer::init_battle(void *data) {
    saddr arg0 = (saddr)this;
    assign_owner_ids();
    ::set_flag_400000(this);
    ((TObjPlayer *)(arg0 + 0x634))->enter_battle_state();
}

void update_photon_chair__10TObjPlayerFv(void *player);
}

void TObjPlayer::reset_area_entry_state() {
    s32 x;
    ((TObjPlayer *)((char *)this + 900))->update_child(this);
    ((TObjPlayer *)((char *)this + 1588))->enter_battle_state();
    x = TObjPlayer::is_locally_controlled(this);
    if (x != 0) {
        TObjPlayer::for_each_player_slot(update_photon_chair__10TObjPlayerFv);
    }
}

void TObjPlayer::destroy_owned_object() { if (*(unsigned int *)&this->unk_548 != 0) { ((TObject *)(*(void* *)&this->unk_548))->queue_destruction(); *(int *)&this->unk_548 = 0; } }


typedef struct E12_801BC948 { u8 b[12]; } E12_801BC948;

typedef struct E1C_801BC948 { u8 pad[0x1C]; } E1C_801BC948;

typedef struct Src_801BC948 {
    u8 pad0[0x28];
    E12_801BC948 recs[5];
    u8 pad64[0xB4 - 0x64];
    u8 levels[0x13];
    u8 padc7[0x142 - 0xC7];
    E1C_801BC948 bonus[0x13];
} Src_801BC948;

typedef struct Player_801BC948 {
    u8 pad0[0x254];
    E12_801BC948 recs[5];
    u8 pad290[0x428 - 0x290];
    u8 techs[0x4AC - 0x428];
    u8 f4ac[4];
} Player_801BC948;

extern "C" {
s32 get_class_index__10TObjPlayerFv(void *);
void TObjPlayer__sub_801BEF44(void *, void *);
void set_technique_level_clamped__10TObjPlayerFP10TObjPlayerUci(void *, u8, s16);
void TObjPlayer__sub_801D955C(void *, s32);
void init_session_technique_caps__10TObjPlayerFPvPv(Player_801BC948 *self, Src_801BC948 *src);

void TObjPlayer::assign_owner_ids() {
    TObjPlayer__sub_801BF9E0((void *)(((saddr)this) + 0x634), this->get_entity_id());
    ((TObjPlayer *)(((saddr)this) + 0x384))->update_follow_particle(((saddr)this));
    this->chair_seat.set_owner_id(this->get_entity_id());
}
void init_session_technique_caps__10TObjPlayerFPvPv(Player_801BC948 *self, Src_801BC948 *src) {
    s32 i;
    TObjPlayer__sub_801C1F78(self->f4ac, ((TObjBase *)(self))->get_entity_id());
    TObjPlayer__sub_801D955C(self->techs, get_class_index__10TObjPlayerFv(self));
    ((TObjPlayer *)(self->techs))->copy_all_technique_entries((void *)0x1D);
    for (i = 0; i < 0x13; i++) {
        set_technique_level_clamped__10TObjPlayerFP10TObjPlayerUci(self, src->levels[i] + src->bonus[i].pad[0], i);
    }
    for (i = 0; i < 5; i++) {
        TObjPlayer__sub_801BEF44(&self->recs[i], &src->recs[i]);
    }
}

void TObjPlayer::reset_technique_caps() {  }
void TObjPlayer::release_technique_caps() {  }

s32 get_record_byte_at(void *, s32);

void TObjPlayer__sub_801BCA14(u8 *player, void *arg1) {
    s32 i;
    TObjPlayer__sub_801C1F78(player + 0x4AC, ((TObjBase *)player)->get_entity_id());
    TObjPlayer__sub_801D955C(player + 0x428, get_class_index__10TObjPlayerFv(player));
    ((TObjPlayer *)(player + 0x428))->copy_all_technique_entries((void *)0x1D);
    i = 0;
    do {
        set_technique_level_clamped__10TObjPlayerFP10TObjPlayerUci(player, ((TObjPlayer *)arg1)->get_slot_value_checked(i) + get_record_byte_at(arg1, i), (s16)i);
        i += 1;
    } while (i < 0x13);
}

void TObjPlayer__sub_801BCAB0(void) {  }
void TObjPlayer::update_state() {
    if (this->obj_isState2_324() != 0) {
        this->clear_flag_400000();
    } else {
        this->sync_current_area();
        this->sync_current_floor();
    }
    if ((TObjPlayer::is_final_phase() != 0) && (this->sub_801A1DDC() != 0)) {
        this->apply_state_transform();
    }
}
void TObjPlayer::release_area_sync() {  }
void TObjPlayer::update_if_active() { if (is_script_controlled() != 0) { sync_current_area(); sync_current_floor(); } }

u8 TObjPlayer__sub_801BEB8C(void *);
u8 TObjPlayer__sub_801BEBB8(void *);
u8 TObjPlayer__sub_801BEBE4(void *);
u8 TObjPlayer__sub_801BEC10(void *);
u8 TObjPlayer__sub_801BEC3C(void *);

void TObjPlayer::load_char_data(u8 *arg1) {
    sub_801BEE2C((int) (*(s16 *)((s8 *)arg1 + 0x24)));
    sub_801BEE24((int) (*(s16 *)((s8 *)arg1 + 0x26)));
    this->set_field_374(TObjPlayer__sub_801BEC3C(arg1));
    this->set_field_374_state(TObjPlayer__sub_801BEC10(arg1));
    this->set_inventory_state(TObjPlayer__sub_801BEBE4(arg1));
    this->set_equip_flags(TObjPlayer__sub_801BEBB8(arg1));
    this->set_luck_materials_used(TObjPlayer__sub_801BEB8C(arg1));
    this->init_player_data(arg1 + 0x118);
    this->hp = (s16) *(s16 *)((s8 *)arg1 + 0x22);
    resend_status_effects();
}

int TObjPlayer::can_cast_technique() { return TObjPlayer::check_technique_castable((saddr)this); }
void TObjPlayer::release_char_data() {  }


extern const f32 TObjPlayer__data_805DC28C;

void TObjPlayer::init_player_data(void *src) {
    u8 *arg0 = (u8 *)this;
    f32 proportions;
    f32 yscale;

    proportions = this->base_stats.proportions;
    TLobby::copy_data(&this->base_stats, src);
    this->base_stats.proportions = proportions;
    this->stat_block = &this->base_stats;
    this->apply_input_mode();
    this->set_move_mode_from_class_flags();
    this->init_trait_flags();
    ((TLobby *)(arg0 + 0xD5C))->copy_from((void *)(get_class_attack_template(this)));
    ((TLobby *)(arg0 + 0xD8C))->copy_entry((void *)(get_class_defense_template(this)));
    yscale = this->get_tp_class_factor();
    this->recalc_combat_stats(this->stat_block, &attack_stats, &resistance_stats, this->get_class_hp_factor(), yscale);
    *(f32 *)((s8 *)this->bodies + 4) = (f32) (TObjPlayer__data_805DC28C * stat_block->proportions);
}

int TObjPlayer__sub_801BEF60(void*, int);

int TObjPlayer::is_flag_set_550(void *data) { return TObjPlayer__sub_801BEF60((char*)this + 0x550, 0); }
void TObjPlayer::reset_pad_binding() {  }
void TObjPlayer::release_pad_binding() {  }

}
