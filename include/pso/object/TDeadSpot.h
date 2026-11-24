#ifndef PSO_OBJECT_TDEADSPOT_H
#define PSO_OBJECT_TDEADSPOT_H

#include "types.h"
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/system/task/TObject.h"

struct NJS_TEXLIST;

class TDeadSpot : public TObject {
public:
    TDeadSpot(TObject *parent, const Vec *point, NJS_TEXLIST *texture, s32 selector, s32 delay, f32 maxScale);
    virtual ~TDeadSpot();
    virtual void run_task();
    virtual void render();
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
    u8 m_C8[0x4];
};
LAYOUT_ASSERT(TDeadSpot_size, sizeof(TDeadSpot) == 0xC8);
LAYOUT_ASSERT(TUnk_80494A10_size, sizeof(TUnk_80494A10) == 0xCC);

#endif
