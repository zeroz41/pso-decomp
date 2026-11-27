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
    TObject *owner;
};
LAYOUT_ASSERT(TUnk_804EE470_size, sizeof(TTitleLogo) == 0x20);

#endif
