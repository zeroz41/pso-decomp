#include "types.h"
#include "pso/object/warp/TObjWarpBossMulti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/TObjEndingPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/item/TItemData.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/player/TPlyItem.h"
#include "pso/weapon/WeaponSpecialSelection.h"
#include "pso/object/base/TObjBase.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {
u8 get_cast_technique_level(void *, int);
}
s32 get_game_play_mode();
extern "C" {

s32 is_trap_stock_empty(void *, s32);
s32 get_empty_action_entry(void *);
}
void TPlyDispConfigSmth::init() {
    s32 i;
    i = 0;
    bank = 0;
    do {
        m_tags[i].init();
        m_tags1[i].init();
        i++;
    } while (i < 4);
}
s32 TObjPlayer::is_palette_entry_displayable(u8 kind, u8 sub) {
    s32 tec;

    switch (kind) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        if (test_actor_flags(0x20006) != 0 || is_current_area_item_enabled() == 0 || get_camera_field() == 0) {
            return 0;
        }
        if ((u8)sub == 2) {
            TItem *weapon = get_equipped_weapon(this);
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
        if (technique_state.test_flag_2() != 0 || test_actor_flags(0x20006) != 0 || get_camera_field() == 0) {
            return 0;
        }
        if (tp - calc_technique_parameters(tec = sub, get_cast_technique_level(&technique_state, sub), get_entity_id())->tp_cost < 0) {
            return 0;
        }
        switch (tec) {
        case 0x11:
            if (get_game_play_mode() == 1) {
                return 0;
            }
            break;
        case 0xE:
            if (TObjWarpBossMulti::is_flag_clear(this) == 0) {
                return 0;
            }
            if (TTecCtrl::is_technique_ready() != 0 || get_game_play_mode() == 1) {
                return 0;
            }
            break;
        }
        return 1;
    case 4:
        if (get_camera_field() == 0) {
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
            if (TObjWarpBossMulti::is_flag_clear(this) == 0) {
                return 0;
            }
            if (TTecCtrl::is_technique_ready() != 0) {
                return 0;
            }
            break;
        }
        return 1;
    case 5:
        if (photon_blast_gauge.has_ready_flag() == 0 || test_actor_flags(0x20006) != 0 || get_camera_field() == 0) {
            return 0;
        }
        return 1;
    case 7:
        return 1;
    }
    return 0;
}
s32 TObjPlayer::can_use_palette_action(u8 kind, u8 arg) {
    TItemData item;
    TItem *w;
    switch (kind) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        if (arg == 2) {
            w = get_equipped_weapon(this);
            if (w != NULL) {
                if (weapon_has_extra_attack((TItemWeapon *)w) == 0) {
                    return 0;
                }
            } else {
                return 0;
            }
        }
        if (is_controls_locked() != 0) {
            return 1;
        }
        break;
    case 3:
        if (validate_and_clear_slot(&technique_state, arg) != 0) {
            return 0;
        }
        if (is_controls_locked() != 0) {
            return 1;
        }
        break;
    case 4:
        item.init();
        item.data1.data_u8[0] = 3;
        switch (arg) {
        case 0:
            item.data1.data_u8[1] = 0;
            item.data1.data_u8[2] = 0;
            break;
        case 1:
            item.data1.data_u8[1] = 0;
            item.data1.data_u8[2] = 1;
            break;
        case 2:
            item.data1.data_u8[1] = 0;
            item.data1.data_u8[2] = 2;
            break;
        case 3:
            if (is_android() != 0) {
                return 0;
            }
            item.data1.data_u8[1] = 1;
            item.data1.data_u8[2] = 0;
            break;
        case 4:
            if (is_android() != 0) {
                return 0;
            }
            item.data1.data_u8[1] = 1;
            item.data1.data_u8[2] = 1;
            break;
        case 5:
            if (is_android() != 0) {
                return 0;
            }
            item.data1.data_u8[1] = 1;
            item.data1.data_u8[2] = 2;
            break;
        case 6:
            if (is_android() != 0) {
                return 0;
            }
            item.data1.data_u8[1] = 6;
            item.data1.data_u8[2] = 0;
            break;
        case 7:
            if (is_android() != 0) {
                return 0;
            }
            item.data1.data_u8[1] = 6;
            item.data1.data_u8[2] = 1;
            break;
        case 8:
            item.data1.data_u8[1] = 3;
            break;
        case 9:
            item.data1.data_u8[1] = 4;
            break;
        case 10:
            item.data1.data_u8[1] = 5;
            break;
        case 11:
            item.data1.data_u8[1] = 7;
            break;
        case 12:
            if (is_android() != 0) {
                return 0;
            }
            item.data1.data_u8[1] = 8;
            break;
        }
        if (arg < 0xd || arg > 0x10) {
            if (inventory_objects->set_mode_and_refresh_object(&item) == 0) {
                return 0;
            }
        } else {
            if (is_boss_area() != 0) {
                return 0;
            }
            switch (arg) {
            case 0xd:
                if (is_trap_stock_empty(this, 0) != 0) {
                    return 0;
                }
                if (TWindowCtrl::is_client_countdown_done(get_entity_id()) == 0) {
                    return 0;
                }
                break;
            case 0xe:
                if (is_trap_stock_empty(this, 1) != 0) {
                    return 0;
                }
                if (TWindowCtrl::is_client_countdown_done(get_entity_id()) == 0) {
                    return 0;
                }
                break;
            case 0xf:
                if (is_trap_stock_empty(this, 2) != 0) {
                    return 0;
                }
                if (TWindowCtrl::is_client_countdown_done(get_entity_id()) == 0) {
                    return 0;
                }
                break;
            case 0x10:
                if (is_trap_stock_empty(this, 3) != 0) {
                    return 0;
                }
                if (TWindowCtrl::is_client_countdown_done(get_entity_id()) == 0) {
                    return 0;
                }
                break;
            }
        }
        if (is_controls_locked() != 0) {
            return 1;
        }
        break;
    case 5:
        if ((s8)photon_blast_gauge.get_blast_level(arg) == (s8)get_empty_action_entry(this)) {
            return 0;
        }
        break;
    case 7:
        return 1;
    }
    return is_palette_entry_displayable(kind, arg) ? 1 : 0;
}

