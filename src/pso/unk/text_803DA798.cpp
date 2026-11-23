#include "types.h"

#include <stddef.h>
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/unk/text_803DA798.h"
#include <dolphin/os/OSCache.h>
// Buffered chunk head: byte size at 0x14, data base address at 0x1C.
struct ChunkedBufferHead {
    u8 unknown_0[0x14];
    u32 bufferSize;
    u8 unknown_18[0x4];
    saddr bufferBase;
};

// Process-wide texture load status: failedIndex + resultCode (see text_803DD5E0 loaders).
struct GvmLoadStatus { s32 failedIndex, b, resultCode, d, e; };

// Chunk descriptor: fc+4 feeds the active address, f8 the active size (set_texture_num).
struct TexChunkDesc { u8 pad[8]; s32 f8; s32 fc; };

struct TexChunkSlot { s32 a; s32 b; TexChunkDesc *p; };

struct TexChunkTable { TexChunkSlot *arr; };

// current_render_context view: active chunk address f8, size f18, chunk table f20.
struct RenderTexContext { u8 pad[8]; s32 f8; u8 pad2[0xc]; s32 f18; u8 pad3[4]; TexChunkTable *f20; };

struct GvmTexRecord { u8 pad[0x18]; };

struct GvmTexRefSlot { s32 a; s32 b; GvmTexRecord *p; };

struct GvmTexRefArray { GvmTexRefSlot *arr; };

struct TexLoadBufferEntry { u32 a; u32 b; u32 c; u8 *d; u32 e; u32 f; };

struct TexLoadTargetData {
    u8 pad[0x1C];
    u32 flags;
};

struct TexLoadTarget {
    u8 pad[0xC];
    struct TexLoadTargetData *inner;
};

// Refcount owner inside record_array_ptr; refs pairs with PlayerRefRecord.cnt.
struct PlayerRefObject { u8 pad[0x24]; s32 refs; };

struct PlayerRefRecord { u32 a; u32 b; u32 recordId; PlayerRefObject *obj; s32 cnt; s32 v14; };

struct TexLoadSlotRef { u32 a; u32 b; TexLoadTarget *c; };

extern saddr record_array_ptr;
extern "C" {
s32 fn_803DB20C(void *);
s32 TObjPlayer__sub_803DAD28(u32 arg0);
extern GvmLoadStatus lbl_8058D470;
void TObjPlayer__sub_803DAB7C(GvmTexRefArray *self, s32 i, s32 j);
s32 TObjPlayer__sub_803DAB9C(s32 arg0, s32 arg1);
s32 TObjPlayer__sub_803DB23C(void *);
s32 TObjPlayer__sub_803DB244(void);
s32 TObjPlayer__sub_803DAD84(struct TexLoadTarget *arg0, s32 arg1, u32 arg2);
s32 TObjPlayer__sub_803DA104(int);
void TObjPlayer__sub_803DAD24(void);
s32 TObjPlayer__sub_803DA8E4(u32 arg0, u32 arg1, s32 arg2, s32 *arg3);
s32 TObjPlayer__sub_803D9DA8(int, void *);
extern s32 player_ref_entry_active_count;
s32 TObjPlayer__sub_803DAA70(u32 arg0, u32 arg1, s32 *arg2);
s32 TObjPlayer__sub_803DAC48(GvmTexRefArray *arg0, s32 arg1, u32 arg2, u32 arg3, s32 *arg4, s32 *arg5);
s32 TObjPlayer__sub_803DAE1C(s32 arg0, s32 arg1, u32 arg2);
s32 TObjFish::set_global_param(GinjaTextureList *texlist) {
    current_render_context->textures = texlist;
    return 1;
}
}
s32 set_texture_num(s32 i);
#pragma push
#pragma opt_common_subs off
#pragma scheduling off
#pragma peephole off
LAYOUT_ASSERT(ChunkedBufferHead_size_offset, offsetof(ChunkedBufferHead, bufferSize) == 0x14);
LAYOUT_ASSERT(ChunkedBufferHead_base_offset, offsetof(ChunkedBufferHead, bufferBase) == 0x1C);

