#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/unk/TLobby.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_8011A780.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/player/PlayerRequirementStats.h"
#include "pso/player/TObjPlayer_8011C000.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/item/TItemMoney.h"
#include "pso/item/TItemObject.h"
#include "pso/item/armor/TItemProArmor.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/item/armor/TItemProUnit.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/player/TObjPlayer_80121010.h"
#include "pso/player/TObjPlayer_80104860.h"
#include "pso/item/TItem.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TObjPlayer_80105874.h"
#include "pso/unk/text_80103674.h"
#include "pso/unk/text_8010F168.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/TItemBuff.h"
#include "pso/item/MagStats.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_80105A2C.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/item/item_pmt.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/item/TItemDisconnectCtrl_80105BE8.h"
#include "pso/item/TItemLockCountCtrl.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/item/TItemTexLoad.h"
#include "pso/effect/item/TItemEffectWeapon.h"
#include "pso/item/drop/TItemDrop_80105D0C.h"
#include "pso/unk/TLobby_80103F5C.h"

// The item class resource sets, one {load, unload} pair each, ended by a null pair;
// init_game_resources hands the table to create_load_unload_set.
struct ItemClassLoadUnloadEntry {  // inferred: from item_class_load_unload_table
    void (*load)();
    void (*unload)();
};

ItemClassLoadUnloadEntry item_class_load_unload_table[15] = {
    { load_items, unload_items },
    { TObjPlayer__sub_80121060, TObjPlayer__sub_8012105C },
    { TItemMag::load_data_files, TItemMag::cleanup },
    { TItemProArmor::load_data, TItemProArmor::free },
    { TItemProShield::load_data, TItemProShield::free },
    { TItemProUnit::load_data, TItemProUnit::free },
    { TLobby::alloc_objects, TLobby::free_boss_rocks },
    { TItemDisconnectCtrl__sub_80105BE8, NULL },
    { TItemLockCountCtrl::create_instance, TItemTimerEvent::clear_active },
    { TItemLockCountCtrl::init_effect_table, TItemLockCountCtrl::free_all },
    { load_item_kt_afs, TItemTexLoad::free_textures },
    { TItemEffectWeapon::initialize_static_effects, TItemEffectWeapon::free_static_effects },
    { init_item_drop_globals, unload_item_drop_globals },
    { TLobby::handle_select_confirm, TLobby__sub_80104464 },
    { NULL, NULL },
};

struct Blk_8010542C { u32 w[4]; };
struct Item_8010542C { u32 a; Blk_8010542C b; };
struct Entry_8010567C { u16 a; u16 b; };

struct Pkt_8010567C {
    u8 hdr[4];
    u8 f4;
    u8 f5;
    s16 f6;
    f32 x;
    f32 z;
    s16 f10;
    s16 f12;
    u8 f14;
    f32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
};

struct Obj_8010567C {
    u8 pad[0x28];
    s16 f28;
    u8 pad2a[2];
    s16 f2c;
    u8 pad2e[0x38 - 0x2E];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0x70 - 0x44];
    f32 f70;
    u8 pad74[0x84 - 0x74];
    s32 f84;
    s32 f88;
    s32 f8c;
};


struct Rec_80105538 { s32 a; u16 b; u16 b2; s32 c; };

struct Pkt_80105538 {
    u8 hdr[4];
    s8 f4;
    s8 f5;
    s16 f6;
    f32 x;
    f32 z;
    s16 f10;
    u8 f12[2];
    s8 f14;
};

struct Vec_80105538 { f32 x, y, z; };

struct Obj_80105538 {
    u8 pad[0x28];
    s16 f28;
    u8 pad2a[2];
    s16 f2c;
    u8 pad2e[0x38 - 0x2E];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0x370 - 0x44];
    s32 f370;
};

