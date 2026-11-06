#ifndef PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01_H
#define PSO_OBJECT_CAVE_TOHANGCEILINGCAVE01_H

#include "types.h"

struct TOHangceilingCave01
{
    static void destroy_instance();
};

extern "C" {
u8 *TOHangceilingCave01KeyQuick__ct(u8 *arg0, s32 arg1);
void *TOHangceilingCave01Key__ct(void *arg0);
void *TOHangceilingCave01Normal__ct(void *arg0);
f32 TOHangceilingCave01Normal__sub_801681D0(f32 farg0);
s32 TOHangceilingCave01__create(u8 *arg0);
bool sub_801688C0__13TUnk_804B2578Fv(u8 *arg0);
void *__dt__22TOHangceilingCave01KeyFv(void *arg0, s16 arg1);
void *__dt__25TOHangceilingCave01NormalFv(void *arg0, s16 arg1);
void *__dt__27TOHangceilingCave01KeyQuickFv(void *arg0, s16 arg1);
}
void load_turiten_singo_resources(void);
extern "C" {
void reset_state(u8 *arg0);
}

#endif
