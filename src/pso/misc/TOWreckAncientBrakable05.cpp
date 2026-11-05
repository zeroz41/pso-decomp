#include "types.h"
#include "pso/misc/TOWreckAncientBrakable05.h"
#include "pso/player/TObjPlayer.h"

struct TOWreckAncientBrakable05;

extern "C" {

void *TOWreckAncientBrakable05__create(void *arg0);
void *__dt__24TOWreckAncientBrakable05Fv(void *arg0, s16 arg1);
u8 *TOWreckAncientBrakable05__ct(TOWreckAncientBrakable05 *arg0, s32 arg1);
void __dl__7TObjectFPv(void *);
void *__dt__22TOWreckAncientBrakableFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void *TOWreckAncientBrakable05__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xBC);
    if (o != NULL) {
        o = TOWreckAncientBrakable05__ct((TOWreckAncientBrakable05 *)((u8 *)o), (s32)arg0);
    }
    return o;
}

extern s32 __vt__24TOWreckAncientBrakable05[];

void *__dt__24TOWreckAncientBrakable05Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__24TOWreckAncientBrakable05;
        __dt__22TOWreckAncientBrakableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
s32 TOWreckAncientBrakable__ct(void *, int);
extern s32 TOWreckAncient__collision_body_templates[];
extern s32 TOWreckAncientBrakable05__name;
u8 *TOWreckAncientBrakable05__ct(TOWreckAncientBrakable05 *wreck_ancient_brakable05, s32 arg1) {
    s32 temp_r0;
    TOWreckAncientBrakable__ct(wreck_ancient_brakable05, 3);
    *(s32 **)((s8 *)wreck_ancient_brakable05 + 0x18) = __vt__24TOWreckAncientBrakable05;
    *(s32 *)((s8 *)wreck_ancient_brakable05 + 0) = (s32) TOWreckAncientBrakable05__name;
    ((TOWreckAncientBrakable05 *)(wreck_ancient_brakable05))->apply_object_set_data((void *)arg1);
    init_collision_body_parts(wreck_ancient_brakable05, (void *) &TOWreckAncient__collision_body_templates[33], 1);
    ((TObjPlayer *)wreck_ancient_brakable05)->register_object_by_id();
    wreck_ancient_brakable05->m_b8 = (s32) wreck_ancient_brakable05->set_params[0];
    temp_r0 = wreck_ancient_brakable05->m_b8;
    if ((temp_r0 < 0) || (temp_r0 >= 0x100)) {
        wreck_ancient_brakable05->m_b8 = -1;
    }
    return (u8 *)wreck_ancient_brakable05;
}

}
