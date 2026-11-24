#include "pso/system/memory.h"
#include "pso/system/ResourceFile.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/TFogCtrl_EOR.h"
#include "pso/render/TFogCtrl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/math/FloatRounding.h"
#include "pso/unk/text_803E1FC8.h"
#include "pso/unk/text_803E2008.h"
#include "pso/unk/text_803E2070.h"
#include <stddef.h>
#include "pso/map/FloorArea.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/collision/TObjFogCollisionPoison.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/math/AngleLookup.h"

extern "C" {
static const char lbl_8043DA20[] = "fogentry.dat";
static const char lbl_8043DA30[] = "fogentry_a.dat";
const char *TFogCtrl__name = "TFogCtrl";
const char *TFogCtrl_EOR__name = "TFogCtrl_EOR";
}

struct GXFogAdjTable {
    u16 r[10];
};

extern "C" {

void create_area_fog_ctrl(void);
void GXInitFogAdjTable(GXFogAdjTable *, s32, void *);
void GXSetFogRangeAdj(s32, s32, GXFogAdjTable *);

extern s32 area_fog_row_table[];
extern FogEntry fog_default_entry;
extern u8 scene_projection_state[];
extern FogEntry *fog_entry_array;
extern s32 fog_update_flags;

extern const f32 TFogCtrl__data_805DA948 = 0.0f;
extern const f32 TFogCtrl__data_805DA94C = 640.0f;
#define FOG_ZERO (*(const f32 *)&TFogCtrl__data_805DA948)
#define FOG_MAX (*(const f32 *)&TFogCtrl__data_805DA94C)
}
FogEntry *copy_fog_entry(FogEntry *dst, FogEntry *src);
void init_scene_fog_system(void);

s32 area_fog_row_table[36] = {
    33, 1, 2, 3, 4, 5, 14, 15, 30, 31, 32, 23, 16, 34, 35, 34, 19, 47,
    96, 97, 98, 64, 65, 24, 25, 26, 27, 28, 40, 41, 66, 99, 100, 16, 73, 75,
};
// The TFogCtrl of each view (one per player in split screen).
TFogCtrl *TFogCtrl::fog_instance_table[4];
FogEntry fog_default_entry;
FogEntry *fog_entry_array;
s32 fog_update_flags;
TFogCtrl_EOR *fog_ctrl_instance;


void init_scene_fog_system(void) {
    s32 i;
    fog_update_flags = 0;
    fog_default_entry.flags = 1;
    fog_default_entry.color = 0;
    fog_default_entry.end = 4000.0f;
    fog_default_entry.start = 100.0f;
    fog_default_entry.rate = 0.01f;
    fog_default_entry.pad_14 = 0;
    for (i = 0; i < 8; i++) {
        fog_default_entry.waves[i] = FOG_ZERO;
        fog_default_entry.wave_phases[i] = 0;
    }
    fog_default_entry.waves[6] = FOG_MAX;
    fog_entry_array = (FogEntry *)mem_alloc(0x80 * sizeof(FogEntry));
    for (i = 0; i < 0x80; i++) {
        copy_fog_entry(&fog_entry_array[i], &fog_default_entry);
    }
    read_disc_file(lbl_8043DA20, fog_entry_array);
    for (i = 0; i < 4; i++) {
        TFogCtrl::fog_instance_table[i] = NULL;
    }
    TParticleCtrl::end_effect_render();
    TFogCtrl::create_instance();
    TObjFogCollisionPoison::clear_state_array();
}

void TFogCtrl::reset() {
    TObjFogCollisionPoison__sub_801533BC();
    TQuestVmDownLoadServer::destroy_instance();
    if (fog_entry_array != NULL) {
        mem_free(fog_entry_array);
    }
    fog_entry_array = NULL;
    fn_803E1FC8(0xFFFFFFFF);
    set_scene_fog_distances((1e+03f), (1e+04f));
    reset_scene_fog();
    TParticleCtrl::begin_effect_render();
}

void create_area_fog_ctrl(void) {
    s32 i;
    if (is_split_screen() != 0) {
        i = 0;
        do {
            new TFogCtrl(tl_02, i);
            i += 1;
        } while (i != 4);
    } else {
        new TFogCtrl(tl_02, 0);
    }
    TObjFogCollisionPoison::create();
    s32 row = area_fog_row_table[get_current_floor_area()];
    TFogCtrl::update_all(row, 1);
}

