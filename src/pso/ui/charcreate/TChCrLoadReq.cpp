#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/charcreate/TCMCharacter.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/charcreate/TChCrLoadReq.h"
#include "pso/ui/charcreate/TChCrLoadGmNjReq.h"
#include "pso/ui/charcreate/TChCrLoadAfs.h"
#include "pso/ui/charcreate/TChCrLoadAfsTextureReq.h"
#include "pso/ui/charcreate/CharacterPreviewModels.h"
#include "pso/system/NinjaChunk.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/CharacterLoadBuffer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/TObjBase.h"

// Built with -inline off,deferred: .text comes out last function first, so the functions are
// written in reverse address order; the data (the node range statics, the load slot count, run_task's
// table, then the preview tables) stays in source order.

#pragma push
#pragma readonly_strings on
const char *TChCrLoadReq::name = "TChCrLoadReq";
#pragma pop

// A node tree is valid when no node, child, sibling or model pointer lies in the low 2 MB.
s32 is_node_tree_valid(NJS_OBJECT *object) {
    if (object->evalflags & 0xFFFFE000) {
        return 0;
    }
    static NJS_OBJECT *node_tree_range_start = (NJS_OBJECT *)0x0;
    static NJS_OBJECT *node_tree_range_end = (NJS_OBJECT *)0x200000;
    static void *model_range_start = (void *)0x0;
    static void *model_range_end = (void *)0x200000;
    if ((object->child > node_tree_range_start && object->child < node_tree_range_end) ||
        (object->sibling > node_tree_range_start && object->sibling < node_tree_range_end) ||
        (object->model > model_range_start && object->model < model_range_end)) {
        return 0;
    }
    if (object->child != NULL && is_node_tree_valid(object->child) == 0) {
        return 0;
    }
    if (object->sibling != NULL && is_node_tree_valid(object->sibling) == 0) {
        return 0;
    }
    return 1;
}

s32 chr_select_load_slot_count;

void *TChCrLoadReq::create(void *parent) {
    return new TChCrLoadReq((TObjPlayer *)parent);
}

TChCrLoadReq *create_ch_cr_load_req(TObject *parent, const CharacterPreviewLoadArgs *args) {
    return new TChCrLoadReq(parent, args);
}

TChCrLoadReq::TChCrLoadReq(TObjPlayer *player) : TObject(player) {
    m_name = TChCrLoadReq::name;
    inputs.appearance = (CharacterAppearanceFields *)player->name;
    inputs.completion_flags = (u32 *)&player->model_load_flags;
    inputs.load_slot = player->get_entity_id();
    inputs.body_model = (s32 *)&player->model;
    inputs.part_models = (s32 *)&player->hair_model;
    inputs.body_textures = &player->body_textures;
    inputs.other_textures = (NJS_TEXLIST *)player->attachment_textures;
    inputs.head_textures = (NJS_TEXLIST *)player->head_textures;
    reset_request();
}

void CharacterPreviewLoadArgs::copy_from(const CharacterPreviewLoadArgs *source) {
    // Preserve the retail word-by-word load and store order.
    volatile CharacterPreviewLoadArgs *destination = this;
    const volatile CharacterPreviewLoadArgs *input = source;
    destination->appearance = input->appearance;
    destination->completion_flags = input->completion_flags;
    destination->load_slot = input->load_slot;
    destination->body_model = input->body_model;
    destination->part_models = input->part_models;
    destination->body_textures = input->body_textures;
    destination->other_textures = input->other_textures;
    destination->head_textures = input->head_textures;
}

TChCrLoadReq::TChCrLoadReq(TObject *parent, const CharacterPreviewLoadArgs *args) : TObject(parent) {
    m_name = TChCrLoadReq::name;
    inputs.copy_from(args);
    reset_request();
}

void TChCrLoadReq::reset_request() {
    s32 i;
    s32 index;
    head_model = inputs.part_models + 2;
    index = character_display_index(reinterpret_cast<uaddr>(inputs.appearance));
    class_appearance = &class_appearance_table[index];
    reset_character_load_buffer(inputs.load_slot);
    inputs.body_model[0] = 0;
    inputs.part_models[1] = 0;
    inputs.part_models[0] = 0;
    inputs.part_models[2] = 0;
    for (i = 0; i < 6; i++) {
        sample_loads[i] = 0;
    }
    holds_load_slot = 0;
    timer = 0x1518;
    state = 0;
}

TChCrLoadReq::~TChCrLoadReq() {
    release_load_slot();
}

