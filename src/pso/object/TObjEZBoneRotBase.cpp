#include "types.h"
#include "pso/object/TObjEZBoneRotPlayer_800FE834.h"
#include "pso/object/TObjEZBoneRotPlayer.h"
#include "pso/object/TObjEZBoneRotBase.h"
#include "pso/object/TObjHMS_EZRope_Player.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjEZRopeBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/AngleLookup.h"

struct EZBoneRotKey {
    s32 bone;
    f32 axis[3];
};

struct EZBoneRotDesc {
    s32 period;
    u8 unk_04[0x4];
    s32 phase_step;
    f32 amplitude_scale;
    EZBoneRotKey *keys;
};

struct EZBoneRotState {
    u8 pad0[0x18];
    void **vtable;
    void *root;
    EZBoneRotDesc *desc;
    u8 pad24[0x84 - 0x24];
    s32 phase;
    u8 pad88[0x94 - 0x88];
    f32 scale;
};

extern "C" {
TObjEZBoneRotBase *TObjEZBoneRotBase__ct(TObjEZBoneRotBase *self, TObject *parent, void *root, EZBoneRotDesc *desc);
extern s32 __vt__19TObjEZBoneRotPlayer[];
extern s32 TObjEZBoneRotPlayer__name;
void *__nw__7TObjectFUl(int);

void TObjEZBoneRotPlayer::run_task() {
    f32 temp_f1;
    s32 temp_r4;
    void *temp_r6;

    temp_r6 = *(void **)((s8 *)this + 0x98);
    temp_r4 = *(s32 *)((s8 *)temp_r6 + 0x320) & 0xDF7FF;
    if (temp_r4 & 0x99003) {
        *(f32 *)((s8 *)this + 0x94) += -0.016666668f;
    } else if ((temp_r4 & 0x1E0) || ((s32) *(s32 *)((s8 *)this + 0x9C) != (s32) *(s32 *)((s8 *)temp_r6 + 0x60))) {
        *(f32 *)((s8 *)this + 0x94) += 0.13333334f;
    } else if (temp_r4 & 0x4661C) {
        *(f32 *)((s8 *)this + 0x94) += 0.016666668f;
    } else {
        *(f32 *)((s8 *)this + 0x94) += -0.016666668f;
    }
    temp_f1 = *(f32 *)((s8 *)this + 0x94);
    if (temp_f1 < 0.0f) {
        *(f32 *)((s8 *)this + 0x94) = (f32) 0.0f;
    } else if (temp_f1 > 1.0f) {
        *(f32 *)((s8 *)this + 0x94) = (f32) 1.0f;
    }
    advance_bone_rotation();
    *(s32 *)((s8 *)this + 0x9C) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)this + 0x98)) + 0x60);
}
u8 *__ct__19TObjEZBoneRotPlayerFv(u8 *arg0, s32 arg1, u8 *arg2, void * _w3) {
    TObjEZBoneRotBase__ct((TObjEZBoneRotBase *)arg0, (TObject *)arg1, arg2, (EZBoneRotDesc *)_w3);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TObjEZBoneRotPlayer;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjEZBoneRotPlayer__name;
    *(s32 *)((s8 *)arg0 + 0x98) = arg1;
    *(s32 *)((s8 *)arg0 + 0x9C) = (s32) *(s32 *)((s8 *)(*(s32 *)((s8 *)arg0 + 0x98)) + 0x60);
    return arg0;
}
void *TObjEZBoneRotPlayer::create(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0xA0);
    if (o != NULL) {
        o = ((void *)__ct__19TObjEZBoneRotPlayerFv((u8 *)o, (s32)arg0, (u8 *)arg1, (void *)arg2));
    }
    return o;
}
void TObjEZBoneRotPlayer::advance_bone_rotation() {
    start_bone_rotation_sequence(*(s32 *)((s8 *)this + 0x84));
    if (*(f32 *)((s8 *)this + 0x94) > 0.0f) {
        *(s32 *)((s8 *)this + 0x84) = (s32) (*(s32 *)((s8 *)this + 0x84) + *(s32 *)((s8 *)(*(void **)((s8 *)this + 0x20)) + 4));
    }
}

}

