#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/misc/TCameraCtrl_8006A03C.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

struct O_8006A044 { u8 pad[0x1c0]; s32 id; f32 v; };

struct Big_8006A13C { u8 pad[0x70]; u8 unk70[0x10]; };

struct Sel_8006A13C { u8 busy; u8 pad1; u16 slot; u8 pad4[0xC]; };

extern void *camera_ctrl_instance;
extern "C" {
s32 obj_testFlags30__14TObjCollidableFUl(u32, s32);
s32 is_split_screen();
}
void reset_cameras_to_actor(void *actor, s32 arg1);
extern "C" {
s32 is_quest_active();
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
u32 get_player_by_client_id(s32);
extern Sel_8006A13C TCameraCtrl__view_state;
extern Big_8006A13C controller_input_state;
extern s32 local_client_id;
void*TCameraCtrl::get_params() { return (char*)this + 0x20; }

extern const f32 lbl_805D8FE8;
extern const f32 lbl_805D8FEC;
extern const f32 lbl_805D8FF0;

void TCameraCtrl__sub_8006A044(s32 id, f32 v) {
    O_8006A044 *p;
    if ((*(O_8006A044 * *)&camera_ctrl_instance) != 0) {
        (*(O_8006A044 * *)&camera_ctrl_instance)->v = v;
        p = (*(O_8006A044 * *)&camera_ctrl_instance);
        p->id = id;
        start_pad_rumble_all(0x60, id);
    }
}

void TCameraCtrl::set_shake_preset(s32 arg0) {
    void *p;

    if ((void *) camera_ctrl_instance != NULL) {
        switch (arg0) {
        case 0:
            *(s32 *)((s8 *)camera_ctrl_instance + 0x1C0) = 0x14;
            p = camera_ctrl_instance;
            *(f32 *)((s8 *)p + 0x1C4) = (f32) lbl_805D8FE8;
            start_pad_rumble_all(0x60, 0x14);
            return;
        case 1:
            *(s32 *)((s8 *)camera_ctrl_instance + 0x1C0) = 0x1E;
            p = camera_ctrl_instance;
            *(f32 *)((s8 *)p + 0x1C4) = (f32) lbl_805D8FEC;
            start_pad_rumble_all(0xA0, 0x1E);
            return;
        case 2:
            *(s32 *)((s8 *)camera_ctrl_instance + 0x1C0) = 0x1E;
            p = camera_ctrl_instance;
            *(f32 *)((s8 *)p + 0x1C4) = (f32) lbl_805D8FF0;
            start_pad_rumble_all(0xE0, 0x1E);
            break;
        }
    }
}
void TCameraCtrl::cycle_spectate_target() {
    void *pad;
    u32 q;
    u32 pl;
    s8 tries;
    u16 slot;
    s32 i;
    if (is_split_screen() != 0 || is_quest_active() != 0) {
        return;
    }
    pad = controller_input_state.unk70;
    if (is_on_current_screen__11TCameraCtrlFv(pad, 0x20000) == 0 ||
        TWindowShortListCtrl__check_controller_button(pad, 0x10) == 0 ||
        is_on_current_screen__11TCameraCtrlFv(pad, 0x10000) == 0 ||
        (pl = get_player_by_client_id(local_client_id)) == 0 ||
        (tries = 0, TCameraCtrl__view_state.busy != 0) ||
        get_current_area() == 0xB ||
        get_current_area() == 0xC ||
        get_current_area() == 0xD ||
        get_current_area() == 0xE ||
        get_current_area() == 0x1E ||
        get_current_area() == 0x1F ||
        get_current_area() == 0x20 ||
        get_current_area() == 0x21 ||
        get_current_area() == 0xF ||
        get_current_area() == 0x12 ||
        get_current_area() == 0) {
        return;
    }
    slot = TCameraCtrl__view_state.slot;
    while (tries <= 3) {
        slot++;
        tries++;
        if (slot >= 4) {
            slot = 0;
        }
        q = get_player_by_client_id(slot);
        if (q != 0) {
            if (((TObjPlayer *)q)->get_field_3e4() == ((TObjPlayer *)pl)->get_field_3e4() && obj_testFlags30__14TObjCollidableFUl(q, 0x02000000) == 0) {
                TCameraCtrl__view_state.slot = slot;
                reset_cameras_to_actor((void *)q, 0);
                for (i = 0; i < 4; i++) {
                    u32 p = get_player_by_client_id(i);
                    if (p != 0) {
                        ((TObjPlayer *)p)->refresh_equipment_slot();
                    }
                }
                return;
            }
        }
    }
}
}
