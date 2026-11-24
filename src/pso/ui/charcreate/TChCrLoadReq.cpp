#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028C8E0.h"
#include "pso/ui/charcreate/TChCrLoadReq.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/CharacterLoadBuffer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

// Built with -inline off,deferred: .text comes out last function first, so the functions are
// written in reverse address order; the data (the node range statics, then the load slot count,
// then run_task's table, then the preview tables) stays in source order.

#pragma push
#pragma readonly_strings on
const char *TChCrLoadReq__name = "TChCrLoadReq";
#pragma pop

extern "C" {
}

// A node tree is valid when no node, child, sibling or model pointer lies in the low 2 MB.
extern "C" s32 is_node_tree_valid(NJS_OBJECT *object) {
    if (object->evalflags & 0xFFFFE000) {
        return 0;
    }
    static NJS_OBJECT *node_tree_range_start = (NJS_OBJECT *)0x0;
    static NJS_OBJECT *node_tree_range_end = (NJS_OBJECT *)0x200000;  // inferred: pairs with node_tree_range_start
    static void *model_range_start = (void *)0x0;  // inferred: bound for the node's model pointer
    static void *model_range_end = (void *)0x200000;  // inferred: bound for the node's model pointer
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
    m_name = TChCrLoadReq__name;
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
    m_name = TChCrLoadReq__name;
    inputs.copy_from(args);
    reset_request();
}

void TChCrLoadReq::reset_request() {
    s32 i;
    s32 index;
    m_58 = inputs.part_models + 2;
    index = character_display_index(reinterpret_cast<uaddr>(inputs.appearance));
    m_5c = &class_appearance_table[index];
    reset_character_load_buffer(inputs.load_slot);
    inputs.body_model[0] = 0;
    inputs.part_models[1] = 0;
    inputs.part_models[0] = 0;
    inputs.part_models[2] = 0;
    for (i = 0; i < 6; i++) {
        m_74[i] = 0;
    }
    m_8c = 0;
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
        if (TAdSinglePlyChrSelectGC__sub_8028CF6C() == 0) {
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

// Preview model index tables, one entry per display class; the base offset of each class is the
// previous one plus 7 strides. They sit after run_task's table in this TU's .data; their users
// (calc_preview_last_index, calc_preview_offset) are still in TAdSinglePlyChrSelectGC_8028C8E0.cpp.
s32 chr_select_preview_stride_table[19] = {
    2, 2, 6, 2, 6, 6, 2, 2, 2, 6, 2, 2, 2, 2, 2, 2, 2, 2, 2,
};

s32 chr_select_preview_base_offset_table[19] = {
    0x0, 0xE, 0x1C, 0x46, 0x54, 0x7E, 0xA8, 0xB6, 0xC4, 0xD2,
    0xFC, 0x10A, 0x118, 0x126, 0x134, 0x142, 0x150, 0x15E, 0x16C,
};
