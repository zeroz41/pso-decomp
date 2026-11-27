#ifndef PSO_ITEM_ITEMUSEEFFECTS_H
#define PSO_ITEM_ITEMUSEEFFECTS_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_804F112C : public TItemObject {
public:
    TUnk_804F112C(TObject *parent, u8 *item);
    // Declared first: apply_use_effect is the key function, so its TU emits the vtable.
    virtual void apply_use_effect();
    virtual ~TUnk_804F112C();
    static TItem *create(u8 *item);

    void inflict_status(s32 kind);
    // The use effects of techniques 8 down to 0 (apply_use_effect's table).
    void inflict_confusion();
    void inflict_slow();
    void inflict_shock();
    void inflict_paralysis();
    void inflict_poison();
    void restore_hp();
    void restore_tp();
    void send_nearby_players();
    void no_effect();
};

#endif
