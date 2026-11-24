// Sora (sky) reflection: the reflected-scene task (TFloorReflection), its
// floor-ray helpers and the recon render hooks. One TU: one .sdata2 pool
// in first-use order from the floor ray's 35.0 through push_reflection_matrix's
// 0.0/1.0 to the projection literals, and the task's vtable names functions of
// both ends.
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
#include "pso/render/GinjaDrawUtil.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/scene/TScene.h"
#include "pso/render/FloorReflection.h"
#include "pso/effect/TEffIndirectSampler.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/GinjaRenderTarget.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/CameraCapture.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH

// Defined at the end of the file, where the original places it with the other out-of-line helpers.
static void set_tex_coord_gen(GXTexCoordID dst_coord, GXTexGenType func, GXTexGenSrc src_param, u32 mtx);
#include <stddef.h>
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D8F74.h"

// The texture list of the reflected scene, once render_shadows has copied a frame into it.
NJS_TEXLIST *reflection_texture_list;
TFloorReflection *scene_sora_instance;
u16 scene_sora_reflect_active;
u8 scene_sora_recon_active_flag;
GinjaRenderTarget *scene_sora_recon_object;

// The direction the reflection ray is cast along (straight up until
// set_reflection_ray_direction replaces it).
Vec sora_reflection_ray_direction = {0.0f, 1.0f, 0.0f};

s32 find_reflective_floor(const Vec *pos, ReflectionPlane *plane) {
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
  VecCopy(&probe, pos);
  probe.y += 35.0f;
  hit = csnVecterUnder(&probe, mask);
  if (hit != 0)
  {
    contact = hit->contact;
    if (!(contact->flags & 0x4000))
    {
      return 0;
    }
    if (plane != NULL)
    {
      plane->point.x = contact->point.x;
      plane->point.y = hit->contact->point.y;
      plane->point.z = hit->contact->point.z;
      plane->normal.x = hit->contact->normal.x;
      plane->normal.y = hit->contact->normal.y;
      plane->normal.z = hit->contact->normal.z;
    }
    return 1;
  }
  return 0;
}


s32 push_player_reflection_matrix(u16 client_id, s32 clip) {
    ReflectionPlane plane;
    s32 visible;
    TObjPlayer *player;

    if (is_central_control_area() == 0) {
        return 0;
    }
    if (scene_sora_reflect_active == 0) {
        return 1;
    }
    player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return 0;
    }
    if (find_reflective_floor(&player->body_center, &plane) == 0) {
        return 0;
    }
    if (clip != 0) {
        visible = set_reflection_scissor(&plane.point, 1);
    } else {
        visible = 1;
    }
    if (visible != 0) {
        push_matrix();
        reflect_matrix_in_plane(NULL, &plane);
    }
    return visible;
}

s32 push_reflection_matrix(Vec *point) {
    ReflectionPlane plane;
    s32 visible;
    if (scene_sora_reflect_active == 0) {
        return 1;
    }
    if (point == NULL) {
        return 0;
    }
    plane.point.x = point->x;
    plane.point.y = point->y;
    plane.point.z = point->z;
    plane.normal.x = 0.0f;
    plane.normal.y = 1.0f;
    plane.normal.z = plane.normal.x;
    visible = set_reflection_scissor(point, 1);
    if (visible != 0) {
        push_matrix();
        reflect_matrix_in_plane(NULL, &plane);
    }
    return visible;

}

void restore_render_scissor(s32 reset_scissor) {
    if (scene_sora_reflect_active != 0) {
        pop_matrix();
        if (reset_scissor != 0) {
            GXSetScissor(0, 0, 0x280, 0x1E0);
        }
    }
}

s32 set_reflection_scissor(const Vec *point, s32) {
    Vec v;
    if (scene_sora_reflect_active == 0) {
        return 1;
    }
    restore_render_scissor(1);
    project_world_to_screen(NULL, point, &v.x);
    if (v.y >= 0.0f && v.y <= 480.0f) {
        GXSetScissor(0, (s32)((u32)v.y), 0x280, (s32)((u32)(480.0f - v.y)));
        return 1;
    }
    return 0;
}

void reset_reflection_tev_stages() {
    if (scene_sora_instance != NULL) {
        TEffIndirectSampler *indirect = scene_sora_instance->get_indirect_effect();
        if (indirect != NULL) {
            indirect->disable_indirect_tev();
        }
    }
}

void play_reflection_particles(s16 effect_id) {
    if (scene_sora_instance != NULL) {
        TEffIndirectSampler *indirect = scene_sora_instance->get_indirect_effect();
        if (indirect != NULL) {
            indirect->enable_indirect_tev(0, effect_id);
        }
    }
}

void destroy_reflection_target() {
    scene_sora_instance = NULL;
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
        scene_sora_instance = NULL;
        target = static_cast<GinjaRenderTarget *>(::operator new(sizeof(GinjaRenderTarget)));
        scene_sora_recon_object = target;
        if (target != NULL) {
            target->init_render_target();
            reflection_texture_list = &scene_sora_recon_object->texture_list;
        }
    }
}


