#ifndef PSO_ITEM_TUNK_804F112C_H
#define PSO_ITEM_TUNK_804F112C_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_804F112C : public TItemObject {
public:
    TUnk_804F112C(TObject *parent, u8 *item);
    // Declared first: apply_use_effect is the key function, so its TU emits the vtable.
    virtual void apply_use_effect();
    virtual ~TUnk_804F112C();
    static TUnk_804F112C *create(u8 *item);

    void send_obj_position_event(s32 kind);
    // The use effects of techniques 8 down to 0 (apply_use_effect's table).
    void set_phase_18();
    void fn_803530A0();
    void update_player_object();
    void fn_80353110();
    void fn_80353134();
    void update_shield();
    void fn_80353194();
    void fn_803531D0();
    void fn_803531F8();
};

#endif
