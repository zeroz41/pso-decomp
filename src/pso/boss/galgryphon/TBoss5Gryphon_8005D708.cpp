#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/object/ambient/TObjFish.h"
struct Cnt_8005D708 { u32 f0; u32 count; };

struct Mot_8005D708 { u32 f0; Cnt_8005D708 *p; };

struct Anm_8005D708 { u32 f0; s32 idx; u32 f8; u32 fc; };

struct VBase_8005D708 { char pad[0x18]; };

struct VObj_8005D708 : VBase_8005D708 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Obj_8005D708 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0xC];
    s32 f34;
    u8 pad38[0x28];
    s32 f60;
    u8 pad64[0xD8 - 0x64];
    Anm_8005D708 *anims;
    Mot_8005D708 *mots;
    u8 pade0[0x354 - 0xE0];
    f32 f354;
    f32 f358;
};

extern "C" {
void TObjLight__sub_801337F8(s32);
void scale_matrix(s32, f32, f32, f32);
void rotate_matrix_y(s32, s32);
void push_matrix();
void post_translate_matrix(void *);
extern s32 current_scene_light;
extern u32 model_render_flags;
extern const f32 lbl_805D8D4C;
extern const f32 lbl_805D8D50;
extern const f32 lbl_805D8D54;
extern const f32 lbl_805D8D58;
extern const f32 lbl_805D8D5C;
int TBoss5Gryphon::vfunc_105() {
#define o ((Obj_8005D708 *)this)
    Cnt_8005D708 *c;
    f32 f;
    s32 idx;
    if (((VObj_8005D708 *)this)->m8(lbl_805D8D4C, lbl_805D8D50) != 0) {
        TObjFish::set_global_param(o->f24);
        push_matrix();
        post_translate_matrix((u8 *)this + 0x38);
        rotate_matrix_y(0, o->f60);
        push_matrix();
        scale_matrix(0, lbl_805D8D54, lbl_805D8D58, lbl_805D8D54);
        pop_matrix();
        scale_matrix(0, lbl_805D8D58, lbl_805D8D58, lbl_805D8D58);
        model_render_flags &= ~0x400;
        idx = (s32)o->f354;
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x1B) {
            idx = 0x1A;
        }
        c = o->mots[o->anims[idx].idx].p;
        f = o->f358;
        if (f < lbl_805D8D5C) {
            f = lbl_805D8D5C;
        } else {
            u32 n = c->count;
            if (f > (n - 1)) {
                f = (f32)n;
            }
        }
        draw_model_motion((void *)o->f34, c, f);
        TObjLight__sub_801337F8(current_scene_light);
        pop_matrix();
    }
#undef o
}

}
