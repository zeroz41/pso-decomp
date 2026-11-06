#ifndef PSO_BOSS_DRAGON_TOBJBOSS1FLOOR_H
#define PSO_BOSS_DRAGON_TOBJBOSS1FLOOR_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjBoss1Floor : public TObject {
public:
    TObjBoss1Floor(TObject *parent);
    virtual ~TObjBoss1Floor();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x1C];
public:
    static void create_instance();
};
typedef char TObjBoss1Floor_size[sizeof(TObjBoss1Floor) == 0x38 ? 1 : -1];

#endif
