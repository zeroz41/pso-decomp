#ifndef PSO_WEAPON_TITEMWEAPONSBERILLSHANDS_H
#define PSO_WEAPON_TITEMWEAPONSBERILLSHANDS_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

struct NJS_TEXLIST;

// S-Berill's Hands (weapon group 0x8E): #1 sets weapon flag 0x800 once pad_1f8 has counted down, and from then on
// transform_model_node sways the projected texture by pad_1fc.
class TItemWeaponSBerillsHands : public TItemWeapon {
public:
    virtual ~TItemWeaponSBerillsHands();
    virtual void transform_model_node();
    virtual void draw_held_model();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    TItemWeaponSBerillsHands(TObject *parent, u8 *item);
    s32 pad_1f8;   // 5 at construction and on emit_marker_effects, counted down by update_weapon
    s32 pad_1fc;   // 182 * sin(pad_200) once pad_1f8 is 0
    s32 pad_200;   // angle, +0xB6 per update_weapon
};

TItem *create_s_berills_hands_weapon(u8 *item);

// The texture list holding the shared capture texture (defined in TObjPlayer_80083594.cpp).
extern NJS_TEXLIST shared_capture_texture_list;
NJS_TEXLIST *get_shared_capture_texture_list(void);

#endif
