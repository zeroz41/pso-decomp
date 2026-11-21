#include "pso/system/TrailStrip.h"
#include "pso/system/MatrixStack.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/barbaray/TObjBoss7Dust.h"
#include "pso/boss/barbaray/TObjBoss7DustCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_802F1A58.h"
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

// TObjBoss7DustCtrl and TObjBoss7Dust share one TU, built deferred and written from the unit's last
// function back: Dust's code comes first in .text, yet DustCtrl's class name precedes Dust's in .sdata
// and .rodata, and Dust's vtable precedes DustCtrl's in .data (reverse key-function order).

struct RecoveredGlobal_802F119C___vt__13TObjBoss7Dust {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {

void __ct__7TObjectFP7TObject(void *, void *);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int, f32);
void matrix_mult_vec(s32, Vec *, TrailStripVertex *);
Vec TObjBoss7DustCtrl__helix_points[6];
s32 TObjBoss7DustCtrl__rotation_pairs[20];
TrailStripVertex TObjBoss7DustCtrl__transformed_vertices[60];
s32 TObjBoss7DustCtrl__vertical_phase_angles[10];
extern const f32 lbl_805DEC70;
extern const f32 lbl_805DEC74;
extern const f32 lbl_805DEC78;
extern const f32 lbl_805DEC7C;
extern const f32 lbl_805DEC80;
extern s32 __vt__17TObjBoss7DustCtrl[];
extern RecoveredGlobal_802F119C___vt__13TObjBoss7Dust __vt__13TObjBoss7Dust;
void fn_802F19C0(void);
}

const char *TObjBoss7DustCtrl__name = "TObjBoss7DustCtrl";
const char *TObjBoss7Dust__name = "TObjBoss7Dust";

s32 lbl_805D6958;

extern "C" {

void fn_802F1454(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        s32 a = (s32)(lbl_805DEC78 * (f32)i);
        f32 s = lbl_805DEC7C * sin_table_lookup(a);
        TObjBoss7DustCtrl__helix_points[i].x = s;
        TObjBoss7DustCtrl__helix_points[i].y = lbl_805DEC80 * (f32)i;
        TObjBoss7DustCtrl__helix_points[i].z = lbl_805DEC7C * cos_table_lookup(a, s);
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
            o->x = lbl_805DEC70;
            o->y = lbl_805DEC70;
            o->z = lbl_805DEC70;
            o->color = 0xFF709070;
            o++;
        }
    }
    for (j = 0; j < 10; j++) {
        TObjBoss7DustCtrl__vertical_phase_angles[j] = TObjPlayer::calc_random_scaled();
    }
    lbl_805D6958 = 0;
}

void TObjBoss7DustCtrl__sub_802F1450(void) {  }

}

void TObjBoss7DustCtrl::create() {
    new TObjBoss7DustCtrl((TObject *)tl_05);
}

TObjBoss7DustCtrl::TObjBoss7DustCtrl(TObject *parent) : TObject(parent) {
    m_name = TObjBoss7DustCtrl__name;
}

TObjBoss7DustCtrl::~TObjBoss7DustCtrl() {}

#pragma push
#pragma opt_propagation off
void TObjBoss7DustCtrl::run_task() {
    f32 scale;
    s32 *ang;
    TrailStripVertex *out;
    s32 *rot;
    s32 i;
    s32 j;

    rot = TObjBoss7DustCtrl__rotation_pairs;
    out = TObjBoss7DustCtrl__transformed_vertices;
    push_matrix();
    scale = lbl_805DEC74;
    ang = TObjBoss7DustCtrl__vertical_phase_angles;
    for (i = 0; i < 10; i++) {
        set_matrix_identity(0);
        translate_matrix(0, lbl_805DEC70, scale * sin_table_lookup(ang[i]), lbl_805DEC70);
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
            matrix_mult_vec(0, &TObjBoss7DustCtrl__helix_points[j], out++);
        }
    }
    pop_matrix();
}
#pragma pop

extern "C" {
s32 TObjBoss7DustCtrl__sub_802F125C(void) {
    s32 index = lbl_805D6958;

    lbl_805D6958 = index + 1;
    if (index + 1 >= 0xA) {
        lbl_805D6958 = 0;
    }
    return index;
}
}

void boss7_dust_draw_at(const Vec *position, s32 slot) {
    TParticleCtrl::end_effect_render();
    push_matrix();
    post_translate_matrix(&position->x);
    draw_trail_strip(&TObjBoss7DustCtrl__transformed_vertices[slot * 6], 6, 0);
    pop_matrix();
}

LAYOUT_ASSERT(RecoveredGlobal_802F119C___vt__13TObjBoss7Dust_size, sizeof(RecoveredGlobal_802F119C___vt__13TObjBoss7Dust) == 0x18);

u8 *__ct__13TObjBoss7DustFv(u8 *object, saddr arg1, saddr arg2) {
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__13TObjBoss7Dust.value;
    ((TObjBoss7Dust *)object)->m_name = TObjBoss7Dust__name;
    TObjBoss7Dust *dust = (TObjBoss7Dust *)object;
    VecCopy(&dust->position, (const Vec *)arg2);
    dust->ticks = 0;
    dust->strip_slot = TObjBoss7DustCtrl__sub_802F125C();
    return object;
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

void init_scene_boss2_tunnel(void) { load_boss7_common_resources(); TObjBoss2Tunnel__sub_802F2C84(); fn_802F1454(); }

extern "C" {
void fn_802F1084(void) { TObjBoss2Tunnel__sub_802F2C50(); fn_802F19C0(); TObjBoss7DustCtrl::create(); }
void fn_802F105C(void) { TObjBoss7DustCtrl__sub_802F1450(); TObjBoss2Tunnel__sub_802F2C4C(); free_boss7_common_resources(); }
}
