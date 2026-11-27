#include "clib/fp_convert.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/TriangleFan3D.h"
#include "pso/render/Draw2D.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/ui/frontend/TAdRicoRingCtrl.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/render/DebugFont.h"
#include "pso/render/ProjectedStripDraw.h"

BmlResource *TAdRicoRing::resource_bundle;
f32 rico_ring_quad_x_min;
s8 rico_ring_quad_x_min_ready;
f32 rico_ring_quad_x_max;
s8 rico_ring_quad_x_max_ready;
f32 rico_ring_quad_y_bottom;
s8 rico_ring_quad_y_bottom_ready;
f32 rico_ring_quad_y_top;
s8 rico_ring_quad_y_top_ready;
f32 rico_ring_quad_z_near;
s8 rico_ring_quad_z_near_ready;
f32 rico_ring_quad_z_far;
s8 rico_ring_quad_z_far_ready;
s8 rico_ring_quad_vertices_ready;

const char *rico_ring_model_names[2] = { "rico_ring.nj", NULL };
const char *rico_ring_motion_names[2] = { "rico_ring.njm", NULL };
BmlResourceDescriptor TAdRicoRingCtrl::resource_descriptor = {
    "rico_ring.bml", rico_ring_model_names, rico_ring_motion_names, 1, 1,
};
// inferred: vertex colours, corners and quad of the ring sprite TAdRicoRingCtrl::render draws in 3D
u32 rico_ring_quad_colors[4] = { 0xB0, 0xB0, 0xB0, 0xB0 };
NJS_POINT3 rico_ring_quad_vertices[4] = { 0.0f };
NJS_POINT3COL rico_ring_quad = { rico_ring_quad_vertices, rico_ring_quad_colors, NULL, 4 };
// inferred: the screen rectangle and colours of the fade TAdRicoRingCtrl::render draws in 2D
NJS_POINT2 rico_ring_fade_positions[4] = {
    {350.0f, 0.0f}, {640.0f, 0.0f}, {640.0f, 600.0f}, {350.0f, 600.0f},
};
NJS_COLOR rico_ring_fade_colors[4];
const char *TAdRicoRing::class_name = "TAdRicoRing";
const char *TAdRicoRingCtrl::class_name = "TAdRicoRingCtrl";

// Definitions use deferred emission order, including the two native vtables.
void TAdRicoRing::set_target_scale(f32 value) {
    target_scale = value;
}

void TAdRicoRingCtrl::load_static_resource() {
    TAdRicoRing::resource_bundle = new BmlResource(1, &TAdRicoRingCtrl::resource_descriptor, 0, 0, NULL);
}

void TAdRicoRingCtrl::release_static_resource() {
    if (TAdRicoRing::resource_bundle != NULL) {
        delete TAdRicoRing::resource_bundle;
        TAdRicoRing::resource_bundle = NULL;
    }
}

TAdRicoRing *TAdRicoRingCtrl::create(TObject *parent) {
    return new TAdRicoRing(parent);
}

TAdRicoRing::TAdRicoRing(TObject *parent) : TObject(parent) {
    m_name = TAdRicoRing::class_name;
    model = get_bml_model(TAdRicoRing::resource_bundle, 0);
    textures = get_bml_texlist(TAdRicoRing::resource_bundle, 0);
    scale[3] = 0.0f;
    scale[2] = 0.0f;
    scale[1] = 0.0f;
    scale[0] = 0.0f;
    scale_step[3] = 0.0f;
    scale_step[2] = 0.0f;
    scale_step[1] = 0.0f;
    scale_step[0] = 0.0f;
    position.z = 0.0f;
    position.y = 0.0f;
    position.x = 0.0f;
    angles[2] = 0;
    angles[1] = 0;
    angles[0] = 0;
    target_scale = 0.0f;
    angular_velocity = 0x5B0;
    flags.set(4);
    switch (get_video_standard()) {
    case 0: angular_acceleration = 0x12; break;
    case 1: angular_acceleration = 0x15; break;
    }
}

