#include "types.h"

struct Ent_803278B0 { u8 type; u8 pad1; u16 count; u8 pad4[4]; s16 *pts; u8 padC[4]; };

struct Hdr_803278B0 { Ent_803278B0 *ents; u8 pad4[4]; void *a; void *b; };

struct Ref_803278B0 { Ent_803278B0 *ent; s16 *pts; };

Ref_803278B0 *scroll_uv_entry_write_cursor;
s16 *scroll_uv_coordinate_write_cursor;
extern "C" {
s32 has_texture_scroll_entry(void *, u16);
void set_ginja_texture_wrap_repeat(void *);
void collect_scroll_uv_entries__19TOComputerMachine01FiPvi(s32 arg0, Hdr_803278B0 *model, s32 id);
void collect_scroll_uv_entries__19TOComputerMachine01FiPvi(s32 arg0, Hdr_803278B0 *model, s32 id) {
    s32 hit;
    Ent_803278B0 *e;
    s16 *q;
    s32 i;
    u16 n;
    hit = 0;
    if (model->a != 0 && has_texture_scroll_entry(model->a, (u16) id) == 1) {
        set_ginja_texture_wrap_repeat(model->a);
        hit = 1;
    }
    if (model->b != 0 && has_texture_scroll_entry(model->b, (u16) id) == 1) {
        set_ginja_texture_wrap_repeat(model->b);
        hit = 1;
    }
    if (hit != 0) {
        for (e = model->ents; e != 0 && e->type != 0xFF; e++) {
            if (e->type == 5 || e->type == 6) {
                scroll_uv_entry_write_cursor->ent = e;
                scroll_uv_entry_write_cursor->pts = scroll_uv_coordinate_write_cursor;
                scroll_uv_entry_write_cursor++;
                n = e->count;
                q = e->pts;
                for (i = 0; i < n; i++) {
                    *scroll_uv_coordinate_write_cursor++ = q[0];
                    *scroll_uv_coordinate_write_cursor++ = q[1];
                    q += 2;
                }
            }
        }
    }
}

}
