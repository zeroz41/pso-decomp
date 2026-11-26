#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/HelpItemRarityStarRow.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/unk/TWindowStatusGaugeFeedback.h"
#include "pso/ui/window/TWindowSubStatusDisp_8026F6DC.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowComCard.h"
#include "pso/ui/window/TWindowBase.h"
#include <stddef.h>
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/system/task/TObject.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/TObjLuker_801329B0.h"


#pragma readonly_strings on
#pragma defer_codegen on


const char *TWindowLockOn__name = "TWindowLockOn";

LockOnPlayerLayout lock_on_window_params = {
    2, 1,
    {6, {10.0f, 0.0f}, {34.0f, 29.0f}, 34.0f, 202.0f, 0.5f, -1, &hud_texlist, 0, 4},
    {3, {44.0f, 5.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
};

LockOnItemLayout lockon_window_layout_entries = {
    2, 1,
    {8},
    {10, {10.0f, 20.0f}},
};

LockOnEnemyLayout lock_on_window_layout_entries = {
    9, 1,
    {3, {10.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {10.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {10.0f, 20.0f}, 0.7f, 0xFFFFFFFF, 0, NULL},
    {6, {10.0f, 44.0f}, {32.0f, 28.0f}, 0.0f, 0.0f, 0.1f, -1, &hud_texlist, 1, 6},
    {6, {26.0f, 44.0f}, {32.0f, 28.0f}, 0.0f, 0.0f, 0.2f, -1, &hud_texlist, 1, 6},
    {6, {42.0f, 44.0f}, {32.0f, 28.0f}, 0.0f, 0.0f, 0.3f, -1, &hud_texlist, 1, 6},
    {6, {58.0f, 44.0f}, {32.0f, 28.0f}, 0.0f, 0.0f, 0.4f, -1, &hud_texlist, 1, 6},
    {{2, {10.0f, 50.0f}, 0.5f, 0xFF00FF15, 0x2A, 100.0f, 0, 0}, 0xFF00CA9E, 0xFFFF2924},
    {{2, {10.0f, 62.0f}, 0.5f, 0xFF008CFC, 0x2A, 100.0f, 0, 0}, 0xFF008DEE, 0xFFFF2924},
};

WindowDescriptor lock_on_window_descriptor = {
    {0.0f, 0.0f}, 50000.0f, NULL, 0x23,
};

extern "C" {
s32 is_split_screen(void);
}
s32 get_status_effect_icon_index(u32);

TWindowLockOn::TWindowLockOn(s32 player, u16 id) : TWindowBase((u8 *)&lock_on_window_descriptor, player, (u8 *)get_window_layout_position(0x1E)) {
    this->m_name = TWindowLockOn__name;
    if (TCameraCtrl::get_camera_id() > 2) {
        this->scale = 0.7f;
        this->height_scale = 0.7f;
    } else {
        this->scale = 1.0f;
        this->height_scale = 1.0f;
    }
    this->target_id = 0xFFFF;
    this->client_index = player;
    this->frames_left = 0;
    this->refresh = NULL;
    this->bind_target(id);
    this->tween_ticks = 0;
}

TWindowLockOn::~TWindowLockOn() {}

void TWindowLockOn::run_task() {
    s32 old;
    open_tick = 0x01000000;
    if (refresh) {
        (this->*refresh)();
    }
    validate_target();
    update_window();
    update_fade();
    update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(&entry_list));
    old = frames_left;
    frames_left = old - 1;
    if (old < 0) {
        close();
    }
}

void TWindowLockOn::render() {
    WindowDrawContext *context;

    context = setup_window_draw_context((f32 *)&scale);
    draw_window_frame(context);
    if (target_position[0] == frame_position[0] && target_position[1] == frame_position[1] && target_size[0] == frame_size[0] && target_size[1] == frame_size[1]) {
        draw_visible_window_entries(
            this,
            reinterpret_cast<const WindowLayoutEntries *>(&entry_list),
            context);
    }
}

TWindowLockOn *TWindowLockOn::create_for_target(s32 player, u16 id) {
    TWindowLockOn *p;
    if (id == 0xFFFF) {
        return NULL;
    }
    if (is_lockable_target(find_entity_by_id(id)) == 0) {
        return NULL;
    }
    p = new TWindowLockOn(player, id);
    return p;
}

void TWindowLockOn::bind_target(u16 id) {
    TObjCollidable *actor;

    if (id == 0xFFFF) {
        queue_destruction();
        return;
    }
    actor = find_entity_by_id(id);
    if (is_lockable_target(actor) == 0) {
        return;
    }
    if (target_id == id) {
        frames_left = 0x5A;
        return;
    }
    if ((f32)frames_left > 90.0f) {
        return;
    }
    target_id = id;
    frames_left = 0x5A;
    update_for_target(actor);
    if (refresh) {
        (this->*refresh)();
    }
}

void TWindowLockOn::update_for_target(TObjCollidable *actor) {
    reinterpret_cast<WindowLayoutEntries *>(&entry_list)->destroy_all_items();
    if (actor->test_actor_flags(0x10000000) != 0) {
        update_for_other_player(actor);
        return;
    }
    if (actor->test_actor_flags(0x80000000) != 0) {
        update_for_item((TItem *)actor);
        return;
    }
    if (actor->test_actor_flags(0x20000000) != 0) {
        update_for_enemy((TObjChara *)actor);
    }
}

#pragma push
#pragma fp_contract on
void TWindowLockOn::update_for_other_player(TObjCollidable *player) {
    WindowTextEntry *name;
    u16 id;
    init_window_layout_entries(reinterpret_cast<WindowLayoutEntries *>(&entry_list), &lock_on_window_params, client_index);
    refresh = &TWindowLockOn::update_photon_blast_marker;
    name = (WindowTextEntry *)get_array_entry(1);
    id = player->get_entity_id();
    name->show_player_name(id);
    name->reveal_all();
    measure_message_text_width_default(name);
    target_size[0] = 34.0f + name->width;
    target_size[1] = 49.0f;
    target_size[0] += 28.0f;
    target_position[1] = get_window_layout_y(0x1E) - target_size[1] * height_scale;
    tween_ticks = 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowLockOn::update_for_item(TItem *item) {
    ItemListRow *e;
    HelpItemRarityStarRow *e2;
    f32 r;
    init_window_layout_entries(reinterpret_cast<WindowLayoutEntries *>(&entry_list), &lockon_window_layout_entries, client_index);
    refresh = &TWindowLockOn::refresh_ground_item;
    e = (ItemListRow *)get_array_entry(0);
    e->init_item_row(item, 0);
    e->calc_row_width();
    e->x = -8.0f;
    if (e->status_icon != 0x33) {
        e->x += 18.0f;
    }
    target_size[0] = e->width;
    target_size[1] = 38.0f;
    e2 = (HelpItemRarityStarRow *)get_array_entry(1);
    if (item->get_item_type() == 0 || item->get_item_type() == 1) {
        e2->stars = (u8)item->calc_display_grade();
        target_size[1] += 20.0f;
        e2->flags &= ~2;
        r = e2->get_item_star_row_width();
        if (target_size[0] < r) {
            target_size[0] = r;
        }
    } else {
        e2->flags |= 2;
    }
    target_size[0] += 28.0f;
    target_position[1] = get_window_layout_y(0x1E) - target_size[1] * height_scale;
    tween_ticks = 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_propagation off
void TWindowLockOn::update_for_enemy(TObjChara *enemy) {
    static const char *type_names[5] = {"Native", "A.Beast", "Machine", "Dark", "\tCG???"};
    static u32 type_colors[5] = {0xFFA5FFAA, 0xFFF5FF99, 0xFFFF958B, 0xFFE1A9FF, 0xFFFFFFFF};
    u32 width;
    WindowTextEntry *e;
    s32 kind;
    TWindowStatusGaugeFeedback *p;
    u32 w2;

    init_window_layout_entries(reinterpret_cast<WindowLayoutEntries *>(&entry_list), &lock_on_window_layout_entries, client_index);
    refresh = &TWindowLockOn::refresh_enemy_statuses;
    e = (WindowTextEntry *)get_array_entry(1);
    TWindowDuelResult::set_default_status(e, (saddr)TWindowSubStatusDisp::get_message_10(0xA5));
    e->reveal_all();
    width = calc_text_width(e->get_text());
    e = (WindowTextEntry *)get_array_entry(0);
    TWindowDuelResult::set_default_status(e, enemy_name_for_rt_index(((TObjEnemy *)enemy)->get_rt_index()));
    e->reveal_all();
    target_size[0] = (f32)calc_text_width(e->get_text());
    target_size[1] = 64.0f;
    if (is_split_screen() == 0) {
        target_size[1] += 29.0f;
    }
    if (enemy->obj_testFlag_2E4(0x40) != 0) {
        kind = 4;
    } else if (enemy->obj_testFlag_2E4(1) != 0) {
        kind = 0;
    } else if (enemy->obj_testFlag_2E4(2) != 0) {
        kind = 1;
    } else if (enemy->obj_testFlag_2E4(4) != 0) {
        kind = 2;
    } else if (enemy->obj_testFlag_2E4(8) != 0) {
        kind = 3;
    } else {
        kind = 4;
    }
    e = (WindowTextEntry *)get_array_entry(2);
    TWindowDuelResult::set_default_status(e, (saddr)type_names[kind]);
    e->reveal_all();
    e->x = 10.0f + (f32)width;
    e->color = type_colors[kind];
    w2 = calc_text_width(e->get_text());
    w2 += width;
    if ((f32)w2 > target_size[0]) {
        target_size[0] = (f32)w2;
    }
    target_size[0] += 28.0f;
    target_position[1] = get_window_layout_y(0x1E) - target_size[1] * height_scale;
    tween_ticks = 0;
    p = (TWindowStatusGaugeFeedback *)get_array_entry(7);
    p->scale = target_size[0] - 28.0f;
    p->maximum = (f32)enemy->get_hpmax();
    p->target = (f32)enemy->hp;
    p = (TWindowStatusGaugeFeedback *)get_array_entry(8);
    p->scale = target_size[0] - 28.0f;
    p->maximum = (f32)enemy->get_tpmax();
    p->target = (f32)enemy->tp;
}
#pragma pop

void TWindowLockOn::update_photon_blast_marker() {
    update_photon_blast_player_marker(reinterpret_cast<saddr>(get_array_entry(0)), target_id);
}

void TWindowLockOn::refresh_ground_item() {}

void TWindowLockOn::refresh_enemy_statuses() {
    s32 i;
    TObjChara *enemy;
    s32 mode;
    TWindowStatusGaugeFeedback *g;
    if (target_id == 0xFFFF) {
        return;
    }
    enemy = (TObjChara *)find_entity_by_id(target_id);
    if (enemy == NULL) {
        return;
    }
    i = 0;
    do {
        mode = get_status_effect_icon_index(enemy->get_status_effect_type(i));
        ((TWindowComCard *)get_array_entry(i + 3))->set_help_mode(mode);
        i++;
    } while (i < 4);
    {
        g = (TWindowStatusGaugeFeedback *)get_array_entry(7);
        g->maximum = enemy->get_hpmax();
        g->target = enemy->hp;
        g->hide();
    }
    {
        g = (TWindowStatusGaugeFeedback *)get_array_entry(8);
        g->maximum = enemy->get_tpmax();
        g->target = enemy->tp;
        g->hide();
    }
}

s32 TWindowLockOn::is_lockable_target(TObjCollidable *actor) {
    if (actor == NULL) {
        return 0;
    }
    if (actor->test_actor_flags(0x10000000) != 0) {
        if (((TObjChara *)actor)->obj_isState3_324() != 0 || ((TObjPlayer *)actor)->is_script_controlled() != 0) {
            return 0;
        }
        return 1;
    }
    if (actor->test_actor_flags(0x20000000) != 0) {
        if (actor->test_actor_flags(0x40000000) != 0) {
            return 0;
        }
        if (((TObjEnemy *)actor)->get_rt_index() != 0) {
            return 1;
        }
        return 0;
    }
    if (actor->test_actor_flags(0x80000000) != 0) {
        return 1;
    }
    return 0;
}

void TWindowLockOn::validate_target() {
    u16 id;
    TObjCollidable *target;
    id = target_id;
    if (id != 0xFFFF) {
        target = find_entity_by_id(id);
        if (target == NULL || target->all_parents_unqueued_for_destruction() == 0) {
            target_id = 0xFFFF;
            if ((f32)frames_left > 15.0f) {
                frames_left = 0xF;
            }
        } else if (target->test_actor_flags(0x10000000) == 0) {
            if (target->test_actor_flags(0x20000000) != 0) {
                if (((TObjChara *)target)->is_actor_dead() != 0) {
                    target_id = 0xFFFF;
                    if ((f32)frames_left > 15.0f) {
                        frames_left = 0xF;
                    }
                }
            } else if (target->test_actor_flags(0x80000000) != 0 && ((TItem *)target)->get_mode() != 0) {
                target_id = 0xFFFF;
                if ((f32)frames_left > 15.0f) {
                    frames_left = 0xF;
                }
            }
        }
    }
}
