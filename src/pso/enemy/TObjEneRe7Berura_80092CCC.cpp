#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct BeruraBase_800931C8_80093180 { char pad[0x14]; };
struct BeruraV_800931C8_80093180 : BeruraBase_800931C8_80093180 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

struct Vec_80093470 { f32 x, y, z; };

struct BeruraBase_80093470 { char pad[0x18]; };

struct Berura_80093470 : BeruraBase_80093470 {
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
};

struct Fields_80093470 {
    u8 pad0[0x38];
    Vec_80093470 pos;
    u8 pad44[0xB8 - 0x44];
    s16 fieldB8;
    u8 padBA[0x308 - 0xBA];
    Vec_80093470 vel;
    u8 pad314[0x378 - 0x314];
    s32 field378;
    u8 pad37C[0x3C0 - 0x37C];
    u32 field3C0;
};

struct VBase_14_c1c33b { char pad[0x14]; };

struct VObj_14_c1c33b : VBase_14_c1c33b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct F_8009331C {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0x3C0 - 0xBA];
    u32 f3C0;
    u8 pad3C4[0x3CC - 0x3C4];
    s32 f3CC;
    u8 pad3D0[0x3F8 - 0x3D0];
    s32 f3F8;
    u8 pad3FC[0x4C0 - 0x3FC];
    s32 f4C0;
    s32 f4C4;
    u8 pad4C8[0x4D0 - 0x4C8];
    f32 f4D0;
};

struct VBase_14_fddec9 { char pad[0x14]; };

struct VObj_14_fddec9 : VBase_14_fddec9 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
};

struct Fade_80092CCC { VObj_14_fddec9 v; u8 pad[0x1C - sizeof(VObj_14_fddec9)]; };

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
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84();
    virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93(); virtual void m94();
    virtual void m95(); virtual void m96(); virtual void m97(); virtual void m98(); virtual void m99();
    virtual void m100(); virtual void m101(); virtual void m102(); virtual void m103();
    virtual void m104();
};

struct Vec_80092CCC { f32 x, y, z; };

struct Elem_80092CCC { u8 data[0x64]; };

struct Berura_80092CCC {
    VObj_18_1fdb47 v;
    u8 pad1C[0x24 - sizeof(VObj_18_1fdb47)];
    s32 f24;
    u8 pad28[0x10];
    Vec_80092CCC pos;
    u8 pad44[0x1C];
    s32 f60;
    u8 pad64[0x2FC - 0x64];
    Vec_80092CCC f2FC;
    u8 pad308[0x326 - 0x308];
    s16 f326;
    u8 pad328[0x3C0 - 0x328];
    s32 f3C0;
    s32 f3C4;
    u32 f3C8;
    u8 pad3CC[4];
    s32 f3D0;
    u8 pad3D4[4];
    Fade_80092CCC f3D8;
    u8 pad3F4[8];
    u8 f3FC[0x418 - 0x3FC];
    u32 f418[2];
    Vec_80092CCC f420[2];
    u8 pad438[0x448 - 0x438];
    Fade_80092CCC fades[2];
};

