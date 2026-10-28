#ifndef PSO_OBJECT_TUNK_804B5E48_H
#define PSO_OBJECT_TUNK_804B5E48_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_804B5E48 : public TObjCollidable {
public:
    virtual ~TUnk_804B5E48();
    void *destroy_seasonal_object(s16);
    int get_anim_frame();
    s32 advance_anim_time(s32, f32);
    u8 unk_AC[0x4];
    f32 m_b0;
};

#endif