extern "C" {
// Item factories by item group (item[0]) and, for armor, by subgroup (item[1]).
typedef TItem *(*Fn_8010542C)(u8 *item);
TItem *TLobby__sub_801054E0(u8 *item);
Fn_8010542C item_pro_create_fn_table[4] = {
    0, TItemProArmor::create, TItemProShield::create, TItemProUnit::create,
};
Fn_8010542C item_create_fn_table[5] = {
    (Fn_8010542C)create_weapon_for_item, TLobby__sub_801054E0, TItemMag::create, TItemObject::create_tool,
    (Fn_8010542C)TItemMoney::create,
};
void *get_player_by_client_id(s32);
s32 get_current_floor(void);
s32 TObjPlayer__sub_80104840(s32);
extern s32 TLobby__designated_client_id;
extern Entry_8010567C *quest_object_entries;
extern s32 local_client_id;
int check_class_equip_permission(TObjPlayer *player, s32 perm);
s32 *csnVecterUnder(s32 origin, s32 mask);
s32 is_valid_drop_floor();
}
void *build_6x06_send_guild_card(void *arg0);
extern Rec_80105538 *TLobby__data_805D6144;
extern "C" {
void send_6x60_standard_drop_item_request(Obj_80105538 *self);

}


extern "C" s32 obj_isState3_324__9TObjCharaFv(void *);
extern "C" s32 is_script_controlled__10TObjPlayerFv(void *);
extern "C" s32 query_flag__13TItemMenuCtrlFl(s32);
extern "C" int clear_fields__20TWindowSubStatusDispFv(void *);
s32 check_equip_requirements(void *self, TItemData *p, s32 *out) {
  void *new_var;
  s32 flags;
  struct 
  {
    s16 a;
    s16 x2;
    s16 b;
    s16 c;
    s32 r[2];
  } st;
  u32 k;
  int new_var3;
  s32 r;
  void *new_var2;
  if (((s32) self == 0) || (p == 0))
  {
    if (out != 0)
    {
      *out |= 0x20;
    }
    return 0;
  }
  new_var2 = self;
  if ((obj_isState3_324__9TObjCharaFv(new_var2) != 0) || (is_script_controlled__10TObjPlayerFv(new_var = new_var2) != 0))
  {
    if (out != 0)
    {
      *out = 0;
    }
    return 1;
  }
  if (is_quest_active() != 0)
  {
    k = 0;
    switch (((u8 *) p)[0])
    {
      case 0:
        k = 1;
        break;

      case 1:
        switch (((u8 *) p)[1])
      {
        case 1:
          k = 2;
          break;

        case 2:
          k = 3;
          break;

        case 3:
          k = 4;
          break;

      }

        break;

      case 2:
        k = 5;
        break;

    }

    if ((k != 0) && (query_flag__13TItemMenuCtrlFl(k) == 1))
    {
      return 0;
    }
  }
  flags = 0;
  switch (((u8 *) p)[0])
  {
    case 0:
      if ((s32) (p = (TItemData *) lookup_item_pmt_record((u8 *) p)) != 0)
    {
      if (check_class_equip_permission((TObjPlayer *) new_var2, (s16) (*((u16 *) ((u8 *) p + 8)))) == 0)
      {
        flags |= 1;
      }
      clear_fields__20TWindowSubStatusDispFv(&st);
      build_player_equipment_requirement_stats((TObjPlayer *) new_var, (PlayerRequirementStats *) (&st));
      if (st.a < (*((u16 *) ((u8 *) p + 0xe))))
      {
        flags |= 2;
      }
      if (st.c < (*((u16 *) ((u8 *) p + 0x12))))
      {
        flags |= 4;
      }
      if (st.b < (*((u16 *) ((u8 *) p + 0x10))))
      {
        flags |= 8;
      }
    }
    else
    {
      flags |= 0x20;
    }
      break;

    case 1:
      if (((u8 *) p)[1] != 3)
    {
      if ((s32) (p = (TItemData *) lookup_item_pmt_record((u8 *) p)) != 0)
      {
        if (check_class_equip_permission((TObjPlayer *) new_var, (s16) (*((u16 *) ((u8 *) p + 0xe)))) == ((0, 0)))
        {
          flags |= 1;
        }
        r = ((TObjChara *) new_var)->get_actor_level_index();
        if (r < ((u8 *) p)[0x10])
        {
          flags |= 0x10;
        }
      }
      else
      {
        flags |= 0x20;
      }
    }
    else
      if (check_class_equip_permission((TObjPlayer *) new_var2, 0xd7) != 0)
    {
      if ((p = (TItemData *) lookup_item_pmt_record((u8 *) p)) != 0)
      {
        switch (*((s16 *) ((u8 *) p + 8)))
        {
          case 1:

          case 5:

          case 0x10:

          case 0x12:

          case 0x15:
            flags |= 1;
            break;

          default:
            break;

        }

      }
      else
      {
        flags |= 0x20;
      }
    }
      break;

    case 2:
      if ((p = (TItemData *) lookup_item_pmt_record((u8 *) p)) != 0)
    {
      if (check_class_equip_permission((TObjPlayer *) new_var, (s16) (*((u16 *) ((u8 *) p + 0x14)))) == 0)
      {
        flags |= 1;
      }
    }
    else
    {
      flags |= 0x20;
    }
      break;

    case 3:
      switch (((u8 *) p)[1])
    {
      case 2:
        r = ((u8 *) p)[4];
      {
        u8 lim = ((u8 (*)(u8, u8)) get_technique_learn_limit)(*((u8 *) (((u8 *) new_var2) + 0x88d)), r);
        if ((lim == 0xff) || (lim < ((u8 *) p)[2]))
        {
          flags |= 1;
        }
      }
        break;

      case 8:
        if (check_class_equip_permission((TObjPlayer *) new_var2, 0xd7) != 0)
      {
        flags |= 1;
      }
        break;

    }

      break;

    case 4:
      new_var3 = 0xf423f;
      if (new_var3 < (*((s32 *) ((u8 *) p + 0x10))))
    {
      flags |= 0x20;
    }
      break;

  }

  if (out != 0)
  {
    *out = flags;
  }
  if (flags == 0)
  {
    return 1;
  }
  return 0;
}

