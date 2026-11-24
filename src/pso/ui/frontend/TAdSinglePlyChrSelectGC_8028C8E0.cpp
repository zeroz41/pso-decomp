#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "types.h"
#include "pso/ui/charcreate/CharacterPreviewModels.h"
#include "pso/ui/charcreate/TChCrLoadAfsTextureReq.h"
#include "pso/ui/charcreate/TChCrLoadGmNjReq.h"
#include "pso/system/NinjaChunk.h"
#include "pso/ui/charcreate/CharacterLoadBuffer.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028C8E0.h"
#include "pso/ui/charcreate/TChCrLoadReq.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/TChCrLoadAfs.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/system/task/TObject.h"

s32 chr_select_slot_state;

void TChCrLoadGmNjReq::sub_8028C8A8() {
    if (chr_select_slot_state < 0 || chr_select_slot_state > 1) return;
    if (slot_claimed == 0) return;
    chr_select_slot_state--;
    slot_claimed = 0;
}

extern "C" {
s32 is_node_tree_valid(u32, s32);
void blend_creation_proportion_shapes(f32 *point);
extern s32 chr_select_preview_stride_table[];
extern s32 chr_select_preview_base_offset_table[];


s32 TChCrLoadGmNjReq::try_acquire_slot() {
    if (((s32) chr_select_slot_state < 0) || ((s32) chr_select_slot_state > 1)) {
        return 0;
    }
    if (slot_claimed != 0) {
        return 0;
    }
    if ((s32) chr_select_slot_state >= 1) {
        return 0;
    }
    chr_select_slot_state += 1;
    slot_claimed = 1;
    return 1;
}

s32 TChCrLoadReq::all_preview_loads_complete() {
    u8 *object = (u8 *)this;
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    do {
        if ((*(TChCrLoadAfs **)(object + offsetof(TChCrLoadReq, m_74) + off))->is_load_complete() == 0) return 0;
        i++;
        off += sizeof(TChCrLoadAfs *);
    } while (i < 6);
    return 1;
}

s32 TAdSinglePlyChrSelectGC__sub_8028C998(void *arg0) {
    return (u32) __cntlzw((u32) (**(s32 **)((s8 *)arg0 + 0x3C) & 0x7F)) >> 5;
}

extern s32 chr_select_load_slot_count;

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
        p = (uaddr)TLobby__sub_801E38A0(static_cast<const u8 *>(m_74[i]->get_load_buffer()), &len, &tag, NULL, NULL);
        if (p == 0 || tag != 0x4E4A544C) return;
        safe_free(reinterpret_cast<void *>(p));
        bufs[i] = (uaddr)TLobby__sub_801E38A0(static_cast<const u8 *>(m_74[i]->get_load_buffer()), &len, &tag, NULL, NULL);
        if (bufs[i] == 0 || tag != 0x4E4A434D) {
            for (i = 0; i < 6; i++) safe_free(reinterpret_cast<void *>(bufs[i]));
            return;
        }
        if (is_node_tree_valid(bufs[i], tag) == 0) {
            for (i = 0; i < 6; i++) safe_free(reinterpret_cast<void *>(bufs[i]));
            return;
        }
    }
    models.appearance = inputs.appearance;
    models.head = reinterpret_cast<NJS_OBJECT *>(*m_58);
    models.body = reinterpret_cast<NJS_OBJECT *>(*inputs.body_model);
    for (i = 0; i < 3; i++) {
        models.sample_indices[i] = m_68[i];
        models.head_samples[i] = reinterpret_cast<NJS_OBJECT *>(bufs[i]);
        models.body_samples[i] = reinterpret_cast<NJS_OBJECT *>(bufs[i + 3]);
    }
    bind_character_preview_models(&models);
    blend_creation_proportion_shapes((f32 *)(&inputs.appearance->width));
    for (j = 0; j < 6; j++) safe_free(reinterpret_cast<void *>(bufs[j]));
}

