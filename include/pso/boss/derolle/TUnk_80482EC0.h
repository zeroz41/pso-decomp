#ifndef PSO_BOSS_DEROLLE_TUNK_80482EC0_H
#define PSO_BOSS_DEROLLE_TUNK_80482EC0_H
#include "types.h"
#include "pso/boss/derolle/TBoss2Mine.h"

class TUnk_80482EC0 : public TBoss2Mine {
public:
    TUnk_80482EC0(TObject *parent, u16 entity_id, s32 set_index);
    virtual ~TUnk_80482EC0();
    virtual void vfunc_105(s32);
    virtual void vfunc_106(s32);
    virtual void vfunc_88();
    u8 unk_3B4[0x3C];
};
typedef char TUnk_80482EC0_size[sizeof(TUnk_80482EC0) == 0x3F0 ? 1 : -1];

#endif
