#include "types.h"
#include "pso/unk/text_80327844.h"
#include "pso/system/memory.h"
#include "pso/system/scene/TScene.h"

struct Pt_80327B40 { s16 x, y; };

struct Mesh_80327B40 { u16 pad0; u16 n; u8 pad4[4]; Pt_80327B40 *pts; };

struct Entry_80327B40 { Mesh_80327B40 *mesh; Pt_80327B40 *src; };

struct Scene_80327B40 { u8 pad0[4]; s32 count; Entry_80327B40 *entries; };

extern "C" {
void DCFlushRangeNoSync(void *, u32);
void *mem_alloc(u32 size);
s32 visit_model_tree_recursive();
void mem_free(void *p);

void TScene::offset_position(s32 arg1, s32 arg2) {
    *(s16 *)&this->m_up = (s16) (*(s16 *)&this->m_up + arg1);
    *(s16 *)((s8 *)this + 0x12) = (s16) (*(s16 *)((s8 *)this + 0x12) + arg2);
    apply_uv_offset((s16)(*(s16 *)&this->m_up), (s16)(*(s16 *)((s8 *)this + 0x12)));
}

void TScene::apply_uv_offset(s16 arg1, s16 arg2) {
    Scene_80327B40 *scene = (Scene_80327B40 *)this;
    s16 dx = arg1 % 256;
    s16 dy = arg2 % 256;
    s32 i;
    for (i = 0; i < scene->count; i++) {
        Mesh_80327B40 *m = scene->entries[i].mesh;
        Pt_80327B40 *src = scene->entries[i].src;
        Pt_80327B40 *dst = m->pts;
        s32 j;
        for (j = 0; j < m->n; j++) {
            dst->x = src->x + dx;
            dst->y = src->y + dy;
            src++;
            dst++;
        }
        DCFlushRangeNoSync(m->pts, m->n * 4);
    }
}

void *TScene::destroy_buffers(s16 arg1) {
    if (this != NULL) {
        if ((u32) this->m_next != 0U) {
            mem_free(this->m_next);
            this->m_next = 0U;
        }
        if ((u32) this->m_prev != 0U) {
            mem_free(this->m_prev);
            this->m_prev = 0U;
        }
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

extern s32 scroll_uv_entry_write_cursor;
extern s32 scroll_uv_coordinate_write_cursor;

void *TScene::init_buffers(s32 arg1, s32 arg2) {
    s32 temp_r0;

    *(s32 *)&this->m_flags = 0;
    *(s32 *)&this->m_name = 0;
    visit_model_tree_recursive();
    *(s32 *)&this->m_prev = 0;
    *(s32 *)&this->m_next = 0;
    temp_r0 = *(s32 *)&this->m_flags;
    if (temp_r0 > 0) {
        *(s32 *)&this->m_prev = (s32)mem_alloc(temp_r0 * 8);
        *(s32 *)&this->m_next = (s32)mem_alloc(*(s32 *)&this->m_name * 4);
        scroll_uv_entry_write_cursor = *(s32 *)&this->m_prev;
        scroll_uv_coordinate_write_cursor = *(s32 *)&this->m_next;
        visit_matching_models((s32)this, (u8 *)arg1, arg2);
    }
    *(s16 *)&this->m_up = 0;
    *(s16 *)((s8 *)this + 0x12) = 0;
    return this;
}

}
