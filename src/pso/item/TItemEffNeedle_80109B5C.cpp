#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEffNeedle_80109B5C.h"
#include "pso/player/TObjPlayer_8010A050.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"

struct Rec_80109B5C { u8 pad[0x1C]; f32 pos[3]; u8 pad2[0x2C - 0x28]; };

extern "C" {
u8 *__ct__18TItemEffNeedleBaseFv(u8 *arg0, void *arg1, u8 *arg2);
void *find_entity_by_id(u16 id);
extern s32 __vt__14TItemEffNeedle[];
extern s32 TItemEffNeedle__class_name;
s32 obj_getField1c(void *);
s32 create_timed_particle_emitter(void *, s32, s32, s32, void *);
void *__nw__7TObjectFUl(s32);
extern s32 tl_05;

typedef struct { u8 pad[0x1C]; u8 f[0x10]; } E80109;

#define self ((u8 *)arg0)
void *__ct__14TItemEffNeedleFv(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *entity;
    __ct__18TItemEffNeedleBaseFv((u8 *)arg0, (void *)arg1, (u8 *)arg2);
    *(s32 **)((s8 *)self + 0x18) = __vt__14TItemEffNeedle;
    *(s32 *)((s8 *)self + 0) = (s32) TItemEffNeedle__class_name;
    *(u16 *)((s8 *)self + 0x50) = arg3;
    *(s32 *)((s8 *)self + 0x54) = arg4;
    entity = (u8 *)find_entity_by_id(*(u16 *)((s8 *)self + 0x50));
    if (entity != NULL) {
        VecCopy((Vec *)(self + 0x30), (const Vec *)(*(Rec_80109B5C **)((s8 *)entity + 0xA4))[*(s32 *)((s8 *)self + 0x54)].pos);
        ((TObjPlayer *)(self + 0x58))->copy_xyz(self + 0x44);
        *(s32 *)((s8 *)self + 0x5C) = (s32) (*(s32 *)((s8 *)self + 0x5C) - *(s32 *)((s8 *)entity + 0x60));
    }
    return arg0;
}
#undef self

void create_needle_effect(s32 item_id, void *arg1) {
    void *var_r31;
    void *temp_r30;
    s32 temp_r29;
    void *temp_r7;

    temp_r29 = (s32)find_item_by_id(item_id);
    var_r31 = __nw__7TObjectFUl(0x64);
    if (var_r31 != NULL) {
        temp_r30 = *(void **)((s8 *)arg1 + 0);
        var_r31 = __ct__14TItemEffNeedleFv(var_r31, tl_05, temp_r29, (s32)(obj_getField1c(temp_r30)), (s32)(*(s32 *)((s8 *)temp_r30 + 0xA8)));
    }
    if (var_r31 != NULL) {
        *(s32 *)((s8 *)var_r31 + 0x3C) = TObjPlayer__sub_8010A058((void *)temp_r29);
        *(s32 *)((s8 *)var_r31 + 0x40) = ((TObjPlayer *)temp_r29)->get_entity_id();
        *(s32 *)((s8 *)var_r31 + 0x44) = (s32) (*(s32 *)((s8 *)var_r31 + 0x44) + 0x8000);
    }
    temp_r7 = *(void **)((s8 *)arg1 + 0);
    create_timed_particle_emitter(((E80109 *)*(void **)((s8 *)temp_r7 + 0xA4))[*(s32 *)((s8 *)arg1 + 4)].f, 0x180, 0, 0x3C, temp_r7);
}

}