extern "C" {
#pragma push
#pragma fp_contract on
s32 reflect_matrix_at_floor(Vec *pos, s32 mask) {
    ReflectionPlane plane;
    Vec a;
    Vec b;
    Vec d;
    TObjPlayer *p;
    CsnHit *r;
    CsnContact *e;
    f32 scale;
    p = get_player_by_client_id(local_client_id);
    if (p == 0) return 0;
    scale = 80.0f;
    if (get_current_floor_area() == AREA_SEABED_UPPER) {
        if ((s16)p->get_room() == 0x5A) {
            scale = 300.0f;
        } else {
            scale = 80.0f;
        }
    }
    VecCopy(&a, pos);
    b.x = scale * sora_reflection_ray_direction.x + a.x;
    b.y = a.y - 35.0f * sora_reflection_ray_direction.y;
    b.z = scale * sora_reflection_ray_direction.z + a.z;
    d.x = b.x - pos->x;
    d.z = b.z - pos->z;
    d.y = b.y - pos->y;
    if (0.0f == vec_squared_length(&d)) {
        plane.point.x = pos->x;
        plane.point.y = pos->y;
        plane.point.z = pos->z;
        plane.normal.x = sora_reflection_ray_direction.x;
        plane.normal.y = sora_reflection_ray_direction.y;
        plane.normal.z = sora_reflection_ray_direction.z;
        reflect_matrix_in_plane(NULL, &plane);
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
        plane.point.x = e->point.x;
        plane.point.y = e->point.y;
        plane.point.z = e->point.z;
        plane.normal.x = e->normal.x;
        plane.normal.y = e->normal.y;
        plane.normal.z = e->normal.z;
        reflect_matrix_in_plane(NULL, &plane);
        return 1;
    }
    return 0;
}
#pragma pop

}

void load_reflection_texture(void) { TObjFish::set_global_param(reflection_texture_list); load_list_texture((saddr)((void*)0), (saddr)((void*)0), (saddr)((void*)0), (saddr)((void*)2)); }


const f64 reflection_angle_to_degrees = 0.0054931640625;

const Vec sora_reflection_up_vec = {0.0f, 1.0f, 0.0f};

void end_projection_texture(s32 flags) {
    if (flags & 0x80) {
        set_ginja_post_tev_stage_count(0);
        set_ginja_post_texgen_count(0);
        set_global_effect_state(0);
        model_render_flags &= 0xFFF7FFFF;
    }
}

void setup_projection_texture(Vec *, SceneSectionAngles *, u32 flags) {
    GinjaMatrix mtx;
    f32 x;
    f32 y;
    f32 fov_y;
    if ((camera_ctrl_instance != NULL) && (reflection_texture_list != NULL)) {
        calc_projection_screen_offset(&x, &y);
        if (flags & 0x80) {
            push_matrix();
            fov_y = (f32) (reflection_angle_to_degrees * calc_camera_vertical_fov());
            if (TCameraCtrl::is_view_offset() != 0) {
                C_MTXLightPerspective(mtx, fov_y, 1.1333334f, 0.5f, -0.5f, (f32) (0.5f - x), (f32) (0.5f - y));
            } else {
                C_MTXLightPerspective(mtx, fov_y, 1.1333334f, 0.5f, -0.5f, 0.5f, 0.5f);
            }
            PSMTXConcat(mtx, *current_matrix, *current_matrix);
            load_current_tex_matrix(2);
            pop_matrix();
            load_current_pos_matrix(2);
            GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP2, GX_COLOR0A0);
            GXSetTevOp(GX_TEVSTAGE1, GX_BLEND);
            set_tex_coord_gen(GX_TEXCOORD1, GX_TG_MTX3x4, GX_TG_POS, GX_TEXMTX2);
            model_render_flags |= 0x80000;
            set_ginja_post_tev_stage_count(1);
            set_ginja_post_texgen_count(1);
            set_global_effect_state(1);
        }
    }
}

