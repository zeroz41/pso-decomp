#ifndef PSO_UI_WINDOW_TUNK_804CE964_H
#define PSO_UI_WINDOW_TUNK_804CE964_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

class TUnk_804CE964 : public TWindowBase {
public:
    virtual ~TUnk_804CE964();
    virtual void render();
    virtual void run_task();
    void * m_60;
    u8 unk_64[0x4];
    f32 m_68;
    u8 unk_6C[0x8];
};
typedef char TUnk_804CE964_size[sizeof(TUnk_804CE964) == 0x74 ? 1 : -1];

#endif
