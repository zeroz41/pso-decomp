#include "types.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/TUnk_804C4540.h"
#include "pso/map/FloorArea.h"
#include "pso/item/TItemData.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/player/TPlyItem.h"
#include "pso/weapon/WeaponSpecialSelection.h"
#include "pso/object/base/TObjBase.h"

struct Tec_801D7DA4 { u8 pad[0x10]; s16 cost; };

struct TItemData_801D8044 { u8 kind; u8 type; u8 sub; u8 pad[0x11]; };

struct TObjPlayer_801D8044 {
    u8 pad0[0x428];
    u8 slots[0x4ac - 0x428];
    u8 cursor[0xd00 - 0x4ac];
    void *fd00;
};

extern "C" {
u8 get_cast_technique_level(void *, int);
Tec_801D7DA4 *calc_technique_parameters(s32, s32, u16);
s32 get_game_play_mode();

s32 TObjPlayer__sub_801AF694(void *, s32);
s32 TWindowCtrl__sub_8024A228(saddr);
s32 TMainCursor__sub_8013F244(void *);
s32 fn_8013F24C(void *, s32);
s32 is_palette_entry_displayable__10TObjPlayerFv(u8 *, u8, u8);
bool can_use_palette_action__10TObjPlayerFPvUcUc(TObjPlayer_801D8044 *self, u8 kind, u8 arg);
// Works on a TPlyDispConfigSmth (its layout, and it sits right after
// TPlyDispConfigSmth::bswap at 0x801D7CF4); owner inferred, not yet moved.
void TObjPlayer::init_action_config() {
    TPlyDispConfigSmth *smth = (TPlyDispConfigSmth *)this;
    s32 i;
    i = 0;
    smth->m_mbr_0x0 = 0;
    do {
        smth->m_tags[i].init();
        smth->m_tags1[i].init();
        i++;
    } while (i < 4);
}
s32 is_palette_entry_displayable__10TObjPlayerFv(u8 *player, u8 kind, u8 sub) {
    s32 tec;

    switch (kind) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        if (((TObjCollidable *)player)->test_actor_flags(0x20006) != 0 || is_current_area_item_enabled() == 0 || ((TObjPlayer *)player)->get_camera_field() == 0) {
            return 0;
        }
        if ((u8)sub == 2) {
            TItem *weapon = TObjPlayer::get_equipped_weapon(player);
            if (weapon != NULL) {
                if (weapon_has_extra_attack((TItemWeapon *)weapon) == 0) {
                    return 0;
                }
            } else {
                return 0;
            }
        }
        return 1;
    case 3:
        if (((TObjPlayer *)(player + 0x428))->test_bit1_at_10() != 0 || ((TObjCollidable *)player)->test_actor_flags(0x20006) != 0 || ((TObjPlayer *)player)->get_camera_field() == 0) {
            return 0;
        }
        if (*(s16 *)(player + 0x32E) - calc_technique_parameters(tec = sub, get_cast_technique_level(player + 0x428, sub), ((TObjBase *)(player))->get_entity_id())->cost < 0) {
            return 0;
        }
        switch (tec) {
        case 0x11:
            if (get_game_play_mode() == 1) {
                return 0;
            }
            break;
        case 0xE:
            if (TObjWarpBossMulti::is_flag_clear(player) == 0) {
                return 0;
            }
            if (TTecCtrl::is_technique_ready() != 0 || get_game_play_mode() == 1) {
                return 0;
            }
            break;
        }
        return 1;
    case 4:
        if (((TObjPlayer *)player)->get_camera_field() == 0) {
            return 0;
        }
        switch ((u8)sub) {
        case 9:
            if (get_game_play_mode() == 1) {
                return 0;
            }
            break;
        case 10:
            break;
        case 11:
            if (TObjWarpBossMulti::is_flag_clear(player) == 0) {
                return 0;
            }
            if (TTecCtrl::is_technique_ready() != 0) {
                return 0;
            }
            break;
        }
        return 1;
    case 5:
        if (((TObjPlayer *)player)->photon_blast_gauge.has_ready_flag() == 0 || ((TObjCollidable *)player)->test_actor_flags(0x20006) != 0 || ((TObjPlayer *)player)->get_camera_field() == 0) {
            return 0;
        }
        return 1;
    case 7:
        return 1;
    }
    return 0;
}
bool can_use_palette_action__10TObjPlayerFPvUcUc(TObjPlayer_801D8044 *self, u8 kind, u8 arg) {
    TItemData_801D8044 item;
    TItem *w;
    switch (kind) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        if (arg == 2) {
            w = TObjPlayer::get_equipped_weapon(self);
            if (w != NULL) {
                if (weapon_has_extra_attack((TItemWeapon *)w) == 0) {
                    return 0;
                }
            } else {
                return 0;
            }
        }
        if (((TObjPlayer *)self)->is_controls_locked() != 0) {
            return 1;
        }
        break;
    case 3:
        if (TObjPlayer::validate_and_clear_slot(self->slots, arg) != 0) {
            return 0;
        }
        if (((TObjPlayer *)self)->is_controls_locked() != 0) {
            return 1;
        }
        break;
    case 4:
        ((TItemData *)(&item))->init();
        item.kind = 3;
        switch (arg) {
        case 0:
            item.type = 0;
            item.sub = 0;
            break;
        case 1:
            item.type = 0;
            item.sub = 1;
            break;
        case 2:
            item.type = 0;
            item.sub = 2;
            break;
        case 3:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 1;
            item.sub = 0;
            break;
        case 4:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 1;
            item.sub = 1;
            break;
        case 5:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 1;
            item.sub = 2;
            break;
        case 6:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 6;
            item.sub = 0;
            break;
        case 7:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 6;
            item.sub = 1;
            break;
        case 8:
            item.type = 3;
            break;
        case 9:
            item.type = 4;
            break;
        case 10:
            item.type = 5;
            break;
        case 11:
            item.type = 7;
            break;
        case 12:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 8;
            break;
        }
        if (arg < 0xd || arg > 0x10) {
            if (((TPlyItem *)((void *)self->fd00))->set_mode_and_refresh_object(&item) == 0) {
                return 0;
            }
        } else {
            if (is_boss_area() != 0) {
                return 0;
            }
            switch (arg) {
            case 0xd:
                if (TObjPlayer__sub_801AF694(self, 0) != 0) {
                    return 0;
                }
                if (TWindowCtrl__sub_8024A228(((TObjBase *)(self))->get_entity_id()) == 0) {
                    return 0;
                }
                break;
            case 0xe:
                if (TObjPlayer__sub_801AF694(self, 1) != 0) {
                    return 0;
                }
                if (TWindowCtrl__sub_8024A228(((TObjBase *)(self))->get_entity_id()) == 0) {
                    return 0;
                }
                break;
            case 0xf:
                if (TObjPlayer__sub_801AF694(self, 2) != 0) {
                    return 0;
                }
                if (TWindowCtrl__sub_8024A228(((TObjBase *)(self))->get_entity_id()) == 0) {
                    return 0;
                }
                break;
            case 0x10:
                if (TObjPlayer__sub_801AF694(self, 3) != 0) {
                    return 0;
                }
                if (TWindowCtrl__sub_8024A228(((TObjBase *)(self))->get_entity_id()) == 0) {
                    return 0;
                }
                break;
            }
        }
        if (((TObjPlayer *)self)->is_controls_locked() != 0) {
            return 1;
        }
        break;
    case 5:
        if ((s8)fn_8013F24C(self->cursor, arg) == (s8)TMainCursor__sub_8013F244(self)) {
            return 0;
        }
        break;
    case 7:
        return 1;
    }
    return is_palette_entry_displayable__10TObjPlayerFv((u8 *)self, kind, arg) != 0;
}

}

