#include "types.h"
#include "pso/boss/TUnk_804E4BF0.h"
#include "pso/boss/TUnk_804E4BF0.h"

#include "pso/boss/goldragon/TBoss8Dragon_802F3AB4.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/system/vector.h"


    extern void* boss8_dragon_leader_part;
extern "C" {
extern s32 __vt__13TUnk_804E4BF0[];
extern void *boss8_dragon_leader_part;
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);

#include "pso/boss/goldragon/TBoss8Dragon.h"

extern "C" {
s32 setup_attack_slot__12TBoss8DragonFiUiiiPv(s32 arg0, u32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    if ((arg3 < 0) || (arg3 > 5)) {
        return 0;
    }
    TBoss4DarkFalz__sub_8004B4F0(arg4, (void *)(arg0 + 0x1C));
    *(s16 *)((s8 *)arg4 + 0) = TBoss8Dragon__sub_802F3C94((void *)arg0, (s32)arg3);
    *(s16 *)((s8 *)arg4 + 2) = 0;
    *(s16 *)((s8 *)arg4 + 6) = ((TBoss8Dragon *)arg0)->get_part_count_plus(arg3);
    if (arg1 != 0U) {
        VecCopy((Vec *)(arg4 + 0x10), (const Vec *)(arg1));
    }
    *(s32 *)((s8 *)arg4 + 0x20) = arg2;
    return 1;
}
}

void TUnk_804E4BF0::render() {  }

void TUnk_804E4BF0::run_task() {  }

}
TUnk_804E4BF0::~TUnk_804E4BF0() {
    if (boss8_dragon_leader_part == this) {
        boss8_dragon_leader_part = NULL;
    }
}
TUnk_804E4BF0::TUnk_804E4BF0(TObject *object, void *arg1p) : TObject(object) {
    if (boss8_dragon_leader_part == NULL) {
        boss8_dragon_leader_part = this;
    }
    TBoss4DarkFalz__sub_8004B4F0((void *)((char *)this + 28), arg1p);
}


void * TBoss8Dragon__sub_802F3C24(void *arg0, void *arg1) {
    void *o;
    o = (void *)new TUnk_804E4BF0((TObject *)arg0, (void *)arg1);
    return o;
}

void TBoss8Dragon__sub_802F3C74(void) {  }

void clear_boss8_dragon_leader_part(void) { boss8_dragon_leader_part = 0; }

u16 TBoss8Dragon::get_part_count_plus(s32 arg1) {
    return (u16) (*(u16 *)((u8 *)this + 0x22) + arg1);
}

s32 TBoss8Dragon__sub_802F3C94(void *arg0, s32 arg1) {
    return *(s16 *)((s8 *)arg0 + 0x1C) + arg1;
}
