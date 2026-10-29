#include "types.h"
#include "pso/misc/TODragonflyMachine01.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/GinjaModel.h"
#include "pso/TODummyKeyCave01Sound.h"
#include "pso/map/FloorArea.h"
#include "pso/enemy/TObjEneMe3Stelth.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct DragonflyModelBounds {
    GinjaModel geometry;
    f32 radius;
};

struct DragonflyMotionSetup {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    s16 initial_action;
    s16 alternate_action;
    s16 unknown_c;
    s16 unknown_e;
};

extern "C" {
s32 rand(void);
f32 sin_table_lookup(s32);
extern s32 __vt__20TODragonflyMachine01[];
extern const char *TODragonflyMachine01__class_name;
extern BmlResource *TODragonflyMachine01__model_resource;
extern const f32 lbl_805DB598;
extern const f32 lbl_805DB5B8;
extern const f32 lbl_805DB5BC;
extern const f32 lbl_805DB5C0;
extern const f32 lbl_805DB5C4;
extern const f32 lbl_805DB5C8;
extern const f32 lbl_805DB5CC;
BmlResource *load_resource_from_descriptor(void *, s32, BmlResourceDescriptor *, s32, s32, s32);
extern DragonflyMotionSetup dragonfly_machine_attack_effect_params;
extern BmlResourceDescriptor TODragonflyMachine01__attack_effect_descriptor;
extern s32 dragonfly_machine_node_index;
extern s32 dragonfly_machine_node_yaw;
extern const f32 lbl_805DB5B0;
extern const f32 lbl_805DB5B4;
s32 play_sound_effect(s32, s32, s32, s32);
void TLobby__sub_8001FE7C(void *, int);
extern const f32 lbl_805DB59C;
extern const f32 lbl_805DB5A0;
extern const f32 lbl_805DB5A4;
extern const f32 lbl_805DB5A8;
extern const f32 lbl_805DB5AC;
s32 push_matrix();
s32 pop_matrix();
void translate_matrix(u32, f32, f32, f32);
s32 post_translate_matrix(Vec *);
s32 draw_ginja_model_with_motion(void *, AnimationMotion *, f32);
s32 rotate_matrix_y(s32, s32);
u8 *__ct__11TODragonflyFv(TODragonfly *);
}

void TODragonflyMachine01::update_yaw_animation() {
    s32 full_turn;
    f32 choice;
    switch (yaw_animation_state) {
    case 0:
        choice = lbl_805DB598 * (f32)rand();
        if (choice <= lbl_805DB59C) yaw_animation_state = 1;
        else if (choice <= lbl_805DB5A0) yaw_animation_state = 2;
        else if (choice <= lbl_805DB5A4) yaw_animation_state = 3;
        else if (choice <= lbl_805DB5A8) yaw_animation_state = 4;
        else yaw_animation_state = 5;
        break;
    case 1:
        animation_yaw += 0x97B;
        if (animation_yaw >= 0x238E) {
            animation_yaw = 0x238E;
            if (++yaw_animation_cycles < 4) yaw_animation_state = 2;
            else yaw_animation_state = 5;
        }
        break;
    case 2:
        animation_yaw -= 0x97B;
        if (animation_yaw <= -0x238E) {
            animation_yaw = -0x238E;
            if (++yaw_animation_cycles < 4) yaw_animation_state = 1;
            else yaw_animation_state = 5;
        }
        break;
    case 3:
        animation_yaw += 0x97B;
        full_turn = 0xFFFF;
        if (full_turn <= animation_yaw) {
            animation_yaw = full_turn;
            if (++yaw_animation_cycles < 1) yaw_animation_state = 4;
            else yaw_animation_state = 5;
        }
        break;
    case 4:
        animation_yaw -= 0x97B;
        if (animation_yaw <= -0xFFFF) {
            animation_yaw = -0xFFFF;
            if (++yaw_animation_cycles < 1) yaw_animation_state = 3;
            else yaw_animation_state = 5;
        }
        break;
    case 5:
        yaw_animation_state = 0;
        animation_yaw = 0;
        yaw_animation_cycles = 0;
        break;
    }
}

void TODragonflyMachine01::rotate_animated_node() {
    if (dragonfly_machine_node_index == 6) {
        rotate_matrix_y(0, dragonfly_machine_node_yaw);
    }
    dragonfly_machine_node_index += 1;
}

void TODragonflyMachine01::render() {
    if (update_object_view_visibility(m_c0, model_radius)) {
        push_matrix();
        translate_matrix(0, lbl_805DB5AC, bob_offset, lbl_805DB5AC);
        post_translate_matrix(&position);
        switch (yaw_animation_state) {
        case 3:
        case 4:
            rotate_matrix_y(0, rotation_y - animation_yaw);
            break;
        default:
            rotate_matrix_y(0, rotation_y);
            break;
        }
        TObjFish::set_global_param(texlist);
        dragonfly_machine_node_index = 0;
        dragonfly_machine_node_yaw = animation_yaw;
        TObjEneRe7Berura::set_global_state((s32)rotate_animated_node);
        draw_ginja_model_with_motion(model, motion, m_b0);
        TObjEneRe7Berura::set_global_state(0);
        pop_matrix();
    }
}

