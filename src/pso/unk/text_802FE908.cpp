#include "types.h"
#include "pso/object/TObjLiveMonitorSmall.h"
#include "pso/object/TObjLiveMonitor.h"

extern "C" {
s32 is_split_screen();
s32 get_current_floor();
s32 is_room_enemy_set_cleared(s32, s32);
void *__nw__7TObjectFUl(s32);
s32 __ct__18TObjLiveCameraCtrlFP7TObject(void *, s32);
s32 __ct__17TObjBoss8DemoRoomFv(void *, s32);
s32 TObjBoss8PillerCtrl__ct(void *, f32, void *, s32, s32);
}
extern void *tl_05;
void create_boss8_demo_objects(void);

void create_boss8_piller_ctrl(s32 arg0, s32 arg1, f32 boss8_piller_ctrl) {
    void *obj = __nw__7TObjectFUl(0x38);
    if (obj != 0) {
        TObjBoss8PillerCtrl__ct(obj, boss8_piller_ctrl, tl_05, arg0, arg1);
    }
}
void create_boss8_demo_objects(void) {
    void *obj;
    if ((is_split_screen() == 0) && ((obj = __nw__7TObjectFUl(0x13C)) != 0)) {
        __ct__18TObjLiveCameraCtrlFP7TObject(obj, (*(s32 *)&tl_05));
    }
    TObjLiveMonitor::create((void *)(*(s32 *)&tl_05));
    ((TObjLiveMonitorSmall *)(*(s32 *)&tl_05))->spawn_for_each_fish();
    if ((is_room_enemy_set_cleared(get_current_floor(), 1) == 0) && ((obj = __nw__7TObjectFUl(0x1C)) != 0)) {
        __ct__17TObjBoss8DemoRoomFv(obj, (*(s32 *)&tl_05));
    }
}
