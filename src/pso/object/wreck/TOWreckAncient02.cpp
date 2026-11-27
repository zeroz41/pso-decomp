#include "types.h"
#include "pso/object/wreck/TOWreckAncient02.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/ActorCollision.h"


void *TOWreckAncient02::create(ObjectSetData *set_data) {
    return new TOWreckAncient02(set_data);
}


TOWreckAncient02::~TOWreckAncient02() {

}

const char *wreck_ancient02_name = "TOWreckAncient02";

TOWreckAncient02::TOWreckAncient02(ObjectSetData *set_data) : TOWreckAncient(0) {
    m_name = wreck_ancient02_name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, &TOWreckAncient::collision_body_templates[0], 1);
    register_object_by_id();
}
