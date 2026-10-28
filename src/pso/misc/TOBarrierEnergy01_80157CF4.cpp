#include "types.h"
#include "pso/TObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/misc/TLobby_80156B18.h"
#include "pso/misc/TOBarrierEnergy01_80158014.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/misc/TOAttackableCol.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

extern "C" {
void vfunc_20__17TOBarrierEnergy01Fv(void);

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void play_proximity_sound__17TOBarrierEnergy01Fv();
extern "C" void vfunc_16__17TOBarrierEnergy01Fv();
extern "C" void vfunc_17__17TOBarrierEnergy01Fv();
extern "C" void vfunc_18__17TOBarrierEnergy01Fv();
extern "C" void interact__14TObjCollidableFl();
extern "C" void get_name__8TObjBaseFv();
extern "C" void get_center__8TObjBaseFv();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void init_door_switch_binding__13TUnk_804B0BB8Fv();
extern "C" u8 lbl_80440188[];
extern "C" u8 lbl_804401A4[];
extern "C" u8 lbl_804401B8[];
extern "C" u8 lbl_804401D0[];
extern "C" void reset_motion_fields__14TObjCollidableFv();
extern "C" void render__17TOBarrierEnergy01Fv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void run_task__13TUnk_804B0BB8Fv();
extern "C" void update_door_switch_state__13TUnk_804B0BB8Fv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern void *bm_fs_obj_lazerguard_model_names[3];
extern void *bm_fs_obj_lazerguard_motion_names[2];
void *bm_fs_obj_lazerguard_model_names[3] = {
    (void *)&lbl_80440188, (void *)&lbl_804401A4, (void *)0x0,
};
__declspec(section ".data") void *bm_fs_obj_lazerguard_motion_names[2] = {
    (void *)&lbl_804401B8, (void *)0x0,
};
void *bm_fs_obj_lazerguard_resource_descriptor[4] = {
    (void *)&lbl_804401D0, (void *)&bm_fs_obj_lazerguard_model_names, (void *)&bm_fs_obj_lazerguard_motion_names, (void *)0x20001,
};
void *barrier_energy01_collision_body_parts[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x40a00000,
    (void *)0x41a00000, (void *)0x1, (void *)0x10003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *__vt__17TOBarrierEnergy01[21] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__17TOBarrierEnergy01Fv, (void *)&run_task__13TUnk_804B0BB8Fv,
    (void *)&render__17TOBarrierEnergy01Fv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__14TObjCollidableFv, (void *)&get_center__8TObjBaseFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFl, (void *)&update_door_switch_state__13TUnk_804B0BB8Fv, (void *)&play_proximity_sound__17TOBarrierEnergy01Fv,
    (void *)&vfunc_16__17TOBarrierEnergy01Fv, (void *)&vfunc_17__17TOBarrierEnergy01Fv, (void *)&vfunc_18__17TOBarrierEnergy01Fv, (void *)&init_door_switch_binding__13TUnk_804B0BB8Fv,
    (void *)&vfunc_20__17TOBarrierEnergy01Fv,
};

void*TOBarrierEnergy01::init() { TLobby__sub_80156BA8(this); return this; }

void TOBarrierEnergy01::vfunc_20() {  }
void TOBarrierEnergy01::play_ambient_loop_sound() {
    s32 arg0 = (s32)this;
    u32 global_state;
    global_state = get_current_area();
    switch (global_state) {
    case 1:
    case 2:
        play_persistent_sound(0x4CB09, (arg0), (arg0 + 0x38), 0, 0);
        return;
    case 3:
    case 4:
    case 5:
        play_persistent_sound(0x44B08, (arg0), (arg0 + 0x38), 0, 0);
        return;
    case 6:
    case 7:
        play_persistent_sound(0x4004CB02, (arg0), (arg0 + 0x38), 0, 0);
        return;
    case 8:
    case 9:
    case 10:
        play_persistent_sound(0x4004CB09, (arg0), (arg0 + 0x38), 0, 0);
        return;
    case 0:
        return;
    case 11:
        return;
    case 12:
        return;
    case 13:
        return;
    case 14:
        return;
    case 15:
        return;
    }
}

}
