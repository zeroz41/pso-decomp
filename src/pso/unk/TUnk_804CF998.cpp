#include "types.h"
#include "pso/unk/TUnk_804CF998.h"

extern const f32 lbl_805DCEF8;

void TUnk_804CF998::render(WindowDrawContext *) {}

void TUnk_804CF998::update() {}

TUnk_804CF998::~TUnk_804CF998() {}

TUnk_804CF998::TUnk_804CF998(s32 m_2) : TWindowLayoutEntry(m_2) {
    this->x = lbl_805DCEF8;
    this->y = lbl_805DCEF8;
    this->width = lbl_805DCEF8;
    this->height = lbl_805DCEF8;
}

TUnk_804CF998::TUnk_804CF998(u8 *rec, s32 m_2) : TWindowLayoutEntry(m_2) {
    this->x = *(f32 *)(rec + 4);
    this->y = *(f32 *)(rec + 8);
    this->width = *(f32 *)(rec + 0xC);
    this->height = *(f32 *)(rec + 0x10);
}
