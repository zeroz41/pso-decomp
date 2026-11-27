#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/switch/TSwitch.h"
#include "types.h"
#include "pso/object/collision/TObjRaderCol.h"
#include "pso/object/collision/TObjRaderHideCol.h"
#include "pso/ui/hud/TObjRaderIcon.h"
#include "pso/render/NinjaUtil.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerCommands.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/hud/SplitScreenQuery.h"

#pragma readonly_strings on


extern "C" {
const char *rader_col_name = "TObjRaderCol";
const char *rader_hide_col_name = "TObjRaderHideCol";
const char *rader_icon_name = "TObjRaderIcon";

}


// Deferred TU: code is generated last-defined-first, so the functions are written in
// reverse address order (vtables and .text then come out in the original order).
#pragma defer_codegen on

TObjRaderCol::~TObjRaderCol() {

}

TObjRaderCol::TObjRaderCol(TObject *parent, ObjectSetData *set_data) : TObjBase(parent) {
    m_name = rader_col_name;
    apply_object_set_data(set_data);
    radius = scale.x;
    id = (s32) set_params[0];
    state = 0;
    delay = 3;
    disallow_rendering();
}

void TObjRaderCol::run_task() {

    switch (this->state) {
    case 0:
        TRaderMapCore::block_region_by_id((s16) this->id);
        this->state = 1;
        return;
    case 1:
        if (is_not_split_screen() == 1) {
            check_any_player_in_range();
            return;
        }
        check_local_player_in_range();
        return;
    }
}

void TObjRaderCol::check_local_player_in_range() {
    TObjPlayer *p = get_player_by_client_id(local_client_id);
    if (p != 0) {
        if (p->is_body_collision_inactive() != 0) {
            return;
        }
    } else {
        return;
    }
    s32 t = delay;
    if (t > 0) {
        delay = t - 1;
        return;
    }
    if (p != 0) {
        if (xz_distance_squared(&p->position, &position) < radius * radius) {
            TRaderMapCore::reveal_region_by_id((s16)id);
            queue_destruction();
        }
    }
}


void TObjRaderCol::check_any_player_in_range() {
    s32 found;
    s32 i;
    s32 j;
    TObjPlayer *p;
    found = 0;
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != 0 && p->is_body_collision_inactive() != 0) {
            found = 1;
        }
    }
    if (found == 0) {
        if (delay > 0) {
            delay--;
        } else {
            for (j = 0; j < 4; j++) {
                p = get_player_by_client_id(j);
                if (p != 0 && xz_distance_squared(&p->position, &position) < radius * radius) {
                    TRaderMapCore::reveal_region_by_id(id);
                    queue_destruction();
                    return;
                }
            }
        }
    }
}

void TObjRaderCol::render() {  }

TObjRaderHideCol::TObjRaderHideCol(TObject *parent, ObjectSetData *set_data) : TObjBase(parent) {
    m_name = rader_hide_col_name;
    apply_object_set_data(set_data);
    hide_radius = scale.x;
    radar_hidden = 0;
    disallow_rendering();
}

TObjRaderHideCol::~TObjRaderHideCol() {

}

void TObjRaderHideCol::run_task() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        if (xyz_distance_squared(&position, &player->position) < hide_radius * hide_radius) {
            if (!(radar_hidden & 1)) {
                TRaderMapCore::hide_radar();
                radar_hidden = 1;
            }
        } else if (radar_hidden & 1) {
            TRaderMapCore::show_radar();
            radar_hidden = 0;
        }
    }
}

void TObjRaderHideCol::render() {  }


TObjRaderIcon::TObjRaderIcon(TObject *parent, ObjectSetData *set_data) : TObjBase(parent) {
    m_name = rader_icon_name;
    apply_object_set_data(set_data);
    initialize_from_placement();
    disallow_rendering();
}

TObjRaderIcon::~TObjRaderIcon() {

}

void TObjRaderIcon::initialize_from_placement() {
    color_mode = 0;
    switch_count = 1;
    first_switch = 0;
    size = 1.0f;
    color = 0;
    color_mode = (s32) this->set_params[0];
    if (color_mode < 0) {
        color_mode = 0;
    }
    if (color_mode > 1) {
        color_mode = 1;
    }
    size = (f32) this->scale.x;
    if (size < 0.0f) {
        size = 0.0f;
    }
    color = (s32) this->set_params[2];
    switch_count = (s32) (u16) ((s32) this->set_params[1] >> 0x10);
    first_switch = (s32) (u16) this->set_params[1];
    if (switch_count < 0) {
        switch_count = 0;
    }
    if (switch_count > 0xC) {
        switch_count = 0xC;
    }
    if (first_switch < 0) {
        first_switch = 0;
    }
    if (first_switch > 0xFF - switch_count) {
        first_switch = 0xFF - switch_count;
    }
}

void TObjRaderIcon::run_task() {
    s32 all;
    s32 i;
    switch (color_mode) {
    case 0:
        all = 1;
        for (i = 0; i < switch_count; i++) {
            if (is_current_floor_switch_set((u16)(first_switch + i)) == 0) {
                all = 0;
            }
        }
        if (all == 1) {
            add_radar_scaled_gate(&position, 0xFF00FF00, rotation.y, 0, 0, size);
        } else {
            add_radar_scaled_gate(&position, 0xFFFF0000, rotation.y, 0, 0, size);
        }
        break;
    case 1:
        add_radar_scaled_gate(&position, color, rotation.y, 0, 0, size);
        break;
    }
}

void TObjRaderIcon::render() {  }


void *TObjRaderIcon::create(ObjectSetData *set_data) {
    return new TObjRaderIcon(tl_05, set_data);
}
