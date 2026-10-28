#ifndef PSO_ITEM_TITEMOBJECT_80115D6C_H
#define PSO_ITEM_TITEMOBJECT_80115D6C_H

#include "types.h"

struct TItemObject;
extern "C" {
void *TItemObject__ct(void *arg0, void *arg1, void *item);
s32 TItemObject__sub_80115DE8(void *item);
void TItemObject__vt16(u8 *arg0, u8 *item);
s32 remove_amount__11TItemObjectFl(TItemObject *arg0, s32 arg1);
s32 add_amount__11TItemObjectFl(void *arg0, s32 arg1);
void *__dt__11TItemObjectFv(void *arg0, s16 arg1);
}
void handle_6x66_use_star_atomizer(u8 *arg0);
extern "C" {
void send_star_atomizer_targets(void *arg0);
}

// --- C functions defined in TItemObject_80115D6C.cpp ---
extern "C" {
void *TItemObject__ct(void *arg0, void *arg1, void *item);
s32 TItemObject__sub_80115DE8(void *item);
void TItemObject__vt16(u8 *item_object, u8 *item);
void *__dt__11TItemObjectFv(void *arg0, s16 arg1);
void send_star_atomizer_targets(void *player);
}
// --- end of C functions

#endif
