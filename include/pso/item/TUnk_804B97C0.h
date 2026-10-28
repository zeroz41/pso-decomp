#ifndef PSO_ITEM_TUNK_804B97C0_H
#define PSO_ITEM_TUNK_804B97C0_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_804B97C0 : public TObjCollidable {
public:
    virtual ~TUnk_804B97C0();
    virtual void vfunc_14();
    virtual void vfunc_15();
    void*init_positions();
    void *dt(s16);
    virtual void render();
    virtual void run_task();
    u8 unk_AC[0x4];
    float m_b0;
};

#endif
