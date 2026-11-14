#include "types.h"
#include "pso/unk/text_802FE9E0.h"
#include "pso/boss/goldragon/TBoss8DragonEffTail.h"
#include "pso/boss/goldragon/TObjBoss8DemoRoom.h"
#include "pso/boss/goldragon/TObjBoss8Piller.h"
#include "pso/camera/TObjLiveCamera.h"
#include "pso/object/TObjLiveMonitor.h"

// Load and release hooks in pairs, run forwards by run_load_callback_table and backwards by call_funcs_reverse.
void (*static_resource_callback_table[10])(void) = {
    TBoss8DragonEffTail::load_statics, TBoss8DragonEffTail::free_statics,
    reset_live_camera_ctrl_globals, release_live_camera_ctrl_globals,
    TObjLiveCamera::load_static_resource, TObjLiveCamera::free_static_resource,
    TObjBoss8Piller::load_resource_descriptor, TObjBoss8Piller::free_held_object,
    TObjBoss8DemoRoom::load_resource, TObjBoss8DemoRoom::free_static_instance,
};

extern "C" {
void call_funcs_reverse__6TLobbyFPvUi(s32, u32);
s32 run_load_callback_table(void *, int);
void fn_802FE9E0(void) {
    call_funcs_reverse__6TLobbyFPvUi((s32)static_resource_callback_table, sizeof(static_resource_callback_table));
}
void fn_802FEA0C(void) {
    run_load_callback_table(static_resource_callback_table, sizeof(static_resource_callback_table));
}

}