struct Obj_801D8474 { s8 a; u8 b; };

extern "C" {

s32 TObjPlayer__sub_801D8664(s32, s16, s16);
s32 TObjPlayer__sub_801D84A8(void* p);
s32 TObjPlayer__sub_801D84F0(void* p);
int bswap_16__FPUs(void*);

s32 TObjPlayer::can_use_palette_action_for_entry(u32 obj) {
    return ((s32 (*)(u32, u8, u8))can_use_palette_action__10TObjPlayerFPvUcUc)(obj, ((Obj_801D8474 *)this)->a, ((Obj_801D8474 *)this)->b);
}

s32 TObjPlayer__sub_801D84A8(void* p) { return *(s32*)((char*)p + 0x0); }

u8 *TObjPlayer__sub_801D84B0(s32 *arg0);

u8 *TObjPlayer__sub_801D84B0(s32 *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0) == 0) {
        return (u8 *)arg0 + 4;
    }
    return (u8 *)arg0 + 0x14;
}

u32 advance_item_id_counter(u16 client);

int TObjPlayer::bswap_disp_config_field() { return bswap_16__FPUs((char*)this + 0x2); }
s32 TObjPlayer__sub_801D84F0(void* p) { return *(s32*)((char*)p + 0x4); }
void TObjPlayer::set_animation_from_data(saddr arg0, s32 picture) {
    void *anim_table_entry;

    anim_table_entry = (void *)((TObjPlayer *)arg0)->get_anim_table_entry(picture);
    TObjPlayer__sub_801D8664(arg0, *(s16 *)((s8 *)anim_table_entry + 0), *(s16 *)((s8 *)anim_table_entry + 2));
    ((TUnk_804C4540 *)arg0)->set_animation_default(picture);
}

extern s32 local_client_id;

void TObjPlayer::assign_lobby_slot_if_flagged(saddr player, void *records) {
    if (*(s32 *)((s8 *)records + 4) & 8) {
        *(s32 *)((s8 *)records + 0x14) = advance_item_id_counter((u16)local_client_id);
        equip_saved_item_if_slot_empty(reinterpret_cast<TObjPlayer *>(player), static_cast<TPlyInventoryItem *>(records));
    }
}

}
