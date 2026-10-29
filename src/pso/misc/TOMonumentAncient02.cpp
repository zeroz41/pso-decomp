#include "types.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjMapObject.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TOMonumentAncient02.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"


struct BmlResourceBlock_804B3960 { const char *model_filenames[2]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3960_size[(sizeof(BmlResourceBlock_804B3960) == 0x18) ? 1 : -1];
typedef char BmlResourceBlock_804B3960_descriptor_offset[(offsetof(BmlResourceBlock_804B3960, descriptor) == 0x8) ? 1 : -1];
struct BmlResourceBlock_804B3978 { const char *model_filenames[2]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3978_size[(sizeof(BmlResourceBlock_804B3978) == 0x18) ? 1 : -1];
typedef char BmlResourceBlock_804B3978_descriptor_offset[(offsetof(BmlResourceBlock_804B3978, descriptor) == 0x8) ? 1 : -1];
struct BmlResourceBlock_804B3990 { const char *model_filenames[2]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B3990_size[(sizeof(BmlResourceBlock_804B3990) == 0x18) ? 1 : -1];
typedef char BmlResourceBlock_804B3990_descriptor_offset[(offsetof(BmlResourceBlock_804B3990, descriptor) == 0x8) ? 1 : -1];
extern char lbl_80442330[];
extern char lbl_80442348[];
extern char lbl_80442364[];
extern char lbl_8044237C[];
extern char lbl_80442398[];
extern char lbl_804423B0[];
extern BmlResourceBlock_804B3960 monument_ancient02_resource_table;
extern BmlResourceBlock_804B3978 bm_fs_obj_o_monument02_resource_bundle;
extern BmlResourceBlock_804B3990 bm_fs_obj_o_monument03_resource_bundle;
extern const char *bm_fs_obj_o_monument01_motion_names[1];
extern const char *bm_fs_obj_o_monument02_motion_names[1];
extern const char *bm_fs_obj_o_monument03_motion_names[1];

struct Node_80172AE0 { u8 pad0[4]; s32 f4; f32 x; f32 y; f32 z; u8 pad14[0x2C - 0x14]; Node_80172AE0 *child; };

struct Model_80172AE0 { u8 pad0[4]; s32 f4; u8 mtx[0x2C - 8]; Node_80172AE0 *child; };

extern "C" {
void *create_particle_emitter(void *pos, s32 id);
u32 init_collision_body_parts(void *, s32, s32);
extern CollisionBody monument_ancient02_collision_parts[1];
extern s32 enable_v2_features;
extern s32 TOMonumentAncient02__name;
extern u32 TOMonumentAncient02__model_resource;
extern const f32 lbl_805DB92C;
extern const f32 lbl_805DB934;
extern const f32 lbl_805DB938;
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 rand(void);
int rotate_matrix_y(int, int);
int push_matrix();
int post_translate_matrix(void *);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern u8 chunk_material_color_half_alpha_f32[];
extern const f32 lbl_805DB920;
extern const f32 lbl_805DB924;
extern const f32 lbl_805DB928;
extern const f32 lbl_805DB930;
void TLobby__sub_8001FE7C(void*, int);
void free_collision_body_parts(void *);
s32 submit_cursor_candidate(void *, s32);
}

void TOMonumentAncient02::run_task() {

    switch (this->m_ac) {
    default:
        this->m_ac = 1;
        if ((u32) this->effect != 0U) {
            ((TParticleCtrl *)(this->effect))->enable();
        }
        return;
    case 1:
        if ((TRaderMapCore::is_not_split_screen() != 1) && (this->in_view == 1)) {
            submit_cursor_candidate(this, -1);
        }
        if ((u32) this->effect != 0U) {
            ((TParticleCtrl *)(this->effect))->enable();
            return;
        }
        break;
    case 2:
        play_persistent_sound(this->sound_id, (s32)this, (u32)&this->position, 0, 0);
        break;
    }
}

extern void *tl_05;

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TOMonumentAncient02::render() {
    Model_80172AE0 *m;
    Node_80172AE0 *n;
    in_view = update_object_view_visibility(m_c0, model_radius);
    if (in_view == 1) {
        push_matrix();
        if (m_c8 == 1) {
            scale.x = lbl_805DB920 * (lbl_805DB924 * (f32)rand()) - lbl_805DB928;
            scale.z = lbl_805DB920 * (lbl_805DB924 * (f32)rand()) - lbl_805DB928;
            post_translate_matrix(&scale);
        }
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        TObjFish::set_global_param(texlist);
        m = (Model_80172AE0 *)model;
        post_translate_matrix(m->mtx);
        draw_ginja_model(m->f4);
        if (m_c8 == 1) {
            if (brightening != 0) {
                light_color[0] += lbl_805DB928;
                if (lbl_805DB92C <= light_color[0]) {
                    light_color[0] = lbl_805DB92C;
                    brightening = 0;
                }
            } else {
                light_color[0] -= lbl_805DB928;
                if (light_color[0] <= lbl_805DB930) {
                    light_color[0] = lbl_805DB930;
                    brightening = 1;
                }
            }
            n = m->child;
            push_matrix();
            translate_matrix(0, n->x, n->y, n->z);
            TParticleCtrl::begin_effect_render();
            saved_model_render_flags = model_render_flags;
            model_render_flags = model_render_flags | 0x20;
            set_constant_material((const NJS_ARGB *)&light_color[0]);
            draw_ginja_model(n->f4);
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
            TParticleCtrl::end_effect_render();
            pop_matrix();
        }
        pop_matrix();
    }
}
#pragma pop

void *TOMonumentAncient02::create(void *arg0) {
    return new TOMonumentAncient02((TObject *)tl_05, arg0);
}

void TOMonumentAncient02::free_shared_data() {
    if ((u32) TOMonumentAncient02__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOMonumentAncient02__model_resource, 1);
        TOMonumentAncient02__model_resource = 0U;
    }
}

void TOMonumentAncient02::load_resources() {
    u8 *tbl = (u8 *)&monument_ancient02_resource_table;
    u8 *p;
    switch (get_current_floor_area()) {
    default:
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, tbl + 0x8, 0, 0, 0);
        }
        TOMonumentAncient02__model_resource = (u32)p;
        break;
    case AREA_CAVE2:
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, tbl + 0x20, 0, 0, 0);
        }
        TOMonumentAncient02__model_resource = (u32)p;
        break;
    case AREA_MINE2:
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, tbl + 0x38, 0, 0, 0);
        }
        TOMonumentAncient02__model_resource = (u32)p;
        break;
    }
}

