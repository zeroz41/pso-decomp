#include "types.h"
#include "pso/unk/TWindowLayoutRect.h"

extern const f32 lbl_805DCEF8;

void TWindowLayoutRect::render(WindowDrawContext *) {}

void TWindowLayoutRect::update() {}

TWindowLayoutRect::~TWindowLayoutRect() {}

TWindowLayoutRect::TWindowLayoutRect(s32 client) : TWindowLayoutEntry(client) {
    this->x = lbl_805DCEF8;
    this->y = lbl_805DCEF8;
    this->width = lbl_805DCEF8;
    this->height = lbl_805DCEF8;
}

TWindowLayoutRect::TWindowLayoutRect(u8 *rec, s32 client) : TWindowLayoutEntry(client) {
    const WindowLayoutRectRecord *r = (const WindowLayoutRectRecord *)rec;
    this->x = r->x;
    this->y = r->y;
    this->width = r->width;
    this->height = r->height;
}
