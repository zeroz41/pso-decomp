#ifndef PSO_ITEM_TITEMTIMEREVENT_H
#define PSO_ITEM_TITEMTIMEREVENT_H

#include "types.h"
#include "pso/item/TItemHeapObject.h"

struct TItemTimerEvent : public TItemHeapObject {
    TItemTimerEvent(TItemHeapObject *parent, u16 client, s32 period);
    virtual ~TItemTimerEvent();
    virtual void apply_effect() = 0;
    virtual void advance_timer();
    virtual void run_task();
    u16 client_id;
    u8 _pad1E[0x2];
    u32 interval;
    u32 elapsed;
    uaddr player;
    static void clear_timer_slot(u16 client_id);
    static void start_event_by_index(u16 client_id);
    static void check_battle_ctrl(int client);
    static void notify_if_active(int client);
    static void clear_active();
    static const char *class_name;
    static const char class_name_string[];
};

LAYOUT_ASSERT(TItemTimerEvent_size, sizeof(TItemTimerEvent) == 0x2C);
#endif
