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
typedef s32 (*Fn_8010542C)(void *);
extern Fn_8010542C item_create_fn_table[];
struct In_801054E0 { u8 pad0; u8 idx; };
typedef s32 (*Fn_801054E0)(In_801054E0 *);
struct E_801054E0 { Fn_801054E0 fn; };
extern E_801054E0 item_pro_create_fn_table[];
s32 TLobby__sub_801054E0(In_801054E0 *arg0);
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
extern const f32 lbl_805DAAB4;
extern "C" {
void send_6x60_standard_drop_item_request(Obj_80105538 *self);

}
struct WeaponPmt_80104FCC { u8 pad[8]; u16 equip; u8 padA[0xE - 0xA]; u16 atp; u16 ata; u16 mst; };
struct ArmorPmt_80104FCC { u8 pad[0xE]; u16 equip; u8 level; };
struct UnitPmt_80104FCC { u8 pad[8]; s16 kind; };
struct MagPmt_80104FCC { u8 pad[0x14]; u16 equip; };


s32 check_equip_requirements(TObjPlayer *player, TItemData *item, s32 *reasons) {
    s32 flags;
    if (player == 0 || item == 0) {
        if (reasons != 0) {
            *reasons |= 0x20;
        }
        return 0;
    }
    if (player->obj_isState3_324() != 0 || player->is_script_controlled() != 0) {
        if (reasons != 0) {
            *reasons = 0;
        }
        return 1;
    }
    if (is_quest_active() != 0) {
        u32 menu = 0;
        switch (item->data1.data_u8[0]) {
        case 0:
            menu = 1;
            break;
        case 1:
            switch (item->data1.data_u8[1]) {
            case 1:
                menu = 2;
                break;
            case 2:
                menu = 3;
                break;
            case 3:
                menu = 4;
                break;
            }
            break;
        case 2:
            menu = 5;
            break;
        }
        if (menu != 0 && TItemMenuCtrl::query_flag(menu) == 1) {
            return 0;
        }
    }
    flags = 0;
    switch (item->data1.data_u8[0]) {
    case 0: {
        WeaponPmt_80104FCC *pmt = (WeaponPmt_80104FCC *)lookup_item_pmt_record((u8 *)item);
        if (pmt != 0) {
            PlayerRequirementStats stats;
            if (check_class_equip_permission(player, (s16)pmt->equip) == 0) {
                flags |= 1;
            }
            ((TWindowSubStatusDisp *)&stats)->clear_fields();
            build_player_equipment_requirement_stats(player, &stats);
            if (stats.values[0] < pmt->atp) {
                flags |= 2;
            }
            if (stats.values[3] < pmt->mst) {
                flags |= 4;
            }
            if (stats.values[2] < pmt->ata) {
                flags |= 8;
            }
        } else {
            flags |= 0x20;
        }
        break;
    }
    case 1:
        if (item->data1.data_u8[1] != 3) {
            ArmorPmt_80104FCC *pmt = (ArmorPmt_80104FCC *)lookup_item_pmt_record((u8 *)item);
            if (pmt != 0) {
                if (check_class_equip_permission(player, (s16)pmt->equip) == 0) {
                    flags |= 1;
                }
                if (player->get_actor_level_index() < pmt->level) {
                    flags |= 0x10;
                }
            } else {
                flags |= 0x20;
            }
        } else if (check_class_equip_permission(player, 0xD7) != 0) {
            UnitPmt_80104FCC *pmt = (UnitPmt_80104FCC *)lookup_item_pmt_record((u8 *)item);
            if (pmt != 0) {
                switch (pmt->kind) {
                case 1:
                case 5:
                case 16:
                case 18:
                case 21:
                    flags |= 1;
                    break;
                }
            } else {
                flags |= 0x20;
            }
        }
        break;
    case 2: {
        MagPmt_80104FCC *pmt = (MagPmt_80104FCC *)lookup_item_pmt_record((u8 *)item);
        if (pmt != 0) {
            if (check_class_equip_permission(player, (s16)pmt->equip) == 0) {
                flags |= 1;
            }
        } else {
            flags |= 0x20;
        }
        break;
    }
    case 3:
        switch (item->data1.data_u8[1]) {
        case 2: {
            u8 limit = get_technique_learn_limit(player->m_88d, item->data1.data_u8[4]);
            if (limit == 0xFF || limit < item->data1.data_u8[2]) {
                flags |= 1;
            }
            break;
        }
        case 8:
            if (check_class_equip_permission(player, 0xD7) != 0) {
                flags |= 1;
            }
            break;
        }
        break;
    case 4:
        if ((s32)item->data2.data_u32 > 999999) {
            flags |= 0x20;
        }
        break;
    }
    if (reasons != 0) {
        *reasons = flags;
    }
    if (flags == 0) {
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
                    return (TItem *)fn(&item);
                }
            }
        }
    }
    return 0;
}

extern "C" {

s32 TLobby__sub_801054E0(In_801054E0 *arg0) {
    if (arg0 != 0) {
        if (arg0->idx < 4) {
            if (item_pro_create_fn_table[arg0->idx].fn != 0) {
                return item_pro_create_fn_table[arg0->idx].fn(arg0);
            }
        }
    }
    return 0;
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
                        v.y = lbl_805DAAB4;
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
