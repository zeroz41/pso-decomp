#include "types.h"
#include "pso/object/TObjLiveMonitorSmall.h"
#include "pso/object/TObjLiveMonitor.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/goldragon/TObjBoss8PillerCtrl.h"
#include "pso/boss/goldragon/TObjBoss8DemoRoom.h"

extern "C" {
s32 is_room_enemy_set_cleared(s32, s32);
s32 __ct__18TObjLiveCameraCtrlFP7TObject(void *, s32);
}
extern void *tl_05;
void create_boss8_demo_objects(void);

void create_boss8_piller_ctrl(const Vec *position, s32 id, f32 ignored) {
    new TObjBoss8PillerCtrl((TObject *)tl_05, ignored, position, id);
}
void create_boss8_demo_objects(void) {
    void *obj;
    if ((is_split_screen() == 0) && ((obj = TObject::operator new(0x13C)) != 0)) {
        __ct__18TObjLiveCameraCtrlFP7TObject(obj, (*(s32 *)&tl_05));
    }
    TObjLiveMonitor::create((void *)(*(saddr *)&tl_05));
    ((TObjLiveMonitorSmall *)(*(saddr *)&tl_05))->spawn_for_each_fish();
    if (is_room_enemy_set_cleared(get_current_floor(), 1) == 0) {
        new TObjBoss8DemoRoom((TObject *)tl_05);
    }
}
