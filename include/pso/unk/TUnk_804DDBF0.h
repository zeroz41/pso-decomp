#ifndef PSO_UNK_TUNK_804DDBF0_H
#define PSO_UNK_TUNK_804DDBF0_H
#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/TUnk_804DDD28.h"

class TUnk_804DDBF0 : public TUnk_804DDD28 {
public:
    BmlMotionEntry motions[16];
    TUnk_804DDBF0();
    virtual s32 get_cell_address(s32, s32);
    virtual ~TUnk_804DDBF0();
    virtual int vfunc_5(s32);
    virtual int vfunc_6(s32, s32, s32);
    virtual int vfunc_7(s32, s32);
    virtual const s32 *vfunc_8(s32, s32);
    virtual int vfunc_9(s32, s32, s32);
    virtual int get_attack3_action();
    virtual int get_attack2_action();
    virtual int get_technique_action();
    virtual int vfunc_15();
    virtual void vfunc_14();
    virtual int vfunc_75();
    virtual int get_run_action();
    virtual int get_photon_blast_action();
    virtual int get_interact_action();
    virtual int get_death_action();
    virtual int get_hurt_action();
    virtual int vfunc_25();
    virtual int get_knockdown_action();
    virtual int vfunc_23();
    virtual int vfunc_22();
    virtual int get_use_item_action();
    virtual int vfunc_20();
    virtual int get_attack1_action();
    virtual int vfunc_4();
    virtual s32 *get_state_table(s32);
    virtual BmlMotionEntry *vfunc_76();
};
LAYOUT_ASSERT(TUnk_804DDBF0_size, sizeof(TUnk_804DDBF0) == 0x8C);

#endif
