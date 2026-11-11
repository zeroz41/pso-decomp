#include "types.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/TCMCharacter.h"
#include "pso/ui/charcreate/CharacterShape.h"
#include "pso/ui/charcreate/CharacterCreationTextureCache.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"

struct W_80290250 { u8 pad[0xfc]; s32 bufp; s32 rc; u8 data[4]; };


struct Opaque_80290088;

extern const f32 lbl_805DD944;
extern const f32 lbl_805DD948;
extern const f32 lbl_805DD94C;
extern const f32 lbl_805DD950;
extern const f32 lbl_805DD954;
s32 find_shape_triangle_region(u8 *arg0);
TChCrLoadAfsTextureReq *create_ch_cr_load_afs_texture_req(void *figure, void *list, void *slot, void *index);
extern "C" {
void calc_shape_region_coefficients(f32 *point);
s32 blend_shape_chunk_vertices(void);
f32 vector_length(f32 *v);
s32 normalize_vector(f32 *v);
}
// Ninja chunk model (NJS_CNK_MODEL): vertex chunk list, polygon chunk list, bounds.
struct CreationShapeModel { s32 *vertex_list; s16 *polygon_list; f32 center[3]; };
struct CreationShapeNode { u32 eval_flags; CreationShapeModel *model; f32 pos[3]; s32 ang[3]; f32 scl[3]; };
extern "C" {
void TAdSinglePlyChrSelectGC__sub_802905A4(void* p, void* q);
}
void reset_creation_shape_set(s32 arg0);
extern void ***char_creation_data_block;
void reset_creation_body_shapes();
void reset_creation_head_shapes();
#pragma common off
CreationHeadModelStates creation_head_shape_destination;
CreationHeadModelStates creation_head_shape_samples[7];
CreationBodyModelStates creation_body_shape_destination;
CreationBodyModelStates creation_body_shape_samples[7];
CreationShapeBlend creation_shape_blend;
CreationTextureCacheEntry creation_texture_cache[CREATION_TEXTURE_CACHE_CAPACITY];
CreationModelPart creation_hair_model_parts[10];
CreationModelPart creation_cap_model_parts[10];
CreationModelPart creation_head_model_parts[5];
__declspec(section ".data") u32 creation_models_ready;
#pragma common reset
extern "C" {
s32 is_entry_equal__23TAdSinglePlyChrSelectGCFPvPv(void *, void *);
s32 creation_motion_group(CharacterAppearanceFields *);
void load_creation_shape_rel(W_80290250 *arg0);
void TCharaMaking__sub_8028E3A0();
void TAdSinglePlyChrSelectGC__sub_80290884(void* p, void* q);
s32 count_char_diffs__23TAdSinglePlyChrSelectGCFPvPv(void *, void *);
extern CreationTextureCacheEntry *char_select_current_entry;
void TAdSinglePlyChrSelectGC__sub_8028ED54(void);
void blend_creation_proportion_shapes(f32 *);
s32 free_bin_model_request(void *, int);
void *__dt__10TObjMotionFv(void *arg0, s16 arg1);
void mem_free(void *p);
s32 __dl__7TObjectFPv(void *);
void TAdSinglePlyChrSelectGC__sub_8028F084(CreationTextureCacheEntry *entry, TCharaMaking *appearance);
void TCharaMaking__bind_appearance_texture_lists(s32 *hair, s32 *head, s32 *body, TCharaMaking *appearance);
void copy_slot_data__23TAdSinglePlyChrSelectGCFPvPv(void *dst, void *src);
extern s32 lbl_805D49B4;
extern int char_creation_figure_draw_flag;
s32 creation_resource_ready_state;
u8 *TAdSinglePlyChrSelectGC__sub_802908CC(u8 *arg0, s16 arg1);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);
void rotate_matrix_y(int, u32);
void push_matrix_from();
void push_matrix();
s32 pop_matrix(void);
int fn_8001ED90(void *p);
void update_pair__23TAdSinglePlyChrSelectGCFPv(void* p);
int TAdSinglePlyChrSelectGC__sub_802905B8(void);
void close_if_active__23TAdSinglePlyChrSelectGCFv(u8 * _w0);
s32 release_texture_list(void *);
int set_motion_interpolation_flag__10TObjMotionFv(void*);
int draw_saving_joints_checked__10TObjMotionFv(void*);

