#ifndef PSO_UNK_TUNK_8048E5DC_H
#define PSO_UNK_TUNK_8048E5DC_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_8048E5DC : public TObject {
public:
    virtual ~TUnk_8048E5DC();
    void *dt(s16);
    virtual void render_shadows();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    f32 m_20;
    u8 unk_24[0x4];
    f32 m_28;
    u8 unk_2C[0x4];
    f32 m_30;
    u8 unk_34[0x4];
    f32 m_38;
};
typedef char TUnk_8048E5DC_size[sizeof(TUnk_8048E5DC) == 0x3C ? 1 : -1];

#endif
