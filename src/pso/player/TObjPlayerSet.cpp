#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TObjPlayerSet.h"
#include "pso/system/task/TObject_8001A448.h"

#include "pso/system/task/TObject.h"


#pragma push
#pragma readonly_strings on
const char *TObjPlayer__player_set_class_name = "TObjPlayerSet";
#pragma pop

void TObjPlayerSet::render() {  }
void TObjPlayerSet::run_task() {  }

extern void *tl_06;

void *TObjPlayerSet::create(void *set_data) {
    return new TObjPlayerSet((TObject *)tl_06, set_data);
}

TObjPlayerSet::~TObjPlayerSet() {

}


#pragma push
#pragma opt_common_subs off
#define player_set this
TObjPlayerSet::TObjPlayerSet(TObject *parent, void *set_data) : TObjBase(parent) {
    *(s32 *)((s8 *)player_set + 0) = (saddr) TObjPlayer__player_set_class_name;
    ((TObjPlayerSet *)(player_set))->apply_object_set_data(set_data);
    if (player_set->scale.x < 0.0f) {
        player_set->scale.x = 0.0f;
    }
    if ((s32) player_set->set_params[0] < 0) {
        player_set->set_params[0] = 0;
    }
    ((TObject *)player_set)->disallow_rendering();
}
#undef player_set
#pragma pop
