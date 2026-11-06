#include "types.h"
#include "pso/enemy/morfos/TObjEneMorfosArm_80335218.h"
#include "pso/enemy/morfos/TObjEneMorfosArm.h"
#include "pso/enemy/morfos/TObjEneMorfos.h"

extern "C" {

void TObjEneMorfosArm__sub_8033542C(void) {  }

extern s32 TObjEneMorfosArm__parent_morfos_instance;

void *TObjEneMorfosArm::create(void *arg0, void *arg1) {
    return new TObjEneMorfosArm((TObject *)arg0, arg1);
}

void TObjEneMorfosArm::init_global() {
    TObjEneMorfosArm__parent_morfos_instance = TObjEneMorfos::get_instance();
}

}
