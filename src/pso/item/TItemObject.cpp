#include "pso/item/ItemCreateFunction.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/map/FloorArea.h"
#include "pso/item/TItemObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/item/TItemData.h"
#include "pso/system/task/TMainTask.h"

#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/item/TItem.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/render/render_util.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

extern "C" {
const char *TItemObject_name = "TItemObject";
}
void handle_6x66_use_star_atomizer(u8 *arg0);
extern const char *TItemObject_name;

LockOnTargetRecord *LockOnTargetRecordList::get_record(s32 index) { return &records[index]; }

u16 LockOnTargetRecord::get_entity_id() { return id; }

void G_UseStarAtomizer_6x66::init_header() {
    header.subcommand = 0x66;
    header.size = 3;
}

void G_UseStarAtomizer_6x66::send() {
    bswap();
    send_subcommand(this);
}

void G_UseStarAtomizer_6x66::bswap() {
    ((G_ClientIDHeader *)&header)->bswap();
    {
        int i;
        for (i = 0; i < 4; i++) {
            bswap_16((u16 *)&target_client_ids[i]);
        }
    }
}

s32 TItem::get_item_flags() { return this->item_flags; }

s32 TItemObject::get_amount() {
    return encoded_amount ^ (saddr)&encoded_amount;
}

TItemObject::~TItemObject() {}

TItem *TItemObject::create_tool(u8 *item) {
    if (item != NULL) {
        ItemCreateFunction factory = TLobby__sub_8010440C(item);
        return factory(item);
    }
    return NULL;
}

TItem *TItemObject::create(u8 *item) {
    if (item != NULL) {
        return new TItemObject(tl_05, item);
    }
    return NULL;
}

TItemObject::TItemObject(TObject *parent, u8 *item) : TItem(parent, item) {
    s16 type;

    m_name = TItemObject_name;
    pmt = (ItemToolPmt *)lookup_item_pmt_record(item);
    technique = item[4];
    set_amount(((TItemData *)item)->get_stack_count());
    if (pmt->flags & 1) {
        add_item_flags(ITEM_FLAG_CONSUMABLE);
    } else {
        clear_item_flags(ITEM_FLAG_CONSUMABLE);
    }
    type = pmt->type;
    if (type != 0) {
        set_drop_model(type + 4);
    }
}

void TItemObject::write_item_data(TItemData *data) {
    if (get_item_group() == 2) {
        data->data1.data_u8[4] = technique;
    }
    data->set_stack_count(get_amount());
}

void TItemObject::apply_use_effect() {
    TItem::use();
    skip_use_feedback = 1;
}

void TItemObject::use() {
    if (is_wrapped() != 0) {
        unwrap();
        return;
    }
    if (owner != NULL) {
        skip_use_feedback = 0;
        apply_use_effect();
        if (skip_use_feedback == 0) {
            apply_switch_attack(0x1AF);
            notify_owner(0x5B211);
        }
        if (get_item_flags() & ITEM_FLAG_CONSUMABLE) {
            consume_item_by_id(get_item_id());
        }
    }
}

s32 TItemObject::remove_amount(s32 count) {
    s32 amount = get_amount();
    if (count <= amount) {
        set_amount(amount - count);
        return 1;
    }
    return 0;
}

s32 TItemObject::add_amount(s32 count) {
    s32 amount = count + get_amount();
    if (amount <= get_max_stack_size()) {
        set_amount(amount);
        return 1;
    }
    return 0;
}

void *TItemObject::get_center() {
    if (owner != NULL) {
        return &owner->position;
    }
    return &position;
}

void send_star_atomizer_targets(TObjPlayer *player) {
    G_UseStarAtomizer_6x66 cmd;
    LockOnActionSlot *slot;
    s32 i;
    if (player != NULL && ((TObjPlayer *)player)->sub_801A1DDC() != 0 && player->lock_on_cursor != NULL) {
        slot = player->lock_on_cursor->find_by_pos(4, 0xA);
        if (slot != NULL) {
            cmd.init_header();
            cmd.target_client_ids[0] = player->get_entity_id();
            for (i = 0; i != 3; i++) {
                cmd.target_client_ids[i + 1] = slot->target_records.get_record(i)->get_entity_id();
            }
            cmd.send();
        }
    }
}

void send_nearby_player_ids(TObjPlayer *self, f32 range) {
    G_UseStarAtomizer_6x66 cmd;
    s32 j;
    u16 i;
    TObjPlayer *player;
    if (self != NULL && ((TObjPlayer *)self)->sub_801A1DDC() != 0) {
        cmd.init_header();
        j = 0;
        for (i = 0; i != 4; i++) {
            player = get_player_by_client_id(i);
            if (player != NULL) {
                if (horizontal_distance_squared(&self->position, &player->position) < range) {
                    cmd.target_client_ids[j++] = player->get_entity_id();
                } else {
                    cmd.target_client_ids[j++] = -1;
                }
            } else {
                cmd.target_client_ids[j++] = -1;
            }
        }
        cmd.send();
    }
}

void handle_6x66_use_star_atomizer(u8 *arg0) {
    G_UseStarAtomizer_6x66 *cmd = (G_UseStarAtomizer_6x66 *)arg0;
    TObjPlayer *user;
    s32 i;
    TObjPlayer *target;
    cmd->bswap();
    user = get_player_by_client_id(cmd->target_client_ids[0]);
    if (user != NULL) {
        i = 0;
        do {
            target = get_player_by_client_id(cmd->target_client_ids[i]);
            if (target != NULL && target->is_actor_dead() == 0) {
                if (user->get_floor() == target->get_floor()) {
                    target->set_hp_clamped(target->get_hpmax());
                    if (is_current_area_item_enabled() != 0) {
                        if (i == 0) {
                            spawn_particle_effect((const Vec *)((u8 *)target + 0x2FC), 0x19);
                        }
                        spawn_particle_effect((const Vec *)((u8 *)target + 0x2FC), 0xC2);
                    }
                }
            }
            i += 1;
        } while (i != 4);
    }
}

s32 get_tool_palette_index(TItem *item) {
    if (item != NULL) {
        u8 group = item->get_item_group();
        u8 index = item->get_item_index();
        switch (group) {
        case 0:
            switch (index) {
            case 0: return 0;
            case 1: return 1;
            case 2: return 2;
            }
            break;
        case 1:
            switch (index) {
            case 0: return 3;
            case 1: return 4;
            case 2: return 5;
            }
            break;
        case 6:
            switch (index) {
            case 0: return 6;
            case 1: return 7;
            }
            break;
        case 3: return 8;
        case 4: return 9;
        case 5: return 10;
        case 7: return 11;
        case 8: return 12;
        default: return -1;
        }
    }
    return -1;
}

void TItemObject::update_owned() {
    if (get_amount() > get_max_stack_size()) {
        refresh_if_current_player();
    }
}

u8 TItemObject::get_pmt_amount() {
    return pmt->amount;
}

u8 TItemObject::get_technique() { return technique; }

void TItemObject::set_amount(s32 amount) {
    encoded_amount = amount ^ (saddr)&encoded_amount;
}

void TItemObject::carry_over_stats(TItemData *, TItem *) {}
