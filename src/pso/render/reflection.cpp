// Sora (sky) reflection: the reflected-scene task (TUnk_804DC7C4), its
// floor-ray helpers and the recon render hooks. One TU: one .sdata2 pool
// 0x805DDD88-0x805DDDB8 in first-use order across 0x8029E7BC-0x8029F5B0
// (35.0 at 0x8029E7BC, 0.0/1.0 at push_reflection_matrix, 480.0, 80.0/300.0
// at 0x8029EC3C, then the projection literals), and the task's vtable
// 0x804DC7C4 names functions of both ends.
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/vector.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/reflection.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/memory.h"
#include "pso/system/scene/TSceneSora.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/scene/TScene.h"
#include "pso/unk/TUnk_804DC7C4.h"
#include "pso/effect/TEffIndirectSampler.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/GinjaRenderTarget.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/scene/TScene_800838C4.h"
#include "pso/system/scene/TScene_8029F5B0.h"
#include "pso/player/TObjPlayer_803DC834.h"
#include <stddef.h>
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"

s32 lbl_805D65F0;
void *scene_sora_instance;
u16 scene_sora_reflect_active;
u8 scene_sora_recon_active_flag;
GinjaRenderTarget *scene_sora_recon_object;

// The direction the reflection ray is cast along (straight up until
// TSceneSora::copy_reflection_vec replaces it).
Vec sora_reflection_ray_direction = {0.0f, 1.0f, 0.0f};

extern "C" {
void reflect_matrix_in_plane(s32 mode, void *plane);
}

s32 fn_8029E7BC(saddr arg0, u8 *arg1) {
  Vec probe;
  s32 area;
  s32 mask;
  CsnHit *hit;
  CsnContact *contact;
  area = get_current_floor_area();
  mask = 0x56EF;
  if (area == AREA_BARBA_RAY)
  {
    mask = 0x4000;
  }
  VecCopy(&probe, (const Vec *)arg0);
  probe.y += 35.0f;
  hit = csnVecterUnder(&probe, mask);
  if (hit != 0)
  {
    contact = hit->contact;
    if (!(contact->flags & 0x4000))
    {
      return 0;
    }
    if (arg1 != 0)
    {
      *((f32 *) (arg1 + 0)) = contact->point.x;
      *((f32 *) (arg1 + 4)) = hit->contact->point.y;
      *((f32 *) (arg1 + 8)) = hit->contact->point.z;
      *((f32 *) (arg1 + 0xC)) = hit->contact->normal.x;
      *((f32 *) (arg1 + 0x10)) = hit->contact->normal.y;
      *((f32 *) (arg1 + 0x14)) = hit->contact->normal.z;
    }
    return 1;
  }
  return 0;
}

extern "C" {
s32 GXSetScissor(s32, s32, s32, s32);
}

s32 push_player_reflection_matrix(u16 client_id, s32 clip) {
    s32 sp8[8];
    s32 var_r3;
    uaddr player;

    if (is_central_control_area() == 0) {
        return 0;
    }
    if ((u16) scene_sora_reflect_active == 0) {
        return 1;
    }
    player = (uaddr)get_player_by_client_id(client_id);
    if (player == 0U) {
        return 0;
    }
    if (fn_8029E7BC(player + 0x2FC, (u8 *)sp8) == 0) {
        return 0;
    }
    if (clip != 0) {
        var_r3 = set_reflection_scissor(sp8, 1);
    } else {
        var_r3 = 1;
    }
    if (var_r3 != 0) {
        push_matrix();
        reflect_matrix_in_plane(0, sp8);
    }
    return var_r3;
}

s32 push_reflection_matrix(Vec *point) {
    Vec plane[2];
    s32 visible;
    if (scene_sora_reflect_active == 0) {
        return 1;
    }
    if (point == NULL) {
        return 0;
    }
    plane[0].x = point->x;
    plane[0].y = point->y;
    plane[0].z = point->z;
    plane[1].x = 0.0f;
    plane[1].y = 1.0f;
    plane[1].z = plane[1].x;
    visible = set_reflection_scissor(point, 1);
    if (visible != 0) {
        push_matrix();
        reflect_matrix_in_plane(0, (s32 *)plane);
    }
    return visible;

}

