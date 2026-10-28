#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneBm3Fly.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneGibbles.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneBm3FlyNest.h"

#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneRe7Berura.h"

struct VBase800AFB60_800AFB28 { char pad[0x18]; };
struct VObj800AFB60_800AFB28 : VBase800AFB60_800AFB28 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

#include "pso/enemy/TObjEneMoja.h"
struct MojaResourceEntry {u8 unknown[8];void* model;void* textures;};

struct MojaResources {u8 unknown[0x42C];MojaResourceEntry* models;};

struct Vec_800AFBF0 { f32 x, y, z; };

struct Base_800AFBF0 { char pad[0x18]; };

struct VObj_800AFBF0 : Base_800AFBF0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual s32 v8(f32, f32);
    virtual s32 v9(f32, f32, f32);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
};

extern MojaResources* lbl_805D50D8;
extern "C" {
s32 is_main_phase_15__9TObjEneDDFv();
s32 clear_global_flag_400__9TObjEneDDFv();
s32 update_player_state__9TObjEneDDFv(void *, s32, s32);
s32 toggle_particle_effect__10TObjPlayerFv();
s32 end_effect_render__13TParticleCtrlFv();
s32 rotate_matrix_y(s32, s32);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
s32 pop_matrix();
s32 set_global_param__8TObjFishFl(s32);
extern Vec_800AFBF0 lbl_8043B10C;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
void render__13TObjEneBm3FlyFv(VObj_800AFBF0 *o);
f32 clamp_velocity__15TObjBoss2TunnelFv(void *);
void clamp_flight_height__13TObjEneBm3FlyFv(u8 *arg0);
void update_dd_flag__13TObjEneBm3FlyFPv(void *arg0);
s32 remove_child__17TObjEneBm3FlyNestFPUc(u32, void *);
s32 refresh_and_send_entity_flags__12TBoss8DragonFv(void *, s32);
s32 TBoss8Dragon__sub_800BB7DC(void *);
s32 transition_enemy_state__9TObjEneDDFs(void *, s32);
}
void restore_default_scene(void);
void set_scene_override(u8 scene);
void spawn_landing_dead_spot(s32 point, s32 delay);
extern "C" {
s32 copy_target_state__14TObjEnePanarmsFPv(void *, s32);
s32 advance_animation_playback();
void *find_entity_by_id(u16 id);
s32 play_sound_effect(s32, void *, s32, s32);
#define clamp_flight_height__13TObjEneBm3FlyFv (*(s32 (*)(void *))&clamp_flight_height__13TObjEneBm3FlyFv)
#define update_dd_flag__13TObjEneBm3FlyFPv (*(s32 (*)(void *, f32, f32, f32))&update_dd_flag__13TObjEneBm3FlyFPv)
void TObjEneBm3Fly__vt103(void);
void TObjEneBm3Fly__vt104(TObjEneBm3Fly *arg0);
void action__13TObjEneBm3FlyFPvi(u8 *arg0, s32 arg1);
s32 TBoss8Dragon__sub_800BB7D8(void *, s32, f32);
s32 post_translate_matrix(void *);
void draw_chunk_object(void *child);
s32 queue_destruction__7TObjectFv();

f32 TObjEneGibbles::get_pos_x() { return *(f32 *)&this->m_up; }

void TObjEneMoja::bindModel(int index) {
    model=lbl_805D50D8->models[index].model;
    (*(void * *)&this->texture_id)=lbl_805D50D8->models[index].textures;
}

void TObjEneBm3Fly__vt104(TObjEneBm3Fly *arg0) {
    if (((VObj800AFB60_800AFB28 *) arg0)->m8((4e+02f), (15.0f)) != 0) {
        update_player_state__9TObjEneDDFv(arg0, 0, 0);
        set_global_param__8TObjFishFl(arg0->texture_id);
        push_matrix();
        post_translate_matrix((u8 *)arg0 + 0x38);
        rotate_matrix_y(0, arg0->rotation_y);
        clear_global_flag_400__9TObjEneDDFv();
        toggle_particle_effect__10TObjPlayerFv();
        draw_chunk_object((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
        end_effect_render__13TParticleCtrlFv();
        pop_matrix();
    }
}

void render__13TObjEneBm3FlyFv(VObj_800AFBF0 *o) {
    s32 kind;
    if (TObjPlayer::check_demo_mode() != 0) {
        o->v104();
        return;
    }
    if (*(s32 *)((s8 *)o + 0x428) & 1) {
        return;
    }
    if (is_main_phase_15__9TObjEneDDFv() != 0) {
        kind = o->v9(lbl_805D9E88, lbl_805D9E84, (15.0f));
    } else if (o->v8((4e+02f), (15.0f)) != 0) {
        kind = 1;
    } else {
        kind = 0;
    }
    if (kind != 0) {
        if (*(s32 *)((s8 *)o + 0x428) & 2) {
            Vec_800AFBF0 v = lbl_8043B10C;
            update_player_state__9TObjEneDDFv(o, (s32)&v, 0);
        }
        ((TObjEneDD *)o)->update_secondary_light();
        set_global_param__8TObjFishFl(((TObjEneBm3Fly *)o)->texture_id);
        push_matrix();
        translate_matrix(0, *(f32 *)((s8 *)o + 0x38), *(f32 *)((s8 *)o + 0x42C), *(f32 *)((s8 *)o + 0x40));
        rotate_matrix_y(0, ((TObjEneBm3Fly *)o)->rotation_y);
        clear_global_flag_400__9TObjEneDDFv();
        toggle_particle_effect__10TObjPlayerFv();
        set_scene_override(0x8F);
        if (kind == 1) {
            ((TObjMotion *)o)->draw();
        } else {
            ((TObjEnemy *)o)->render_world_model();
        }
        restore_default_scene();
        end_effect_render__13TParticleCtrlFv();
        pop_matrix();
        ((TObjEneDD *)o)->update_primary_light();
    }
}

void TObjEneBm3Fly__vt103(void) {  }
void TObjEneBm3Fly::handle_message(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)this + 0x428) = (s32) (*(s32 *)((s8 *)this + 0x428) | 1);
        *(s32 *)((s8 *)this + 0x428) = (s32) (*(s32 *)((s8 *)this + 0x428) & 0xFFFFFFFD);
        return;
    case 3:
        queue_destruction__7TObjectFv();
    case 5:
    case 0:
        return;
    }
}

extern s32 bm3_fly_breakup_params[];
extern s32 TObjEneBm3Fly__breakup_model;

void TObjEneBm3Fly::state_death_fall(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    s32 temp_r0;
    u32 temp_photon;
    s32 temp_copy;
    switch (arg1) {
    case 4:
        this->m_b8 = 4;
        ((TObjEneBm3Fly *)arg0)->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x428) = (s32) (*(s32 *)((s8 *)arg0 + 0x428) & 0xFFFFFFFE);
        *(s32 *)((s8 *)arg0 + 0x428) = (s32) (*(s32 *)((s8 *)arg0 + 0x428) | 2);
        ((s32 (*)(void *))refresh_and_send_entity_flags__12TBoss8DragonFv)(arg0);
        temp_photon = (u32)find_entity_by_id(this->owner_id);
        if (temp_photon != 0U) {
            remove_child__17TObjEneBm3FlyNestFPUc(temp_photon, arg0);
        }
        TBoss8Dragon__sub_800BB7DC(arg0);
        this->m_3c0 = 0;
        *(s32 *)((s8 *)arg0 + 0x3C4) = 0;
        this->m_3e0 = (f32) (0.0f);
        *(f32 *)((s8 *)arg0 + 0x430) = (f32) *(f32 *)((s8 *)arg0 + 0x308);
        *(f32 *)((s8 *)arg0 + 0x438) = (f32) this->m_310;
        *(f32 *)((s8 *)arg0 + 0x3E4) = clamp_velocity__15TObjBoss2TunnelFv(arg0 + 0x430);
        temp_copy = copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003E425);
        play_sound_effect(temp_copy, (u8 *)&this->position, 0, 0);
        return;
    case 3:
        if ((*(f32 *)((s8 *)arg0 + 0x42C) - *(f32 *)((s8 *)arg0 + 0x3C)) < (-2e+01f)) {
            transition_enemy_state__9TObjEneDDFs(arg0, 9);
        }
        break;
    case 0:
        advance_animation_playback();
        switch (this->m_3c0) {
        case 0:
        case 1:
            update_dd_flag__13TObjEneBm3FlyFPv(arg0, *(f32 *)((s8 *)arg0 + 0x430), *(f32 *)((s8 *)arg0 + 0x438), *(f32 *)((s8 *)arg0 + 0x3E4));
            this->m_3e0 = (f32) (this->m_3e0 - (0.1f));
            *(f32 *)((s8 *)arg0 + 0x42C) = (f32) (*(f32 *)((s8 *)arg0 + 0x42C) + this->m_3e0);
            if (*(f32 *)((s8 *)arg0 + 0x42C) < (1.2f) + *(f32 *)((s8 *)arg0 + 0x3C)) {
                *(f32 *)((s8 *)arg0 + 0x42C) = (1.2f) + *(f32 *)((s8 *)arg0 + 0x3C);
                if (((s32) this->m_3c0 == 0) && (((TObjEneDD *)arg0)->get_flag_b4() == 0)) {
                    this->m_3c0 = 1;
                    this->m_3e0 = (f32) (0.5f);
                    *(f32 *)((s8 *)arg0 + 0x3E4) *= (0.98f);
                } else {
                    this->m_3c0 = 2;
                    *(f32 *)((s8 *)arg0 + 0x3E4) = (f32) (0.0f);
                    *(s32 *)((s8 *)arg0 + 0x428) = (s32) (*(s32 *)((s8 *)arg0 + 0x428) & 0xFFFFFFFD);
                    spawn_landing_dead_spot((s32)(arg0 + 0x38), 0xA);
                    ((TObjPlayer *)(arg0 + 0x38))->spawn_effect_at_ground(0x1E);
                }
            }
            clamp_flight_height__13TObjEneBm3FlyFv(arg0);
            break;
        case 2:
            *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) + 1);
            *(f32 *)((s8 *)arg0 + 0x42C) = (f32) (*(f32 *)((s8 *)arg0 + 0x42C) - (0.1f));
            break;
        }
        *(f32 *)((s8 *)arg0 + 0x3E4) *= (0.98f);
        break;
    case 1:
    case 5:
        break;
    }
}

