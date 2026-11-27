#include "types.h"
#include "pso/item/TItemLoad.h"

#pragma inline_depth(1)
#pragma dont_inline off
struct DrawLineEnd { s32 w[4]; };

struct DrawLineRecord { s32 f0; DrawLineEnd a; DrawLineEnd b; f32 f24; f32 f28; };

extern "C" {
void copy_draw_line_record(DrawLineRecord *d, DrawLineRecord *s);
}

void *RelocatedFile::get_root() { return root; }

void copy_draw_line_record(DrawLineRecord *d, DrawLineRecord *s) {
    d->f0 = s->f0;
    d->a = s->a;
    d->b = s->b;
    d->f24 = s->f24;
    d->f28 = s->f28;
}
