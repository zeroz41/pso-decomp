#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_80359A7C_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_80359A7C_H

#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

// The TBoss8Dragon that TBoss8Dragon::spawn_attack_object creates. Its table (0x804F1A78) differs from
// TBoss8Dragon's only in the destructor and run_task slots.
class TUnk_804F1A78 : public TBoss8Dragon {
public:
    TUnk_804F1A78(TObject *parent, void *set_data, s32 hp);
    virtual ~TUnk_804F1A78();
    virtual void run_task();
};

#endif