void restore_render_scissor(s32 reset_scissor) {
    if ((u16) scene_sora_reflect_active != 0) {
        pop_matrix();
        if (reset_scissor != 0) {
            GXSetScissor(0, 0, 0x280, 0x1E0);
        }
    }
}

s32 set_reflection_scissor(void *point, s32 _w1) {
    Vec v;
    if (scene_sora_reflect_active == 0) {
        return 1;
    }
    restore_render_scissor(1);
    project_world_to_screen(NULL, (const Vec *)point, &v.x);
    if (v.y >= 0.0f && v.y <= 480.0f) {
        GXSetScissor(0, (s32)((u32)v.y), 0x280, (s32)((u32)(480.0f - v.y)));
        return 1;
    }
    return 0;
}

void reset_reflection_tev_stages() {
    if (scene_sora_instance != NULL) {
        // get_state() reads the word at 0x20, which is TUnk_804DC7C4::indirect_effect.
        TEffIndirectSampler *indirect = (TEffIndirectSampler *)((TSceneSora *)scene_sora_instance)->get_state();
        if (indirect != NULL) {
            indirect->disable_indirect_tev();
        }
    }
}

void play_reflection_particles(s16 effect_id) {
    if (scene_sora_instance != NULL) {
        TEffIndirectSampler *indirect = (TEffIndirectSampler *)((TSceneSora *)scene_sora_instance)->get_state();
        if (indirect != NULL) {
            indirect->enable_indirect_tev(0, effect_id);
        }
    }
}

void destroy_reflection_target() {
    scene_sora_instance = 0;
    if (is_central_control_area() != 0) {
        if (scene_sora_recon_object != NULL) {
            scene_sora_recon_object->release_texture();
        }
        if (scene_sora_recon_object != NULL) {
            ::operator delete(scene_sora_recon_object);
            scene_sora_recon_object = NULL;
        }
    }
}


void create_reflection_target() {
    GinjaRenderTarget *target;

    if (is_central_control_area() != 0) {
        scene_sora_instance = 0;
        target = static_cast<GinjaRenderTarget *>(::operator new(sizeof(GinjaRenderTarget)));
        scene_sora_recon_object = target;
        if (target != NULL) {
            target->init_render_target();
            lbl_805D65F0 = reinterpret_cast<saddr>(&scene_sora_recon_object->texture_list);
        }
    }
}

struct Ray_8029EC3C { Vec o; Vec d; };


extern "C" {
#pragma push
#pragma fp_contract on
s32 fn_8029EC3C(Vec *pos, s32 mask) {
    Ray_8029EC3C ray;
    Vec a;
    Vec b;
    Vec d;
    void *p;
    CsnHit *r;
    CsnContact *e;
    f32 scale;
    p = get_player_by_client_id(local_client_id);
    if (p == 0) return 0;
    scale = 80.0f;
    if (get_current_floor_area() == AREA_SEABED_UPPER) {
        if ((s16)((TObjBase *)p)->get_room() == 0x5A) {
            scale = 300.0f;
        } else {
            scale = 80.0f;
        }
    }
    VecCopy((Vec *)&a, (const Vec *)pos);
    b.x = scale * sora_reflection_ray_direction.x + a.x;
    b.y = a.y - 35.0f * sora_reflection_ray_direction.y;
    b.z = scale * sora_reflection_ray_direction.z + a.z;
    d.x = b.x - pos->x;
    d.z = b.z - pos->z;
    d.y = b.y - pos->y;
    if (0.0f == vec_squared_length(&d)) {
        ray.o.x = pos->x;
        ray.o.y = pos->y;
        ray.o.z = pos->z;
        ray.d.x = sora_reflection_ray_direction.x;
        ray.d.y = sora_reflection_ray_direction.y;
        ray.d.z = sora_reflection_ray_direction.z;
        reflect_matrix_in_plane(0, &ray);
        return 1;
    }
    if (0.0f == sora_reflection_ray_direction.x && 0.0f == sora_reflection_ray_direction.z) {
        r = csnVecterUnder(&a, mask);
    } else {
        r = csnVector(&a, &b, mask);
    }
    if (r != 0) {
        e = r->contact;
        if (!(e->flags & 0x4000)) return 0;
        ray.o.x = e->point.x;
        ray.o.y = e->point.y;
        ray.o.z = e->point.z;
        ray.d.x = e->normal.x;
        ray.d.y = e->normal.y;
        ray.d.z = e->normal.z;
        reflect_matrix_in_plane(0, &ray);
        return 1;
    }
    return 0;
}
#pragma pop

}

