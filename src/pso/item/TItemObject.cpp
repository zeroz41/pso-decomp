#include "pso/map/CurrentArea.h"
#include "pso/item/TItemObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TItemData.h"
#include "pso/TMainTask.h"

#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TMainCursor.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/protocol/subcmd_6x.h"
extern "C" {
s16 get_entity_id(TObjPlayer *);
f32 horizontal_distance_squared(void *, void *);
s32 sub_801A1DDC__10TObjPlayerFv(void *);
void *get_player_by_client_id(s32 i);
void send_nearby_player_ids(TObjPlayer *self, f32 range);
void *spawn_particle_effect(void *pos, s32 id);
void *TObjPlayer__sub_80116620(void *, s32);
void send_star_atomizer_targets(TObjPlayer *player);
}
void handle_6x66_use_star_atomizer(u8 *arg0);

extern "C" {
void *lookup_item_pmt_record(u8 *item);
// The factory that builds the tool an item code names.
TItem *(*TLobby__sub_8010440C(u8 *item))(u8 *item);
}

extern const char *TItemObject_name;

s32 TItemObject::get_amount() {
    return encoded_amount ^ (s32)&encoded_amount;
}

TItemObject::~TItemObject() {}

TItem *TItemObject::create_tool(u8 *item) {
    if (item != NULL) {
        TItem *(*factory)(u8 *) = TLobby__sub_8010440C(item);
        return factory(item);
    }
    return NULL;
}

TItemObject *TItemObject::create(u8 *item) {
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
    s32 cursor;
    s32 i;
    if (player != NULL && sub_801A1DDC__10TObjPlayerFv(player) != 0 && (TMainCursor *)player->m_424 != NULL) {
        cursor = ((TMainCursor *)player->m_424)->find_by_pos(4, 0xA);
        if (cursor != 0) {
            ((TObjPlayer *)&cmd)->set_type_bytes();
            cmd.target_client_ids[0] = get_entity_id(player);
            for (i = 0; i != 3; i++) {
                cmd.target_client_ids[i + 1] = ((TObjPlayer *)TObjPlayer__sub_80116620((void *)(cursor + 0x9C), i))->get_type_id();
            }
            ((TObjPlayer *)&cmd)->bswap_and_send_item();
        }
    }
}

void send_nearby_player_ids(TObjPlayer *self, f32 range) {
    G_UseStarAtomizer_6x66 cmd;
    s32 j;
    u16 i;
    TObjPlayer *player;
    if (self != NULL && sub_801A1DDC__10TObjPlayerFv(self) != 0) {
        ((TObjPlayer *)&cmd)->set_type_bytes();
        j = 0;
        for (i = 0; i != 4; i++) {
            player = (TObjPlayer *)get_player_by_client_id(i);
            if (player != NULL) {
                if (horizontal_distance_squared(&self->position, &player->position) < range) {
                    cmd.target_client_ids[j++] = get_entity_id(player);
                } else {
                    cmd.target_client_ids[j++] = -1;
                }
            } else {
                cmd.target_client_ids[j++] = -1;
            }
        }
        ((TObjPlayer *)&cmd)->bswap_and_send_item();
    }
}

void handle_6x66_use_star_atomizer(u8 *arg0) {
    G_UseStarAtomizer_6x66 *cmd = (G_UseStarAtomizer_6x66 *)arg0;
    TObjPlayer *user;
    s32 i;
    TObjPlayer *target;
    ((TObjPlayer *)cmd)->bswap_fields_x4();
    user = (TObjPlayer *)get_player_by_client_id(cmd->target_client_ids[0]);
    if (user != NULL) {
        i = 0;
        do {
            target = (TObjPlayer *)get_player_by_client_id(cmd->target_client_ids[i]);
            if (target != NULL && target->has_flag_0x800() == 0) {
                if (user->get_field_3e4() == target->get_field_3e4()) {
                    target->set_hp_clamped(((TItemProShield *)target)->get_field_2b8());
                    if (are_items_enabled_here() != 0) {
                        if (i == 0) {
                            spawn_particle_effect((u8 *)target + 0x2FC, 0x19);
                        }
                        spawn_particle_effect((u8 *)target + 0x2FC, 0xC2);
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
    encoded_amount = amount ^ (s32)&encoded_amount;
}

void TItemObject::carry_over_stats(TItemData *, TItem *) {}
