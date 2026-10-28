#ifndef PSO_MISC_TUNK_8048E640_H
#define PSO_MISC_TUNK_8048E640_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_8048E640 : public TObjBase {
public:
    virtual ~TUnk_8048E640();
    virtual void render();
    virtual void run_task();
    u8 unk_90[0x4];
};
typedef char TUnk_8048E640_size[sizeof(TUnk_8048E640) == 0x94 ? 1 : -1];

#endif