void TObjPlayer__sub_8029EE2C(void) { TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lbl_805D65F0)); load_list_texture((saddr)((void*)0), (saddr)((void*)0), (saddr)((void*)0), (saddr)((void*)2)); }

struct Cam_8029EFFC { Vec pos; Vec scale; };

struct Pl_8029EFFC {
    u8 pad0[0x38];
    Vec pos38;
    u8 pad44[0x2FC - 0x44];
    Vec pos2FC;
};

extern "C" {
// Every caller tests this as an int; the header's bool return would not match.
void GXSetTevOp(s32 stage, s32 mode);
void GXSetTevOrder(s32 stage, s32 coord, s32 map, s32 color);
}
const f64 lbl_80465E18 = 0.0054931640625;

const Vec sora_reflection_up_vec = {0.0f, 1.0f, 0.0f};

void TObjPlayer::clear_state_if_flag80(s32 arg0) {
    if (arg0 & 0x80) {
        set_ginja_post_tev_stage_count(0);
        set_ginja_post_texgen_count(0);
        TObjPlayer::set_global_effect_state(0);
        model_render_flags &= 0xFFF7FFFF;
    }
}

void TObjPlayer::setup_projection_texture(Vec *, SceneSectionAngles *, u32 flags) {
    GinjaMatrix mtx;
    f32 x;
    f32 y;
    f32 fov_y;
    if ((camera_ctrl_instance != NULL) && ((u32) lbl_805D65F0 != 0U)) {
        calc_projection_screen_offset(&x, &y);
        if (flags & 0x80) {
            push_matrix();
            fov_y = (f32) (lbl_80465E18 * calc_camera_fov_degrees());
            if (TCameraCtrl::is_view_offset() != 0) {
                C_MTXLightPerspective(mtx, fov_y, 1.1333334f, 0.5f, -0.5f, (f32) (0.5f - x), (f32) (0.5f - y));
            } else {
                C_MTXLightPerspective(mtx, fov_y, 1.1333334f, 0.5f, -0.5f, 0.5f, 0.5f);
            }
            PSMTXConcat(mtx, *current_matrix, *current_matrix);
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
    Cam_8029EFFC c3;
    Cam_8029EFFC c2;
    Cam_8029EFFC c1;
    s32 r = 0;
    Vec v = sora_reflection_up_vec;
    s32 hit;
    s32 i;
    f32 k;
    f32 len;
    Pl_8029EFFC *p;
    if (camera_ctrl_instance == 0 || recon_object == 0) {
        return;
    }
    p = (Pl_8029EFFC *)get_player_by_client_id(local_client_id);
    if (p == NULL) {
        return;
    }
    TScene::begin_reflection_pass();
    TScene::set_visibility_radius_margin(100.0f);
    if (TSceneSora::instance != 0) {
        TSceneSora::sky_active_flag = 0;
    }
    TSceneSora::copy_reflection_vec((u8 *)&v);
    scene_sora_reflect_active = 1;
    {
        Vec off = p->pos2FC;
        off.y += 10.0f;
        hit = fn_8029E7BC((saddr)&off, (u8 *)&reflect_pos);
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
                    c3.scale.x = 0.0f;
                    c3.scale.y = 1.0f;
                    c3.scale.z = c3.scale.x;
                    push_matrix();
                    reflect_matrix_in_plane(0, &c3);
                    ((TMainTask *)((u8 *)&main_task))->render_object_layers(3);
                    pop_matrix();
                }
            }
        } else if (p != NULL) {
            ((TMainTask *)((u8 *)&main_task))->render_object_layers(1);
            c2.pos.x = reflect_pos.x;
            c2.pos.y = reflect_pos.y;
            c2.pos.z = reflect_pos.z;
            c2.scale.x = 0.0f;
            c2.scale.y = 1.0f;
            c2.scale.z = c2.scale.x;
            push_matrix();
            reflect_matrix_in_plane(0, &c2);
            ((TMainTask *)((u8 *)&main_task))->render_object_layers(4);
            pop_matrix();
        }
    }
    ((TMainTask *)((u8 *)&main_task))->render_task_layer_02();
    if (p != NULL) {
        c1.pos.x = reflect_pos.x;
        c1.pos.y = reflect_pos.y;
        c1.pos.z = reflect_pos.z;
        c1.scale.x = 0.0f;
        c1.scale.y = 1.0f;
        c1.scale.z = c1.scale.x;
        push_matrix();
        reflect_matrix_in_plane(0, &c1);
        ((TMainTask *)((u8 *)&main_task))->render_object_layers(5);
        pop_matrix();
    }
    k = 0.0f;
    scene_sora_reflect_active = 0;
    for (i = 0; i < 2; i++) {
        v.x = p->pos38.x - camera_ctrl_instance->pos.x;
        v.y = k;
        v.z = p->pos38.z - camera_ctrl_instance->pos.z;
        len = fabs_float(v.z);
        if (fabs_float(v.x) >= len) {
            if (i != 0) {
                if (0.0f != v.z) {
                    v.x = 0.0f;
                }
            } else if (0.0f != v.x) {
                v.z = 0.0f;
            }
        } else if (i != 0) {
            if (0.0f != v.x) {
                v.z = 0.0f;
            }
        } else if (0.0f != v.z) {
            v.x = 0.0f;
        }
        if (k != vec_squared_length(&v)) {
            Vec tmp;
            normalize_vector(&v);
            TSceneSora::copy_reflection_vec((u8 *)&v);
            push_matrix();
            push_matrix();
            VecCopy((Vec *)(&tmp), (const Vec *)(&p->pos2FC));
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
    TScene::end_reflection_pass();
    TScene::set_visibility_radius_margin(0.0f);
    if (TSceneSora::instance != 0) {
        TSceneSora::sky_active_flag = 1;
    }
    recon_object->copy_efb_to_texture();
    TSceneSora::set_scene_flag(reinterpret_cast<saddr>(&recon_object->texture_list));
}

void TUnk_804DC7C4::render() {  }
void TUnk_804DC7C4::run_task() {
    TScene::set_id(TObjPlayer::setup_projection_texture);
    TScene::set_active_scene(TObjPlayer::clear_state_if_flag80);
    TScene::set_instance(TObjPlayer__sub_8029EE2C);
}

TUnk_804DC7C4::~TUnk_804DC7C4() {
    scene_sora_reflect_active = 0;
    scene_sora_recon_active_flag = 0;
    lbl_805D65F0 = 0;
    if (indirect_effect != NULL) {
        indirect_effect->queue_destruction();
        indirect_effect = NULL;
    }
    TScene::set_id(0);
    TScene::set_active_scene(0);
    TScene::set_instance(0);
}

TUnk_804DC7C4::TUnk_804DC7C4(TObject *parent) : TObject(parent) {
    scene_sora_reflect_active = 0;
    scene_sora_recon_active_flag = 0;
    if (scene_sora_instance != NULL) {
        return;
    }
    scene_sora_instance = this;
    recon_object = scene_sora_recon_object;
    indirect_effect = new TEffIndirectSampler(0x28, 1, tl_05);
    reflect_pos.x = 0.0f;
    reflect_pos.y = 0.0f;
    reflect_pos.z = 0.0f;
    reflect_normal.x = 0.0f;
    reflect_normal.y = 1.0f;
    reflect_normal.z = 0.0f;
}


s32 TSceneSora::get_state() { return *(s32*)((char*)this + 0x20); }
void TSceneSora::set_scene_flag(int scene_flag) { (*(int *)&lbl_805D65F0) = scene_flag; }
void TSceneSora::copy_reflection_vec(u8 *arg0) {
    VecCopy((Vec *)(&sora_reflection_ray_direction), (const Vec *)(arg0));
}
