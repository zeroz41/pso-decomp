#include "types.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/unk/TUnk_804B0BB8.h"

extern const float lbl_805DB3DC;

TUnk_804B0BB8::TUnk_804B0BB8(TObject *parent) : TUnk_804AFBF8(parent) {
    m_c8 = -1;
    m_cc = 0;
    m_d0 = 0;
    m_ac = 0;
    m_b8 = lbl_805DB3DC;
}

void TUnk_804B0BB8::vfunc_20() {}
void TODoorAncient01::vfunc_20() {}