void TFloorReflection::render_shadows() {
    ReflectionPlane c3;
    ReflectionPlane c2;
    ReflectionPlane c1;
    s32 r = 0;
    Vec v = sora_reflection_up_vec;
    s32 hit;
    s32 i;
    f32 k;
    f32 len;
    TObjPlayer *p;
    if (camera_ctrl_instance == 0 || recon_object == 0) {
        return;
    }
    p = get_player_by_client_id(local_client_id);
    if (p == NULL) {
        return;
    }
    TScene::begin_reflection_pass();
    TScene::set_visibility_radius_margin(100.0f);
    if (TSceneSora::instance != 0) {
        TSceneSora::sky_active_flag = 0;
    }
    set_reflection_ray_direction(&v);
    scene_sora_reflect_active = 1;
    {
        Vec off = p->body_center;
        off.y += 10.0f;
        hit = find_reflective_floor(&off, &reflect_plane);
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
                    c3.point.x = p->position.x;
                    c3.point.y = p->position.y;
                    c3.point.z = p->position.z;
                    c3.normal.x = 0.0f;
                    c3.normal.y = 1.0f;
                    c3.normal.z = c3.normal.x;
                    push_matrix();
                    reflect_matrix_in_plane(NULL, &c3);
                    ((TMainTask *)((u8 *)&main_task))->render_object_layers(3);
                    pop_matrix();
                }
            }
        } else if (p != NULL) {
            ((TMainTask *)((u8 *)&main_task))->render_object_layers(1);
            c2.point.x = reflect_plane.point.x;
            c2.point.y = reflect_plane.point.y;
            c2.point.z = reflect_plane.point.z;
            c2.normal.x = 0.0f;
            c2.normal.y = 1.0f;
            c2.normal.z = c2.normal.x;
            push_matrix();
            reflect_matrix_in_plane(NULL, &c2);
            ((TMainTask *)((u8 *)&main_task))->render_object_layers(4);
            pop_matrix();
        }
    }
    ((TMainTask *)((u8 *)&main_task))->render_task_layer_02();
    if (p != NULL) {
        c1.point.x = reflect_plane.point.x;
        c1.point.y = reflect_plane.point.y;
        c1.point.z = reflect_plane.point.z;
        c1.normal.x = 0.0f;
        c1.normal.y = 1.0f;
        c1.normal.z = c1.normal.x;
        push_matrix();
        reflect_matrix_in_plane(NULL, &c1);
        ((TMainTask *)((u8 *)&main_task))->render_object_layers(5);
        pop_matrix();
    }
    k = 0.0f;
    scene_sora_reflect_active = 0;
    for (i = 0; i < 2; i++) {
        v.x = p->position.x - camera_ctrl_instance->pos.x;
        v.y = k;
        v.z = p->position.z - camera_ctrl_instance->pos.z;
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
            set_reflection_ray_direction(&v);
            push_matrix();
            push_matrix();
            VecCopy(&tmp, &p->body_center);
            r = reflect_matrix_at_floor(&tmp, 0x4000);
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
    set_reflection_texture_list(&recon_object->texture_list);
}

void TFloorReflection::render() {  }
void TFloorReflection::run_task() {
    TScene::set_id(setup_projection_texture);
    TScene::set_active_scene(end_projection_texture);
    TScene::set_instance(load_reflection_texture);
}

TFloorReflection::~TFloorReflection() {
    scene_sora_reflect_active = 0;
    scene_sora_recon_active_flag = 0;
    reflection_texture_list = NULL;
    if (indirect_effect != NULL) {
        indirect_effect->queue_destruction();
        indirect_effect = NULL;
    }
    TScene::set_id(0);
    TScene::set_active_scene(0);
    TScene::set_instance(0);
}

TFloorReflection::TFloorReflection(TObject *parent) : TObject(parent) {
    scene_sora_reflect_active = 0;
    scene_sora_recon_active_flag = 0;
    if (scene_sora_instance != NULL) {
        return;
    }
    scene_sora_instance = this;
    recon_object = scene_sora_recon_object;
    indirect_effect = new TEffIndirectSampler(0x28, 1, tl_05);
    reflect_plane.point.x = 0.0f;
    reflect_plane.point.y = 0.0f;
    reflect_plane.point.z = 0.0f;
    reflect_plane.normal.x = 0.0f;
    reflect_plane.normal.y = 1.0f;
    reflect_plane.normal.z = 0.0f;
}


TEffIndirectSampler *TFloorReflection::get_indirect_effect() { return indirect_effect; }
void set_reflection_texture_list(NJS_TEXLIST *texture_list) { reflection_texture_list = texture_list; }
void set_reflection_ray_direction(const Vec *direction) {
    VecCopy(&sora_reflection_ray_direction, direction);
}

// The SDK's GXSetTexCoordGen out of line: no normalisation, identity post-transform.
static void set_tex_coord_gen(GXTexCoordID dst_coord, GXTexGenType func, GXTexGenSrc src_param, u32 mtx) {
    GXSetTexCoordGen2(dst_coord, func, src_param, mtx, GX_FALSE, GX_PTIDENTITY);
}

inline void TScene::end_reflection_pass() { reflection_pass_active = 0; }

inline void TScene::set_visibility_radius_margin(f32 margin) { visibility_radius_margin = margin; }

inline void TScene::begin_reflection_pass() { reflection_pass_active = 1; }

// Copies the 640x480 frame into the render target's texture as RGB565 and clears it.
inline void GinjaRenderTarget::copy_efb_to_texture() {
    GXColor clear_color = {0, 0, 0, 0};
    GXSetZMode(GX_FALSE, GX_ALWAYS, GX_TRUE);
    GXSetCopyClear(clear_color, 0xFFFFFF);
    GXSetTexCopySrc(0, 0, 640, 480);
    GXSetTexCopyDst(640, 480, GX_TF_RGB565, GX_FALSE);
    GXCopyTex(texture_list.textures->texture->surface->header.pixels, GX_TRUE);
    GXPixModeSync();
}
