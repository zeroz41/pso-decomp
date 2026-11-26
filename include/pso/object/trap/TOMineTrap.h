#ifndef PSO_OBJECT_TRAP_TOMINETRAP_H
#define PSO_OBJECT_TRAP_TOMINETRAP_H

#include "types.h"
#include "pso/object/trap/TOMine.h"

struct TObjPlayer;

// The player flag (0x10000) that shows a mine to a player beyond 200 units or
// another room.
s32 can_see_traps(TObjPlayer *player);
// m_name of every TOMineTrap; TObjPlayer counts and finds traps by it.
extern const char *mine_trap_name;

struct TOMineTrap : public TOMine {
    // owner: the actor that placed it; kind 0-3 picks the attack; slot is its index among the owner's traps.
    TOMineTrap(TObjBase *owner, s16 kind, s16 slot);
    virtual ~TOMineTrap();
    virtual void spawn_disp_objects();
    virtual void set_armed();
    virtual void spawn_blast_particle();
    // The client id of the player that placed it (0xFFFF for none); get_trap_type reads it.
    void set_trap_type(u16 type);
    virtual const char *get_name();
    virtual void run_task();
    u8 _pad37C[0x2];
    u16 trap_number;
    s32 owner_message_shown;
    u16 get_trap_type();
    // Names inferred: the mode, the trap number 6x80 packets match, the instance flag set_instance writes.
    s16 get_mode();
    u16 get_trap_number();
    static int get_instance();
    static int get_trap_count();
    static int set_instance(int instance);
    static int set_trap_count(int trap_count);
    void set_state();
    s32 find_target_in_range();
    void set_triggered();
    static void destroy_matching_traps();
    // A mine trap for owner (a player on this floor) unless v2 is off, kind/slot are out
    // of range or this is a boss or no-item area; NULL then.
    static TOMineTrap *create_placed_trap(TObjBase *owner, s16 kind, s16 slot);
    void*get_mine_data_ptr();
    virtual s32 select_melee_contact_body(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual f32 receive_physical_attack(void *, f32);
    void send_state_packet(u16 idx);
    s32 show_owner_message(TObjChara *player);
};

LAYOUT_ASSERT(TOMineTrap_size, sizeof(TOMineTrap) == 0x384);
#endif
