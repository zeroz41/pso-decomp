#ifndef PSO_MISC_TBREAKUPMDL_H
#define PSO_MISC_TBREAKUPMDL_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/TObject.h"

class TUnk_8048FA00;

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
    s32 collect_node_positions(u8 *arg1, s32 arg2);
    s32 build_node_records(u8 *arg1, s32 arg2);
    void copy(void* q);
    u8 unk_3C[0x18];
    u8 *setup_pieces(s32 arg1, s32 arg2, f32 farg0);
    u8 *init_from_model(s32 arg1);
    static TUnk_8048FA00 *init(void *mem, int model, int motion, f32 frames);
};

// One node record of a breakup model: where its piece starts and how it flies off (the De Rol Le breakup
// effects copy pos into each piece's position and rotate vel into its velocity).
struct BreakupNodeRecord {
    u8 pad_0[4];
    Vec pos;
    Vec vel;
};

// The 0x10-byte breakup model built by init_from_model (vtable 0x8048FA00).
class TUnk_8048FA00 {
public:
    u8 pad_0[4];
    BreakupNodeRecord *m_records;
    u8 pad_8[4];
    virtual ~TUnk_8048FA00();
};

typedef char TBreakUpMdl_size[sizeof(TBreakUpMdl) == 0x54 ? 1 : -1];
#endif