extern "C" {
s32 transition_enemy_state__9TObjEneDDFs(void *, s32);
s32 copy_target_state__14TObjEnePanarmsFPv(void *, int);
s32 play_sound_effect(s32, void *, s32, s32);
s32 advance_animation_playback(void *);
extern const f32 TObjEneRe7Berura__data_805D9738;
void TObjEneRe7Berura__sub_80093470(Berura_80093470 *obj, s32 mode);
void TObjEneRe7BeruraPunch__sub_800962F4(void *p);
void TObjPlayer__sub_800A04F0(void *);
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 fn_80095DD0(void *);
s32 fn_80095DF4(void *);
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_player_state__9TObjEneDDFv(void *, void *, int);
s32 update_obstruction_fade(void *);
s32 scroll_strip_uvs(s32, int, int);
s32 defer_render__7TObjectFv(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern Vec_80092CCC lbl_80439EC4[];
extern Elem_80092CCC TObjEneRe7Berura__detached_part_states[];
extern s32 re7_berura_demo_state;
extern s32 lbl_805D4F6C;
extern s32 re7_berura_demo_camera_ptr;
extern s32 berura_demo_flag;
extern s32 re7_berura_demo_flag;
extern void *TObjEneRe7Berura__demo_target;
extern s32 *berura_node_matrix_ptr_a;
extern s16 *berura_node_matrix_ptr_b;
extern s32 belra_uv_animation_buffer;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 TObjEneRe7Berura__data_805D9724;
extern const f32 lbl_805D9728;
extern const f32 TObjEneRe7Berura__data_805D972C;
extern const f32 TObjEneRe7Berura__data_805D9730;
extern const f32 lbl_805D9734;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
void render__16TObjEneRe7BeruraFv(Berura_80092CCC *o);
s32 get_camera_ctrl__9TObjEneDDFv(s32, s32);

void render__16TObjEneRe7BeruraFv(Berura_80092CCC *o) {
    s32 fade;
    s32 mode;
    s32 cam;
    s32 i;
    s32 f1;
    s32 f2;
    s32 l3;
    s32 l4;
    if (TObjPlayer::check_demo_mode() != 0) {
        o->v.m104();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = get_camera_mode__11TCameraCtrlFv();
    }
    if (o->f3C0 & 1) {
        mode = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        mode = o->v.m9(lbl_805D9E88, lbl_805D9E84, lbl_805D9728);
    } else if (o->v.m8(TObjEneRe7Berura__data_805D9724, lbl_805D9728) != 0) {
        mode = 1;
    } else {
        mode = 0;
    }
    if (mode != 0) {
        if (o->f326 != 0xB) {
            Vec_80092CCC v = lbl_80439EC4[0];
            update_player_state__9TObjEneDDFv(o, &v, 0);
        }
        ((TObjEneDD *)o)->update_secondary_light();
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        model_render_flags &= ~0x810;
        TObjPlayer::toggle_particle_effect();
        for (i = 0; i < 2; i++) {
            if (o->f418[i] & 1) {
                fn_80095DF4(&TObjEneRe7Berura__detached_part_states[i]);
            }
        }
        *berura_node_matrix_ptr_a = o->f3C4;
        berura_node_matrix_ptr_b[0] = o->f3C8;
        berura_node_matrix_ptr_b[1] = o->f3C8 >> 16;
        scroll_strip_uvs(belra_uv_animation_buffer, (s16)o->f3D0, 0);
        fade = (s32)&o->fades[cam];
        update_obstruction_fade((void *)fade);
        cam = ((RenderFadeState *)fade)->updateFromCamera((const f32*)(&o->f2FC));
        TObjFish::set_global_param(o->f24);
        push_matrix();
        post_translate_matrix(&o->pos);
        rotate_matrix_y(0, o->f60);
        if (o->f326 == 5) {
            re7_berura_demo_state = 0;
            lbl_805D4F6C = 0;
            (*(void * *)&re7_berura_demo_camera_ptr) = o->f420;
            o->f420[0].x = lbl_805D9728;
            o->f420[0].y = TObjEneRe7Berura__data_805D972C;
            o->f420[0].z = TObjEneRe7Berura__data_805D9730;
            o->f420[1].x = lbl_805D9728;
            o->f420[1].y = TObjEneRe7Berura__data_805D972C;
            o->f420[1].z = lbl_805D9734;
            berura_demo_flag = (o->f418[0] >> 2) & 1;
            re7_berura_demo_flag = (o->f418[1] >> 2) & 1;
            TObjEneRe7Berura__demo_target = o->f3FC;
            if (cam != 0) {
                re7_berura_demo_flag = 0;
                berura_demo_flag = 0;
                ((Fade_80092CCC *)fade)->v.m6();
                f1 = 1;
                if (defer_render__7TObjectFv(o) != 0) {
                    f1 = 0;
                }
                if (f1 != 0) {
                    TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneRe7Berura::demo_frame_callback));
                    ((TObjMotion *)o)->draw();
                    TObjEneRe7Berura::set_global_state(0);
                }
                ((Fade_80092CCC *)fade)->v.m7();
            } else {
                TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneRe7Berura::demo_frame_callback));
                if (mode == 1) {
                    ((TObjMotion *)o)->draw();
                } else {
                    ((TObjEnemy *)o)->render_world_model();
                }
                TObjEneRe7Berura::set_global_state(0);
            }
        } else {
            re7_berura_demo_state = 0;
            lbl_805D4F6C = 0;
            if (o->f3C0 & 2) {
                if (o->f3D8.v.m8() != 0) {
                    o->f3D8.v.m6();
                    f2 = 1;
                    if (defer_render__7TObjectFv(o) != 0) {
                        f2 = 0;
                    }
                    if (f2 != 0) {
                        TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneRe7Berura::advance_state));
                        ((TObjMotion *)o)->draw();
                        TObjEneRe7Berura::set_global_state(0);
                    }
                    o->f3D8.v.m7();
                }
            } else if (cam != 0) {
                ((Fade_80092CCC *)fade)->v.m6();
                TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneRe7Berura::advance_state));
                ((TObjMotion *)o)->draw();
                TObjEneRe7Berura::set_global_state(0);
                ((Fade_80092CCC *)fade)->v.m7();
            } else if (mode == 1) {
                ((TObjMotion *)o)->draw();
            } else {
                ((TObjEnemy *)o)->render_world_model();
            }
        }
        pop_matrix();
        ((TObjEneDD *)o)->update_primary_light();
        for (l3 = 0; l3 < 2; l3++) {
            if (o->f418[l3] & 1) {
                fn_80095DD0(&TObjEneRe7Berura__detached_part_states[l3]);
            }
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        return;
    }
    if (o->f326 == 5) {
        for (l4 = 0; l4 < 2; l4++) {
            VecCopy((Vec *)&o->f420[l4], (const Vec *)&o->pos);
        }
    }
}

