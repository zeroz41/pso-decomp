#ifndef PSO_WEAPON_TITEMATTACKER_H
#define PSO_WEAPON_TITEMATTACKER_H

#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>
#include "types.h"

// Called with a timer's object when the timer runs out.
typedef void (*ItemTimerCallback)(TObject *object);

// The hit a delayed weapon attack carries to its target (launch_shot,
// launch_rare_weapon_special, TUnk_804A2260::sub_80124C90).
struct DelayedWeaponHit {
    void copy_from(DelayedWeaponHit *source_record);
    s32 reserved;   // always 0
    s32 kind;       // TItemWeapon::deliver_hit's attack_kind
    s32 weapon;     // item id of the weapon
    u16 source;     // entity id of the attacker
    u16 target;     // entity id of the target
    s16 collider;   // the target's collision body
    f32 damage;     // TItemWeapon::deliver_hit's scale
};

class TItemAttacker : public TObject {
public:
    TItemAttacker(TObject *parent, const Vec *position, s32 frames, DelayedWeaponHit *attack_record);
    virtual ~TItemAttacker();
    virtual void run_task();
public:
    void deliver_delayed_weapon_hit();
    // Calls expire(object) after frames frames unless object is destroyed
    // first; nothing when object is NULL.
    static void spawn_item_timer(TObject *object, ItemTimerCallback expire, s32 frames);
    DelayedWeaponHit hit;
    s32 done;          // set once the hit is delivered or the target is gone
    Vec target_pos;    // the target body's center when spawned
    Vec origin;
};

LAYOUT_ASSERT(TItemAttacker_size, sizeof(TItemAttacker) == 0x50);

extern "C" {
void TItemAttacker__sub_8010349C(TObject *attacker);
void TItemBuff__ct(void);
}
extern s32 item_buffer_temp_mode;
extern void *item_buff_buffer;

void spawn_item_attacker(TObject *parent, const Vec *position, s32 frames, DelayedWeaponHit *attack_record);
s32 create_item_buff(s32 size);
saddr get_item_chunk_buffer(int a0);

#endif
