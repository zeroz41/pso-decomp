#ifndef PSO_MISC_TOTRAPCHAINSAW_H
#define PSO_MISC_TOTRAPCHAINSAW_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TOTrapChainSaw : public TUnk_804AFBF8 {
    TOTrapChainSaw(TObject *parent, void *set_data);
    virtual ~TOTrapChainSaw();
    virtual void vfunc_14();
    virtual void decode_params();
    virtual void vfunc_16();
    virtual int check_player_contact();
    virtual void vfunc_18();
    virtual s32 consume_counter(void *);
    virtual void set_hit_cooldown_for_player(void *);
    virtual int clear_field_d8();
    virtual void update_extension();
    virtual void update_sweep();
    virtual void update_state();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual f32 scale_by_level(f32 farg0);
    virtual void render();
    virtual void run_task();
    u32 m_c8;
    u32 m_cc;
    u32 m_d0;
    u32 m_d4;
    u8 unk_D8[0x4];
    u32 m_dc;
    u32 m_e0;
    u32 m_e4;
    u32 m_e8;
    u32 m_ec;
    u8 _padF0[0x4];
    u32 m_f4;
    void update_demo();
};

typedef char TOTrapChainSaw_size[sizeof(TOTrapChainSaw) == 0xF8 ? 1 : -1];
#endif