#pragma push
#pragma scheduling off
#pragma peephole off
s32 set_texture_num(s32 i) {
    TexChunkDesc *o = ((RenderTexContext *)current_render_context)->f20->arr[i].p;
    ((RenderTexContext *)current_render_context)->f8 = o->fc + 4;
    ((RenderTexContext *)current_render_context)->f18 = o->f8;
    return 1;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off

void TObjPlayer__sub_803DA7E0(void) {
    lbl_8058D470.failedIndex = -1;
    lbl_8058D470.b = -1;
    lbl_8058D470.resultCode = 0;
    lbl_8058D470.d = 0;
    lbl_8058D470.e = 0;
}
#pragma pop

void TObjPlayer__sub_803DA808(void *buf, saddr src, u32 size) {
    move_data(buf, (const void *)src, size);
    DCFlushRange(buf, size);
}

s32 TObjPlayer__sub_803DA84C(u8 *head, s32 src, s32 offsetRaw, s32 lengthRaw) {
    u32 remaining;
    u32 copyMax;
    u32 copyStart;
    uaddr copyLen;
    copyStart = offsetRaw & 0xFFFFFFFC;
    copyMax = lengthRaw & 0xFFFFFFFC;
    if (copyMax == 0) {
        return 0;
    }
    remaining = ((ChunkedBufferHead *)head)->bufferSize;
    copyLen = remaining - copyStart;
    if (copyStart >= remaining) {
        return 7;
    }
    if (copyLen > copyMax) {
        copyLen = copyMax;
    }
    TObjPlayer__sub_803DA808((void *)(copyStart + ((ChunkedBufferHead *)head)->bufferBase), src, copyLen);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
s32 TObjPlayer__sub_803DA8B4(u8 *arg0, s32 src) {
    TObjPlayer__sub_803DA808((void *)*(saddr *)((s8 *)arg0 + 0x1C), src, *(u32 *)((s8 *)arg0 + 0x14));
    return 0;
}
#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
s32 TObjPlayer__sub_803DA8E4(u32 arg0, u32 arg1, s32 arg2, s32 *arg3) {
    PlayerRefRecord *rec;
    s32 idx;
    s32 r;
    s32 slot;
    idx = TObjPlayer::find_table_index_by_id(arg0);
    if (TObjPlayer__sub_803DA104(arg2) != 0) {
        if (idx < 0) {
            *arg3 = -1;
            return 0;
        }
        r = TObjPlayer::find_record_index(arg0, arg1);
        if (r < 0) {
            slot = TObjPlayer::find_free_slot(&rec, NULL);
            if (slot < 0) {
                return -1;
            }
            rec->recordId = arg1;
            rec->obj = (*(PlayerRefRecord **)&record_array_ptr)[idx].obj;
            rec->obj->refs++;
            rec->cnt = 1;
            rec->v14 = (*(PlayerRefRecord **)&record_array_ptr)[idx].v14;
            ((void (*)(PlayerRefRecord *)) TObjPlayer__sub_803DAD24)(rec);
            *arg3 = slot;
            return 1;
        }
        *arg3 = r;
        (*(PlayerRefRecord **)&record_array_ptr)[r].cnt++;
        (*(PlayerRefRecord **)&record_array_ptr)[r].obj->refs++;
        return 1;
    }
    *arg3 = idx;
    if (idx < 0) {
        return 0;
    }
    (*(PlayerRefRecord **)&record_array_ptr)[idx].cnt++;
    (*(PlayerRefRecord **)&record_array_ptr)[idx].obj->refs++;
    return 1;
}
#pragma pop

s32 TObjPlayer__sub_803DAA70(u32 arg0, u32 arg1, s32 *arg2) {
    u8 *entry;
    s32 *rec;
    s32 slotIdx;
    slotIdx = TObjPlayer::find_free_slot(&entry, &rec);
    if (slotIdx < 0) {
        return -1;
    }
    *(s32 **)((s8 *)entry + 0xC) = rec;
    if (TObjPlayer__sub_803D9DA8((saddr)entry, (void *)arg2) != 1) {
        *(s32 **)((s8 *)entry + 0xC) = NULL;
        return -1;
    }
    if ((u32) arg0 != 0xFFFFFFFFU) {
        *(s32 *)((s8 *)(*(s32 **)((s8 *)entry + 0xC)) + 0) = arg0;
    }
    if (TObjPlayer__sub_803DA104((int) (*(s32 *)((s8 *)arg2 + 0))) != 0) {
        *(s32 *)((s8 *)entry + 8) = arg1;
    } else {
        *(s32 *)((s8 *)entry + 8) = -1;
    }
    ((void (*)(u8 *)) TObjPlayer__sub_803DAD24)(entry);
    *(s32 *)((s8 *)entry + 0x10) = 1;
    *(s32 *)((s8 *)(*(s32 **)((s8 *)entry + 0xC)) + 0x24) = 1;
    player_ref_entry_active_count += 1;
    return slotIdx;
}

#pragma push
#pragma scheduling off
#pragma peephole off
void TObjPlayer__sub_803DAB7C(GvmTexRefArray *self, s32 i, s32 j) {
    self->arr[i].p = (GvmTexRecord *)record_array_ptr + j;
}
#pragma pop

s32 TObjPlayer__sub_803DAB9C(s32 handle, s32 arg1) {
    u8 *p = (*(TexLoadBufferEntry * *)&record_array_ptr)[handle].d;
    if (p == 0) {
        ((s32 *)&lbl_8058D470)[2] = 1;
        return -1;
    }
    if (TObjPlayer__sub_803DA84C(p + 4, arg1, 0, *(s32 *)(p + 0x18)) != 0) {
        ((s32 *)&lbl_8058D470)[2] = 8;
        return -1;
    }
    return 1;
}

#pragma push
#pragma scheduling off
void TObjPlayer__sub_803DAC1C(s32 handle) {
    TObjPlayer__sub_803DAE98(&((GinjaTextureState *)record_array_ptr)[handle]);
}
#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
s32 TObjPlayer__sub_803DAC48(GvmTexRefArray *list, s32 i, u32 arg2, u32 arg3, s32 *arg4, s32 *arg5) {
    switch (TObjPlayer__sub_803DA8E4(arg2, arg3, *arg4, arg5)) {
    case -1:
        return -1;
    case 0:
        *arg5 = TObjPlayer__sub_803DAA70(arg2, arg3, arg4);
        if (*arg5 < 0) {
            return -1;
        }
        TObjPlayer__sub_803DAB7C(list, i, *arg5);
        return 0;
    case 1:
        TObjPlayer__sub_803DAB7C(list, i, *arg5);
        return 1;
    }
    return 0;
}
#pragma pop

void TObjPlayer__sub_803DAD24(void) {

}

#pragma push
#pragma scheduling off
s32 TObjPlayer__sub_803DAD28(u32 arg0) {
    s32 temp_r0;
    s32 table_index;
    u8 *var_r3;
    u8 *var_r4;
    table_index = TObjPlayer::find_table_index_by_id(arg0);
    if (table_index < 0) {
        var_r3 = (u8 *)((void *)-1);
        return -1;
    }
    var_r4 = (u8 *)((*(u8 * *)&record_array_ptr));
    var_r4 += table_index * 0x18;
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r4 + 0xC));
    temp_r0 = (long) (var_r3 + 4);
    var_r3 = reinterpret_cast<u8 *>(current_render_context);
    *(s32 *)((s8 *)var_r3 + 8) = temp_r0;
    var_r3 = reinterpret_cast<u8 *>(current_render_context);
    *(s32 *)((s8 *)var_r3 + 0x18) = (s32) *(s32 *)((s8 *)var_r4 + 8);
    var_r3 = (u8 *)((void *)1);
    return 1;
}
#pragma pop

