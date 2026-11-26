#include "pso/system/memory.h"
#include "pso/ui/charcreate/CharacterPreviewModels.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/system/task/TObject.h"
#include "pso/network/TLobby.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/charcreate/TCMCharacter.h"
#include "pso/ui/charcreate/CharacterShape.h"
#include "pso/ui/charcreate/CharacterCreationTextureCache.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/AsyncFileRead.h"



TChCrLoadAfsTextureReq *create_ch_cr_load_afs_texture_req(void *figure, void *list, void *slot, void *index);
extern "C" {
f32 vector_length(f32 *v);
}
// Ninja chunk model (NJS_CNK_MODEL): vertex chunk list, polygon chunk list, bounds.
struct CreationShapeModel { s32 *vertex_list; s16 *polygon_list; f32 center[3]; };
struct CreationShapeNode { u32 eval_flags; CreationShapeModel *model; f32 pos[3]; s32 ang[3]; f32 scl[3]; };
s32 char_select_active_flag;
int char_creation_figure_draw_flag;
u32 creation_figure_rotation_y;
TCMCharacter *creation_figure_object;
CreationTextureCacheEntry *char_select_current_entry;
uaddr chara_select_hair_node_a;
uaddr chara_select_hair_node_b;
uaddr chara_select_head_node;
void ***char_creation_data_block;
saddr chara_select_preview_resource;
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
s32 creation_resource_ready_state;
extern "C" {
s32 creation_motion_group(CharacterAppearanceFields *);
void TCharaMaking__sub_8028E3A0();
void copy_player_visual_record(void *, void *);

void TAdSinglePlyChrSelectGC__sub_8028ED54(s32 part);
void TAdSinglePlyChrSelectGC__sub_8028F084(CreationTextureCacheEntry *entry, CharacterAppearanceFields *appearance);
extern s32 memcard_access_active;

void translate_matrix_vec3(u8 *matrix, u8 *vec);
void rotate_matrix_y(int, u32);
s32 release_texture_list(void *);
}

