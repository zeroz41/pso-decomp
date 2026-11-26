#include "types.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/object/container/TObjContainerIdo.h"

void TUnk_804B97C0::update_state() {  }

void TUnk_804B97C0::run_task() {
    update_state();
}

void TUnk_804B97C0::render() {
    if (update_object_view_visibility(view_far_depth, view_radius) != 0) {
        draw_model();
    }
}

void TUnk_804B97C0::draw_model() {  }
