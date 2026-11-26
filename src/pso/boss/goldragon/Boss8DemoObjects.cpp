#include "types.h"
#include "pso/object/TObjLiveMonitorSmall.h"
#include "pso/object/TObjLiveMonitor.h"
#include "pso/camera/TObjLiveCameraCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/boss/goldragon/TObjBoss8PillerCtrl.h"
#include "pso/boss/goldragon/TObjBoss8DemoRoom.h"
#include "pso/network/TLobby.h"
#include "pso/boss/goldragon/Boss8DemoObjects.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_8020BFE4.h"
#include "pso/boss/goldragon/TBoss8DragonEffTail.h"
#include "pso/boss/goldragon/TObjBoss8Piller.h"
#include "pso/camera/TObjLiveCamera.h"
#include "pso/map/area/AreaScene.h"

void create_boss8_piller_ctrl(const Vec *position, u16 id, f32 ignored) {
    new TObjBoss8PillerCtrl(tl_05, ignored, position, id);
}
void create_boss8_demo_objects(void) {
    if (is_split_screen() == 0) {
        new TObjLiveCameraCtrl(tl_05);
    }
    TObjLiveMonitor::create(tl_05);
    TObjLiveMonitorSmall::spawn_all(tl_05);
    if (is_room_enemy_set_cleared(get_current_floor(), 1) == 0) {
        new TObjBoss8DemoRoom(tl_05);
    }
}

// Load and release hooks in pairs, run forwards by run_load_callback_table and backwards by call_funcs_reverse.
void (*static_resource_callback_table[10])(void) = {
    TBoss8DragonEffTail::load_statics, TBoss8DragonEffTail::free_statics,
    reset_live_camera_ctrl_globals, release_live_camera_ctrl_globals,
    TObjLiveCamera::load_static_resource, TObjLiveCamera::free_static_resource,
    TObjBoss8Piller::load_resource_descriptor, TObjBoss8Piller::free_held_object,
    TObjBoss8DemoRoom::load_resource, TObjBoss8DemoRoom::free_static_instance,
};

extern "C" {
void fn_802FE9E0(void) {
    TLobby::call_funcs_reverse(static_resource_callback_table, (unsigned int)(sizeof(static_resource_callback_table)));
}
void fn_802FEA0C(void) {
    run_load_callback_table(static_resource_callback_table, sizeof(static_resource_callback_table));
}
}
