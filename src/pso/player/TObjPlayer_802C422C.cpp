#include "types.h"
#include "pso/player/TObjPlayer_802C422C.h"
#include "pso/ui/TAdSelectGameModeGC_802C4748.h"
#include "pso/system/date.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TAdSelectGameModeGC.h"
#include "pso/TPlyOnCreated.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"

extern "C" {

u32 update_battle_controller__10TObjPlayerFv();
void export_state_to_record__10TObjPlayerFPvPv(u8 *arg0, s8 *arg1);

extern s32 local_client_id;

s32 sync_state__10TObjPlayerFi(s32 arg0) {
    u32 temp_r3;
    temp_r3 = update_battle_controller__10TObjPlayerFv();
    if (temp_r3 == 0U) {
        TPlyOnCreated::create((void *)((u16) local_client_id), (void *)fn_802C4748);
        return 0;
    }
    export_state_to_record__10TObjPlayerFPvPv((u8 *)temp_r3, (s8 *)arg0);
    return 1;
}

s32 get_char_index__23TAdSinglePlyChrSelectGCFUi(u32 arg0);

void TObjPlayer::sync_char_select_state() { get_char_index__23TAdSinglePlyChrSelectGCFUi((u32)((void*)65535)); ((int (*)(void))sync_state__10TObjPlayerFi)(); }

void *get_player_by_client_id(s32 i);

s32 try_assign_battle_ctrl__10TObjPlayerFiUs(s32 arg0, u16 arg1) {
    s32 temp = (s32)get_player_by_client_id((arg1));
    if (temp == 0) {
        return 0;
    }
    ((s32 (*)(void *, s32))export_player_record__10TObjPlayerFPvPv)((void *)arg0, temp);
    return 1;
}

s32 update_battle__10TObjPlayerFi(s32 arg0) {
    s32 r;
    r = update_battle_controller__10TObjPlayerFv();
    if (r == 0) {
        return 0;
    }
    ((s32 (*)(void *, s32))export_player_record__10TObjPlayerFPvPv)((void *)arg0, (s32)r);
    return 1;
}

}

struct Rec_802C456C { u8 pad[6]; u8 f6; u8 pad2[0x1c - 7]; };

struct Obj_802C456C { Rec_802C456C recs[1]; };

struct O_802C4688 { u8 pad[0x408]; u8 buf[1]; };

struct Obj_802C4648 { u8 pad[0x77]; u8 f77; u8 pad2[0x93 - 0x78]; u8 f93; u8 pad3[0xaf - 0x94]; u8 faf; u8 pad4[0xcb - 0xb0]; u8 fcb; };

struct E_802C4668 { u8 pad[7]; u8 v; u8 pad2[0x14]; };

struct O_802C4668 { E_802C4668 e[4]; };

struct E_802C4698 { u8 pad[0x1c]; };

struct O_802C4698 { u8 pad[6]; E_802C4698 e[1]; };

struct S_802C457C { u8 pad0[0x3A1]; u8 f3A1; u8 pad3A2[0x408 - 0x3A2]; u8 buf[1]; };

