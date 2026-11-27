#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TObjPlayerSet.h"

#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma push
#pragma readonly_strings on
const char *TObjPlayerSet::class_name = "TObjPlayerSet";
#pragma pop

void TObjPlayerSet::render() {  }
void TObjPlayerSet::run_task() {  }

void *TObjPlayerSet::create(void *set_data) {
    return new TObjPlayerSet(tl_06, set_data);
}

TObjPlayerSet::~TObjPlayerSet() {

}

#pragma push
#pragma opt_common_subs off
TObjPlayerSet::TObjPlayerSet(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    if (scale.x < 0.0f) {
        scale.x = 0.0f;
    }
    if ((s32) set_params[0] < 0) {
        set_params[0] = 0;
    }
    disallow_rendering();
}
#pragma pop