#pragma push
#pragma readonly_strings on
// empty motion name lists of the character-making BmlResourceDescriptors (inferred)
const char *pla_motion_files[1] = {NULL};
const char *plb_motion_files[1] = {NULL};
const char *plc_motion_files[1] = {NULL};
const char *pld_motion_files[1] = {NULL};
const char *ple_motion_files[1] = {NULL};
const char *plf_motion_files[1] = {NULL};
const char *plg_motion_files[1] = {NULL};
const char *plh_motion_files[1] = {NULL};
const char *pli_motion_files[1] = {NULL};
const char *plj_motion_files[1] = {NULL};
const char *plk_motion_files[1] = {NULL};
const char *pll_motion_files[1] = {NULL};
const char *pls_motion_files[1] = {NULL};
const char *plt_motion_files[1] = {NULL};
const char *plu_motion_files[1] = {NULL};
const char *plv_motion_files[1] = {NULL};
const char *plw_motion_files[1] = {NULL};
const char *plx_motion_files[1] = {NULL};
const char *ply_motion_files[1] = {NULL};
const char *pla_model_files[14] = {
    "plAbdy00.nj", "plAcap06.nj", "plAhai00.nj", "plAhai01.nj",
    "plAhai02.nj", "plAhai03.nj", "plAhai04.nj", "plAhai05.nj",
    "plAhai06.nj", "plAhai07.nj", "plAhai08.nj", "plAhai09.nj",
    "plAhed00.nj", NULL,
};
BmlResourceDescriptor pla_bml_descriptor = {"planj.bml", pla_model_files, pla_motion_files, 13, 0};
const char *plb_model_files[13] = {
    "plBbdy00.nj", "plBhai00.nj", "plBhai01.nj", "plBhai02.nj",
    "plBhai03.nj", "plBhai04.nj", "plBhai05.nj", "plBhai06.nj",
    "plBhai07.nj", "plBhai08.nj", "plBhai09.nj", "plBhed00.nj",
    NULL,
};
BmlResourceDescriptor plb_bml_descriptor = {"plbnj.bml", plb_model_files, plb_motion_files, 12, 0};
const char *plc_model_files[7] = {
    "plCbdy00.nj", "plChed00.nj", "plChed01.nj", "plChed02.nj",
    "plChed03.nj", "plChed04.nj", NULL,
};
BmlResourceDescriptor plc_bml_descriptor = {"plcnj.bml", plc_model_files, plc_motion_files, 6, 0};
const char *pld_model_files[23] = {
    "plDbdy00.nj", "plDcap00.nj", "plDcap01.nj", "plDcap02.nj",
    "plDcap03.nj", "plDcap04.nj", "plDcap05.nj", "plDcap06.nj",
    "plDcap07.nj", "plDcap08.nj", "plDcap09.nj", "plDhai00.nj",
    "plDhai01.nj", "plDhai02.nj", "plDhai03.nj", "plDhai04.nj",
    "plDhai05.nj", "plDhai06.nj", "plDhai07.nj", "plDhai08.nj",
    "plDhai09.nj", "plDhed00.nj", NULL,
};
BmlResourceDescriptor pld_bml_descriptor = {"pldnj.bml", pld_model_files, pld_motion_files, 22, 0};
const char *ple_model_files[7] = {
    "plEbdy00.nj", "plEhed00.nj", "plEhed01.nj", "plEhed02.nj",
    "plEhed03.nj", "plEhed04.nj", NULL,
};
BmlResourceDescriptor ple_bml_descriptor = {"plenj.bml", ple_model_files, ple_motion_files, 6, 0};
const char *plf_model_files[7] = {
    "plFbdy00.nj", "plFhed00.nj", "plFhed01.nj", "plFhed02.nj",
    "plFhed03.nj", "plFhed04.nj", NULL,
};
BmlResourceDescriptor plf_bml_descriptor = {"plfnj.bml", plf_model_files, plf_motion_files, 6, 0};
const char *plg_model_files[23] = {
    "plGbdy00.nj", "plGcap00.nj", "plGcap01.nj", "plGcap02.nj",
    "plGcap03.nj", "plGcap04.nj", "plGcap05.nj", "plGcap06.nj",
    "plGcap07.nj", "plGcap08.nj", "plGcap09.nj", "plGhai00.nj",
    "plGhai01.nj", "plGhai02.nj", "plGhai03.nj", "plGhai04.nj",
    "plGhai05.nj", "plGhai06.nj", "plGhai07.nj", "plGhai08.nj",
    "plGhai09.nj", "plGhed00.nj", NULL,
};
BmlResourceDescriptor plg_bml_descriptor = {"plgnj.bml", plg_model_files, plg_motion_files, 22, 0};
const char *plh_model_files[23] = {
    "plHbdy00.nj", "plHcap00.nj", "plHcap01.nj", "plHcap02.nj",
    "plHcap03.nj", "plHcap04.nj", "plHcap05.nj", "plHcap06.nj",
    "plHcap07.nj", "plHcap08.nj", "plHcap09.nj", "plHhai00.nj",
    "plHhai01.nj", "plHhai02.nj", "plHhai03.nj", "plHhai04.nj",
    "plHhai05.nj", "plHhai06.nj", "plHhai07.nj", "plHhai08.nj",
    "plHhai09.nj", "plHhed00.nj", NULL,
};
BmlResourceDescriptor plh_bml_descriptor = {"plhnj.bml", plh_model_files, plh_motion_files, 22, 0};
const char *pli_model_files[23] = {
    "plIbdy00.nj", "plIcap00.nj", "plIcap01.nj", "plIcap02.nj",
    "plIcap03.nj", "plIcap04.nj", "plIcap05.nj", "plIcap06.nj",
    "plIcap07.nj", "plIcap08.nj", "plIcap09.nj", "plIhai00.nj",
    "plIhai01.nj", "plIhai02.nj", "plIhai03.nj", "plIhai04.nj",
    "plIhai05.nj", "plIhai06.nj", "plIhai07.nj", "plIhai08.nj",
    "plIhai09.nj", "plIhed00.nj", NULL,
};
BmlResourceDescriptor pli_bml_descriptor = {"plinj.bml", pli_model_files, pli_motion_files, 22, 0};
const char *plj_model_files[7] = {
    "plJbdy00.nj", "plJhed00.nj", "plJhed01.nj", "plJhed02.nj",
    "plJhed03.nj", "plJhed04.nj", NULL,
};
BmlResourceDescriptor plj_bml_descriptor = {"pljnj.bml", plj_model_files, plj_motion_files, 6, 0};
const char *plk_model_files[23] = {
    "plKbdy00.nj", "plKcap00.nj", "plKcap01.nj", "plKcap02.nj",
    "plKcap03.nj", "plKcap04.nj", "plKcap05.nj", "plKcap06.nj",
    "plKcap07.nj", "plKcap08.nj", "plKcap09.nj", "plKhai00.nj",
    "plKhai01.nj", "plKhai02.nj", "plKhai03.nj", "plKhai04.nj",
    "plKhai05.nj", "plKhai06.nj", "plKhai07.nj", "plKhai08.nj",
    "plKhai09.nj", "plKhed00.nj", NULL,
};
BmlResourceDescriptor plk_bml_descriptor = {"plknj.bml", plk_model_files, plk_motion_files, 22, 0};
const char *pll_model_files[23] = {
    "plLbdy00.nj", "plLcap00.nj", "plLcap01.nj", "plLcap02.nj",
    "plLcap03.nj", "plLcap04.nj", "plLcap05.nj", "plLcap06.nj",
    "plLcap07.nj", "plLcap08.nj", "plLcap09.nj", "plLhai00.nj",
    "plLhai01.nj", "plLhai02.nj", "plLhai03.nj", "plLhai04.nj",
    "plLhai05.nj", "plLhai06.nj", "plLhai07.nj", "plLhai08.nj",
    "plLhai09.nj", "plLhed00.nj", NULL,
};
BmlResourceDescriptor pll_bml_descriptor = {"pllnj.bml", pll_model_files, pll_motion_files, 22, 0};
const char *pls_model_files[4] = {
    "plSbdy00.nj", "plShai00.nj", "plShed00.nj", NULL,
};
BmlResourceDescriptor pls_bml_descriptor = {"plsnj.bml", pls_model_files, pls_motion_files, 3, 0};
const char *plt_model_files[4] = {
    "plTbdy00.nj", "plThai00.nj", "plThed00.nj", NULL,
};
BmlResourceDescriptor plt_bml_descriptor = {"pltnj.bml", plt_model_files, plt_motion_files, 3, 0};
const char *plu_model_files[3] = {
    "plUbdy00.nj", "plUhed00.nj", NULL,
};
BmlResourceDescriptor plu_bml_descriptor = {"plunj.bml", plu_model_files, plu_motion_files, 2, 0};
const char *plv_model_files[3] = {
    "plVbdy00.nj", "plVhed00.nj", NULL,
};
BmlResourceDescriptor plv_bml_descriptor = {"plvnj.bml", plv_model_files, plv_motion_files, 2, 0};
const char *plw_model_files[3] = {
    "plWbdy00.nj", "plWhed00.nj", NULL,
};
BmlResourceDescriptor plw_bml_descriptor = {"plwnj.bml", plw_model_files, plw_motion_files, 2, 0};
const char *plx_model_files[3] = {
    "plXbdy00.nj", "plXhed00.nj", NULL,
};
BmlResourceDescriptor plx_bml_descriptor = {"plxnj.bml", plx_model_files, plx_motion_files, 2, 0};
const char *ply_model_files[3] = {
    "plYbdy00.nj", "plYhed00.nj", NULL,
};
BmlResourceDescriptor ply_bml_descriptor = {"plynj.bml", ply_model_files, ply_motion_files, 2, 0};
BmlResourceDescriptor *character_making_resource_descriptor_table[19] = {
    &pla_bml_descriptor, &plb_bml_descriptor, &plc_bml_descriptor, &pld_bml_descriptor,
    &ple_bml_descriptor, &plf_bml_descriptor, &plg_bml_descriptor, &plh_bml_descriptor,
    &pli_bml_descriptor, &plj_bml_descriptor, &plk_bml_descriptor, &pll_bml_descriptor,
    &pls_bml_descriptor, &plt_bml_descriptor, &plu_bml_descriptor, &plv_bml_descriptor,
    &plw_bml_descriptor, &plx_bml_descriptor, &ply_bml_descriptor,
};
TObjMotionAction character_making_action_table[9] = {
    { MOTION_MODE_LOOP, 0, 33, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 1, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 0, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 31, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 32, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 30, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 47, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 48, 1.0f, 0 },
    { MOTION_MODE_LOOP, 0, 46, 1.0f, 0 },
};
// TCMCharacter class-name pointer, stored as the object name by TCMCharacter__ct (inferred)