extern "C" {
int check_class_equip_permission(TObjPlayer *player, s32 perm) {
    s32 t = player->class_flags;
    if (t & CLASS_FLAG_HUNTER) {
        if (!(perm & 1)) return 0;
    } else if (t & CLASS_FLAG_RANGER) {
        if (!(perm & 2)) return 0;
    } else if (!(perm & 4)) {
        return 0;
    }
    if (t & CLASS_FLAG_ANDROID) {
        if (!(perm & 0x10)) return 0;
    } else if (t & CLASS_FLAG_NEWMAN) {
        if (!(perm & 0x20)) return 0;
    } else if (t & CLASS_FLAG_HUMAN) {
        if (!(perm & 8)) return 0;
    }
    if (t & CLASS_FLAG_MALE) {
        if (!(perm & 0x40)) return 0;
    } else if (t & CLASS_FLAG_FEMALE) {
        if (!(perm & 0x80)) return 0;
    }
    return 1;
}

u8 roll_weapon_special_channel15(u8 arg0) { return roll_weapon_special_for_stars(arg0); }
}

TItem *construct_item(TItemData *data) {
    Item_8010542C *src = (Item_8010542C *)data;
    Fn_8010542C fn;
    if (src != 0) {
        Item_8010542C item = *src;
        ((TItemData *)&item)->decode_from_network();
        if (((TItemData *)(&item))->isValidGroundDrop() != 0) {
            if (*(u8 *)src < 5) {
                fn = item_create_fn_table[*(u8 *)src];
                if (fn != 0) {
                    observe_item_id(item.b.w[2]);
                    return fn((u8 *)&item);
                }
            }
        }
    }
    return 0;
}

