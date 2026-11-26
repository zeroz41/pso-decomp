#ifndef PSO_OBJECT_KEY_TODUMMYKEYCAVE01_H
#define PSO_OBJECT_KEY_TODUMMYKEYCAVE01_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_TEXLIST;

struct TODummyKeyCave01 : public TObjBase {
    static void free_resources();
    static void load_resources();
    TODummyKeyCave01(TObject *parent, void *set_data);
    virtual ~TODummyKeyCave01();
    void init_from_set_data();
    NJS_TEXLIST *off_textures;  // the key's textures while its switch is off
    NJS_TEXLIST *on_textures;   // ... and while it is on
    u16 id;                     // the floor switch it shows, 0xFFFF for none (always on)
    u16 switch_state;                   // the switch's state last frame
    NJS_ARGB color;             // tint of the glow; red pulses while the switch is off
    Vec key_offset;             // where the key head sits; y rises while the switch is on
    s32 pulse_rising;           // 1 while the pulse is brightening
    s32 model_variant;          // set_params[1] low half: picks the model on the battle floors
    s32 sound_kind;             // set_params[2] low half: which sound the tone plays (0-6)
    s32 mute_off_sound;         // set_params[2] high half: 1 plays no sound when the switch turns off
    s32 sound_delay;            // set_params[1] high half: frames before the sound
    s32 key_angle;              // the head's spin, wound up while the switch is on
    s32 spins;                  // 1: the head spins instead of rising (some floors)
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TODummyKeyCave01_size, sizeof(TODummyKeyCave01) == 0xD4);

#endif
