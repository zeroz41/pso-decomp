#include "pso/TSwitch.h"
#include "pso/misc/TSwitch.h"

#include "types.h"

extern "C" {
s32 get_current_floor(void);
s32 memcpy(void *, void *, void *);
s32 memset(void *, int, int);
}

void TSwitch::render() {  }
void TSwitch::run_task() {  }

u8 TSwitch__floor_switch_table[18][32];

void restore_switch_table(s32 arg0, s32 arg1) {
    memcpy((void *) TSwitch__floor_switch_table, (void *)arg0, (void *)arg1);
}

u32 copy_switch_table(void* destination) {
    memcpy(destination, TSwitch__floor_switch_table, (void *)(0x240));
    return 0x240;
}

s32 get_floor_switch_flag(u32 id, s16 floor) {
    u8 *row;
    s32 idx;
    s32 bit;
    if (floor < 0 || floor > 17) {
        return -1;
    }
    if ((u16)id > 0xFF) {
        return -1;
    }
    id++;
    row = TSwitch__floor_switch_table[floor];
    idx = (u16)id / 8;
    bit = (u16)id % 8;
    if (bit > 0) {
        return (row[idx] & (1 << (8 - bit))) >> (8 - bit);
    }
    return row[idx - 1] & 1;
}

u8 is_floor_switch_set(u32 id, s16 floor) {
    return (u8) (get_floor_switch_flag(id, floor) != 0);
}

#pragma readonly_strings on
const char *TSwitch__name = "TSwitch";

extern "C" {

u8 is_current_floor_switch_set(s32 id) {
    return is_floor_switch_set((u32)id, (s16)((s16)((int) (get_current_floor()))));
}

void clear_floor_switch_flag(u32 id, s16 floor) {
    u8 *row;
    s32 idx;
    s32 bit;
    if (floor < 0 || floor > 17) {
        return;
    }
    if ((u16)id > 0xFF) {
        return;
    }
    id++;
    row = TSwitch__floor_switch_table[floor];
    idx = (u16)id / 8;
    bit = (u16)id % 8;
    if (bit != 0) {
        row[idx] &= ~(1 << (8 - bit));
    } else {
        row[idx - 1] &= ~1;
    }
}

void clear_current_floor_switch(s32 id) {
    clear_floor_switch_flag((u32)((u32)id), (s16)((s16)((int) (get_current_floor()))));
}

void set_floor_switch_flag(u32 id, s16 floor) {
    u8 *row;
    s32 idx;
    s32 bit;
    if (floor < 0 || floor > 17) {
        return;
    }
    if ((u16)id > 0xFF) {
        return;
    }
    id++;
    row = TSwitch__floor_switch_table[floor];
    idx = (u16)id / 8;
    bit = (u16)id % 8;
    if (bit > 0) {
        row[idx] |= 1 << (8 - bit);
    } else {
        row[idx - 1] |= 1;
    }
}

void set_current_floor_switch(s32 id) {
    set_floor_switch_flag((u32)((u32)id), (s16)((s16)((int) (get_current_floor()))));
}
}

TSwitch::TSwitch(TObject *parent) : TObject(parent) {
    m_name = TSwitch__name;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
}
void clear_switch_table(void) {
    memset((void *) TSwitch__floor_switch_table, 0, 0x240);
}
void init_switch_table(void) {
    memset((void *) TSwitch__floor_switch_table, 0, 0x240);
}

TSwitch::~TSwitch() {}
