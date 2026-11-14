#ifndef PSO_UI_TUNK_804E0B28_H
#define PSO_UI_TUNK_804E0B28_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TWindowBase;

/* Character-select transition task (vtable 0x804E0B28): slides two status panels between position and target;
 * lbl_805D67E8 holds the live instance for the TWindowSubSymbolChat display callback. */
class TUnk_804E0B28 : public TObject {
public:
    TUnk_804E0B28(TObject *parent, s32 client);
    virtual ~TUnk_804E0B28();
    virtual void render();
    virtual void run_task();
    static void update_transition_anim_if_active();
    void update_transition_anim();

    f32 position0X;
    f32 position0Y;
    f32 target0X;
    f32 target0Y;
    f32 position1X;
    f32 position1Y;
    f32 target1X;
    f32 target1Y;
    s32 client;
    s32 timer;
    TObject *parent;
    TWindowBase *statusWindow;
    TWindowBase *callback;
};
typedef char TUnk_804E0B28_size[sizeof(TUnk_804E0B28) == 0x50 ? 1 : -1];

#endif
