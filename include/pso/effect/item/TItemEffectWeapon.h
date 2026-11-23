#ifndef PSO_EFFECT_ITEM_TITEMEFFECTWEAPON_H
#define PSO_EFFECT_ITEM_TITEMEFFECTWEAPON_H

#include "pso/system/TrailStrip.h"
#include "pso/item/TItemHeapObject.h"

class TItemEffectWeapon : public TItemHeapObject {
public:
    TItemEffectWeapon(saddr parent, s32 param);
    virtual ~TItemEffectWeapon();
    void run_task();
    void update_hidden();  // each frame the weapon is hidden (TItemWeapon::update_equipped)
    void update_shown();   // each frame the weapon is shown
public:
    typedef TrailStripVertex TrailVertex;
    void render_trail();
    void push_trail_interpolated(const f32* first, const f32* second);
    void push_trail_entry(const f32* first, const f32* second);
    static TrailVertex* allocate_trail_buffer();
    static void release_trail_buffer(void* buffer);
    static void free_static_effects();
    static void initialize_static_effects();
    TrailVertex* vertices;
    s32 vertex_count;
    u32 color;
    s32 pad_28;

    static const char *class_name;
};

#include <stddef.h>
LAYOUT_ASSERT(WeaponTrailVertexSize, sizeof(TItemEffectWeapon::TrailVertex) == 0x10);
LAYOUT_ASSERT(WeaponTrailVertexColor, offsetof(TItemEffectWeapon::TrailVertex, color) == 0xC);
LAYOUT_ASSERT(WeaponTrailBufferOffset, offsetof(TItemEffectWeapon, vertices) == 0x1C);
LAYOUT_ASSERT(WeaponTrailCountOffset, offsetof(TItemEffectWeapon, vertex_count) == 0x20);
LAYOUT_ASSERT(WeaponTrailColorOffset, offsetof(TItemEffectWeapon, color) == 0x24);
LAYOUT_ASSERT(WeaponTrailSize, sizeof(TItemEffectWeapon) == 0x2C);

#endif
