#include "pso/system/BmlAccessors.h"
// The bridges: TObjHashiBase and its three set objects TObjHashi,
// TObjHashiVersus1 and TObjHashiVersus2, and the packet 6x78 slot timers.
//
// Built -inline off,deferred: the functions come out last to first, so the
// file is written from the end of the unit's .text back.
#include "types.h"
#include "pso/object/TObjHashi.h"
#include "pso/object/TObjHashiVersus1.h"
#include "pso/object/TObjHashiVersus2.h"
#include "pso/system/task/TMainTask.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/render/TextureState.h"
#include "pso/object/collision/TObjInfoCol.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/DebugFont.h"
#include "pso/math/MatrixReflect.h"

// The unit's .sdata2 float pool is still referenced
// from the DOL: CW pools these in the order the functions need them, and no
// source arrangement found yet gives the original order 120, 400, 40, 0, 640,
// 0.15, 30 (written source gives 120, 0, 640, 400, 40, 0.15, 30).
extern const f32 hashi_versus2_model_radius; // TObjHashiVersus2's model radius
extern const f32 hashi_view_depth;
extern const f32 hashi_model_radius;
extern const f32 hashi_zero;
extern const f32 hashi_screen_width;
extern const f32 hashi_rise_speed;
extern const f32 hashi_start_drop; // how far below its raised height it starts

__declspec(section ".data") const char *fe_obj_hashi_model_names[2] = { "fe_obj_hashi.gj", NULL };
__declspec(section ".sdata") const char *fe_obj_hashi_motion_names[1] = { NULL };
BmlResourceDescriptor fe_obj_hashi_resource_descriptor = {
    "fe_obj_hashi.bml", fe_obj_hashi_model_names, fe_obj_hashi_motion_names, 1, 0
};
__declspec(section ".data") const char *fe_obj306_hashi_model_names[2] = { "fe_obj306_hashi.gj", NULL };
__declspec(section ".sdata") const char *fe_obj306_hashi_motion_names[1] = { NULL };
BmlResourceDescriptor fe_obj306_hashi_resource_descriptor = {
    "fe_obj306_hashi.bml", fe_obj306_hashi_model_names, fe_obj306_hashi_motion_names, 1, 0
};
__declspec(section ".data") const char *fe_obj321_hashi_model_names[2] = { "fe_obj321_hashi.gj", NULL };
__declspec(section ".sdata") const char *fe_obj321_hashi_motion_names[1] = { NULL };
BmlResourceDescriptor fe_obj321_hashi_resource_descriptor = {
    "fe_obj321_hashi.bml", fe_obj321_hashi_model_names, fe_obj321_hashi_motion_names, 1, 0
};

const char *TObjHashiBase::class_name = "TObjHashiBase";
const char *TObjHashi::class_name = "TObjHashi";
const char *TObjHashiVersus1::class_name = "TObjHashiVersus1";
const char *TObjHashiVersus2::class_name = "TObjHashiVersus2";

// Boxes 9 deep and 40 wide along the bridge.
CollisionBody hashi_collision_bodies[1] = {
    { { 0.0f, 0.0f, 30.0f }, 9.0f, 40.0f, 1, 0x10003 },
};
CollisionBody hashi_versus1_collision_bodies[2] = {
    { { 0.0f, 0.0f, 15.0f }, 9.0f, 40.0f, 1, 0x10003 },
    { { 0.0f, 0.0f, -15.0f }, 9.0f, 40.0f, 1, 0x10003 },
};
CollisionBody hashi_versus2_collision_bodies[2] = {
    { { 0.0f, 0.0f, 55.0f }, 9.0f, 40.0f, 1, 0x10003 },
    { { 0.0f, 0.0f, -55.0f }, 9.0f, 40.0f, 1, 0x10003 },
};

BmlResource *TObjHashi::bml_resource;
BmlResource *TObjHashiVersus1::bml_resource;
BmlResource *TObjHashiVersus2::bml_resource;

static s32 handle_6x78_entries[12];

void start_handle_6x78_entry(u16 index) {
    if (index < 12) {
        handle_6x78_entries[index] = 300;
    }
}

s32 get_handle_6x78_entry(u16 index) {
    if (index >= 12) {
        return 0;
    }
    return handle_6x78_entries[index];
}

void set_handle_6x78_entry(u16 index, s32 value) {
    if (index < 12) {
        handle_6x78_entries[index] = value;
    }
}

void handle_6x78(G_Unknown_6x78 *cmd) {
    cmd->bswap();
    if (get_handle_6x78_entry(cmd->client_id) != 0) {
        set_handle_6x78_entry(cmd->client_id, 0);
        return;
    }
    start_handle_6x78_entry(cmd->client_id);
}

TObjHashiBase::TObjHashiBase(TObject *parent, ObjectSetData *set_data) : TObjMapObject(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    switchId = set_params[0];
    view_range = hashi_view_depth;
    model_radius = hashi_model_radius;
    if (is_current_floor_switch_set((u16)switchId) == 1) {
        object_state = 2;
        raisedHeight = position.y;
        riseSpeed = hashi_rise_speed;
    } else {
        object_state = 0;
        raisedHeight = position.y;
        position.y = position.y - hashi_start_drop;
        riseSpeed = hashi_rise_speed;
    }
}


TObjHashiBase::~TObjHashiBase() {}

