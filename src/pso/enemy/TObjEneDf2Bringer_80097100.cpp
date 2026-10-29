#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDf2Bringer.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/misc/TBreakUpMdl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80096F54_TBreakUpMdl__data_8048FA00 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80096F54_TBreakUpMdl__data_8048FA00_size[sizeof(RecoveredGlobal_80096F54_TBreakUpMdl__data_8048FA00) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80096F54_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_80096F54_lbl_8058D490_size[sizeof(RecoveredGlobal_80096F54_lbl_8058D490) == 0x30 ? 1 : -1];

struct RecoveredGlobal_80096FD8_TBreakUpMdl__data_8048FA00 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80096FD8_TBreakUpMdl__data_8048FA00_size[sizeof(RecoveredGlobal_80096FD8_TBreakUpMdl__data_8048FA00) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80096FD8_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_80096FD8_lbl_8058D490_size[sizeof(RecoveredGlobal_80096FD8_lbl_8058D490) == 0x30 ? 1 : -1];

struct RecoveredGlobal_80096F54_lbl_8058D490;

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
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

struct Vec_80097100 { f32 x, y, z; };

struct Motion_80097100 { u8 pad0[4]; u32 count; };

struct MotRef_80097100 { u8 pad0[4]; Motion_80097100 *mot; };

struct Anim_80097100 { u8 pad0[4]; s32 idx; u8 pad8[8]; };

struct Bringer_80097100 : VObj_18_26a62c {
    u8 pad1C[0x24 - 0x1C];
    void *texlist;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    u8 pos[0x60 - 0x38];
    s32 f60;
    u8 pad64[0xD8 - 0x64];
    Anim_80097100 *anims;
    MotRef_80097100 *mots;
    u8 padE0[0x354 - 0xE0];
    f32 animIdx;
    f32 frame;
};

extern "C" {
s32 push_matrix();
s32 post_translate_matrix(void *);
void rotate_matrix_y(s32, s32);
s32 update_player_state__9TObjEneDDFv(void *, void *, int);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern Vec_80097100 lbl_8043A0E0;
extern const f32 lbl_805D97D8;
extern const f32 lbl_805D97DC;
extern const f32 TObjEneDf2Bringer__data_805D97E0;
int TObjEneDf2Bringer__sub_800994F8(void*);

void TObjEneDf2Bringer::vfunc_105() {
    Bringer_80097100 *self = (Bringer_80097100 *)this;
    f32 frame;
    s32 i;
    Motion_80097100 *mot;
    ((TObjEneDD *)self)->get_target_info();
    if (self->m8(lbl_805D97D8, lbl_805D97DC) != 0) {
        Vec_80097100 v = lbl_8043A0E0;
        update_player_state__9TObjEneDDFv(self, &v, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param((s32)self->texlist);
        push_matrix();
        post_translate_matrix(self->pos);
        rotate_matrix_y(0, self->f60);
        i = (s32)self->animIdx;
        if (i < 0) {
            i = 0;
        } else if (i >= 11) {
            i = 10;
        }
        mot = self->mots[self->anims[i].idx].mot;
        frame = self->frame;
        if (frame < TObjEneDf2Bringer__data_805D97E0) {
            frame = TObjEneDf2Bringer__data_805D97E0;
        } else if (frame > (mot->count - 1)) {
            frame = (mot->count - 1);
        }
        set_motion_packed_rotation();
        draw_model_motion((void *)self->f34, mot, frame);
        clear_motion_packed_rotation();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneDf2Bringer::vfunc_83() { if (get_target_info() != 0) { TObjEneDf2Bringer__sub_800994F8(this); } }

}
