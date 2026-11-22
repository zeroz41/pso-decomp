#include "pso/system/TrailStrip.h"
#include "pso/system/MatrixStack.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/barbaray/TObjBoss7Dust.h"
#include "pso/boss/barbaray/TObjBoss7DustCtrl.h"
#include "pso/boss/barbaray/TObjBoss7Tunnel.h"
#include "pso/unk/text_802F0E24.h"
#include "pso/system/vector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"

#include "types.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D853C.h"

// TObjBoss7DustCtrl and TObjBoss7Dust share one TU, built deferred and written from the unit's last
// function back: Dust's code comes first in .text, yet DustCtrl's class name precedes Dust's in .sdata
// and .rodata, and Dust's vtable precedes DustCtrl's in .data (reverse key-function order).

Vec TObjBoss7DustCtrl__helix_points[6];
s32 TObjBoss7DustCtrl__rotation_pairs[20];
TrailStripVertex TObjBoss7DustCtrl__transformed_vertices[60];
s32 TObjBoss7DustCtrl__vertical_phase_angles[10];

const char *TObjBoss7DustCtrl__name = "TObjBoss7DustCtrl";
const char *TObjBoss7Dust__name = "TObjBoss7Dust";

s32 TObjBoss7DustCtrl_dust_counter;

void TObjBoss7DustCtrl::init_strips() {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        int a = (int)(10922.667f * (f32)i);
        f32 sine = sin_table_lookup(a);
        TObjBoss7DustCtrl__helix_points[i].x = 0.7f * sine;
        TObjBoss7DustCtrl__helix_points[i].y = 0.083333336f * (f32)i;
        TObjBoss7DustCtrl__helix_points[i].z = 0.7f * cos_table_lookup(a);
    }
    {
        s32 *p = TObjBoss7DustCtrl__rotation_pairs;
        for (i = 0; i < 20; i++) {
            *p++ = TObjPlayer::calc_random_scaled();
        }
    }
    {
        TrailStripVertex *o = TObjBoss7DustCtrl__transformed_vertices;
        for (i = 0; i < 60; i++) {
            o->x = 0.0f;
            o->y = 0.0f;
            o->z = 0.0f;
            o->color = 0xFF709070;
            o++;
        }
    }
    for (j = 0; j < 10; j++) {
        TObjBoss7DustCtrl__vertical_phase_angles[j] = TObjPlayer::calc_random_scaled();
    }
    TObjBoss7DustCtrl_dust_counter = 0;
}

void TObjBoss7DustCtrl::free_strips() {}

void TObjBoss7DustCtrl::create() {
    new TObjBoss7DustCtrl(tl_05);
}

TObjBoss7DustCtrl::TObjBoss7DustCtrl(TObject *parent) : TObject(parent) {
    m_name = TObjBoss7DustCtrl__name;
}

TObjBoss7DustCtrl::~TObjBoss7DustCtrl() {}

#pragma push
#pragma opt_propagation off
void TObjBoss7DustCtrl::run_task() {
    s32 *ang;
    TrailStripVertex *out;
    s32 *rot;
    s32 i;
    s32 j;

    rot = TObjBoss7DustCtrl__rotation_pairs;
    out = TObjBoss7DustCtrl__transformed_vertices;
    push_matrix();
    ang = TObjBoss7DustCtrl__vertical_phase_angles;
    for (i = 0; i < 10; i++) {
        set_matrix_identity(0);
        translate_matrix(0, 0.0f, 6.0f * sin_table_lookup(ang[i]), 0.0f);
        {
            s32 a = ang[i];
            s32 r;
            *rot += 0x1333;
            r = *rot++;
            ang[i] = a + 0x800;
            rotate_matrix_x(0, r);
        }
        *rot += 0x555;
        rotate_matrix_x(0, *rot++);
        for (j = 0; j < 6; j++) {
            matrix_mult_vec(NULL, &TObjBoss7DustCtrl__helix_points[j], (Vec *)out++);
        }
    }
    pop_matrix();
}
#pragma pop

s32 TObjBoss7DustCtrl::next_strip_slot() {
    s32 index = TObjBoss7DustCtrl_dust_counter;

    TObjBoss7DustCtrl_dust_counter = index + 1;
    if (index + 1 >= 0xA) {
        TObjBoss7DustCtrl_dust_counter = 0;
    }
    return index;
}

void boss7_dust_draw_at(const Vec *position, s32 slot) {
    TParticleCtrl::end_effect_render();
    push_matrix();
    post_translate_matrix(&position->x);
    draw_trail_strip(&TObjBoss7DustCtrl__transformed_vertices[slot * 6], 6, 0);
    pop_matrix();
}

TObjBoss7Dust::TObjBoss7Dust(TObject *parent, const Vec *position) : TObject(parent) {
    m_name = TObjBoss7Dust__name;
    VecCopy(&this->position, position);
    ticks = 0;
    strip_slot = TObjBoss7DustCtrl::next_strip_slot();
}

TObjBoss7Dust::~TObjBoss7Dust() {}

void TObjBoss7Dust::run_task() {
    position.z -= boss7_tunnel_max_scroll_speed;
    ticks++;
    if (ticks >= 90) {
        queue_destruction();
    }
}

void TObjBoss7Dust::render() { boss7_dust_draw_at(&position, strip_slot); }

void init_scene_boss2_tunnel(void) { load_boss7_common_resources(); TObjBoss7Tunnel::clear_state_flags(); TObjBoss7DustCtrl::init_strips(); }

void create_boss7_tunnel(void) { TObjBoss7Tunnel::create(); TObjBoss7Tunnel::create_parent_object(); TObjBoss7DustCtrl::create(); }
void free_boss7_tunnel(void) { TObjBoss7DustCtrl::free_strips(); TObjBoss7Tunnel::sub_802F2C4C(); free_boss7_common_resources(); }