void TChCrLoadReq::run_task() {
    if (--timer <= 0) {
        queue_destruction();
        return;
    }
    static void (TChCrLoadReq::*tbl[3])() = { &TChCrLoadReq::update_load_progress, &TChCrLoadReq::try_advance_state, &TChCrLoadReq::close_and_destroy };
    (this->*tbl[state])();
}

void TChCrLoadReq::update_load_progress() {
    if (timer > 0x1512) {
        if (load_slot_available() == 0) {
            timer = 0x1512;
            goto claim;
        }
    } else {
claim:
        if (try_claim_load_slot() != 0) {
            request_model_loads();
            request_texture_loads();
            state = 1;
        }
    }
}

void TChCrLoadReq::try_advance_state() {
    if (completion_flags_clear() != 0) {
        start_preview_loads();
        state = 2;
    }
}

void TChCrLoadReq::close_and_destroy() {
    if (all_preview_loads_complete()) {
        load_preview_models();
        *inputs.completion_flags &= 0xFFFFFF7F;
        release_load_slot();
        queue_destruction();
    }
}

saddr TChCrLoadReq::calc_preview_offset(s32 display_index, s32 head, s32 region_index) {
    return head + (region_index * chr_select_preview_stride_table[display_index] + chr_select_preview_base_offset_table[display_index]);
}

saddr TChCrLoadReq::calc_preview_last_index(s32 display_index, s32 region_index) {
    s32 stride=chr_select_preview_stride_table[display_index];
    return stride + region_index * stride - 1 + chr_select_preview_base_offset_table[display_index];
}

s32 load_slot_available() {
    return chr_select_load_slot_count < 1;
}

s32 TChCrLoadReq::try_claim_load_slot() {
    if (((s32) holds_load_slot != 0) || ((s32) chr_select_load_slot_count < 0) || ((s32) chr_select_load_slot_count > 1)) {
        return 0;
    }
    if ((s32) chr_select_load_slot_count >= 1) {
        return 0;
    }
    holds_load_slot = 1;
    chr_select_load_slot_count += 1;
    return 1;
}

void TChCrLoadReq::release_load_slot() {
    if (((s32) chr_select_load_slot_count <= 1) && ((s32) this->holds_load_slot != 0)) {
        this->holds_load_slot = 0;
        if (--chr_select_load_slot_count == 0) {
            return;
        }
    }
}

void TChCrLoadReq::request_model_loads() {
    TChCrLoadGmNjReqArgs body;
    TChCrLoadGmNjReqArgs cap;
    TChCrLoadGmNjReqArgs hair;
    TChCrLoadGmNjReqArgs head;
    s32 index;
    const char **names;
    const char *name;
    reset_character_load_buffer(inputs.load_slot);
    *inputs.body_model = 0;
    body.name = class_appearance->bodyModel;
    body.model_out = (NJS_OBJECT **)inputs.body_model;
    body.load_slot = inputs.load_slot;
    body.completion_mask = 0x40;
    body.completion_flags = inputs.completion_flags;
    if (create_ch_cr_load_gm_nj_req(this, &body) == NULL) return;
    index = inputs.appearance->hair;
    inputs.part_models[1] = 0;
    names = class_appearance->capModels;
    if (names != NULL && (name = names[index]) != NULL) {
        cap.name = name;
        cap.model_out = (NJS_OBJECT **)&inputs.part_models[1];
        cap.load_slot = inputs.load_slot;
        cap.completion_mask = 8;
        cap.completion_flags = inputs.completion_flags;
        if (create_ch_cr_load_gm_nj_req(this, &cap) == NULL) return;
    } else {
        *inputs.completion_flags &= ~8;
    }
    inputs.part_models[0] = 0;
    names = class_appearance->hairModels;
    if (names != NULL && (name = names[index]) != NULL) {
        hair.name = name;
        hair.model_out = (NJS_OBJECT **)&inputs.part_models[0];
        hair.load_slot = inputs.load_slot;
        hair.completion_mask = 0x10;
        hair.completion_flags = inputs.completion_flags;
        if (create_ch_cr_load_gm_nj_req(this, &hair) == NULL) return;
    } else {
        *inputs.completion_flags &= ~0x10;
    }
    inputs.part_models[2] = 0;
    head.name = class_appearance->headModels[inputs.appearance->head];
    head.model_out = (NJS_OBJECT **)&inputs.part_models[2];
    head.load_slot = inputs.load_slot;
    head.completion_mask = 0x20;
    head.completion_flags = inputs.completion_flags;
    if (create_ch_cr_load_gm_nj_req(this, &head) == NULL) return;
}

