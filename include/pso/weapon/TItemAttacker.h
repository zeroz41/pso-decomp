#ifndef PSO_WEAPON_TITEMATTACKER_H
#define PSO_WEAPON_TITEMATTACKER_H

#include "pso/system/task/TObject.h"
#include "types.h"

// Called with a timer's object when the timer runs out.
typedef void (*ItemTimerCallback)(TObject *object);

class TItemAttacker : public TObject {
public:
    TItemAttacker(s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    virtual ~TItemAttacker();
    virtual void run_task();
public:
    void copy_from(void *arg1);
    // Calls expire(object) after frames frames unless object is destroyed
    // first; nothing when object is NULL.
    static void spawn_item_timer(TObject *object, ItemTimerCallback expire, s32 frames);
};

extern "C" {
void TItemAttacker__sub_8010349C(u32 arg0);
void TItemBuff__ct(void);
u8 *__ct__13TItemAttackerFllll(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
}
s32 create_item_buff(s32 arg0);
extern "C" {
int get_item_chunk_buffer(int a0);
}

#endif
