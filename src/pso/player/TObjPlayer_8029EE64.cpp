#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TScene.h"
#include "pso/misc/TUnk_804DC7C4.h"
#include "pso/misc/TSceneSora.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"

struct Vec_8029EFFC { f32 x, y, z; };

struct Cam_8029EFFC { Vec_8029EFFC pos; Vec_8029EFFC scale; };

struct Pl_8029EFFC {
    u8 pad0[0x38];
    Vec_8029EFFC pos38;
    u8 pad44[0x2FC - 0x44];
    Vec_8029EFFC pos2FC;
};

struct G_8029EFFC {
    u8 pad0[0x178];
    f32 x178;
    f32 y17C;
    f32 z180;
};

struct Sora_8029EFFC {
    u8 pad0[0x1C];
    u32 f1C;
    u8 pad20[4];
    Vec_8029EFFC pos24;
};

extern "C" {
s32 TCameraCtrl__sub_800689F4();
s32 fn_8029F5B0(int, int, int, int);
s32 PSMTXConcat(void *, void *, void *);
s32 C_MTXLightPerspective(void *, f32, f32, f32, f32, f32, f32);
s32 GXSetTevOp(int, int);
s32 GXSetTevOrder(int, int, int, int);
s32 push_matrix();
s32 pop_matrix();
}
void calc_projection_screen_offset(f32 *arg0, f32 *arg1);
f32 calc_camera_fov_degrees(void);
void set_ginja_post_texgen_count(s32 x);
void set_ginja_post_tev_stage_count(s32 x);
void load_current_pos_matrix(s32 arg0);
void load_current_tex_matrix(s32 i);
extern const f64 lbl_80465E18;
extern u32 camera_ctrl_instance;
extern u32 lbl_805D65F0;
extern s32 current_matrix;
extern const f32 lbl_805DDDA0;
extern const f32 lbl_805DDDA4;
extern const f32 lbl_805DDDA8;
extern "C" {
void TObjPlayer__sub_8029EE2C(void);
int set_instance__6TSceneFi(void *f);
void VecCopy__FP3VecPC3Vec(Vec_8029EFFC *, Vec_8029EFFC *);
f32 fabs_float(f32);
void *get_player_by_client_id(s32 i);
s32 fn_8029E7BC(s32 arg0, u8 *arg1);
s32 fn_8029EC3C(Vec_8029EFFC *, s32);
void TScene__sub_8029F5D8();
void TScene__sub_8029F5E4(f32);
void TScene__sub_8029F5EC();
f32 vec_squared_length(u8 *arg0);
void reflect_matrix_in_plane(s32, Cam_8029EFFC *);
void normalize_vector(Vec_8029EFFC *);
extern Vec_8029EFFC sora_reflection_up_vec;
extern s32 TSceneSora__sky_active_flag;
extern s32 local_client_id;
extern u32 TSceneSora__instance;
extern s16 scene_sora_reflect_active;
extern u8 scene_sora_recon_active_flag;
extern const f32 lbl_805DDD8C;
extern const f32 lbl_805DDD90;
extern const f32 lbl_805DDDAC;
extern const f32 lbl_805DDDB0;
extern s32 model_render_flags;

void TObjPlayer::clear_state_if_flag80(s32 arg0) {
    if (arg0 & 0x80) {
        set_ginja_post_tev_stage_count(0);
        set_ginja_post_texgen_count(0);
        TObjPlayer::set_global_effect_state(0);
        model_render_flags &= 0xFFF7FFFF;
    }
}

void TObjPlayer::setup_projection_texture(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp10[0x30];
    f32 spC;
    f32 sp8;
    f32 temp_f31;
    if (((u32) camera_ctrl_instance != 0U) && ((u32) lbl_805D65F0 != 0U)) {
        calc_projection_screen_offset(&spC, &sp8);
        if (arg2 & 0x80) {
            push_matrix();
            temp_f31 = (f32) (lbl_80465E18 * calc_camera_fov_degrees());
            if (TCameraCtrl__sub_800689F4() != 0) {
                C_MTXLightPerspective(&sp10, temp_f31, lbl_805DDDA0, lbl_805DDDA4, lbl_805DDDA8, (f32) (lbl_805DDDA4 - spC), (f32) (lbl_805DDDA4 - sp8));
            } else {
                C_MTXLightPerspective(&sp10, temp_f31, lbl_805DDDA0, lbl_805DDDA4, lbl_805DDDA8, lbl_805DDDA4, lbl_805DDDA4);
            }
            PSMTXConcat(&sp10, (void *)current_matrix, (void *)current_matrix);
            load_current_tex_matrix(2);
            pop_matrix();
            load_current_pos_matrix(2);
            GXSetTevOrder(1, 1, 2, 4);
            GXSetTevOp(1, 2);
            fn_8029F5B0(1, 0, 0, 0x24);
            model_render_flags |= 0x80000;
            set_ginja_post_tev_stage_count(1);
            set_ginja_post_texgen_count(1);
            TObjPlayer::set_global_effect_state(1);
        }
    }
}

void TUnk_804DC7C4::render_shadows() {
    Sora_8029EFFC *o = (Sora_8029EFFC *)this;
    Cam_8029EFFC c3;
    Cam_8029EFFC c2;
    Cam_8029EFFC c1;
    s32 r = 0;
    Vec_8029EFFC v = sora_reflection_up_vec;
    s32 hit;
    s32 i;
    f32 k;
    f32 len;
    Pl_8029EFFC *p;
    if (camera_ctrl_instance == 0 || o->f1C == 0) {
        return;
    }
    p = (Pl_8029EFFC *)get_player_by_client_id(local_client_id);
    if (p == NULL) {
        return;
    }
    TScene__sub_8029F5EC();
    TScene__sub_8029F5E4(lbl_805DDDAC);
    if (TSceneSora__instance != 0) {
        TSceneSora__sky_active_flag = 0;
    }
    TSceneSora::copy_reflection_vec((u8 *)&v);
    scene_sora_reflect_active = 1;
    {
        Vec_8029EFFC off = p->pos2FC;
        off.y += lbl_805DDDB0;
        hit = fn_8029E7BC((s32)&off, (u8 *)&o->pos24);
    }
    if (is_boss_area() != 0) {
        hit = 1;
    }
    if (hit != 0 || scene_sora_recon_active_flag != 0) {
        scene_sora_recon_active_flag = 0;
        if (is_boss_area() != 0) {
            if (p != NULL) {
                ((TMainTask *)((u8 *)&main_task))->render_object_layers(2);
                if (get_current_floor_area() == AREA_BARBA_RAY) {
                    c3.pos.x = p->pos38.x;
                    c3.pos.y = p->pos38.y;
                    c3.pos.z = p->pos38.z;
                    c3.scale.x = lbl_805DDD8C;
                    c3.scale.y = lbl_805DDD90;
                    c3.scale.z = c3.scale.x;
                    push_matrix();
                    reflect_matrix_in_plane(0, &c3);
                    ((TMainTask *)((u8 *)&main_task))->render_object_layers(3);
                    pop_matrix();
                }
            }
        } else if (p != NULL) {
            ((TMainTask *)((u8 *)&main_task))->render_object_layers(1);
            c2.pos.x = o->pos24.x;
            c2.pos.y = o->pos24.y;
            c2.pos.z = o->pos24.z;
            c2.scale.x = lbl_805DDD8C;
            c2.scale.y = lbl_805DDD90;
            c2.scale.z = c2.scale.x;
            push_matrix();
            reflect_matrix_in_plane(0, &c2);
            ((TMainTask *)((u8 *)&main_task))->render_object_layers(4);
            pop_matrix();
        }
    }
    ((TMainTask *)((u8 *)&main_task))->render_task_layer_02();
    if (p != NULL) {
        c1.pos.x = o->pos24.x;
        c1.pos.y = o->pos24.y;
        c1.pos.z = o->pos24.z;
        c1.scale.x = lbl_805DDD8C;
        c1.scale.y = lbl_805DDD90;
        c1.scale.z = c1.scale.x;
        push_matrix();
        reflect_matrix_in_plane(0, &c1);
        ((TMainTask *)((u8 *)&main_task))->render_object_layers(5);
        pop_matrix();
    }
    k = lbl_805DDD8C;
    scene_sora_reflect_active = 0;
    for (i = 0; i < 2; i++) {
        v.x = p->pos38.x - ((G_8029EFFC *)camera_ctrl_instance)->x178;
        v.y = k;
        v.z = p->pos38.z - ((G_8029EFFC *)camera_ctrl_instance)->z180;
        len = fabs_float(v.z);
        if (fabs_float(v.x) >= len) {
            if (i != 0) {
                if (lbl_805DDD8C != v.z) {
                    v.x = lbl_805DDD8C;
                }
            } else if (lbl_805DDD8C != v.x) {
                v.z = lbl_805DDD8C;
            }
        } else if (i != 0) {
            if (lbl_805DDD8C != v.x) {
                v.z = lbl_805DDD8C;
            }
        } else if (lbl_805DDD8C != v.z) {
            v.x = lbl_805DDD8C;
        }
        if (k != vec_squared_length((u8 *)&v)) {
            Vec_8029EFFC tmp;
            normalize_vector(&v);
            TSceneSora::copy_reflection_vec((u8 *)&v);
            push_matrix();
            push_matrix();
            VecCopy__FP3VecPC3Vec(&tmp, &p->pos2FC);
            r = fn_8029EC3C(&tmp, 0x4000);
            if (r == 1) {
                ((TMainTask *)((u8 *)&main_task))->render_object_layers(0);
            }
            pop_matrix();
            pop_matrix();
        }
        if (r != 0) {
            break;
        }
    }
    TScene__sub_8029F5D8();
    TScene__sub_8029F5E4(lbl_805DDD8C);
    if (TSceneSora__instance != 0) {
        TSceneSora__sky_active_flag = 1;
    }
    ((TObjPlayer *)(o->f1C))->copy_efb_to_texture();
    TSceneSora::set_scene_flag(o->f1C + 0x1C);
}

void TUnk_804DC7C4::render() {  }
int TScene::set_scene_callbacks() {
    TScene::set_id((int)((void *)TObjPlayer::setup_projection_texture));
    TScene::set_active_scene((int)((void *)TObjPlayer::clear_state_if_flag80));
    return set_instance__6TSceneFi((void *)TObjPlayer__sub_8029EE2C);
}
}
