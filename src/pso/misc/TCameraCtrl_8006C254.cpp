#include "types.h"
#include "pso/misc/TCameraCtrl_80067FC0.h"
#include "pso/misc/TCameraCtrl_8006C254.h"
#include "pso/misc/TUnk_80488B38.h"
#include "pso/misc/TUnk_80488B68.h"
#include "pso/misc/TUnk_80488B08.h"
#include "pso/system/vector.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/CameraHelpers.h"
#include <stddef.h>
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TCameraCtrl_8006C580.h"
#include "pso/system/memory.h"
#include "pso/misc/TUnk_80488D70.h"
#include "pso/misc/TScene.h"
#include "pso/map/CurrentArea.h"

extern "C" {
void __dl__7TObjectFPv(void *);

#pragma push
#pragma fp_contract on
#pragma pop

}

extern void* camera_controller_registry[];
void* camera_controller_registry[];

struct CameraMotionData;
extern "C" {

void *TCameraCtrl__vt5(void);

}

extern s32 TCameraCtrl__saved_projection_angle;
extern s32 scripted_camera_projection_angle;

#pragma push
#pragma opt_common_subs off
#pragma pop

void *TCameraCtrl__vt5(void) {
    void *o = (void *)new TUnk_80488B68();
    return o;
}

#pragma push
#pragma fp_contract on
struct Vec_8006C28C { f32 x, y, z; };
struct Motion_8006C28C { u32 data; u32 frames; };
struct Mode_8006C28C { u32 asset; u32 flags; };
struct Cam_8006C28C {
    u8 pad0[0x3C];
    Vec_8006C28C position;
    Vec_8006C28C target;
    s32 projection;
    u8 pad58[0x6C - 0x58];
    Vec_8006C28C position_origin;
    Vec_8006C28C target_origin;
    s32 pitch;
    s32 yaw;
    s32 roll;
    Motion_8006C28C *motion;
    Mode_8006C28C *mode;
    u8 bank;
    u8 index;
    u16 flags;
    f32 frame;
    f32 step;
};
struct Stack_8006C28C {
    void *ptrs[4];
    Vec_8006C28C p;
    Vec_8006C28C v;
    s32 sp54;
    Vec_8006C28C sp58;
    u8 out[0x2C];
};

void sample_camera_motion(u8 *arg0, s32 arg1, u8 *arg2, f32 farg0);
extern "C" {
void set_camera_capture_overlay_alpha(int);
f32 vec_squared_length(u8 *arg0);
void normalize_vector(Vec_8006C28C *);
s32 push_matrix_from(void *src);
void rotate_matrix_y(int, s32);
void matrix_mult_vec(int, Vec_8006C28C *, Vec_8006C28C *);
s32 pop_matrices(s32 arg0);
extern u8 identity_matrix[];

void TUnk_80488B68::run_task() {
    Cam_8006C28C *s = (Cam_8006C28C *)this;
    Stack_8006C28C st;
    Vec_8006C28C tmp;
    Vec_8006C28C p2;
    Vec_8006C28C v2;
    st.ptrs[0] = &st.p;
    st.ptrs[1] = &st.v;
    st.ptrs[2] = &st.sp54;
    st.ptrs[3] = &st.sp58;
    sample_camera_motion((u8 *)st.out, (s32)s->motion, (u8 *)st.ptrs, (f32)((f32)s->frame));
    s->projection = scripted_camera_projection_angle;
    set_camera_capture_overlay_alpha(0x8F);
    if (s->mode->flags & 4) {
        if (s->mode->flags & 0x80) {
            s->projection = 0x36C1;
            tmp.x = st.v.x;
            tmp.y = 0.0f;
            tmp.z = st.v.z;
            f32 m = vec_squared_length((u8 *)&tmp);
            if (m) {
                normalize_vector(&tmp);
            }
            s->position.x = -(4e+01f * tmp.x - st.p.x);
            s->position.y = st.p.y;
            s->position.z = -(4e+01f * tmp.z - st.p.z);
            s->target.x = st.v.x + st.p.x;
            s->target.y = st.v.y + st.p.y;
            s->target.z = st.v.z + st.p.z;
        } else {
            s->position.x = st.p.x;
            s->position.y = st.p.y;
            s->position.z = st.p.z;
            s->target.x = st.v.x + s->position.x;
            s->target.y = st.v.y + s->position.y;
            s->target.z = st.v.z + s->position.z;
        }
    } else {
        p2.x = st.p.x;
        p2.y = st.p.y;
        p2.z = st.p.z;
        v2.x = st.v.x;
        v2.y = st.v.y;
        v2.z = st.v.z;
        if (vec_squared_length((u8 *)&v2) != 0.0f) {
            normalize_vector(&v2);
        }
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, s->yaw);
        matrix_mult_vec(0, &p2, &p2);
        matrix_mult_vec(0, &v2, &v2);
        pop_matrices(1);
        s->position.x = p2.x + s->position_origin.x;
        s->position.y = p2.y + s->position_origin.y;
        s->position.z = p2.z + s->position_origin.z;
        s->target.x = v2.x + s->position.x;
        s->target.y = v2.y + s->position.y;
        s->target.z = v2.z + s->position.z;
    }
    s->frame += s->step;
    if (s->frame > (s->motion->frames - 1) || s->frame >= 5e+03f) {
        if (s->mode->flags & 0x20) {
            s->frame = 0.0f;
            return;
        }
        s->frame = (s->motion->frames - 1);
        s->flags |= 1;
    }
}
}
#pragma pop

