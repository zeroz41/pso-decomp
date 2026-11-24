#include "pso/player/TPlyCharData.h"
#include "types.h"
#include "pso/player/TObjPlayer_802C422C.h"
#include "pso/ui/frontend/TAdSelectGameModeGC_802C4748.h"
#include "pso/system/date.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/network/TPlyOnCreated.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"
#include "pso/player/TPlyItem.h"
#include "pso/player/PlayerSlots.h"
#include "pso/unk/TLobby_802A0F3C.h"

extern "C" {

TObjPlayer *get_local_player();

extern s32 local_client_id;

s32 sync_state__10TObjPlayerFi(saddr arg0) {
    uaddr player;
    player = (uaddr)get_local_player();
    if (player == 0U) {
        TPlyOnCreated::create((u16)local_client_id, fn_802C4748);
        return 0;
    }
    ((TObjPlayer *)player)->export_state_to_record((TPlyCharData *)arg0);
    return 1;
}


void TObjPlayer::sync_char_select_state() { TAdSinglePlyChrSelectGC::get_char_index((uaddr)(65535)); ((int (*)(void))sync_state__10TObjPlayerFi)(); }


s32 TObjPlayer::try_assign_battle_ctrl(u16 client) {
    s32 temp = (saddr)get_player_by_client_id((client));
    if (temp == 0) {
        return 0;
    }
    ((s32 (*)(void *, s32))export_player_record__10TObjPlayerFPvPv)((void *)this, temp);
    return 1;
}

s32 update_battle__10TObjPlayerFi(saddr arg0) {
    s32 r;
    r = (saddr)get_local_player();
    if (r == 0) {
        return 0;
    }
    ((s32 (*)(void *, s32))export_player_record__10TObjPlayerFPvPv)((void *)arg0, (s32)r);
    return 1;
}

}

struct Rec_802C456C { u8 pad[6]; u8 f6; u8 pad2[0x1c - 7]; };

struct Obj_802C456C { Rec_802C456C recs[1]; };

struct Obj_802C4648 { u8 pad[0x77]; u8 f77; u8 pad2[0x93 - 0x78]; u8 f93; u8 pad3[0xaf - 0x94]; u8 faf; u8 pad4[0xcb - 0xb0]; u8 fcb; };

struct E_802C4668 { u8 pad[7]; u8 v; u8 pad2[0x14]; };

struct O_802C4668 { E_802C4668 e[4]; };

struct S_802C457C { u8 pad0[0x3A1]; u8 f3A1; u8 pad3A2[0x408 - 0x3A2]; u8 buf[1]; };