extern "C" {
void TObjPlayer__sub_802C456C(Obj_802C456C *self, s32 i, u8 v);
u8 *TObjPlayer__sub_802C4688(O_802C4688 *self, s32 i);
void TObjPlayer__sub_802C4648(Obj_802C4648 *self, u32 v);
void TObjPlayer__sub_802C4668(O_802C4668 *self, u32 c);
E_802C4698 *TObjPlayer__sub_802C4698(O_802C4698 *self, s32 i);
s32 copy_player_visual_record(void *, void *);
s32 TObjPlayer__sub_8013A748(void *, void *);
s32 clamp_stats__10TObjPlayerFiPv(void *, void *, void *);
s8 query_state_if_present__10TObjPlayerFPv(void *, void *);
u8 TObjPlayer__sub_801BE7BC(void *);
u8 get_equip_flags__10TObjPlayerFv(void *);
u8 get_inventory_state__10TObjPlayerFv(void *);
u8 get_field_374_state__10TObjPlayerFv(void *);
u8 get_field_374__10TObjPlayerFv(void *);
s32 TObjPlayer__sub_801C0124(void *, s16);
void split_capped_value__10TObjPlayerFUcPUcPSc(s32, u8 *, E_802C4698 *);
s32 TObjPlayer__sub_802A1018();
void is_slot_within_limit__10TObjPlayerFllUc(u8 id, s16 i, u8 v);
int init_action_config__10TObjPlayerFv(void*);
int set_palette_entry__20TWindowActionPaletteFlllll(void*);

void TObjPlayer::init_battle_selection() { get_char_index__23TAdSinglePlyChrSelectGCFUi((u32)((void*)65535)); ((int (*)(void))update_battle__10TObjPlayerFi)(); }

void export_player_record__10TObjPlayerFPvPv(TObjPlayer *arg0, u8 *arg1) {
    E_802C4698 *e;
    s32 i;
    ((TObjPlayer *)arg1)->set_flag_80000();
    copy_player_visual_record((u8 *)arg0 + 0x370, arg1 + 0x85C);
    *(s8 *)((s8 *)arg0 + 0) = query_state_if_present__10TObjPlayerFPv(arg1, (void *) (arg0->get_ptr_4()));
    ((TObjPlayer *)(*(s32 *)((s8 *)arg1 + 0xD00)))->set_flag_and_update((int)arg1);
    clamp_stats__10TObjPlayerFiPv(arg1, (u8 *)arg0 + 0x34C, (void *) (TObjPlayer::get_class_stat_entry((u8 *)arg1)));
    *(s8 *)((s8 *)arg0 + 1) = ((TObjPlayer *)arg1)->get_hp_material_points();
    *(s8 *)((s8 *)arg0 + 2) = ((TObjPlayer *)arg1)->get_tp_materials_clamped();
    arg0->set_flag_e7(get_field_374__10TObjPlayerFv(arg1));
    arg0->set_flag_103(get_field_374_state__10TObjPlayerFv(arg1));
    arg0->set_action_flags(get_inventory_state__10TObjPlayerFv(arg1));
    arg0->set_byte_13b(get_equip_flags__10TObjPlayerFv(arg1));
    arg0->set_field_157(TObjPlayer__sub_801BE7BC(arg1));
    TObjPlayer__sub_8013A748((u8 *)arg0 + 0x3C0, arg1 + 0x500);
    for (i = 0; i < 0x13; i++) {
        e = TObjPlayer__sub_802C4698((O_802C4698 *) arg0, i);
        split_capped_value__10TObjPlayerFUcPUcPSc(TObjPlayer__sub_801C0124(arg1 + 0x428, i),
            TObjPlayer__sub_802C4688((O_802C4688 *) arg0, i), e);
    }
    *(s8 *)((s8 *)arg0 + 3) = current_language;
    if (TObjPlayer__sub_802A1018() != 0) {
        arg0->set_flag_40();
    }
    ((TObjPlayer *)arg1)->apply_pending_action((s32)arg0);
    ((TObjPlayer *)arg1)->copy_mag_level_to_record((u8 *)arg0);
    ((TObjPlayer *)arg1)->copy_byte_339_to_record((u8 *)arg0);
    ((TObjPlayer *)arg1)->copy_battle_mode((u8 *)arg0);
    ((TObjPlayer *)arg1)->set_flag_524288();
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
void TObjPlayer::set_field_157(u8 v) { this->m_157 = v; }
void TObjPlayer::set_byte_13b(u8 v) { this->m_13b = v; }
void TObjPlayer::set_action_flags(u8 v) { this->m_11f = v; }
void TObjPlayer::set_flag_103(u8 v) { this->m_103 = v; }
void TObjPlayer::set_flag_e7(u8 v) { *((u8 *)this + 0xE7) = v; }
void TObjPlayer::set_field_1ab(u8 v) { this->m_1ab = v; }
void TObjPlayer::set_field_18f(u8 v) { this->m_18f = v; }

void TObjPlayer::set_current_time() {
    s32 arg0 = (s32)this;
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

u8 *TObjPlayer__sub_802C4688(O_802C4688 *self, s32 i) {
    return &self->buf[i];
}

E_802C4698 *TObjPlayer__sub_802C4698(O_802C4698 *self, s32 i) {
    return &self->e[i];
}

void TObjPlayer::set_flag_40() { *(u8*)((char*)this + 0x7) |= 0x40; }
}
int init_character_action_config(void* p) { return init_action_config__10TObjPlayerFv((char*)p + 0x24); }

int TObjPlayer__sub_802C46E0(void* p) { return set_palette_entry__20TWindowActionPaletteFlllll(p); }

void TObjPlayer::set_flag_524288() { sub_8011E204((s32)((void*)524288)); }
void TObjPlayer::set_flag_80000() { set_state_flags((u32)((void*)524288)); }
