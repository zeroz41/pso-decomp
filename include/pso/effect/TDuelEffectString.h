#ifndef PSO_EFFECT_TDUELEFFECTSTRING_H
#define PSO_EFFECT_TDUELEFFECTSTRING_H
#include "pso/system/task/TObject.h"
#include "types.h"

extern const char *TDuelEffectString__class_name;

class TDuelEffectString : public TObject {
public:
    TDuelEffectString(TObject *arg1, void *arg2, void *arg3);
    virtual ~TDuelEffectString();
    virtual void run_task();
    virtual void render();
    // 0x1C: the screen position the ctor copies from its second argument; 0x24: its third argument.
    f32 pad_1C[2];
    void *pad_24;
    u32 pad_28;
};

#endif
