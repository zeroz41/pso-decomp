#include "pso/player/PlayerLevelTable.h"
#include "pso/player/TPlyCharData.h"
#include "types.h"
#include "pso/player/TObjPlayer_802C367C.h"
#include "pso/unk/text_802C3AC0.h"
#include "pso/player/TObjPlayer.h"

typedef struct S_802C3720 {
    u8 pad0[0x3A4];
    u32 f3A4;
} S_802C3720;

extern "C" {
int TObjPlayer__sub_802C456C(void*, s32, void*);
}
int init_character_action_config(void*);
extern "C" {
s32 TObjPlayer__sub_802C46E0(s32, s32, s32, s32, s32);

int init_new_character_data(void* p) { *(unsigned char*)(p) = 0; ((TObjPlayer *)p)->clear_item_slots(); init_character_action_config((char*)p + 0x3c0); init_class_starting_inventory(p); ((TObjPlayer *)p)->m_36c = 300; ((TObjPlayer *)p)->set_action_state((u8)(1)); return 1; }

void TObjPlayer::clear_30_slots() { { int i; for (i = 0; i < 30; i++) { TObjPlayer__sub_802C456C(this, i, (void*)0); } } }

void TObjPlayer::reset_action_palette() {
    s32 i;
    s8 *p;
    p = (s8 *)((TObjPlayer *)this)->get_action_data();
    for (i = 0; i < 0x14; i++) {
        *p = TObjPlayer::get_item_count_max();
        p++;
    }
    if (((S_802C3720 *)this)->f3A4 & 0x80) {
        ((TObjPlayer *)((S_802C3720 *)this))->set_action_palette_slot(0, 0);
    }
    ((TObjPlayer *)((S_802C3720 *)this))->clear_30_slots();
}

void init_technique_levels(s32 flags, s8 *counts) {
    s32 i;
    s8 *p = counts;
    for (i = 0; i < 0x14; i++, p++) {
        *p = TObjPlayer::get_item_count_max();
    }
    if (flags & 0x80) {
        *counts = 0;
    }
}

void TObjPlayer::setup_effect_slots(s32 arg0, saddr arg1) {
    TObjPlayer__sub_802C46E0(arg1, 0, 0, 1, 0);
    TObjPlayer__sub_802C46E0(arg1, 1, 0, 1, 0);
    TObjPlayer__sub_802C46E0(arg1, 0, 1, 2, 0);
    TObjPlayer__sub_802C46E0(arg1, 0, 2, 2, 1);
    if (arg0 & 0x60) {
        TObjPlayer__sub_802C46E0(arg1, 0, 3, 4, 0);
        return;
    }
    TObjPlayer__sub_802C46E0(arg1, 0, 3, 3, 0);
}

void init_character_stats_for_level(s32 cls, TPlyCharData *c, s32 level) {
    struct stats st;
    level = TObjPlayer::clamp_index_to_max(level);
    copy_stats__10TObjPlayerFPv(&st, get_class_base_stats(cls));
    if (level != 0) {
        apply_class_level_growth(cls, level, &st);
    }
    c->m_stats.stats.atp = st.atp;
    c->m_stats.stats.mst = st.mst;
    c->m_stats.stats.evp = st.evp;
    c->m_stats.stats.hp = st.hp;
    c->m_stats.stats.dfp = st.dfp;
    c->m_stats.stats.ata = st.ata;
    c->m_stats.stats.lck = st.lck;
    c->m_stats.mbr_0xe = 0x28;
    c->m_stats.mbr_0x14 = 10.0f;
    c->m_stats.level = level;
    c->m_stats.exp = TObjPlayer::get_current_state_field(cls, level);
    c->m_stats.meseta = 300;
    c->m_inventory.m_hp_materials_used = 0;
    c->m_inventory.m_tp_materials_used = 0;
    c->set_power_materials_used(0);
    c->set_mind_materials_used(0);
    c->set_evade_materials_used(0);
    c->set_def_materials_used(0);
    c->set_luck_materials_used(0);
}

void init_new_character_stats(TPlyCharData *character) {
    init_character_stats_for_level(character->m_disp_part2.char_class, character, 0);
}
}
