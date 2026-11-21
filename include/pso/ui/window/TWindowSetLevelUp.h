#ifndef PSO_UI_WINDOW_TWINDOWSETLEVELUP_H
#define PSO_UI_WINDOW_TWINDOWSETLEVELUP_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TWindowSetLevelUp : public TObject {
public:
    virtual ~TWindowSetLevelUp();
    void update_stat_messages();
    virtual void run_task();
    virtual void render();
public:
    void copy_stat_block(saddr arg1);
};

extern "C" {
void TWindowSetLevelUp__sub_8026DE28(void *p, s32 v);
void *__ct__17TWindowSetLevelUpFv(void *window_set_level_up, void *arg1, void *arg2, void *arg3);
void *__dt__17TWindowSetLevelUpFv(void *object, s16 arg1);
void render__17TWindowSetLevelUpFv(void);
void run_task__17TWindowSetLevelUpFv(u8 *arg0);
}

#endif
