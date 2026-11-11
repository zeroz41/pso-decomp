#ifndef PSO_BOSS_DEROLLE_TUNK_80482D04_H
#define PSO_BOSS_DEROLLE_TUNK_80482D04_H
#include "types.h"
#include "pso/boss/derolle/TBoss2Mine.h"

class TUnk_80482D04 : public TBoss2Mine {
public:
    TUnk_80482D04(TObject *parent, u16 entity_id, s32 set_index);
    virtual ~TUnk_80482D04();
    virtual void vfunc_105(s32);
    virtual void vfunc_106(s32);
    void move_mine();
    virtual void vfunc_88();
    u8 unk_3B4[0x3C];
    // Set by init_launch and followed by move_mine (names inferred):
    TObject *owner;     // the object the mine rides on
    s32 slot;           // its launch slot, 0-2
    Vec owner_offset;   // where it sits relative to the owner
    Vec direction;      // its launch direction
};
typedef char TUnk_80482D04_size[sizeof(TUnk_80482D04) == 0x410 ? 1 : -1];

#endif
