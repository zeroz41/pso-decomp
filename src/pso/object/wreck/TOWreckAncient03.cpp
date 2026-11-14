#include "types.h"
#include "pso/object/wreck/TOWreckAncient03.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"

#pragma readonly_strings on

extern "C" {

void *TOWreckAncient03__create(void *set_data) {
    return new TOWreckAncient03(set_data);
}


}
TOWreckAncient03::~TOWreckAncient03() {

}

const char *TOWreckAncient03__name = "TOWreckAncient03";

TOWreckAncient03::TOWreckAncient03(void *set_data) : TOWreckAncient(2) {
    m_name = TOWreckAncient03__name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, &TOWreckAncient__collision_body_templates[2], 1);
    register_object_by_id();
}
