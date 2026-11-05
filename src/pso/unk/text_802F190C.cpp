#include "types.h"
#include "pso/TObject.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_802F190C.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct Obj_8003B1FC { u8 pad[0x14]; Obj_8003B1FC *child; u8 pad2[0x3c - 0x18]; u8 xf[0xC]; };

struct Ch_802F1960 { u8 pad[0x44]; f32 f; };

struct Obj_802F1960 { u8 pad0[0x14]; Ch_802F1960 *child; };

extern "C" {
s32 vec3_add_to(void *, void *);
extern void *lbl_805D6960;
void fn_802F190C(Obj_8003B1FC *self, void *arg);
void fn_802F1960(Obj_802F1960 *o, f32 d);
void fn_802F190C(Obj_8003B1FC *self, void *arg) {
    Obj_8003B1FC *c;
    while ((c = self->child) != 0) {
        vec3_add_to(c->xf, arg);
        ((TObject *)c)->set_parent((TObject *)lbl_805D6960);
    }
}
void fn_802F1960(Obj_802F1960 *o, f32 d) {
    Ch_802F1960 *c;
    while ((c = o->child) != 0) {
        c->f = c->f + d;
        ((TObject *)c)->set_parent((TObject *)lbl_805D6960);
    }
}

}

extern "C" {

int draw_ginja_model_with_motion(void*, void*, float);
void *__ct__7TObjectFP7TObject(void *, void *);
void *__nw__7TObjectFUl(int);

extern void *tl_07;
extern void *lbl_805D6960;

void fn_802F19C0(void) {
    void *o;
    o = __nw__7TObjectFUl(0x1C);
    if (o != NULL) {
        o = __ct__7TObjectFP7TObject(o, tl_07);
    }
    lbl_805D6960 = o;
}

extern int boss7_common_texture_list;

void draw_particle_effect(void* a0) {
    set_draw_list_mask((u32)((void*)3));

    TParticleCtrl::begin_effect_render();
    TObjFish::set_global_param(boss7_common_texture_list);
    set_motion_packed_rotation();

    draw_ginja_model_with_motion((void*)(*(int*)((char*)a0 + 0x1c)), (void*)(*(int*)((char*)a0 + 0x20)), *(float*)((char*)a0 + 0x28));

    clear_motion_packed_rotation();
    TParticleCtrl::end_effect_render();
    restore_draw_list_mask();
}

} // extern "C"
