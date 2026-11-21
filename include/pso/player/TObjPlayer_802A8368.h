#ifndef PSO_PLAYER_TOBJPLAYER_802A8368_H
#define PSO_PLAYER_TOBJPLAYER_802A8368_H

#include "types.h"

struct TEffIndirectCtrl;
extern "C" {
void clear_indirect_effect_ctrl_table(void);
void reset_indirect_effect_ctrl_table(void);
}
void setup_indirect_tev_alternate(TEffIndirectCtrl *ctrl, s32 unused, s32 sampler, s32 arg3);
void setup_indirect_tev_ordinary(TEffIndirectCtrl *ctrl, s32 sampler, s32 scale, s32 second);

#endif
