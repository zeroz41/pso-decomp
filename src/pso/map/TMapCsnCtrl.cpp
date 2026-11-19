#include "pso/map/TMapCsnCtrl.h"

#include "pso/map/TObjMapCsn.h"
#include "types.h"

// TObjMapCsn's name lives in this TU (.sdata 0x805D2CD0, string 0x8043F268), as TMapCsnCtrl's lives in
// TObjMapCsn.cpp.
const char *TObjMapCsn__class_name = "TObjMapCsn";

void TMapCsnCtrl::sub_80140F44() {
    unk_1C = 0;
}

TMapCsnCtrl::~TMapCsnCtrl() {}

TMapCsnCtrl::TMapCsnCtrl(TObject *parent) : TObject(parent) {
    m_name = TMapCsnCtrl__class_name;
    sub_80140F44();
}