const char *TCMCharacter::name = "TCMCharacter";
extern "C" {
// empty model part copied into every slot by init_entry_tables (inferred)
__declspec(section ".rodata") CreationModelPart empty_creation_model_part = {0, 0};
#pragma pop
__declspec(section ".data") CreationModelNodeState creation_empty_model_node = {0,0};
}
void load_creation_shape_rel(TCMCharacter *character);
s32 scan_creation_resources(void *context);
uaddr relocate_data_block_pointers(uaddr data, u32 size);
void reset_character_creation_figure_rotation(void);

extern s32 creation_region_sample_index_table[24]; extern CreationShapePoint creation_shape_corners[9];
#pragma defer_codegen on
TCMCharacter::TCMCharacter(TObject *parent) : TObjMotion(parent) {
    CreationTextureCacheEntry *p;
    s32 res;
    CharacterAppearanceFields *cm;

    m_name = TCMCharacter::name;
    memcard_access_active = 1;
    cm = creation_player_character;
    char_select_active_flag = 0;
    char_creation_figure_draw_flag = 0;
    creation_figure_object = this;
    res = (saddr)new BmlResource(6, ((BmlResourceDescriptor **)character_making_resource_descriptor_table)[character_display_index((uaddr)cm)], 0, 0, NULL);
    chara_select_preview_resource = res;
    for (p = creation_texture_cache; p < creation_texture_cache + CREATION_TEXTURE_CACHE_CAPACITY; p++) {
        p->in_use = 0;
        p->hair_textures.textures.present = 0;
        p->head_textures.textures.present = 0;
        p->body_textures.textures.present = 0;
        p->hair_textures.complete = 0;
        p->head_textures.complete = 0;
        p->body_textures.complete = 0;
    }
    char_select_current_entry = 0;
    TAdSinglePlyChrSelectGC__sub_8028ED54(0);
    char_select_current_entry = 0;
    set_action_table(character_making_action_table);
    set_motion_list(creation_menu_main_obj->motions);
    requested_action = creation_motion_group(creation_player_character);
    set_animation(requested_action);
    joint_matrices = mem_alloc(0xC00);
    position.z = 0.0f;
    position.y = 0.0f;
    position.x = 0.0f;
    rotation_z = 0;
    rotation_y = 0;
    rotation_x = 0;
    load_creation_shape_rel(this);
    reset_character_creation_figure_rotation();
    creation_resource_ready_state = 0;
}
TCMCharacter::~TCMCharacter() {
    CreationTextureCacheEntry *p;
    CreationTextureCacheEntry *end;
    for (p = creation_texture_cache, end = creation_texture_cache + CREATION_TEXTURE_CACHE_CAPACITY; p < end; p++) {
        if (p->in_use != 0) {
            ((TAdSinglePlyChrSelectGC *)p)->update_char_panels();
        }
    }
    free_field_FC();
    delete (BmlResource *)chara_select_preview_resource;
    chara_select_preview_resource = 0;
    reset_model_parts();
    chara_select_head_node = 0;
    chara_select_hair_node_b = 0;
    chara_select_hair_node_a = 0;
    model = 0;
    mem_free(joint_matrices);
    creation_resource_ready_state = 0;
    creation_figure_object = 0;
    memcard_access_active = 0;
    char_creation_figure_draw_flag = 0;
}