void action__13TObjEneBm3FlyFPvi(u8 *arg0, s32 arg1) {
    s32 temp_r4;
    u32 temp_ret;

    switch (arg1) {
    case 4:
        ((TObjEneDD *)arg0)->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x428) = (s32) (*(s32 *)((s8 *)arg0 + 0x428) | 1);
        temp_r4 = *(s32 *)((s8 *)arg0 + 0x428) & 0xFFFFFFFD;
        *(s32 *)((s8 *)arg0 + 0x428) = temp_r4;
        *(s32 *)((s8 *)arg0 + 0x80) = 0;
        refresh_and_send_entity_flags__12TBoss8DragonFv(arg0, temp_r4);
        temp_ret = (u32)find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x418));
        if (temp_ret != 0U) {
            remove_child__17TObjEneBm3FlyNestFPUc(temp_ret, arg0);
        }
        TBoss8Dragon__sub_800BB7DC(arg0);
        TBoss8Dragon__sub_800BB7D8(arg0, 0xF1, (1.0f));
        play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003E425), arg0 + 0x38, 0, 0);
        TBoss3Volopt::create_breakup_mdl((s32)TObjEneBm3Fly__breakup_model, (s32)bm3_fly_breakup_params, (s32)(*(s32 *)((s8 *)arg0 + 0x24)), (s32)(arg0 + 0x2FC), (s32)(*(s32 *)((s8 *)arg0 + 0x60)));
        *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x3C0) >= 2) {
            transition_enemy_state__9TObjEneDDFs(arg0, 9);
        }
    case 5:
        return;
    case 0:
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) + 1);
        break;
    }
}
}

#undef clamp_flight_height__13TObjEneBm3FlyFv
#undef update_dd_flag__13TObjEneBm3FlyFPv

struct VBaseB0_800b07d0 { char pad[0x18]; };
struct VObjB0_800b07d0 : VBaseB0_800b07d0 {
    virtual void v0();  virtual void v1();  virtual void v2();  virtual void v3();
    virtual void v4();  virtual void v5();  virtual void v6();  virtual void v7();
    virtual void v8();  virtual void v9();  virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual s32 v18(void *, f32);
    virtual void v19(); virtual void v20(void *, f32);
    virtual void v21(); virtual void v22(); virtual void v23(void *, f32);
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
    virtual void v92(); virtual void v93(); virtual void v94();
};

struct VBase_800B0B20 { char pad[0x18]; };
struct VObj_800B0B20 : VBase_800B0B20 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
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
    virtual s32 m102(f32);
};

struct Vec_800B0B20 { f32 x, y, z; };
extern "C" {
s32 vec3_add_to(void *, void *);
f32 vec3_dot(void *, void *);
s32 subtract_vector(void *, void *);
}

struct Base_800B012C { u8 pad[0x18]; };

struct Ene_800B012C : Base_800B012C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void m87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void m94();
    virtual void v95();
    virtual void v96();
    virtual s32 m97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void m102(f32);
};

struct V3_800B012C { f32 x, y, z; };

struct P_800B012C { u8 pad[0x430]; V3_800B012C v; };

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
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
    virtual s32 m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual s32 m93();
};

struct VBase_800B044C { char pad[0x18]; };

struct VObj_800B044C : VBase_800B044C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
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
    virtual s32 m102(f32);
};

struct Vec_800B0F70 { f32 x, y, z; };

extern "C" {
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjEneBm3Fly__play_orbit_flight_sound(s32 arg0);
f32 calc_scaled_value__15TObjBoss2TunnelFlf(int, int, f32, f32);
void sub_800B1634__13TObjEneBm3FlyFv(u8 *arg0);
f32 approach_value__13TObjEneBm3FlyFff(f32 farg0, f32 farg1);
s32 update_linked_position__12TObjEneDD_STFf(f32);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
void TObjEneBm3Fly__sub_800B02C8(TObjEneBm3Fly *arg0, s32 arg1);
struct Fly_800B1684;
void choose_attack__13TObjEneBm3FlyFPv(Fly_800B1684 *s);
s32 clear_attack_receipts__9TObjEneDDFv();
s32 noop__12TBoss8DragonFv(void *);
s32 set_field_378__9TObjEneDDFl(void *, s16);
f32 atan2_float(f32, f32);
f32 update_scale__15TObjBoss2TunnelFv(void *);
void update_collide_flag__13TObjEneBm3FlyFv(void *arg0);
s32 enemy_clear_target__12TObjEneDD_STFUs(void *);
extern const f64 TObjEneBm3Fly__data_8043B118[];
extern const f32 lbl_805D9E80;
void TObjEneBm3Fly__sub_800B1214(u8 *arg0, s32 arg1);
f32 calc_boss4_scale__10TObjPlayerFi(s32 arg0);
s32 is_vec_xz_cross_negative(void *, void *);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
void TObjEneBm3Fly__sub_800B0F70(u8 *arg0, s32 arg1);
struct Base_800B150C_800B07D0 { char pad[0x18]; };
struct VObj_800B150C_800B07D0 : Base_800B150C_800B07D0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(); virtual void m94(); virtual void m95();
    virtual void m96(); virtual int m97();
};

void TObjEneBm3Fly__vt102(void *arg0, f32 farg0);
s32 spawn_part__14TObjEneEpsilonFi(void *, f32);

extern u8 *lbl_805D50EC;

#pragma push
#pragma opt_common_subs off
typedef void (*Fv_800B012C)(void *);
typedef s32 (*Fi_800B012C)(void *);
typedef void (*Ff_800B012C)(void *, f32);
void TObjEneBm3Fly::update_recoil_state(s32 arg1) {
    s32 t;
    f32 v;
    switch (arg1) {
    case 4:
        this->m_b8 = 3;
        this->vfunc_96();
        *(u32 *)((s8 *)((u8 *)this) + 0x428) &= ~1;
        *(u32 *)((s8 *)((u8 *)this) + 0x428) |= 2;
        set_field_378__9TObjEneDDFl(this, this->mode);
        noop__12TBoss8DragonFv(this);
        play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(this, 0x4003E425), ((u8 *)this) + 0x38, 0, 0);
        this->m_3c0 = 0;
        break;
    case 3:
        if (this->animationFlags & 0x10) {
            if (((Ene_800B012C *)((u8 *)this))->m97() != 0) {
                ((Ene_800B012C *)((u8 *)this))->m102((2e+02f));
            }
#define copy_target_state__14TObjEnePanarmsFPv (*(void * (*)(void *, int))&copy_target_state__14TObjEnePanarmsFPv)
#define sub_800B1634__13TObjEneBm3FlyFv (*(s32 (*)(void *))&sub_800B1634__13TObjEneBm3FlyFv)
#define approach_value__13TObjEneBm3FlyFff (*(f32 (*)(void *, f32, f32))&approach_value__13TObjEneBm3FlyFff)
#define clamp_flight_height__13TObjEneBm3FlyFv (*(s32 (*)(void *))&clamp_flight_height__13TObjEneBm3FlyFv)
#define transition_enemy_state__9TObjEneDDFs (*(s32 (*)(void *, int))&transition_enemy_state__9TObjEneDDFs)
#define clamp_velocity__15TObjBoss2TunnelFv (*(f32 (*)(void *, s32))&clamp_velocity__15TObjBoss2TunnelFv)
#define choose_attack__13TObjEneBm3FlyFPv (*(s32 (*)(void *))&choose_attack__13TObjEneBm3FlyFPv)
#define update_dd_flag__13TObjEneBm3FlyFPv (*(s32 (*)(void *, f32, f32, f32))&update_dd_flag__13TObjEneBm3FlyFPv)
#define play_sound_effect (*(s32 (*)(void *, void *, int, int))&play_sound_effect)
#define update_collide_flag__13TObjEneBm3FlyFv (*(s32 (*)(void *))&update_collide_flag__13TObjEneBm3FlyFv)
            if (this->m_378 == 3) {
                choose_attack__13TObjEneBm3FlyFPv(this);
            } else {
                transition_enemy_state__9TObjEneDDFs(this, this->m_378);
            }
        }
        break;
    case 0:
        advance_animation_playback();
        t = this->m_3c0;
        this->m_3c0 = t + 1;
        ((P_800B012C *)((u8 *)this))->v.x = *(f32 *)((s8 *)((u8 *)this) + 0x308);
        ((P_800B012C *)((u8 *)this))->v.z = this->m_310;
        v = clamp_velocity__15TObjBoss2TunnelFv(&((P_800B012C *)((u8 *)this))->v, t);
        update_dd_flag__13TObjEneBm3FlyFPv(((u8 *)this), ((P_800B012C *)((u8 *)this))->v.x, ((P_800B012C *)((u8 *)this))->v.z, v);
        clamp_flight_height__13TObjEneBm3FlyFv(this);
        *(f32 *)((s8 *)((u8 *)this) + 0x308) *= (0.5f);
        this->m_310 *= (0.5f);
        this->vfunc_89();
        break;
    case 5:
        clear_attack_receipts__9TObjEneDDFv();
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneBm3Fly__sub_800B02C8(TObjEneBm3Fly *arg0, s32 arg1) {
    u8 *temp_r4;
    switch (arg1) {
    case 4:
        arg0->m_b8 = 1;
        ((TObjEneBm3Fly *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x428) = (s32) (*(s32 *)((s8 *)arg0 + 0x428) & 0xFFFFFFFE);
        *(s32 *)((s8 *)arg0 + 0x428) = (s32) (*(s32 *)((s8 *)arg0 + 0x428) | 2);
        arg0->actorFlags = (s32) (arg0->actorFlags | 0x01000000);
        sub_800B1634__13TObjEneBm3FlyFv(arg0);
        *(f32 *)((s8 *)arg0 + 0x394) = (f32) (((3e+01f) * sin_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0x448)))) + *(f32 *)((s8 *)arg0 + 0x41C));
        arg0->m_398 = (f32) *(f32 *)((s8 *)arg0 + 0x444);
        *(f32 *)((s8 *)arg0 + 0x39C) = (f32) (((3e+01f) * cos_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0x448)))) + *(f32 *)((s8 *)arg0 + 0x424));
        temp_r4 = (u8 *)arg0->movementParameters;
        arg0->m_3e0 = (f32) ((2.0f) + calc_scaled_value__15TObjBoss2TunnelFlf((int) (*(s32 *)((s8 *)temp_r4 + 8)), (int)temp_r4, (f32) (*(f32 *)((s8 *)temp_r4 + 4)), (f32) ((3e+01f))));
        ((TObjEneDD *)arg0)->update_velocity();
        break;
    case 3:
        if (update_linked_position__12TObjEneDD_STFf((f32) ((2e+02f))) != 0) {
            transition_enemy_state__9TObjEneDDFs(arg0, 2);
        } else if (arg0->m_3ac < arg0->m_3e0) {
            transition_enemy_state__9TObjEneDDFs(arg0, 1);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback();
        ((TObjEneDD *)arg0)->update_velocity();
        *(f32 *)((s8 *)arg0 + 0x42C) = approach_value__13TObjEneBm3FlyFff(arg0, (f32) (*(f32 *)((s8 *)arg0 + 0x42C)), arg0->m_398);
        arg0->update_state_flag();
        ((TObjEneBm3Fly *)(arg0))->vfunc_88();
        clamp_flight_height__13TObjEneBm3FlyFv(arg0);
        ((TObjEneDD *)arg0)->transform_part_positions();
        arg0->play_pitched_cue();
        break;
    }
}
#pragma pop

