#ifndef PSO_ITEM_TITEMDATA_8010EDA8_H
#define PSO_ITEM_TITEMDATA_8010EDA8_H

#include "types.h"

extern "C" {
void add_elt_resist(void *res, s32 amount);
void add_eth_resist(void *res, s32 amount);
void TItemData__sub_8010EDD8(void *res, s32 amount);
void subtract_dfp(void *arg0, s16 arg1);
void subtract_stat_ptr(s16 *arg0, s32 arg1);
saddr get_item_description_text(s32 name);
saddr get_text_collection(s32 arg0);
}

// --- C functions defined in TItemData_8010EDA8.cpp ---
extern "C" {
void add_elt_resist(void *res, s32 amount);
void add_eth_resist(void *res, s32 amount);
void TItemData__sub_8010EDD8(void *res, s32 amount);
void subtract_dfp(void *arg0, s16 arg1);
void subtract_stat_ptr(s16 *arg0, s32 arg1);
saddr get_item_description_text(s32 name);
saddr get_text_collection(s32 arg0);
}
// --- end of C functions

#endif
