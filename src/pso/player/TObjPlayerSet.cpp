#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TObjPlayerSet.h"
#include "pso/system/task/TObject_8001A448.h"

#include "pso/system/task/TObject.h"


extern "C" {
u8 * __ct__8TObjBaseFP7TObject(void *);
extern s32 __vt__13TObjPlayerSet[];
extern s32 TObjPlayer__player_set_class_name;
u8 *TObjPlayerSet__ct(TObjPlayerSet *arg0, s32 arg1, s32 arg2);

void TObjPlayerSet::render() {  }
void TObjPlayerSet::run_task() {  }

extern void *tl_06;

void *TObjPlayerSet::create(void *arg0) {
    void *o = TObject::operator new(0x90);
    if (o != NULL) {
        o = TObjPlayerSet__ct((TObjPlayerSet *)((u8 *)o), (s32)tl_06, (s32)arg0);
    }
    return o;
}

}
TObjPlayerSet::~TObjPlayerSet() {

}


#pragma push
#pragma opt_common_subs off
u8 *TObjPlayerSet__ct(TObjPlayerSet *player_set, s32 arg1, s32 arg2) {
    __ct__8TObjBaseFP7TObject(player_set);
    *(s32 **)((s8 *)player_set + 0x18) = __vt__13TObjPlayerSet;
    *(s32 *)((s8 *)player_set + 0) = (s32) TObjPlayer__player_set_class_name;
    ((TObjPlayerSet *)(player_set))->apply_object_set_data((void *)arg2);
    if (player_set->scale.x < 0.0f) {
        player_set->scale.x = 0.0f;
    }
    if ((s32) player_set->set_params[0] < 0) {
        player_set->set_params[0] = 0;
    }
    ((TObject *)player_set)->disallow_rendering();
    return (u8 *)player_set;
}
#pragma pop
