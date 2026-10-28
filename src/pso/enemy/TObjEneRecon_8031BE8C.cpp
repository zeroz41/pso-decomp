#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneRecon_8031BE8C.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct VBase_14_fddec9 { char pad[0x14]; };

struct VObj_14_fddec9 : VBase_14_fddec9 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8();
};

struct VBase_18_1fdb47 { char pad[0x18]; };

struct VObj_18_1fdb47 : VBase_18_1fdb47 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    virtual s32 m9(f32, f32, f32);
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual s32 m104();
};

struct Vec_8031BE8C { f32 x, y, z; };

struct Recon_8031BE8C { u8 pad[0x480]; VObj_14_fddec9 fade; };

extern "C" {
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_player_state__9TObjEneDDFv(void *, void *, int);
s32 defer_render__7TObjectFv(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
extern Vec_8031BE8C lbl_804760FC;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 recon_intro_stage;
extern u8 *recon_model_matrix_ptr;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern const f32 lbl_805DF3BC;
extern const f32 TObjEneRecon__data_805DF3C0;
extern const f32 TObjEneRecon__data_805DF3C4;
#pragma push
#pragma opt_common_subs off
void render__12TObjEneReconFv(u8 *ene_recon) {
    s32 var_r29;
    s32 var_r31;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_18_1fdb47 *)(ene_recon))->m104();
        return;
    }
    if (!(*(s32 *)((s8 *)ene_recon + 0x444) & 1)) {
        if (is_main_phase_15__9TObjEneDDFv() != 0) {
            var_r31 = ((VObj_18_1fdb47 *)(ene_recon))->m9(lbl_805D9E88, lbl_805D9E84, TObjEneRecon__data_805DF3C0);
        } else if (((VObj_18_1fdb47 *)(ene_recon))->m8(lbl_805DF3BC, TObjEneRecon__data_805DF3C0) != 0) {
            var_r31 = 1;
        } else {
            var_r31 = 0;
        }
        if (var_r31 != 0) {
            var_r29 = 1;
            if (((TObjEneRecon *)ene_recon)->render_model_if_visible() == 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                if (((s16) *(s16 *)((s8 *)ene_recon + 0x326) == 5) && (((Recon_8031BE8C *)ene_recon)->fade.m8() != 0)) {
                    ((Recon_8031BE8C *)ene_recon)->fade.m6();
                    if (defer_render__7TObjectFv(ene_recon) != 0) {
                        var_r29 = 0;
                    }
                }
                if (var_r29 != 0) {
                    if ((*(s32 *)((s8 *)ene_recon + 0x444) & 2) && !(*(s32 *)((s8 *)ene_recon + 0x418) & 0x4000)) {
                        Vec_8031BE8C v = lbl_804760FC;
                        update_player_state__9TObjEneDDFv(ene_recon, &v, 0);
                    }
                    ((TObjEneDD *)ene_recon)->update_secondary_light();
                    TObjFish::set_global_param((int) (*(s32 *)((s8 *)ene_recon + 0x24)));
                    push_matrix();
                    translate_matrix(0, (f32) (*(f32 *)((s8 *)ene_recon + 0x38)), (f32) (*(f32 *)((s8 *)ene_recon + 0x448)), (f32) (*(f32 *)((s8 *)ene_recon + 0x40)));
                    rotate_matrix_y(0, (int) (*(s32 *)((s8 *)ene_recon + 0x60)));
                    TObjEneDD::clear_global_flag_400();
                    recon_intro_stage = 0;
                    recon_model_matrix_ptr = ene_recon + 0x40C;
                    *(f32 *)((s8 *)ene_recon + 0x40C) = (f32) TObjEneRecon__data_805DF3C4;
                    *(f32 *)((s8 *)ene_recon + 0x410) = (f32) TObjEneRecon__data_805DF3C4;
                    *(f32 *)((s8 *)ene_recon + 0x414) = (f32) TObjEneRecon__data_805DF3C4;
                    TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneRecon::advance_intro_stage));
                    TObjPlayer::toggle_particle_effect();
                    model_render_flags |= 0x01000000;
                    if (var_r31 == 1) {
                        ((TObjMotion *)ene_recon)->draw();
                    } else {
                        ((TObjEnemy *)ene_recon)->render_world_model();
                    }
                    model_render_flags &= 0xFEFFFFFF;
                    TParticleCtrl::end_effect_render();
                    TObjEneRe7Berura::set_global_state(NULL);
                    pop_matrix();
                    ((TObjEneDD *)ene_recon)->update_primary_light();
                }
                if (((s16) *(s16 *)((s8 *)ene_recon + 0x326) == 5) && (((Recon_8031BE8C *)ene_recon)->fade.m8() != 0)) {
                    ((Recon_8031BE8C *)ene_recon)->fade.m7();
                }
                model_render_flags = saved_model_render_flags;
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            }
        }
    }
}
#pragma pop

}