#define I(o) (*(s32 *)(arg0 + (o)))
#define R(o) (*(f32 *)(arg0 + (o)))
#define P(o) (*(u8 **)(arg0 + (o)))
#define V ((VObj_800B044C *)(arg0))
void TObjEneBm3Fly::state_circle_target(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    f32 speed;
    f32 vertical;
    switch (arg1) {
    case 4:
        this->m_b8 = 1;
        V->m94();
        I(0x428) &= ~1;
        I(0x428) |= 2;
        I(0x30) |= 0x01000000;
        if (this->mode == 4) {
            I(0x3C0) = 2;
            I(0x3CC) = 0;
        } else {
            I(0x3C0) = 0;
            I(0x3D0) = I(0x60) + 0x8000;
            I(0x3D4) = 0;
            I(0x3CC) = 0;
            I(0x3D8) = 0;
        }
        break;
    case 3:
        if (P(0x390) == NULL) {
            transition_enemy_state__9TObjEneDDFs(arg0, 5);
        } else if (I(0x3CC) > 0x8000 || I(0x3CC) < -0x8000) {
            choose_attack__13TObjEneBm3FlyFPv(arg0);
        }
        break;
    case 0:
        advance_animation_playback();
        if (((TObjEneEpsilon *)arg0)->update_death_check() == 0 && V->m102((2e+02f)) == 0) {
            break;
        }
        switch (I(0x3C0)) {
        case 0:
            circle_destination(I(0x3D0));
            ((TObjEneDD *)arg0)->update_velocity();
            vertical = (0.0f);
            speed = *(f32 *)((s8 *)(P(0x350)) + 4);
            if (R(0x3AC) < (14.0f)) {
                if (calc_boss4_scale__10TObjPlayerFi((s32)arg0) > (0.5f)) {
                    I(0x3D4) = (s32)(((-65536.0f) * speed) / (439.82288f));
                } else {
                    I(0x3D4) = (s32)(((65536.0f) * speed) / (439.82288f));
                }
                I(0x3C0) = 1;
            }
            break;
        case 1:
            I(0x3D0) += I(0x3D4) / 2;
            I(0x3CC) += I(0x3D4) / 2;
            circle_destination(I(0x3D0));
            ((TObjEneDD *)arg0)->update_velocity();
            speed = *(f32 *)((s8 *)(P(0x350)) + 4);
            vertical = (0.0f);
            if (R(0x3AC) < speed) {
                I(0x3C0) = 2;
            }
            break;
        case 2:
            I(0x3D0) += I(0x3D4);
            I(0x3CC) += I(0x3D4);
            circle_destination(I(0x3D0));
            ((TObjEneDD *)arg0)->update_velocity();
            speed = *(f32 *)((s8 *)(P(0x350)) + 4);
            vertical = (1e+01f) * sin_table_lookup(I(0x3D8));
            I(0x3D8) += 0x380;
            break;
        }
        VecCopy((Vec *)(arg0 + 0x430), (const Vec *)(arg0 + 0x3A0));
        update_dd_flag__13TObjEneBm3FlyFPv(arg0, R(0x430), R(0x438), speed);
        R(0x42C) = approach_value__13TObjEneBm3FlyFff(arg0, R(0x42C), R(0x398) + vertical);
        clamp_flight_height__13TObjEneBm3FlyFv(arg0);
        I(0x60) = (s32)(TObjEneBm3Fly__data_8043B118[0] * atan2_float(
            *(f32 *)((s8 *)(P(0x390)) + 0x38) - R(0x38), *(f32 *)((s8 *)(P(0x390)) + 0x40) - R(0x40)));
        V->m87();
        ((TObjEneBm3Fly *)arg0)->play_pitched_cue();
        break;
    case 1:
        break;
    case 5:
        break;
    }
}

void TObjEneBm3Fly::execute_action(s32 arg1) {
    u8 *temp_r3;

    switch (arg1) {
    case 4:
        this->m_b8 = 1;
        this->vfunc_96();
        *(s32 *)((s8 *)((u8 *)this) + 0x428) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x428) & 0xFFFFFFFE);
        *(s32 *)((s8 *)((u8 *)this) + 0x428) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x428) | 2);
        this->actorFlags = (s32) (this->actorFlags & 0xFEFFFFFF);
        *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = 0;
        this->m_3c0 = 0;
        *(s32 *)((s8 *)((u8 *)this) + 0x454) = 1;
        return;
    case 3:
        if (this->m_3ac > (4.5e+02f)) {
            transition_enemy_state__9TObjEneDDFs(this, 5);
            return;
        }
        switch (this->m_3c0) {
        case 0:
        case 1:
            if ((void *) this->m_390 == NULL) {
                transition_enemy_state__9TObjEneDDFs(this, 5);
            }
        case 2:
            return;
        case 3:
            transition_enemy_state__9TObjEneDDFs(this, 4);
            return;
        }
        break;
    case 0:
        advance_animation_playback();
        if (((TObjEneEpsilon *)((u8 *)this))->update_death_check() == 0) {
            enemy_clear_target__12TObjEneDD_STFUs(((u8 *)this));
        }
        switch (this->m_3c0) {
        case 0:
            if ((void *) this->m_390 != NULL) {
                update_height_offset();
            }
            this->update_velocity();
            *(f32 *)((s8 *)((u8 *)this) + 0x430) = sin_table_lookup(this->rotation_y);
            *(f32 *)((s8 *)((u8 *)this) + 0x438) = cos_table_lookup(this->rotation_y);
            update_state_flag();
            *(f32 *)((s8 *)((u8 *)this) + 0x42C) = approach_value__13TObjEneBm3FlyFff(this, (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x42C)), this->m_398);
            clamp_flight_height__13TObjEneBm3FlyFv(this);
            if (can_attack_target() != 0) {
                this->m_b8 = 0;
                this->m_3c0 = 1;
            }
            break;
        case 1:
            *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C4) + 1);
            if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x3C4) >= (s32) *(s32 *)((s8 *)lbl_805D50EC + 0x1C)) {
                *(s32 *)((s8 *)((u8 *)this) + 0x3C4) = 0;
                this->m_3c0 = 2;
                this->m_b8 = 2;
            }
            update_collide_flag__13TObjEneBm3FlyFv(this);
            break;
        case 2:
            if (objInBand((GameObj *)(this), (f32) ((9.0f))) != 0) {
                *(s32 *)((s8 *)((u8 *)this) + 0x440) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x440) + 1);
                temp_r3 = (unsigned char *) (this->m_390);
                if ((temp_r3 != NULL) && (((VObjB0_800b07d0 *)temp_r3)->v18(this, (1.0f)) != 0)) {
                    ((VObjB0_800b07d0 *)((unsigned char *) (this->m_390)))->v20(this, (1.0f));
                    ((VObjB0_800b07d0 *)((unsigned char *) (this->m_390)))->v23(this, (3.0f));
                    if ((TObjEneDD::check_v2_mode() != 0) && (calc_boss4_scale__10TObjPlayerFi((s32)this) < (0.05f))) {
                        TObjEneDD::inflict_poison((s32)this, (u8 *)this->m_390);
                    }
                }
                play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(this, 0x4003A524), ((u8 *)this) + 0x38, 0, 0);
                TObjPlayer::play_effect_if_v2(-0x400);
            }
            if (this->get_flag_b4() != 0) {
                if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x440) >= 4) {
                    *(s32 *)((s8 *)((u8 *)this) + 0x440) = 0;
                    this->m_3c0 = 3;
                } else {
                    this->m_b8 = 1;
                    this->m_3c0 = 0;
                }
            }
            update_collide_flag__13TObjEneBm3FlyFv(this);
            break;
        }
        this->vfunc_89();
        this->play_pitched_cue();
        return;
    case 5:
        *(s32 *)((s8 *)((u8 *)this) + 0x454) = 0;
        break;
    }
}

