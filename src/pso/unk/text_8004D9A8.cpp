#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/TObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_8004D9A8.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss4Uro.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"

extern "C" {

s32 TObjPlayer__sub_80052390();
s32 push_matrix();
s32 post_translate_matrix(void *);
extern void *lbl_80485550[3];

struct O_8004D9A8 { u8 pad0[0xBC]; s32 bc[6]; s32 d4[6]; s32 ec[6]; f32 f104; f32 f108; f32 f10c; };
void fn_8004D9A8(u8 *arg0) {
    O_8004D9A8 *o = (O_8004D9A8 *)arg0;
    s32 i;
    f32 s;

    if ((0.0f) != o->f10c) {
        if (o->f10c < (1.0f)) {
            TObjPlayer__sub_80052390();
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(lbl_80485550);
        for (i = 0; i < 6; i++) {
            s = o->f108;
            if (i == 0 || i == 1) {
                s = o->f104;
            }
            TObjFish::set_global_param(o->d4[i]);
            draw_model_motion((void *)o->bc[i], (void *)o->ec[i], s);
        }
        clear_motion_packed_rotation();
        pop_matrix();
        if (o->f10c < (1.0f)) {
            TObjPlayer::sync_player_globals();
        }
    }
}

}

typedef struct { f32 x, y, z; } Vec_8004DA7C;
struct Self_8004DA7C { u8 pad[0x90]; s32 t; u8 pad94[0x14]; void *p[5]; u8 padbc[0x48]; f32 f104; f32 f108; f32 f10c; };

struct Ent_8004DA7C { s32 arg; s32 start; s32 end; u8 data[0xC]; };

extern "C" {
void subtract_vector(void *, void *);
void normalize_vector(void *);
void vec3_add_to(void *, void *);
s32 play_sound_effect(int, void *, int, int);
void *TObjDFDemo0__entry_table[30] = {
    (void *)0x14b, (void *)0x0, (void *)0x82, (void *)0x0,
    (void *)0x0, (void *)0xc2f00000, (void *)0x14c, (void *)0x50,
    (void *)0x8c, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x14c, (void *)0x64, (void *)0x8c, (void *)0x43020000,
    (void *)0x0, (void *)0xc2f00000, (void *)0x14c, (void *)0x78,
    (void *)0x8c, (void *)0xc3020000, (void *)0x0, (void *)0xc2f00000,
    (void *)0x14d, (void *)0x92, (void *)0xc8, (void *)0x0,
    (void *)0x0, (void *)0xc2f00000,
};
void *lbl_804854D8[6] = {
    (void *)0x50, (void *)0x4e, (void *)0x19, (void *)0x19,
    (void *)0x19, (void *)0x18,
};
void *lbl_804854F0[3] = {
    (void *)0x0, (void *)0x0, (void *)0xc2f00000,
};
void *lbl_804854FC[3] = {
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_80485508[3] = {
    (void *)0x10000, (void *)0x0, (void *)0x3f000000,
};
void *lbl_80485514[15] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41f00000,
    (void *)0x0, (void *)0x42700000, (void *)0x0, (void *)0x42700000,
    (void *)0x0, (void *)0xc1f00000, (void *)0x0, (void *)0x42700000,
    (void *)0x0, (void *)0x42f00000, (void *)0x0,
};
#define TObjDFDemo0__entry_table ((u8 *)TObjDFDemo0__entry_table)
#define lbl_804854F0 ((u8 *)lbl_804854F0)
#define lbl_80485514 ((u8 *)lbl_80485514)
#define V90 (*(Vec_8004DA7C *)lbl_804854F0)
void TBoss3Volopt__sub_8004DA7C(u8 *self) {
    s32 i;
    Self_8004DA7C *S = (Self_8004DA7C *)self;
    f32 v;
    for (i = 0; i < 5; i++) {
        Ent_8004DA7C *e = &((Ent_8004DA7C *)TObjDFDemo0__entry_table)[i];
        s32 t = *(s32 *)((s8 *)self + 0x90);
        if (t >= e->end) {
            if (((Self_8004DA7C *)self)->p[i] != NULL) {
                TParticleCtrl::release(((Self_8004DA7C *)self)->p[i]);
                ((Self_8004DA7C *)self)->p[i] = NULL;
            }
        } else if (t >= e->start) {
            if (((Self_8004DA7C *)self)->p[i] == NULL) {
                ((Self_8004DA7C *)self)->p[i] = create_particle_emitter(e->data, e->arg);
                if (((Self_8004DA7C *)self)->p[i] != NULL) {
                    ((TParticleCtrl *)(((Self_8004DA7C *)self)->p[i]))->set_flags(0x40);
                }
            }
            switch (i) {
            case 1: case 2: case 3: {
                u8 *p = (u8 *)((Self_8004DA7C *)self)->p[i];
                if (p != NULL) {
                    Vec_8004DA7C a = *(Vec_8004DA7C *)(p + 0x60);
                    Vec_8004DA7C b = V90;
                    subtract_vector(&b, &a);
                    b.y = (0.0f);
                    normalize_vector(&b);
                    b.x *= (1.95f);
                    b.z *= (1.95f);
                    vec3_add_to(&a, &b);
                    ((TParticleCtrl *)((Self_8004DA7C *)self)->p[i])->set_position(&a);
                }
            }
            break;
            }
        }
    }
    {
        s32 t = *(s32 *)((s8 *)self + 0x90);
        if (t >= 0x8C && t < 0x91) {
            void *p;
            Vec_8004DA7C c = V90;
            vec3_add_to(&c, &((Vec_8004DA7C *)lbl_80485514)[t - 0x8C]);
            p = spawn_particle_effect(&c, 0x14A);
            if (p != NULL) {
                ((TParticleCtrl *)p)->set_flags(0x40);
            }
        }
    }
    if (*(s32 *)((s8 *)self + 0x90) >= 0xAA) {
        v = (0.1f); v = S->f10c + v;
        S->f10c = v;
        if (v > 1.0f) {
            S->f10c = 1.0f;
        }
    }
    v = (0.5f); v = S->f104 + v;
    S->f104 = v;
    if (v >= (3e+01f)) {
        S->f104 = (0.0f);
    }
    v = (0.5f); v = S->f108 + v;
    S->f108 = v;
    if (v > 139.0f) {
        S->f108 = 139.0f;
    }
    switch (*(s32 *)((s8 *)self + 0x90)) {
    case 0:
        play_sound_effect(0x4003BC07, lbl_804854F0, 0, 1);
        play_sound_effect(0x3C604, lbl_804854F0, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
        break;
    case 0x50:
        play_sound_effect(0x3A805, 0, 0, 0);
    case 0x64:
    case 0x78:
        play_sound_effect(0x4003D006, lbl_804854F0, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
        break;
    case 0x8C:
        play_sound_effect(0x36408, lbl_804854F0, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
        break;
    case 0x92:
        play_sound_effect(0x3DA03, lbl_804854F0, 0, 1);
        break;
    case 0xAA:
        play_sound_effect(0x40039E09, lbl_804854F0, 0, 1);
        break;
    case 0xC8:
        play_sound_effect(0x40039E21, lbl_804854F0, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
        break;
    }
    ((TBoss4Type2 *)(self + 0x94))->scroll_strips();
    if (++*(s32 *)((s8 *)self + 0x90) >= 0x118) {
        queue_destruction__7TObjectFv(self);
    }
}

#undef TObjDFDemo0__entry_table
#undef lbl_804854F0
#undef lbl_80485514
#undef V90
void *lbl_80485550[3] = {
    (void *)0x0, (void *)0x0, (void *)0xc2f00000,
};
}

struct S_8004DE44 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x94 - 0x1c];
    u8 f94[0x14];
    void *ptr[5];
};

extern "C" {
void fn_8004AA04(void *);
void __dl__7TObjectFPv(void *);
extern void *__vt__11TObjDFDemo0[13];
S_8004DE44 *__dt__11TObjDFDemo0Fv(S_8004DE44 *o, s16 flag);
S_8004DE44 *__dt__11TObjDFDemo0Fv(S_8004DE44 *o, s16 flag) {
    s32 i;
    if (o != 0) {
        o->vt = __vt__11TObjDFDemo0;
        fn_8004AA04(o->f94);
        for (i = 0; i < 5; i++) {
            if (o->ptr[i] != 0) {
                TParticleCtrl::release(o->ptr[i]);
                o->ptr[i] = 0;
            }
        }
        restore_player_cameras();
        __dt__8TObjBaseFv(o, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(o);
        }
    }
    return o;
}

typedef struct Obj_8004DEE0 {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u8 pad1c[0x90 - 0x1c];
    s32 f90;
    u8 f94[0xA8 - 0x94];
    s32 fa8[5];
    s32 fbc[3][6];
    f32 f104;
    f32 f108;
    f32 f10c;
} Obj_8004DEE0;

typedef struct Data_8004DEE0 {
    u8 pad0[0x78];
    s32 f78[6];
    f32 f90[3];
    f32 f9c[3];
    f32 fa8[3];
    u8 padb4[0xFC - 0xB4];
    u8 vt[4];
} Data_8004DEE0;

s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
void init_model_node_tables(void *, void *, s32);
void set_scripted_camera_pose(void *, void *, void *);
void __ct__8TObjBaseFP7TObject(void *, void *);
extern u8 TObjDFDemo0__model_node_entries[];
extern s32 lbl_80485EB0[];
extern s32 TObjDFDemo0__name;

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void get_name__8TObjBaseFv();
extern "C" void get_center__8TObjBaseFv();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void render_shadows__7TObjectFv();
extern "C" void reset_motion_fields__8TObjBaseFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
void *__vt__11TObjDFDemo0[13] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__11TObjDFDemo0Fv, (void *)&TBoss3Volopt__sub_8004DA7C,
    (void *)&fn_8004D9A8, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__8TObjBaseFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv,
};

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
Obj_8004DEE0 *TObjDFDemo0__ct(void *arg0, void *parent) {
    Obj_8004DEE0 *self = (Obj_8004DEE0 *)arg0;
    s32 k;
    s32 h;
    s32 i;
    s32 j;

    __ct__8TObjBaseFP7TObject(self, parent);
    self->vt = (void *)__vt__11TObjDFDemo0;
    self->f0 = TObjDFDemo0__name;
    h = TBoss4Uro::get_instance_count();
    for (i = 0; i < 6; i++) {
        {
            s32 t = lbl_80485EB0[i];
            k = t;
            self->fbc[0][i] = get_bml_model(h, t);
        }
        self->fbc[1][i] = TObjFish__sub_8001EDB0(h, k);
        self->fbc[2][i] = get_bml_motion(h, ((s32 *)lbl_804854D8)[i]);
    }
    self->f104 = (-0.5f);
    self->f108 = (-0.5f);
    for (j = 0; j < 5; j++) {
        self->fa8[j] = 0;
    }
    init_model_node_tables(self->f94, TObjDFDemo0__model_node_entries, 7);
    activate_camera_mode(5);
    set_scripted_camera_pose(lbl_804854F0, lbl_804854F0, lbl_804854FC);
    ((TCameraCtrl *)lbl_80485508)->cache_target_and_forward(0x416C);
    self->f10c = (0.0f);
    play_sound_effect(0x40039E21, lbl_804854F0, 0, 1);
    self->f90 = 0;
    return self;
}
#pragma pop

}
