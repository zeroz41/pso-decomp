#include "types.h"
#include "pso/object/TObjLiveMonitorSmall.h"
#include "pso/object/TObjLiveMonitor.h"
#include "pso/camera/TObjLiveCameraCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/goldragon/TObjBoss8PillerCtrl.h"
#include "pso/boss/goldragon/TObjBoss8DemoRoom.h"

extern "C" {
s32 is_room_enemy_set_cleared(s32, s32);
}
extern void *tl_05;
void create_boss8_demo_objects(void);

void create_boss8_piller_ctrl(const Vec *position, u16 id, f32 ignored) {
    new TObjBoss8PillerCtrl((TObject *)tl_05, ignored, position, id);
}
void create_boss8_demo_objects(void) {
    if (is_split_screen() == 0) {
        new TObjLiveCameraCtrl((TObject *)tl_05);
    }
    TObjLiveMonitor::create((TObject *)tl_05);
    TObjLiveMonitorSmall::spawn_all((TObject *)tl_05);
    if (is_room_enemy_set_cleared(get_current_floor(), 1) == 0) {
        new TObjBoss8DemoRoom((TObject *)tl_05);
    }
}