#pragma push
#pragma fp_contract on
#undef I
#undef R
#undef P
#undef V
#define I(o) (*(s32 *)(arg0 + (o)))
#define R(o) (*(f32 *)(arg0 + (o)))
#define P(o) (*(u8 **)(arg0 + (o)))
#define V ((VObj_800B0B20 *)(arg0))

void TObjEneBm3Fly__sub_800B0B20(u8 *arg0, s32 arg1) {
    Vec_800B0B20 *pos;
    Vec_800B0B20 *off;
    Vec_800B0B20 *vel;
    Vec_800B0B20 p;
    Vec_800B0B20 d;
    f32 z;
    f32 x;
    f32 s;
    f32 len;

    vel = (Vec_800B0B20 *)(arg0 + 0x3E8);
    pos = (Vec_800B0B20 *)(arg0 + 0x3F4);
    off = (Vec_800B0B20 *)(arg0 + 0x400);

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        V->m94();
        I(0x428) &= ~1;
        I(0x428) |= 2;
        I(0x30) |= 0x01000000;
        vel->x = R(0x430) * R(0x43C);
        vel->y = (0.0f);
        vel->z = R(0x438) * R(0x43C);
        if (is_vec_xz_cross_negative(arg0 + 0x430, arg0 + 0x3A0) != 0) {
            I(0x3CC) = 0x8000;
        } else {
            I(0x3CC) = 0;
        }
        I(0x3C4) = 0;
        off->x = (0.0f);
        off->y = (0.0f);
        off->z = (0.0f);
        pos->x = (0.0f);
        pos->y = R(0x42C) - R(0x3C);
        pos->z = (0.0f);
        break;
    case 3:
        if (R(0x3AC) > (4.5e+02f) || P(0x390) == NULL) {
            transition_enemy_state__9TObjEneDDFs(arg0, 5);
        } else if (R(0x3AC) < (1e+02f)) {
            ((s32 (*)())choose_attack__13TObjEneBm3FlyFPv)();
        }
        break;
    case 0:
        advance_animation_playback();
        if (((TObjEneEpsilon *)arg0)->update_death_check() == 0 && V->m102((2e+02f)) == 0) {
            break;
        }
        ((TObjEneBm3Fly *)arg0)->update();
        ((TObjEneDD *)arg0)->update_velocity();
        VecCopy((Vec *)pos, (const Vec *)(arg0 + 0x2FC));
        subtract_vector(pos, off);
        if (I(0x3C4) == 0) {
            if ((0.0f) == R(0x430) && (0.0f) == R(0x438)) {
                R(0x430) = sin_table_lookup(I(0x60));
                R(0x438) = cos_table_lookup(I(0x60));
            }
            if (vec3_dot(arg0 + 0x430, arg0 + 0x3A0) < (0.99f)) {
                if (is_vec_xz_cross_negative(arg0 + 0x430, arg0 + 0x3A0) != 0) {
                    x = -R(0x438);
                    z = R(0x430);
                } else {
                    x = R(0x438);
                    z = -R(0x430);
                }
                vel->x = (0.18f) * x + vel->x;
                vel->y = (0.0f);
                vel->z = (0.18f) * z + vel->z;
                VecCopy((Vec *)(arg0 + 0x430), (const Vec *)vel);
                update_scale__15TObjBoss2TunnelFv(arg0 + 0x430);
            } else {
                I(0x3C4) = 1;
                VecCopy((Vec *)(arg0 + 0x430), (const Vec *)(arg0 + 0x3A0));
            }
        } else {
            VecCopy((Vec *)(arg0 + 0x430), (const Vec *)(arg0 + 0x3A0));
            s = (5.0f) * sin_table_lookup(I(0x3CC));
            I(0x3CC) += 0x600;
            off->x = R(0x3A8) * s;
            off->y = (0.0f);
            off->z = -R(0x3A0) * s;
        }
        if (R(0x43C) > *(f32 *)((s8 *)(P(0x350)) + 4)) {
            R(0x43C) *= (0.96f);
        } else {
            R(0x43C) = *(f32 *)((s8 *)(P(0x350)) + 4);
        }
        vel->x = R(0x430) * R(0x43C);
        vel->y = (0.0f);
        vel->z = R(0x438) * R(0x43C);
        pos->x += vel->x;
        pos->z += vel->z;
        VecCopy((Vec *)&p, (const Vec *)pos);
        vec3_add_to(&p, off);
        VecCopy((Vec *)&d, (const Vec *)&p);
        subtract_vector(&d, arg0 + 0x38);
        d.y = (0.0f);
        len = ((f32 (*)(void *))clamp_velocity__15TObjBoss2TunnelFv)(&d);
        update_dd_flag__13TObjEneBm3FlyFPv(arg0, d.x, d.z, len);
        R(0x42C) = approach_value__13TObjEneBm3FlyFff(arg0, pos->y, R(0x398));
        pos->y = R(0x42C);
        clamp_flight_height__13TObjEneBm3FlyFv(arg0);
        I(0x60) = (s32)(TObjEneBm3Fly__data_8043B118[0] * atan2_float(R(0x430), R(0x438)));
        V->m87();
        pos->x -= R(0x38);
        pos->y -= R(0x42C);
        pos->z -= R(0x40);
        ((TObjEneBm3Fly *)arg0)->play_pitched_cue();
        break;
    case 5:
        R(0x43C) = *(f32 *)((s8 *)(P(0x350)) + 4);
        break;
    }
}

#pragma pop
#undef I
#undef R
#undef P
#undef V

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define F_800B(off, T) (*(T *)(arg0 + (off)))

