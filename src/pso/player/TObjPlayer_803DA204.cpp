#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaTextureInput.h"
#include "pso/player/TObjPlayer.h"

struct Sub_803DA688 { u32 v; };

struct Rec_803DA688 { u32 a; u32 b; u32 c; Sub_803DA688 *d; u32 e; u32 f; };

struct E_803DA55C { u8 pad[0xC]; u32 *p; u8 pad2[8]; };

struct Slot_803DA5A8 { u32 id; u8 pad[0x24]; };

struct Err_803DA5A8 { s32 a; s32 b; s32 code; };

struct Slot_803DA388 { s32 id; s32 a; s32 b; s32 c; s32 d; s32 e; s32 f; s32 g; s32 h; s32 i; };

extern "C" {
extern s32 player_ref_entry_active_count;
extern s32 record_array_count;
extern Rec_803DA688 *record_array_ptr;
extern Err_803DA5A8 lbl_8058D470[];
extern s32 lbl_805D775C;
extern Slot_803DA5A8 *lbl_805D7760;
s32 find_free_slot__10TObjPlayerFPvPv(Rec_803DA688 **arg0, Slot_803DA5A8 **arg1);
void TObjPlayer__sub_803DA388(Slot_803DA388 *p, s32 n);
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
    if (attributes & 0x40000000) {
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
void TObjPlayer::init_record_array(s32 arg1) {
    Rec_803DA688 *arg0 = (Rec_803DA688 *)this;
    s32 i;
    record_array_ptr = arg0;
    record_array_count = arg1;
    for (i = 0; i < arg1; i++) {
        arg0->a = 0;
        arg0->b = 0;
        arg0->c = 0xFFFFFFFF;
        arg0->d = NULL;
        arg0->e = 0;
        arg0->f = 0;
        arg0++;
    }
}
#pragma pop

#pragma push
#pragma optimize_for_size off
void TObjPlayer__sub_803DA388(Slot_803DA388 *p, s32 n) {
    s32 i;
    lbl_805D7760 = (Slot_803DA5A8 *)p;
    lbl_805D775C = n;
    for (i = 0; i < n; i++) {
        p->id = -1;
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->f = 0;
        p->g = 0;
        p->h = 0;
        p->i = 0;
        p++;
    }
}
#pragma pop

s32 TObjPlayer::find_table_index_by_id(u32 id) {
    E_803DA55C *e;
    u32 *q;
    s32 i;
    i = 0;
    e = (*(E_803DA55C * *)&record_array_ptr);
    for (; i < record_array_count; e++, i++) {
        q = e->p;
        if (q != 0 && id == *q) {
            return i;
        }
    }
    return -1;
}

s32 find_free_slot__10TObjPlayerFPvPv(Rec_803DA688 **arg0, Slot_803DA5A8 **arg1) {
    s32 i;
    Rec_803DA688 *p;
    Slot_803DA5A8 *q;
    s32 idx;
    *arg0 = NULL;
    p = record_array_ptr;
    for (i = 0; i < record_array_count; p++, i++) {
        if (p->d == NULL) {
            *arg0 = p;
            idx = i;
            break;
        }
    }
    if (*arg0 == NULL) {
        lbl_8058D470[0].code = 7;
        return -1;
    }
    if (arg1 != NULL) {
        *arg1 = NULL;
        q = lbl_805D7760;
        for (i = 0; i < lbl_805D775C; i++, q++) {
            if (q->id == 0xFFFFFFFF) {
                *arg1 = q;
                break;
            }
        }
        if (*arg1 == NULL) {
            lbl_8058D470[0].code = 7;
            return -1;
        }
        return idx;
    }
    return idx;
}

s32 TObjPlayer::find_record_index(u32 arg0, u32 arg1) {
    Sub_803DA688 *d;
    s32 i;
    Rec_803DA688 *p = record_array_ptr;
    for (i = 0; i < record_array_count; p++, i++) {
        if (p->c == arg1) {
            d = p->d;
            if (d != 0 && d->v == arg0) return i;
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
        player_ref_entry_active_count -= 1;
    }
    if (texture->ref_count <= 0) {
        texture->tlut_name = -1;
        texture->reserved00 = 0;
        texture->reserved04 = 0;
        texture->surface = NULL;
        texture->reserved14 = 0;
    }
}

}
