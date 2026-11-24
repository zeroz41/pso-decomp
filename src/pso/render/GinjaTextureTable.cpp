#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/GinjaTextureInput.h"
#include "pso/render/RenderSbssGlobals.h"

void GinjaTextureInput::set_render_rect(void *pixels, s32 input_format, s32 input_width, s32 input_height) {
    data = pixels;
    width = input_width;
    height = input_height;
    format = input_format;
}

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma optimize_for_size off
void set_texture_name(NJS_TEXNAME *entry, GinjaTextureInput *input, u32 index, u32 attributes) {
    if (attributes & NJD_TEXATTR_TYPE_MEMORY) {
        entry->filename = reinterpret_cast<char *>(input);
        entry->attr = attributes;
        entry->global_index = index;
    } else {
        entry->filename = reinterpret_cast<char *>(input);
        entry->attr = attributes;
        entry->global_index = index;
    }
}
#pragma pop

#pragma push
#pragma optimize_for_size off
void init_texture_states(GinjaTextureState *states, s32 count) {
    s32 i;
    texture_states = states;
    texture_state_count = count;
    for (i = 0; i < count; i++) {
        states->reserved00 = 0;
        states->reserved04 = 0;
        states->tlut_name = 0xFFFFFFFF;
        states->surface = NULL;
        states->ref_count = 0;
        states->reserved14 = 0;
        states++;
    }
}
#pragma pop

#pragma push
#pragma optimize_for_size off
void init_texture_surfaces(GinjaSurfaceState *surfaces, s32 count) {
    s32 i;
    texture_surfaces = surfaces;
    texture_surface_count = count;
    for (i = 0; i < count; i++) {
        surfaces->id = -1;
        surfaces->header.format = 0;
        surfaces->header.reserved04 = 0;
        surfaces->header.reserved08 = 0;
        surfaces->header.width = 0;
        surfaces->header.height = 0;
        surfaces->header.size = 0;
        surfaces->header.flags = 0;
        surfaces->header.pixels = NULL;
        surfaces->ref_count = 0;
        surfaces++;
    }
}
#pragma pop

s32 find_texture_by_surface_id(u32 id) {
    GinjaTextureState *texture;
    GinjaSurfaceState *surface;
    s32 i;
    i = 0;
    texture = texture_states;
    for (; i < texture_state_count; texture++, i++) {
        surface = texture->surface;
        if (surface != 0 && id == surface->id) {
            return i;
        }
    }
    return -1;
}

s32 find_free_texture_slot(GinjaTextureState **texture, GinjaSurfaceState **surface) {
    s32 i;
    GinjaTextureState *p;
    GinjaSurfaceState *q;
    s32 idx;
    *texture = NULL;
    p = texture_states;
    for (i = 0; i < texture_state_count; p++, i++) {
        if (p->surface == NULL) {
            *texture = p;
            idx = i;
            break;
        }
    }
    if (*texture == NULL) {
        texture_error.code = 7;
        return -1;
    }
    if (surface != NULL) {
        *surface = NULL;
        q = texture_surfaces;
        for (i = 0; i < texture_surface_count; i++, q++) {
            if (q->id == 0xFFFFFFFF) {
                *surface = q;
                break;
            }
        }
        if (*surface == NULL) {
            texture_error.code = 7;
            return -1;
        }
        return idx;
    }
    return idx;
}

s32 find_texture_by_surface_and_tlut(u32 id, u32 tlut_name) {
    GinjaSurfaceState *surface;
    s32 i;
    GinjaTextureState *p = texture_states;
    for (i = 0; i < texture_state_count; p++, i++) {
        if (p->tlut_name == tlut_name) {
            surface = p->surface;
            if (surface != 0 && surface->id == id) return i;
        }
    }
    return -1;
}

void clear_unreferenced_texture_entry(GinjaTextureState *texture) {
    GinjaSurfaceState *surface = texture->surface;
    if (surface->ref_count <= 0) {
        surface->id = -1;
        surface->header.format = 0;
        surface->header.reserved04 = 0;
        surface->header.reserved08 = 0;
        surface->header.width = 0;
        surface->header.height = 0;
        surface->header.size = 0;
        surface->header.flags = 0;
        surface->header.pixels = NULL;
        active_texture_surface_count -= 1;
    }
    if (texture->ref_count <= 0) {
        texture->tlut_name = -1;
        texture->reserved00 = 0;
        texture->reserved04 = 0;
        texture->surface = NULL;
        texture->reserved14 = 0;
    }
}

void init_texture_tables(GinjaTextureState *states, s32 count, GinjaSurfaceState *surfaces, s32 surface_count) {
    init_texture_states(states, count);
    init_texture_surfaces(surfaces, surface_count);
}
