#ifndef PSO_UNK_TUNK_804887C8_H
#define PSO_UNK_TUNK_804887C8_H
#include "types.h"
#include "pso/camera/TCameraController.h"

class TUnk_804887C8 : public TCameraController {
public:
    TUnk_804887C8();
    virtual ~TUnk_804887C8();
    virtual void run_task();
};
LAYOUT_ASSERT(TUnk_804887C8_size, sizeof(TUnk_804887C8) == 0x6C);

#endif
