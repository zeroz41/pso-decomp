#ifndef PSO_OBJECT_TRAP_TOTRAPCHAINSAW_H
#define PSO_OBJECT_TRAP_TOTRAPCHAINSAW_H

#include "types.h"
#include <stddef.h>
#include "pso/object/base/TObjMapObject.h"

class TObjPlayer;

struct TOTrapChainSaw : public TObjMapObject {
    TOTrapChainSaw(TObject *parent, void *set_data);
    virtual ~TOTrapChainSaw();
    virtual void vfunc_14();
    virtual void decode_params();
    virtual void vfunc_16();
    virtual void check_player_contact();
    virtual void vfunc_18(TObjPlayer *player);
    virtual s32 consume_counter(TObjPlayer *player);
    virtual void set_hit_cooldown_for_player(TObjPlayer *player);
    virtual void clear_field_d8();
    virtual void update_extension();
    virtual void update_sweep();
    virtual void update_state();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual f32 scale_by_level(f32 level);
    virtual void render();
    virtual void run_task();
    u32 m_c8;
    s32 max_offset;     // set_params[1] high half: how far it extends or sweeps
    s32 step;           // set_params[1] low half: the extension or yaw step per frame
    s32 yaw_offset;
    s32 hit_cooldown[4];
    s32 switch_id;      // set_params[0] clamped to 0-255: the floor switch it follows
    s32 pause_timer;    // frames it waits after turning around
    s32 switch_on;      // the switch's state this frame
    u32 behavior;       // set_params[2] high half (0 or 1): which update runs, 0 update_extension, 1 update_sweep
    void update_demo();
    static void load_shared_resource();
    static void unload_static_data();
};

LAYOUT_ASSERT(TOTrapChainSaw_size, sizeof(TOTrapChainSaw) == 0xF8);
LAYOUT_ASSERT(TOTrapChainSawCooldownOffset, offsetof(TOTrapChainSaw, hit_cooldown) == 0xD8);
#endif