void TODragonflyMachine01::run_task() {
    this->m_fc = (s32) (this->m_fc + this->m_f8);
    bob_offset = (f32) (this->m_ec * sin_table_lookup(this->m_fc));
    if (TObjPlayer::check_demo_mode() == 1) {
        this->vfunc_14();
        return;
    }
    update_anim_phase();
    switch (this->m_ac) {
    case 0:
        update_yaw_animation();
        update_idle();
        return;
    case 1:
        sub_80164A90();
        return;
    case 2:
        update_yaw_animation();
        sub_80164990();
        return;
    case 3:
        move_toward_target();
        return;
    }
}

void *TODragonflyMachine01::create(void *arg0) {
    TODragonflyMachine01 *object = (TODragonflyMachine01 *)TObject::operator new(sizeof(TODragonflyMachine01));
    if (object != NULL) {
        object = object->initialize(arg0);
    }
    return object;
}

void TODragonflyMachine01::unload_static_data() {
    if (TODragonflyMachine01__model_resource != NULL) {
        TLobby__sub_8001FE7C(TODragonflyMachine01__model_resource, 1);
        TODragonflyMachine01__model_resource = NULL;
    }
}

void TODragonflyMachine01::create_attack_effect() {
    BmlResource *resource;
    s32 zero = 0;
    resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &TODragonflyMachine01__attack_effect_descriptor, 0, 0, 0);
    }
    TODragonflyMachine01__model_resource = resource;
    dragonfly_machine_node_index = zero;
    dragonfly_machine_node_yaw = zero;
    DragonflyMotionSetup setup = dragonfly_machine_attack_effect_params;
    setup.motions = resource->motions;
    TObjEneMe3Stelth::spawn_attack(0x38, resource->models->model, resource->models->m_c, (s32)&setup, lbl_805DB5B0, lbl_805DB5B4);
}

TODragonflyMachine01::~TODragonflyMachine01() {}

#pragma push
#pragma fp_contract on
TODragonflyMachine01 *TODragonflyMachine01::initialize(void *set_data) {
    __ct__11TODragonflyFv(this);
    *(s32 **)((u8 *)this + 0x18) = __vt__20TODragonflyMachine01;
    m_name = TODragonflyMachine01__class_name;
    apply_object_set_data(set_data);
    model = (NJS_OBJECT *)TODragonflyMachine01__model_resource->models->model;
    texlist = TODragonflyMachine01__model_resource->models->m_c;
    motion = TODragonflyMachine01__model_resource->motions->motion;
    animation_end_frame = (f32)motion->frameCount - lbl_805DB5B8;
    m_b8 = (f32) lbl_805DB5B8;
    m_c0 = (f32) lbl_805DB5BC;
    model_radius = ((DragonflyModelBounds *)((NJS_OBJECT *)model)->model)->radius;
    m_ac = 0;
    m_f4 = (f32) ((lbl_805DB5C0 * (f32) set_params[0]) + lbl_805DB5B8);
    m_f8 = (int) (lbl_805DB5C4 * (lbl_805DB5C8 / (lbl_805DB5CC / m_f4)));
    m_fc = (int) (lbl_805DB5C4 * (lbl_805DB5C8 * (lbl_805DB598 * (f32) rand())));
    m_ec = (f32) ((lbl_805DB5C0 * (f32) set_params[1]) + lbl_805DB5B8);
    bob_offset = (f32) (m_ec * sin_table_lookup(m_fc));
    yaw_animation_state = 0;
    yaw_animation_cycles = 0;
    animation_yaw = 0;
    return this;
}
#pragma pop

void TODummyKeyCave01Sound::play_cave01_key_sound() {
    s32 area;
    s32 temp_r3_2;

    switch (sound_kind) {
    case 1:
        play_sound_effect(0x4005281F, 0, 0, 0);
        return;
    case 2:
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    case 3:
        area = get_current_floor_area();
        if ((area != AREA_BATTLE1) && (area != AREA_BATTLE2)) {
            play_sound_effect(0x52812, 0, 0, 0);
            return;
        }
        break;
    case 4:
        temp_r3_2 = get_current_floor_area();
        if ((temp_r3_2 != AREA_BATTLE1) && (temp_r3_2 != AREA_BATTLE2)) {
            play_sound_effect(0x52813, 0, 0, 0);
            return;
        }
        break;
    case 5:
        play_sound_effect(0x4001C112, 0, 0, 0);
        return;
    case 6:
        play_sound_effect(0x4002A60B, 0, 0, 0);
        break;
    }
}
