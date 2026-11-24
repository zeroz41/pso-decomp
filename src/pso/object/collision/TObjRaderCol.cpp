#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/collision/TObjRaderCol.h"
#include "pso/object/collision/TObjRaderHideCol.h"
#include "pso/ui/hud/TObjRaderIcon.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

struct Col_8019750C { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x4C]; f32 f90; s32 id; u8 pad98[4]; s32 f9C; };

struct Ply_8019750C { u8 pad0[0x38]; f32 pos[3]; };
struct Icon_80197110 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x1C]; s32 f60; u8 pad64[0x2C]; s32 f90; s32 f94; s32 f98; f32 f9C; u32 fA0; };

extern "C" {
const char *TObjRaderCol__name = "TObjRaderCol";
const char *TObjRaderHideCol__name = "TObjRaderHideCol";
const char *TObjRaderIcon__name = "TObjRaderIcon";
void check_any_player_in_range__12TObjRaderColFPv(Col_8019750C *arg0);
u8 is_current_floor_switch_set(u16);

}


// Deferred TU: code is generated last-defined-first, so the functions are written in
// reverse address order (vtables and .text then come out in the original order).
#pragma defer_codegen on

TObjRaderCol::~TObjRaderCol() {

}

TObjRaderCol::TObjRaderCol(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjRaderCol__name;
    apply_object_set_data(set_data);
    *(f32 *)((s8 *)this + 0x90) = (f32) scale.x;
    id = (s32) set_params[0];
    m_98 = 0;
    m_9c = 3;
    disallow_rendering();
}

void TObjRaderCol::run_task() {

    switch (this->m_98) {
    case 0:
        TRaderMapCore::block_region_by_id((s16) this->id);
        this->m_98 = 1;
        return;
    case 1:
        if (TRaderMapCore::is_not_split_screen() == 1) {
            check_any_player_in_range__12TObjRaderColFPv((Col_8019750C *)(this));
            return;
        }
        TObjRaderCol::check_local_player_in_range(this);
        return;
    }
}

#define arg0 ((Col_8019750C *)arg0_)
void TObjRaderCol::check_local_player_in_range(void *arg0_) {
    Ply_8019750C *p = (Ply_8019750C *)get_player_by_client_id(local_client_id);
    if (p != 0) {
        if (((TObjPlayer *)p)->is_body_collision_inactive() != 0) {
            return;
        }
    } else {
        return;
    }
    s32 t = arg0->f9C;
    if (t > 0) {
        arg0->f9C = t - 1;
        return;
    }
    if (p != 0) {
        if (xz_distance_squared((Vec *)p->pos, (Vec *)arg0->pos) < arg0->f90 * arg0->f90) {
            TRaderMapCore::reveal_region_by_id((s16)arg0->id);
            ((TObject *)arg0)->queue_destruction();
        }
    }
}
#undef arg0


void check_any_player_in_range__12TObjRaderColFPv(Col_8019750C *arg0) {
    s32 found;
    s32 i;
    s32 j;
    Ply_8019750C *p;
    found = 0;
    for (i = 0; i < 4; i++) {
        p = (Ply_8019750C *)get_player_by_client_id(i);
        if (p != 0 && ((TObjPlayer *)p)->is_body_collision_inactive() != 0) {
            found = 1;
        }
    }
    if (found == 0) {
        if (arg0->f9C > 0) {
            arg0->f9C--;
        } else {
            for (j = 0; j < 4; j++) {
                p = (Ply_8019750C *)get_player_by_client_id(j);
                if (p != 0 && xz_distance_squared((Vec *)p->pos, (Vec *)arg0->pos) < arg0->f90 * arg0->f90) {
                    TRaderMapCore::reveal_region_by_id(arg0->id);
                    ((TObject *)arg0)->queue_destruction();
                    return;
                }
            }
        }
    }
}

void TObjRaderCol::render() {  }

TObjRaderHideCol::TObjRaderHideCol(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjRaderHideCol__name;
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


TObjRaderIcon::TObjRaderIcon(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjRaderIcon__name;
    apply_object_set_data(set_data);
    initialize_from_placement();
    disallow_rendering();
}

TObjRaderIcon::~TObjRaderIcon() {

}

void TObjRaderIcon::initialize_from_placement() {
    s32 temp_r0;
    *(s32 *)&this->m_90 = 0;
    *(s32 *)&this->m_94 = 1;
    *(s32 *)&this->m_98 = 0;
    *(f32 *)&this->_pad9C = 1.0f;
    *(s32 *)&this->m_a0 = 0;
    *(s32 *)&this->m_90 = (s32) this->set_params[0];
    if ((s32) *(s32 *)&this->m_90 < 0) {
        *(s32 *)&this->m_90 = 0;
    }
    if ((s32) *(s32 *)&this->m_90 > 1) {
        *(s32 *)&this->m_90 = 1;
    }
    *(f32 *)&this->_pad9C = (f32) this->scale.x;
    if (*(f32 *)&this->_pad9C < 0.0f) {
        *(f32 *)&this->_pad9C = 0.0f;
    }
    *(s32 *)&this->m_a0 = (s32) *(s32 *)&this->set_params[2];
    *(s32 *)&this->m_94 = (s32) (u16) ((s32) *(s32 *)&this->set_params[1] >> 0x10);
    *(s32 *)&this->m_98 = (s32) (u16) *(s32 *)&this->set_params[1];
    if ((s32) *(s32 *)&this->m_94 < 0) {
        *(s32 *)&this->m_94 = 0;
    }
    if ((s32) *(s32 *)&this->m_94 > 0xC) {
        *(s32 *)&this->m_94 = 0xC;
    }
    if ((s32) *(s32 *)&this->m_98 < 0) {
        *(s32 *)&this->m_98 = 0;
    }
    if ((s32) *(s32 *)&this->m_98 > 0xFF - *(s32 *)&this->m_94) {
        *(s32 *)&this->m_98 = 0xFF - *(s32 *)&this->m_94;
    }
}

void TObjRaderIcon::run_task() {
    Icon_80197110 *arg0 = (Icon_80197110 *)this;
    s32 all;
    s32 i;
    switch (arg0->f90) {
    case 0:
        all = 1;
        for (i = 0; i < arg0->f94; i++) {
            if (is_current_floor_switch_set(arg0->f98 + i) == 0) {
                all = 0;
            }
        }
        if (all == 1) {
            add_radar_scaled_gate(&position, 0xFF00FF00, arg0->f60, 0, 0, arg0->f9C);
        } else {
            add_radar_scaled_gate(&position, 0xFFFF0000, arg0->f60, 0, 0, arg0->f9C);
        }
        break;
    case 1:
        add_radar_scaled_gate(&position, arg0->fA0, arg0->f60, 0, 0, arg0->f9C);
        break;
    }
}

void TObjRaderIcon::render() {  }


void *TObjRaderIcon::create(void *set_data) {
    return new TObjRaderIcon(tl_05, set_data);
}
