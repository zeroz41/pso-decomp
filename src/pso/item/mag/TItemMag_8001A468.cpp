#include "types.h"
#include "pso/item/TItemLoad_8010FDF0.h"

#pragma inline_depth(1)
#pragma dont_inline off
struct Sub_8001A470 { s32 w[4]; };

struct Rec_8001A470 { s32 f0; Sub_8001A470 a; Sub_8001A470 b; f32 f24; f32 f28; };

extern "C" {
void copy_draw_line_record(Rec_8001A470 *d, Rec_8001A470 *s);
}

void *RelocatedFile::get_root() { return root; }

void copy_draw_line_record(Rec_8001A470 *d, Rec_8001A470 *s) {
    d->f0 = s->f0;
    d->a = s->a;
    d->b = s->b;
    d->f24 = s->f24;
    d->f28 = s->f28;
}
