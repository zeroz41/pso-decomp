// Built -inline off,deferred: the functions are written from the last back.
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/misc/TOSwitchItem.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/protocol/protocol_types.h"
#include "pso/system/NinjaTypes.h"

extern void *tl_05;

const char *TOSwitchItem__class_name = "TOSwitchItem";

s32 TItem::is_unit() {
    u8 result = 0;
    if (item_type == 1 && item_group == 3) {
        result = 1;
    }
    return result;
}

TOSwitchItem::TOSwitchItem(TObject *parent, void *set_data) : TOKey(parent) {
    m_name = TOSwitchItem__class_name;
    apply_object_set_data(set_data);
    init_params();
    items_present = 0;
}

TOSwitchItem::~TOSwitchItem() {}

void TOSwitchItem::load_assets() {}

void TOSwitchItem::free_assets() {}

void *TOSwitchItem::create(void *set_data) {
    return new TOSwitchItem((TObject *)tl_05, set_data);
}

void TOSwitchItem::run_task() {
    s32 count;
    s32 n;
    s32 i;
    TItem *item;

    update_armed_switch();
    count = 0;
    n = get_item_registry_count();
    for (i = 0; i != n; i++) {
        item = get_sorted_item_registry_entry(i);
        if (item->get_mode() == 0 && horizontal_distance_squared(&item->position, &position) < range_sq) {
            switch (item_filter) {
            case SWITCH_ITEM_ANY:
                count++;
                break;
            case SWITCH_ITEM_WEAPON:
                if (item->get_item_type() == 0) {
                    count++;
                }
                break;
            case SWITCH_ITEM_ARMOR:
                if (item->get_item_type() == 1 && item->get_item_group() == 1) {
                    count++;
                }
                break;
            case SWITCH_ITEM_SHIELD:
                if (item->get_item_type() == 1 && item->get_item_group() == 2) {
                    count++;
                }
                break;
            case SWITCH_ITEM_UNIT:
                if (item->is_unit() == 1) {
                    count++;
                }
                break;
            case SWITCH_ITEM_MAG:
                if (item->get_item_type() == 2) {
                    count++;
                }
                break;
            case SWITCH_ITEM_TOOL:
                if (item->get_item_type() == 3) {
                    count += item->get_amount();
                }
                break;
            case SWITCH_ITEM_MESETA:
                if (item->get_item_type() == 4) {
                    count += item->calc_price();
                }
                break;
            }
        }
    }
    if (required_count <= count) {
        if (items_present == 0) {
            items_present = 1;
            send_switch_on();
        }
    } else if (items_present != 0) {
        items_present = 0;
        send_switch_on();
    }
}

void TOSwitchItem::debug_draw_key_id() {}

void TOSwitchItem::render() {
    if (TObjPlayer::check_demo_mode() == 1) {
        NJS_ARGB color;
        color.a = 0.3f;
        color.r = 0.3f;
        color.g = 0.3f;
        color.b = 0.0f;
        debug_draw_sphere(&position, &color, newton_sqrtf(range_sq));
    }
}

void TOSwitchItem::init_params() {
    init_switch_id();
    range_sq = scale.x * scale.x;
    item_filter = set_params[1];
    if (item_filter >= 8) {
        item_filter = SWITCH_ITEM_ANY;
    }
    required_count = set_params[2] + 1;
}

void TOSwitchItem::send_switch_on() {
    G_SwitchStateChanged_6x05 cmd;
    cmd.init();
    cmd.header.client_id = get_entity_id(this);
    cmd.unused1 = 0;
    cmd.switch_id = switch_id;
    cmd.floor = get_current_floor();
    cmd.flags = items_present != 0;
    cmd.send();
}
