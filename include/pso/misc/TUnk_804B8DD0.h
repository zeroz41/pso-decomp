#ifndef PSO_MISC_TUNK_804B8DD0_H
#define PSO_MISC_TUNK_804B8DD0_H
#include "types.h"
#include "pso/TObject.h"

// Gogo-ball goal marker, spawned in pairs by TUnk_804B8E00::run_task.
class TUnk_804B8DD0 : public TObject {
public:
    TUnk_804B8DD0(Vec *pos, s32 arg2, s32 arg3, s32 lifetime, TObject *parent);
    TUnk_804B8DD0(Vec *pos, s32 arg2, s32 lifetime, TObject *parent);
    virtual ~TUnk_804B8DD0();
    void update_effects();
    virtual void render();
    virtual void run_task();
    Vec pos;
    s32 m_28;
    s32 age;      // inferred: counts frames up to lifetime
    s32 m_30;
    s32 lifetime; // inferred: run_task destroys the marker when age reaches it
    s32 m_38;
    s32 active;   // inferred: set while the sync flags select this marker
    s32 m_40;
};
typedef char TUnk_804B8DD0_size[sizeof(TUnk_804B8DD0) == 0x44 ? 1 : -1];

#endif
