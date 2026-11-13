#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueMissile.h"
#include "pso/system/task/TObject.h"

extern "C" {


void TObjEneMe1GiGueMissile::update_lifetime() {
    f32 temp_f1;

    temp_f1 = this->m_24;
    if (temp_f1 > *(f32 *)&this->unk_20) {
        TObject::queue_destruction();
        return;
    }
    this->m_24 = (f32) (temp_f1 + *(f32 *)&this->_padAC);
}

}
