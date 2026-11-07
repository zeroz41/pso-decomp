#ifndef PSO_EFFECT_TDUELEFFECTNUMBER_H
#define PSO_EFFECT_TDUELEFFECTNUMBER_H

#include "pso/system/task/TObject.h"
#include "types.h"

extern const char *TDuelEffectNumber__class_name;

class TDuelEffectNumber : public TObject {
public:
    TDuelEffectNumber(TObject *arg1, void *arg2, void *arg3);
    virtual ~TDuelEffectNumber();
    void sub_8007FF28(s32);
    void sub_8007FFF4(s32);
    virtual void run_task();
    virtual void render();
    // 0x1C: the screen position the ctor copies from its second argument; 0x24: its third argument.
    f32 pad_1C[2];
    void *pad_24;
    u32 pad_28;
public:
    void render_pair(f32 f);
    void render_number_default(f32 farg0);
public:
    static void calc_digit_transform(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3);
};

void calc_duel_number_uv(s32 arg0, u8 *arg1, s32 arg2);

#endif
