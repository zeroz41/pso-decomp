#include "types.h"
#include "pso/boss/TBoss8Dragon_8005D700.h"
#include "pso/unk/text_80355A1C.h"

extern "C" {
extern u8 lbl_804792D8[];
extern void *gryphon_tornado_particle_id_table;

void TBoss8Dragon__sub_80355A1C(void) {  }
void TBoss8Dragon__sub_80355A20(void) {
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        gryphon_tornado_particle_id_table = lbl_804792D8;
        break;
    }
}

}
