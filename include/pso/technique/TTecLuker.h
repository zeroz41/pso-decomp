#ifndef PSO_TECHNIQUE_TTECLUKER_H
#define PSO_TECHNIQUE_TTECLUKER_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"

struct TTecLuker : public TUnk_804CC148 {
    virtual ~TTecLuker();
    virtual void vfunc_6(void *);
    virtual void run_task();
    u32 m_ec;
    u32 m_f0;
    s16 m_f4;
    u16 m_f6;
    u32 m_f8;
    void* m_fc;
    u8 _pad100[0x8];
    u32 m_108;
    u32 m_10c;
    void *destroy(s16 arg1);
    void update_player_target();
    static void apply_all_players();
    static void create_for_player(int arg0, s32 arg1);
    void init_fields(s16 arg1);
    void send_telepipe_packet();
    void create(void *arg1, void *arg2, void *arg3);
    void setup_telepipe_field();
    void send_swapped_telepipe_packet();
    void byteswap_telepipe_packet();
    void set_state(s32 v);
    static s32 is_parents_unqueued(u32 arg0);
    u8 *construct_field_collider(s32 arg1, s32 arg2, s32 arg3);
};

typedef char TTecLuker_size[sizeof(TTecLuker) == 0x110 ? 1 : -1];
#endif
