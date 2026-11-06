#include "pso/map/TMapCsnCtrl.h"

#include "types.h"

extern const char *TMapCsnCtrl__class_name;

void TMapCsnCtrl::sub_80140F44() {
    unk_1C = 0;
}

TMapCsnCtrl::~TMapCsnCtrl() {}

TMapCsnCtrl::TMapCsnCtrl(TObject *parent) : TObject(parent) {
    m_name = TMapCsnCtrl__class_name;
    sub_80140F44();
}