extern "C" {

void TObjEZBoneRotPlayer::calc_bone_offsets_recursive(void *arg1, s32 arg2, s32 arg3) {
    s32 k;
    f32 t;
    do {
        k = *(s32 *)((s8 *)(*(s32 **)((s8 *)this + 0x8C)) + 0);
        if (k < 0) {
            return;
        }
        if (k == *(s32 *)((s8 *)this + 0x88)) {
            t = (f32) arg3 * sin_table_lookup(arg2);
            *(s32 *)((s8 *)arg1 + 0x14) = *(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x90)) + 0) + (s32) (*(f32 *)((s8 *)(*(u8 **)((s8 *)this + 0x8C)) + 4) * t);
            *(s32 *)((s8 *)arg1 + 0x18) = *(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x90)) + 4) + (s32) (*(f32 *)((s8 *)(*(u8 **)((s8 *)this + 0x8C)) + 8) * t);
            *(s32 *)((s8 *)arg1 + 0x1C) = *(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x90)) + 8) + (s32) (*(f32 *)((s8 *)(*(u8 **)((s8 *)this + 0x8C)) + 0xC) * t);
            *(u8 **)((s8 *)this + 0x90) = *(u8 **)((s8 *)this + 0x90) + 0xC;
            *(u8 **)((s8 *)this + 0x8C) = *(u8 **)((s8 *)this + 0x8C) + 0x10;
            if (*(s32 *)((s8 *)(*(s32 **)((s8 *)this + 0x8C)) + 0) < 0) {
                return;
            }
        }
        *(s32 *)((s8 *)this + 0x88) = *(s32 *)((s8 *)this + 0x88) + 1;
        if (*(void **)((s8 *)arg1 + 0x2C) != NULL) {
            calc_bone_offsets_recursive(*(void **)((s8 *)arg1 + 0x2C), arg2 + *(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x20)) + 8), (s32) (*(f32 *)((s8 *)(*(u8 **)((s8 *)this + 0x20)) + 0xC) * (f32) arg3));
        }
        arg1 = *(void **)((s8 *)arg1 + 0x30);
    } while (arg1 != NULL);
}

void TObjEZBoneRotPlayer::start_bone_rotation_sequence(s32 arg1) {
    *(s32 *)((s8 *)((u8 *)this) + 0x88) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x8C) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x20)) + 0x10);
    *(s32 *)((s8 *)((u8 *)this) + 0x90) = (s32) (((u8 *)this) + 0x24);
    calc_bone_offsets_recursive((void *)(*(u8 **)((s8 *)((u8 *)this) + 0x1C)), arg1, (s32)((s32) ((f32) *(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x20)) + 0) * *(f32 *)((s8 *)((u8 *)this) + 0x94))));
}

void TObjEZBoneRotBase::sub_800FEC40(u8 *arg1) {
    s32 temp_r3;
    u8 *temp_r4;
    u8 *var_r31;
    var_r31 = arg1;
loop_1:
    temp_r3 = *(s32 *)((s8 *)(*(s32 **)((s8 *)((u8 *)this) + 0x8C)) + 0);
    if (temp_r3 >= 0) {
        if (temp_r3 == (s32) *(s32 *)((s8 *)((u8 *)this) + 0x88)) {
            *(s32 *)((s8 *)var_r31 + 0) = (s32) (*(s32 *)((s8 *)var_r31 + 0) & 0xFFFFFFFD);
            *(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x90)) + 0) = (s32) *(s32 *)((s8 *)var_r31 + 0x14);
            *(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x90)) + 4) = (s32) *(s32 *)((s8 *)var_r31 + 0x18);
            *(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x90)) + 8) = (s32) *(s32 *)((s8 *)var_r31 + 0x1C);
            *(u8 **)((s8 *)((u8 *)this) + 0x90) = (unsigned char *) ((void *) ((u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x90)) + 0xC));
            *(s32 **)((s8 *)((u8 *)this) + 0x8C) = (s32 *) ((u8 *)(*(s32 **)((s8 *)((u8 *)this) + 0x8C)) + 0x10);
            if ((s32) *(s32 *)((s8 *)(*(s32 **)((s8 *)((u8 *)this) + 0x8C)) + 0) >= 0) {
                goto block_4;
            }
        } else {
block_4:
            *(s32 *)((s8 *)((u8 *)this) + 0x88) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x88) + 1);
            temp_r4 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0x2C));
            if (temp_r4 != NULL) {
                sub_800FEC40(temp_r4);
            }
            var_r31 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0x30));
            if (var_r31 != NULL) {
                goto loop_1;
            }
        }
    }
}

void TObjEZBoneRotBase::sub_800FED0C() {
    *(s32 *)((s8 *)((u8 *)this) + 0x88) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x8C) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x20)) + 0x10);
    *(s32 *)((s8 *)((u8 *)this) + 0x90) = (s32) (((u8 *)this) + 0x24);
    sub_800FEC40((u8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x1C)));
}

}

