#ifndef PSO_UNK_TUNK_804A6CC8_H
#define PSO_UNK_TUNK_804A6CC8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// The Yasminkov 2000H weapon class (vtable 0x804A6CC8; old names
// yasminkov_2000h_node_callback, yasminkov_2000h_ct): update_attack and
// update_idle show or shrink model node 2 (scale), emit_marker_effects
// starts the slide and update_weapon moves slide.y and ejects a casing; the
// model hook (slot 60) translates node 1 by slide. Made by
// create_yasminkov_2000h.
class TUnk_804A6CC8 : public TItemWeapon {
public:
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    virtual ~TUnk_804A6CC8();
    TUnk_804A6CC8(TObject *parent, u8 *item);
    s32 shown;           // 0x1F8: 1 while scale is full size (inferred name)
    WeaponVector scale;  // scale_current_matrix in vfunc_60
    s32 slide_state;     // 2 opening, 3 open, 1 closing, 0 closed
    WeaponVector slide;  // post_translate_matrix in vfunc_60
};

u8 *create_yasminkov_2000h(u8 *item);

#endif
