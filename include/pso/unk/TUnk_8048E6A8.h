#ifndef PSO_UNK_TUNK_8048E6A8_H
#define PSO_UNK_TUNK_8048E6A8_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TUnk_8048E6A8 : public TObjBase {
public:
    virtual ~TUnk_8048E6A8();
    virtual void render();
    virtual void run_task();
};
LAYOUT_ASSERT(TUnk_8048E6A8_size, sizeof(TUnk_8048E6A8) == 0x90);

#endif