TObjEZBoneRotBase::~TObjEZBoneRotBase() {}

extern "C" {
void __ct__7TObjectFP7TObject(TObject *self, TObject *parent);
extern void *__vt__17TObjEZBoneRotBase[];
extern const char *lbl_805D2B48;

TObjEZBoneRotBase *TObjEZBoneRotBase__ct(TObjEZBoneRotBase *self, TObject *parent, void *root, EZBoneRotDesc *desc) {
    EZBoneRotState *state = (EZBoneRotState *)self;
    TObjEZBoneRotBase *base;
    EZBoneRotKey *key;

    __ct__7TObjectFP7TObject(self, parent);
    base = (TObjEZBoneRotBase *)(TObject *)self;
    state->vtable = __vt__17TObjEZBoneRotBase;
    self->m_name = lbl_805D2B48;
    state->root = root;
    state->desc = desc;
    key = state->desc->keys;
    while (key->bone >= 0) {
        key++;
    }
    base->sub_800FED0C();
    state->phase = 0;
    state->scale = 0.0f;
    return self;
}
}

extern "C" {
void __dt__17TObjEZBoneRotBaseFv(void *self, s32 flag);
void __dl__7TObjectFPv(void *p);

void *__dt__19TObjEZBoneRotPlayerFv(void *self, s16 flag) {
    if (self != 0) {
        *(void **)((u8 *)self + 0x18) = __vt__19TObjEZBoneRotPlayer;
        __dt__17TObjEZBoneRotBaseFv(self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

struct RotSrc_800FEEA4 {
    s8 bone;
    u8 pad[3];
    f32 angle;
    u8 data[0xC];
};

struct PosSrc_800FEEA4 {
    s8 bone;
    u8 pad[3];
    s32 ofs;
    u8 data[0x10];
};

struct RotDst_800FEEA4 {
    f32 angle;
    u8 data[0xC];
};

struct PosDst_800FEEA4 {
    s32 val;
    u8 data[0xC];
};

struct Model_800FEEA4 {
    u8 pad[0x60];
    s32 base;
};

struct Self_800FEEA4 {
    u8 pad[0x30];
    Model_800FEEA4 *model;
    PosSrc_800FEEA4 *pos_src;
    RotSrc_800FEEA4 *rot_src;
    u8 pad3C[4];
    PosDst_800FEEA4 *pos_dst;
    RotDst_800FEEA4 *rot_dst;
};

extern "C" {
void matrix_mult_vec(s32, void *, void *);
void push_matrix(void);
extern u8 TObjEZBoneRotPlayer__chain_gravity[];

void TObjHMS_EZRope_Player::render() { sub_800FF2D0(); }
void TObjHMS_EZRope_Player::run_task() {
    RotSrc_800FEEA4 *rs;
    RotDst_800FEEA4 *rd;
    PosSrc_800FEEA4 *ps;
    PosDst_800FEEA4 *pd;
    if (((Self_800FEEA4 *)this)->rot_dst != NULL) {
        push_matrix();
        TObjPlayer::invert_matrix_in_place(0);
        rs = ((Self_800FEEA4 *)this)->rot_src;
        rd = ((Self_800FEEA4 *)this)->rot_dst;
        while (rs->bone >= 0) {
            rd->angle = rs->angle;
            push_matrix();
            TObjPlayer::concat_matrix(0, ((TObjMotion *)(((Self_800FEEA4 *)this)->model))->get_item_ptr(rs->bone));
            matrix_mult_vec(0, rs->data, rd->data);
            pop_matrix();
            rs++;
            rd++;
        }
        pop_matrix();
    }
    push_matrix();
    TObjPlayer::invert_matrix_in_place(0);
    ps = ((Self_800FEEA4 *)this)->pos_src;
    pd = ((Self_800FEEA4 *)this)->pos_dst;
    while (ps->bone >= 0) {
        pd->val = ((Self_800FEEA4 *)this)->model->base + ps->ofs;
        push_matrix();
        TObjPlayer::concat_matrix(0, ((TObjMotion *)(((Self_800FEEA4 *)this)->model))->get_item_ptr(ps->bone));
        matrix_mult_vec(0, ps->data, pd->data);
        pop_matrix();
        ps++;
        pd++;
    }
    pop_matrix();
    ((TObjEZRopeBase *)((Self_800FEEA4 *)this))->sub_800FF788(TObjEZBoneRotPlayer__chain_gravity);
}

}