extern "C" {
void run_task__12TCMCharacterFv();
}
extern "C" {
void vfunc_6__8TObjBaseFPsl();
}
extern "C" {
void interact__14TObjCollidableFl();
}
extern "C" {
void get_name__8TObjBaseFv();
}
extern "C" {
void get_center__8TObjBaseFv();
}
extern "C" {
void apply_object_set_data__8TObjBaseFPv();
}
extern "C" {
void classify_actor_view_detail__8TObjBaseFfff();
}
extern "C" {
void render_shadows__7TObjectFv();
}
extern "C" {
void reset_motion_fields__10TObjMotionFv();
}
extern "C" {
void update_object_view_visibility__8TObjBaseFff();
}
#pragma push
#pragma readonly_strings on
// empty motion name lists of the character-making BmlResourceDescriptors (inferred)
const char *lbl_805D3B70[1] = {NULL};
const char *lbl_805D3B74[1] = {NULL};
const char *lbl_805D3B78[1] = {NULL};
const char *lbl_805D3B7C[1] = {NULL};
const char *lbl_805D3B80[1] = {NULL};
const char *lbl_805D3B84[1] = {NULL};
const char *lbl_805D3B88[1] = {NULL};
const char *lbl_805D3B8C[1] = {NULL};
const char *lbl_805D3B90[1] = {NULL};
const char *lbl_805D3B94[1] = {NULL};
const char *lbl_805D3B98[1] = {NULL};
const char *lbl_805D3B9C[1] = {NULL};
const char *lbl_805D3BA0[1] = {NULL};
const char *lbl_805D3BA4[1] = {NULL};
const char *lbl_805D3BA8[1] = {NULL};
const char *lbl_805D3BAC[1] = {NULL};
const char *lbl_805D3BB0[1] = {NULL};
const char *lbl_805D3BB4[1] = {NULL};
const char *lbl_805D3BB8[1] = {NULL};
const char *lbl_804D3A08[14] = {
    "plAbdy00.nj", "plAcap06.nj", "plAhai00.nj", "plAhai01.nj",
    "plAhai02.nj", "plAhai03.nj", "plAhai04.nj", "plAhai05.nj",
    "plAhai06.nj", "plAhai07.nj", "plAhai08.nj", "plAhai09.nj",
    "plAhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3A40 = {"planj.bml", lbl_804D3A08, lbl_805D3B70, 13, 0};
const char *lbl_804D3A50[13] = {
    "plBbdy00.nj", "plBhai00.nj", "plBhai01.nj", "plBhai02.nj",
    "plBhai03.nj", "plBhai04.nj", "plBhai05.nj", "plBhai06.nj",
    "plBhai07.nj", "plBhai08.nj", "plBhai09.nj", "plBhed00.nj",
    NULL,
};
BmlResourceDescriptor lbl_804D3A84 = {"plbnj.bml", lbl_804D3A50, lbl_805D3B74, 12, 0};
const char *lbl_804D3A94[7] = {
    "plCbdy00.nj", "plChed00.nj", "plChed01.nj", "plChed02.nj",
    "plChed03.nj", "plChed04.nj", NULL,
};
BmlResourceDescriptor lbl_804D3AB0 = {"plcnj.bml", lbl_804D3A94, lbl_805D3B78, 6, 0};
const char *lbl_804D3AC0[23] = {
    "plDbdy00.nj", "plDcap00.nj", "plDcap01.nj", "plDcap02.nj",
    "plDcap03.nj", "plDcap04.nj", "plDcap05.nj", "plDcap06.nj",
    "plDcap07.nj", "plDcap08.nj", "plDcap09.nj", "plDhai00.nj",
    "plDhai01.nj", "plDhai02.nj", "plDhai03.nj", "plDhai04.nj",
    "plDhai05.nj", "plDhai06.nj", "plDhai07.nj", "plDhai08.nj",
    "plDhai09.nj", "plDhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3B1C = {"pldnj.bml", lbl_804D3AC0, lbl_805D3B7C, 22, 0};
const char *lbl_804D3B2C[7] = {
    "plEbdy00.nj", "plEhed00.nj", "plEhed01.nj", "plEhed02.nj",
    "plEhed03.nj", "plEhed04.nj", NULL,
};
BmlResourceDescriptor lbl_804D3B48 = {"plenj.bml", lbl_804D3B2C, lbl_805D3B80, 6, 0};
const char *lbl_804D3B58[7] = {
    "plFbdy00.nj", "plFhed00.nj", "plFhed01.nj", "plFhed02.nj",
    "plFhed03.nj", "plFhed04.nj", NULL,
};
BmlResourceDescriptor lbl_804D3B74 = {"plfnj.bml", lbl_804D3B58, lbl_805D3B84, 6, 0};
const char *lbl_804D3B84[23] = {
    "plGbdy00.nj", "plGcap00.nj", "plGcap01.nj", "plGcap02.nj",
    "plGcap03.nj", "plGcap04.nj", "plGcap05.nj", "plGcap06.nj",
    "plGcap07.nj", "plGcap08.nj", "plGcap09.nj", "plGhai00.nj",
    "plGhai01.nj", "plGhai02.nj", "plGhai03.nj", "plGhai04.nj",
    "plGhai05.nj", "plGhai06.nj", "plGhai07.nj", "plGhai08.nj",
    "plGhai09.nj", "plGhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3BE0 = {"plgnj.bml", lbl_804D3B84, lbl_805D3B88, 22, 0};
const char *lbl_804D3BF0[23] = {
    "plHbdy00.nj", "plHcap00.nj", "plHcap01.nj", "plHcap02.nj",
    "plHcap03.nj", "plHcap04.nj", "plHcap05.nj", "plHcap06.nj",
    "plHcap07.nj", "plHcap08.nj", "plHcap09.nj", "plHhai00.nj",
    "plHhai01.nj", "plHhai02.nj", "plHhai03.nj", "plHhai04.nj",
    "plHhai05.nj", "plHhai06.nj", "plHhai07.nj", "plHhai08.nj",
    "plHhai09.nj", "plHhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3C4C = {"plhnj.bml", lbl_804D3BF0, lbl_805D3B8C, 22, 0};
const char *lbl_804D3C5C[23] = {
    "plIbdy00.nj", "plIcap00.nj", "plIcap01.nj", "plIcap02.nj",
    "plIcap03.nj", "plIcap04.nj", "plIcap05.nj", "plIcap06.nj",
    "plIcap07.nj", "plIcap08.nj", "plIcap09.nj", "plIhai00.nj",
    "plIhai01.nj", "plIhai02.nj", "plIhai03.nj", "plIhai04.nj",
    "plIhai05.nj", "plIhai06.nj", "plIhai07.nj", "plIhai08.nj",
    "plIhai09.nj", "plIhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3CB8 = {"plinj.bml", lbl_804D3C5C, lbl_805D3B90, 22, 0};
const char *lbl_804D3CC8[7] = {
    "plJbdy00.nj", "plJhed00.nj", "plJhed01.nj", "plJhed02.nj",
    "plJhed03.nj", "plJhed04.nj", NULL,
};
BmlResourceDescriptor lbl_804D3CE4 = {"pljnj.bml", lbl_804D3CC8, lbl_805D3B94, 6, 0};
const char *lbl_804D3CF4[23] = {
    "plKbdy00.nj", "plKcap00.nj", "plKcap01.nj", "plKcap02.nj",
    "plKcap03.nj", "plKcap04.nj", "plKcap05.nj", "plKcap06.nj",
    "plKcap07.nj", "plKcap08.nj", "plKcap09.nj", "plKhai00.nj",
    "plKhai01.nj", "plKhai02.nj", "plKhai03.nj", "plKhai04.nj",
    "plKhai05.nj", "plKhai06.nj", "plKhai07.nj", "plKhai08.nj",
    "plKhai09.nj", "plKhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3D50 = {"plknj.bml", lbl_804D3CF4, lbl_805D3B98, 22, 0};
const char *lbl_804D3D60[23] = {
    "plLbdy00.nj", "plLcap00.nj", "plLcap01.nj", "plLcap02.nj",
    "plLcap03.nj", "plLcap04.nj", "plLcap05.nj", "plLcap06.nj",
    "plLcap07.nj", "plLcap08.nj", "plLcap09.nj", "plLhai00.nj",
    "plLhai01.nj", "plLhai02.nj", "plLhai03.nj", "plLhai04.nj",
    "plLhai05.nj", "plLhai06.nj", "plLhai07.nj", "plLhai08.nj",
    "plLhai09.nj", "plLhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3DBC = {"pllnj.bml", lbl_804D3D60, lbl_805D3B9C, 22, 0};
const char *lbl_804D3DCC[4] = {
    "plSbdy00.nj", "plShai00.nj", "plShed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3DDC = {"plsnj.bml", lbl_804D3DCC, lbl_805D3BA0, 3, 0};
const char *lbl_804D3DEC[4] = {
    "plTbdy00.nj", "plThai00.nj", "plThed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3DFC = {"pltnj.bml", lbl_804D3DEC, lbl_805D3BA4, 3, 0};
const char *lbl_804D3E0C[3] = {
    "plUbdy00.nj", "plUhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3E18 = {"plunj.bml", lbl_804D3E0C, lbl_805D3BA8, 2, 0};
const char *lbl_804D3E28[3] = {
    "plVbdy00.nj", "plVhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3E34 = {"plvnj.bml", lbl_804D3E28, lbl_805D3BAC, 2, 0};
const char *lbl_804D3E44[3] = {
    "plWbdy00.nj", "plWhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3E50 = {"plwnj.bml", lbl_804D3E44, lbl_805D3BB0, 2, 0};
const char *lbl_804D3E60[3] = {
    "plXbdy00.nj", "plXhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3E6C = {"plxnj.bml", lbl_804D3E60, lbl_805D3BB4, 2, 0};
const char *lbl_804D3E7C[3] = {
    "plYbdy00.nj", "plYhed00.nj", NULL,
};
BmlResourceDescriptor lbl_804D3E88 = {"plynj.bml", lbl_804D3E7C, lbl_805D3BB8, 2, 0};
BmlResourceDescriptor *character_making_resource_descriptor_table[19] = {
    &lbl_804D3A40, &lbl_804D3A84, &lbl_804D3AB0, &lbl_804D3B1C,
    &lbl_804D3B48, &lbl_804D3B74, &lbl_804D3BE0, &lbl_804D3C4C,
    &lbl_804D3CB8, &lbl_804D3CE4, &lbl_804D3D50, &lbl_804D3DBC,
    &lbl_804D3DDC, &lbl_804D3DFC, &lbl_804D3E18, &lbl_804D3E34,
    &lbl_804D3E50, &lbl_804D3E6C, &lbl_804D3E88,
};
void *character_making_action_table[36] = {
    (void *)0x10000, (void *)0x21, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x1, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x1f, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x20, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x1e, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x2f, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x30, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x2e, (void *)0x3f800000, (void *)0x0,
};
// TCMCharacter class-name pointer, stored as the object name by TCMCharacter__ct (inferred)
const char *TCMCharacter__name = "TCMCharacter";
// empty model part copied into every slot by init_entry_tables (inferred)
__declspec(section ".rodata") CreationModelPart lbl_80451CD0 = {0, 0};
#pragma pop
__declspec(section ".data") CreationModelNodeState creation_empty_model_node = {0,0};

struct Sel_802902CC {
    u8 pad0[4];
    s32 a4;
    s32 a8;
    s32 c[3];
    s32 d[3];
    s32 e[3];
};

s32 load_resource_from_descriptor(s32, s32, s32, s32, s32, s32);
s32 __ct__10TObjMotionFP7TObject(void *, void *);
void *mem_alloc(u32 size);
}
extern u32 creation_figure_object;
void request_creation_motion(s32 arg0);
extern s32 chara_select_creation_shape_rel_files[];
extern u32 creation_figure_rotation_y;
void map_shape_region_samples(s32 region, s32 *samples);
extern CreationShapeBlend creation_shape_blend;
s32 clear_creation_shape_eval_masks(f32 *dst, const f32 *a, const f32 *b, const f32 *c);
s32 scan_creation_resources(void *arg0);
u32 relocate_data_block_pointers(u32 arg0, u32 arg1);
extern s32 char_select_active_flag;
void reset_character_creation_figure_rotation(void);
extern void *creation_menu_main_obj;
extern const f32 lbl_805DD940;
extern "C" {

void TCharaMaking__bind_head_shape_nodes(CharacterAppearanceFields *appearance, void *model);
void TCharaMaking__bind_body_shape_nodes(CharacterAppearanceFields *appearance, void *model);
void *TCMCharacter__ct(void *arg0, void *arg1);
extern s32 creation_region_sample_index_table[24]; extern CreationShapePoint lbl_804D400C[9]; extern void* lbl_804D4054[21];
#define lbl_804D4054 ((s32 *)lbl_804D4054)
#pragma defer_codegen on
}

extern "C" {
void *TCMCharacter__ct(void *motion, void *arg1) {
    CreationTextureCacheEntry *p;
    s32 res;
    CharacterAppearanceFields *cm;

    __ct__10TObjMotionFP7TObject(motion, arg1);
    *(void **)((s8 *)motion + 0x18) = (void *)lbl_804D4054;
    *(const char **)((s8 *)motion + 0) = TCMCharacter__name;
    lbl_805D49B4 = 1;
    cm = creation_player_character;
    char_select_active_flag = 0;
    char_creation_figure_draw_flag = 0;
    creation_figure_object = (u32)motion;
    res = (s32)(int)::operator new(0x440);
    if (res != 0) {
        res = load_resource_from_descriptor(res, 6, ((s32 *)character_making_resource_descriptor_table)[((TCharaMaking *)cm)->get_display_index()], 0, 0, 0);
    }
    chara_select_preview_resource = res;
    for (p = ((CreationTextureCacheEntry *)creation_texture_cache); p < ((CreationTextureCacheEntry *)creation_texture_cache) + 0x80; p++) {
        p->in_use = 0;
        p->hair_textures.present = 0;
        p->head_textures.present = 0;
        p->body_textures.present = 0;
        p->hair_textures.complete = 0;
        p->head_textures.complete = 0;
        p->body_textures.complete = 0;
    }
    char_select_current_entry = 0;
    ((void (*)(int))TAdSinglePlyChrSelectGC__sub_8028ED54)(0);
    char_select_current_entry = 0;
    ((TObjMotion *)motion)->set_field_d8((s32)((void *)character_making_action_table));
    ((TObjMotion *)motion)->set_field_dc(*(s32 *)((s8 *)creation_menu_main_obj + 0x430));
    ((TObjMotion *)motion)->requested_action = creation_motion_group(creation_player_character);
    ((TObjMotion *)motion)->set_animation(((TObjMotion *)motion)->requested_action);
    *(s32 *)((s8 *)motion + 0xE0) = (s32)mem_alloc(0xC00);
    *(f32 *)((s8 *)motion + 0x40) = lbl_805DD940;
    *(f32 *)((s8 *)motion + 0x3C) = lbl_805DD940;
    *(f32 *)((s8 *)motion + 0x38) = lbl_805DD940;
    ((TObjMotion *)motion)->rotation_z = 0;
    ((TObjMotion *)motion)->rotation_y = 0;
    *(s32 *)((s8 *)motion + 0x5C) = 0;
    load_creation_shape_rel((W_80290250 *)motion);
    reset_character_creation_figure_rotation();
    creation_resource_ready_state = 0;
    return motion;
}
u8 *TAdSinglePlyChrSelectGC__sub_802908CC(u8 *arg0, s16 arg1) {
    CreationTextureCacheEntry *p;
    CreationTextureCacheEntry *end;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804D4054;
        for (p = creation_texture_cache, end = creation_texture_cache + 128; p < end; p++) {
            if (p->in_use != 0) {
                ((TAdSinglePlyChrSelectGC *)p)->update_char_panels();
            }
        }
        ((TAdSinglePlyChrSelectGC *)arg0)->free_field_FC();
        free_bin_model_request((void *)chara_select_preview_resource, 1);
        chara_select_preview_resource = 0;
        ((TCMCharacter *)arg0)->reset_model_parts();
        (*(s32 *)&chara_select_head_node) = 0;
        (*(s32 *)&chara_select_hair_node_b) = 0;
        (*(s32 *)&chara_select_hair_node_a) = 0;
        ((TAdSinglePlyChrSelectGC *)arg0)->m_34 = 0;
        mem_free((void *)(*(s32 *)((s8 *)arg0 + 0xE0)));
        creation_resource_ready_state = 0;
        creation_figure_object = 0;
        lbl_805D49B4 = 0;
        char_creation_figure_draw_flag = 0;
        __dt__10TObjMotionFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
void update_pair__23TAdSinglePlyChrSelectGCFPv(void* p) { TAdSinglePlyChrSelectGC::init_entry_tables(p); ((TCMCharacter *)p)->load_model_parts(); }
void TAdSinglePlyChrSelectGC__sub_80290884(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }
void TAdSinglePlyChrSelectGC::init_entry_tables(void* _w0) {
    for (s32 i = 0; i < 10; i++) {
        TAdSinglePlyChrSelectGC__sub_80290884(&creation_hair_model_parts[i], &lbl_80451CD0);
        TAdSinglePlyChrSelectGC__sub_80290884(&creation_cap_model_parts[i], &lbl_80451CD0);
    }
    for (s32 i = 0; i < 5; i++) {
        TAdSinglePlyChrSelectGC__sub_80290884(&creation_head_model_parts[i], &lbl_80451CD0);
    }
}
void TCMCharacter::load_model_parts() {
    TCharaMaking *appearance = (TCharaMaking *)creation_player_character;
    CharacterClassAppearance *entry = &class_appearance_table[((TCharaMaking *)creation_player_character)->get_display_index()];
    creation_models_ready = 1;
    model = (void *)get_bml_model((BmlResource *)chara_select_preview_resource, 0);
    s32 next = bind_model_parts(&chara_select_hair_node_b, entry->capModels, creation_cap_model_parts, 4, 1);
    next = bind_model_parts(&chara_select_hair_node_a, entry->hairModels, creation_hair_model_parts, 4, next);
    bind_model_parts(&chara_select_head_node, entry->headModels, creation_head_model_parts, 3, next);
    appearance->get_display_index();
}

s32 TCMCharacter::bind_model_parts(u32 *selected, const char **names, CreationModelPart *parts,
                                 s32 part, s32 model_index) {
    *selected = 0;
    if (names == NULL) {
        return model_index;
    }
    CharacterAppearanceFields *appearance = (CharacterAppearanceFields *)creation_player_character;
    s32 count = class_appearance_table[((TCharaMaking *)creation_player_character)->get_display_index()].counts[part];
    if (count == 0) {
        count = 1;
    }
    s32 i = 0;
    while (i < count) {
        if (*names == NULL) {
            parts->present = 0;
            parts->model = 0;
        } else {
            parts->present = 1;
            parts->model = get_bml_model((BmlResource *)chara_select_preview_resource, model_index++);
        }
        i++;
        names++;
        parts++;
    }
    chara_select_head_node = parts[(&appearance->costume)[part]].model;
    return model_index;
}

void TCMCharacter::reset_model_parts() {
    for (s32 i = 0; i < 10; i++) {
        creation_hair_model_parts[i].present = creation_cap_model_parts[i].present = 0;
    }
    for (s32 i = 0; i < 5; i++) {
        creation_head_model_parts[i].present = 0;
    }
    creation_models_ready = 0;
}
u8 TAdSinglePlyChrSelectGC::is_active() {
    return (u8) (char_select_active_flag == 1);
}
int TAdSinglePlyChrSelectGC__sub_802905B8(void) {  return char_creation_figure_draw_flag; }
void TAdSinglePlyChrSelectGC__sub_802905A4(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }
}
void reset_creation_shape_set(s32 arg0) {
    TAdSinglePlyChrSelectGC__sub_802905A4((void*)arg0, (void*)((void *)&creation_empty_model_node));
}
#pragma push
#pragma fp_contract on
#pragma opt_common_subs on
#pragma scheduling on
void reset_creation_head_shapes() {
  CreationModelNodeState *p = creation_head_shape_destination.nodes;
  s32 i = 0;
  do
  {
    reset_creation_shape_set((s32)p);
    ++i;
    ++p;
  }
  while (i < 5);
  s32 group = 0;
  do
  {
    CreationModelNodeState *q = creation_head_shape_samples[group].nodes;
    s32 j = 0;
    do
    {
      reset_creation_shape_set((s32)q);
      ++j;
      ++q;
    }
    while (j < 5);
    ++group;
  }
  while (group < 7);
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs on
#pragma scheduling on
void reset_creation_body_shapes() {
  CreationModelNodeState *p = creation_body_shape_destination.nodes;
  s32 i = 0;
  do
  {
    reset_creation_shape_set((s32)p);
    ++i;
    ++p;
  }
  while (i < 65);
  s32 group = 0;
  do
  {
    CreationModelNodeState *q = creation_body_shape_samples[group].nodes;
    s32 j = 0;
    do
    {
      reset_creation_shape_set((s32)q);
      ++j;
      ++q;
    }
    while (j < 65);
    ++group;
  }
  while (group < 7);
}
#pragma pop

void TCharaMaking__bind_body_shape_nodes(CharacterAppearanceFields *appearance, void *model) {
    reset_creation_body_shapes();
    make_node_flag_table((NJS_OBJECT *)model, (NodeFlagEntry *)&creation_body_shape_destination);
    for (s32 i = 0; i < 7; ++i) {
        make_node_flag_table((NJS_OBJECT *)char_creation_data_block[0][i], (NodeFlagEntry *)&creation_body_shape_samples[i]);
    }
}
void TCharaMaking__bind_head_shape_nodes(CharacterAppearanceFields *appearance, void *model) {
    reset_creation_head_shapes();
    make_node_flag_table((NJS_OBJECT *)model, (NodeFlagEntry *)&creation_head_shape_destination);
    s32 head = appearance->head + 1;
    for (s32 i = 0; i < 7; ++i) {
        make_node_flag_table((NJS_OBJECT *)char_creation_data_block[head][i], (NodeFlagEntry *)&creation_head_shape_samples[i]);
    }
}
void TAdSinglePlyChrSelectGC::reset_creation_parts() {
    Sel_802902CC *arg0 = (Sel_802902CC *)this;
    s32 i;
    reset_creation_head_shapes();
    reset_creation_body_shapes();
    make_node_flag_table((NJS_OBJECT *)((void *)arg0->a4), (NodeFlagEntry *)((void *)&creation_head_shape_destination));
    make_node_flag_table((NJS_OBJECT *)((void *)arg0->a8), (NodeFlagEntry *)((void *)&creation_body_shape_destination));
    for (i = 0; i < 3; i++) {
        s32 t = arg0->c[i];
        make_node_flag_table((NJS_OBJECT *)((void *)arg0->d[i]), (NodeFlagEntry *)((u8 *)creation_head_shape_samples + t * 0x28));
        make_node_flag_table((NJS_OBJECT *)((void *)arg0->e[i]), (NodeFlagEntry *)((u8 *)creation_body_shape_samples + t * 0x208));
    }
}
void load_creation_shape_rel(W_80290250 *arg0) {
    s32 rc;
    arg0->bufp = (s32)TQuestVmDownLoadServer::alloc(0x44000);
    rc = TLobby::request_file_read((s32)(chara_select_creation_shape_rel_files[((TCharaMaking *)(*(void * *)&creation_player_character))->get_display_index()]), (s32)arg0->bufp, (s32 *)arg0->data, (void **)0);
    arg0->rc = rc;
    if (rc >= 0) {
        if (arg0->rc > 0x44000) {
            return;
        }
    }
}
void TAdSinglePlyChrSelectGC::free_field_FC() {
    TAdSinglePlyChrSelectGC::safe_free(*(s32 *)((s8 *)this + 0xFC));
    *(s32 *)((s8 *)this + 0xFC) = 0;
}

void TCMCharacter::run_task() {
    static void (TCMCharacter::*modes[2])() = {
        &TCMCharacter::apply_character_appearance, &TCMCharacter::update_chara_preview,
    };
    (this->*modes[char_select_active_flag])();
}

#undef lbl_804D4054

// The three shape samples (corners in lbl_804D400C) of each proportion region.
s32 creation_region_sample_index_table[24] = {
    1, 3, 0,
    0, 4, 3,
    3, 5, 4,
    1, 3, 2,
    2, 6, 3,
    3, 5, 6,
    2, 6, 7,
    8, 7, 2,
};
// The (width, height) corner of each shape sample in the proportion plane.
CreationShapePoint lbl_804D400C[9] = {
    {0.0f, 0.0f}, {1.0f / 3.0f, 0.0f}, {2.0f / 3.0f, 0.0f}, {1.0f / 3.0f, 0.5f}, {0.0f, 1.0f},
    {1.0f / 3.0f, 1.0f}, {2.0f / 3.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f},
};
void *lbl_804D4054[21] = {
    (void *)0x0, (void *)0x0, (void *)&TAdSinglePlyChrSelectGC__sub_802908CC, (void *)&run_task__12TCMCharacterFv,
    (void *)&close_if_active__23TAdSinglePlyChrSelectGCFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__10TObjMotionFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFl, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};

#define lbl_804D4054 ((s32 *)lbl_804D4054)

void TCMCharacter::apply_character_appearance() {
    struct Opaque_80290088 *app;
    CharacterAppearanceFields *raw;
    s32 hair;
    s32 head;
    if (fn_8001ED90((void *)chara_select_preview_resource) == 0 || this->shape_rel_ready == 0) {
        return;
    }
    update_pair__23TAdSinglePlyChrSelectGCFPv(this);
    raw = (CharacterAppearanceFields *)creation_player_character;
    app = (struct Opaque_80290088 *)raw;
    hair = raw->hair;
    if ((s32)creation_hair_model_parts[hair].present == 1) {
        chara_select_hair_node_a = creation_hair_model_parts[hair].model;
    }
    if ((s32)creation_cap_model_parts[hair].present == 1) {
        chara_select_hair_node_b = creation_cap_model_parts[hair].model;
    }
    head = ((CharacterAppearanceFields *)app)->head;
    if ((s32)creation_head_model_parts[head].present == 1) {
        chara_select_head_node = creation_head_model_parts[head].model;
    }
    char_creation_data_block = (void ***)relocate_data_block_pointers(this->shape_rel, this->shape_rel_size);
    TCharaMaking__bind_body_shape_nodes((CharacterAppearanceFields *)((CharacterAppearanceFields *)app), this->model);
    TCharaMaking__bind_head_shape_nodes((CharacterAppearanceFields *)((CharacterAppearanceFields *)app), (void *)((void *)chara_select_head_node));
    blend_creation_proportion_shapes(&((CharacterAppearanceFields *)creation_player_character)->width);
    lbl_805D49B4 = 0;
    char_select_active_flag = 1;
}

void TCMCharacter::update_chara_preview() {
    s32 state;
    state = TCharaMaking::query_state();
    TAdSinglePlyChrSelectGC__sub_8028ED54();
    switch (state) {
    case 3:
        if (chara_select_head_node != 0) {
            TCharaMaking__bind_head_shape_nodes((CharacterAppearanceFields *)((CharacterAppearanceFields *)creation_player_character), (void *)((void *)(chara_select_head_node = creation_head_model_parts[((CharacterAppearanceFields *)creation_player_character)->head].model)));
        }
        break;
    case 4: {
        s32 hair = ((CharacterAppearanceFields *)creation_player_character)->hair;
        u32 a = creation_hair_model_parts[hair].model;
        u32 b = creation_cap_model_parts[hair].model;
        chara_select_hair_node_a = a;
        chara_select_hair_node_b = b;
        break;
    }
    }
    blend_creation_proportion_shapes(&((CharacterAppearanceFields *)creation_player_character)->width);
    ((TObjMotion *)this)->advance_animation();
}

void request_creation_motion(s32 arg0) {
    if (creation_figure_object == 0 || creation_player_character == 0) {
        return;
    }
    ((TObjMotion *)creation_figure_object)->set_field_b8(arg0 * 3 + creation_motion_group(creation_player_character));
}

void TAdSinglePlyChrSelectGC::draw_player_model() { set_motion_interpolation_flag__10TObjMotionFv(this); draw_saving_joints_checked__10TObjMotionFv(this); }
void close_if_active__23TAdSinglePlyChrSelectGCFv(u8 * ad_single_ply_chr_select_gc) {
    if ((s32) char_select_active_flag != 0) {
        ((TAdSinglePlyChrSelectGC *)ad_single_ply_chr_select_gc)->draw_creation_figure();
    }
}
void TAdSinglePlyChrSelectGC::draw_creation_figure() {
    u32 v;
    TParticleCtrl::begin_effect_render();
    if (scan_creation_resources(this) == 0) {
        char_creation_figure_draw_flag = 0;
        return;
    }
    {
        char_creation_figure_draw_flag = 1;
        push_matrix();
        translate_matrix_vec3(0, ((u8 *)this) + 0x38);
        rotate_matrix_y(0, creation_figure_rotation_y);
        TObjFish::set_global_param((s32)((u8 *)char_select_current_entry + 0x460));
        this->draw_player_model();
        ((TObjMotion *)((u8 *)this))->get_item_ptr(0x3A);
        push_matrix_from();
        TObjFish::set_global_param((s32)((u8 *)char_select_current_entry + 0x2EC));
        TObjPlayer::play_phase_transition_sound(creation_head_model_parts[*(s16 *)((s8 *)char_select_current_entry + 0xA)].model);
        pop_matrix();
        v = creation_cap_model_parts[*(s16 *)((s8 *)char_select_current_entry + 0xC)].model;
        if (v != 0) {
            TCharaMaking::enable_making();
            ((TObjMotion *)((u8 *)this))->get_item_ptr(0x3B);
            push_matrix_from();
            TObjFish::set_global_param((s32)((u8 *)char_select_current_entry + 0x178));
            TObjPlayer::play_phase_transition_sound(v);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
        v = creation_hair_model_parts[*(s16 *)((s8 *)char_select_current_entry + 0xC)].model;
        if (v != 0) {
            TCharaMaking::enable_making();
            ((TObjMotion *)((u8 *)this))->get_item_ptr(0x3B);
            push_matrix_from();
            TObjFish::set_global_param((s32)((u8 *)char_select_current_entry + 0x178));
            TCharaMaking::setup_from_data(v, creation_player_character);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
s32 scan_creation_resources(void *arg0) {
    CreationTextureCacheEntry *p;
    CreationTextureCacheEntry *end;
    end = &((CreationTextureCacheEntry *)&creation_texture_cache)[0x80];
    for (p = (CreationTextureCacheEntry *)&creation_texture_cache; p < end; p++) {
        if (p->in_use == 0) {
            continue;
        }
        if (p->hair_textures.present != 0 && p->hair_textures.complete == 0) {
            continue;
        }
        if (p->head_textures.present != 0 && p->head_textures.complete == 0) {
            continue;
        }
        if (p->body_textures.complete == 0) {
            continue;
        }
        if (is_entry_equal__23TAdSinglePlyChrSelectGCFPvPv(p, (void *)creation_player_character) != 0) {
            break;
        }
    }
    if (p == end) {
        if (char_select_current_entry == NULL) {
            creation_resource_ready_state = 0;
            return 0;
        }
        creation_resource_ready_state = 1;
        return 1;
    }
    char_select_current_entry = p;
    creation_resource_ready_state = 2;
    return 1;
}
s32 find_shape_triangle_region(u8 *arg0) {
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f4_2;
    temp_f3 = *(f32 *)((s8 *)arg0 + 0);
    if (temp_f3 > lbl_805DD948) {
        if ((lbl_805DD94C * (temp_f3 - lbl_805DD948)) <= *(f32 *)((s8 *)arg0 + 4)) {
            return 6;
        }
        return 7;
    }
    if (temp_f3 <= lbl_805DD950) {
        temp_f4 = *(f32 *)((s8 *)arg0 + 4);
        if (temp_f3 >= (lbl_805DD948 * temp_f4)) {
            return 0;
        }
        if (temp_f3 <= (lbl_805DD954 * (temp_f4 - lbl_805DD944))) {
            return 1;
        }
        return 2;
    }
    temp_f4_2 = *(f32 *)((s8 *)arg0 + 4);
    if (temp_f3 <= (lbl_805DD954 * (temp_f4_2 - lbl_805DD944))) {
        return 3;
    }
    if (temp_f3 >= (lbl_805DD948 * temp_f4_2)) {
        return 4;
    }
    return 5;
}
void map_shape_region_samples(s32 region, s32 *samples) {
    s32 i;
    for (i = 0; i < 3; i++) {
        s32 sample = creation_region_sample_index_table[i + region * 3];
        if (sample == 7) {
            sample = 4;
        } else if (sample == 8) {
            sample = 0;
        }
        samples[i] = sample;
    }
}

void TAdSinglePlyChrSelectGC::get_sorted_region_samples(s32 *samples) {
    s32 j;
    s32 y;
    s32 x;
    s32 i;
    TCharaMaking__sub_8028E3A0();
    map_shape_region_samples((s32)(((void *)find_shape_triangle_region((u8 *)this))), (s32 *)samples);
    for (i = 0; i < 2; i++) {
        for (j = 2; j > i; j--) {
            x = samples[j];
            y = samples[j - 1];
            if (x < y) {
                samples[j - 1] = x;
                samples[j] = y;
            }
        }
    }
}
#pragma push
#pragma fp_contract on
// Barycentric weights of point inside the sample triangle of its region (inferred).
void calc_shape_region_coefficients(f32 *point) {
    s32 region = find_shape_triangle_region((u8 *)point);
    s32 i0;
    s32 i1;
    s32 i2;
    f32 u;
    f32 v;
    f32 y0;
    f32 d;
    f32 *hp;
    creation_shape_blend.region = region;
    i0 = creation_region_sample_index_table[region * 3];
    i1 = creation_region_sample_index_table[region * 3 + 1];
    i2 = creation_region_sample_index_table[region * 3 + 2];
    u = lbl_804D400C[i2].width - lbl_804D400C[i0].width;
    u = (point[0] - lbl_804D400C[i0].width) / u;
    hp = &lbl_804D400C[0].height;
    y0 = hp[i0 * 2];
    v = hp[i1 * 2];
    v = v;
    v = v - y0;
    d = hp[i2 * 2] - y0;
    d = (point[1] - y0) - d * u;
    v = d / v;
    creation_shape_blend.weights[2] = u;
    creation_shape_blend.weights[1] = v;
    creation_shape_blend.weights[0] = lbl_805DD944 - (v + u);
}
s32 clear_creation_shape_eval_masks(f32 *dst, const f32 *a, const f32 *b, const f32 *c) {
    s32 i;
    for (i = 0; i < 3; i++) {
        *dst++ = creation_shape_blend.weights[2] * *c++ + (creation_shape_blend.weights[0] * *a++ + creation_shape_blend.weights[1] * *b++);
    }
    return 1;
}

s32 TAdSinglePlyChrSelectGC::map_button_code(s32 arg0) {
    switch (arg0) {
    case 0x29:
        return 3;
    case 0x2C:
        return 4;
    case 0xFF:
        return -1;
    default:
        return -2;
    }
}

// Blends the vertex chunks of the three source models into the destination
// model's chunk list with the region weights: positions, normals (renormalised)
// and the upper half of the Ninja flags word.
s32 blend_shape_chunk_vertices(void) {
    s32 *a;
    s32 *b;
    s32 *c;
    s32 *d;
    s32 n;
    s32 extra;
    s32 count;
    s32 k;
    s32 rest;
    f32 v[3];
    f32 fa;
    f32 fb;
    f32 fc;
    CreationModelNodeState *dst = creation_shape_blend.destination;
    for (k = 0; k < 3; k++) {
    }
    d = ((CreationShapeNode *)dst->node)->model->vertex_list;
    a = ((CreationShapeNode *)creation_shape_blend.sources[0]->node)->model->vertex_list;
    b = ((CreationShapeNode *)creation_shape_blend.sources[1]->node)->model->vertex_list;
    c = ((CreationShapeNode *)creation_shape_blend.sources[2]->node)->model->vertex_list;
    for (n = 1000; n > 0; n--) {
        extra = TAdSinglePlyChrSelectGC::map_button_code(*d & 0xFF);
        if (extra < 0) {
            break;
        }
        count = (u32)d[1] >> 16;
        d += 2;
        a += 2;
        b += 2;
        c += 2;
        for (; count > 0; count--) {
            for (k = 3; k > 0; k--) {
                *d++ = f32_bits(creation_shape_blend.weights[2] * bits_to_f32(*c++) +
                                (creation_shape_blend.weights[0] * bits_to_f32(*a++) +
                                 creation_shape_blend.weights[1] * bits_to_f32(*b++)));
            }
            rest = extra;
            if (rest >= 3) {
                v[0] = creation_shape_blend.weights[2] * bits_to_f32(*c++) +
                       (creation_shape_blend.weights[0] * bits_to_f32(*a++) + creation_shape_blend.weights[1] * bits_to_f32(*b++));
                v[1] = creation_shape_blend.weights[2] * bits_to_f32(*c++) +
                       (creation_shape_blend.weights[0] * bits_to_f32(*a++) + creation_shape_blend.weights[1] * bits_to_f32(*b++));
                v[2] = creation_shape_blend.weights[2] * bits_to_f32(*c++) +
                       (creation_shape_blend.weights[0] * bits_to_f32(*a++) + creation_shape_blend.weights[1] * bits_to_f32(*b++));
                if (vector_length(v) != lbl_805DD940) {
                    normalize_vector(v);
                }
                d[0] = f32_bits(v[0]);
                d[1] = f32_bits(v[1]);
                d[2] = f32_bits(v[2]);
                d += 3;
                rest -= 3;
            }
            if (rest >= 1) {
                fa = (s32)((u32)*a++ >> 16);
                fb = (s32)((u32)*b++ >> 16);
                fc = (s32)((u32)*c++ >> 16);
                *d = ((s32)(creation_shape_blend.weights[2] * fc +
                            (creation_shape_blend.weights[0] * fa + creation_shape_blend.weights[1] * fb)) << 16) |
                     (*d & 0xFFFF);
                d++;
                rest--;
            }
            if (rest > 0) {
                d += rest;
                a += rest;
                b += rest;
                c += rest;
            }
        }
    }
    return 1;
}

void blend_creation_proportion_shapes(f32 *point) {
    s32 samples[3];
    u32 flags;
    s32 n;
    s32 m;
    TCharaMaking__sub_8028E3A0();
    calc_shape_region_coefficients(point);
    map_shape_region_samples(creation_shape_blend.region, samples);
    creation_shape_blend.destination = creation_head_shape_destination.nodes;
    creation_shape_blend.sources[0] = creation_head_shape_samples[samples[0]].nodes;
    creation_shape_blend.sources[1] = creation_head_shape_samples[samples[1]].nodes;
    creation_shape_blend.sources[2] = creation_head_shape_samples[samples[2]].nodes;
    for (n = 5; n > 0; n--) {
        if (creation_shape_blend.destination->node != NULL) {
            CreationShapeModel *dst = ((CreationShapeNode *)creation_shape_blend.destination->node)->model;
            if (dst != NULL) {
                f32 *a;
                f32 *b;
                f32 *c;
                s32 k;
                for (k = 0; k < 3; k++) {
                }
                a = ((CreationShapeNode *)creation_shape_blend.sources[0]->node)->model->center;
                b = ((CreationShapeNode *)creation_shape_blend.sources[1]->node)->model->center;
                c = ((CreationShapeNode *)creation_shape_blend.sources[2]->node)->model->center;
                dst->center[0] = creation_shape_blend.weights[2] * c[0] + (creation_shape_blend.weights[0] * a[0] + creation_shape_blend.weights[1] * b[0]);
                dst->center[1] = creation_shape_blend.weights[2] * c[1] + (creation_shape_blend.weights[0] * a[1] + creation_shape_blend.weights[1] * b[1]);
                dst->center[2] = creation_shape_blend.weights[2] * c[2] + (creation_shape_blend.weights[0] * a[2] + creation_shape_blend.weights[1] * b[2]);
            }
            if ((creation_shape_blend.sources[0]->flags | creation_shape_blend.sources[1]->flags | creation_shape_blend.sources[2]->flags) & 1) {
                ((CreationShapeNode *)creation_shape_blend.destination->node)->eval_flags &= ~1;
                clear_creation_shape_eval_masks(((CreationShapeNode *)creation_shape_blend.destination->node)->pos,
                    ((CreationShapeNode *)creation_shape_blend.sources[0]->node)->pos,
                    ((CreationShapeNode *)creation_shape_blend.sources[1]->node)->pos,
                    ((CreationShapeNode *)creation_shape_blend.sources[2]->node)->pos);
            }
            if (creation_shape_blend.sources[0]->flags & 0x10) {
                blend_shape_chunk_vertices();
            }
        }
        creation_shape_blend.destination++;
        creation_shape_blend.sources[0]++;
        creation_shape_blend.sources[1]++;
        creation_shape_blend.sources[2]++;
    }
    creation_shape_blend.destination = creation_body_shape_destination.nodes;
    creation_shape_blend.sources[0] = creation_body_shape_samples[samples[0]].nodes;
    creation_shape_blend.sources[1] = creation_body_shape_samples[samples[1]].nodes;
    creation_shape_blend.sources[2] = creation_body_shape_samples[samples[2]].nodes;
    for (m = 64; m > 0; m--) {
        CreationShapeModel *dst = ((CreationShapeNode *)creation_shape_blend.destination->node)->model;
        if (dst != NULL) {
            f32 *a = ((CreationShapeNode *)creation_shape_blend.sources[0]->node)->model->center;
            f32 *b = ((CreationShapeNode *)creation_shape_blend.sources[1]->node)->model->center;
            f32 *c = ((CreationShapeNode *)creation_shape_blend.sources[2]->node)->model->center;
            dst->center[0] = creation_shape_blend.weights[2] * c[0] + (creation_shape_blend.weights[0] * a[0] + creation_shape_blend.weights[1] * b[0]);
            dst->center[1] = creation_shape_blend.weights[2] * c[1] + (creation_shape_blend.weights[0] * a[1] + creation_shape_blend.weights[1] * b[1]);
            dst->center[2] = creation_shape_blend.weights[2] * c[2] + (creation_shape_blend.weights[0] * a[2] + creation_shape_blend.weights[1] * b[2]);
        }
        flags = creation_shape_blend.sources[0]->flags | creation_shape_blend.sources[1]->flags | creation_shape_blend.sources[2]->flags;
        if (flags & 1) {
            ((CreationShapeNode *)creation_shape_blend.destination->node)->eval_flags &= ~1;
            clear_creation_shape_eval_masks(((CreationShapeNode *)creation_shape_blend.destination->node)->pos,
                ((CreationShapeNode *)creation_shape_blend.sources[0]->node)->pos,
                ((CreationShapeNode *)creation_shape_blend.sources[1]->node)->pos,
                ((CreationShapeNode *)creation_shape_blend.sources[2]->node)->pos);
        }
        if (flags & 4) {
            ((CreationShapeNode *)creation_shape_blend.destination->node)->eval_flags &= ~4;
            clear_creation_shape_eval_masks(((CreationShapeNode *)creation_shape_blend.destination->node)->scl,
                ((CreationShapeNode *)creation_shape_blend.sources[0]->node)->scl,
                ((CreationShapeNode *)creation_shape_blend.sources[1]->node)->scl,
                ((CreationShapeNode *)creation_shape_blend.sources[2]->node)->scl);
        }
        if (flags & 0x10) {
            blend_shape_chunk_vertices();
        }
        creation_shape_blend.destination++;
        creation_shape_blend.sources[0]++;
        creation_shape_blend.sources[1]++;
        creation_shape_blend.sources[2]++;
    }
}
#pragma pop

s32 TAdSinglePlyChrSelectGC::count_remaining_slots() {
    CreationTextureCacheEntry *p;
    s32 n;
    n = 2;
    for (p = ((CreationTextureCacheEntry *)&creation_texture_cache); p < &((CreationTextureCacheEntry *)&creation_texture_cache)[0x80]; p++) {
        if (p->in_use != 0) {
            if (p->hair_textures.present != 0 && p->hair_textures.complete == 0) {
                n--;
            }
            if (p->head_textures.present != 0 && p->head_textures.complete == 0) {
                n--;
            }
            if (p->body_textures.complete == 0) {
                n--;
            }
        }
    }
    return n;
}
s32 TAdSinglePlyChrSelectGC::has_matching_entry(void *arg0) {
    CreationTextureCacheEntry *p;
    CreationTextureCacheEntry *end;
    end = (CreationTextureCacheEntry *)((u8 *)((CreationTextureCacheEntry *)&creation_texture_cache) + 0x23600);
    for (p = ((CreationTextureCacheEntry *)&creation_texture_cache); p < end; p++) {
        if (p->in_use != 0 && is_entry_equal__23TAdSinglePlyChrSelectGCFPvPv(p, arg0) != 0) return 1;
    }
    return 0;
}
CreationTextureCacheEntry *TAdSinglePlyChrSelectGC::find_free_slot() {
    CreationTextureCacheEntry *p;
    for (p = creation_texture_cache; p < (CreationTextureCacheEntry *)((u8 *)creation_texture_cache + 0x23600); p++) {
        if (p->in_use == 0) return p;
    }
    return 0;
}
void TAdSinglePlyChrSelectGC__sub_8028F084(CreationTextureCacheEntry *entry, TCharaMaking *appearance) {
    CreationTextureLoadSlot *slot;
    s32 index;
    TCharaMaking__bind_appearance_texture_lists(&entry->hair_textures.present, &entry->head_textures.present, &entry->body_textures.present, appearance);
    index = appearance->get_display_index();
    slot = &entry->hair_textures;
    if (slot->present != 0) {
        slot->request = create_ch_cr_load_afs_texture_req((void *)creation_figure_object, &slot->list, slot, (void *)index);
    }
    slot = &entry->head_textures;
    if (slot->present != 0) {
        slot->request = create_ch_cr_load_afs_texture_req((void *)creation_figure_object, &slot->list, slot, (void *)index);
    }
    slot = &entry->body_textures;
    slot->request = create_ch_cr_load_afs_texture_req((void *)creation_figure_object, &slot->list, slot, (void *)index);
    entry->in_use = 1;
    copy_slot_data__23TAdSinglePlyChrSelectGCFPvPv(entry, appearance);
}
s32 TAdSinglePlyChrSelectGC::evict_char_entries(s32 arg0) {
    s32 n;
    s32 k;
    CreationTextureCacheEntry *p;
    TCharaMaking::query_state();
    n = 0;
    for (k = 4; k >= 1; k--) {
        for (p = (CreationTextureCacheEntry *)&creation_texture_cache[127]; p >= (CreationTextureCacheEntry *)creation_texture_cache; p--) {
            if (p != char_select_current_entry && p->in_use != 0 && (p->hair_textures.present == 0 || p->hair_textures.complete != 0) && (p->head_textures.present == 0 || p->head_textures.complete != 0) && p->body_textures.complete != 0 &&
                count_char_diffs__23TAdSinglePlyChrSelectGCFPvPv(p, creation_player_character) >= k) {
                p->in_use = 0;
                ((TAdSinglePlyChrSelectGC *)p)->update_char_panels();
                if (++n == arg0) {
                    return n;
                }
            }
        }
    }
    return n;
}
void TAdSinglePlyChrSelectGC::update_char_panels() {
    u8 *arg0 = (u8 *)this;
    if (((s32) this->m_down != 0) && ((s32) this->m_up != 0)) {
        release_texture_list(arg0 + 0x178);
    }
    if (((s32) *(s32 *)((s8 *)arg0 + 0x188) != 0) && ((s32) *(s32 *)((s8 *)arg0 + 0x184) != 0)) {
        release_texture_list(arg0 + 0x2EC);
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x2F8) != 0) {
        release_texture_list(arg0 + 0x460);
    }
}

#pragma defer_codegen off
