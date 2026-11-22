#ifndef PSO_ITEM_TUNK_804EDD44_H
#define PSO_ITEM_TUNK_804EDD44_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"

class TUnk_804EDD44 : public TObject {
public:
    TUnk_804EDD44(TObject *parent, f32 *position, f32 *direction, s32 tint, s32 item_id);
    TUnk_804EDD44(TObject *parent, ActorBodyHit *hit, f32 *direction, s32 tint, s32 item_id);
    virtual ~TUnk_804EDD44();
    void anchor_card_effect();
    virtual void run_task();
    virtual void start_card_effect_flash();
    virtual void start_card_effect_trail();
    virtual void vfunc_8();
    void sub_8032E294();
    void destroy_effect_objects();
    void *particles[3];  // queued for destruction by destroy_effect_objects
    ActorBodyHit hit_target;
    s32 age;            // frames run: the flash starts at 0, the trail at 6, the effect ends at 12 (name inferred)
    u16 target_id;      // get_entity_id of hit_target's actor, 0xFFFF when placed at a position
    Vec direction;      // normalized by sub_8032E294
    Vec anchor_offset;  // direction times the hit body's radius: position is the body's center less this
    u32 tint;           // the particles' tint colour, 0 for none
    s32 rotation[3];    // x, y, z angles; y faces direction
    s32 item_id;        // the card, looked up with find_item_by_id
    Vec position;
};
LAYOUT_ASSERT(TUnk_804EDD44_size, sizeof(TUnk_804EDD44) == 0x70);

#endif
