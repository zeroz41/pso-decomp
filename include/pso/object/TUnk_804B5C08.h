#ifndef PSO_OBJECT_TUNK_804B5C08_H
#define PSO_OBJECT_TUNK_804B5C08_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_804B5C08 : public TObjBase {
public:
    virtual ~TUnk_804B5C08();
    virtual void vfunc_13(s32);
    virtual void render();
    virtual void run_task();
    u8 unk_90[0x4];
    s32 m_94;
    u8 unk_98[0x4];
    float m_9c;
};
typedef char TUnk_804B5C08_size[sizeof(TUnk_804B5C08) == 0xA0 ? 1 : -1];

#endif