extern "C" {
void TObjPlayer__sub_802C456C(Obj_802C456C *self, s32 i, u8 v);
void TObjPlayer__sub_802C4648(Obj_802C4648 *self, u32 v);
void TObjPlayer__sub_802C4668(O_802C4668 *self, u32 c);
s32 copy_player_visual_record(void *, void *);
s32 TObjPlayer__sub_8013A748(void *, void *);
void is_slot_within_limit__10TObjPlayerFllUc(u8 id, s16 i, u8 v);
s32 clamp_stats__10TObjPlayerFiPv(void *, void *, void *);
u8 TObjPlayer__sub_801C0124(void *, s16);
int init_action_config__10TObjPlayerFv(void*);
int set_palette_entry__20TWindowActionPaletteFlllll(void*);

void TObjPlayer::init_battle_selection() { TAdSinglePlyChrSelectGC::get_char_index((uaddr)(65535)); ((int (*)(void))update_battle__10TObjPlayerFi)(); }

void export_player_record__10TObjPlayerFPvPv(TPlyCharData *record, u8 *arg1) {
    u8 *overflow;
    s32 i;
    ((TObjPlayer *)arg1)->set_flag_80000();
    copy_player_visual_record(&record->m_disp_part2, arg1 + 0x85C);
    record->m_inventory.m_num_items = query_state_if_present__10TObjPlayerFPv(reinterpret_cast<TObjPlayer *>(arg1), record->m_inventory.get_items());
    ((TObjPlayer *)arg1)->inventory_objects->set_flag_and_update((TObjPlayer *)arg1);
    clamp_stats__10TObjPlayerFiPv(arg1, &record->m_stats, (void *) (TObjPlayer::get_class_stat_entry((u8 *)arg1)));
    record->m_inventory.m_hp_materials_used = ((TObjPlayer *)arg1)->get_hp_material_points();
    record->m_inventory.m_tp_materials_used = ((TObjPlayer *)arg1)->get_tp_materials_clamped();
    record->set_power_materials_used(((TObjPlayer *)arg1)->get_power_materials_used());
    record->set_mind_materials_used(((TObjPlayer *)arg1)->get_mind_materials_used());
    record->set_evade_materials_used(((TObjPlayer *)arg1)->get_evade_materials_used());
    record->set_def_materials_used(((TObjPlayer *)arg1)->get_def_materials_used());
    record->set_luck_materials_used(((TObjPlayer *)arg1)->get_luck_materials_used());
    TObjPlayer__sub_8013A748(&record->m_config, arg1 + 0x500);
    for (i = 0; i < 0x13; i++) {
        overflow = record->technique_level_overflow(i);
        TObjPlayer::split_capped_value(TObjPlayer__sub_801C0124(arg1 + 0x428, i),
            record->technique_level(i), overflow);
    }
    record->m_inventory.m_language = current_language;
    if (game_files_modified() != 0) {
        record->mark_game_files_modified();
    }
    ((TObjPlayer *)arg1)->apply_pending_action((saddr)record);
    ((TObjPlayer *)arg1)->copy_mag_level_to_record((u8 *)record);
    ((TObjPlayer *)arg1)->copy_byte_339_to_record((u8 *)record);
    ((TObjPlayer *)arg1)->copy_battle_mode((u8 *)record);
    ((TObjPlayer *)arg1)->clear_flag_80000();
}

void TObjPlayer::set_action_state(u8 v) { *(u8*)((char*)this + 0x173) = v; }
void TObjPlayer::clear_item_slots() { { int i; for (i = 0; i < 30; i++) { ((TAdSinglePlyChrSelectGC *)((char*)this + 0x4 + i * 28))->clear_inventory_slot(); } } }

void TObjPlayer__sub_802C456C(Obj_802C456C *self, s32 i, u8 v) {
    self->recs[i].f6 = v;
}

void TObjPlayer::set_action_palette_slot(s32 i, u8 v) {
    S_802C457C *self = (S_802C457C *)this;
    is_slot_within_limit__10TObjPlayerFllUc(self->f3A1, i, v);
    self->buf[i] = v;
}

void*TObjPlayer::get_action_data() { return (char*)this + 0x408; }
void TPlyCharData::set_luck_materials_used(u8 count) { m_inventory.m_items[12].m_present[3] = count; }
void TPlyCharData::set_def_materials_used(u8 count) { m_inventory.m_items[11].m_present[3] = count; }
void TPlyCharData::set_evade_materials_used(u8 count) { m_inventory.m_items[10].m_present[3] = count; }
void TPlyCharData::set_mind_materials_used(u8 count) { m_inventory.m_items[9].m_present[3] = count; }
void TPlyCharData::set_power_materials_used(u8 count) { m_inventory.m_items[8].m_present[3] = count; }
void TObjPlayer::set_field_1ab(u8 v) { *((u8 *)this + 0x1AB) = v; }
void TObjPlayer::set_field_18f(u8 v) { *((u8 *)this + 0x18F) = v; }

void TObjPlayer::set_current_time() {
    saddr arg0 = (saddr)this;
    s32 spC;
    s32 sp8;
    getDateStamp((DateStamp *)(&spC));
    DateToSeconds((DateStamp *)(&spC), (int *)(&sp8));
    TObjPlayer__sub_802C4648((Obj_802C4648 *)(arg0), sp8);
}

void TObjPlayer__sub_802C4648(Obj_802C4648 *self, u32 v) {
    self->f77 = v;
    self->f93 = v >> 8;
    self->faf = v >> 16;
    self->fcb = v >> 24;
}

void TObjPlayer__sub_802C4668(O_802C4668 *self, u32 c) {
    self->e[0].v = c;
    self->e[1].v = c >> 8;
    self->e[2].v = c >> 16;
    self->e[3].v = c >> 24;
}

u8 *TPlyCharData::technique_level(s32 tech) {
    return &m_tech_levels[tech];
}

u8 *TPlyCharData::technique_level_overflow(s32 tech) {
    return (u8 *)&m_inventory.m_items[tech].m_present[2];
}

void TPlyCharData::mark_game_files_modified() { m_inventory.m_items[0].m_present[3] |= 0x40; }
}
int init_character_action_config(void* p) { return init_action_config__10TObjPlayerFv((char*)p + 0x24); }

int TObjPlayer__sub_802C46E0(void* p) { return set_palette_entry__20TWindowActionPaletteFlllll(p); }

void TObjPlayer::clear_flag_80000() { clear_state_flags((saddr)((void*)524288)); }
void TObjPlayer::set_flag_80000() { set_state_flags((uaddr)((void*)524288)); }