void TChCrLoadReq::request_texture_loads() {
    TChCrLoadAfsTextureReqArgs body;
    TChCrLoadAfsTextureReqArgs head;
    TChCrLoadAfsTextureReqArgs other;
    s32 display = character_display_index(reinterpret_cast<uaddr>(inputs.appearance));

    body.textures = inputs.body_textures;
    body.completion_mask = 4;
    body.completion_flags = (s32 *)inputs.completion_flags;
    body.display_index = display;
    if (TChCrLoadAfsTextureReq::create(this, &body) == NULL) {
        return;
    }
    if (class_appearance->hairModels != NULL || class_appearance->capModels != NULL) {
        head.textures = inputs.head_textures;
        head.completion_mask = 1;
        head.completion_flags = (s32 *)inputs.completion_flags;
        head.display_index = display;
        if (TChCrLoadAfsTextureReq::create(this, &head) == NULL) {
            return;
        }
    } else {
        *inputs.completion_flags &= ~1;
    }
    other.textures = inputs.other_textures;
    other.completion_mask = 2;
    other.completion_flags = (s32 *)inputs.completion_flags;
    other.display_index = display;
    if (TChCrLoadAfsTextureReq::create(this, &other) == NULL) {
        return;
    }
}

void TChCrLoadReq::start_preview_loads() {
    s32 disp;
    s32 i;
    s32 id;
    TChCrLoadAfs *load;
    get_sorted_character_proportion_samples(reinterpret_cast<const f32 *>(&inputs.appearance->width), sample_indices);
    disp = character_display_index(reinterpret_cast<uaddr>(inputs.appearance));
    for (i = 0; i < 3; i++) {
        id = sample_indices[i];
        load = TChCrLoadAfs::create(this, 0xDB, calc_preview_offset(disp, inputs.appearance->head, id));
        sample_loads[i] = load;
        if (load == NULL) {
            break;
        }
        sample_loads[i + 3] = TChCrLoadAfs::create(this, 0xDB, calc_preview_last_index(disp, id));
    }
}

void TChCrLoadReq::load_preview_models() {
    u32 len;
    u32 tag;
    uaddr bufs[6];
    CharacterPreviewModels models;
    s32 i;
    s32 j;
    uaddr p;
    for (i = 0; i < 6; i++) {
        len = 0;
        p = (uaddr)TLobby__sub_801E38A0(static_cast<const u8 *>(sample_loads[i]->get_load_buffer()), &len, &tag, NULL, NULL);
        if (p == 0 || tag != 0x4E4A544C) return;
        safe_free(reinterpret_cast<void *>(p));
        bufs[i] = (uaddr)TLobby__sub_801E38A0(static_cast<const u8 *>(sample_loads[i]->get_load_buffer()), &len, &tag, NULL, NULL);
        if (bufs[i] == 0 || tag != 0x4E4A434D) {
            for (i = 0; i < 6; i++) safe_free(reinterpret_cast<void *>(bufs[i]));
            return;
        }
        if (is_node_tree_valid(reinterpret_cast<NJS_OBJECT *>(bufs[i])) == 0) {
            for (i = 0; i < 6; i++) safe_free(reinterpret_cast<void *>(bufs[i]));
            return;
        }
    }
    models.appearance = inputs.appearance;
    models.head = reinterpret_cast<NJS_OBJECT *>(*head_model);
    models.body = reinterpret_cast<NJS_OBJECT *>(*inputs.body_model);
    for (i = 0; i < 3; i++) {
        models.sample_indices[i] = sample_indices[i];
        models.head_samples[i] = reinterpret_cast<NJS_OBJECT *>(bufs[i]);
        models.body_samples[i] = reinterpret_cast<NJS_OBJECT *>(bufs[i + 3]);
    }
    bind_character_preview_models(&models);
    blend_creation_proportion_shapes(&inputs.appearance->width);
    for (j = 0; j < 6; j++) safe_free(reinterpret_cast<void *>(bufs[j]));
}

s32 TChCrLoadReq::completion_flags_clear() {
    return (*inputs.completion_flags & 0x7F) == 0 ? 1 : 0;
}

s32 TChCrLoadReq::all_preview_loads_complete() {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (sample_loads[i]->is_load_complete() == 0) return 0;
    }
    return 1;
}

// Preview model index tables, one entry per display class; the base offset of each class is the
// previous one plus 7 strides.
s32 chr_select_preview_stride_table[19] = {
    2, 2, 6, 2, 6, 6, 2, 2, 2, 6, 2, 2, 2, 2, 2, 2, 2, 2, 2,
};

s32 chr_select_preview_base_offset_table[19] = {
    0x0, 0xE, 0x1C, 0x46, 0x54, 0x7E, 0xA8, 0xB6, 0xC4, 0xD2,
    0xFC, 0x10A, 0x118, 0x126, 0x134, 0x142, 0x150, 0x15E, 0x16C,
};

