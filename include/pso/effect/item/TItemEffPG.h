#ifndef PSO_EFFECT_ITEM_TITEMEFFPG_H
#define PSO_EFFECT_ITEM_TITEMEFFPG_H

#include <stddef.h>
#include <dolphin/mtx.h>
#include "types.h"
#include "pso/item/TUnk_804E355C.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"

struct NJS_TEXLIST;
struct NJS_OBJECT;
class TItemEffPGModel;
class TParticleCtrl;

// TItemEffPG's parameters (init_params fills in the defaults).
struct ItemEffPGParams : S_802E451C {
    f32 max_radius;      // at most 50
    f32 required_charge;
    f32 radius_step;     // added to the radius each frame
    NJS_OBJECT *model;   // the weapon's second model
    NJS_TEXLIST *texture_list;
    ItemEffPGParams *init_params();
};

struct TItemEffPG : public TUnk_804E355C {
    TItemEffPG(TObject *parent, ItemEffPGParams *params);
    virtual ~TItemEffPG();
    virtual s32 consume_charge();
    virtual void run_task();

    static const char *class_name;

    f32 max_radius;      // run_task grows body.radius by radius_step a frame up to it
    f32 radius_step;
    f32 required_charge; // photon blast charge spent to keep the effect alive
    TItemEffPGModel *visual;
    static void create(TObject *parent, ItemEffPGParams *params);
    static void create(TObject *parent, ItemEffPGParams *params, s32 count); // makes a TItemEffPGLimited
};

LAYOUT_ASSERT(ItemEffPGParams_size, sizeof(ItemEffPGParams) == 0x3C);
LAYOUT_ASSERT(TItemEffPG_charge_offset, offsetof(TItemEffPG, required_charge) == 0xCC);
LAYOUT_ASSERT(TItemEffPG_visual_offset, offsetof(TItemEffPG, visual) == 0xD0);
LAYOUT_ASSERT(TItemEffPG_size, sizeof(TItemEffPG) == 0xD4);

// A TItemEffPG that lasts a number of uses instead of spending photon blast charge.
class TItemEffPGLimited : public TItemEffPG {
public:
    TItemEffPGLimited(TObject *parent, ItemEffPGParams *params, s32 count);
    virtual ~TItemEffPGLimited();
    virtual s32 consume_charge();
    s32 uses_left; // consume_charge counts it down and fails at 0
};
LAYOUT_ASSERT(TItemEffPGLimited_size, sizeof(TItemEffPGLimited) == 0xD8);

// What a TItemEffPG shows: the weapon's second model and its child turning in
// opposite directions, growing with the collider's radius, with a particle
// emitter; it fades out once the TItemEffPG ends.
class TItemEffPGModel : public TObject {
public:
    TItemEffPGModel(TItemEffPG *parent, ItemEffPGParams *params);
    virtual ~TItemEffPGModel();
    virtual void render();
    virtual void run_task();
    void begin_fade();

    s32 item_id;
    NJS_OBJECT *model;  // drawn turning by rotation_y, its child by child_rotation_y
    NJS_TEXLIST *texture_list;
    NJS_ARGB color;
    TParticleCtrl *particle;
    s32 rotation_y;
    s32 child_rotation_y;
    f32 max_scale;
    Vec scale;
    f32 scale_step;
    s32 fading;  // set by begin_fade: color.a falls until the effect ends
    Vec position;
};

LAYOUT_ASSERT(TItemEffPGModel_size, sizeof(TItemEffPGModel) == 0x68);
LAYOUT_ASSERT(TItemEffPGModel_color_offset, offsetof(TItemEffPGModel, color) == 0x28);
LAYOUT_ASSERT(TItemEffPGModel_scale_offset, offsetof(TItemEffPGModel, scale) == 0x48);
LAYOUT_ASSERT(TItemEffPGModel_position_offset, offsetof(TItemEffPGModel, position) == 0x5C);

#endif
