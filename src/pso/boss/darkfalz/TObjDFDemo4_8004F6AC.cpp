
#include "types.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl_800687BC.h"

extern "C" {
struct Pose_8004EB78 { s32 a; s32 b; s32 c; };
struct Pose2_8004F6AC { Pose_8004EB78 a; Pose_8004EB78 b; };
struct Obj_8004F6AC {
    s32 vt0;
    u8 pad4[0x18 - 0x4];
    void *vt18;
    u8 pad1c[0xE8 - 0x1C];
    u8 pos[0xC];
    s32 f0f4;
    u8 pad0f8[0xFC - 0xF8];
    f32 f0fc;
    s32 f100;
    s32 f104;
};
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
s32 TObjFish__sub_800E3124(void *, void *);
void set_scripted_camera_pose(void *, void *, void *);
void init_model_node_tables(void *, void *, int);
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 boss4_zanzo_bml_index_table[];
extern s32 lbl_80486FB0[];
extern s32 lbl_805D2798;
extern f32 lbl_805D8A04;
extern s32 lbl_804373C4[];
extern Pose_8004EB78 lbl_804373E8;
extern Pose_8004EB78 lbl_804373DC;
}

extern "C" {
void __dt__11TObjDFDemo4Fv(void);
void run_task__11TObjDFDemo4Fv(void);
void render__11TObjDFDemo4Fv(void);
void render_shadows__7TObjectFv(void);
void vfunc_6__8TObjBaseFPsl(void);
void apply_object_set_data__8TObjBaseFPv(void);
void reset_motion_fields__8TObjBaseFv(void);
void get_center__8TObjBaseFv(void);
void update_object_view_visibility__8TObjBaseFff(void);
void classify_actor_view_detail__8TObjBaseFfff(void);
void get_name__8TObjBaseFv(void);
}
__declspec(section ".data") s32 lbl_80485720[2] = {0x12, 0x11};
s32 lbl_80485728[3] = {0x20, 0x21, 0x22};
s32 lbl_80485734[12] = {0x34, 0, 0, 0, 0x35, 0, 0, 0, -1, 0, 0, 0};
void *lbl_80485764[13] = {
    0, 0, (void *)__dt__11TObjDFDemo4Fv, (void *)run_task__11TObjDFDemo4Fv, (void *)render__11TObjDFDemo4Fv,
    (void *)render_shadows__7TObjectFv, (void *)vfunc_6__8TObjBaseFPsl, (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__8TObjBaseFv, (void *)get_center__8TObjBaseFv,
    (void *)update_object_view_visibility__8TObjBaseFff, (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__8TObjBaseFv,
};

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void *TObjDFDemo4__ct(Obj_8004F6AC *self, void *parent, void *arg2, void *arg3) {
    s32 cnt;
    Pose2_8004F6AC p;
    s32 i;
    s32 j;
    s32 k;

    __ct__8TObjBaseFP7TObject(self, parent);
    self->vt18 = lbl_80485764;
    self->vt0 = lbl_805D2798;
    VecCopy((Vec *)self->pos, (const Vec *)arg2);
    self->f0f4 = (s32)arg3;
    cnt = TBoss4Uro::get_instance_count();
    for (j = 0; j < 2; j++) {
        s32 t = boss4_zanzo_bml_index_table[j];
        k = t;
        ((s32 *)self)[j * 3 + 0x2B] = get_bml_model(cnt, t);
        ((s32 *)self)[j * 3 + 0x2C] = TObjFish__sub_8001EDB0(cnt, k);
        ((s32 *)self)[j * 3 + 0x2D] = get_bml_motion(cnt, lbl_80485720[j]);
    }
    for (i = 0; i < 3; i++) {
        s32 t = lbl_80486FB0[i];
        k = t;
        ((s32 *)self)[i * 3 + 0x31] = get_bml_model(cnt, t);
        ((s32 *)self)[i * 3 + 0x32] = TObjFish__sub_8001EDB0(cnt, k);
        ((s32 *)self)[i * 3 + 0x33] = get_bml_motion(cnt, lbl_80485728[i]);
    }
    self->f0fc = lbl_805D8A04;
    init_model_node_tables((u8 *)self + 0x90, lbl_804373C4, 2);
    {
        s32 n;
        for (n = 0; n < 2; n++) {
            ((s32 *)self)[n + 0x29] = 0;
        }
    }
    activate_camera_mode(5);
    p.b.a = lbl_804373DC.a;
    p.b.b = lbl_804373DC.b;
    p.b.c = lbl_804373DC.c;
    p.a.a = lbl_804373E8.a;
    p.a.b = lbl_804373E8.b;
    p.a.c = lbl_804373E8.c;
    p.a.b = self->f0f4;
    {
        u8 *pos = self->pos;
        set_scripted_camera_pose(pos, pos, &p);
    }
    ((TCameraCtrl *)&p.b)->cache_target_and_forward(0x416C);
    self->f100 = TObjFish__sub_800E3124(lbl_80485734, (u8 *)self + 0x104);
    *(s32 *)((u8 *)self + 0xf8) = 0;
    return self;
}
#pragma pop