void TChCrLoadReq::start_preview_loads() {
    s32 off;
    u8 *entry;
    s32 disp;
    s32 i;
    s32 id;
    TChCrLoadAfs *load;
    get_sorted_character_proportion_samples(reinterpret_cast<const f32 *>(&inputs.appearance->width), m_68);
    disp = character_display_index(reinterpret_cast<uaddr>(inputs.appearance));
    for (i = 0, off = 0; i < 3; i++, off += 4) {
        entry = (u8 *)this + off;
        id = *(s32 *)(entry + offsetof(TChCrLoadReq, m_68));
        load = TChCrLoadAfs::create(this, 0xDB,
            calc_preview_offset(disp, inputs.appearance->head, id));
        *(TChCrLoadAfs **)(entry + offsetof(TChCrLoadReq, m_74)) = load;
        if (load == NULL) {
            break;
        }
        *(TChCrLoadAfs **)(entry + offsetof(TChCrLoadReq, m_74) + 3 * sizeof(TChCrLoadAfs *)) =
            TChCrLoadAfs::create(this, 0xDB, calc_preview_last_index(disp, id));
    }
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
    if (m_5c->hairModels != NULL || m_5c->capModels != NULL) {
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
    body.name = m_5c->bodyModel;
    body.model_out = (NJS_OBJECT **)inputs.body_model;
    body.load_slot = inputs.load_slot;
    body.completion_mask = 0x40;
    body.completion_flags = inputs.completion_flags;
    if (create_ch_cr_load_gm_nj_req(this, &body) == NULL) return;
    index = inputs.appearance->hair;
    inputs.part_models[1] = 0;
    names = m_5c->capModels;
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
    names = m_5c->hairModels;
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
    head.name = m_5c->headModels[inputs.appearance->head];
    head.model_out = (NJS_OBJECT **)&inputs.part_models[2];
    head.load_slot = inputs.load_slot;
    head.completion_mask = 0x20;
    head.completion_flags = inputs.completion_flags;
    if (create_ch_cr_load_gm_nj_req(this, &head) == NULL) return;
}

void TChCrLoadReq::release_load_slot() {
    if (((s32) chr_select_load_slot_count <= 1) && ((s32) this->m_8c != 0)) {
        this->m_8c = 0;
        if (--chr_select_load_slot_count == 0) {
            return;
        }
    }
}

s32 TChCrLoadReq::try_claim_load_slot() {
    if (((s32) m_8c != 0) || ((s32) chr_select_load_slot_count < 0) || ((s32) chr_select_load_slot_count > 1)) {
        return 0;
    }
    if ((s32) chr_select_load_slot_count >= 1) {
        return 0;
    }
    m_8c = 1;
    chr_select_load_slot_count += 1;
    return 1;
}

s32 TAdSinglePlyChrSelectGC__sub_8028CF6C(void) {
    return chr_select_load_slot_count < 1;
}

}

saddr TChCrLoadReq::calc_preview_last_index(s32 display_index, s32 region_index) {
    s32 stride=chr_select_preview_stride_table[display_index];
    return stride + region_index * stride - 1 + chr_select_preview_base_offset_table[display_index];
}

saddr TChCrLoadReq::calc_preview_offset(s32 display_index, s32 head, s32 region_index) {
    return head + (region_index * chr_select_preview_stride_table[display_index] + chr_select_preview_base_offset_table[display_index]);
}

void TChCrLoadReq::close_and_destroy() {
    if (all_preview_loads_complete()) {
        load_preview_models();
        *inputs.completion_flags &= 0xFFFFFF7F;
        release_load_slot();
        queue_destruction();
    }
}

void TChCrLoadReq::try_advance_state() {
    if (TAdSinglePlyChrSelectGC__sub_8028C998(this) != 0) {
        start_preview_loads();
        state = 2;
    }
}
