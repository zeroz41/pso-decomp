#include "types.h"
#include "pso/render/GinjaModel.h"
#include "pso/render/GinjaUvScroll.h"

struct Ref_803278B0 { GinjaVertexArray *ent; s16 *pts; };

Ref_803278B0 *scroll_uv_entry_write_cursor;
s16 *scroll_uv_coordinate_write_cursor;
extern "C" {
void collect_scroll_uv_entries__19TOComputerMachine01FiPvi(s32 arg0, GinjaModel *model, s32 id) {
    s32 hit;
    GinjaVertexArray *e;
    s16 *q;
    s32 i;
    u16 n;
    hit = 0;
    if (model->primary != 0 && has_texture_scroll_entry(model->primary, (u16) id) == 1) {
        set_ginja_texture_wrap_repeat(model->primary);
        hit = 1;
    }
    if (model->secondary != 0 && has_texture_scroll_entry(model->secondary, (u16) id) == 1) {
        set_ginja_texture_wrap_repeat(model->secondary);
        hit = 1;
    }
    if (hit != 0) {
        for (e = model->vertices; e != 0 && e->attribute != 0xFF; e++) {
            if (e->attribute == 5 || e->attribute == 6) {
                scroll_uv_entry_write_cursor->ent = e;
                scroll_uv_entry_write_cursor->pts = scroll_uv_coordinate_write_cursor;
                scroll_uv_entry_write_cursor++;
                n = e->count;
                q = static_cast<s16 *>(e->data);
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
