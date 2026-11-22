#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar_8028B6C0.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

TObjBoss5Pillar *TObjBoss5Pillar::create(Vec *pos) {
    return new TObjBoss5Pillar(tl_02, pos);
}

extern "C" {
void TObjBoss5Pillar__sub_8028B70C(void) {  }
void TObjBoss5Pillar__sub_8028B710(void) {  }

}
