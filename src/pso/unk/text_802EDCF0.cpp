#include "types.h"
#include "pso/boss/TBoss8Dragon_800BC53C.h"
#include "pso/enemy/TObjEneDD_800B9A34.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_802EDCF0.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjFish.h"

struct Obj_802EDCF0 {
    u8 pad0[0x6D4];
    s32 f6D4;
    s32 f6D8;
    void *f6DC[4];
    u8 pad6EC[0x708 - 0x6EC];
    void *f708;
    u8 pad70C[0x718 - 0x70C];
    void *f718;
    void *f71C;
    void *f720;
    u8 pad724[0x784 - 0x724];
    void *f784;
    void *f788[6];
};

extern "C" {
s32 __dt__7TObjectFv(void *, int);
s32 free_if_positive__13TBoss2DeRolLeFis(s32 arg0, s16 arg1);
void mem_free(void *p);
s32 __dl__7TObjectFPv(void *);
extern s32 TBoss7DeRolLeC__vtable[];
extern u32 boss7_joint_state;
u8 *__dt__14TBoss7DeRolLeCFv(u8 *arg0, s16 arg1) {
    Obj_802EDCF0 *o = (Obj_802EDCF0 *) arg0;
    s32 i;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = TBoss7DeRolLeC__vtable;
        if (o->f784 != 0) {
            queue_destruction__7TObjectFv(o->f784);
            o->f784 = 0;
        }
        for (i = 0; i < 6; i++) {
            if (o->f788[i] != 0) {
                queue_destruction__7TObjectFv(o->f788[i]);
                o->f788[i] = 0;
            }
        }
        mem_free((void *)o->f6D4);
        o->f6D4 = 0;
        if (o->f71C != 0) {
            queue_destruction__7TObjectFv(o->f71C);
            o->f71C = 0;
        }
        if (o->f720 != 0) {
            queue_destruction__7TObjectFv(o->f720);
            o->f720 = 0;
        }
        if (o->f718 != 0) {
            delete_buffer__12TBoss8DragonFis((s32)o->f718, 1);
            o->f718 = 0;
        }
        if (o->f708 != 0) {
            queue_destruction__7TObjectFv(o->f708);
            o->f708 = 0;
        }
        for (i = 3; i >= 0; i--) {
            queue_destruction__7TObjectFv(o->f6DC[i]);
            o->f6DC[i] = 0;
        }
        mem_free((void *)o->f6D8);
        ((TObjCollidable *)arg0)->clear_collision_bodies();
        if (boss7_joint_state == (u32) arg0) {
            boss7_joint_state = 0;
        }
        ((TObjFish *)arg0)->destroy_child();
        __dt__7TObjectFv(arg0 + 0x690, -1);
        free_if_positive__13TBoss2DeRolLeFis((s32)(arg0 + 0x670), -1);
        free_if_positive__13TBoss2DeRolLeFis((s32)(arg0 + 0x650), -1);
        free_if_positive__13TBoss2DeRolLeFis((s32)(arg0 + 0x630), -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
