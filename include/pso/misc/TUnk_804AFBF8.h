#ifndef PSO_MISC_TUNK_804AFBF8_H
#define PSO_MISC_TUNK_804AFBF8_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_804AFBF8 : public TObjCollidable {
public:
    virtual ~TUnk_804AFBF8();
    void *destroy_key_base(s16);
    s32 is_in_view_depth(f32);
    void update_anim_phase();
    virtual void render();
    virtual void run_task();
    u32 m_ac;
    f32 m_b0;
    u32 m_b4;
    f32 m_b8;
    u32 m_bc;
    f32 m_c0;
    u32 m_c4;
};

#endif
