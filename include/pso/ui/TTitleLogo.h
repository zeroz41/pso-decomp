#ifndef PSO_UI_TTITLELOGO_H
#define PSO_UI_TTITLELOGO_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TTitleLogo : public TObject {
public:
    TTitleLogo(TObject *parent);
    virtual ~TTitleLogo();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
};
LAYOUT_ASSERT(TTitleLogo_size, sizeof(TTitleLogo) == 0x20);

#endif
