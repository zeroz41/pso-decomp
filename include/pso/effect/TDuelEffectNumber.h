#ifndef PSO_EFFECT_TDUELEFFECTNUMBER_H
#define PSO_EFFECT_TDUELEFFECTNUMBER_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TDuelEffectNumber : public TObject {
public:
    TDuelEffectNumber(TObject *arg1, void *arg2, void *arg3);
    virtual ~TDuelEffectNumber();
    void sub_8007FF28(s32);
    void sub_8007FFF4(s32);
    virtual void run_task();
    virtual void render();
public:
    void render_pair(f32 f);
    void render_number_default(f32 farg0);
public:
    static void calc_digit_transform(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3);
};

void calc_duel_number_uv(s32 arg0, u8 *arg1, s32 arg2);

#endif
