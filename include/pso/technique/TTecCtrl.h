#ifndef PSO_TECHNIQUE_TTECCTRL_H
#define PSO_TECHNIQUE_TTECCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct BmlResource;

class TTecCtrl : public TObject {
public:
    TTecCtrl(TObject *parent);
    virtual ~TTecCtrl();
    virtual void run_task();
    virtual void render();
public:
    static s32 classify_distance_band(s32 arg0, s32 level, u16 arg2);
    static s32 is_technique_ready();

    u32 pad_1C;  // zeroed by the ctor
    u8 pad_20[4];
};
LAYOUT_ASSERT(TTecCtrlSize, sizeof(TTecCtrl) == 0x24);

// technic.bml (the technique effects' models and motions) and technic.gvm (their textures), loaded by
// load_technique_resources.
extern BmlResource *technique_effect_bml;
struct GinjaTextureList;
extern GinjaTextureList *lbl_805D63B0;

extern "C" {
void TLobby__sub_8022F068(void);
}
void *get_technique_base_params(int a0);

#endif
