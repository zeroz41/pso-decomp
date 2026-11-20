#ifndef PSO_RENDER_REFLECTION_H
#define PSO_RENDER_REFLECTION_H
#include "types.h"
#include <dolphin/mtx.h>

s32 push_reflection_matrix(Vec *point);

extern "C" {
s32 fn_8029E7BC(saddr arg0, u8 *arg1);
void TObjPlayer__sub_8029EE2C(void);
}

#endif
