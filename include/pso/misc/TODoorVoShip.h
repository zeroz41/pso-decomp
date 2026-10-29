#ifndef PSO_MISC_TODOORVOSHIP_H
#define PSO_MISC_TODOORVOSHIP_H

#include "types.h"
#include "pso/object/TObjMapObject.h"
#include "pso/system/NinjaTypes.h"

struct BmlResource;

// The sealed door of Vol Opt's ship: three seal lights burn on its signal
// model, each going out once its story flag is set; with all three out the
// door stops blocking players.
struct TODoorVoShip : public TObjMapObject {
    enum {
        SEAL_LIGHT_1 = 0x2,  // out once story flag 0x2C is set
        SEAL_LIGHT_2 = 0x4,  // out once story flag 0x2D is set
        SEAL_LIGHT_3 = 0x8,  // out once story flag 0x2E is set
        SEAL_LIGHTS = SEAL_LIGHT_1 | SEAL_LIGHT_2 | SEAL_LIGHT_3,
        FADE_RISING = 0x10   // light_color.a is rising
    };

    TODoorVoShip(TObject *parent, void *set_data);
    virtual ~TODoorVoShip();
    virtual void run_task();
    virtual void render();
    static void *create(void *set_data);
    static void free_static_data();
    static void load_shared_resource();

    u8 pad_c8[0x4];
    u32 light_flags;           // SEAL_LIGHT_* still burning, FADE_RISING
    AnimationMotion *shape_motion;  // the door's shape motion (fe_obj_fuuin_doa.njs)
    NJS_OBJECT *light_model;   // the signal model the seal lights hang on
    s32 light_texlist;
    NJS_ARGB light_color;      // the seal lights' constant material; a pulses -1..0

    static BmlResource *bml_resource;
};

typedef char TODoorVoShip_size[sizeof(TODoorVoShip) == 0xEC ? 1 : -1];

#endif