TAdRicoRing::~TAdRicoRing() {}

void TAdRicoRing::run_task() {
    if (flags.test_flags_any(1) != 0) {
        update_position();
        if (scale[0] <= -1.0f) {
            queue_destruction();
            return;
        }
    }
    if (flags.test_flags_any(2) != 0) {
        update_position();
        f32 limit = target_scale;
        if (limit <= scale[0]) {
            scale[0] = limit;
            scale[3] = 0.0f;
            scale[2] = 0.0f;
            scale[1] = 0.0f;
            flags.clear(2);
        }
    }
    angles[1] += angular_velocity;
    if (flags.test_flags_any(4) != 0) {
        angular_velocity += angular_acceleration;
        if (angular_velocity >= 0xCCC) {
            flags.clear(4);
        }
    } else {
        angular_velocity -= angular_acceleration;
        if (angular_velocity <= 0x5B0) {
            flags.set(4);
        }
    }
}

void TAdRicoRing::update_position() {
    scale[0] += scale_step[0];
    scale[1] += scale_step[1];
    scale[2] = scale[1];
    scale[3] = scale[1];
}

void TAdRicoRing::set_scale4(f32 value) {
    scale[0] = value;
    scale[1] = value;
    scale[2] = value;
    scale[3] = value;
}

void TAdRicoRing::render() {
    push_matrix();
    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(textures));
    post_translate_matrix(&position.x);
    rotate_matrix_zyx(NULL, angles[0], angles[1], angles[2]);
    set_chunk_render_flags(1);
    draw_chunk_object(model);
    set_chunk_render_flags(2);
    draw_chunk_object(model);
    clear_chunk_render_flags();
    pop_matrix();
}

void TAdRicoRing::start_anim(f32 duration) {
    f32 step;

    if (flags.test_flags_any(2) != 0) {
        flags.clear(2);
    }
    flags.set(1);
    if (0.0f != duration) {
        scale_step[0] = (-1.0f - scale[0]) / duration;
        step = (-1.0f - scale[1]) / duration;
        scale_step[1] = step;
        scale_step[2] = step;
        scale_step[3] = step;
    }
}

void TAdRicoRing::start_fade(f32 duration) {
    f32 step;

    if (flags.test_flags_any(1) != 0) {
        flags.clear(1);
    }
    flags.set(2);
    if (0.0f != duration) {
        scale_step[0] = (target_scale - scale[0]) / duration;
        step = (target_scale - scale[1]) / duration;
        scale_step[1] = step;
        scale_step[2] = step;
        scale_step[3] = step;
    }
}

TAdRicoRingCtrl::TAdRicoRingCtrl(TObject *parent) : TObject(parent) {
    m_name = TAdRicoRingCtrl::class_name;
    rings[0] = create(tl_04);
    TAdRicoRing *ring = rings[0];
    if (ring != NULL) {
        ring->set_target_scale(0.0f);
        rings[0]->set_scale4(0.0f);
    }
    rings[1] = create(tl_04);
    ring = rings[1];
    if (ring != NULL) {
        ring->set_target_scale(0.0f);
        rings[1]->set_scale4(0.0f);
    }
    fade = 1.0f;
    fade_step = 0.0f;
    Vec point = { 1.8f, 0.3f, -5.0f };
    set_position(&point);
}

