#include "types.h"
#include "pso/misc/TLobby_8001D6A0.h"
#include "pso/misc/TNpcPlayer_802C3CD0.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/misc/TQuestListVM.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"

struct E_802C4698 { u8 pad[0x1c]; };

struct O_802C4698 { u8 pad[6]; E_802C4698 e[1]; };

struct O_802C4688 { u8 pad[0x408]; u8 buf[1]; };

struct E_802C4698;
struct O_802C4698;
struct O_802C4688;
struct VBase_802C3F74 { char pad[0x18]; };

struct Item_802C3F74 : VBase_802C3F74 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20(s32);
    virtual void m21(s32);
};

extern "C" {
s16 get_actor_tp(void *);
s16 get_actor_hp(void *);
void copy_player_visual_record(void *, void *);
void TObjPlayer__sub_8013A748(void *, void *);
void clamp_stats__10TObjPlayerFiPv(void *, void *, s32);
s8 TObjPlayer__sub_801AFD8C(void *);
s8 query_state_if_present__10TObjPlayerFPv(void *, s32);
u8 TObjPlayer__sub_801BE7BC(void *);
u8 get_equip_flags__10TObjPlayerFv(void *);
u8 get_inventory_state__10TObjPlayerFv(void *);
u8 get_field_374_state__10TObjPlayerFv(void *);
u8 get_field_374__10TObjPlayerFv(void *);
s32 TObjPlayer__sub_801C0124(void *, s16);
s32 get_ptr_4__10TObjPlayerFv(s8 *);
s32 get_class_stat_entry__10TObjPlayerFPUc(void *);
void split_capped_value__10TObjPlayerFUcPUcPSc(s32, u8 *, E_802C4698 *);
u8 *TObjPlayer__sub_802C4688(O_802C4688 *self, s32 i);
E_802C4698 *TObjPlayer__sub_802C4698(O_802C4698 *self, s32 i);
s32 reset(s32);
s32 export_inventory_entry__10TObjPlayerFiPv(Item_802C3F74 *, s32);
s32 TObjPlayer__sub_802A1018();
int init_character_stats_for_level(s32, s8 *, s32);
int copy_item_entry_array(s8, s32, s32);

s32 TNpcPlayer::send_command(s32 cls, s8 arg1, s32 src, s32 level, s8 *arg4) {
    *arg4 = arg1;
    copy_item_entry_array(arg1, src, get_ptr_4__10TObjPlayerFv(arg4));
    init_character_stats_for_level(cls, arg4, level);
    return 1;
}
void export_character_data__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1) {
    s32 i;
    s16 hp;
    s16 facing;
    TItem *eq;
    E_802C4698 *e;
    s32 j;
    s32 k;
    ((TObjPlayer *)arg0)->set_flag_80000();
    *(s8 *)((s8 *)arg1 + 0) = query_state_if_present__10TObjPlayerFPv(arg0, get_ptr_4__10TObjPlayerFv((s8 *)arg1));
    hp = get_actor_hp(arg0);
    facing = get_actor_tp(arg0);
    for (i = 0; i != 0xD; i++) {
        eq = ((TObjPlayer *)arg0)->get_equipped_item(i);
        if (eq != NULL) {
            eq->remove_equip_stats(1);
        }
    }
    *(s8 *)((s8 *)arg1 + 1) = ((TObjPlayer *)arg0)->get_hp_material_points();
    *(s8 *)((s8 *)arg1 + 2) = ((TObjPlayer *)arg0)->get_tp_materials_clamped();
    ((TObjPlayer *)arg1)->set_flag_e7(get_field_374__10TObjPlayerFv(arg0));
    ((TObjPlayer *)arg1)->set_flag_103(get_field_374_state__10TObjPlayerFv(arg0));
    ((TObjPlayer *)arg1)->set_action_flags(get_inventory_state__10TObjPlayerFv(arg0));
    ((TObjPlayer *)arg1)->set_byte_13b(get_equip_flags__10TObjPlayerFv(arg0));
    ((TObjPlayer *)arg1)->set_field_157(TObjPlayer__sub_801BE7BC(arg0));
    copy_data__6TLobbyFPvPv(arg1 + 0x34C, (void *)((TQuestListVM *)arg0)->get_quest_id());
    clamp_stats__10TObjPlayerFiPv(arg0, arg1 + 0x34C, get_class_stat_entry__10TObjPlayerFPUc(arg0));
    copy_player_visual_record(arg1 + 0x370, arg0 + 0x85C);
    TObjPlayer__sub_8013A748(arg1 + 0x3C0, arg0 + 0x500);
    for (j = 0; j < 0x13; j++) {
        e = TObjPlayer__sub_802C4698((O_802C4698 *)arg1, j);
        split_capped_value__10TObjPlayerFUcPUcPSc(TObjPlayer__sub_801C0124(arg0 + 0x428, j),
            TObjPlayer__sub_802C4688((O_802C4688 *)arg1, j), e);
    }
    for (k = 0; k != 0xD; k++) {
        eq = ((TObjPlayer *)arg0)->get_equipped_item(k);
        if (eq != NULL) {
            eq->add_equip_stats(1);
        }
    }
    ((TObjPlayer *)arg0)->set_hp_clamped(hp);
    ((TObjPlayer *)arg0)->set_tp(facing);
    *(s8 *)((s8 *)arg1 + 3) = TObjPlayer__sub_801AFD8C(arg0);
    ((TObjPlayer *)arg0)->apply_pending_action((s32)arg1);
    ((TObjPlayer *)arg0)->copy_mag_level_to_record((u8 *)arg1);
    ((TObjPlayer *)arg0)->copy_byte_339_to_record((u8 *)arg1);
    ((TObjPlayer *)arg0)->copy_battle_mode((u8 *)arg1);
    ((TObjPlayer *)arg0)->set_flag_524288();
}
void export_state_to_record__10TObjPlayerFPvPv(u8 *arg0, s8 *arg1) {
    Item_802C3F74 *items[30];
    s16 hp;
    s16 facing;
    Item_802C3F74 *item;
    s32 i;
    s32 n;
    Item_802C3F74 **p;
    s32 k;
    s32 b;
    s32 i2;
    s32 rec;
    s32 a;
    s32 m;
    ((TObjPlayer *)arg0)->set_flag_80000();
    arg1[0] = query_state_if_present__10TObjPlayerFPv(arg0, get_ptr_4__10TObjPlayerFv(arg1));
    hp = get_actor_hp(arg0);
    facing = get_actor_tp(arg0);
    p = items;
    for (i = 0; i < 30; i++) {
        *p++ = NULL;
    }
    p = items;
    n = 0;
    for (i2 = 0; i2 != 13; i2++) {
        item = (Item_802C3F74 *)((TObjPlayer *)arg0)->get_equipped_item(i2);
        if (item != NULL) {
            item->m21(1);
            *p++ = item;
            n++;
        }
    }
    arg1[0] = n;
    rec = get_ptr_4__10TObjPlayerFv(arg1);
    p = items;
    for (i = 0; i < 30; i++) {
        if (*p != NULL) {
            export_inventory_entry__10TObjPlayerFiPv(*p, rec);
            p++;
        } else {
            reset(rec);
        }
        rec += 0x1C;
    }
    arg1[1] = ((TObjPlayer *)arg0)->get_hp_material_points();
    arg1[2] = ((TObjPlayer *)arg0)->get_tp_materials_clamped();
    ((TObjPlayer *)arg1)->set_flag_e7(get_field_374__10TObjPlayerFv(arg0));
    ((TObjPlayer *)arg1)->set_flag_103(get_field_374_state__10TObjPlayerFv(arg0));
    ((TObjPlayer *)arg1)->set_action_flags(get_inventory_state__10TObjPlayerFv(arg0));
    ((TObjPlayer *)arg1)->set_byte_13b(get_equip_flags__10TObjPlayerFv(arg0));
    ((TObjPlayer *)arg1)->set_field_157(TObjPlayer__sub_801BE7BC(arg0));
    clamp_stats__10TObjPlayerFiPv(arg0, arg1 + 0x34C, get_class_stat_entry__10TObjPlayerFPUc(arg0));
    copy_player_visual_record(arg1 + 0x370, arg0 + 0x85C);
    TObjPlayer__sub_8013A748(arg1 + 0x3C0, arg0 + 0x500);
    for (k = 0; k < 19; k++) {
        a = (s32)TObjPlayer__sub_802C4698((O_802C4698 *)arg1, k);
        split_capped_value__10TObjPlayerFUcPUcPSc(TObjPlayer__sub_801C0124(arg0 + 0x428, k), TObjPlayer__sub_802C4688((O_802C4688 *)arg1, k), (E_802C4698 *)a);
    }
    for (m = 0; m != 13; m++) {
        item = (Item_802C3F74 *)((TObjPlayer *)arg0)->get_equipped_item(m);
        if (item != NULL) {
            item->m20(1);
        }
    }
    ((TObjPlayer *)arg0)->set_hp_clamped(hp);
    ((TObjPlayer *)arg0)->set_tp(facing);
    arg1[3] = TObjPlayer__sub_801AFD8C(arg0);
    if (TObjPlayer__sub_802A1018() != 0) {
        ((TObjPlayer *)arg1)->set_flag_40();
    }
    ((TObjPlayer *)arg0)->apply_pending_action((s32)arg1);
    ((TObjPlayer *)arg0)->copy_mag_level_to_record((u8 *)arg1);
    ((TObjPlayer *)arg0)->copy_byte_339_to_record((u8 *)arg1);
    ((TObjPlayer *)arg0)->copy_battle_mode((u8 *)arg1);
    ((TObjPlayer *)arg0)->set_flag_524288();
}

}
