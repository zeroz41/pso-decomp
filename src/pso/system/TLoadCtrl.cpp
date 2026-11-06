#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8001C5E8.h"
#include "pso/system/TLoadCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdLoadQuestGC.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"

extern u8 lbl_805D4A78;

u8 TAdSinglePlyChrSelectGC::get_chr_select_state() {
    return lbl_805D4A78;
}

extern s32 guild_card_save_file_block_count;

s32 TAdSinglePlyChrSelectGC__sub_8001C5F0(void) {
    return guild_card_save_file_block_count;
}

extern u32 TLoadCtrl__instance;

void TLoadCtrl::set_field1C(s32 arg0) {
    if ((void *) TLoadCtrl__instance != NULL) {
        *(s32 *)((s8 *)TLoadCtrl__instance + 0x1C) = arg0;
    }
}

struct Base_8001C8B8_8001C61C { char pad[0x18]; };
struct VObj_8001C8B8_8001C61C : Base_8001C8B8_8001C61C {
    virtual void m0(s32);
};

struct RecoveredGlobal_8001C828___vt__9TLoadCtrl {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8001C7A0___vt__9TLoadCtrl { s32 value; u8 remaining[0x14]; };

struct Vec_8001C620 { s32 x, y, z; };

struct Obj_8001C620 { u8 pad[0x1C]; s32 f1c; s32 f20; };

extern "C" {
s32 __nw__7TObjectFUl(int);
s32 __ct__7TObjectFP7TObject(void *, void *);
s32 __ct__9TAdFadeGCFP7TObjectPv(int, int, int);
extern RecoveredGlobal_8001C828___vt__9TLoadCtrl __vt__9TLoadCtrl;
extern s32 TLoadCtrl__class_name;
extern s32 TLoadCtrl__loading_mode;
extern s32 TLoadCtrl__fade_task;
extern s32 tl_fade;
u8 *TLoadCtrl__ct(TLoadCtrl *arg0, s32 arg1);
u8 * __dt__7TObjectFv(void *, s16);
void queue_destruction__7TObjectFv(void *arg0);
void __dl__7TObjectFPv(s32);
u8 *__dt__9TLoadCtrlFv(u8 *arg0, s16 arg1);
bool TLoadCtrl__sub_8001C60C(void);
void TNowLoading__sub_8001D4D4(void);
u8 *TCameraCtrl__ct(u8 *arg0, void *parent);
void TLoadCtrl__sub_80226DA0(s32 index);
s32 select_area_entrance(void *);
void fn_8034AD2C(void);
extern s32 lbl_80515BA0[];
extern s32 tl_su;
extern s32 tl_camera;
s32 TNowLoading__ct(s32, void *, void *);
void set_active_camera_pose(u8 *arg0, u8 *arg1);
s32 activate_camera_mode(s32 arg0);
}
void update_sound_request_slots(void);
extern "C" {
s32 __ct__14TAdFloorLoadGCFP7TObjectPv(s32, void *, int);
extern u8 lbl_804349CC[];
extern Vec_8001C620 lbl_804349D8;
extern Vec_8001C620 lbl_804349E4;
void TNowLoading__sub_8001D4D0(void);
void fn_8034AD28(void);
void reset__11TCameraCtrlFv(void);

bool TLoadCtrl__sub_8001C60C(void) {
    return (*(s32 *)&TLoadCtrl__instance) != 0;
}

void TLoadCtrl::render() {  }

extern void *camera_ctrl_instance;

typedef char RecoveredGlobal_8001C828___vt__9TLoadCtrl_size[sizeof(RecoveredGlobal_8001C828___vt__9TLoadCtrl) == 0x18 ? 1 : -1];

void TLoadCtrl::run_task() {
    Obj_8001C620 *self = (Obj_8001C620 *)this;
    s32 o;
    if (TLoadCtrl__instance != 0U) {
        if ((u32)TLoadCtrl__fade_task != 0U && ((TObject *)TLoadCtrl__fade_task)->all_parents_unqueued_for_destruction() == 0) {
            TLoadCtrl__fade_task = 0;
        }
        if (++self->f20 == 2) {
            switch (TLoadCtrl__loading_mode) {
            case 0:
                o = __nw__7TObjectFUl(0x3C);
                if ((u32)o != 0) {
                    TNowLoading__ct(o, self, lbl_804349CC);
                }
                break;
            case 1:
                o = __nw__7TObjectFUl(0x20);
                if ((u32)o != 0) {
                    TAdLoadQuestGC__ct((void *)o, this);
                }
                break;
            case 2:
                break;
            case 3:
                o = __nw__7TObjectFUl(0x1C);
                if ((u32)o != 0) {
                    __ct__14TAdFloorLoadGCFP7TObjectPv(o, self, 0);
                }
                break;
            case 4:
                o = __nw__7TObjectFUl(0x1C);
                if ((u32)o != 0) {
                    __ct__14TAdFloorLoadGCFP7TObjectPv(o, self, 1);
                }
                break;
            }
        }
        if (self->f1c != 0) {
            controller_stuff();
            TKeyBoardControl::update_input_frame();
        }
        update_sound_request_slots();
        Vec_8001C620 a = lbl_804349D8;
        Vec_8001C620 b = lbl_804349E4;
        activate_camera_mode(9);
        set_active_camera_pose((u8 *)&a, (u8 *)&b);
    }
}

u8 *__dt__9TLoadCtrlFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8001C7A0___vt__9TLoadCtrl *)&__vt__9TLoadCtrl).value;
        if ((void *) (*(u8 * *)&TLoadCtrl__fade_task) != NULL) {
            queue_destruction__7TObjectFv(((*(u8 * *)&TLoadCtrl__fade_task)));
            (*(u8 * *)&TLoadCtrl__fade_task) = NULL;
        }
        if ((u32) TLoadCtrl__instance != 0U) {
            TLoadCtrl__instance = 0U;
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

u8 *TLoadCtrl__ct(TLoadCtrl *load_ctrl, s32 arg1) {
    s32 temp_r3;
    s32 var_r0;
    __ct__7TObjectFP7TObject((void *)load_ctrl, (void *)arg1);
    *(s32 **)((s8 *)load_ctrl + 0x18) = &__vt__9TLoadCtrl.value;
    load_ctrl->m_1c = 1;
    TLoadCtrl__fade_task = 0;
    load_ctrl->m_20 = 0;
    *(s32 *)((s8 *)load_ctrl + 0) = (s32) TLoadCtrl__class_name;
    if (((u32) (*(u32 *)&TLoadCtrl__loading_mode) == 0U) || ((u32) (*(u32 *)&TLoadCtrl__loading_mode) == 1U)) {
        temp_r3 = __nw__7TObjectFUl(0x38);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = __ct__9TAdFadeGCFP7TObjectPv(temp_r3, tl_fade, 2);
        }
        TLoadCtrl__fade_task = var_r0;
    }
    return (u8 *)load_ctrl;
}

