#ifndef PSO_BOSS_DARKFALZ_TOBJDFRECOVER_H
#define PSO_BOSS_DARKFALZ_TOBJDFRECOVER_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>

class TObjDFRecover : public TObject {
public:
    u8 _pad1C[0xC];
    s32 countdown;
 void *effect;
    s32 phase;
    u16 target_id;
    u8 _pad36[2];
    Vec cached_position;
    static TObjDFRecover *create(TObject *parent, u16 id, const Vec *position);
    TObjDFRecover(TObject *parent, u16 id, const Vec *position);
    virtual ~TObjDFRecover();
    virtual void run_task();
};

LAYOUT_ASSERT(TObjDFRecover_parent_offset, offsetof(TObjDFRecover, m_up) == 0x10);
LAYOUT_ASSERT(TObjDFRecover_countdown_offset, offsetof(TObjDFRecover, countdown) == 0x28);
LAYOUT_ASSERT(TObjDFRecover_effect_offset, offsetof(TObjDFRecover, effect) == 0x2C);
LAYOUT_ASSERT(TObjDFRecover_phase_offset, offsetof(TObjDFRecover, phase) == 0x30);
LAYOUT_ASSERT(TObjDFRecover_target_id_offset, offsetof(TObjDFRecover, target_id) == 0x34);
LAYOUT_ASSERT(TObjDFRecover_cached_position_offset, offsetof(TObjDFRecover, cached_position) == 0x38);

LAYOUT_ASSERT(TObjDFRecover_size, sizeof(TObjDFRecover) == 0x44);

#endif
