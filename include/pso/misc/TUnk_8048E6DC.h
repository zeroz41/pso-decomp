#ifndef PSO_MISC_TUNK_8048E6DC_H
#define PSO_MISC_TUNK_8048E6DC_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_8048E6DC : public TObjBase {
public:
    virtual ~TUnk_8048E6DC();
    virtual void render();
    virtual void run_task();
    u8 unk_90[0x1C];
};
typedef char TUnk_8048E6DC_size[sizeof(TUnk_8048E6DC) == 0xAC ? 1 : -1];

#endif
