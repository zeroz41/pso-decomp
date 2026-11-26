#ifndef PSO_OBJECT_TDEADSPOT_H
#define PSO_OBJECT_TDEADSPOT_H

#include "types.h"
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

struct NJS_TEXLIST;

class TDeadSpot : public TObject {
public:
    TDeadSpot(TObject *parent, const Vec *point, NJS_TEXLIST *texture, s32 selector, s32 delay, f32 maxScale);
    virtual ~TDeadSpot();
    virtual void run_task();
    virtual void render();
    // Spawns a dead spot with the given texture selector and maximum scale; the wrappers fix both.
    static void spawn(const Vec *point, s32 selector, s32 delay, f32 maxScale);
    static void spawn_kind0_scale2_5(const Vec *point, s32 delay);
    static void spawn_kind0_scale7_5(const Vec *point, s32 delay);
    static void spawn_kind0_scale15(const Vec *point, s32 delay);
    static void spawn_kind0_scale25(const Vec *point, s32 delay);
    static void spawn_kind1_scale2_5(const Vec *point, s32 delay);
    static void spawn_kind1_scale7_5(const Vec *point, s32 delay);
    static void spawn_kind1_scale15(const Vec *point, s32 delay);
    static void spawn_kind1_scale25(const Vec *point, s32 delay);
    static void spawn_kind2_scale2_5(const Vec *point, s32 delay);
    static void spawn_kind2_scale7_5(const Vec *point, s32 delay);
    static void spawn_kind2_scale15(const Vec *point, s32 delay);
    static void spawn_kind2_scale25(const Vec *point, s32 delay);
    // The shared corpse mark model the spots draw with, loaded and freed with the floor.
    static void load_resource();
    static void free_resource();
    ParticleStripVertex verts[4]; // 0x1C
    Vec center;                    // 0x7C
    Vec corners[4];                // 0x88
    NJS_TEXLIST *texture;     // 0xB8
    s32 selector;                  // 0xBC, texture number
    f32 max_scale;                 // 0xC0
    f32 scale;                     // 0xC4, drawn while above zero
};

class TUnk_80494A10 : public TDeadSpot {
public:
    TUnk_80494A10(TObject *parent, const Vec *point, NJS_TEXLIST *texture, s32 selector, s32 delay, f32 maxScale);
    virtual ~TUnk_80494A10();
    virtual void run_task();
    f32 alpha;  // 0-1, fades the spot in once it is drawn
};
LAYOUT_ASSERT(TDeadSpot_size, sizeof(TDeadSpot) == 0xC8);
LAYOUT_ASSERT(TUnk_80494A10_size, sizeof(TUnk_80494A10) == 0xCC);

extern const char *dead_spot_class_name;

struct CornerRow {
    u8 pad[0x88];
    Vec corners[4];
};

#endif
