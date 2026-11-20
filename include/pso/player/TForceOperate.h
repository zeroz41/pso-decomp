#ifndef PSO_PLAYER_TFORCEOPERATE_H
#define PSO_PLAYER_TFORCEOPERATE_H

#include "types.h"
#include "pso/system/task/TObject.h"

#include "pso/unk/TUnk_8013E020.h"

// run_task is declared first: it is the key function that places the vtable at 0x804C3F60.
struct TForceOperate : public TObject {
    virtual void run_task();
    TForceOperate(TObject *parent, u16 id);
    virtual ~TForceOperate();
    TUnk_8013E020 m_1c;
};

typedef char TForceOperate_size[sizeof(TForceOperate) == 0x24 ? 1 : -1];

void calc_death_sink_offset(void *arg0);
void reset_player_appearance_opacity(void *a0);
void save_render_material_state(u8 *arg0);
void update_player_appear_fade(u8 *arg0);
extern "C" {
void update_target_lock(s32 arg0, s32 arg1);
}

#endif
