#include "pso/misc/TODoorAncient09.h"

#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TLobby_80160804.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/misc/TSwitch.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"

// TLobby_8001EF5C's resource loader and release, declared there with
// stand-in types (see the lane report): the 0x440-byte resource's constructor
// and destructor.
extern "C" {
BmlResource *load_resource_from_descriptor(void *storage, s32 kind, BmlResourceDescriptor *descriptor, s32, s32, s32);
void TLobby__sub_8001FE7C(BmlResource *resource, s16 del);
}

// Written from the last function back: the unit is compiled with deferred
// code generation (its vtable precedes its switch tables).

const char *fs_obj_o_door05l_model_names[] = {"fs_obj_o_door05l.gj", NULL};
const char *fs_obj_o_door05l_motion_names[] = {"fs_obj_o_door05l.njm", NULL};
BmlResourceDescriptor door_ancient09_resource_descriptor = {
    "fs_obj_o_door05l.bml", fs_obj_o_door05l_model_names, fs_obj_o_door05l_motion_names, 1, 1,
};

const char *door_ancient09_class_name = "TODoorAncient09";

static CollisionBody door_ancient09_collision_body[1] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003},
};

BmlResource *TODoorAncient09::bml_resource;
s32 *TODoorAncient09::texture_lists;

TODoorAncient09::TODoorAncient09(TObject *parent, void *set_data) : TODoorBase(parent) {
    m_name = door_ancient09_class_name;
    apply_object_set_data(set_data);
    texlist = texture_lists[0];
    model = (void *)bml_resource->models[0].model;
    motion = bml_resource->motions[0].motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    m_b8 = animation_end_frame / 30.0f;
    init_collision_body_parts(this, door_ancient09_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    if (set_params[0] < 0) {
        set_params[0] = 0;
    } else if (set_params[0] > 0xFE) {
        set_params[0] = 0xFE;
    }
    init_door_switch_binding();
    extra_switch_id = set_params[0] + 1;
    both_switches_set = 0;
    m_dc = 0;
    is_open = 0;
    m_e4 = 0;
}

TODoorAncient09::~TODoorAncient09() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TODoorAncient09::load_resources() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &door_ancient09_resource_descriptor, 0, 0, 0);
    }
    bml_resource = resource;
    texture_lists = (s32 *)mem_alloc(8);
    texture_lists[0] = bml_resource->models[0].m_c;
    texture_lists[1] = (s32)load_gvm_texture_file((s32)"fs_obj_o_door05l_g.gvm");
}

void TODoorAncient09::destroy() {
    if (texture_lists != NULL) {
        TObjPlayer::free_if_valid(texture_lists[1]);
        if (texture_lists != NULL) {
            mem_free(texture_lists);
            texture_lists = NULL;
        }
    }
    if (bml_resource != NULL) {
        TLobby__sub_8001FE7C(bml_resource, 1);
        bml_resource = NULL;
    }
}

void *TODoorAncient09::create(void *set_data) {
    return new TODoorAncient09(tl_05, set_data);
}

void TODoorAncient09::update_closed() {
    if ((door_flags & 1) && is_any_player_within_radius_xz(4900.0f) == 1) {
        m_ac = 1;
        texlist = texture_lists[1];
        set_indexed_flags(0, 8);
        is_open = 1;
        switch (get_current_floor_area()) {
        case AREA_CAVE1:
        case AREA_CAVE2:
        case AREA_CAVE3:
            play_sound_effect(0x42807, &position, 0, 0);
            break;
        case AREA_MINE1:
        case AREA_MINE2:
            play_sound_effect(0x4004BC01, &position, 0, 0);
            break;
        case AREA_RUINS1:
        case AREA_RUINS2:
        case AREA_RUINS3:
            play_sound_effect(0x4004B708, &position, 0, 0);
            break;
        case AREA_PIONEER2_EP1:
        case AREA_LOBBY:
            break;
        }
    }
}

void TODoorAncient09::update_open() {
    if (door_flags & 1) {
        texlist = texture_lists[1];
        if (is_any_player_within_radius_xz(10000.0f) == 1) {
            return;
        }
        m_ac = 3;
        clear_player_status_flag(0, 8);
        is_open = 0;
        switch (get_current_floor_area()) {
        case AREA_CAVE1:
        case AREA_CAVE2:
        case AREA_CAVE3:
            play_sound_effect(0x42807, &position, 0, 0);
            break;
        case AREA_MINE1:
        case AREA_MINE2:
            play_sound_effect(0x4004BC01, &position, 0, 0);
            break;
        case AREA_RUINS1:
        case AREA_RUINS2:
        case AREA_RUINS3:
            play_sound_effect(0x4004B708, &position, 0, 0);
            break;
        case AREA_PIONEER2_EP1:
        case AREA_LOBBY:
            break;
        }
    } else {
        m_ac = 3;
        texlist = texture_lists[0];
        clear_player_status_flag(0, 8);
        is_open = 0;
    }
}

void TODoorAncient09::update_demo() {}

void TODoorAncient09::render() {
    if (update_object_view_visibility(m_c0, model_radius) != 0 && is_in_view_depth(30.0f) != 0) {
        switch (m_ac) {
        case 1:
        case 3:
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(NULL, rotation_y);
            TObjFish::set_global_param(texlist);
            draw_ginja_model_with_motion(model, motion, m_b0);
            pop_matrix();
            return;
        case 2:
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(NULL, rotation_y);
            TObjFish::set_global_param(texlist);
            draw_ginja_model_with_motion(model, motion, animation_end_frame - 1.0f);
            pop_matrix();
            return;
        case 0:
            draw_switch_lights();
            break;
        }
    }
}

