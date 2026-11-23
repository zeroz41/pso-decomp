#ifndef PSO_OBJECT_TRAP_TOMINETRAP_H
#define PSO_OBJECT_TRAP_TOMINETRAP_H

#include "types.h"
#include "pso/object/trap/TOMine.h"

struct TObjPlayer;

extern "C" s32 fn_80171314(TObjPlayer *player);

struct TOMineTrap : public TOMine {
    // owner: the actor that placed it; kind 0-3 picks the attack; slot is its index among the owner's traps.
    TOMineTrap(TObjBase *owner, s16 kind, s16 slot);
    virtual ~TOMineTrap();
    virtual void spawn_disp_objects();
    virtual void vfunc_86();
    virtual void vfunc_82();
    void sub_80171348(u16);
    virtual const char *get_name();
    virtual void run_task();
    u8 _pad37C[0x2];
    u16 m_37e;
    s32 m_380;
    u16 get_trap_type();
    static int get_trap_count();
    static int set_instance(int instance);
    static int set_trap_count(int trap_count);
    s32 matches_id(u16 id);
    void set_state();
    s32 find_target_in_range();
    void set_triggered();
    static void destroy_matching_traps();
    void*get_mine_data_ptr();
    virtual s32 select_melee_contact_body(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual f32 receive_physical_attack(void *, f32);
    void sync_position();
    void send_state_packet(u16 idx);
    s32 show_owner_message(TObjChara *player);
};

LAYOUT_ASSERT(TOMineTrap_size, sizeof(TOMineTrap) == 0x384);
#endif
