#include "types.h"
#include "pso/item/TUnk_804A0668.h"
#include "pso/item/TUnk_804A0688.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/boss/TBoss3Volopt.h"

struct Base_8011E140_8011DA9C { char pad[0x18]; };
struct VObj_8011E140_8011DA9C : Base_8011E140_8011DA9C {
    virtual void m0(int);
};

struct RecoveredGlobal_8011DC90___vt__15TItemTimerEvent {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
u32 get_player_by_client_id(u16);
void fn_8011085C(u8 *arg0, s32 arg1);
extern struct VObj_8011E140_8011DA9C *item_timer_event_instance;
void fn_801108C8(u8 *arg0, s32 arg1);
void disallow_rendering__7TObjectFv(TObject *arg0);
s32 __ct__15TItemHeapObjectFP7TObject(void *);
extern s32 __vt__15TItemTimerEvent[];
extern s32 TItemTimerEvent__class_name;
u8 *TItemTimerEvent__ct(TItemTimerEvent *arg0, s32 arg1, s16 arg2, s32 arg3);
void *__dt__13TUnk_804A0568Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A0588Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A05A8Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A05C8Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A05E8Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A0608Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A0628Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A0648Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A0668Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A0688Fv(void *arg0, s16 arg1);
void *__dt__15TItemTimerEventFv(void *arg0, s16 arg1);
s32 test_action_mask__10TObjPlayerFl(s32, s32);
s32 is_item_area_enabled();
s32 TObjectV8047c128_subtract_hp(u8 *arg0, s16 arg1);
void __dt__15TItemHeapObjectFv(void *, int);
s32 fn_8011E1D4();
void __dl__15TItemHeapObjectFPv(void *);
s32 obj_isState3_324__9TObjCharaFv(s32);
s32 obj_testFlags30__14TObjCollidableFUl(s32, s32);
s32 set_flag_10000__10TObjPlayerFv();

void TUnk_804A0668::vfunc_7() {
    if (test_action_mask__10TObjPlayerFl(this->m_28, 0x1C) != 0) {
        this->m_24 = (this->m_24 + 1);
    }
}

void TUnk_804A0688::vfunc_6() {
    ((TBoss3Volopt *)(this->m_28))->get_field_3e0();
    if ((is_item_area_enabled() == 1) && (obj_isState3_324__9TObjCharaFv(this->m_28) == 0) && (obj_testFlags30__14TObjCollidableFUl(this->m_28, 0x800) == 0)) {
        TObjectV8047c128_subtract_hp((u8 *)this->m_28, 1);
    }
}

void TUnk_804A0688::vfunc_7() {
    if (test_action_mask__10TObjPlayerFl(this->m_28, 0x1C) != 0) {
        this->m_24 = (this->m_24 + 1);
    }
}

void TItemTimerEvent::vfunc_7() {
    this->m_24 = (this->m_24 + 1);
}

void TItemTimerEvent::run_task() {
    this->m_28 = get_player_by_client_id(this->m_1c);
    if ((u32) this->m_28 == 0U) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if ((s32) this->m_24 == (s32) this->m_20) {
        this->vfunc_6();
        this->m_24 = 0;
        return;
    }
    this->vfunc_7();
}

void *__dt__15TItemTimerEventFv(void *item_heap_object, s16 arg1) {
    if (item_heap_object != NULL) {
        *(s32 **)((s8 *)item_heap_object + 0x18) = __vt__15TItemTimerEvent;
        __dt__15TItemHeapObjectFv(item_heap_object, 0);
        if (arg1 > 0) {
            __dl__15TItemHeapObjectFPv(item_heap_object);
        }
    }
    return item_heap_object;
}

extern s32 lbl_804A0568[];

typedef char RecoveredGlobal_8011DC90___vt__15TItemTimerEvent_size[sizeof(RecoveredGlobal_8011DC90___vt__15TItemTimerEvent) == 0x20 ? 1 : -1];
u8 *TItemTimerEvent__ct(TItemTimerEvent *item_timer_event, s32 arg1, s16 arg2, s32 arg3) {
    __ct__15TItemHeapObjectFP7TObject(item_timer_event);
    *(s32 **)((s8 *)item_timer_event + 0x18) = &(*(RecoveredGlobal_8011DC90___vt__15TItemTimerEvent *)&__vt__15TItemTimerEvent).value;
    *(s32 *)((s8 *)item_timer_event + 0) = (s32) TItemTimerEvent__class_name;
    *(s16 *)&item_timer_event->m_1c = arg2;
    *(s32 *)&item_timer_event->m_28 = 0;
    *(s32 *)&item_timer_event->m_20 = arg3;
    *(s32 *)&item_timer_event->m_24 = 0;
    disallow_rendering__7TObjectFv((item_timer_event));
    return (u8 *)item_timer_event;
}

void *__dt__13TUnk_804A0568Fv(void *item_timer_event, s16 arg1) {
    if (item_timer_event != NULL) {
        *(s32 **)((s8 *)item_timer_event + 0x18) = lbl_804A0568;
        __dt__15TItemTimerEventFv(item_timer_event, (s16)(0));
        if (arg1 > 0) {
            __dl__15TItemHeapObjectFPv(item_timer_event);
        }
    }
    return item_timer_event;
}

extern s32 lbl_804A0588[];

void *__dt__13TUnk_804A0588Fv(void *item_timer_event, s16 arg1) {
    if (item_timer_event != NULL) {
        *(s32 **)((s8 *)item_timer_event + 0x18) = lbl_804A0588;
        __dt__15TItemTimerEventFv(item_timer_event, (s16)(0));
        if (arg1 > 0) {
            __dl__15TItemHeapObjectFPv(item_timer_event);
        }
    }
    return item_timer_event;
}

extern s32 lbl_804A05A8[];

void *__dt__13TUnk_804A05A8Fv(void *item_timer_event, s16 arg1) {
    if (item_timer_event != NULL) {
        *(s32 **)((s8 *)item_timer_event + 0x18) = lbl_804A05A8;
        __dt__15TItemTimerEventFv(item_timer_event, (s16)(0));
        if (arg1 > 0) {
            __dl__15TItemHeapObjectFPv(item_timer_event);
        }
    }
    return item_timer_event;
}

extern s32 lbl_804A05C8[];

void *__dt__13TUnk_804A05C8Fv(void *item_timer_event, s16 arg1) {
    if (item_timer_event != NULL) {
        *(s32 **)((s8 *)item_timer_event + 0x18) = lbl_804A05C8;
        __dt__15TItemTimerEventFv(item_timer_event, (s16)(0));
        if (arg1 > 0) {
            __dl__15TItemHeapObjectFPv(item_timer_event);
        }
    }
    return item_timer_event;
}

extern s32 lbl_804A05E8[];

void *__dt__13TUnk_804A05E8Fv(void *item_timer_event, s16 arg1) {
    if (item_timer_event != NULL) {
        *(s32 **)((s8 *)item_timer_event + 0x18) = lbl_804A05E8;
        __dt__15TItemTimerEventFv(item_timer_event, (s16)(0));
        if (arg1 > 0) {
            __dl__15TItemHeapObjectFPv(item_timer_event);
        }
    }
    return item_timer_event;
}

extern s32 lbl_804A0608[];

void *__dt__13TUnk_804A0608Fv(void *item_timer_event, s16 arg1) {
    if (item_timer_event != NULL) {
        *(s32 **)((s8 *)item_timer_event + 0x18) = lbl_804A0608;
        __dt__15TItemTimerEventFv(item_timer_event, (s16)(0));
        if (arg1 > 0) {
            __dl__15TItemHeapObjectFPv(item_timer_event);
        }
    }
    return item_timer_event;
}

extern s32 lbl_804A0628[];

void *__dt__13TUnk_804A0628Fv(void *item_timer_event, s16 arg1) {
    if (item_timer_event != NULL) {
        *(s32 **)((s8 *)item_timer_event + 0x18) = lbl_804A0628;
        __dt__15TItemTimerEventFv(item_timer_event, (s16)(0));
        if (arg1 > 0) {
            __dl__15TItemHeapObjectFPv(item_timer_event);
        }
    }
    return item_timer_event;
}

extern s32 lbl_804A0648[];

void *__dt__13TUnk_804A0648Fv(void *item_timer_event, s16 arg1) {
    if (item_timer_event != NULL) {
        *(s32 **)((s8 *)item_timer_event + 0x18) = lbl_804A0648;
        __dt__15TItemTimerEventFv(item_timer_event, (s16)(0));
        if (arg1 > 0) {
            __dl__15TItemHeapObjectFPv(item_timer_event);
        }
    }
    return item_timer_event;
}

extern s32 lbl_804A0668[];

void *__dt__13TUnk_804A0668Fv(void *item_timer_event, s16 arg1) {
    if (item_timer_event != NULL) {
        *(s32 **)((s8 *)item_timer_event + 0x18) = lbl_804A0668;
        __dt__15TItemTimerEventFv(item_timer_event, (s16)(0));
        if (arg1 > 0) {
            __dl__15TItemHeapObjectFPv(item_timer_event);
        }
    }
    return item_timer_event;
}

extern s32 lbl_804A0688[];

void *__dt__13TUnk_804A0688Fv(void *item_timer_event, s16 arg1) {
    if (item_timer_event != NULL) {
        *(s32 **)((s8 *)item_timer_event + 0x18) = lbl_804A0688;
        __dt__15TItemTimerEventFv(item_timer_event, (s16)(0));
        if (arg1 > 0) {
            __dl__15TItemHeapObjectFPv(item_timer_event);
        }
    }
    return item_timer_event;
}

void TItemTimerEvent::clear_timer_slot(u16 arg0) {
    if (((void *) (*(u8 * *)&item_timer_event_instance) != NULL) && (arg0 < 0xCU)) {
        fn_8011085C((*(u8 * *)&item_timer_event_instance), arg0);
    }
}

void TItemTimerEvent::start_event_by_index(u16 arg0) {
    if (((void *) (*(u8 * *)&item_timer_event_instance) != NULL) && (arg0 < 0xCU)) {
        fn_801108C8((*(u8 * *)&item_timer_event_instance), arg0);
    }
}

void TItemTimerEvent::check_battle_ctrl(int arg0) {
    if (get_player_by_client_id(arg0) != 0U) {
        fn_8011E1D4();
    }
}

void TItemTimerEvent::notify_if_active(int arg0) {
    if (get_player_by_client_id(arg0) != 0U) {
        set_flag_10000__10TObjPlayerFv();
    }
}

void TItemTimerEvent::clear_active() {
    if (item_timer_event_instance != NULL) {
        item_timer_event_instance->m0(1);
    }
    item_timer_event_instance = NULL;
}

}
