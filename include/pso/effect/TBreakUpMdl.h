#ifndef PSO_EFFECT_TBREAKUPMDL_H
#define PSO_EFFECT_TBREAKUPMDL_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"

class TUnk_8048FA00;
struct NJS_OBJECT;
struct NJS_MOTION;

struct TBreakUpMdl : public TObject {
    virtual ~TBreakUpMdl();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u8 _pad28[0xC];
    u32 m_34;
    u32 m_38;
    virtual void render();
    virtual void run_task();
    void init_alpha(s32 arg1, f32 farg0);
    void copy(void* q);
    u8 unk_3C[0x18];
};

// One node record of a breakup model: where its piece starts and how it flies off (the De Rol Le breakup
// effects copy pos into each piece's position and rotate vel into its velocity).
struct BreakupNodeRecord {
    u8 pad_0[4];
    Vec pos;
    Vec vel;
};

// The 0x10-byte breakup model (vtable 0x8048FA00).
class TUnk_8048FA00 {
public:
    s32 m_count;
    BreakupNodeRecord *m_records;
    s32 m_8;
    TUnk_8048FA00(long model, long motion, f32 frame);
    TUnk_8048FA00(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame);
    TUnk_8048FA00(long model);
    virtual ~TUnk_8048FA00();
    s32 collect_node_positions(u8 *node, s32 index);
    s32 build_node_records(u8 *node, s32 index);
};

LAYOUT_ASSERT(TBreakUpMdl_size, sizeof(TBreakUpMdl) == 0x54);
#endif
