#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneDD_800BB804.h"
#include "pso/enemy/TObjEneRecon_8031E88C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneRecobox.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

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

struct FadeBase_8031EA70 { char pad[0x14]; };

struct Fade_8031EA70 : FadeBase_8031EA70 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8();
    u8 pad18[4];
};

struct ObjBase_8031EA70 { char pad[0x18]; };

struct Obj_8031EA70 : ObjBase_8031EA70 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
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
    virtual void m104();
};

struct Holder_8031EA70 { u8 pad[0x460]; Fade_8031EA70 arr[4]; };

extern "C" {
s32 get_target_info__9TObjEneDDFv();
s32 debug_printf_at(s32, const char *, ...);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern char lbl_804763D4[];
extern char lbl_804763E4[];
extern char lbl_804763F4[];
extern char lbl_80476400[];
extern char lbl_80476410[];
extern char lbl_80476428[];
extern char lbl_80476440[];
extern s32 debug_chunk_object;
extern const f32 TObjEneRecon__data_805DF438;
extern const f32 lbl_805DF43C;
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_obstruction_fade(int);
s32 defer_render__7TObjectFv(void *);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern const f32 lbl_805DF440;
extern const f32 lbl_805DF444;
void TObjEneRecobox::draw_with_debug_info() {
    u8 *arg0 = (u8 *)this;
    if (get_target_info__9TObjEneDDFv() != 0) {
        switch (this->m_3f8) {
        case 0:
            debug_printf_at(pack_debug_text_position(0, 9), lbl_804763D4);
            break;
        case 1:
            debug_printf_at(pack_debug_text_position(0, 9), lbl_804763E4);
            break;
        case 2:
            debug_printf_at(pack_debug_text_position(0, 9), lbl_804763F4);
            break;
        }
        debug_printf_at(pack_debug_text_position(0, 0xA), lbl_80476400);
        debug_printf_at(pack_debug_text_position(0, 2), lbl_80476410);
        debug_printf_at(pack_debug_text_position(0, 3), lbl_80476428);
        debug_printf_at(pack_debug_text_position(0, 5), lbl_80476440);
    }
    if (((VObj_18_26a62c *)(arg0))->m8(TObjEneRecon__data_805DF438, lbl_805DF43C) != 0) {
        TObjFish::set_global_param(this->texture_id);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        switch (this->m_3f8) {
        case 1:
            rotate_matrix_x(0, 0x8000);
            break;
        case 2:
            rotate_matrix_x(0, 0x4000);
            break;
        }
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(this->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
    push_matrix();
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    draw_chunk_object((void *)debug_chunk_object);
    pop_matrix();
}
void TObjEneRecobox::render() {
    s32 temp_r30;
    Fade_8031EA70 *temp_r29;
    s32 var_r29;
    s32 var_r28;
    s32 var_r27;
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneRecobox *)arg0)->draw_with_debug_info();
        return;
    }
    var_r29 = 0;
    if (is_split_screen() != 0) {
        var_r29 = get_camera_mode__11TCameraCtrlFv();
    }
    if (!(*(s32 *)((s8 *)arg0 + 0x40C) & 1)) {
        if (is_main_phase_15__9TObjEneDDFv() != 0) {
            var_r28 = ((Obj_8031EA70 *)arg0)->m9(lbl_805DF440 + lbl_805D9E88, lbl_805DF444 + lbl_805D9E84, lbl_805DF43C);
        } else if (((Obj_8031EA70 *)arg0)->m8(TObjEneRecon__data_805DF438, lbl_805DF43C) != 0) {
            var_r28 = 1;
        } else {
            var_r28 = 0;
        }
        if (var_r28 != 0) {
            var_r27 = 0;
            if (((TObjEneRecobox *)arg0)->render_trap_model_if_visible() == 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                if ((s16) ((TObjEneRecobox *)arg0)->mode == 1) {
                    if (((Fade_8031EA70 *)(arg0 + 0x3C0))->m8() != 0) {
                        if (defer_render__7TObjectFv(arg0) != 0) {
                            model_render_flags = saved_model_render_flags;
                            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                            return;
                        }
                        var_r27 = 1;
                        ((Fade_8031EA70 *)(arg0 + 0x3C0))->m6();
                        goto block_18;
                    }
                    model_render_flags = saved_model_render_flags;
                    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                    return;
                }
block_18:
                temp_r29 = &((Holder_8031EA70 *)arg0)->arr[var_r29];
                update_obstruction_fade((int)temp_r29);
                temp_r30 = ((RenderFadeState *)temp_r29)->updateFromCamera((const f32*)(arg0 + 0x2FC));
                if ((var_r27 == 0) && (temp_r30 != 0)) {
                    if (defer_render__7TObjectFv(arg0) != 0) {
                        model_render_flags = saved_model_render_flags;
                        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                        return;
                    }
                    temp_r29->m6();
                    goto block_23;
                }
block_23:
                ((TObjEneDD *)arg0)->update_secondary_light();
                TObjFish::set_global_param((int) (((TObjEneRecobox *)arg0)->texture_id));
                push_matrix();
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_y(0, (int) (((TObjEneRecobox *)arg0)->rotation_y));
                switch (((TObjEneRecobox *)arg0)->m_3f8) {
                case 1:
                    rotate_matrix_x(0, 0x8000);
                    break;
                case 2:
                    rotate_matrix_x(0, 0x4000);
                    break;
                }
                TObjEneDD::clear_global_flag_400();
                TObjPlayer::toggle_particle_effect();
                if (var_r28 == 1) {
                    ((TObjMotion *)arg0)->draw();
                } else {
                    ((TObjEnemy *)arg0)->render_world_model();
                }
                TParticleCtrl::end_effect_render();
                pop_matrix();
                ((TObjEneDD *)arg0)->update_primary_light();
                if (var_r27 != 0) {
                    ((Fade_8031EA70 *)(arg0 + 0x3C0))->m7();
                } else if (temp_r30 != 0) {
                    temp_r29->m7();
                }
                model_render_flags = saved_model_render_flags;
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                goto block_37;
            }
        } else {
            goto block_37;
        }
    } else {
block_37:
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    }
}

}
