#ifndef PSO_ENEMY_FLY_TOBJENEBM3FLYNEST_H
#define PSO_ENEMY_FLY_TOBJENEBM3FLYNEST_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/render/RenderFadeState.h"

// The nest of the Bm3 flies: it keeps up to six TObjEneBm3Fly children alive (start_num at
// first, total_num in all, both from its set parameters) and sends TObjEneBm3FlyNest_CarryFly
// effects out when it is hit.
struct TObjEneBm3FlyNest : public TObjEneDD {
    TObjEneBm3FlyNest(TObject *parent, void *set_data);
    virtual ~TObjEneBm3FlyNest();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
    virtual void vfunc_28();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void vfunc_88();
    // Slot 104, the first one TObjEneDD leaves to its subclasses; run_task calls it in demo mode.
    virtual void init();
    virtual void render_with_state_debug();
    void init_params();
    // dispatch_action's handlers, one per state; reason is TObjEneDD's 4 enter / 3 check /
    // 0 update / 5 leave.
    void handle_appear(s32 reason);         // state 0
    void state_initial_emit(s32 reason);    // state 1
    void state_wait(s32 reason);            // state 2
    void handle_event(s32 reason);          // state 3
    void sub_800B318C(s32 reason);          // state 4
    void update_state(s32 reason);          // state 5
    void state_spawn(s32 reason);           // state 6
    void handle_motion_event(s32 reason);   // state 7
    void state_dying(s32 reason);           // state 8
    void handle_state(s32 reason);          // state 9
    s32 sub_800B3AC8();
    Vec *sub_800B2A54();
    s32 copy_target_state(s32 sound_id);
    static void capture_attachment(void * _w0);
    static void handle_attachment_sample(s32);
    static u8 *sub_800B4158();
    void remove_child(u8 *child);
    s32 has_free_attack_slot(u16 id);
    void spawn_child();
    void update_replenish();
    void copy_pos();
    static void free_fly();
    static void *create(void *arg0);
    static void load_resources();
    static void init_vertex_table();

    u8 pad_374[0x4];
    s32 unk_378;         // TObjEneDD's area: set_field_378 stores it, state 7 returns to it
    f32 unk_37c;         // TObjEneDD's area: the ctor sets it to 10.0f
    u8 pad_380[0xC];
    s32 state;           // 0x38C "STATE : NORMAL/DEAD/FALLEN" (2/9/5) in render_with_state_debug
    s32 start_num;       // 0x390 "START NUM"
    s32 total_num;       // 0x394 "TOTAL NUM", capped by the set entry
    s32 unk_398[4];
    s32 unk_3a8;
    s32 unk_3ac;
    s32 unk_3b0;
    s32 unk_3b4;
    u16 unk_3b8[6];
    u16 unk_3c4;
    Vec unk_3c8[2];
    Vec unk_3e0[8];
    RenderFadeState fades[4];  // one per camera (render)
    f32 unk_4b0;         // the nest's height offset (render)
    u32 unk_4b4;         // update_replenish's state
    s32 unk_4b8;         // flies left to send out (spawn_child decrements it)
    s32 unk_4bc;
    s32 unk_4c0;
    s32 unk_4c4;
    s32 unk_4c8;
    s32 unk_4cc;
    s32 unk_4d0;
    s32 unk_4d4;
    f32 unk_4d8;
};

typedef char TObjEneBm3FlyNest_size[sizeof(TObjEneBm3FlyNest) == 0x4DC ? 1 : -1];


#endif