TAdRicoRingCtrl::~TAdRicoRingCtrl() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (rings[i] != NULL) {
            rings[i]->queue_destruction();
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TAdRicoRingCtrl::run_task() {
    f32 value;
    fade += fade_step;
    value = fade;
    if (value < 0.0f) {
        fade = 0.0f;
        return;
    }
    if (value > 1.0f) {
        fade = 1.0f;
    }
}
#pragma pop

// inferred: the ring's base position the fade corners are laid out from
const f32 rico_ring_base_pos[3] = { 1.8f, 0.3f, -5.0f };

#pragma push
#pragma opt_common_subs off
void TAdRicoRingCtrl::render() {
    f32 t = fade;
    if (t >= 1.0f) {
        return;
    }
    if (rico_ring_quad_x_min_ready == 0) {
        rico_ring_quad_x_min_ready = 1;
        rico_ring_quad_x_min = rico_ring_base_pos[0] - 50.0f;
    }
    if (rico_ring_quad_x_max_ready == 0) {
        rico_ring_quad_x_max_ready = 1;
        rico_ring_quad_x_max = 50.0f + rico_ring_base_pos[0];
    }
    if (rico_ring_quad_y_bottom_ready == 0) {
        rico_ring_quad_y_bottom_ready = 1;
        rico_ring_quad_y_bottom = -8.75f + (rico_ring_base_pos[1] - 1.0f);
    }
    if (rico_ring_quad_y_top_ready == 0) {
        rico_ring_quad_y_top_ready = 1;
        rico_ring_quad_y_top = 0.025f + (rico_ring_base_pos[1] - 1.0f);
    }
    if (rico_ring_quad_z_near_ready == 0) {
        rico_ring_quad_z_near_ready = 1;
        rico_ring_quad_z_near = rico_ring_base_pos[2];
    }
    if (rico_ring_quad_z_far_ready == 0) {
        rico_ring_quad_z_far_ready = 1;
        rico_ring_quad_z_far = 50.0f + rico_ring_base_pos[2];
    }
    if (rico_ring_quad_vertices_ready == 0) {
        f32 b = rico_ring_quad_y_top;
        f32 c = rico_ring_quad_z_near;
        f32 d = rico_ring_quad_x_max;
        f32 a = rico_ring_quad_x_min;
        f32 e = rico_ring_quad_y_bottom;
        f32 g = rico_ring_quad_z_far;
        f32 *v = (f32 *)rico_ring_quad_vertices;
        v[0] = a;
        v[1] = b;
        v[2] = c;
        v[3] = d;
        v[4] = b;
        v[5] = c;
        v[6] = d;
        v[7] = e;
        v[8] = g;
        v[9] = a;
        v[10] = e;
        v[11] = g;
        rico_ring_quad_vertices_ready = 1;
    }
    draw_tri_fan_3d(&rico_ring_quad, 4, 6);
    t = fade;
    if (t > 0.0f) {
        NJS_POINT2COL args = { rico_ring_fade_positions, rico_ring_fade_colors, NULL, 4 };
        u32 cnt = (u32)(255.0f * t);
        s32 i;
        for (i = 0; i < 4; i++) {
            rico_ring_fade_colors[i].color = cnt;
        }
        draw_polygon_2d(&args, 4, 6, -2.0f);
    }
}
#pragma pop

void TAdRicoRingCtrl::start_fade_all(f32 duration) {
    s32 i;
    for (i = 0; i != 2; i++) {
        if (rings[i] != NULL) {
            rings[i]->start_fade(duration);
        }
    }
    if (0.0f != duration) {
        fade_step = -1.0f / duration;
    }
}

void TAdRicoRingCtrl::start_rings_anim(f32 duration) {
    s32 i;
    for (i = 0; i != 2; i++) {
        if (rings[i] != NULL) {
            rings[i]->start_anim(duration);
            rings[i] = NULL;
        }
    }
    f32 t = 2.0f + duration;
    if (0.0f != t) {
        fade_step = 1.0f / t;
    }
}

#pragma push
#pragma fp_contract on
void TAdRicoRingCtrl::set_position(const Vec *point) {
    if (point != NULL) {
        TAdRicoRing *ring = rings[0];
        if (ring != NULL) {
            VecCopy(&ring->position, point);
        }
        ring = rings[1];
        if (ring != NULL) {
            VecCopy(&ring->position, point);
            ring = rings[1];
            ring->position.y = -(2.0f * ((NJS_CNK_MODEL *)ring->model->model)->r - ring->position.y);
        }
    }
}
#pragma pop