extern "C" {

TItem *TLobby__sub_801054E0(u8 *item) {
    if (item != 0) {
        if (item[1] < 4) {
            if (item_pro_create_fn_table[item[1]] != 0) {
                return item_pro_create_fn_table[item[1]](item);
            }
        }
    }
    return 0;
}

// Dead-stripped by the linker: its 0.0f is the only trace left. The DOL pools 0.0f (0x805DAAB0)
// ahead of send_6x60_standard_drop_item_request's 100.0f, so a 0.0f user came first in this TU.
// inferred: minimal body, the real function is unknown.
void clear_drop_request_position(Vec_80105538 *v) {
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
}

void send_6x60_standard_drop_item_request(Obj_80105538 *self) {
    void *p1;
    void *p2;
    if (self != 0) {
        p1 = get_player_by_client_id(TLobby__designated_client_id);
        p2 = get_player_by_client_id(local_client_id);
        if (p1 != 0 && p2 != 0) {
            get_current_floor();
            if (is_valid_drop_floor() != 0 &&
                (((TObjPlayer *)p1)->get_floor() != ((TObjPlayer *)p2)->get_floor() ||
                 TLobby__designated_client_id == local_client_id)) {
                if (self->f2c != -1) {
                    Rec_80105538 e = TLobby__data_805D6144[self->f2c];
                    if (e.b != 0xFFFF) {
                        Pkt_80105538 pkt;
                        build_6x06_send_guild_card(&pkt);
                        pkt.f4 = get_current_floor();
                        pkt.f5 = self->f370;
                        pkt.f6 = self->f2c;
                        pkt.x = self->x;
                        pkt.z = self->z;
                        pkt.f10 = self->f28;
                        pkt.f14 = get_current_floor_area();
                        Vec_80105538 v;
                        v.x = pkt.x;
                        v.y = 100.0f;
                        v.z = pkt.z;
                        if (csnVecterUnder((s32)&v, 1) != 0) {
                            ((TLobby *)(&pkt))->dispatch_packet_wrapper();
                        }
                    }
                }
            }
        }
    }
}

void TObjChara::request_box_item_drop(void *unused, s16 arg2) {
    Obj_8010567C *self = (Obj_8010567C *)this;
    void *p1;
    void *p2;
    if (self != 0) {
        p1 = get_player_by_client_id(TLobby__designated_client_id);
        p2 = get_player_by_client_id(local_client_id);
        if (p1 != 0 && p2 != 0 && TObjPlayer__sub_80104840(get_current_floor_area()) != AREA_PIONEER2_EP1 &&
            (((TObjPlayer *)p1)->get_floor() != ((TObjPlayer *)p2)->get_floor() ||
             TLobby__designated_client_id == local_client_id)) {
            if (self->f2c != -1) {
                Entry_8010567C e = quest_object_entries[self->f2c];
                if (e.b != 0xFFFF) {
                    Pkt_8010567C pkt;
                    ((TLobby *)(&pkt))->build_6x06_guild_card_packet();
                    pkt.f4 = get_current_floor();
                    pkt.f5 = 0x30;
                    pkt.x = self->x;
                    pkt.z = self->z;
                    pkt.f10 = self->f28;
                    pkt.f12 = arg2;
                    pkt.f6 = self->f2c;
                    pkt.f14 = get_current_floor_area();
                    pkt.f18 = self->f70;
                    pkt.f1c = this->set_params[0];
                    pkt.f20 = self->f88;
                    pkt.f24 = this->set_params[2];
                    ((TLobby *)(&pkt))->process_and_dispatch_packet();
                }
            }
        }
    }
}
}

struct Msg_801057A8 {
    s8 client;
    u8 pad1[3];
    f32 x;
    f32 z;
    s16 area;
    u8 pad2[2];
    u8 item[1];
};

struct Item_801057A8 {
    u8 pad[0x28];
    s16 area;
    u8 pad2[0xE];
    f32 x;
    f32 y;
    f32 z;
};

extern "C" {
Item_801057A8 *spawn_dropped_item_from_msg(Msg_801057A8 *arg0, s32 arg1);
Item_801057A8 *spawn_dropped_item_from_msg(Msg_801057A8 *arg0, s32 arg1) {
    Item_801057A8 *item;
    s8 me;
    s32 act;
    u8 ok;
    item = NULL;
    if (arg0 != NULL) {
        me = get_current_floor();
        act = is_local_player_off_current_floor();
        ok = 0;
        if (arg0->client == me && act != 1) {
            ok = 1;
        }
        if (ok != 0) {
            item = (Item_801057A8 *)construct_item((TItemData *)arg0->item);
            if (item != NULL) {
                item->x = arg0->x;
                item->z = arg0->z;
                item->area = arg0->area;
                ((TItem *)item)->place_on_ground(arg0->client, &item->x, 1);
            }
        }
        if (arg1 == 0) {
            ((void (*)(s32, s32, u8 *, f32, f32))add_item_condition)(arg0->client, arg0->area, arg0->item, arg0->x, arg0->z);
        }
    }
    return item;
}

}

