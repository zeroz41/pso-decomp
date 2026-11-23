#include "types.h"
#include "pso/unk/TUnk_804CF998.h"

extern const f32 lbl_805DCEF8;

void TUnk_804CF998::render(WindowDrawContext *) {}

void TUnk_804CF998::update() {}

TUnk_804CF998::~TUnk_804CF998() {}

TUnk_804CF998::TUnk_804CF998(s32 client) : TWindowLayoutEntry(client) {
    this->x = lbl_805DCEF8;
    this->y = lbl_805DCEF8;
    this->width = lbl_805DCEF8;
    this->height = lbl_805DCEF8;
}

TUnk_804CF998::TUnk_804CF998(u8 *rec, s32 client) : TWindowLayoutEntry(client) {
    const WindowLayoutRectRecord *r = (const WindowLayoutRectRecord *)rec;
    this->x = r->x;
    this->y = r->y;
    this->width = r->width;
    this->height = r->height;
}
