#ifndef PSO_TECHNIQUE_TTECCTRL_H
#define PSO_TECHNIQUE_TTECCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct BmlResource;
struct TechniqueParams;
struct TObjPlayer;

class TTecCtrl : public TObject {
public:
    TTecCtrl(TObject *parent);
    virtual ~TTecCtrl();
    virtual void run_task();
    virtual void render();
public:
    static s32 classify_distance_band(s32 technique, s32 level, u16 slot);
    static s32 is_technique_ready();

    static const char *class_name;

    u32 pad_1C;  // zeroed by the ctor
    u8 pad_20[4];
};
LAYOUT_ASSERT(TTecCtrlSize, sizeof(TTecCtrl) == 0x24);

// technic.bml (the technique effects' models and motions) and technic.gvm (their textures), loaded by
// load_technique_resources.
extern BmlResource *technique_effect_bml;
struct NJS_TEXLIST;
extern NJS_TEXLIST *technique_texture_list;

// Row `kind` of technique_param_table.
TechniqueParams *get_technique_base_params(int kind);
// Casts technique `tech` from `pl` at the targets its technique data holds.
void launch_technique(s32 tech, s32 level, TObjPlayer *pl);
// Copies the lock-on cursor's targets for technique `kind` into owner's technique data.
void capture_technique_targets(int kind, TObjPlayer *owner);

void load_technique_resources(void);
void release_technique_resources(void);
// The band (0..) of a technique level, one per five levels.
s32 get_technique_level_tier(s32 level);
// The flags the technique's caster gets from its boosts and battle values.
u32 get_technique_caster_flags(s32 technique, u16 actor);

#endif