#pragma push
#pragma fp_contract on
#define I(o) (*(s32 *)(arg0 + (o)))
#define R(o) (*(f32 *)(arg0 + (o)))
void TObjEneBm3Fly__sub_800B0F70(u8 *arg0, s32 arg1) {
    Vec_800B0F70 d;
    f32 radius;
    s32 a;
    switch (arg1) {
    case 4:
        ((TObjEneBm3Fly *)arg0)->m_b8 = 1;
        ((TObjEneBm3Fly *)(arg0))->vfunc_95();
        I(0x428) &= ~1;
        I(0x428) |= 2;
        I(0x30) |= 0x01000000;
        I(0x3CC) = 0;
        I(0x3D0) = (s32)((512.0f) * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + 0x800;
        I(0x3D4) = I(0x448);
        I(0x3D8) = (s32)((512.0f) * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + 0xA00;
        d.x = R(0x38) - R(0x41C);
        d.y = (0.0f);
        d.z = R(0x40) - R(0x424);
        if (is_vec_xz_cross_negative(&d, arg0 + 0x430) != 0) {
            I(0x3D8) *= -1;
        }
        enemy_clear_target__12TObjEneDD_STFUs(arg0);
        I(0x3C8) = -1;
        break;
    case 3:
        if (update_linked_position__12TObjEneDD_STFf((2e+02f)) != 0) {
            transition_enemy_state__9TObjEneDDFs(arg0, 2);
        }
        break;
    case 0:
        advance_animation_playback();
        I(0x3C4)++;
        if (I(0x3C4) > 300) {
            I(0x3C4) = 0;
            I(0x3D8) = (s32)((512.0f) * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + 0xA00;
        }
        I(0x3CC) += I(0x3D0);
        radius = (3e+01f) * cos_table_lookup(I(0x3CC) / 2);
        I(0x3D4) += I(0x3D8);
        a = I(0x3D4);
        R(0x38) = radius * sin_table_lookup(a) + R(0x41C);
        R(0x42C) = (1e+01f) * sin_table_lookup(I(0x3D4)) + R(0x444);
        R(0x40) = radius * cos_table_lookup(a) + R(0x424);
        I(0x60) = a - 0x4000;
        update_collide_flag__13TObjEneBm3FlyFv(arg0);
        R(0x44) = R(0x2FC);
        R(0x4C) = R(0x304);
        ((TObjEneBm3Fly *)(arg0))->vfunc_88();
        TObjEneBm3Fly__play_orbit_flight_sound((s32)arg0);
        break;
    case 5:
        R(0x430) = R(0x38) - R(0x44);
        R(0x434) = (0.0f);
        R(0x438) = R(0x40) - R(0x4C);
        R(0x43C) = update_scale__15TObjBoss2TunnelFv(arg0 + 0x430);
        break;
    }
}
#pragma pop

void TObjEneBm3Fly__sub_800B1214(u8 *arg0, s32 arg1) {
    f32 *p = (f32 *)(arg0 + 0x3E8);
    switch (arg1) {
    case 4:
        F_800B(0xB8, s16) = 1;
        ((TObjEneBm3Fly *)(arg0))->vfunc_95();
        F_800B(0x428, s32) &= ~1;
        F_800B(0x428, s32) |= 2;
        F_800B(0x30, s32) |= 0x01000000;
        sub_800B1634__13TObjEneBm3FlyFv(arg0);
        F_800B(0x3C0, s32) = 0;
        F_800B(0x3C4, s32) = 0;
        p[0] = (3e+01f) * sin_table_lookup(F_800B(0x448, s32)) + F_800B(0x41C, f32);
        p[1] = F_800B(0x444, f32);
        p[2] = (3e+01f) * cos_table_lookup(F_800B(0x448, s32)) + F_800B(0x424, f32);
        F_800B(0x60, s32) = (s32)(TObjEneBm3Fly__data_8043B118[0] * atan2_float(F_800B(0x40C, f32), F_800B(0x414, f32)));
        enemy_clear_target__12TObjEneDD_STFUs(arg0);
        break;
    case 3:
        if (F_800B(0x3C4, s32) == 2) {
            transition_enemy_state__9TObjEneDDFs(arg0, 1);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback();
        switch (F_800B(0x3C4, s32)) {
        case 0:
            F_800B(0x38, f32) += F_800B(0x40C, f32);
            F_800B(0x42C, f32) += F_800B(0x410, f32);
            F_800B(0x40, f32) += F_800B(0x414, f32);
            F_800B(0x40C, f32) *= (0.9f);
            F_800B(0x410, f32) += lbl_805D9E80;
            F_800B(0x414, f32) *= (0.9f);
            F_800B(0x3C0, s32)++;
            if (F_800B(0x3C0, s32) > 40) {
                F_800B(0x3C4, s32) = 1;
                F_800B(0x3C0, s32) = 0;
                F_800B(0x43C, f32) = (0.0f);
            }
            break;
        case 1:
            VecCopy((Vec *)(arg0 + 0x430), (const Vec *)p);
            F_800B(0x430, f32) -= F_800B(0x38, f32);
            F_800B(0x434, f32) -= F_800B(0x42C, f32);
            F_800B(0x438, f32) -= F_800B(0x40, f32);
            F_800B(0x3E0, f32) = update_scale__15TObjBoss2TunnelFv(arg0 + 0x430);
            if (F_800B(0x43C, f32) < (2.0f)) {
                F_800B(0x43C, f32) += (0.1f);
            }
            if (F_800B(0x3E0, f32) < (2.0f)) {
                VecCopy((Vec *)(arg0 + 0x38), (const Vec *)p);
                F_800B(0x3C4, s32) = 2;
            } else {
                F_800B(0x38, f32) = F_800B(0x430, f32) * F_800B(0x43C, f32) + F_800B(0x38, f32);
                F_800B(0x42C, f32) = F_800B(0x434, f32) * F_800B(0x43C, f32) + F_800B(0x42C, f32);
                F_800B(0x40, f32) = F_800B(0x438, f32) * F_800B(0x43C, f32) + F_800B(0x40, f32);
            }
            F_800B(0x60, s32) = (s32)(TObjEneBm3Fly__data_8043B118[0] * atan2_float(F_800B(0x430, f32), F_800B(0x438, f32)));
            break;
        }
        update_collide_flag__13TObjEneBm3FlyFv(arg0);
        F_800B(0x44, f32) = F_800B(0x2FC, f32);
        F_800B(0x4C, f32) = F_800B(0x304, f32);
        clamp_flight_height__13TObjEneBm3FlyFv(arg0);
        ((TObjEneBm3Fly *)(arg0))->vfunc_88();
        break;
    }
}
#pragma pop

void TObjEneBm3Fly__vt102(void *arg0, f32 farg0) {
    if (((VObj_800B150C_800B07D0 *)arg0)->m97() != 0) {
        ((TObjEneDD_ST *)arg0)->select_and_apply_target(farg0);
        return;
    }
    spawn_part__14TObjEneEpsilonFi(arg0, farg0);
}
void TObjEneBm3Fly__play_orbit_flight_sound(s32 arg0) {
    play_persistent_sound((((s32)copy_target_state__14TObjEnePanarmsFPv((void *)arg0, 0x4003AB23))), (arg0), (arg0 + 0x38), 0, 0);
    TObjPlayer::play_effect_if_v2(-0x400);
}
void TObjEneBm3Fly::play_pitched_cue() {
    s32 arg0 = (s32)this;
    play_persistent_sound((((s32)copy_target_state__14TObjEnePanarmsFPv((void *)arg0, 0x40039E22))), (arg0), (arg0 + 0x38), 0, 0);
    TObjPlayer::play_effect_if_v2(-0x400);
}

}

#undef copy_target_state__14TObjEnePanarmsFPv
#undef sub_800B1634__13TObjEneBm3FlyFv
#undef approach_value__13TObjEneBm3FlyFff
#undef clamp_flight_height__13TObjEneBm3FlyFv
#undef transition_enemy_state__9TObjEneDDFs
#undef clamp_velocity__15TObjBoss2TunnelFv
#undef choose_attack__13TObjEneBm3FlyFPv
#undef update_dd_flag__13TObjEneBm3FlyFPv
#undef play_sound_effect
#undef update_collide_flag__13TObjEneBm3FlyFv

#define cos_table_lookup (*(f32 (*)())&cos_table_lookup)
#define transition_enemy_state__9TObjEneDDFs (*(s32 (*)(void *, int))&transition_enemy_state__9TObjEneDDFs)
#define clamp_flight_height__13TObjEneBm3FlyFv (*(int (*)(void*))&clamp_flight_height__13TObjEneBm3FlyFv)

typedef struct Cand_800B1684 {
    u16 id;
    u16 pad;
    f32 dist;
} Cand_800B1684;

typedef struct Fly_800B1684 {
    u8 pad0[0x38C];
    u16 f38C;
    u8 pad38E[0x418 - 0x38E];
    u16 nest;
    u8 pad41A[0x454 - 0x41A];
    s32 f454;
} Fly_800B1684;

extern "C" {
void vfunc_88__13TObjEneBm3FlyFv(u8 *arg0);
f32 fabs_float(f32);
extern s32 TObjEneBm3Fly__attack_params;
s32 get_random_scaled__9TObjEneDDFv(void *);
s32 has_free_attack_slot__17TObjEneBm3FlyNestFUs(void *, u16);
s32 enemy_set_target_id(void *, u16);
s32 collect_enemy_target_candidates(void *, Cand_800B1684 *, f32);
void vfunc_89__13TObjEneBm3FlyFv(void* p);
int vfunc_89__9TObjEneDDFv(void*);

u16 TObjEneBm3Fly::get_active_id() {
    if ((s32) *(s32 *)((s8 *)this + 0x454) != 0) {
        return this->m_38c;
    }
    return 0xFFFFU;
}

#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::sub_800B1634() {
    *(f32 *)((s8 *)((u8 *)this) + 0x444) = (f32) (((2.0f) * calc_elapsed_scaled__9TObjEneDDFv(this)) + ((45.0f) + *(f32 *)((s8 *)((u8 *)this) + 0x420)));
    *(s32 *)((s8 *)((u8 *)this) + 0x448) = get_random_scaled__9TObjEneDDFv(this);
}
#pragma pop

void choose_attack__13TObjEneBm3FlyFPv(Fly_800B1684 *s) {
    Cand_800B1684 players[4];
    void *nest;
    s32 count;
    u16 id;
    s32 i;
    nest = find_entity_by_id(s->nest);
    if (nest == NULL) {
        transition_enemy_state__9TObjEneDDFs(s, 4);
        s->f454 = 0;
    }
    if (has_free_attack_slot__17TObjEneBm3FlyNestFUs(nest, s->f38C) != 0) {
        transition_enemy_state__9TObjEneDDFs(s, 3);
        return;
    }
    count = collect_enemy_target_candidates(s, players, (1e+04f));
    for (i = 0; i < count; i++) {
        id = players[i].id;
        if (id != s->f38C && has_free_attack_slot__17TObjEneBm3FlyNestFUs(nest, id) != 0) {
            enemy_set_target_id(s, id);
            transition_enemy_state__9TObjEneDDFs(s, 3);
            return;
        }
    }
    transition_enemy_state__9TObjEneDDFs(s, 4);
    s->f454 = 0;
}

s32 TObjEneBm3Fly::can_attack_target() {
    f32 temp_f31;
    if ((this->m_3ac < ((5.0f) + ((TObjPlayer *)TObjEneBm3Fly__attack_params)->get_pos_x())) && (fabs_float((f32) (*(f32 *)((s8 *)((u8 *)this) + 0x42C) - this->m_398)) < (1.0f))) {
        temp_f31 = vec3_dot(((u8 *)this) + 0x430, ((u8 *)this) + 0x3A0);
        ((TObjPlayer *)(this->m_318))->get_field_0c();
        if (temp_f31 >= cos_table_lookup()) {
            return 1;
        }
    }
    return 0;
}

f32 approach_value__13TObjEneBm3FlyFff(f32 farg0, f32 farg1) {
    f32 temp_f31;
    f32 var_f1;
    f32 cap;

    temp_f31 = farg1 - farg0;
    if (fabs_float(temp_f31) < (0.2f)) {
        return farg1;
    }
    var_f1 = (0.1f);
    var_f1 = temp_f31 * var_f1;
    if (var_f1 > (1.5f)) {
        var_f1 = (1.5f);
    } else if (var_f1 < (-1.5f)) {
        var_f1 = (-1.5f);
    }
    return farg0 + var_f1;
}

void TObjEneBm3Fly::vfunc_88() {
    f32 temp_f31;
    temp_f31 = *(f32 *)((s8 *)((u8 *)this) + 0x42C) - *(f32 *)((s8 *)((u8 *)this) + 0x3C);
    if (temp_f31 >= (3e+01f)) {
        this->vfunc_97();
    } else {
        this->vfunc_98();
    }
    *(f32 *)((s8 *)this->m_a4 + 4) = temp_f31;
}

void TObjEneBm3Fly::vfunc_89() { vfunc_89__9TObjEneDDFv(this); clamp_flight_height__13TObjEneBm3FlyFv(this); }

}

#undef cos_table_lookup
#undef transition_enemy_state__9TObjEneDDFs
#undef clamp_flight_height__13TObjEneBm3FlyFv

#define VBase_18 VBase_18__p3
#define VObj_18 VObj_18__p3

#include <stddef.h>
#include "pso/TObject.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

struct Base_800B2214_800B1978 { char pad[0xC]; };

struct VObj_800B2214_800B1978 : Base_800B2214_800B1978 {
    virtual void m2(int);
};

struct VBase_18_6eb1ad
{
  char pad[0x18];
};

struct VObj_18_6eb1ad : VBase_18_6eb1ad {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
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
    virtual s32 m81();
    virtual void m82();
    virtual s32 m83();
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
    virtual s32 m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual s32 m103();
};

struct Stack_800B22C8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
};

struct RecoveredGlobal_800B22C8_lbl_8043B0FC {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_800B22C8_lbl_80491B4C {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_800B2168___vt__13TObjEneBm3Fly {
    s32 value;
    u8 remaining[0x1A8];
};

struct Vec_800B23A0 { s32 x, y, z; };

typedef struct VBase_18_6eb1ad VBase_18_6eb1ad;

typedef struct VObj_18_6eb1ad VObj_18_6eb1ad;

typedef char RecoveredGlobal_800B2168___vt__13TObjEneBm3Fly_size[sizeof(RecoveredGlobal_800B2168___vt__13TObjEneBm3Fly) == 0x1AC ? 1 : -1];

typedef char RecoveredGlobal_800B22C8_lbl_8043B0FC_size[sizeof(RecoveredGlobal_800B22C8_lbl_8043B0FC) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_800B22C8_lbl_80491B4C_size[sizeof(RecoveredGlobal_800B22C8_lbl_80491B4C) == 0x2C ? 1 : -1];

struct RecoveredGlobal_800B2948_lbl_8043B2A4 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_800B2948_lbl_80500B00 {
    s32 value;
    u8 remaining[0x3C];
};

struct Obj_800B2A5C { u8 pad[0x3b0]; s32 count; u8 pad2[4]; u16 ids[6]; };

struct Obj_800B2AF4 { u8 pad[0x3b0]; s32 count; u8 pad2[4]; u16 ids[6]; };

typedef char RecoveredGlobal_800B2948_lbl_8043B2A4_size[sizeof(RecoveredGlobal_800B2948_lbl_8043B2A4) == 0x20 ? 1 : -1];

typedef char RecoveredGlobal_800B2948_lbl_80500B00_size[sizeof(RecoveredGlobal_800B2948_lbl_80500B00) == 0x40 ? 1 : -1];

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
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
    virtual s32 m93();
};

typedef struct Vec_800B39CC {
    f32 x, y, z;
} Vec_800B39CC;

typedef struct Nest_800B39CC {
    u8 pad0[0x2C];
    s16 f2C;
    u8 pad2E[0x38 - 0x2E];
    Vec_800B39CC pos;
    u8 pad44[0x3B0 - 0x44];
    s32 count;
    s32 spawned;
    u16 ids[6];
    u16 nextId;
    u8 pad3C6[0x3D4 - 0x3C6];
    u8 f3D4[0xC];
} Nest_800B39CC;

u16 obj_getField1c(void *);
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
void *create_particle_emitter(void *pos, s32 id);
s32 init_from_model__11TBreakUpMdlFl(int, void *);
void TObjEneBm3Fly__sub_800B0B20(u8 *arg0, s32 arg1);
void vfunc_61__13TObjEneBm3FlyFv(void);
void vfunc_62__13TObjEneBm3FlyFv(void* p);
void vfunc_63__13TObjEneBm3FlyFv(u8 *arg0);
void vfunc_28__13TObjEneBm3FlyFv(void);
void TObjEneBm3Fly__vt85(s32 arg0, u32 arg1, s32 arg2);
void * __dt__13TObjEneBm3FlyFv(void *arg0, s16 arg1);
u8 * TObjEneBm3Fly__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, u8 *arg5, u8 *arg6);
int TObjEneBm3FlyNest__sub_800B4158(void);
u32 TObjEneEpsilon__sub_800B92F8(void *, void *, f32);
s32 enemy_copy_target_destination__12TObjEneDD_STFv();
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
u32 move_with_wall_slide_commit__9TObjEneDDFfff();
s32 was_hit_by_ranged__13TObjEneBm3FlyFv();
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);

void vfunc_6__13TUnk_804B9870FPsl();
void vfunc_103__9TObjEneDDFPUc();
void vfunc_79__9TObjEneDDFv();
void TObjEneDD__vt82();
void vfunc_85__9TObjEneDDFv();
void vfunc_86__9TObjEneDDFv();
void vfunc_90__9TObjEneDDFv();
void vfunc_91__9TObjEneDDFv();
void vfunc_92__9TObjEneDDFv();
void vfunc_93__9TObjEneDDFv();
void vfunc_94__9TObjEneDDFv();
void vfunc_95__9TObjEneDDFv();
void vfunc_96__9TObjEneDDFv();
void vfunc_97__9TObjEneDDFv();
void vfunc_98__9TObjEneDDFv();
void vfunc_99__9TObjEneDDFv();
void vfunc_100__9TObjEneDDFv();
void vfunc_101__9TObjEneDDFPUc();
void vfunc_102__9TObjEneDDFv();
void vfunc_29__13TUnk_804806E8Fv();
void vfunc_73__13TUnk_804806E8Fv();
void consume_timer_field__13TUnk_804806E8Fl();
void vfunc_67__13TUnk_804806E8Ff();
void vfunc_66__13TUnk_804806E8Fv();
void get_anim_node_position__13TUnk_804806E8FlP3Vec();
void vfunc_60__13TUnk_804806E8Fv();
void vfunc_59__13TUnk_804806E8Fv();
void vfunc_58__13TUnk_804806E8Fv();
void apply_slow_status__13TUnk_804806E8Fv();
void update_shock_clock__13TUnk_804806E8Fv();
void vfunc_43__13TUnk_804806E8Fv();
void vfunc_18__13TUnk_804806E8FPUc();
void interact__13TUnk_804AF8A0Fl();
void vfunc_74__9TObjEnemyFl();
void apply_hit_message_flags__9TObjEnemyFPv();
void add_actor_exp__13TUnk_804806E8Fl();
void apply_action_hold_status__13TUnk_804806E8Ff();
void apply_anti_technique__13TUnk_804806E8Fl();
void apply_attack_stat_status__13TUnk_804806E8FPv();
void apply_confusion_status__13TUnk_804806E8Fv();
void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
void apply_movement_ailment__13TUnk_804806E8Fl();
void apply_object_set_data__13TUnk_804B9870FPv();
void apply_paralysis__13TUnk_804806E8Fv();
void apply_poison_status__13TUnk_804806E8Fv();
void apply_set_data__9TObjEnemyFPv();
void apply_shock_status__13TUnk_804806E8Fv();
void apply_switch_attack__13TUnk_804806E8Fv();
void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void clear_all_status_effects__13TUnk_804806E8Fv();
void clear_harmful_statuses__13TUnk_804806E8Fv();
void cure_paralysis__13TUnk_804806E8Fv();
void cure_poison_ailment__13TUnk_804806E8Fv();
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
void vfunc_78__13TUnk_804806E8Fl();
void vfunc_77__13TUnk_804806E8Fv();
void vfunc_76__13TUnk_804806E8Fv();
void vfunc_75__13TUnk_804806E8Ff();
void clear_lobby_object_state__9TObjEnemyFv();
void vfunc_9__13TUnk_804806E8Fv();
void get_actor_level_index__13TUnk_804806E8Fv();
void get_name__9TObjEnemyFv();
void get_pos__13TUnk_804806E8Fl();
void is_actor_cadence_frame__13TUnk_804806E8Fl();
void is_target_in_attack_range__13TUnk_804806E8Fv();
void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
void receive_physical_attack__13TUnk_804806E8FPvf();
void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
void reset_motion_fields__13TUnk_804806E8Fv();
void reset_pose__13TUnk_804806E8Fv();
void roll_physical_accuracy__13TUnk_804806E8FPvlf();
void select_melee_contact_body__13TUnk_804806E8FPvf();
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
void try_start_action__13TUnk_804806E8Fll();
void update_action_hold_status__13TUnk_804806E8Fv();
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
void update_actor_ground_y__13TUnk_804806E8Fv();
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
void update_flag30_timer__13TUnk_804806E8Fv();
void update_movement_status__13TUnk_804806E8Fv();
void update_object_view_visibility__13TUnk_804B9870Fff();
void update_poison_status__13TUnk_804806E8Fv();
extern RecoveredGlobal_800B22C8_lbl_8043B0FC bm3_fly_resource_binding_desc;
typedef struct Ctl_800B47C4 {
    f32 *pv;
    s32 *pc;
    s32 d;
    s32 e;
    s32 f;
} Ctl_800B47C4;
extern s32 TObjEneBm3Fly__name;
extern s32 bm3_fly_boss_stat_handle;
extern s32 lbl_805D50E8;
extern u8 *bm3_fly_nest_resources;
extern void *tl_04;

extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void run_task__13TObjEneBm3FlyFv();
void *bm3_fly_decision_row[7] = {
    (void *)0x43610000, (void *)0x3f6d097b, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *bm3_fly_collider_params[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *bm3_fly_action_table[20] = {
    (void *)0x10000, (void *)0xa, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10001, (void *)0xc, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30002, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f800000, (void *)0x0,
    (void *)0x30004, (void *)0x3, (void *)0x3f800000, (void *)0x0,
};
void *__vt__13TObjEneBm3Fly[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TObjEneBm3FlyFv, (void *)&run_task__13TObjEneBm3FlyFv,
    (void *)&render__13TObjEneBm3FlyFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__13TObjEneBm3FlyFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__13TObjEneBm3FlyFv, (void *)&vfunc_62__13TObjEneBm3FlyFv, (void *)&vfunc_63__13TObjEneBm3FlyFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&vfunc_73__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&TObjEneBm3Fly__vt85,
    (void *)&vfunc_88__13TObjEneBm3FlyFv, (void *)&vfunc_89__13TObjEneBm3FlyFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&TObjEneBm3Fly__vt102, (void *)&TObjEneBm3Fly__vt103, (void *)&TObjEneBm3Fly__vt104,
};
#define bm3_fly_collider_params (*(RecoveredGlobal_800B22C8_lbl_80491B4C *)bm3_fly_collider_params)
#define __vt__13TObjEneBm3Fly ((s32 *)__vt__13TObjEneBm3Fly)

#pragma push
#pragma opt_common_subs off
void TObjEneBm3Fly::clamp_flight_height() {
    u8 *arg0 = (u8 *)this;
    if ((*(f32 *)((s8 *)arg0 + 0x42C) - *(f32 *)((s8 *)arg0 + 0x3C)) < (1.2f)) {
        *(f32 *)((s8 *)arg0 + 0x42C) = (1.2f) + *(f32 *)((s8 *)arg0 + 0x3C);
    }
#define queue_destruction__7TObjectFv (*(void (*)(void *))&queue_destruction__7TObjectFv)
#define update_scale__15TObjBoss2TunnelFv (*(s32 (*)(void *))&update_scale__15TObjBoss2TunnelFv)
#define remove_child__17TObjEneBm3FlyNestFPUc (*(void (*)(Obj_800B2A5C *, u8 *))&remove_child__17TObjEneBm3FlyNestFPUc)
#define has_free_attack_slot__17TObjEneBm3FlyNestFUs (*(s32 (*)(Obj_800B2AF4 *, u16))&has_free_attack_slot__17TObjEneBm3FlyNestFUs)
#define clear_global_flag_400__9TObjEneDDFv (*(void (*)(void))&clear_global_flag_400__9TObjEneDDFv)
#define update_player_state__9TObjEneDDFv (*(void (*)(void *, Vec_800B23A0 *, s32))&update_player_state__9TObjEneDDFv)
#define set_field_378__9TObjEneDDFl (*(s32 (*)(void *, s32))&set_field_378__9TObjEneDDFl)
#define transition_enemy_state__9TObjEneDDFs (*(s32 (*)(void *, s32))&transition_enemy_state__9TObjEneDDFs)
#define toggle_particle_effect__10TObjPlayerFv (*(void (*)(void))&toggle_particle_effect__10TObjPlayerFv)
#define copy_target_state__14TObjEnePanarmsFPv (*(int (*)(void*))&copy_target_state__14TObjEnePanarmsFPv)
#define advance_animation_playback (*(s32 (*)(void *))&advance_animation_playback)
#define end_effect_render__13TParticleCtrlFv (*(void (*)(void))&end_effect_render__13TParticleCtrlFv)
#define play_sound_effect (*(s32 (*)(void *, void *, int, int))&play_sound_effect)
#define rotate_matrix_y (*(void (*)(s32, s32))&rotate_matrix_y)
#define set_global_param__8TObjFishFl (*(void (*)(s32))&set_global_param__8TObjFishFl)
#define vfunc_89__9TObjEneDDFv (*(void (*)())&vfunc_89__9TObjEneDDFv)
#define render__13TObjEneBm3FlyFv (*(void (*)())&render__13TObjEneBm3FlyFv)
    this->m_300 = *(f32 *)((s8 *)arg0 + 0x42C);
}
#pragma pop

void TObjEneBm3Fly::store_position() {
    u8 *arg0 = (u8 *)this;
    this->m_2fc = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    this->m_304 = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x2FC));
}

void TObjEneBm3Fly::update_state_flag() {

    if (TObjEneEpsilon__sub_800B92F8(this, *(void **)((s8 *)this->movementParameters + 8), *(*(f32 **)&lbl_805D50EC)) != 0U) {
        *(s32 *)((s8 *)this + 0x428) = (s32) (*(s32 *)((s8 *)this + 0x428) | 2);
        return;
    }
    *(s32 *)((s8 *)this + 0x428) = (s32) (*(s32 *)((s8 *)this + 0x428) & 0xFFFFFFFD);
}

void update_dd_flag__13TObjEneBm3FlyFPv(void *arg0) {
    if (move_with_wall_slide_commit__9TObjEneDDFfff() != 0U) {
        *(s32 *)((s8 *)arg0 + 0x428) = (s32) (*(s32 *)((s8 *)arg0 + 0x428) | 2);
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x428) = (s32) (*(s32 *)((s8 *)arg0 + 0x428) & 0xFFFFFFFD);
}

void TObjEneBm3Fly::update_collide_flag() {
    if (this->vfunc_102() != 0U) {
        *(s32 *)((s8 *)this + 0x428) = (s32) (*(s32 *)((s8 *)this + 0x428) | 2);
        return;
    }
    *(s32 *)((s8 *)this + 0x428) = (s32) (*(s32 *)((s8 *)this + 0x428) & 0xFFFFFFFD);
}

#pragma push
#pragma fp_contract on
void TObjEneBm3Fly::circle_destination(s32 arg1) {
    enemy_copy_target_destination__12TObjEneDD_STFv();
    *(f32 *)((s8 *)this + 0x394) = (f32) (((7e+01f) * ((f32 (*)(s32))sin_table_lookup)(arg1)) + *(f32 *)((s8 *)this + 0x394));
    this->m_398 = (f32) ((*(f32 *)((s8 *)this + 0x3C)) + *(f32 *)((s8 *)this + 0x44C));
    *(f32 *)((s8 *)this + 0x39C) = (f32) (((7e+01f) * ((f32 (*)(s32))cos_table_lookup)(arg1)) + *(f32 *)((s8 *)this + 0x39C));
}
#pragma pop

void TObjEneBm3Fly::update_height_offset() {
    enemy_copy_target_destination__12TObjEneDD_STFv();
    this->m_398 = (f32) (*(f32 *)((s8 *)this + 0x3C) + *(f32 *)((s8 *)this + 0x450));
}

void TObjEneBm3Fly::update() {
    enemy_copy_target_destination__12TObjEneDD_STFv();
    this->m_398 = (f32) (*(f32 *)((s8 *)this + 0x3C) + *(f32 *)((s8 *)this + 0x44C));
}

void TObjEneBm3Fly::vfunc_61() {  }

void TObjEneBm3Fly::vfunc_62() { if (this->mode != 6) { ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(this, (void*)6); } }

void TObjEneBm3Fly::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    temp_r0 = this->mode;
    if ((temp_r0 != 8) && (temp_r0 != 9) && (temp_r0 != 7)) {
        if (was_hit_by_ranged__13TObjEneBm3FlyFv() != 0) {
            ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(arg0, (void*)(7));
            return;
        }
        ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(arg0, (void*)(8));
    }
}