extern s32 __vt__13TUnk_80488B68[];

void *__dt__13TUnk_80488B68Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_80488B68;
        __dt__13TUnk_80488A28Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern "C" {

s32 load_relocatable_file(s32 arg0, s32 arg1);

}
TUnk_80488B68::TUnk_80488B68() : TUnk_80488A28() {
    this->m_38 = 0;
    scripted_camera_projection_angle = 0;
    TCameraCtrl__saved_projection_angle = 0;
    *(unsigned char *)&this->unk_99 = 0;
    this->m_98 = 0;
    this->m_9a = 0;
    *(float*)((char*)this + 0x9c) = 0.0f;
    this->m_a0 = 0.0f;
    *(float*)((char*)this + 0x6c) = 0.0f;
    this->m_70 = 0.0f;
    *(float*)((char*)this + 0x74) = 0.0f;
    this->m_78 = 0.0f;
    *(float*)((char*)this + 0x7c) = 0.0f;
    this->m_80 = 0.0f;
    *(int*)((char*)this + 0x84) = 0;
    this->m_88 = 0;
    *(int*)((char*)this + 0x8c) = 0;
    this->m_90 = 0;
    *(int*)((char*)this + 0x94) = 0;
}

void TCameraCtrl::free_entries() {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (TCameraCtrl__camera_banks.e[i].p != 0) {
            xfree(TCameraCtrl__camera_banks.e[i].p);
            TCameraCtrl__camera_banks.e[i].p = 0;
        }
    }
}

void TCameraCtrl::load_camera_banks() {
    u32 j;
    Bank_8006C6CC *b;
    u32 n;
    u32 k;
    s32 i;
    s32 sz;
    for (i = 0; i < 8; i++) {
        TCameraCtrl__camera_banks.e[i].p = 0;
    }
    b = &camera_path_bank_table[get_current_area()];
    if (b->entries == 0) {
        return;
    }
    n = b->count;
    if (n >= 8) {
        return;
    }
    for (j = 0; j < n; j++) {
        sz = ((TScene *)(b->entries[j].id))->update_lobby_scene();
        if (sz <= -1) {
            return;
        }
        TCameraCtrl__camera_banks.e[j].p = xmalloc(sz);
    }
    for (k = 0; k < n; k++) {
        TCameraCtrl__camera_banks.e[k].a = load_relocatable_file(b->entries[k].id, (s32)TCameraCtrl__camera_banks.e[k].p);
    }
}