void TAdSinglePlyChrSelectGC::update_pair(void* p) { TAdSinglePlyChrSelectGC::init_entry_tables(p); ((TCMCharacter *)p)->load_model_parts(); }

void copy_creation_model_part(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }
void TAdSinglePlyChrSelectGC::init_entry_tables(void* _w0) {
    for (s32 i = 0; i < 10; i++) {
        copy_creation_model_part(&creation_hair_model_parts[i], &empty_creation_model_part);
        copy_creation_model_part(&creation_cap_model_parts[i], &empty_creation_model_part);
    }
    for (s32 i = 0; i < 5; i++) {
        copy_creation_model_part(&creation_head_model_parts[i], &empty_creation_model_part);
    }
}
void TCMCharacter::load_model_parts() {
    CharacterAppearanceFields *appearance = creation_player_character;
    CharacterClassAppearance *entry = &class_appearance_table[character_display_index(reinterpret_cast<uaddr>(creation_player_character))];
    creation_models_ready = 1;
    model = get_bml_model((BmlResource *)chara_select_preview_resource, 0);
    s32 next = bind_model_parts(&chara_select_hair_node_b, entry->capModels, creation_cap_model_parts, 4, 1);
    next = bind_model_parts(&chara_select_hair_node_a, entry->hairModels, creation_hair_model_parts, 4, next);
    bind_model_parts(&chara_select_head_node, entry->headModels, creation_head_model_parts, 3, next);
    character_display_index(reinterpret_cast<uaddr>(appearance));
}

