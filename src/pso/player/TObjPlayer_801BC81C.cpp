#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_801BC81C.h"
#include "pso/player/TObjPlayer_801BE778.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 is_locally_controlled__10TObjPlayerFPv(void *);
void for_each_player_slot__10TObjPlayerFv(void *);
int is_script_controlled__10TObjPlayerFv(void*);
s32 sub_801A1DDC__10TObjPlayerFv(s32);
s32 is_final_phase__10TObjPlayerFv();
s32 obj_isState2_324__13TUnk_804806E8Fv();

extern "C" {

void TObjPlayer::init_battle() {
    s32 arg0 = (s32)this;
    ((s32 (*)())TObjPlayer__sub_801BC8F0)();
    set_flag_400000__10TObjPlayerFi((arg0));
    ((TObjPlayer *)(arg0 + 0x634))->enter_battle_state();
}

}

extern "C" {
extern s32 update_photon_chair__10TObjPlayerFv[];
}

void TObjPlayer::reset_area_entry_state() {
    s32 x;
    ((TObjPlayer *)((char *)this + 900))->update_child(this);
    ((TObjPlayer *)((char *)this + 1588))->enter_battle_state();
    x = is_locally_controlled__10TObjPlayerFPv(this);
    if (x != 0) {
        for_each_player_slot__10TObjPlayerFv(update_photon_chair__10TObjPlayerFv);
    }
}

void TObjPlayer::destroy_owned_object() { if (*(unsigned int *)&this->unk_548 != 0) { queue_destruction__7TObjectFv(*(void* *)&this->unk_548); *(int *)&this->unk_548 = 0; } }

}

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
s32 TObjPlayer__sub_801C2244(void *, void *);
s32 get_class_index__10TObjPlayerFv(void *);
void TObjPlayer__sub_801BEF44(void *, void *);
void TObjPlayer__sub_801C1F78(void *, s32);
void clamp_and_set_unit_value__10TObjPlayerFiUci(void *, u8, s16);
void TObjPlayer__sub_801D955C(void *, s32);
void init_session_technique_caps__10TObjPlayerFPvPv(Player_801BC948 *self, Src_801BC948 *src);

void TObjPlayer__sub_801BC8F0(s32 arg0) {
    TObjPlayer__sub_801BF9E0((void *)(arg0 + 0x634), (int) (get_entity_id((void *)arg0)));
    ((TObjPlayer *)(arg0 + 0x384))->update_follow_particle(arg0);
    TObjPlayer__sub_801C2244((void *)(arg0 + 0x34C), (void *) (get_entity_id((void *)arg0)));
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

s32 TObjPlayer__sub_801C21C4(void *, s32);
s32 get_slot_value_checked__10TObjPlayerFl(void *, s32);

void TObjPlayer__sub_801BCA14(u8 *player, void *arg1) {
    s32 i;
    TObjPlayer__sub_801C1F78(player + 0x4AC, ((s32 (*)())get_entity_id)());
    TObjPlayer__sub_801D955C(player + 0x428, get_class_index__10TObjPlayerFv(player));
    ((TObjPlayer *)(player + 0x428))->copy_all_technique_entries((void *)0x1D);
    i = 0;
    do {
        clamp_and_set_unit_value__10TObjPlayerFiUci(player, get_slot_value_checked__10TObjPlayerFl(arg1, i) + TObjPlayer__sub_801C21C4(arg1, i), (s16)i);
        i += 1;
    } while (i < 0x13);
}

void TObjPlayer__sub_801BCAB0(void) {  }
void TObjPlayer::update_state() {
    s32 arg0 = (s32)this;
    if (obj_isState2_324__13TUnk_804806E8Fv() != 0) {
        ((TObjPlayer *)arg0)->set_flag_400000();
    } else {
        ((TObjPlayer *)arg0)->sync_current_area();
        ((TObjPlayer *)arg0)->sync_current_floor();
    }
    if ((is_final_phase__10TObjPlayerFv() != 0) && (sub_801A1DDC__10TObjPlayerFv(arg0) != 0)) {
        ((TObjPlayer *)arg0)->apply_state_transform();
    }
}
void TObjPlayer__sub_801BCB28(void) {  }
void TObjPlayer::update_if_active() { if (is_script_controlled__10TObjPlayerFv(this) != 0) { sync_current_area(); sync_current_floor(); } }

}