void TObjHashiBase::run_task() {
    f32 height;
    s32 index;
    switch (object_state) {
    case 0:
        if (is_current_floor_switch_set((u16)switchId) != 0) {
            object_state = 1;
            return;
        }
        break;
    case 1:
        position.y = position.y + riseSpeed;
        if (position.y > (height = raisedHeight)) {
            position.y = height;
            object_state = 2;
            return;
        }
        break;
    case 2:
        index = 0;
        while (index < body_count) {
            set_indexed_flags(index, 8);
            ++index;
        }
        object_state = 3;
        break;
    case 3:
        break;
    }
}

void TObjHashiBase::render() {
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation.y);
        set_texture_list(texlist);
        if (motion != NULL) {
            draw_model_motion(model, motion, animation_frame);
        } else {
            draw_ginja_object(model);
        }
        pop_matrix();
    }
}


// Kept from the old unit: with the pool constants read through their DOL
// symbols (above), common-subexpression elimination keeps 0.0f in a different
// register; with literals the function matches without it.
#pragma push
#pragma opt_common_subs off
s32 TObjHashiBase::update_object_view_visibility(f32 depth, f32 radius) {
    f32 screen[2];
    Vec view;
    if (TMainTask::get_render_pass() == 1) {
        return visibility;
    }
    if (xz_distance_squared((const Vec *)&camera_ctrl_instance->pos.x, &position) < (radius * radius)) {
        visibility = 1;
        return 1;
    }
    matrix_mult_vec(NULL, &position, &view);
    if (view.z > hashi_zero) {
        visibility = 0;
        return 0;
    }
    if (view.z < -depth) {
        visibility = 0;
        return 0;
    }
    if (view.x < hashi_zero) {
        view.x = (camera_right.x * radius) + position.x;
        view.y = (camera_right.y * radius) + position.y;
        view.z = (camera_right.z * radius) + position.z;
        project_world_to_screen(NULL, &view, screen);
        if (screen[0] < hashi_zero) {
            visibility = 0;
            return 0;
        }
    } else {
        view.x = -((camera_right.x * radius) - position.x);
        view.y = -((camera_right.y * radius) - position.y);
        view.z = -((camera_right.z * radius) - position.z);
        project_world_to_screen(NULL, &view, screen);
        if (screen[0] > hashi_screen_width) {
            visibility = 0;
            return 0;
        }
    }
    visibility = 1;
    return 1;
}
#pragma pop

TObjHashi::TObjHashi(TObject *parent, ObjectSetData *set_data) : TObjHashiBase(parent, set_data) {
    m_name = class_name;
    model = get_bml_model(bml_resource, 0);
    texlist = get_bml_texlist(bml_resource, 0);
    init_collision_body_parts(this, hashi_collision_bodies, 1);
    actorFlags |= 0x40000000;
    register_object_by_id();
}

TObjHashi::~TObjHashi() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjHashi::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &fe_obj_hashi_resource_descriptor, 0, 0, NULL);
    bml_resource = resource;
}

void TObjHashi::unload_static_data() {
    if (bml_resource != NULL) {
        delete (BmlResource *)bml_resource;
        bml_resource = NULL;
    }
}

void *TObjHashi::create(ObjectSetData *set_data) {
    return new TObjHashi(tl_05, set_data);
}

TObjHashiVersus1::TObjHashiVersus1(TObject *parent, ObjectSetData *set_data) : TObjHashiBase(parent, set_data) {
    m_name = class_name;
    if (is_current_floor_switch_set((u16)switchId) == 0) {
        position.y = position.y - scale.x;
    }
    riseSpeed = scale.y;
    model = get_bml_model(bml_resource, 0);
    texlist = get_bml_texlist(bml_resource, 0);
    init_collision_body_parts(this, hashi_versus1_collision_bodies, 2);
    actorFlags |= 0x40000000;
    register_object_by_id();
}

TObjHashiVersus1::~TObjHashiVersus1() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjHashiVersus1::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &fe_obj306_hashi_resource_descriptor, 0, 0, NULL);
    bml_resource = resource;
}

void TObjHashiVersus1::unload_static_data() {
    if (bml_resource != NULL) {
        delete (BmlResource *)bml_resource;
        bml_resource = NULL;
    }
}

void *TObjHashiVersus1::create(ObjectSetData *set_data) {
    return new TObjHashiVersus1(tl_05, set_data);
}

TObjHashiVersus2::TObjHashiVersus2(TObject *parent, ObjectSetData *set_data) : TObjHashiBase(parent, set_data) {
    m_name = class_name;
    if (is_current_floor_switch_set((u16)switchId) == 0) {
        position.y = position.y - scale.x;
    }
    riseSpeed = scale.y;
    model_radius = hashi_versus2_model_radius;
    model = get_bml_model(bml_resource, 0);
    texlist = get_bml_texlist(bml_resource, 0);
    init_collision_body_parts(this, hashi_versus2_collision_bodies, 2);
    actorFlags |= 0x40000000;
    register_object_by_id();
}

TObjHashiVersus2::~TObjHashiVersus2() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjHashiVersus2::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &fe_obj321_hashi_resource_descriptor, 0, 0, NULL);
    bml_resource = resource;
}

void TObjHashiVersus2::unload_static_data() {
    if (bml_resource != NULL) {
        delete (BmlResource *)bml_resource;
        bml_resource = NULL;
    }
}

void *TObjHashiVersus2::create(ObjectSetData *set_data) {
    return new TObjHashiVersus2(tl_05, set_data);
}

extern const f32 hashi_versus2_model_radius = 120.0f;
extern const f32 hashi_view_depth = 400.0f;
extern const f32 hashi_model_radius = 40.0f;
extern const f32 hashi_zero = 0.0f;
extern const f32 hashi_screen_width = 640.0f;
extern const f32 hashi_rise_speed = 0.15f;
extern const f32 hashi_start_drop = 30.0f;
