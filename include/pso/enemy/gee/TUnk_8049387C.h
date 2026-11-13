#ifndef PSO_ENEMY_GEE_TUNK_8049387C_H
#define PSO_ENEMY_GEE_TUNK_8049387C_H
#include "types.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"

class TUnk_8049387C : public TObjEneMe1Gee {
public:
    virtual ~TUnk_8049387C();
    void run_task();
    virtual void vfunc_107();
    virtual void vfunc_117(u32);
    virtual void vfunc_106();
    virtual void vfunc_105();
    virtual s32 vfunc_108();
    virtual int vfunc_116(TObjChara *target);
    virtual void vfunc_113();
    virtual int vfunc_109();
    virtual void vfunc_110(s32);
    virtual void vfunc_111(s32);
    virtual void vfunc_112(s32);
    void sub_800CB764(s32);
    void sub_800C84C8();
    s32 m_490;
    s32 m_494;
    TObjEneMe1Gee *m_498[8];
    u32 m_4b8;
};

#endif