s32 TObjPlayer__sub_803DAD84(struct TexLoadTarget *arg0, s32 size, u32 arg2) {
    struct TexLoadTargetData *p = arg0->inner;
    if ((p->flags & 0x80000000) != 0 && arg2 != 0) {
        if (TObjPlayer__sub_803DB23C((u8 *)p + 4) != 0) {
            lbl_8058D470.resultCode = 8;
            return -1;
        }
    } else {
        if (((s32 (*)(u8 *))TObjPlayer__sub_803DA8B4)((u8 *)p + 4) != 0) {
            lbl_8058D470.resultCode = 8;
            return -1;
        }
    }
    while (TObjPlayer__sub_803DB244() != 0) {
    }
    return 1;
}

struct TexLoadTarget;
s32 TObjPlayer__sub_803DAE1C(s32 arg0, s32 size, u32 arg2) {
    TObjPlayer__sub_803DA7E0();
    s32 r = TObjPlayer__sub_803DAD84((**(TexLoadSlotRef ***)(&current_render_context->textures))[arg0].c, size, arg2);
    if (r < 0) {
        lbl_8058D470.failedIndex = arg0;
    }
    return r;
}

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
#pragma peephole off
#pragma scheduling off
s32 TObjPlayer__sub_803DAE98(GinjaTextureState *texture) {
    GinjaSurfaceState *surface;
    if (texture->surface == NULL) {
        return -1;
    }
    if (texture->ref_count > 0) {
        texture->ref_count--;
    }
    surface = texture->surface;
    if (surface->ref_count > 0) {
        surface->ref_count--;
        if (texture->surface->ref_count == 0) {
            fn_803DB20C(&texture->surface->header.format);
            *(s32 *)((s8 *)current_render_context + 0x14) = -1;
        }
    }
    ((TObjPlayer *)texture)->release_empty_ref_entry();
    return 1;
}
#pragma pop
