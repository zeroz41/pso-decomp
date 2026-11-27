#include "types.h"
#include "pso/object/container/TObjContainerIdoBase.h"
#include "pso/object/container/TObjContainerIdo.h"

void TObjContainerIdoBase::update_state() {  }

void TObjContainerIdoBase::run_task() {
    update_state();
}

void TObjContainerIdoBase::render() {
    if (update_object_view_visibility(view_far_depth, view_radius) != 0) {
        draw_model();
    }
}

void TObjContainerIdoBase::draw_model() {  }
