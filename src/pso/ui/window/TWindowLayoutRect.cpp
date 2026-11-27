#include "types.h"
#include "pso/ui/window/TWindowLayoutRect.h"

void TWindowLayoutRect::render(WindowDrawContext *) {}

void TWindowLayoutRect::update() {}

TWindowLayoutRect::~TWindowLayoutRect() {}

TWindowLayoutRect::TWindowLayoutRect(s32 client) : TWindowLayoutEntry(client) {
    this->x = 0.0f;
    this->y = 0.0f;
    this->width = 0.0f;
    this->height = 0.0f;
}

TWindowLayoutRect::TWindowLayoutRect(u8 *rec, s32 client) : TWindowLayoutEntry(client) {
    const WindowLayoutRectRecord *r = (const WindowLayoutRectRecord *)rec;
    this->x = r->x;
    this->y = r->y;
    this->width = r->width;
    this->height = r->height;
}
