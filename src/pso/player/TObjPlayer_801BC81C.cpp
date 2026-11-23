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


extern "C" {

void TObjPlayer::init_battle() {
    saddr arg0 = (saddr)this;
    ((s32 (*)())TObjPlayer__sub_801BC8F0)();
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
s32 get_entity_id(void *);
s32 TObjPlayer__sub_801BF9E0(void *, int);
s32 set_field2_s16(void *, s32);
s32 get_class_index__10TObjPlayerFv(void *);
void TObjPlayer__sub_801BEF44(void *, void *);
void TObjPlayer__sub_801C1F78(void *, s32);
void clamp_and_set_unit_value__10TObjPlayerFiUci(void *, u8, s16);
void TObjPlayer__sub_801D955C(void *, s32);
void init_session_technique_caps__10TObjPlayerFPvPv(Player_801BC948 *self, Src_801BC948 *src);

void TObjPlayer__sub_801BC8F0(saddr arg0) {
    TObjPlayer__sub_801BF9E0((void *)(arg0 + 0x634), (int) (get_entity_id((void *)arg0)));
    ((TObjPlayer *)(arg0 + 0x384))->update_follow_particle(arg0);
    set_field2_s16((void *)(arg0 + 0x34C), (get_entity_id((void *)arg0)));
}
void init_session_technique_caps__10TObjPlayerFPvPv(Player_801BC948 *self, Src_801BC948 *src) {
    s32 i;
    TObjPlayer__sub_801C1F78(self->f4ac, get_entity_id(self));
    TObjPlayer__sub_801D955C(self->techs, get_class_index__10TObjPlayerFv(self));
    ((TObjPlayer *)(self->techs))->copy_all_technique_entries((void *)0x1D);
    for (i = 0; i < 0x13; i++) {
        clamp_and_set_unit_value__10TObjPlayerFiUci(self, src->levels[i] + src->bonus[i].pad[0], i);
    }
    for (i = 0; i < 5; i++) {
        TObjPlayer__sub_801BEF44(&self->recs[i], &src->recs[i]);
    }
}

void TObjPlayer__sub_801BCA0C(void) {  }
void TObjPlayer__sub_801BCA10(void) {  }

s32 get_record_byte_at(void *, s32);

void TObjPlayer__sub_801BCA14(u8 *player, void *arg1) {
    s32 i;
    TObjPlayer__sub_801C1F78(player + 0x4AC, ((s32 (*)())get_entity_id)());
    TObjPlayer__sub_801D955C(player + 0x428, get_class_index__10TObjPlayerFv(player));
    ((TObjPlayer *)(player + 0x428))->copy_all_technique_entries((void *)0x1D);
    i = 0;
    do {
        clamp_and_set_unit_value__10TObjPlayerFiUci(player, ((TObjPlayer *)arg1)->get_slot_value_checked(i) + get_record_byte_at(arg1, i), (s16)i);
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
void TObjPlayer__sub_801BCB28(void) {  }
void TObjPlayer::update_if_active() { if (is_script_controlled() != 0) { sync_current_area(); sync_current_floor(); } }

s32 TObjPlayer__sub_801B2014(void *);
s32 TObjPlayer__sub_801BEB68(void *, void *);
saddr TObjPlayer__sub_801BEB8C(void *);
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
    TObjPlayer__sub_801BEB68(this, (void *) (TObjPlayer__sub_801BEB8C(arg1)));
    this->init_player_data(arg1 + 0x118);
    this->hp = (s16) *(s16 *)((s8 *)arg1 + 0x22);
    TObjPlayer__sub_801B2014(this);
}

int TObjPlayer::can_cast_technique() { return TObjPlayer::check_technique_castable((saddr)this); }
void TObjPlayer__sub_801BCC50(void) {  }

u8 *get_class_attack_template(TObjPlayer *arg0);
u8 *get_class_defense_template(TObjPlayer *arg0);

extern const f32 TObjPlayer__data_805DC28C;

void TObjPlayer::init_player_data(void *src) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f31;
    f32 yscale;

    temp_f31 = this->m_d48;
    TLobby::copy_data((u8 *)&this->unk_D38, src);
    this->m_d48 = temp_f31;
    this->stat_block = (player_stats *)this->unk_D38;
    this->apply_input_mode();
    this->set_move_mode_from_class_flags();
    this->init_trait_flags();
    ((TLobby *)(arg0 + 0xD5C))->copy_from((void *)(get_class_attack_template(this)));
    ((TLobby *)(arg0 + 0xD8C))->copy_entry((void *)(get_class_defense_template(this)));
    yscale = this->get_tp_class_factor();
    this->recalc_combat_stats(this->stat_block, arg0 + 0xD5C, arg0 + 0xD8C, this->get_class_hp_factor(), yscale);
    *(f32 *)((s8 *)this->bodies + 4) = (f32) (TObjPlayer__data_805DC28C * this->stat_block->proportions);
}

int TObjPlayer__sub_801BEF60(void*, int);

int TObjPlayer::is_flag_set_550() { return TObjPlayer__sub_801BEF60((char*)this + 0x550, 0); }
void TObjPlayer__sub_801BCD50(void) {  }
void TObjPlayer__sub_801BCD54(void) {  }

}
