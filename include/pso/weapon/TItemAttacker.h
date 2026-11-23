#ifndef PSO_WEAPON_TITEMATTACKER_H
#define PSO_WEAPON_TITEMATTACKER_H

#include "pso/system/task/TObject.h"
#include "types.h"

// Called with a timer's object when the timer runs out.
typedef void (*ItemTimerCallback)(TObject *object);

class TItemAttacker : public TObject {
public:
    TItemAttacker(saddr parent, saddr position, s32 frames, saddr attack_record);
    virtual ~TItemAttacker();
    virtual void run_task();
public:
    void copy_from(void *source_record);
    // Calls expire(object) after frames frames unless object is destroyed
    // first; nothing when object is NULL.
    static void spawn_item_timer(TObject *object, ItemTimerCallback expire, s32 frames);
};

extern "C" {
void TItemAttacker__sub_8010349C(uaddr attacker);
void TItemBuff__ct(void);
u8 *__ct__13TItemAttackerFllll(u8 *object, s32 parent, s32 position, s32 frames, s32 attack_record);
}
s32 create_item_buff(s32 size);
saddr get_item_chunk_buffer(int a0);

#endif
