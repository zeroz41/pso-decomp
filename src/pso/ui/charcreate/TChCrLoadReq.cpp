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
#include "pso/unk/TLobby_8028D714.h"

// Built with -inline off,deferred: .text comes out last function first, so the functions are
// written in reverse address order; the data (the node range statics, then the load slot count,
// then run_task's table, then the preview tables) stays in source order.

#pragma push
#pragma readonly_strings on
const char *TChCrLoadReq__name = "TChCrLoadReq";
#pragma pop

extern "C" {
u16 get_entity_id(void *);
extern s32 __vt__12TChCrLoadReq[];
void sub_8028CEEC__12TChCrLoadReqFPl(TChCrLoadReq *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
}
void * create_ch_cr_load_req(void *arg0, void *arg1);

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

void *create_ch_cr_load_req(void *parent, void *arg1) {
    return new TChCrLoadReq((TObject *)parent, arg1);
}

// TObjPlayer has no fields yet at 0xCF4, 0xB88 and 0xA1C.
TChCrLoadReq::TChCrLoadReq(TObjPlayer *player) : TObject(player) {
    m_name = TChCrLoadReq__name;
    m_38 = (CharacterAppearanceFields *)player->name;
    m_3c = (u32 *)&player->m_cfc;
    m_40 = get_entity_id(player);
    m_44 = (s32 *)&player->model;
    m_48 = (s32 *)&player->m_8ac;
    m_4c = (u8 *)player + 0xCF4;
    m_50 = (u8 *)player + 0xB88;
    m_54 = (u8 *)player + 0xA1C;
    reset_request();
}

void TChCrLoadReq::copy(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); *(u32 *)&this->m_flags = *(u32*)((char*)q + 0x4); *(u32 *)&this->m_prev = *(u32*)((char*)q + 0x8); *(u32 *)&this->m_next = *(u32*)((char*)q + 0xc); *(u32 *)&this->m_up = *(u32*)((char*)q + 0x10); *(u32 *)&this->m_down = *(u32*)((char*)q + 0x14); *(u32*)((char*)this + 0x18) = *(u32*)((char*)q + 0x18); *(u32*)((char*)this + 0x1c) = *(u32*)((char*)q + 0x1c); }

TChCrLoadReq::TChCrLoadReq(TObject *object, void *arg2) : TObject(object) {
    m_name = TChCrLoadReq__name;
    ((TChCrLoadReq *)((char *)this + 56))->copy(arg2);
    this->reset_request();
}

void TChCrLoadReq::reset_request() {
    s32 i;
    s32 index;
    m_58 = m_48 + 2;
    index = ((TCharaMaking *)m_38)->get_display_index();
    m_5c = &class_appearance_table[index];
    TLobby__sub_8028D738(m_40);
    m_44[0] = 0;
    m_48[1] = 0;
    m_48[0] = 0;
    m_48[2] = 0;
    for (i = 0; i < 6; i++) {
        m_74[i] = 0;
    }
    m_8c = 0;
    timer = 0x1518;
    state = 0;
}

extern "C" TChCrLoadReq *__dt__12TChCrLoadReqFv(TChCrLoadReq *req, s16 free) {
    if (req != NULL) {
        *(s32 **)((u8 *)req + 0x18) = __vt__12TChCrLoadReq;
        sub_8028CEEC__12TChCrLoadReqFPl(req);
        __dt__7TObjectFv(req, 0);
        if (free > 0) {
            __dl__7TObjectFPv(req);
        }
    }
    return req;
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
        if (((TAdSinglePlyChrSelectGC *)this)->try_claim_load_slot() != 0) {
            ((TAdSinglePlyChrSelectGC *)this)->request_model_loads();
            ((TAdSinglePlyChrSelectGC *)this)->request_texture_loads();
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
