#ifndef PSO_BOSS_TBOSS5GRYPHONCOLLI_C_H
#define PSO_BOSS_TBOSS5GRYPHONCOLLI_C_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TBoss5GryphonColli_C : public TObjCollidable {
public:
    virtual ~TBoss5GryphonColli_C();
    void *destroy(s16);
    void clear_entry_flags();
    virtual void render();
    u8 unk_AC[0xC];
};
typedef char TBoss5GryphonColli_C_size[sizeof(TBoss5GryphonColli_C) == 0xB8 ? 1 : -1];

#endif
