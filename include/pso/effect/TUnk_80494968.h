#ifndef PSO_EFFECT_TUNK_80494968_H
#define PSO_EFFECT_TUNK_80494968_H
#include "types.h"
#include "pso/effect/TAttackTrace.h"

class TUnk_80494968 : public TAttackTrace {
public:
    static TUnk_80494968 *create(u32, u32);
    void clear_segments();
    virtual ~TUnk_80494968();
    virtual void vfunc_6(void *, void *);
    virtual void shift_line_buffer_down();
    void sub_800D7818(s32, s32);
    virtual void render();
    virtual void run_task();
    s32 segment_count;
    u8 unk_20[0x100];
    s32 m_120;
    u8 unk_124[0x4];
};
typedef char TUnk_80494968_size[sizeof(TUnk_80494968) == 0x128 ? 1 : -1];

#endif
