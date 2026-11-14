#include "types.h"
#include "pso/object/wreck/TOWreckAncient02.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"

extern "C" {

void *TOWreckAncient02__create(void *set_data) {
    return new TOWreckAncient02(set_data);
}


}
TOWreckAncient02::~TOWreckAncient02() {

}

extern const char *TOWreckAncient02__name;

TOWreckAncient02::TOWreckAncient02(void *set_data) : TOWreckAncient(0) {
    m_name = TOWreckAncient02__name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, &TOWreckAncient__collision_body_templates[0], 1);
    register_object_by_id();
}
