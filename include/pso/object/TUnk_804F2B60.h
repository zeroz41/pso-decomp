#ifndef PSO_OBJECT_TUNK_804F2B60_H
#define PSO_OBJECT_TUNK_804F2B60_H

#include "types.h"
#include "pso/TObject.h"

// The quest add_damage_to opcode's one-shot task: on its first update it
// hands the player with client_id a direct attack of kind 21 for `damage`
// and destroys itself.
class TUnk_804F2B60 : public TObject {
public:
    TUnk_804F2B60(u16 client_id, TObject *parent, f32 damage);
    virtual ~TUnk_804F2B60();
    virtual void run_task();
    f32 damage;
    u16 client_id;
    u8 pad_22[0x2];
};

typedef char TUnk_804F2B60_size[sizeof(TUnk_804F2B60) == 0x24 ? 1 : -1];

#endif
