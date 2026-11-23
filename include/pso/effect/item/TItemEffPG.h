#ifndef PSO_EFFECT_ITEM_TITEMEFFPG_H
#define PSO_EFFECT_ITEM_TITEMEFFPG_H

#include <stddef.h>
#include "types.h"
#include "pso/item/TUnk_804E355C.h"

struct GinjaTextureList;
struct NJS_OBJECT;
class TUnk_804F0BF0;

// TItemEffPG's parameters (init_params fills in the defaults).
struct S_8035016C : S_802E451C {
    f32 max_radius;      // at most 50
    f32 required_charge;
    f32 radius_step;     // added to the radius each frame
    NJS_OBJECT *model;   // the weapon's second model
    GinjaTextureList *texture_list;
    S_8035016C *init_params();
};

struct TItemEffPG : public TUnk_804E355C {
    TItemEffPG(TObject *parent, S_8035016C *params);
    virtual ~TItemEffPG();
    virtual s32 consume_charge();
    virtual void run_task();

    static const char *class_name;

    f32 max_radius;      // run_task grows body.radius by radius_step a frame up to it
    f32 radius_step;
    f32 required_charge; // photon blast charge spent to keep the effect alive
    TUnk_804F0BF0 *visual;
    static void create(TObject *parent, S_8035016C *params);
    static void create(TObject *parent, S_8035016C *params, s32 count); // makes a TUnk_804F0C08
};

LAYOUT_ASSERT(S_8035016C_size, sizeof(S_8035016C) == 0x3C);
LAYOUT_ASSERT(TItemEffPG_charge_offset, offsetof(TItemEffPG, required_charge) == 0xCC);
LAYOUT_ASSERT(TItemEffPG_visual_offset, offsetof(TItemEffPG, visual) == 0xD0);
LAYOUT_ASSERT(TItemEffPG_size, sizeof(TItemEffPG) == 0xD4);

#endif
