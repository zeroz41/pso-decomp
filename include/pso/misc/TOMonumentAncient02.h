#ifndef PSO_MISC_TOMONUMENTANCIENT02_H
#define PSO_MISC_TOMONUMENTANCIENT02_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TOMonumentAncient02 : public TUnk_804AFBF8 {
    TOMonumentAncient02(TObject *parent, void *set_data);
    virtual ~TOMonumentAncient02();
    virtual void vfunc_6(s16 *, s32);
    virtual void interact(s32 client);
    s32 m_c8;  // 1 once its story flag is set: it shakes and its light pulses
    s32 brightening;  // 1 while the light brightens
    u32 m_d0;  // the story flag it waits for
    u32 sound_id;  // the sound it loops once active
    f32 light_color[4];  // the light's constant material colour (a, r, g, b)
    u32 effect;  // its particle effect
    s32 in_view;  // 1 while update_object_view_visibility sees it
    virtual void run_task();
    virtual void render();
    static void *create(void *arg0);
    static void free_shared_data();
    static void load_resources();
};

typedef char TOMonumentAncient02_size[sizeof(TOMonumentAncient02) == 0xF0 ? 1 : -1];

#endif
