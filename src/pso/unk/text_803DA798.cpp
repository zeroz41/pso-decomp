#include "types.h"

#include <stddef.h>
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/unk/text_803DA798.h"
#include "pso/unk/text_803DAFA8.h"
#include <dolphin/os/OSCache.h>
extern "C" {
s32 TObjPlayer__sub_803DB23C(GinjaTextureHeader *header);
s32 TObjPlayer__sub_803DB244(void);
s32 TObjPlayer__sub_803DA104(int format);
s32 TObjPlayer__sub_803D9DA8(GinjaTextureState *texture, GvrTextureDesc *desc);
}

s32 TObjFish::set_global_param(NJS_TEXLIST *texlist) {
    current_render_context->textures = texlist;
    return 1;
}

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
#pragma peephole off

#pragma push
#pragma scheduling off
#pragma peephole off
s32 set_texture_num(s32 i) {
    GinjaTextureState *texture = current_render_context->textures->textures[i].texture;
    current_render_context->texture_header = &texture->surface->header;
    current_render_context->tlut_name = texture->tlut_name;
    return 1;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off

void reset_texture_error(void) {
    lbl_8058D470.entry_index = -1;
    lbl_8058D470.pad_04 = -1;
    lbl_8058D470.code = 0;
    lbl_8058D470.pad_0C = 0;
    lbl_8058D470.pad_10 = 0;
}
#pragma pop

void TObjPlayer__sub_803DA808(void *buf, saddr src, u32 size) {
    move_data(buf, (const void *)src, size);
    DCFlushRange(buf, size);
}

s32 TObjPlayer__sub_803DA84C(GinjaTextureHeader *header, s32 src, s32 offsetRaw, s32 lengthRaw) {
    u32 remaining;
    u32 copyMax;
    u32 copyStart;
    uaddr copyLen;
    copyStart = offsetRaw & 0xFFFFFFFC;
    copyMax = lengthRaw & 0xFFFFFFFC;
    if (copyMax == 0) {
        return 0;
    }
    remaining = header->size;
    copyLen = remaining - copyStart;
    if (copyStart >= remaining) {
        return 7;
    }
    if (copyLen > copyMax) {
        copyLen = copyMax;
    }
    TObjPlayer__sub_803DA808((void *)(copyStart + (uaddr)header->pixels), src, copyLen);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
s32 TObjPlayer__sub_803DA8B4(GinjaTextureHeader *header, s32 src) {
    TObjPlayer__sub_803DA808(header->pixels, src, header->size);
    return 0;
}
#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
s32 TObjPlayer__sub_803DA8E4(u32 id, u32 tlut_name, s32 format, s32 *slot_out) {
    GinjaTextureState *texture;
    s32 index;
    s32 shared;
    s32 slot;
    index = TObjPlayer::find_table_index_by_id(id);
    if (TObjPlayer__sub_803DA104(format) != 0) {
        if (index < 0) {
            *slot_out = -1;
            return 0;
        }
        shared = TObjPlayer::find_record_index(id, tlut_name);
        if (shared < 0) {
            slot = TObjPlayer::find_free_slot(&texture, NULL);
            if (slot < 0) {
                return -1;
            }
            texture->tlut_name = tlut_name;
            texture->surface = record_array_ptr[index].surface;
            texture->surface->ref_count++;
            texture->ref_count = 1;
            texture->reserved14 = record_array_ptr[index].reserved14;
            TObjPlayer__sub_803DAD24(texture);
            *slot_out = slot;
            return 1;
        }
        *slot_out = shared;
        record_array_ptr[shared].ref_count++;
        record_array_ptr[shared].surface->ref_count++;
        return 1;
    }
    *slot_out = index;
    if (index < 0) {
        return 0;
    }
    record_array_ptr[index].ref_count++;
    record_array_ptr[index].surface->ref_count++;
    return 1;
}
#pragma pop

s32 TObjPlayer__sub_803DAA70(u32 id, u32 tlut_name, GvrTextureDesc *desc) {
    GinjaTextureState *texture;
    GinjaSurfaceState *surface;
    s32 slot;
    slot = TObjPlayer::find_free_slot(&texture, &surface);
    if (slot < 0) {
        return -1;
    }
    texture->surface = surface;
    if (TObjPlayer__sub_803D9DA8(texture, desc) != 1) {
        texture->surface = NULL;
        return -1;
    }
    if (id != 0xFFFFFFFFU) {
        texture->surface->id = id;
    }
    if (TObjPlayer__sub_803DA104(desc->format) != 0) {
        texture->tlut_name = tlut_name;
    } else {
        texture->tlut_name = -1;
    }
    TObjPlayer__sub_803DAD24(texture);
    texture->ref_count = 1;
    texture->surface->ref_count = 1;
    player_ref_entry_active_count += 1;
    return slot;
}

#pragma push
#pragma scheduling off
#pragma peephole off
void TObjPlayer__sub_803DAB7C(NJS_TEXLIST *list, s32 index, s32 slot) {
    list->textures[index].texture = record_array_ptr + slot;
}
#pragma pop

s32 TObjPlayer__sub_803DAB9C(s32 slot, s32 src) {
    GinjaSurfaceState *surface = record_array_ptr[slot].surface;
    if (surface == 0) {
        lbl_8058D470.code = 1;
        return -1;
    }
    if (TObjPlayer__sub_803DA84C(&surface->header, src, 0, surface->header.size) != 0) {
        lbl_8058D470.code = 8;
        return -1;
    }
    return 1;
}

#pragma push
#pragma scheduling off
void TObjPlayer__sub_803DAC1C(s32 slot) {
    TObjPlayer__sub_803DAE98(&record_array_ptr[slot]);
}
#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
s32 TObjPlayer__sub_803DAC48(NJS_TEXLIST *list, s32 index, u32 id, u32 tlut_name, GvrTextureDesc *desc, s32 *slot) {
    switch (TObjPlayer__sub_803DA8E4(id, tlut_name, desc->format, slot)) {
    case -1:
        return -1;
    case 0:
        *slot = TObjPlayer__sub_803DAA70(id, tlut_name, desc);
        if (*slot < 0) {
            return -1;
        }
        TObjPlayer__sub_803DAB7C(list, index, *slot);
        return 0;
    case 1:
        TObjPlayer__sub_803DAB7C(list, index, *slot);
        return 1;
    }
    return 0;
}
#pragma pop

void TObjPlayer__sub_803DAD24(GinjaTextureState *) {

}

#pragma push
#pragma scheduling off
s32 TObjPlayer__sub_803DAD28(u32 id) {
    s32 index;
    GinjaTextureState *texture;
    index = TObjPlayer::find_table_index_by_id(id);
    if (index < 0) {
        return -1;
    }
    texture = record_array_ptr + index;
    current_render_context->texture_header = &texture->surface->header;
    current_render_context->tlut_name = texture->tlut_name;
    return 1;
}
#pragma pop

s32 TObjPlayer__sub_803DAD84(GinjaTextureState *texture, s32 src, u32 arg2) {
    GinjaSurfaceState *surface = texture->surface;
    if ((surface->header.flags & 0x80000000) != 0 && arg2 != 0) {
        if (TObjPlayer__sub_803DB23C(&surface->header) != 0) {
            lbl_8058D470.code = 8;
            return -1;
        }
    } else {
        if (TObjPlayer__sub_803DA8B4(&surface->header, src) != 0) {
            lbl_8058D470.code = 8;
            return -1;
        }
    }
    while (TObjPlayer__sub_803DB244() != 0) {
    }
    return 1;
}

s32 TObjPlayer__sub_803DAE1C(s32 index, s32 src, u32 arg2) {
    reset_texture_error();
    s32 r = TObjPlayer__sub_803DAD84(current_render_context->textures->textures[index].texture, src, arg2);
    if (r < 0) {
        lbl_8058D470.entry_index = index;
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
            free_texture_pixels(&texture->surface->header);
            current_render_context->reserved14 = -1;
        }
    }
    clear_unreferenced_texture_entry(texture);
    return 1;
}
#pragma pop
