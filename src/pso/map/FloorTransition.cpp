#include "types.h"
#include "pso/map/FloorTransition.h"
#include "pso/object/TObjChallenge4PRetry.h"
#include "pso/network/TLobby.h"
#include "pso/map/FloorArea.h"
#include "pso/map/FloorMapSelection.h"
#include <stddef.h>
#include "pso/system/scene/TScene.h"
#include "pso/player/LocalClientId.h"
#include "pso/render/TextureState.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/system/NinjaTypes.h"
#include "pso/map/area/AreaScene.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/MatrixStack.h"

// Area set-up functions of Dragon2Scene.cpp and Delo2Scene.cpp, which have no header.
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
    { "CITY", init_city_area, cleanup_city_area },
    { "FOREST01", init_forest1_area, cleanup_forest1_area },
    { "FOREST02", init_forest2_area, cleanup_forest2_area },
    { "CAVE01", init_cave1_area, cleanup_cave1_area },
    { "CAVE02", init_cave2_area, cleanup_cave2_area },
    { "CAVE03", init_cave3_area, cleanup_cave3_area },
    { "MACHINE01", init_machine1_area, cleanup_machine1_area },
    { "MACHINE02", init_machine2_area, cleanup_machine2_area },
    { "ANCIENT01", init_ancient1_area, cleanup_ancient1_area },
    { "ANCIENT02", init_ancient2_area, cleanup_ancient2_area },
    { "ANCIENT03", init_ancient3_area, cleanup_ancient3_area },
    { "BOSS01", init_dragon_area_scene, cleanup_dragon_area_scene },
    { "BOSS02", init_boss2_area, cleanup_boss2_area },
    { "BOSS03", init_boss3_area, cleanup_boss3_area },
    { "BOSS04", init_boss4_area, cleanup_boss4_area },
    { "LOBBY", init_lobby_area, cleanup_lobby_area },
    { "VERSUS01", init_spaceship_area, cleanup_spaceship_area },
    { "VERSUS02", init_temple_area, cleanup_temple_area },
    { "LABO", init_city_area, cleanup_city_area },
    { "RUINS01", init_temple_area, cleanup_temple_area },
    { "RUINS02", init_temple_area, cleanup_temple_area },
    { "SPACE01", init_spaceship_area, cleanup_spaceship_area },
    { "SPACE02", init_spaceship_area, cleanup_spaceship_area },
    { "JUNGLE01", init_jungle_area, update_floor_state_deferred },
    { "JUNGLE02", init_jungle_area, update_floor_state_deferred },
    { "JUNGLE03", init_jungle_area, update_floor_state_deferred },
    { "JUNGLE04", init_jungle_area, update_floor_state_deferred },
    { "JUNGLE05", init_jungle_area, update_floor_state_deferred },
    { "SEABED01", initialize_boss_scene, update_scene_alt },
    { "SEABED02", initialize_boss_scene, update_scene_alt },
    { "BOSS05", init_gryphon_area, cleanup_gryphon_area },
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
