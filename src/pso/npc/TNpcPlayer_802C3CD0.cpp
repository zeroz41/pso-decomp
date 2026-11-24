#include "pso/item/InventoryEntryCopy.h"
#include "pso/player/TObjPlayer_802C367C.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyItem.h"
#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TNpcPlayer_802C3CD0.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby_802A0F3C.h"
#include "pso/network/TPlyJoinLobbyEntry.h"


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
void copy_player_visual_record(void *, void *);
void clamp_stats__10TObjPlayerFiPv(void *, void *, s32);
u8 TObjPlayer__sub_801C0124(void *, s16);
u8 *TObjPlayer__sub_802C4688(O_802C4688 *self, s32 i);
E_802C4698 *TObjPlayer__sub_802C4698(O_802C4698 *self, s32 i);
saddr reset(s32);

s32 TNpcPlayer::send_command(s32 cls, s32 count, const TPlyInventoryItem *source, s32 level, TPlyCharData *character) {
    character->m_inventory.m_num_items = count;
    copy_item_entry_array(count, source,
        character->m_inventory.get_items());
    init_character_stats_for_level(cls, character, level);
    return 1;
}
void export_character_data__10TObjPlayerFPvPv(TObjPlayer *player, TPlyCharData *character) {
    u8 *arg0 = reinterpret_cast<u8 *>(player);
    u8 *arg1 = reinterpret_cast<u8 *>(character);
    s32 i;
    s16 hp;
    s16 facing;
    TItem *eq;
    E_802C4698 *e;
    s32 j;
    s32 k;
    player->set_flag_80000();
    character->m_inventory.m_num_items = player->query_state_if_present(character->m_inventory.get_items());
    hp = ((TObjChara *)arg0)->get_actor_hp();
    facing = get_actor_tp(arg0);
    for (i = 0; i != 0xD; i++) {
        eq = player->get_equipped_item(i);
        if (eq != NULL) {
            eq->remove_equip_stats(1);
        }
    }
    character->m_inventory.m_hp_materials_used = player->get_hp_material_points();
    character->m_inventory.m_tp_materials_used = player->get_tp_materials_clamped();
    ((TObjPlayer *)arg1)->set_flag_e7(player->get_field_374());
    ((TObjPlayer *)arg1)->set_flag_103(player->get_field_374_state());
    ((TObjPlayer *)arg1)->set_action_flags(player->get_inventory_state());
    ((TObjPlayer *)arg1)->set_byte_13b(player->get_equip_flags());
    ((TObjPlayer *)arg1)->set_field_157(player->get_luck_materials_used());
    TLobby::copy_data(&character->m_stats, player->get_stats());
    clamp_stats__10TObjPlayerFiPv(arg0, &character->m_stats, (saddr)TObjPlayer::get_class_stat_entry(arg0));
    copy_player_visual_record(&character->m_disp_part2, arg0 + 0x85C);
    TObjPlayer__sub_8013A748(&character->m_config, arg0 + 0x500);
    for (j = 0; j < 0x13; j++) {
        e = TObjPlayer__sub_802C4698((O_802C4698 *)arg1, j);
        TObjPlayer::split_capped_value(TObjPlayer__sub_801C0124(arg0 + 0x428, j),
            TObjPlayer__sub_802C4688((O_802C4688 *)arg1, j), (s8 *)e);
    }
    for (k = 0; k != 0xD; k++) {
        eq = player->get_equipped_item(k);
        if (eq != NULL) {
            eq->add_equip_stats(1);
        }
    }
    player->set_hp_clamped(hp);
    player->set_tp(facing);
    character->m_inventory.m_language = player->get_language();
    player->apply_pending_action((saddr)arg1);
    player->copy_mag_level_to_record((u8 *)arg1);
    player->copy_byte_339_to_record((u8 *)arg1);
    player->copy_battle_mode((u8 *)arg1);
    player->clear_flag_80000();
}
void export_state_to_record__10TObjPlayerFPvPv(u8 *player, s8 *arg1) {
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
    saddr a;
    s32 m;
    ((TObjPlayer *)player)->set_flag_80000();
    arg1[0] = ((TObjPlayer *)player)->query_state_if_present(reinterpret_cast<TPlyCharData *>(arg1)->m_inventory.get_items());
    hp = ((TObjChara *)player)->get_actor_hp();
    facing = get_actor_tp(player);
    p = items;
    for (i = 0; i < 30; i++) {
        *p++ = NULL;
    }
    p = items;
    n = 0;
    for (i2 = 0; i2 != 13; i2++) {
        item = (Item_802C3F74 *)((TObjPlayer *)player)->get_equipped_item(i2);
        if (item != NULL) {
            item->m21(1);
            *p++ = item;
            n++;
        }
    }
    arg1[0] = n;
    rec = reinterpret_cast<saddr>(reinterpret_cast<TPlyCharData *>(arg1)->m_inventory.get_items());
    p = items;
    for (i = 0; i < 30; i++) {
        if (*p != NULL) {
            reinterpret_cast<TItem *>(*p)->export_inventory_entry(reinterpret_cast<TPlyInventoryItem *>(rec));
            p++;
        } else {
            reset(rec);
        }
        rec += 0x1C;
    }
    arg1[1] = ((TObjPlayer *)player)->get_hp_material_points();
    arg1[2] = ((TObjPlayer *)player)->get_tp_materials_clamped();
    ((TObjPlayer *)arg1)->set_flag_e7(((TObjPlayer *)player)->get_field_374());
    ((TObjPlayer *)arg1)->set_flag_103(((TObjPlayer *)player)->get_field_374_state());
    ((TObjPlayer *)arg1)->set_action_flags(((TObjPlayer *)player)->get_inventory_state());
    ((TObjPlayer *)arg1)->set_byte_13b(((TObjPlayer *)player)->get_equip_flags());
    ((TObjPlayer *)arg1)->set_field_157(((TObjPlayer *)player)->get_luck_materials_used());
    clamp_stats__10TObjPlayerFiPv(player, arg1 + 0x34C, (saddr)TObjPlayer::get_class_stat_entry(player));
    copy_player_visual_record(arg1 + 0x370, player + 0x85C);
    TObjPlayer__sub_8013A748(arg1 + 0x3C0, player + 0x500);
    for (k = 0; k < 19; k++) {
        a = (saddr)TObjPlayer__sub_802C4698((O_802C4698 *)arg1, k);
        TObjPlayer::split_capped_value(TObjPlayer__sub_801C0124(player + 0x428, k), TObjPlayer__sub_802C4688((O_802C4688 *)arg1, k), (s8 *)a);
    }
    for (m = 0; m != 13; m++) {
        item = (Item_802C3F74 *)((TObjPlayer *)player)->get_equipped_item(m);
        if (item != NULL) {
            item->m20(1);
        }
    }
    ((TObjPlayer *)player)->set_hp_clamped(hp);
    ((TObjPlayer *)player)->set_tp(facing);
    arg1[3] = ((TObjPlayer *)player)->get_language();
    if (TObjPlayer__sub_802A1018() != 0) {
        ((TObjPlayer *)arg1)->set_flag_40();
    }
    ((TObjPlayer *)player)->apply_pending_action((saddr)arg1);
    ((TObjPlayer *)player)->copy_mag_level_to_record((u8 *)arg1);
    ((TObjPlayer *)player)->copy_byte_339_to_record((u8 *)arg1);
    ((TObjPlayer *)player)->copy_battle_mode((u8 *)arg1);
    ((TObjPlayer *)player)->clear_flag_80000();
}

}