struct Obj_801D8474 { s8 a; u8 b; };

extern "C" {

s32 TObjPlayer__sub_801D8664(s32, s16, s16);
s32 TObjPlayer__sub_801D84A8(void* p);
s32 TObjPlayer__sub_801D84F0(void* p);
int bswap_16__FPUs(void*);

s32 TObjPlayer::can_use_palette_action_for_entry(TObjPlayer *player) {
    return player->can_use_palette_action(((Obj_801D8474 *)this)->a, ((Obj_801D8474 *)this)->b);
}

s32 TObjPlayer__sub_801D84A8(void* p) { return *(s32*)((char*)p + 0x0); }

u8 *TObjPlayer__sub_801D84B0(s32 *cursor_sets);

u8 *TObjPlayer__sub_801D84B0(s32 *cursor_sets) {
    if ((s32) *(s32 *)((s8 *)cursor_sets + 0) == 0) {
        return (u8 *)cursor_sets + 4;
    }
    return (u8 *)cursor_sets + 0x14;
}

u32 advance_item_id_counter(u16 client);

int TObjPlayer::bswap_disp_config_field() { return bswap_16__FPUs((char*)this + 0x2); }
s32 TObjPlayer__sub_801D84F0(void* p) { return *(s32*)((char*)p + 0x4); }
void TObjPlayer::set_animation_from_data(saddr player, s32 picture) {
    void *anim_table_entry;

    anim_table_entry = (void *)((TObjPlayer *)player)->get_anim_table_entry(picture);
    TObjPlayer__sub_801D8664(player, *(s16 *)((s8 *)anim_table_entry + 0), *(s16 *)((s8 *)anim_table_entry + 2));
    ((TObjEndingPlayer *)player)->set_animation_default(picture);
}

void TObjPlayer::assign_lobby_slot_if_flagged(saddr player, void *records) {
    if (*(s32 *)((s8 *)records + 4) & 8) {
        *(s32 *)((s8 *)records + 0x14) = advance_item_id_counter((u16)local_client_id);
        equip_saved_item_if_slot_empty(reinterpret_cast<TObjPlayer *>(player), static_cast<TPlyInventoryItem *>(records));
    }
}

}
