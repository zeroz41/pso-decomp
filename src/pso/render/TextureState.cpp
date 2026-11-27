#include "types.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/system/MemoryMove.h"
#include "pso/render/TextureState.h"
#include "pso/render/GinjaTextureHeader.h"
#include <dolphin/os/OSCache.h>
#include "pso/render/GinjaModelQueue.h"
#include "pso/system/MatrixStack.h"
extern "C" {
// Called with the whole format word, as Ginja's C callers do without a prototype; the callee reads the low byte.
s32 is_palette_texture_format(int format);
}

s32 set_texture_list(NJS_TEXLIST *texlist) {
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
    texture_error.entry_index = -1;
    texture_error.pad_04 = -1;
    texture_error.code = 0;
    texture_error.pad_0C = 0;
    texture_error.pad_10 = 0;
}
#pragma pop

void copy_texture_data_and_flush(void *buf, saddr src, u32 size) {
    move_data(buf, (const void *)src, size);
    DCFlushRange(buf, size);
}

s32 copy_texture_pixel_range(GinjaTextureHeader *header, s32 src, s32 offsetRaw, s32 lengthRaw) {
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
    copy_texture_data_and_flush((void *)(copyStart + (uaddr)header->pixels), src, copyLen);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
s32 copy_texture_pixels(GinjaTextureHeader *header, s32 src) {
    copy_texture_data_and_flush(header->pixels, src, header->size);
    return 0;
}
#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
s32 reference_loaded_texture(u32 id, u32 tlut_name, s32 format, s32 *slot_out) {
    GinjaTextureState *texture;
    s32 index;
    s32 shared;
    s32 slot;
    index = find_texture_by_surface_id(id);
    if (is_palette_texture_format(format) != 0) {
        if (index < 0) {
            *slot_out = -1;
            return 0;
        }
        shared = find_texture_by_surface_and_tlut(id, tlut_name);
        if (shared < 0) {
            slot = find_free_texture_slot(&texture, NULL);
            if (slot < 0) {
                return -1;
            }
            texture->tlut_name = tlut_name;
            texture->surface = texture_states[index].surface;
            texture->surface->ref_count++;
            texture->ref_count = 1;
            texture->reserved14 = texture_states[index].reserved14;
            notify_texture_state_ready(texture);
            *slot_out = slot;
            return 1;
        }
        *slot_out = shared;
        texture_states[shared].ref_count++;
        texture_states[shared].surface->ref_count++;
        return 1;
    }
    *slot_out = index;
    if (index < 0) {
        return 0;
    }
    texture_states[index].ref_count++;
    texture_states[index].surface->ref_count++;
    return 1;
}
#pragma pop

s32 create_texture_state(u32 id, u32 tlut_name, GvrTextureDesc *desc) {
    GinjaTextureState *texture;
    GinjaSurfaceState *surface;
    s32 slot;
    slot = find_free_texture_slot(&texture, &surface);
    if (slot < 0) {
        return -1;
    }
    texture->surface = surface;
    if (init_texture_from_gvr_desc(texture, desc) != 1) {
        texture->surface = NULL;
        return -1;
    }
    if (id != 0xFFFFFFFFU) {
        texture->surface->id = id;
    }
    if (is_palette_texture_format(desc->format) != 0) {
        texture->tlut_name = tlut_name;
    } else {
        texture->tlut_name = -1;
    }
    notify_texture_state_ready(texture);
    texture->ref_count = 1;
    texture->surface->ref_count = 1;
    active_texture_surface_count += 1;
    return slot;
}

#pragma push
#pragma scheduling off
#pragma peephole off
void set_texlist_texture(NJS_TEXLIST *list, s32 index, s32 slot) {
    list->textures[index].texture = texture_states + slot;
}
#pragma pop

s32 reload_texture_slot_pixels(s32 slot, s32 src) {
    GinjaSurfaceState *surface = texture_states[slot].surface;
    if (surface == 0) {
        texture_error.code = 1;
        return -1;
    }
    if (copy_texture_pixel_range(&surface->header, src, 0, surface->header.size) != 0) {
        texture_error.code = 8;
        return -1;
    }
    return 1;
}

#pragma push
#pragma scheduling off
void release_texture_slot(s32 slot) {
    release_texture_state(&texture_states[slot]);
}
#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
s32 bind_texlist_texture(NJS_TEXLIST *list, s32 index, u32 id, u32 tlut_name, GvrTextureDesc *desc, s32 *slot) {
    switch (reference_loaded_texture(id, tlut_name, desc->format, slot)) {
    case -1:
        return -1;
    case 0:
        *slot = create_texture_state(id, tlut_name, desc);
        if (*slot < 0) {
            return -1;
        }
        set_texlist_texture(list, index, *slot);
        return 0;
    case 1:
        set_texlist_texture(list, index, *slot);
        return 1;
    }
    return 0;
}
#pragma pop

void notify_texture_state_ready(GinjaTextureState *) {

}

#pragma push
#pragma scheduling off
s32 select_texture_by_surface_id(u32 id) {
    s32 index;
    GinjaTextureState *texture;
    index = find_texture_by_surface_id(id);
    if (index < 0) {
        return -1;
    }
    texture = texture_states + index;
    current_render_context->texture_header = &texture->surface->header;
    current_render_context->tlut_name = texture->tlut_name;
    return 1;
}
#pragma pop

s32 reload_texture_state_pixels(GinjaTextureState *texture, s32 src, u32 use_header) {
    GinjaSurfaceState *surface = texture->surface;
    if ((surface->header.flags & 0x80000000) != 0 && use_header != 0) {
        if (start_texture_header_transfer(&surface->header) != 0) {
            texture_error.code = 8;
            return -1;
        }
    } else {
        if (copy_texture_pixels(&surface->header, src) != 0) {
            texture_error.code = 8;
            return -1;
        }
    }
    while (texture_transfer_pending() != 0) {
    }
    return 1;
}

s32 reload_list_texture_pixels(s32 index, s32 src, u32 use_header) {
    reset_texture_error();
    s32 r = reload_texture_state_pixels(current_render_context->textures->textures[index].texture, src, use_header);
    if (r < 0) {
        texture_error.entry_index = index;
    }
    return r;
}

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
#pragma peephole off
#pragma scheduling off
s32 release_texture_state(GinjaTextureState *texture) {
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
