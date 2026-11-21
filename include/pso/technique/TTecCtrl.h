#ifndef PSO_TECHNIQUE_TTECCTRL_H
#define PSO_TECHNIQUE_TTECCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct BmlResource;

class TTecCtrl : public TObject {
public:
    virtual ~TTecCtrl();
    virtual void run_task();
    virtual void render();
public:
    static s32 classify_distance_band(s32 arg0, s32 arg1, u16 arg2);
    static s32 is_technique_ready();
};

// technic.bml (the technique effects' models and motions) and technic.gvm (their textures), loaded by
// load_technique_resources.
extern BmlResource *technique_effect_bml;
extern void **lbl_805D63B0;

extern "C" {
void TLobby__sub_8022F068(void);
void *__ct__8TTecCtrlFv(void *tec_ctrl, void *parent);
}
void *get_technique_base_params(int a0);

#endif
