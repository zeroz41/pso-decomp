#ifndef PSO_OBJECT_TOBJDFDEMO1_H
#define PSO_OBJECT_TOBJDFDEMO1_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TObjDFDemo1 : public TObjBase {
public:
    virtual ~TObjDFDemo1();
    virtual void run_task();
    void draw_fading_model();
    void sub_8004E068();
    virtual void render();
    u8 unk_90[0x7C];
    s32 m_10c;
    u8 unk_110[0x4];
    f32 m_114;
    u8 unk_118[0x18];
};
typedef char TObjDFDemo1_size[sizeof(TObjDFDemo1) == 0x130 ? 1 : -1];

#endif