void TODoorAncient09::draw_switch_lights() {
    s32 on[2];
    NJS_OBJECT *pairs[2][2];
    NJS_OBJECT *root;
    u8 lit;
    u8 set;
    NJS_OBJECT **pair;
    s32 i;
    lit = 0;
    root = (NJS_OBJECT *)model;
    pairs[0][0] = root->child->child;
    pairs[0][1] = root->child->child->sibling;
    pairs[1][0] = root->child->sibling;
    pairs[1][1] = root->child->sibling->sibling;
    if (is_current_floor_switch_set((u16)switch_id) != 0 || (door_flags & 1)) {
        lit = 1;
    }
    on[0] = lit;
    set = 0;
    if (is_current_floor_switch_set(extra_switch_id) != 0 || (door_flags & 1)) {
        set = 1;
    }
    on[1] = set;
    push_matrix();
    TObjFish::set_global_param(texture_lists[0]);
    post_translate_matrix(&position.x);
    post_translate_matrix(root->pos);
    rotate_matrix_y(NULL, rotation_y);
    draw_ginja_model((s32)root->model);
    draw_ginja_model((s32)root->child->model);
    TParticleCtrl::begin_effect_render();
    for (i = 0; i < 2; i++) {
        if (on[i] != 0) {
            TObjFish::set_global_param(texture_lists[1]);
        } else {
            TObjFish::set_global_param(texture_lists[0]);
        }
        push_matrix();
        pair = pairs[i];
        post_translate_matrix(pair[0]->pos);
        draw_ginja_model((s32)pair[0]->model);
        pop_matrix();
        push_matrix();
        post_translate_matrix(pair[1]->pos);
        draw_ginja_model((s32)pair[1]->model);
        pop_matrix();
    }
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TODoorAncient09::update_door_switch_state() {
    s16 state;
    switch (lock_mode) {
    case 1:
        play_open_sound();
        door_flags |= 1;
        return;
    case 2:
        if (is_current_floor_switch_set((u16)switch_id) == 1 && is_current_floor_switch_set(extra_switch_id) == 1) {
            play_open_sound();
            door_flags |= 1;
            both_switches_set = 1;
            return;
        }
        door_flags &= ~1;
        both_switches_set = 0;
        return;
    case 3:
        if (is_current_floor_switch_set((u16)switch_id) == 1 && is_current_floor_switch_set(extra_switch_id) == 1) {
            play_open_sound();
            door_flags |= 1;
            if (set_entry != NULL && access_object_saved_state(&state, 1) != 0) {
                state = 1;
                door_ancient09_sync_state(&state);
                access_object_saved_state(&state, 0);
            }
        }
        return;
    default:
        door_flags &= ~1;
        break;
    }
}

void TODoorAncient09::play_open_sound() {
    if (!(door_flags & 1)) {
        switch (get_current_floor_area()) {
        case AREA_PIONEER2_EP1:
            play_sound_effect(0x42A04, &position, 0, 0);
            break;
        case AREA_FOREST1:
        case AREA_FOREST2:
            play_sound_effect(0x4BC07, &position, 0, 0);
            break;
        case AREA_CAVE1:
        case AREA_CAVE2:
        case AREA_CAVE3:
            play_sound_effect(0x42807, &position, 0, 0);
            break;
        case AREA_MINE1:
        case AREA_MINE2:
            play_sound_effect(0x4004BC00, &position, 0, 0);
            break;
        case AREA_RUINS1:
        case AREA_RUINS2:
        case AREA_RUINS3:
            play_sound_effect(0x4004BC07, &position, 0, 0);
            break;
        case AREA_LOBBY:
            break;
        }
    }
}

s32 TODoorAncient09::init_door_switch_binding() {
    switch_id = set_params[0];
    if (switch_id > 0x100) {
        lock_mode = 0;
    } else if (switch_id < 0) {
        lock_mode = 1;
    } else if (set_params[2] < 0 && (get_main_phase() == 0xF || is_split_screen() == 1)) {
        lock_mode = 3;
    } else {
        lock_mode = 2;
    }
    return switch_id;
}

void TODoorAncient09::vfunc_6(s16 *state, s32) {
    if (*state == 1) {
        door_flags |= 1;
    }
}

// The 6x0B object-state message (see the lane report: the stack structs
// still call the packet helpers under their TLobby / TOBarrierEnergy01 names).
struct State_80160838 { s16 a; s16 b; };
struct Pkt_80160838 { s16 hdr; u16 id; s32 state; s32 kind; };
struct Obj_80160838 { u8 pad[4]; s16 kind; };

void TODoorAncient09::door_ancient09_sync_state(void *src_arg) {
    State_80160838 *src = (State_80160838 *)src_arg;
    State_80160838 st;
    Obj_80160838 *obj;
    if (src != NULL) {
        ((TLobby *)&st)->copy_short_fields(src);
    } else {
        access_object_saved_state(&st, 1);
    }
    obj = (Obj_80160838 *)set_entry;
    if (obj != NULL) {
        Pkt_80160838 pkt;
        ((TOBarrierEnergy01 *)&pkt)->init();
        pkt.id = entity_id;
        pkt.state = st.a;
        pkt.kind = obj->kind;
        update_and_send_60__6TLobbyFPv(&pkt);
    }
}
