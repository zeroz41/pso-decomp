#ifndef PSO_WEAPON_TUNK_804A4948_H
#define PSO_WEAPON_TUNK_804A4948_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Base of the S-rank weapons (create_srank_common_weapon makes the plain one).
class TUnk_804A4948 : public TItemWeapon {
public:
    TUnk_804A4948(TObject *parent, u8 *item);
    virtual ~TUnk_804A4948();
    void send_srank_stat_extra(uaddr, s32);
    void send_srank_stat_extra_to_locks();
    virtual void emit_marker_effects();
    virtual void on_equipped();
    virtual void deliver_hit(TObjPlayer *attacker, TObjChara *target, s32 attack_kind, f32 scale, s32 body);
    void set_special_selector(u8);
    // First virtual of its own; the empty base body sits at the end of TUnk_804A3A20's text.
    virtual void vfunc_62();

    s32 kind;  // get_item_index()
};

#endif
