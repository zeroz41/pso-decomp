#ifndef PSO_EFFECT_ITEM_TITEMEFFECTWEAPON_H
#define PSO_EFFECT_ITEM_TITEMEFFECTWEAPON_H

#include "types.h"
#include "pso/item/TItemHeapObject.h"

class TItemEffectWeapon : public TItemHeapObject {
public:
    TItemEffectWeapon(s32 arg1, s32 param);
    virtual ~TItemEffectWeapon();
    void run_task();
public:
    struct TrailVertex {
        f32 x, y, z;
        u32 color;
    };
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
    s32 field_28;
public:
    int decrement_timer();
    u8 *create_instance();
};

#include <stddef.h>
typedef char WeaponTrailVertexSize[(sizeof(TItemEffectWeapon::TrailVertex) == 0x10) ? 1 : -1];
typedef char WeaponTrailVertexColor[(offsetof(TItemEffectWeapon::TrailVertex, color) == 0xC) ? 1 : -1];
typedef char WeaponTrailBufferOffset[(offsetof(TItemEffectWeapon, vertices) == 0x1C) ? 1 : -1];
typedef char WeaponTrailCountOffset[(offsetof(TItemEffectWeapon, vertex_count) == 0x20) ? 1 : -1];
typedef char WeaponTrailColorOffset[(offsetof(TItemEffectWeapon, color) == 0x24) ? 1 : -1];
typedef char WeaponTrailSize[(sizeof(TItemEffectWeapon) == 0x2C) ? 1 : -1];

#endif
