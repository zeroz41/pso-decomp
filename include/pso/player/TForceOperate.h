#ifndef PSO_PLAYER_TFORCEOPERATE_H
#define PSO_PLAYER_TFORCEOPERATE_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TForceOperate : public TObject {
    virtual ~TForceOperate();
    virtual void run_task();
    void* m_1c;
    static s32 destroy(s32 arg0, s16 arg1);
    void set_field_0(s16 v);
    u8 unk_20[0x4];
};

typedef char TForceOperate_size[sizeof(TForceOperate) == 0x24 ? 1 : -1];

extern "C" {
void *TForceOperate__ct(void *arg0, void *arg1, void *arg2);
}
void calc_death_sink_offset(void *arg0);
void reset_player_appearance_opacity(void *a0);
extern "C" {
void run_task__13TForceOperateFv(s32 arg0);
}
void save_render_material_state(u8 *arg0);
void update_player_appear_fade(u8 *arg0);
extern "C" {
void update_target_lock__10TObjPlayerFii(s32 arg0, s32 arg1);
}

#endif