void TFogCtrl::update_fog_entries() {
    s32 i;
    if (TLobby::is_online_ready() != 0) {
        if (!(fog_update_flags & 2)) {
            read_disc_file(lbl_8043DA30, fog_entry_array);
            fog_update_flags |= 2;
        }
    } else if (fog_update_flags & 2) {
        read_disc_file(lbl_8043DA20, fog_entry_array);
        fog_update_flags &= ~2;
    }
    for (i = 0; i != 4; i++) {
        if (fog_instance_table[i] != NULL) {
            fog_instance_table[i]->on_entries_loaded();
        }
    }
    TParticleCtrl::end_effect_render();
}

void TFogCtrl::on_entries_loaded() { }

void TFogCtrl::release_fog_entries() {
    s32 i;
    for (i = 0; i != 4; i++) {
        if (fog_instance_table[i] != NULL) {
            fog_instance_table[i]->on_entries_released();
        }
    }
}

void TFogCtrl::on_entries_released() { }

#pragma push
#pragma opt_common_subs off
TFogCtrl::TFogCtrl(TObject *parent, s32 index) : TObject(parent) {
    s32 i;
    f32 zero;
    m_name = TFogCtrl__name;
    this->index = index;
    if (this->index >= 0 && this->index < 4) {
        fog_instance_table[this->index] = this;
    }
    mode = 0;
    zero = FOG_ZERO;
    for (i = 0; i < 4; i++) {
        slot_storage[i].entry = 0;
        copy_fog_entry(&slot_storage[i].params, &fog_default_entry);
        slot_storage[i].scroll = zero;
        slots[i] = &slot_storage[i];
    }
    selected = 0;
    zero = FOG_ZERO;
    request_from = 0;
    request_to = 0;
    request_selected = 0;
    pad_1a8 = 0;
    blend_from = 0;
    blend_to = 0;
    blend_selected = 0;
    blend_amount = zero;
    blend_rate = zero;
    locked = 0;
    dirty = 0;
    apply_slot_params(0);
}
#pragma pop

TFogCtrl::~TFogCtrl() {
    reset_scene_fog();
    TParticleCtrl::end_effect_render();
    if (index >= 0 && index < 4) {
        fog_instance_table[index] = NULL;
    }
}

#pragma push
#pragma fp_contract on
void TFogCtrl::run_task() {
    u32 c0;
    u32 c1;
    FogSlot *mixed;
    FogSlot *from;
    FogSlot *to;
    s32 update;
    f32 amount;
    f32 inv;
    f32 a;
    f32 b;
    u32 color;

    update = 0;
    switch (mode) {
    case 0:
        if (is_controller_animated(selected) != 0) {
            update = 1;
        }
        break;
    case 1:
        swap_slots(request_to, request_selected);
        update = 1;
        selected = request_selected;
        mode = 0;
        break;
    case 2:
        blend_from = request_from;
        blend_to = request_to;
        blend_selected = request_selected;
        blend_amount = FOG_ZERO;
        if (blend_to == 0) {
            blend_rate = slots[blend_from]->params.rate;
        } else {
            blend_rate = slots[blend_to]->params.rate;
        }
        if (blend_rate <= FOG_ZERO) {
            blend_rate = (0.001f);
        }
        selected = 3;
        slots[3]->entry = slots[blend_to]->entry;
        mode = 3;
    case 3:
        mixed = slots[3];
        from = slots[blend_from];
        to = slots[blend_to];
        mixed->scroll = FOG_ZERO;
        amount = blend_amount;
        if (amount >= 1.0f) {
            swap_slots(request_to, request_selected);
            selected = blend_selected;
            mode = 0;
        } else {
            c0 = from->params.color;
            c1 = to->params.color;
            inv = 1.0f - amount;
            a = (f32)((c0 >> 16) & 0xFF) * inv;
            b = (f32)((c1 >> 16) & 0xFF) * amount;
            color = (u8)(u32)(a + b) << 16;
            a = (f32)((c0 >> 8) & 0xFF) * inv;
            b = (f32)((c1 >> 8) & 0xFF) * amount;
            color |= (u8)(u32)(a + b) << 8;
            a = (f32)(c0 & 0xFF) * inv;
            b = (f32)(c1 & 0xFF) * amount;
            color |= (u8)(u32)(a + b);
            mixed->params.color = color;
            mixed->params.end = from->params.end * inv + to->params.end * amount;
            mixed->params.start = from->params.start * inv + to->params.start * amount;
            mixed->params.waves[0] = to->params.waves[0];
            mixed->params.waves[2] = from->params.waves[2] * inv + to->params.waves[2] * amount;
            mixed->params.waves[4] = from->params.waves[4] * inv + to->params.waves[4] * amount;
            mixed->params.waves[6] = from->params.waves[6] * inv + to->params.waves[6] * amount;
            mixed->params.wave_phases[2] = from->params.wave_phases[2] * inv + to->params.wave_phases[2] * amount;
            mixed->params.wave_phases[4] = from->params.wave_phases[4] * inv + to->params.wave_phases[4] * amount;
            mixed->params.wave_phases[6] = from->params.wave_phases[6] * inv + to->params.wave_phases[6] * amount;
            blend_amount += blend_rate;
        }
        update = 1;
        break;
    }
    if (update != 0) {
        apply_slot_params(selected);
    }
}
#pragma pop

