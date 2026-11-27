#ifndef PSO_OBJECT_SWITCH_TSWITCH_H
#define PSO_OBJECT_SWITCH_TSWITCH_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TSwitch : public TObject {
public:
    static u8 floor_switch_table[18][32];
    TSwitch(TObject *parent);
    virtual ~TSwitch();
    virtual void run_task();
    virtual void render();

    u8 pad_1c;
    u32 pad_20;
    u32 pad_24;
};

void clear_current_floor_switch(s32 id);
void clear_floor_switch_flag(u32 id, s16 floor);
void clear_switch_table(void);
u32 copy_switch_table(void *destination);
s32 get_floor_switch_flag(u32 id, s16 floor);
void init_switch_table(void);
u8 is_current_floor_switch_set(u32 id);
u8 is_floor_switch_set(u32 id, s16 floor);
void restore_switch_table(const void *src, s32 size);
void set_current_floor_switch(s32 id);
void set_floor_switch_flag(u32 id, s16 floor);

#endif