void TObjEneBm3Fly::vfunc_28() {  }

void TObjEneBm3Fly__vt85(s32 arg0, u32 arg1, s32 msg) {
    switch (arg1) {
    case 0:
        TObjEneBm3Fly__sub_800B1214((u8 *)arg0, (msg));
        return;
    case 1:
        TObjEneBm3Fly__sub_800B0F70((u8 *)arg0, (msg));
        return;
    case 2:
        TObjEneBm3Fly__sub_800B0B20((u8 *)arg0, (msg));
        return;
    case 3:
        ((TObjEneBm3Fly *)arg0)->execute_action((msg));
        return;
    case 4:
        ((TObjEneBm3Fly *)arg0)->state_circle_target((msg));
        return;
    case 6:
        ((TObjEneBm3Fly *)arg0)->update_recoil_state((msg));
        return;
    case 8:
        ((TObjEneBm3Fly *)arg0)->state_death_fall((msg));
        return;
    case 5:
        TObjEneBm3Fly__sub_800B02C8((TObjEneBm3Fly *)((u8 *)arg0), (msg));
        return;
    case 7:
        action__13TObjEneBm3FlyFPvi((u8 *)arg0, (msg));
        return;
    case 9:
        ((TObjEneBm3Fly *)arg0)->handle_message((msg));
    default:
        return;
    }
}

}
void TObjEneBm3Fly::run_task() {
  u8* arg0 = (u8*)this;
  f32 temp_f2;
  f32 temp_f31;
  f32 var_f30;
  s16 temp_r0;
  u32 entity;
  u8 *temp_r3_2;
  u8 *temp_r3_3;
  u8 *temp_r3_4;
  if (TObjPlayer::check_demo_mode() != 0)
  {
    (((VObj_18_6eb1ad *)(arg0))->m103());
    return;
  }
  entity = (u32)find_entity_by_id((owner_id));
  if ((entity == 0U) || (((TObject *)entity)->all_parents_unqueued_for_destruction() == 0))
  {
    queue_destruction__7TObjectFv((void *) arg0);
    return;
  }
  if ((this->vfunc_83()) != 4)
  {
    (this->vfunc_85());
    temp_r3_2 = particle_effect;
    if (temp_r3_2 == 0)
    {
      particle_effect = (u8 *)create_particle_emitter(&this->m_2fc, 0xC7);
      temp_r3_3 = particle_effect;
      if (temp_r3_3 != 0)
      {
        ((TParticleCtrl *)temp_r3_3)->enable();
      }
    }
    else
    {
      ;
      if ((((mode) == 9) || ((mode) == 8)) || ((mode) == 7))
      {
        ((TParticleCtrl *)temp_r3_2)->enable();
      }
      else
      {
        if ((alternate_phase) == 0)
        {
          var_f30 = (3.0f);
          alternate_phase = 1;
        }
        else
        {
          var_f30 = (-3.0f);
          alternate_phase = 0;
        }
        if (TObjEneDD::check_v2_mode() != 0)
        {
          var_f30 *= (3.0f);
        }
        temp_f31 = var_f30 * ((f32 (*)(s32))cos_table_lookup)(rotation_y);
        temp_f2 = var_f30 * (-((f32 (*)(s32))sin_table_lookup)(rotation_y));
        *((f32 *) ((particle_effect) + 0x60)) = (f32) (((*(Vec *)&this->m_2fc).x) + temp_f31);
        *((f32 *) ((particle_effect) + 0x64)) = (f32) ((-1.5f) + ((*(Vec *)&this->m_2fc).y));
        *((f32 *) ((particle_effect) + 0x68)) = (f32) (((*(Vec *)&this->m_2fc).z) + temp_f2);
      }
    }
  }
  else
  {
    temp_r3_4 = particle_effect;
    if (temp_r3_4 != 0)
    {
      ((TParticleCtrl *)temp_r3_4)->enable();
    }
  }
  ((TObjEneBm3Fly *)arg0)->store_position();
  ((TBoss8Dragon *)arg0)->set_player_state_default();
  (this->vfunc_100());
}

