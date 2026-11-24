#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/TriangleFan3D.h"
#include "pso/render/Draw2D.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/ui/frontend/TAdRicoRingCtrl.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803E2D70.h"

extern "C" {
extern TObject *tl_04;
BmlResource *TAdRicoRing__resource_bundle;
f32 lbl_805D4A04;
s8 lbl_805D4A08;
f32 lbl_805D4A0C;
s8 lbl_805D4A10;
f32 lbl_805D4A14;
s8 lbl_805D4A18;
f32 lbl_805D4A1C;
s8 lbl_805D4A20;
f32 lbl_805D4A24;
s8 lbl_805D4A28;
f32 lbl_805D4A2C;
s8 lbl_805D4A30;
s8 lbl_805D4A31;
u32 __cvt_fp2unsigned(f32);
}

const char *rico_ring_model_names[2] = { "rico_ring.nj", NULL };
const char *rico_ring_motion_names[2] = { "rico_ring.njm", NULL };
BmlResourceDescriptor TAdRicoRingCtrl__resource_descriptor = {
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
const char *TAdRicoRing__class_name = "TAdRicoRing";
const char *TAdRicoRingCtrl__class_name = "TAdRicoRingCtrl";

// Definitions use deferred emission order, including the two native vtables.
void TAdRicoRing::sub_8001BED0(f32 value) {
    target_scale = value;
}

void TAdRicoRingCtrl::load_static_resource() {
    TAdRicoRing__resource_bundle = new BmlResource(1, &TAdRicoRingCtrl__resource_descriptor, 0, 0, NULL);
}

void TAdRicoRingCtrl::release_global_805D4A00() {
    if (TAdRicoRing__resource_bundle != NULL) {
        delete TAdRicoRing__resource_bundle;
        TAdRicoRing__resource_bundle = NULL;
    }
}

TAdRicoRing *TAdRicoRingCtrl::create(TObject *parent) {
    return new TAdRicoRing(parent);
}

TAdRicoRing::TAdRicoRing(TObject *parent) : TObject(parent) {
    m_name = TAdRicoRing__class_name;
    model = get_bml_model(TAdRicoRing__resource_bundle, 0);
    textures = get_bml_texlist(TAdRicoRing__resource_bundle, 0);
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
    switch (TKeyBoardControl__sub_8000F828()) {
    case 0: angular_acceleration = 0x12; break;
    case 1: angular_acceleration = 0x15; break;
    }
}

TAdRicoRing::~TAdRicoRing() {}

void TAdRicoRing::run_task() {
    if (test_flags_any(&flags.bits, 1) != 0) {
        update_position();
        if (scale[0] <= -1.0f) {
            queue_destruction();
            return;
        }
    }
    if (test_flags_any(&flags.bits, 2) != 0) {
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
    if (test_flags_any(&flags.bits, 4) != 0) {
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
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(textures));
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

    if (test_flags_any(&flags.bits, 2) != 0) {
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

    if (test_flags_any(&flags.bits, 1) != 0) {
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
    m_name = TAdRicoRingCtrl__class_name;
    rings[0] = create(tl_04);
    TAdRicoRing *ring = rings[0];
    if (ring != NULL) {
        ring->sub_8001BED0(0.0f);
        rings[0]->set_scale4(0.0f);
    }
    rings[1] = create(tl_04);
    ring = rings[1];
    if (ring != NULL) {
        ring->sub_8001BED0(0.0f);
        rings[1]->set_scale4(0.0f);
    }
    fade = 1.0f;
    fade_step = 0.0f;
    Vec point = { 1.8f, 0.3f, -5.0f };
    sub_8001B424(&point);
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
    if (lbl_805D4A08 == 0) {
        lbl_805D4A08 = 1;
        lbl_805D4A04 = rico_ring_base_pos[0] - 50.0f;
    }
    if (lbl_805D4A10 == 0) {
        lbl_805D4A10 = 1;
        lbl_805D4A0C = 50.0f + rico_ring_base_pos[0];
    }
    if (lbl_805D4A18 == 0) {
        lbl_805D4A18 = 1;
        lbl_805D4A14 = -8.75f + (rico_ring_base_pos[1] - 1.0f);
    }
    if (lbl_805D4A20 == 0) {
        lbl_805D4A20 = 1;
        lbl_805D4A1C = 0.025f + (rico_ring_base_pos[1] - 1.0f);
    }
    if (lbl_805D4A28 == 0) {
        lbl_805D4A28 = 1;
        lbl_805D4A24 = rico_ring_base_pos[2];
    }
    if (lbl_805D4A30 == 0) {
        lbl_805D4A30 = 1;
        lbl_805D4A2C = 50.0f + rico_ring_base_pos[2];
    }
    if (lbl_805D4A31 == 0) {
        f32 b = lbl_805D4A1C;
        f32 c = lbl_805D4A24;
        f32 d = lbl_805D4A0C;
        f32 a = lbl_805D4A04;
        f32 e = lbl_805D4A14;
        f32 g = lbl_805D4A2C;
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
        lbl_805D4A31 = 1;
    }
    draw_tri_fan_3d(&rico_ring_quad, 4, 6);
    t = fade;
    if (t > 0.0f) {
        NJS_POINT2COL args = { rico_ring_fade_positions, rico_ring_fade_colors, NULL, 4 };
        u32 cnt = __cvt_fp2unsigned(255.0f * t);
        s32 i;
        for (i = 0; i < 4; i++) {
            rico_ring_fade_colors[i].color = cnt;
        }
        draw_polygon_2d(&args, 4, 6, -2.0f);
    }
}
#pragma pop

void TAdRicoRingCtrl::start_fade_all(f32 x) {
    s32 i;
    for (i = 0; i != 2; i++) {
        if (rings[i] != NULL) {
            rings[i]->start_fade(x);
        }
    }
    if (0.0f != x) {
        fade_step = -1.0f / x;
    }
}

void TAdRicoRingCtrl::sub_8001B4A0(f32 x) {
    s32 i;
    for (i = 0; i != 2; i++) {
        if (rings[i] != NULL) {
            rings[i]->start_anim(x);
            rings[i] = NULL;
        }
    }
    f32 t = 2.0f + x;
    if (0.0f != t) {
        fade_step = 1.0f / t;
    }
}

#pragma push
#pragma fp_contract on
void TAdRicoRingCtrl::sub_8001B424(const Vec *point) {
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
