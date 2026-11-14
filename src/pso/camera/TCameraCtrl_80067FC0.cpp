#include "types.h"
#include "pso/unk/TUnk_80488A28.h"
#include "pso/camera/TCameraCtrl_80067FC0.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/system/vector.h"
#include "pso/unk/TUnk_80488838.h"
#include "pso/unk/TUnk_80488A28.h"
#include "pso/unk/TUnk_80488DA0.h"
#include "pso/unk/TUnk_80488E00.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl.h"

struct Vec_8006835C { f32 x, y, z; };

struct View_8006835C {
    u8 pad0[0x178];
    Vec_8006835C pos;
    Vec_8006835C target;
    u8 f190[4];
    u8 f194[4];
};

struct Flags_8006835C { u8 pad0[8]; u32 flags; };

struct Scissor_8006835C { u8 pad0[8]; f32 x; f32 y; u8 pad10[0x30 - 0x10]; u8 f30[4]; };

struct View_80068530 {
    u8 pad0[0xD4];
    Vec_8006835C eye[4];
    Vec_8006835C look[4];
    u8 pad134[0x178 - 0x134];
    Vec_8006835C pos;
    Vec_8006835C target;
    u8 pad190[0x19C - 0x190];
    s32 f19c;
    Vec_8006835C curPos;
    Vec_8006835C curTarget;
    f32 f1b8;
    f32 f1bc;
};

struct Cam_80068530 {
    u8 pad0[0x3C];
    Vec_8006835C pos;
    Vec_8006835C target;
    s32 f54;
    f32 f58;
    f32 f5c;
};

struct Obj_8006809C { u8 pad0[0x38]; f32 x; f32 y; f32 z; u8 pad44[0x60 - 0x44]; s32 angle; };

struct Hit_8006809C { u8 pad0[4]; void *pos; };

struct Cam_8006809C { u8 pad0[0x1C]; Obj_8006809C *obj; u8 pad20[0x60 - 0x20]; Vec_8006835C out; };

extern "C" {
Vec_8006835C *get_target__11TCameraCtrlFv(void *);
void direction_to_pitch_yaw(u8 *arg0, s32 *arg1, s32 *arg2);
void set_viewport_scissor__11TCameraCtrlFiPv(s32, void *);
void GXSetScissorBoxOffset(s32, s32);
f32 vector_length(void *);
void normalize_vector(void *);
extern Vec_8006835C lbl_804FF5E8;
extern Flags_8006835C TCameraCtrl__view_state;
extern Scissor_8006835C TCameraCtrl__data_804FF634;
extern u8 TCameraCtrl__up_vector[];
extern View_8006835C *camera_ctrl_instance;
void apply_camera_controller_pose(Cam_80068530 *arg0);
s32 is_split_screen();
f32 fabs_float();
Vec_8006835C *get_position_ptr__10TObjPlayerFv(void *);
Vec_8006835C *get_target_ptr__11TCameraCtrlFv(void *);
Hit_8006809C *csnVector(void *, void *, s32);
s32 matrix_mult_vec(int, void *, void *);
s32 vec3_dot(void *, void *);
s32 rotate_matrix_y(int, s32);
s32 push_matrix_from(void *);
s32 pop_matrices(int);
const Vec_8006835C lbl_80438168 = {0.0f, 0.0f, -1.0f};
const Vec_8006835C lbl_80438174 = {0.0f, 0.0f, -1.0f};
extern u8 identity_matrix[];
extern s32 __vt__13TUnk_80488A28[];
void __dt__7TObjectFv(void *, int);

}
void set_camera_look_at(u8 *eye, u8 *target, u8 *up);

#pragma push
#pragma fp_contract on
s32 TUnk_80488E00::predict_obstruction() {
    Cam_8006809C *self = (Cam_8006809C *)this;
    Vec_8006835C dir;
    Vec_8006835C probe;
    Vec_8006835C d;
    Vec_8006835C *tgt;
    Vec_8006835C *pos;
    Vec_8006835C *a;
    Vec_8006835C *b;
    Hit_8006809C *hit;
    f32 dist;
    if (self->obj == NULL) {
        return 0;
    }
    tgt = get_target_ptr__11TCameraCtrlFv(self->obj);
    pos = get_position_ptr__10TObjPlayerFv(self->obj);
    d.x = pos->x - tgt->x;
    d.y = pos->y - tgt->y;
    d.z = pos->z - tgt->z;
    dist = vector_length(&d);
    if (dist < 1.0f) {
        Vec_8006835C v1 = lbl_80438168;
        Vec_8006835C v2 = lbl_80438174;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, *(s32 *) camera_ctrl_instance->f194);
        matrix_mult_vec(0, &v1, &v1);
        pop_matrices(1);
        v1.y = 0.0f;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, self->obj->angle);
        matrix_mult_vec(0, &v2, &v2);
        pop_matrices(1);
        vec3_dot(&v1, &v2);
        if (fabs_float() > 0.25f) {
            dist = 0.0f;
        } else {
            dist *= 13.0f;
        }
    } else {
        dist *= 13.0f;
    }
    if (is_split_screen() != 0) {
        s32 mode = TCameraCtrl::get_camera_mode();
        View_80068530 *v = (View_80068530 *) camera_ctrl_instance;
        a = &v->eye[mode];
        b = &v->look[mode];
        probe.y = v->look[mode].y;
    } else {
        a = &camera_ctrl_instance->pos;
        b = &camera_ctrl_instance->target;
        probe.y = camera_ctrl_instance->target.y;
    }
    dir.x = a->x - b->x;
    dir.y = a->y - b->y;
    dir.z = a->z - b->z;
    if (0.0f != vector_length(&dir)) {
        normalize_vector(&dir);
    }
    probe.x = dist * dir.x + self->obj->x;
    probe.z = dist * dir.z + self->obj->z;
    if (camera_ctrl_instance == NULL) {
        return 0;
    }
    hit = csnVector(a, &probe, 0x100);
    if (hit != NULL) {
        VecCopy((Vec *)&self->out, (const Vec *)hit->pos);
        self->out.x -= 2.0f * dir.x;
        self->out.y -= 2.0f * dir.y;
        self->out.z -= 2.0f * dir.z;
        return 1;
    }
    return 0;
}
#pragma pop