void TObjEneRe7Berura::advance_state() {
    switch ((s32) re7_berura_demo_state) {
    case 25:
        lbl_805D4F6C = model_render_flags;
        model_render_flags &= 0xFFFF7FFF;
        break;
    case 26:
        model_render_flags = lbl_805D4F6C;
        break;
    }
    re7_berura_demo_state += 1;
}

void TObjEneRe7Berura::demo_frame_callback() {
    switch ((s32) re7_berura_demo_state) {
    case 0x2:
        lbl_805D4F6C = model_render_flags;
        model_render_flags &= 0xFFFF7FFF;
        break;
    case 0x3:
        model_render_flags = lbl_805D4F6C;
        break;
    case 0x4C:
    case 0x50:
        get_camera_ctrl__9TObjEneDDFv(re7_berura_demo_camera_ptr, re7_berura_demo_camera_ptr);
        re7_berura_demo_camera_ptr += 0xC;
        break;
    case 0x21:
        if ((s32) berura_demo_flag != 0) {
            ((BeruraV_800931C8_80093180 *)TObjEneRe7Berura__demo_target)->m6();
        }
        break;
    case 0x38:
        if ((s32) re7_berura_demo_flag != 0) {
            ((BeruraV_800931C8_80093180 *)TObjEneRe7Berura__demo_target)->m6();
        }
        break;
    case 0x32:
        if ((s32) berura_demo_flag != 0) {
            ((BeruraV_800931C8_80093180 *)TObjEneRe7Berura__demo_target)->m7();
        }
        break;
    case 0x49:
        if ((s32) re7_berura_demo_flag != 0) {
            ((BeruraV_800931C8_80093180 *)TObjEneRe7Berura__demo_target)->m7();
        }
        break;
    }
    re7_berura_demo_state += 1;
}

void TObjEneRe7Berura::update_death_state(s32 mode) {
    F_8009331C *self = (F_8009331C *)this;
    switch (mode) {
    case 4:
        self->fB8 = 7;
        this->vfunc_96();
        self->f3C0 &= ~7;
        advance_animation_playback(self);
        ((TBoss8Dragon *)self)->refresh_and_send_entity_flags();
        TObjEneRe7BeruraPunch__sub_800962F4((void *)self->f3F8);
        self->f4D0 = self->f3CC;
        self->f4C4 = 0;
        self->f4C0 = 0;
        ((TObjPlayer *)((u8 *)self + 0x2FC))->request_two_effects();
        TObjPlayer__sub_800A04F0((u8 *)self + 0x3D8);
        self->f3C0 |= 2;
        play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(self, 0x4003AD25), (u8 *)self + 0x38, 0, 0);
        break;
    case 0:
        switch (self->f4C4) {
        case 0: {
            advance_animation_playback(self);
            if (((VObj_14_c1c33b *)((u8 *)self + 0x3D8))->m4() != 0) {
                self->f4C4 = 4;
                self->f3C0 |= 1;
                TObjPlayer::apply_effect_variant_b((s32)((u8 *)self + 0x38), 0);
                queue_destruction__7TObjectFv(self);
            }
        }
            break;
        }
        break;
    case 3:
        break;
    case 5:
        break;
    }
}

void TObjEneRe7Berura__sub_80093470(Berura_80093470 *obj, s32 mode) {
    Fields_80093470 *self = (Fields_80093470 *)obj;
    Vec_80093470 v;
    f32 speed;
    switch (mode) {
    case 4:
        self->fieldB8 = 6;
        obj->m94();
        self->field3C0 &= ~7;
        advance_animation_playback(self);
        play_sound_effect(copy_target_state__14TObjEnePanarmsFPv(self, 0x4003A826), &self->pos, 0, 0);
        ((TObjEneDD_ST *)self)->set_active();
        break;
    case 3:
        if (((TObjEneDD *)self)->get_flag_b4() != 0) {
            transition_enemy_state__9TObjEneDDFs(self, self->field378);
        }
        break;
    case 0:
        advance_animation_playback(self);
        VecCopy((Vec *)&v, (const Vec *)&self->vel);
        speed = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
        ((TObjEneDD *)self)->move_clamped_on_ground(v.x, v.z, speed);
        self->vel.x *= TObjEneRe7Berura__data_805D9738;
        self->vel.z *= TObjEneRe7Berura__data_805D9738;
        break;
    case 5:
        ((TObjEneDD *)self)->clear_attack_receipts();
        ((TObjEneDD *)self)->clear_field_388();
        break;
    }
}

}
