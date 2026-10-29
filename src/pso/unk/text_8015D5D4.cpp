#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TObjMapObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TODoorBase.h"
#include "pso/map/FloorArea.h"

extern "C" {
s32 play_sound_effect(s32, void *, s32, s32);
extern "C" void update_open__10TODoorBaseFv();
extern "C" void update_opening__10TODoorBaseFv();
extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void update_demo__10TODoorBaseFv();
extern "C" void interact__14TObjCollidableFl();
extern "C" void get_name__8TObjBaseFv();
extern "C" void get_center__8TObjBaseFv();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void update_closing__10TODoorBaseFv();
extern "C" void init_door_switch_binding__10TODoorBaseFv();
extern "C" void update_closed__10TODoorBaseFv();
extern "C" void reset_motion_fields__14TObjCollidableFv();
extern "C" void render__13TObjMapObjectFv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void run_task__10TODoorBaseFv();
extern "C" void update_door_switch_state__10TODoorBaseFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
void *__vt__10TODoorBase[21] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__10TODoorBaseFv, (void *)&run_task__10TODoorBaseFv,
    (void *)&render__13TObjMapObjectFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__14TObjCollidableFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFl, (void *)&update_door_switch_state__10TODoorBaseFv, (void *)&update_closed__10TODoorBaseFv,
    (void *)&update_opening__10TODoorBaseFv, (void *)&update_open__10TODoorBaseFv, (void *)&update_closing__10TODoorBaseFv, (void *)&init_door_switch_binding__10TODoorBaseFv,
    (void *)&update_demo__10TODoorBaseFv,
};

void TODoorBase::play_door_sound() {
    if (!(this->door_flags & 1)) {
        switch ((u32)get_current_floor_area()) {
        case AREA_PIONEER2_EP1:
        case AREA_PIONEER2_EP2:
            play_sound_effect(0x42A04, (u8 *)&this->position, 0, 0);
            break;
        case AREA_FOREST1:
        case AREA_FOREST2:
            play_sound_effect(0x4BC07, (u8 *)&this->position, 0, 0);
            break;
        case AREA_CAVE1:
        case AREA_CAVE2:
        case AREA_CAVE3:
            play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
            break;
        case AREA_MINE1:
        case AREA_MINE2:
            play_sound_effect(0x4004BC00, (u8 *)&this->position, 0, 0);
            break;
        case AREA_RUINS1:
        case AREA_RUINS2:
        case AREA_RUINS3:
            play_sound_effect(0x4004BC07, (u8 *)&this->position, 0, 0);
            break;
        case AREA_BATTLE1:
        case AREA_BATTLE2:
            play_sound_effect(0x4004BC00, (u8 *)&this->position, 0, 0);
            break;
        }
    }
}

}