void TCameraCtrl__sub_80068354(void) {  }
void TCameraCtrl__sub_80068358(void) {  }

void TUnk_80488A28::post_update_view() {
    Vec_8006835C e;
    Vec_8006835C d;
    Vec_8006835C *t;
    d.x = camera_ctrl_instance->target.x - camera_ctrl_instance->pos.x;
    d.y = camera_ctrl_instance->target.y - camera_ctrl_instance->pos.y;
    d.z = camera_ctrl_instance->target.z - camera_ctrl_instance->pos.z;
    if (0.0f == vector_length(&d)) {
        normalize_vector(&d);
        camera_ctrl_instance->target.x = camera_ctrl_instance->pos.x;
        camera_ctrl_instance->target.y = camera_ctrl_instance->pos.y;
        camera_ctrl_instance->target.z = 1.0f + camera_ctrl_instance->pos.z;
    } else if (0.0f == d.x && 0.0f == d.z) {
        camera_ctrl_instance->target.z += 0.01f;
        d.z = 1.0f;
    }
    direction_to_pitch_yaw((u8 *)&d, (s32 *)camera_ctrl_instance->f190, (s32 *)camera_ctrl_instance->f194);
    t = get_target__11TCameraCtrlFv(camera_ctrl_instance);
    e.x = camera_ctrl_instance->target.x + t->x;
    e.y = camera_ctrl_instance->target.y + t->y;
    e.z = camera_ctrl_instance->target.z + t->z;
    set_camera_look_at((u8 *)&camera_ctrl_instance->pos, (u8 *)&e, (u8 *)TCameraCtrl__up_vector);
    lbl_804FF5E8.x = camera_ctrl_instance->pos.x;
    lbl_804FF5E8.y = camera_ctrl_instance->pos.y;
    lbl_804FF5E8.z = camera_ctrl_instance->pos.z;
    if (TCameraCtrl__view_state.flags & 0x200) {
        GXSetScissorBoxOffset((s32)-(TCameraCtrl__data_804FF634.x - 320.0f), (s32)-(TCameraCtrl__data_804FF634.y - 240.0f));
        TCameraCtrl__sub_801E32D8(TCameraCtrl__data_804FF634.x, TCameraCtrl__data_804FF634.y);
        set_viewport_scissor__11TCameraCtrlFiPv(2, TCameraCtrl__data_804FF634.f30);
    }
}

#define V ((View_80068530 *)camera_ctrl_instance)
void apply_camera_controller_pose(Cam_80068530 *arg0) {
    s32 no;
    s32 id;
    if ((TCameraCtrl__view_state.flags & 4) || (TCameraCtrl__view_state.flags & 8)) {
        V->curPos.x = arg0->pos.x;
        V->curPos.y = arg0->pos.y;
        V->curPos.z = arg0->pos.z;
        V->curTarget.x = arg0->target.x;
        V->curTarget.y = arg0->target.y;
        V->curTarget.z = arg0->target.z;
        V->pos.x = V->curPos.x;
        V->pos.y = V->curPos.y;
        V->pos.z = V->curPos.z;
        V->target.x = V->curTarget.x;
        V->target.y = V->curTarget.y;
        V->target.z = V->curTarget.z;
        no = TCameraCtrl::get_camera_no();
        VecCopy((Vec *)&V->eye[no], (const Vec *)&arg0->pos);
        VecCopy((Vec *)&V->look[no], (const Vec *)&arg0->target);
    } else {
        V->curPos.x = arg0->pos.x;
        V->curPos.y = arg0->pos.y;
        V->curPos.z = arg0->pos.z;
        V->curTarget.x = arg0->target.x;
        V->curTarget.y = arg0->target.y;
        V->curTarget.z = arg0->target.z;
    }
    V->f1b8 = arg0->f58;
    V->f1bc = arg0->f5c;
    if (V->f19c != arg0->f54) {
        TCameraCtrl__view_state.flags |= 0x40;
        V->f19c = arg0->f54;
    }
}

TUnk_80488A28::~TUnk_80488A28() {

}
TUnk_80488A28::TUnk_80488A28() : TObject(0) {
    this->position.x = 0.0f;
    this->position.y = 0.0f;
    this->position.z = 0.0f;
    this->m_2c = 0;
    *(s32 *)((s8 *)this + 0x30) = 0;
    this->m_34 = 0;
    this->target.x = 0.0f;
    this->target.y = 0.0f;
    this->target.z = 1.0f;
    this->m_60 = 0.0f;
    *(f32 *)((s8 *)this + 0x64) = 0.0f;
    this->m_68 = 0.0f;
    *(s32 *)((s8 *)this + 0x28) = 0;
    this->m_24 = 0;
    this->m_38 = 0;
    this->m_58 = 0.0f;
    *(f32 *)((s8 *)this + 0x5C) = 0.289f;
    this->projection_angle = 0x36C1;
    this->m_20 = 0xFFFF;
}