s32 TCMCharacter::bind_model_parts(uaddr *selected, const char **names, CreationModelPart *parts,
                                 s32 part, s32 model_index) {
    *selected = 0;
    if (names == NULL) {
        return model_index;
    }
    CharacterAppearanceFields *appearance = (CharacterAppearanceFields *)creation_player_character;
    s32 count = class_appearance_table[character_display_index(reinterpret_cast<uaddr>(creation_player_character))].counts[part];
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
            parts->model = (saddr)get_bml_model((BmlResource *)chara_select_preview_resource, model_index++);
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
s32 TAdSinglePlyChrSelectGC::is_active() {
    return (u8)((u8) (char_select_active_flag == 1));
}
int get_char_creation_figure_draw_flag(void) { return char_creation_figure_draw_flag; }
extern "C" void copy_creation_model_node(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(u32*)((char*)p + 0x4) = *(u32*)((char*)q + 0x4); }
void reset_creation_shape_set(saddr node) {
    copy_creation_model_node((void*)node, (void *)&creation_empty_model_node);
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
    reset_creation_shape_set((saddr)p);
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
      reset_creation_shape_set((saddr)q);
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
    reset_creation_shape_set((saddr)p);
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
      reset_creation_shape_set((saddr)q);
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
void bind_character_preview_models(const CharacterPreviewModels *models) {
    s32 i;
    reset_creation_head_shapes();
    reset_creation_body_shapes();
    make_node_flag_table(models->head, (NodeFlagEntry *)((void *)&creation_head_shape_destination));
    make_node_flag_table(models->body, (NodeFlagEntry *)((void *)&creation_body_shape_destination));
    for (i = 0; i < 3; i++) {
        s32 t = models->sample_indices[i];
        make_node_flag_table(models->head_samples[i], (NodeFlagEntry *)&creation_head_shape_samples[t]);
        make_node_flag_table(models->body_samples[i], (NodeFlagEntry *)&creation_body_shape_samples[t]);
    }
}
void load_creation_shape_rel(TCMCharacter *character) {
    s32 rc;
    character->shape_rel = TQuestVmDownLoadServer::alloc(0x44000);
    rc = request_file_read(
        chara_select_creation_shape_rel_files[character_display_index(reinterpret_cast<uaddr>(creation_player_character))],
        character->shape_rel, &character->shape_rel_ready, NULL);
    character->shape_rel_size = rc;
    if (rc >= 0) {
        if (character->shape_rel_size > 0x44000) {
            return;
        }
    }
}
void TCMCharacter::free_field_FC() {
    safe_free(shape_rel);
    shape_rel = NULL;
}

void TCMCharacter::run_task() {
    static void (TCMCharacter::*modes[2])() = {
        &TCMCharacter::apply_character_appearance, &TCMCharacter::update_chara_preview,
    };
    (this->*modes[char_select_active_flag])();
}


// The three shape samples (corners in creation_shape_corners) of each proportion region.
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
CreationShapePoint creation_shape_corners[9] = {
    {0.0f, 0.0f}, {1.0f / 3.0f, 0.0f}, {2.0f / 3.0f, 0.0f}, {1.0f / 3.0f, 0.5f}, {0.0f, 1.0f},
    {1.0f / 3.0f, 1.0f}, {2.0f / 3.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f},
};


void TCMCharacter::apply_character_appearance() {
    CharacterAppearanceFields *app;
    CharacterAppearanceFields *raw;
    s32 hair;
    s32 head;
    if (is_bml_loaded((BmlResource *)chara_select_preview_resource) == 0 || this->shape_rel_ready == 0) {
        return;
    }
    TAdSinglePlyChrSelectGC::update_pair(this);
    raw = creation_player_character;
    app = raw;
    hair = raw->hair;
    if ((s32)creation_hair_model_parts[hair].present == 1) {
        chara_select_hair_node_a = creation_hair_model_parts[hair].model;
    }
    if ((s32)creation_cap_model_parts[hair].present == 1) {
        chara_select_hair_node_b = creation_cap_model_parts[hair].model;
    }
    head = app->head;
    if ((s32)creation_head_model_parts[head].present == 1) {
        chara_select_head_node = creation_head_model_parts[head].model;
    }
    char_creation_data_block = (void ***)relocate_data_block_pointers(reinterpret_cast<saddr>(this->shape_rel), this->shape_rel_size);
    TCharaMaking__bind_body_shape_nodes(app, this->model);
    TCharaMaking__bind_head_shape_nodes(app, (void *)chara_select_head_node);
    blend_creation_proportion_shapes(&creation_player_character->width);
    memcard_access_active = 0;
    char_select_active_flag = 1;
}

void TCMCharacter::update_chara_preview() {
    s32 state;
    state = TCharaMaking::query_state();
    TAdSinglePlyChrSelectGC__sub_8028ED54(state);
    switch (state) {
    case 3:
        if (chara_select_head_node != 0) {
            TCharaMaking__bind_head_shape_nodes(creation_player_character, (void *)((void *)(chara_select_head_node = creation_head_model_parts[creation_player_character->head].model)));
        }
        break;
    case 4: {
        s32 hair = creation_player_character->hair;
        uaddr a = creation_hair_model_parts[hair].model;
        uaddr b = creation_cap_model_parts[hair].model;
        chara_select_hair_node_a = a;
        chara_select_hair_node_b = b;
        break;
    }
    }
    blend_creation_proportion_shapes(&creation_player_character->width);
    this->advance_animation();
}

void request_creation_motion(s32 motion) {
    if (creation_figure_object == 0 || creation_player_character == 0) {
        return;
    }
    creation_figure_object->set_requested_action(motion * 3 + creation_motion_group(creation_player_character));
}

void TCMCharacter::draw_player_model() { set_motion_interpolation_flag(); draw_saving_joints_checked(); }
void TCMCharacter::render() {
    if (char_select_active_flag != 0) {
        draw_creation_figure();
    }
}
void TCMCharacter::draw_creation_figure() {
    u32 v;
    TParticleCtrl::begin_effect_render();
    if (scan_creation_resources(this) == 0) {
        char_creation_figure_draw_flag = 0;
        return;
    }
    {
        char_creation_figure_draw_flag = 1;
        push_matrix();
        translate_matrix_vec3(0, (u8 *)&position);
        rotate_matrix_y(0, creation_figure_rotation_y);
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>((u8 *)char_select_current_entry + 0x460));
        this->draw_player_model();
        push_matrix_from((void *)get_joint_matrix(0x3A));
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>((u8 *)char_select_current_entry + 0x2EC));
        TObjPlayer::play_phase_transition_sound(creation_head_model_parts[*(s16 *)((s8 *)char_select_current_entry + 0xA)].model);
        pop_matrix();
        v = creation_cap_model_parts[*(s16 *)((s8 *)char_select_current_entry + 0xC)].model;
        if (v != 0) {
            TCharaMaking::enable_making();
            push_matrix_from((void *)get_joint_matrix(0x3B));
            set_texture_list(reinterpret_cast<NJS_TEXLIST *>((u8 *)char_select_current_entry + 0x178));
            TObjPlayer::play_phase_transition_sound(v);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
        v = creation_hair_model_parts[*(s16 *)((s8 *)char_select_current_entry + 0xC)].model;
        if (v != 0) {
            TCharaMaking::enable_making();
            push_matrix_from((void *)get_joint_matrix(0x3B));
            set_texture_list(reinterpret_cast<NJS_TEXLIST *>((u8 *)char_select_current_entry + 0x178));
            TCharaMaking::setup_from_data(v, creation_player_character);
            pop_matrix();
            TCharaMaking::clear_flag_bit0();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
s32 scan_creation_resources(void *context) {
    CreationTextureCacheEntry *p;
    CreationTextureCacheEntry *end;
    end = creation_texture_cache + CREATION_TEXTURE_CACHE_CAPACITY;
    for (p = creation_texture_cache; p < end; p++) {
        if (p->in_use == 0) {
            continue;
        }
        if (p->hair_textures.textures.present != 0 && p->hair_textures.complete == 0) {
            continue;
        }
        if (p->head_textures.textures.present != 0 && p->head_textures.complete == 0) {
            continue;
        }
        if (p->body_textures.complete == 0) {
            continue;
        }
        if (p->is_entry_equal(creation_player_character) != 0) {
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
s32 find_shape_triangle_region(u8 *point) {
    f32 u;
    f32 v0;
    f32 v1;
    u = *(f32 *)((s8 *)point + 0);
    if (u > 0.6666667f) {
        if ((3.0f * (u - 0.6666667f)) <= *(f32 *)((s8 *)point + 4)) {
            return 6;
        }
        return 7;
    }
    if (u <= 0.33333334f) {
        v0 = *(f32 *)((s8 *)point + 4);
        if (u >= (0.6666667f * v0)) {
            return 0;
        }
        if (u <= (-0.6666667f * (v0 - 1.0f))) {
            return 1;
        }
        return 2;
    }
    v1 = *(f32 *)((s8 *)point + 4);
    if (u <= (-0.6666667f * (v1 - 1.0f))) {
        return 3;
    }
    if (u >= (0.6666667f * v1)) {
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

void get_sorted_character_proportion_samples(const f32 *point, s32 *samples) {
    s32 j;
    s32 y;
    s32 x;
    s32 i;
    TCharaMaking__sub_8028E3A0();
    map_shape_region_samples(find_shape_triangle_region((u8 *)point), samples);
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
    u = creation_shape_corners[i2].width - creation_shape_corners[i0].width;
    u = (point[0] - creation_shape_corners[i0].width) / u;
    hp = &creation_shape_corners[0].height;
    y0 = hp[i0 * 2];
    v = hp[i1 * 2];
    v = v;
    v = v - y0;
    d = hp[i2 * 2] - y0;
    d = (point[1] - y0) - d * u;
    v = d / v;
    creation_shape_blend.weights[2] = u;
    creation_shape_blend.weights[1] = v;
    creation_shape_blend.weights[0] = 1.0f - (v + u);
}
s32 clear_creation_shape_eval_masks(f32 *dst, const f32 *a, const f32 *b, const f32 *c) {
    s32 i;
    for (i = 0; i < 3; i++) {
        *dst++ = creation_shape_blend.weights[2] * *c++ + (creation_shape_blend.weights[0] * *a++ + creation_shape_blend.weights[1] * *b++);
    }
    return 1;
}

s32 TAdSinglePlyChrSelectGC::map_button_code(s32 code) {
    switch (code) {
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
                if (vector_length(v) != 0.0f) {
                    normalize_vector((Vec *)v);
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
    for (p = creation_texture_cache; p < creation_texture_cache + CREATION_TEXTURE_CACHE_CAPACITY; p++) {
        if (p->in_use != 0) {
            if (p->hair_textures.textures.present != 0 && p->hair_textures.complete == 0) {
                n--;
            }
            if (p->head_textures.textures.present != 0 && p->head_textures.complete == 0) {
                n--;
            }
            if (p->body_textures.complete == 0) {
                n--;
            }
        }
    }
    return n;
}
s32 TAdSinglePlyChrSelectGC::has_matching_entry(CharacterAppearanceFields *character) {
    CreationTextureCacheEntry *p;
    CreationTextureCacheEntry *end;
    end = creation_texture_cache + CREATION_TEXTURE_CACHE_CAPACITY;
    for (p = creation_texture_cache; p < end; p++) {
        if (p->in_use != 0 && p->is_entry_equal(character) != 0) return 1;
    }
    return 0;
}
CreationTextureCacheEntry *TAdSinglePlyChrSelectGC::find_free_slot() {
    CreationTextureCacheEntry *p;
    for (p = creation_texture_cache; p < creation_texture_cache + CREATION_TEXTURE_CACHE_CAPACITY; p++) {
        if (p->in_use == 0) return p;
    }
    return 0;
}
void TAdSinglePlyChrSelectGC__sub_8028F084(CreationTextureCacheEntry *entry, CharacterAppearanceFields *appearance) {
    CreationTextureLoadSlot *slot;
    saddr index;
    TCharaMaking__bind_appearance_texture_lists(&entry->hair_textures.textures, &entry->head_textures.textures, &entry->body_textures.textures, appearance);
    index = character_display_index(reinterpret_cast<uaddr>(appearance));
    slot = &entry->hair_textures;
    if (slot->textures.present != 0) {
        slot->request = create_ch_cr_load_afs_texture_req(creation_figure_object, &slot->textures.list, slot, (void *)index);
    }
    slot = &entry->head_textures;
    if (slot->textures.present != 0) {
        slot->request = create_ch_cr_load_afs_texture_req(creation_figure_object, &slot->textures.list, slot, (void *)index);
    }
    slot = &entry->body_textures;
    slot->request = create_ch_cr_load_afs_texture_req(creation_figure_object, &slot->textures.list, slot, (void *)index);
    entry->in_use = 1;
    entry->copy_slot_data(appearance);
}
s32 TAdSinglePlyChrSelectGC::evict_char_entries(s32 limit) {
    s32 n;
    s32 k;
    CreationTextureCacheEntry *p;
    TCharaMaking::query_state();
    n = 0;
    for (k = 4; k >= 1; k--) {
        for (p = &creation_texture_cache[127]; p >= creation_texture_cache; p--) {
            if (p != char_select_current_entry && p->in_use != 0 && (p->hair_textures.textures.present == 0 || p->hair_textures.complete != 0) && (p->head_textures.textures.present == 0 || p->head_textures.complete != 0) && p->body_textures.complete != 0 &&
                p->count_char_diffs(creation_player_character) >= k) {
                p->in_use = 0;
                ((TAdSinglePlyChrSelectGC *)p)->update_char_panels();
                if (++n == limit) {
                    return n;
                }
            }
        }
    }
    return n;
}
void TAdSinglePlyChrSelectGC::update_char_panels() {
    u8 *base = (u8 *)this;
    if (((saddr) this->m_down != 0) && ((saddr) this->m_up != 0)) {
        release_texture_list(base + 0x178);
    }
    if (((s32) *(s32 *)((s8 *)base + 0x188) != 0) && ((s32) *(s32 *)((s8 *)base + 0x184) != 0)) {
        release_texture_list(base + 0x2EC);
    }
    if ((s32) *(s32 *)((s8 *)base + 0x2F8) != 0) {
        release_texture_list(base + 0x460);
    }
}


s32 select_unused_appearance_part(void *appearance, s32 part) {
    CharacterAppearanceFields c = *(CharacterAppearanceFields *)appearance;
    s32 max;
    s32 cur;
    s32 v;
    max = class_appearance_table[character_display_index(reinterpret_cast<uaddr>(&c))].counts[part];
    cur = (&c.costume)[part];
    v = cur;
    do {
        if (++v >= max) {
            v = 0;
        }
    } while (v != cur);
    if (v != cur) {
        (&c.costume)[part] = v;
        if (TAdSinglePlyChrSelectGC::has_matching_entry(&c) == 0) {
            goto ok;
        }
    }
    v = cur;
    do {
        if (--v < 0) {
            v = max - 1;
        }
    } while (v != cur);
    if (v != cur) {
        (&c.costume)[part] = v;
        if (TAdSinglePlyChrSelectGC::has_matching_entry(&c) == 0) {
            goto ok;
        }
    }
    return 0;
ok:
    copy_player_visual_record(appearance, &c);
    return 1;
}

#pragma push
#pragma fp_contract on
void TAdSinglePlyChrSelectGC__sub_8028ED54(s32 part) {
    CreationTextureCacheEntry *entry;
    if (TAdSinglePlyChrSelectGC::count_remaining_slots() > 0) {
        CharacterAppearanceFields buf = *creation_player_character;
        if ((part < 0) || (part >= 5)) {
            if (TAdSinglePlyChrSelectGC::has_matching_entry(&buf) != 0) {
                return;
            }
            goto load;
        }
        if ((TAdSinglePlyChrSelectGC::has_matching_entry(&buf) == 0) || (select_unused_appearance_part(&buf, part) != 0)) {
load:
            entry = TAdSinglePlyChrSelectGC::find_free_slot();
            if (entry == 0) {
                if (TAdSinglePlyChrSelectGC::evict_char_entries(1) == 0) {
                    return;
                }
                entry = TAdSinglePlyChrSelectGC::find_free_slot();
            }
            TAdSinglePlyChrSelectGC__sub_8028F084(entry, &buf);
        }
    }
}
#pragma pop

void CreationTextureCacheEntry::copy_slot_data(CharacterAppearanceFields *character) {
    s32 i;
    for (i = 0; i < 5; i++) (&costume)[i] = (&character->costume)[i];
    section = character->section;
}

s32 CreationTextureCacheEntry::count_char_diffs(CharacterAppearanceFields *character) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 5; i++) {
        if ((&costume)[i] != (&character->costume)[i]) {
            n++;
        }
    }
    if (section != character->section) {
        n++;
    }
    return n;
}

s32 CreationTextureCacheEntry::is_entry_equal(CharacterAppearanceFields *character) {
    s32 i;
    if (section != character->section) {
        return 0;
    }
    for (i = 0; i < 5; i++) {
        if ((&costume)[i] != (&character->costume)[i]) {
            return 0;
        }
    }
    return 1;
}