extern "C" {
void *__dt__13TObjEneBm3FlyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TObjEneBm3Fly;
        if (((TObjEneBm3Fly *)arg0)->particle_effect != NULL) { queue_destruction__7TObjectFv(((TObjEneBm3Fly *)arg0)->particle_effect); *(s32 *)((s8 *)arg0 + 0x458) = 0; }
        free_collision_body_parts(arg0);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
struct VBase_18_800B1F80 { char pad[0x18]; };
struct VObj_18_800B1F80 : VBase_18_800B1F80 {
#define VV(n) virtual void m##n();
    VV(0) VV(1) VV(2) VV(3) VV(4) VV(5) VV(6) VV(7) VV(8) VV(9)
    VV(10) VV(11) VV(12) VV(13) VV(14) VV(15) VV(16) VV(17) VV(18) VV(19)
    VV(20) VV(21) VV(22) VV(23) VV(24) VV(25) VV(26) VV(27) VV(28) VV(29)
    VV(30) VV(31) VV(32) VV(33) VV(34) VV(35) VV(36) VV(37) VV(38) VV(39)
    VV(40) VV(41) VV(42) VV(43) VV(44) VV(45) VV(46) VV(47) VV(48) VV(49)
    VV(50) VV(51) VV(52) VV(53) VV(54) VV(55) VV(56) VV(57) VV(58) VV(59)
    VV(60) VV(61) VV(62) VV(63) VV(64) VV(65) VV(66) VV(67) VV(68) VV(69)
    VV(70) VV(71) VV(72) VV(73) VV(74) VV(75) VV(76) VV(77) VV(78) VV(79)
    VV(80) VV(81) VV(82) VV(83) VV(84)
#undef VV
    virtual s32 m85(s16, s32);
};

void reset_hp__9TObjEneDDFv(void *, s32, s32, s32);
void initialize_enemy_state__9TObjEneDDFv(void *, s32);
void init_model__9TObjEneDDFv(void *, void *, s32);

s32 TObjEneBm3Fly::init_child_params() {
    init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)bm3_fly_nest_resources + 0x42C)) + 8);
    this->texture_id = *(s32 *)((s8 *)(*(u8 **)((s8 *)bm3_fly_nest_resources + 0x42C)) + 0xC);
    init_model__9TObjEneDDFv(this, &bm3_fly_collider_params, 1);
    set_field_d8((s32)bm3_fly_action_table);
    set_field_dc(*(s32 *)((s8 *)bm3_fly_nest_resources + 0x430));
    this->m_b8 = 0;
    set_animation(this->m_b8);
    set_field_b8(this->m_b8);
    reset_hp__9TObjEneDDFv(this, bm3_fly_boss_stat_handle, TObjEneBm3Fly__attack_params, lbl_805D50E8);
    check_state_flag_1();
    this->movementParameters = bm3_fly_decision_row;
    initialize_enemy_state__9TObjEneDDFv(this, 3);
    this->m_37c = (5.0f);
    enemy_init_acquire_period(0xA);
    enemy_init_validate_period(0xA);
    set_active();
    this->actorFlags |= 0x01000000;
    *(s32 *)((s8 *)this + 0x428) = 2;
    *(f32 *)((s8 *)this + 0x42C) = *(f32 *)((s8 *)this + 0x3C);
    *(f32 *)((s8 *)this + 0x430) = (0.0f);
    *(f32 *)((s8 *)this + 0x434) = (0.0f);
    *(f32 *)((s8 *)this + 0x438) = (0.0f);
    *(f32 *)((s8 *)this + 0x43C) = (0.0f);
    *(s32 *)((s8 *)this + 0x440) = 0;
    *(f32 *)((s8 *)this + 0x444) = (0.0f);
    *(s32 *)((s8 *)this + 0x448) = 0;
    *(f32 *)((s8 *)this + 0x44C) = (2.0f) * calc_elapsed_scaled__9TObjEneDDFv(this) + (45.0f);
    *(f32 *)((s8 *)this + 0x450) = (2.0f) * calc_elapsed_scaled__9TObjEneDDFv(this) + (15.0f);
    *(s32 *)((s8 *)this + 0x454) = 0;
    this->particle_effect = 0;
    this->alternate_phase = 0;
    this->m_3c0 = 0;
    *(s32 *)((s8 *)this + 0x3C4) = 0;
    this->m_3c8 = 0;
    *(s32 *)((s8 *)this + 0x3CC) = 0;
    this->m_3d0 = 0;
    *(s32 *)((s8 *)this + 0x3D4) = 0;
    this->m_3d8 = 0;
    *(s32 *)((s8 *)this + 0x3DC) = 0;
    this->m_3e0 = (0.0f);
    *(f32 *)((s8 *)this + 0x3E4) = (0.0f);
    this->m_3e8 = (0.0f);
    *(f32 *)((s8 *)this + 0x3EC) = (0.0f);
    this->m_3f0 = (0.0f);
    *(f32 *)((s8 *)this + 0x3F4) = (0.0f);
    this->m_3f8 = (0.0f);
    *(f32 *)((s8 *)this + 0x3FC) = (0.0f);
    this->m_400 = (0.0f);
    *(f32 *)((s8 *)this + 0x404) = (0.0f);
    this->m_408 = (0.0f);
    this->mode = 0;
    return ((VObj_18_800B1F80 *)this)->m85(this->mode, 4);
}
#pragma pop

