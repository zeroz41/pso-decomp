#pragma defer_codegen on
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/derolle/TObjBoss2Dust.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk_8003A81C.h"
#include "pso/system/vector.h"
#include "pso/system/TrailStrip.h"
#include "pso/system/MatrixStack.h"
#include "pso/boss/derolle/TObjBoss2DustCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TObject.h"

extern "C" {

f32 sin_table_lookup(int);
f32 cos_table_lookup(int, f32);
void matrix_mult_vec(s32, Vec *, TrailStripVertex *);
Vec boss2_dust_points[6];
s32 boss2_dust_rotation_table[20];
TrailStripVertex boss2_dust_output_table[60];
s32 boss2_dust_random_angles[10];
extern const f32 lbl_805D85B8;
extern const f32 lbl_805D85BC;
extern const f32 lbl_805D85C0;
extern const f32 lbl_805D85C4;
extern const f32 lbl_805D85C8;
s32 TObjBoss2DustCtrl_dust_counter;

extern saddr tl_05;


}

#pragma push
#pragma readonly_strings on
const char *TObjBoss2DustCtrl__name = "TObjBoss2DustCtrl";
const char *TObjBoss2Dust__name = "TObjBoss2Dust";
#pragma pop

extern "C" {
void fn_8003AD54(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        s32 a = (s32)(lbl_805D85C0 * (f32)i);
        f32 s = lbl_805D85C4 * sin_table_lookup(a);
        boss2_dust_points[i].x = s;
        boss2_dust_points[i].y = lbl_805D85C8 * (f32)i;
        boss2_dust_points[i].z = lbl_805D85C4 * cos_table_lookup(a, s);
    }
    {
        s32 *p = boss2_dust_rotation_table;
        for (i = 0; i < 20; i++) {
            *p++ = TObjPlayer::calc_random_scaled();
        }
    }
    {
        TrailStripVertex *o = boss2_dust_output_table;
        for (i = 0; i < 60; i++) {
            o->x = lbl_805D85B8;
            o->y = lbl_805D85B8;
            o->z = lbl_805D85B8;
            o->color = 0xFF709070;
            o++;
        }
    }
    for (j = 0; j < 10; j++) {
        boss2_dust_random_angles[j] = TObjPlayer::calc_random_scaled();
    }
    TObjBoss2DustCtrl_dust_counter = 0;
}

void TObjBoss2DustCtrl__sub_8003AD50(void) {  }
}

void TObjBoss2DustCtrl::create() {
    new TObjBoss2DustCtrl((TObject *)tl_05);
}

TObjBoss2DustCtrl::TObjBoss2DustCtrl(TObject *parent) : TObject(parent) {
    m_name = TObjBoss2DustCtrl__name;
}

TObjBoss2DustCtrl::~TObjBoss2DustCtrl() {}

extern "C" {
#pragma push
#pragma opt_propagation off
void TObjBoss2DustCtrl::run_task() {
    f32 scale;
    s32 *ang;
    TrailStripVertex *out;
    s32 *rot;
    s32 i;
    s32 j;

    rot = boss2_dust_rotation_table;
    out = boss2_dust_output_table;
    push_matrix();
    scale = lbl_805D85BC;
    ang = boss2_dust_random_angles;
    for (i = 0; i < 10; i++) {
        set_matrix_identity(0);
        translate_matrix(0, lbl_805D85B8, scale * sin_table_lookup(ang[i]), lbl_805D85B8);
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
            matrix_mult_vec(0, &boss2_dust_points[j], out++);
        }
    }
    pop_matrix();
}
#pragma pop

s32 TObjBoss2DustCtrl__sub_8003AB5C(void) {
    s32 slot = TObjBoss2DustCtrl_dust_counter;
    TObjBoss2DustCtrl_dust_counter = slot + 1;
    if (slot + 1 >= 10) {
        TObjBoss2DustCtrl_dust_counter = 0;
    }
    return slot;
}

void boss2_dust_draw_at(const Vec *position, s32 slot) {
    TParticleCtrl::end_effect_render();
    push_matrix();
    post_translate_matrix(&position->x);
    draw_trail_strip(&boss2_dust_output_table[slot * 6], 6, 0);
    pop_matrix();
}

}

TObjBoss2Dust::TObjBoss2Dust(TObject *parent, const Vec *position) : TObject(parent) {
    m_name = TObjBoss2Dust__name;
    VecCopy(&this->position, position);
    ticks = 0;
    strip_slot = TObjBoss2DustCtrl__sub_8003AB5C();
}

TObjBoss2Dust::~TObjBoss2Dust() {}

void TObjBoss2Dust::run_task() {
    position.z -= boss2_tunnel_max_scroll_speed;
    ticks++;
    if (ticks >= 90) {
        queue_destruction();
    }
}
