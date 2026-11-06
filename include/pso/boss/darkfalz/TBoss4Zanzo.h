#ifndef PSO_BOSS_DARKFALZ_TBOSS4ZANZO_H
#define PSO_BOSS_DARKFALZ_TBOSS4ZANZO_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss4Zanzo : public TObject {
public:
    virtual ~TBoss4Zanzo();
    virtual void render();
    virtual void run_task();
};

extern "C" {
u8 *TBoss4Type2__ct(u8 *arg0, s32 parent, s32 *arg2);
void sub_80056998__11TBoss4Type2Fv(u8 *arg0);
void TBoss4Type2__sub_80056B3C(void *arg0, s32 lo, s32 hi);
void render__13TUnk_80486924Fv(void *p);
void *__ct__11TBoss4ZanzoFv(void *arg0, void *arg1, void *arg2);
f32 compute_wave_offset__11TBoss4Type2Ff(f32 farg0);
void fn_8005586C(u8 *arg0, u8 *arg1);
void render__11TBoss4ZanzoFv(u8 *arg0);
void run_task__11TBoss4ZanzoFv(void *arg0);
}

#endif