void TFogCtrl::render() {  }

void TFogCtrl::load_entry_into_slot(s32 i, s32 entry) {
    s32 k;
    FogSlot *f = slots[i];
    f->entry = entry;
    copy_fog_entry(&f->params, TFogCtrl::get_entry(entry));
    f->scroll = FOG_ZERO;
    for (k = 0; k < 3; k++) {
        f->pad_48[k] = 0;
    }
}

void TFogCtrl::swap_slots(s32 i, s32 j) {
    FogSlot *t = slots[i];
    slots[i] = slots[j];
    slots[j] = t;
}

s32 TFogCtrl::is_controller_animated(s32 idx) {
    f32 scroll;
    f32 next;
    FogSlot *slot = slots[idx];
    u32 flags = slot->params.flags;
    if (flags & 2) {
        if (FOG_ZERO != slot->params.waves[2] || FOG_ZERO != slot->params.waves[4] || slot->params.wave_phases[6] != 0) {
            return 1;
        }
        return 0;
    }
    if (flags & 4) {
        scroll = slot->scroll;
        floor_to_float(scroll);
        next = scroll + slot->params.waves[0];
        floor_to_float(next);
        if (next < FOG_ZERO) {
            next += 128.0f;
        } else if (next >= 128.0f) {
            next -= 128.0f;
        }
        slot->scroll = next;
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
void TFogCtrl::apply_slot_params(s32 idx) {
    FogEntry *row = &slots[idx]->params;
    f32 t;
    color = row->color;
    end = row->end;
    start = row->start;
    width = FOG_MAX;
    if (FOG_ZERO != row->waves[2]) {
        t = row->waves[2] * sin_table_lookup((s32)((182.04445f) * ((f32)actor_frame_tick * row->waves[0] + (f32)row->wave_phases[2])));
        end += t;
    }
    if (FOG_ZERO != row->waves[4]) {
        t = row->waves[4] * sin_table_lookup((s32)((182.04445f) * ((f32)actor_frame_tick * row->waves[0] + (f32)row->wave_phases[4])));
        start += t;
    }
    if (FOG_ZERO != row->waves[6]) {
        width = (f32)row->wave_phases[6] * sin_table_lookup((s32)((182.04445f) * ((f32)actor_frame_tick * row->waves[0]))) + row->waves[6];
    }
    dirty |= 1;
}
#pragma pop

s32 TFogCtrl::get_param() { return locked; }

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TFogCtrl::request_transition(s32 arg1, s32 arg2) {
    if (arg2 & 1) {
        mode = 1;
    } else {
        mode = 2;
    }
    request_from = selected;
    request_to = 2;
    request_selected = arg1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TFogCtrl::request_fog(s32 entry, s32 flags) {
    if (get_param() != 0) {
        return 0;
    }
    if (slots[selected]->entry == entry) {
        return 1;
    }
    load_entry_into_slot(2, entry);
    request_transition(0, flags);
    return 1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TFogCtrl::select_fog(s32 entry, s32 arg2) {
    if (get_param() != 0) {
        return 0;
    }
    if (slots[selected]->entry == entry) {
        return 1;
    }
    load_entry_into_slot(2, entry);
    request_transition(1, arg2);
    return 1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TFogCtrl::restore_fog(s32 arg1) {
    s32 temp_r0;
    if (get_param() != 0) {
        return 0;
    }
    temp_r0 = selected;
    if (temp_r0 == 0) {
        return 1;
    }
    if ((temp_r0 == 3) && (blend_selected == 0)) {
        return 1;
    }
    if (arg1 & 1) {
        mode = 1;
    } else {
        mode = 2;
    }
    request_from = selected;
    request_to = 0;
    request_selected = 0;
    return 1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TFogCtrl::apply_fog_entry() {
    GXFogAdjTable tbl;
    set_scene_fog_type(2);
    fn_803E1FC8((color << 8) | (color >> 24));
    set_scene_fog_distances(start, end);
    if (is_split_screen() == 0) {
        if (width >= FOG_MAX) {
            width = FOG_MAX;
        } else if (width <= FOG_ZERO) {
            width = FOG_ZERO;
        }
        GXInitFogAdjTable(&tbl, (s32)width, scene_projection_state);
        GXSetFogRangeAdj(1, 0x140, &tbl);
    } else {
        if (width >= (3.2e+02f)) {
            width = (3.2e+02f);
        } else if (width <= FOG_ZERO) {
            width = FOG_ZERO;
        }
        GXInitFogAdjTable(&tbl, (s32)width, scene_projection_state);
        GXSetFogRangeAdj(1, 0xA0, &tbl);
    }
    TParticleCtrl::end_effect_render();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TFogCtrl::clear_active_flag() {
    s32 temp_r3;

    if (is_split_screen() == 0) {
        temp_r3 = dirty;
        if (temp_r3 & 1) {
            dirty = temp_r3 & ~1;
            apply_fog_entry();
        }
    } else {
        apply_fog_entry();
        dirty &= ~1;
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TFogCtrl::update_all() {
    s32 i;
    if (is_split_screen() == 0) {
        for (i = 0; i != 4; i++) {
            if (fog_instance_table[i] != NULL) {
                fog_instance_table[i]->clear_active_flag();
            }
        }
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TFogCtrl::clear_split_screen_fog() {
    TFogCtrl *fog;
    if (is_split_screen() == 1) {
        fog = fog_instance_table[TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_mode())];
        if (fog != NULL) {
            fog->clear_active_flag();
        }
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
FogEntry *TFogCtrl::get_entry(int a0) { return &fog_entry_array[a0]; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
FogEntry *copy_fog_entry(FogEntry *dst, FogEntry *src) {
    *dst = *src;
    return dst;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TFogCtrl::get_current_entry() { return slots[0]->entry; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TFogCtrl::restore_fog_for_player(s32 owner_client_id, s32 player) {
    if (is_split_screen() == 0) {
        owner_client_id = 0;
    }
    if ((owner_client_id >= 0) && (owner_client_id < 4)) {
        if (fog_instance_table[owner_client_id] != NULL) {
            return fog_instance_table[owner_client_id]->restore_fog(player);
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TFogCtrl::select_fog_for_viewport(s32 arg0, s32 entry, s32 arg2) {
    if (is_split_screen() == 0) {
        arg0 = 0;
    }
    if (arg0 >= 0 && arg0 < 4 && fog_instance_table[arg0] != NULL) {
        return fog_instance_table[arg0]->select_fog(entry, arg2);
    }
    return 0;
}
#pragma pop

s32 TFogCtrl::update_all(s32 arg0) {
    s32 i;
    for (i = 0; i != 4; i++) {
        if (fog_instance_table[i] != NULL) {
            fog_instance_table[i]->restore_fog(arg0);
        }
    }
    return 1;
}

s32 TFogCtrl::update_first_active_fog() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (fog_instance_table[i] != NULL) {
            return fog_instance_table[i]->get_current_entry();
        }
    }
    return 0;
}

s32 TFogCtrl::apply_all(s32 entry, s32 arg1) {
    s32 i;
    for (i = 0; i != 4; i++) {
        if (fog_instance_table[i] != NULL) {
            fog_instance_table[i]->select_fog(entry, arg1);
        }
    }
    return 1;
}

s32 TFogCtrl::update_all(s32 entry, s32 flags) {
    s32 i;
    for (i = 0; i != 4; i++) {
        if (fog_instance_table[i] != NULL) {
            fog_instance_table[i]->request_fog(entry, flags);
        }
    }
    return 1;
}

void TFogCtrl::create_instance() {
    fog_ctrl_instance = new TFogCtrl_EOR();
}

void TQuestVmDownLoadServer::destroy_instance() {
    if (fog_ctrl_instance != NULL) {
        fog_ctrl_instance->queue_destruction();
    }
    fog_ctrl_instance = NULL;
}

TFogCtrl_EOR::TFogCtrl_EOR() : TObject(&end_of_render_root) {
    m_name = TFogCtrl_EOR__name;
}

TFogCtrl_EOR::~TFogCtrl_EOR() {

}

void TFogCtrl_EOR::run_task() { TFogCtrl::update_all(); }

s32 TQuestVmDownLoadServer::poll_serial_access() { return TAdEnterSerialAccessGC::parse_serial_value(); }

s32 TQuestVmDownLoadServer::get_serial_access() { return TAdEnterSerialAccessGC::parse_serial_value(); }
