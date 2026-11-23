#ifndef PSO_EFFECT_TDUELEFFECTNUMBER_H
#define PSO_EFFECT_TDUELEFFECTNUMBER_H

#include "pso/system/task/TObject.h"
#include "pso/effect/sprite/TQuadSprite.h"
#include "types.h"


// One digit of the duel start countdown: it pops in at twice its size, holds,
// fades out, and leaves an expanding echo behind; it lives for 30 frames.
class TDuelEffectNumber : public TObject {
public:
    static const char *class_name;
    TDuelEffectNumber(TObject *parent, f32 *pos, s32 digit);
    virtual ~TDuelEffectNumber();
    void draw_digit_quad(QuadSpriteRect *quad, f32 *center, f32 depth, f32 scale, f32 alpha);
    void draw_echo(QuadSpriteRect *quad);
    void draw_digit(QuadSpriteRect *quad);
    void calc_digit_uv(QuadSpriteRect *quad, s32 digit);
    virtual void run_task();
    virtual void render();
    f32 pos[2];  // screen position
    s32 digit;
    s32 timer;   // frames since the digit appeared
};

#endif
