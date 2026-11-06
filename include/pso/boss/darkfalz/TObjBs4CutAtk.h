#ifndef PSO_BOSS_DARKFALZ_TOBJBS4CUTATK_H
#define PSO_BOSS_DARKFALZ_TOBJBS4CUTATK_H
#include "pso/system/task/TObject.h"
#include <stddef.h>

class TObjBs4CutAtk : public TObject {
public:
    virtual ~TObjBs4CutAtk();
    void *create(void *, void *, void *);
    virtual void run_task();
    virtual void render();

    s32 angle;
    s32 angle_step;
    s32 age;
};
typedef char CutAttackSize[(sizeof(TObjBs4CutAtk)==0x28)?1:-1];
typedef char CutAttackAngle[(offsetof(TObjBs4CutAtk,angle)==0x1C)?1:-1];
typedef char CutAttackStep[(offsetof(TObjBs4CutAtk,angle_step)==0x20)?1:-1];
typedef char CutAttackAge[(offsetof(TObjBs4CutAtk,age)==0x24)?1:-1];
#endif
