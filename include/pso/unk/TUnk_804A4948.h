#ifndef PSO_UNK_TUNK_804A4948_H
#define PSO_UNK_TUNK_804A4948_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// Base of the S-rank weapons (create_srank_common_weapon makes the plain one).
class TUnk_804A4948 : public TItemWeapon {
public:
    TUnk_804A4948(TObject *parent, u8 *item);
    virtual ~TUnk_804A4948();
    s32 send_srank_stat_extra(u32, s32);
    void send_srank_stat_extra_to_locks();
    virtual void emit_marker_effects();
    virtual void vfunc_57();
    virtual void deliver_hit(s32 arg1, u8 *arg2, s32 arg3, s32 arg4, f32 farg0);
    void set_special_selector(u8);
    // First virtual of its own; the empty base body sits at the end of TUnk_804A3A20's text (0x801283B8).
    virtual void vfunc_62();

    s32 kind;  // get_item_index()
};

#endif
