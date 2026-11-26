#include "types.h"
#include "pso/unk/TLobby_80228154.h"
#include "pso/object/TObjChallenge4PRetry.h"
#include "pso/network/TLobby.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby_80207644.h"
#include <stddef.h>
#include "pso/system/scene/TScene.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/unk/text_803DA798.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/model_render_state.h"
#include "pso/system/NinjaTypes.h"
#include "pso/map/area/AreaScene.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/MatrixStack.h"

// Area set-up functions of TLobby_80299A60/B90/C4C.cpp, which have no header.
s32 init_scene_delo2();
s32 load_dragon2_scene();


// The screen quad draw_textured_quad_at_depth reads.

union TLobbySpriteColor {
    struct { u8 a, r, g, b; } channels;
    u32 packed;
};

// Draws one frame of a sprite on the screen; flags 1 rotates the quad by the
// sprite's angle, 2 tints it with the model material colour, 0x20 blends.
void draw_screen_sprite(NJS_SPRITE *sprite, s32 frame_index, s32 flags, f32 depth) {
    TLobbyScreenQuad quad;
    union TLobbySpriteColor color;
    if (sprite == NULL) {
        return;
    }
    if (sprite->tlist == NULL) {
        return;
    }
    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(sprite->tlist));
    NJS_TEXANIM *frame = &sprite->tanim[frame_index];
    f32 left = -frame->cx;
    f32 top = -frame->cy;
    f32 right = left + frame->sx;
    f32 bottom = top + frame->sy;
    left *= sprite->sx;
    right *= sprite->sx;
    top *= sprite->sy;
    bottom *= sprite->sy;
    quad.x0 = sprite->p.x + left;
    quad.y0 = sprite->p.y + top;
    quad.x1 = sprite->p.x + right;
    quad.y1 = sprite->p.y + bottom;
    quad.u0 = frame->u1 / 256.0f;
    if (1.0f < quad.u0) {
        quad.u0 = 1.0f;
    }
    quad.v0 = frame->v1 / 256.0f;
    if (1.0f < quad.v0) {
        quad.v0 = 1.0f;
    }
    quad.u1 = frame->u2 / 256.0f;
    if (1.0f < quad.u1) {
        quad.u1 = 1.0f;
    }
    quad.v1 = frame->v2 / 256.0f;
    if (1.0f < quad.v1) {
        quad.v1 = 1.0f;
    }
    color.packed = 0xFFFFFFFF;
    if (flags & 1) {
        Vec offset;
        f32 cx = (quad.x1 + quad.x0) / 2.0f;
        f32 cy = (quad.y1 + quad.y0) / 2.0f;
        offset.x = quad.x0 - cx;
        offset.y = quad.y0 - cy;
        offset.z = 0.0f;
        push_matrix_from(identity_matrix);
        rotate_matrix_z(NULL, sprite->ang);
        rotate_vector_by_matrix(0, &offset, &offset);
        pop_matrix();
        quad.x0 = cx + offset.x;
        quad.y0 = cy + offset.y;
        quad.x1 = cx - offset.x;
        quad.y1 = cy - offset.y;
    }
    if (flags & 2) {
        color.channels.b = 255.0f * model_material_color.b;
        color.channels.g = 255.0f * model_material_color.g;
        color.channels.r = 255.0f * model_material_color.r;
        color.channels.a = 255.0f * model_material_color.a;
    }
    if (flags & 4) {
        quad.u1 = quad.u0;
        quad.u0 = quad.u1;
    }
    if (flags & 8) {
        quad.v1 = quad.v0;
        quad.u0 = quad.v1;
    }
    depth = -1.0f / depth;
    begin_screen_draw(0x20 == (flags & 0x20));
    set_draw_texture_and_color(frame->texid, color.packed);
    draw_textured_quad_at_depth(&quad.x0, depth);
    end_screen_draw();
}

void FloorTransition::clear_ready_flag_unless_locked() {
    if (get_current_floor_area() != AREA_LOBBY) {
        state_flags &= ~1;
    }
}

// Callers supply an existing terrain hint. The transition recomputes its map from the selected floor.
void FloorTransition::set_next_floor(s32 floor, s32) {
    next_floor = floor;
    next_map = get_floor_map_terrain(next_floor);
}

#pragma push
#pragma fp_contract on
s32 select_area_entrance(FloorTransition *transition) {
    s32 floor_delta;
    s32 temp_r3;
    if ((s32) transition->previous_floor > 0x11) {
        return 4;
    }
    if (transition->state_flags & 1) {
        return 2;
    }
    if ((TLobby::get_instance() == 0) && (get_floor_area(transition->previous_floor) == 0xD)) {
        switch (get_floor_area(transition->current_floor)) {
        case 8:
        case 9:
        case 10:
            return 1;
        default:
            return 0;
        }
    }
    floor_delta = transition->current_floor - transition->previous_floor;
    if (floor_delta >= 0) {
        return 1;
    }
    return (floor_delta < 0) ? 0 : 4;
}
#pragma pop

// inferred: the area's name, the function that loads and sets it up, and the one that tears it down
// (load_area_scene_and_init calls init; run_area_scene_cleanup and promote_area_floor call cleanup).
struct AreaInitializer {
    const char *name;
    s32 (*init)();
    void (*cleanup)();
};

