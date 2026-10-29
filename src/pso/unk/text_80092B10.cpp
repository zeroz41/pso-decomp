#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct VBase_80092B10 { char pad[0x18]; };
struct VObj_80092B10 : VBase_80092B10 {
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

extern "C" {

int TObjEneRe7Berura__sub_80095328(void*);

typedef struct { s32 x, y, z; } Vec_80092B10;
typedef struct { u32 pad0; u32 count; } Motion_80092B10;
typedef struct { u32 pad0; Motion_80092B10 *motion; } MotEnt_80092B10;
typedef struct { u32 pad0; s32 index; u32 pad8[2]; } Anim_80092B10;

typedef struct {
    VObj_80092B10 v;
    u8 pad1c[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    u8 f38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0xD8 - 0x64];
    Anim_80092B10 *anims;
    MotEnt_80092B10 *mots;
    u8 padE0[0x326 - 0xE0];
    s16 f326;
    u8 pad328[0x354 - 0x328];
    f32 f354;
    f32 f358;
} Ene_80092B10;

void update_player_state__9TObjEneDDFv(void *, Vec_80092B10 *, s32);
s32 rotate_matrix_y(int, int);
void push_matrix(void);
void post_translate_matrix(void *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern Vec_80092B10 re7_berura_init_vec;
extern const f32 TObjEneRe7Berura__data_805D9724;
extern const f32 lbl_805D9728;
extern const f32 TObjEneRe7Berura__data_805D972C;

void TObjEneRe7Berura::vfunc_105() {
    Ene_80092B10 *self = (Ene_80092B10 *)this;
    s32 idx;
    Motion_80092B10 *mot;
    f32 frame;

    ((TObjEneDD *)self)->get_target_info();
    if (self->v.m8(TObjEneRe7Berura__data_805D9724, lbl_805D9728) != 0) {
        if (self->f326 != 0xB) {
            Vec_80092B10 v = re7_berura_init_vec;
            update_player_state__9TObjEneDDFv(self, &v, 0);
        }
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(self->f24);
        push_matrix();
        post_translate_matrix(self->f38);
        rotate_matrix_y(0, self->f60);
        idx = (s32)self->f354;
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 8) {
            idx = 7;
        }
        mot = self->mots[self->anims[idx].index].motion;
        frame = self->f358;
        if (frame < TObjEneRe7Berura__data_805D972C) {
            frame = TObjEneRe7Berura__data_805D972C;
        } else if (frame > (mot->count - 1)) {
            frame = (f32)mot->count;
        }
        set_motion_packed_rotation();
        draw_model_motion((void *)self->f34, mot, frame);
        clear_motion_packed_rotation();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
void TObjEneRe7Berura::vfunc_83() { if (get_target_info() != 0) { TObjEneRe7Berura__sub_80095328(this); } }

}
