#include "types.h"
#include "pso/enemy/TObjEneMe1Canadin_EffLineFade.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/enemy/TObjEneMe1Canadin_EffLineFade.h"
#include "pso/enemy/TObjEneDarkGunner.h"

extern "C" {

void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

void TObjEneMe1Canadin_EffLineFade::run_task() {
    s32 var_r31;

    var_r31 = this->m_37;
    var_r31 -= 0x10;
    if (var_r31 < 0) {
        var_r31 = 0;
        queue_destruction__7TObjectFv(this);
    }
    this->m_37 = (u8) var_r31;
    this->m_3b = (s8) var_r31;
}

extern s32 __vt__29TObjEneMe1Canadin_EffLineFade[];

}
TObjEneMe1Canadin_EffLineFade::~TObjEneMe1Canadin_EffLineFade() {

}
extern "C" {

}