TOMonumentAncient02::~TOMonumentAncient02() {
    TParticleCtrl::release((void *)effect);
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOMonumentAncient02::TOMonumentAncient02(TObject *parent, void *set_data) : TObjMapObject(parent) {
    s32 area;
    m_name = (const char *)TOMonumentAncient02__name;
    apply_object_set_data(set_data);
    model = (void *) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOMonumentAncient02__model_resource) + 0x42C)) + 8);
    texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOMonumentAncient02__model_resource) + 0x42C)) + 0xC);
    init_collision_body_parts(this, (s32) monument_ancient02_collision_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    area = get_current_floor_area();
    switch (area) {
    default:
        m_d0 = 0x2C;
        sound_id = 0x4C119;
        break;
    case AREA_CAVE2:
        m_d0 = 0x2D;
        sound_id = 0x44116;
        break;
    case AREA_MINE2:
        m_d0 = 0x2E;
        sound_id = 0x4004C10F;
        break;
    }
    m_ac = 0;
    m_c8 = 0;
    brightening = 0;
    cursor_action.set_use();
    m_c0 = (f32) lbl_805DB934;
    model_radius = (f32) lbl_805DB938;
    light_color[0] = (f32) lbl_805DB92C;
    light_color[1] = (f32) lbl_805DB92C;
    light_color[2] = (f32) lbl_805DB92C;
    light_color[3] = (f32) lbl_805DB92C;
    effect = (s32)create_particle_emitter(&position, 0x7F);
    in_view = 1;
    if ((s32) enable_v2_features == 1) {
        if (get_game_play_mode() == 1) {
            queue_destruction__7TObjectFv(this);
        }
    }
}

__declspec(section ".data") BmlResourceBlock_804B3960 monument_ancient02_resource_table = { { lbl_80442330, NULL }, { lbl_80442348, monument_ancient02_resource_table.model_filenames, bm_fs_obj_o_monument01_motion_names, 1, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3978 bm_fs_obj_o_monument02_resource_bundle = { { lbl_80442364, NULL }, { lbl_8044237C, bm_fs_obj_o_monument02_resource_bundle.model_filenames, bm_fs_obj_o_monument02_motion_names, 1, 0 } };
__declspec(section ".data") BmlResourceBlock_804B3990 bm_fs_obj_o_monument03_resource_bundle = { { lbl_80442398, NULL }, { lbl_804423B0, bm_fs_obj_o_monument03_resource_bundle.model_filenames, bm_fs_obj_o_monument03_motion_names, 1, 0 } };
CollisionBody monument_ancient02_collision_parts[1] = {
    { { 0.0f, 10.0f, 0.0f }, 20.0f, 0.0f, 0, 0x30003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
__declspec(section ".sdata") const char *bm_fs_obj_o_monument01_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_fs_obj_o_monument02_motion_names[1] = { NULL };
__declspec(section ".sdata") const char *bm_fs_obj_o_monument03_motion_names[1] = { NULL };