void TLoadCtrl::cleanup_scene() {
    u32 t;

    t = TLoadCtrl__instance;
    if (t != 0U) {
        queue_destruction__7TObjectFv((void *)t);
        TLoadCtrl__instance = 0U;
    }
    switch (TLoadCtrl__loading_mode) {
    case 0:
        TLobby::release_bgm_resource();
        TNowLoading__sub_8001D4D0();
        break;
    case 1:
        TLobby::release_bgm_resource();
        TAdLoadQuestGC__sub_8030984C();
        break;
    case 3:
    case 4:
        TLobby::release_bgm_resource();
        fn_8034AD28();
        break;
    }
    TCameraCtrl::reset_default_view();
    reset__11TCameraCtrlFv();
    if (camera_ctrl_instance != NULL) {
        if (camera_ctrl_instance != NULL) {
            ((VObj_8001C8B8_8001C61C *)camera_ctrl_instance)->m0(1);
        }
        camera_ctrl_instance = NULL;
    }
    TCameraCtrl::reset_view_state();
    TCameraCtrl::init_default_view();
    TCameraCtrl::create();
}

void TLoadCtrl::start_loading(u32 arg0) {
    s32 temp_r3;
    u8 *load_ctrl;
    u8 *temp_cam;
    u32 var_r31;
    var_r31 = arg0;
    TCameraCtrl::reset_view_state();
    TCameraCtrl::init_default_view();
    if (var_r31 == 2U) {
        temp_r3 = select_area_entrance(lbl_80515BA0);
        if (temp_r3 == 0) {
            var_r31 = 3U;
        } else if (temp_r3 == 1) {
            var_r31 = 4U;
        } else {
            var_r31 = 0U;
        }
    }
    switch ((s32) var_r31) {
    case 0:
        TNowLoading__sub_8001D4D4();
        break;
    case 1:
        TAdLoadQuestGC__sub_80309850();
        break;
    case 3:
    case 4:
        fn_8034AD2C();
        break;
    }
    TLoadCtrl__loading_mode = (s32) var_r31;
    switch ((s32) var_r31) {
    case 2:
        break;
    case 0:
        TLoadCtrl__sub_80226DA0(0);
        break;
    case 1:
        TLoadCtrl__sub_80226DA0(3);
        break;
    case 3:
        TLoadCtrl__sub_80226DA0(1);
        break;
    case 4:
        TLoadCtrl__sub_80226DA0(2);
        break;
    }
    temp_cam = (u8 *) __nw__7TObjectFUl(0x1D4);
    if (temp_cam != NULL) {
        TCameraCtrl__ct(temp_cam, (void *)tl_camera);
    }
    load_ctrl = (u8 *) __nw__7TObjectFUl(0x24);
    if (load_ctrl != NULL) {
        load_ctrl = TLoadCtrl__ct((TLoadCtrl *)load_ctrl, tl_su);
    }
    TLoadCtrl__instance = (u32) load_ctrl;
}

void TLoadCtrl::poll_default() { TLoadCtrl::start_loading((u32)((void*)(0))); }
}
