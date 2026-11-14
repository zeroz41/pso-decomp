#ifndef PSO_UI_WINDOW_TWINDOWUSERSORT_H
#define PSO_UI_WINDOW_TWINDOWUSERSORT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowUserSort : public TWindowBase {
    // render is declared first: it is the key function that places the vtable in
    // TWindowUserSort.cpp while the destructor still calls TWindowDD::destroy_window_base by hand.
    virtual void render();
    virtual ~TWindowUserSort();
    u8 _pad1C[0x8];
    void* entries; // inferred: start of the entry list run_task, render and the constructor pass on
    u8 _pad28[0x38];
    u32 m_60;
    virtual void run_task();
};

typedef char TWindowUserSort_size[sizeof(TWindowUserSort) == 0x64 ? 1 : -1];
#endif
