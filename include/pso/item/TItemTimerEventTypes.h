#ifndef PSO_ITEM_TITEMTIMEREVENTTYPES_H
#define PSO_ITEM_TITEMTIMEREVENTTYPES_H

#include "types.h"

struct StatusTargetBase { char pad[0x18]; };

struct StatusTarget : StatusTargetBase {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void m21(void *, void *, s32, s32, s32);
};

struct StatusRequest { s32 k1; s32 v1; s32 k2; f32 v2; };

struct CurseTimerView { u8 pad[0x28]; StatusTarget *obj; f32 f2c; };

#endif