extern "C" {
s32 create_load_unload_set(ItemClassLoadUnloadEntry *table);
extern s32 lbl_805D5440;
extern int item_class_load_handle;

void TObjPlayer::free_item_globals() { TItemDrop__sub_8010F168((void *)item_class_load_handle, (s16)((void*)1)); item_class_load_handle = 0; TItemLoad::free_all(); TItemBuff::free_all_and_init(); }

void TObjPlayer::init_game_resources() {
    init_item_chunk_buffers();
    TItemLoad::init_resources();
    item_class_load_handle = create_load_unload_set(item_class_load_unload_table);
    ((FlagWord *)(&lbl_805D5440))->reset();
}

void fn_801058E8(void* p) { *(u8*)((char*)p + 0x7) |= 0x1; }

s32 TObjPlayer::is_script_controlled() {
    return this->control_state == 6;
}

int TObjPlayer::activate_d04_slot() { return TObjPlayer::get_slot_value((s32 *)((char*)this + 0xd04), 1); }

}

extern "C" {

int TItemData::test_flag3() { return TObjPlayer::get_slot_value((s32 *)((char*)this + 0xd04), 3); }
int TItemData::get_item_field_2() { return TObjPlayer::get_slot_value((s32 *)((char*)this + 0xd04), 2); }


}

MagStats *MagStats::init() { clear(); return this; }

void TWindowSubStatusDisp::clear_fields() { *(s16*)((char*)this + 0xa) = 0; *(s16 *)&this->m_prev = 0; *(s16 *)&this->m_id = 0; *(s16 *)&this->m_flags = 0; *(s16*)((char*)this + 0x2) = 0; *(s16 *)&this->m_name = 0; *(s16 *)&this->m_down = 0; *(s16*)((char*)this + 0x12) = 0; *(s16 *)&this->m_up = 0; *(s16*)((char*)this + 0xe) = 0; *(s16 *)&this->m_next = 0; }

extern "C" {

s32 test_flags_any(s32, s32);

extern u32 TItemMenuCtrl__instance;

s32 TItemMenuCtrl::query_flag(s32 arg0) {
    if ((u32) TItemMenuCtrl__instance != 0U) {
        return test_flags_any(TItemMenuCtrl__instance + 0x1C, 1 << arg0);
    }
    return 0;
}

}

void TLobby::dispatch_packet_wrapper() { bswap_6x60_drop_request_fields(this); send_subcommand_to_leader(this); }

void bswap_6x60_drop_request_fields(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16((u16 *)((char*)p + 0x6)); bswap_16((u16 *)((char*)p + 0x10)); bswap_16((u16 *)((char*)p + 0x12)); bswap_32((u32 *)((char*)p + 0x8)); bswap_32((u32 *)((char*)p + 0xc)); }
void *build_6x06_send_guild_card(void *arg0) {
    build_6x05_write_switch_flag(arg0);
    *(s8 *)((s8 *)arg0 + 0) = 0x60;
    *(s8 *)((s8 *)arg0 + 1) = 6;
    return arg0;
}
void build_6x05_write_switch_flag(void* a0) { *(float*)((char*)a0 + 0xc) = 0.0f; *(float*)((char*)a0 + 0x8) = 0.0f; *(short*)((char*)a0 + 0x10) = 0; *(short*)((char*)a0 + 0x12) = 0; *(unsigned char*)((char*)a0 + 0x5) = 0; *(unsigned char*)((char*)a0 + 0x4) = 0; *(unsigned char*)((char*)a0 + 0x0) = 96; *(unsigned char*)((char*)a0 + 0x1) = 5; }

void TLobby::process_and_dispatch_packet() { bswap_6xa2_fields(); send_subcommand_to_leader(this); }
void TLobby::bswap_6xa2_fields() { bswap_6x60_drop_request_fields(this); bswap_32((u32 *)((char*)this + 0x18)); bswap_32((u32 *)((char*)this + 0x1c)); bswap_32((u32 *)((char*)this + 0x20)); bswap_32((u32 *)((char*)this + 0x24)); }
void *TLobby::build_6x06_guild_card_packet() {
    build_6x06_send_guild_card(this);
    *((u8 *)this + 0) = 0xA2;
    *((u8 *)this + 1) = 0x0A;
    return this;
}