AreaInitializer area_initializer_dispatch_table[] = {
    { "CITY", TLobby::setup_scene, TLobby::cleanup_boss3_scene },
    { "FOREST01", init_stage_forest_b, TLobby::update_floor_objects },
    { "FOREST02", init_forest_b, TLobby::update_all },
    { "CAVE01", init_cave_b_stage, TLobby::run_floor_update },
    { "CAVE02", load_scene_cave_b, TLobby::update_floor_and_windows },
    { "CAVE03", init_stage_cave_b, TLobby::update_scene },
    { "MACHINE01", init_machine_scene, TLobby::update_floor_alt },
    { "MACHINE02", init_machine_b_scene, TLobby::update_floor_b },
    { "ANCIENT01", ship_scene_update, TLobby::update_floor },
    { "ANCIENT02", init_ship_scene, TLobby::update_floor_a },
    { "ANCIENT03", load_scene_ship_b, TLobby::update_floor_state },
    { "BOSS01", init_dragon_area_scene, cleanup_dragon_area_scene },
    { "BOSS02", TLobby::setup_area, cleanup_boss2_area },
    { "BOSS03", TLobby::spawn_boss3_volopt_ctrl, cleanup_boss3_area },
    { "BOSS04", TLobby::init_lobby_scene, TLobby::reset_subsystems },
    { "LOBBY", TLobby::init_lobby_floor_scene, TLobby::update_floor_download },
    { "VERSUS01", init_spaceship_area, TLobby::refresh_floor_state },
    { "VERSUS02", init_temple_area, TLobby::run_floor_update_2 },
    { "LABO", TLobby::setup_scene, TLobby::cleanup_boss3_scene },
    { "RUINS01", init_temple_area, TLobby::run_floor_update_2 },
    { "RUINS02", init_temple_area, TLobby::run_floor_update_2 },
    { "SPACE01", init_spaceship_area, TLobby::refresh_floor_state },
    { "SPACE02", init_spaceship_area, TLobby::refresh_floor_state },
    { "JUNGLE01", init_jungle_area, update_floor_state_deferred },
    { "JUNGLE02", init_jungle_area, update_floor_state_deferred },
    { "JUNGLE03", init_jungle_area, update_floor_state_deferred },
    { "JUNGLE04", init_jungle_area, update_floor_state_deferred },
    { "JUNGLE05", init_jungle_area, update_floor_state_deferred },
    { "SEABED01", initialize_boss_scene, update_scene_alt },
    { "SEABED02", initialize_boss_scene, update_scene_alt },
    { "BOSS05", TLobby::init_gryphon_area, TLobby::cleanup_floor_state },
    { "BOSS06", TLobby::init_particle_model, TLobby::refresh_lobby_state },
    { "BOSS07", init_scene_delo2, TLobby::update_subsystems },
    { "BOSS08", load_dragon2_scene, TLobby::update_field_state },
    { "JUNGLE06", init_jungle_area, update_floor_state_deferred },
    { "JUNGLE07", init_jungle_area, update_floor_state_deferred },
};

void run_area_scene_cleanup(FloorTransition *transition) {
    FloorMapSelection selection;
    FloorMapSelection *selection_ptr;
    FloorTransition *trans;
    selection_ptr = &selection;
    trans = transition;
    if (lookup_floor_map_selection(transition->current_floor, selection_ptr) != 0) {
        area_initializer_dispatch_table[selection.area].cleanup();
    } else {
        area_initializer_dispatch_table[trans->current_floor].cleanup();
    }
    trans->current_floor = 0;
    trans->f8 = 0;
    trans->next_floor = 0;
}


void load_area_scene_and_init(u8 *transition) {
    FloorMapSelection selection;
    FloorMapSelection *selection_ptr;
    s32 value;
    u8 *trans;
    trans = transition;
    value = *(s32 *)((s8 *)transition + 4);
    set_current_floor_area((value));
    value = *(s32 *)((s8 *)trans + 0x10);
    TScene::set_scene(value);
    value = *(s32 *)((s8 *)trans + 4);
    selection_ptr = &selection;
    if (lookup_floor_map_selection(value, selection_ptr) != 0) {
        area_initializer_dispatch_table[selection.area].init();
        return;
    }
    area_initializer_dispatch_table[*(s32 *)((s8 *)trans + 4)].init();
}

void promote_area_floor(FloorTransition *transition) {
    FloorMapSelection selection;
    FloorMapSelection *selection_ptr;
    FloorTransition *trans;
    selection_ptr = &selection;
    trans = transition;
    if (lookup_floor_map_selection(transition->current_floor, selection_ptr) != 0) {
        area_initializer_dispatch_table[selection.area].cleanup();
    } else {
        area_initializer_dispatch_table[trans->current_floor].cleanup();
    }
    trans->previous_floor = (s32) trans->current_floor;
    trans->current_floor = (s32) trans->next_floor;
    trans->current_map = (s32) trans->next_map;
    TLobby::reset_story_select_state();
}

FloorTransition floor_transition_state;
