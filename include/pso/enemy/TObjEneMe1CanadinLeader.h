#ifndef PSO_ENEMY_TOBJENEME1CANADINLEADER_H
#define PSO_ENEMY_TOBJENEME1CANADINLEADER_H

#include "types.h"
#include "pso/enemy/TObjEneMe1Canadin.h"

struct TObjEneMe1CanadinLeader : public TObjEneMe1Canadin {
    TObjEneMe1CanadinLeader(TObject *parent, void *set_data);
    virtual ~TObjEneMe1CanadinLeader();
    virtual void run_task();
    virtual void vfunc_105();
    virtual void vfunc_106();
    virtual void vfunc_107();
    virtual s32 vfunc_108();
    virtual int vfunc_109();
    virtual void vfunc_110(s32);
    virtual void vfunc_111(s32);
    virtual void vfunc_112(s32);
    virtual void vfunc_113();
    virtual int vfunc_116();
    virtual void vfunc_117(u32);
    u8 pad_4CC[0x2C];
    static void update_formation_state(void *arg0);
    static void *create(void *arg0);
    void set_flag3c8_bit40();
    void set_flag3c8_bit20();
    void set_flag3c8_bit8();
    void set_attack_flag();
    void set_leader_index(s32 arg1, s32 arg2);
    static void update_fade_sequence(void *pv);
    static void *create_canadin(void *arg0, void *arg1, void *arg2, void *arg3);
};

typedef char TObjEneMe1CanadinLeader_size[sizeof(TObjEneMe1CanadinLeader) == 0x4F8 ? 1 : -1];

#endif