u8 *TObjEneBm3Fly__ct(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, u8 *arg5, u8 *arg6) {
    ((TObjEneDD_ST *)arg0)->init_object();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_800B2168___vt__13TObjEneBm3Fly *)__vt__13TObjEneBm3Fly).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjEneBm3Fly__name;
    ((TObjEneBm3Fly *)arg0)->owner_id = obj_getField1c(arg2);
    ((TObjEneDD *)arg0)->init_common_from((u8 *)arg2);
    ((TObjEneBm3Fly *)arg0)->m_1c = arg3;
    *(s16 *)((s8 *)arg0 + 0x2C) = arg4;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg5));
    VecCopy((Vec *)(arg0 + 0x41C), (const Vec *)(arg2 + 0x38));
    VecCopy((Vec *)(arg0 + 0x40C), (const Vec *)(arg6));
    ((TObjEneBm3Fly *)arg0)->init_child_params();
    *(s32 *)((s8 *)arg0 + 0x80) = 0;
    return arg0;
}

void TObjEneBm3Fly::release_shared_data() {
    void *obj = (*(void **)&TObjEneBm3Fly__breakup_model);
    if (obj != NULL) {
        if (obj != NULL) {
            ((VObj_800B2214_800B1978 *)obj)->m2(1);
        }
        (*(void **)&TObjEneBm3Fly__breakup_model) = NULL;
    }
}

void *TObjEneBm3Fly::create(void *arg1, void *arg2, void *arg3, void *arg4) {
    void *o;
    o = __nw__7TObjectFUl(0x4A8);
    if (o != NULL) {
        o = TObjEneBm3Fly__ct((u8 *)o, (s32)tl_04, (u8 *)this, (s32)arg1, (s32)arg2, (u8 *)arg3, (u8 *)arg4);
    }
    return o;
}

void TObjEneBm3Fly::load_resources() {
    typedef char sp8_offset[(offsetof(Stack_800B22C8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800B22C8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800B22C8, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_800B22C8, sp14) == 0xC) ? 1 : -1];
    Stack_800B22C8 stack;
    s32 temp_r3;
    s32 var_r0;
    u8 *temp_r5;
    bm3_fly_nest_resources = ((u8 * (*)(void))TObjEneBm3FlyNest__sub_800B4158)();
    temp_r3 = ((TAdSinglePlyChrSelectGC *)0x10)->alloc();
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = init_from_model__11TBreakUpMdlFl(temp_r3, (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)bm3_fly_nest_resources + 0x42C)) + 8)));
    }
    (*(s32 *)&(*(void **)&TObjEneBm3Fly__breakup_model)) = var_r0;
    bm3_fly_boss_stat_handle = register_boss__6TLobbyFl(0);
    TObjEneBm3Fly__attack_params = dispatch_shared_handler_b__6TLobbyFl(0);
    lbl_805D50E8 = register_object__6TLobbyFl(0);
    (*(s32 *)&(*(f32 **)&lbl_805D50EC)) = dispatch_shared_handler_a__6TLobbyFl(0);
    stack.sp8 = *(s32 *)((s8 *)&bm3_fly_resource_binding_desc.value + 0);
    stack.spC = *(s32 *)((s8 *)&bm3_fly_resource_binding_desc.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&bm3_fly_resource_binding_desc.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&bm3_fly_resource_binding_desc.value + 0xC);
    stack.sp8 = *(s32 *)((s8 *)bm3_fly_nest_resources + 0x430);
    temp_r5 = (u8 *)(*(u8 **)((s8 *)bm3_fly_nest_resources + 0x42C));
    TLobby::spawn_npc_enemy((s16)(7), (s32)((int) (*(s32 *)((s8 *)temp_r5 + 8))), (s32)((int) (*(s32 *)((s8 *)temp_r5 + 0xC))), (s32)((void *)&stack.sp8), (f32)((f32) (*(f32 *)((s8 *)&bm3_fly_collider_params.value + 0xC))), (f32)((f32) ((15.0f))));
}

}

#undef queue_destruction__7TObjectFv
#undef update_scale__15TObjBoss2TunnelFv
#undef remove_child__17TObjEneBm3FlyNestFPUc
#undef has_free_attack_slot__17TObjEneBm3FlyNestFUs
#undef clear_global_flag_400__9TObjEneDDFv
#undef update_player_state__9TObjEneDDFv
#undef set_field_378__9TObjEneDDFl
#undef transition_enemy_state__9TObjEneDDFs
#undef toggle_particle_effect__10TObjPlayerFv
#undef copy_target_state__14TObjEnePanarmsFPv
#undef advance_animation_playback
#undef end_effect_render__13TParticleCtrlFv
#undef play_sound_effect
#undef rotate_matrix_y
#undef set_global_param__8TObjFishFl
#undef vfunc_89__9TObjEneDDFv
#undef render__13TObjEneBm3FlyFv
#undef VBase_18
#undef VObj_18

#undef lbl_805D50EC
