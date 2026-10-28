#include "types.h"
#include "pso/misc/TOExplosiveMachine01.h"

extern "C" {

s32 TOExplosiveMachine__ct();
s32 TObjFish__sub_8001EDB0(s32, s32);
void *get_bml_model(s32, s32);
void __dl__7TObjectFPv(void *);
void __dt__18TOExplosiveMachineFv(void *, int);
void *__nw__7TObjectFUl(int);

void *TOExplosiveMachine01__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xAC);
    if (o != NULL) {
        o = TOExplosiveMachine01__ct((TOExplosiveMachine01 *)((void *)o), (s32)arg0);
    }
    return o;
}

extern s32 __vt__20TOExplosiveMachine01[];

void *__dt__20TOExplosiveMachine01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TOExplosiveMachine01;
        __dt__18TOExplosiveMachineFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 TOExplosiveMachine01__class_name;
extern s32 explosive_machine_model_archive;

void *TOExplosiveMachine01__ct(TOExplosiveMachine01 *explosive_machine01, s32 arg1) {
    TOExplosiveMachine__ct();
    *(s32 **)((s8 *)explosive_machine01 + 0x18) = __vt__20TOExplosiveMachine01;
    *(s32 *)((s8 *)explosive_machine01 + 0) = (s32) TOExplosiveMachine01__class_name;
    explosive_machine01->apply_object_set_data((void *)arg1);
    explosive_machine01->model = get_bml_model(explosive_machine_model_archive, 0);
    explosive_machine01->texlist = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 0);
    explosive_machine01->m_94 = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)explosive_machine01->model + 4)) + 0x14);
    *(void **)((s8 *)explosive_machine01 + 0x9C) = get_bml_model(explosive_machine_model_archive, 1);
    explosive_machine01->m_a4 = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 1);
    *(void **)((s8 *)explosive_machine01 + 0xA0) = get_bml_model(explosive_machine_model_archive, 2);
    explosive_machine01->m_a8 = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 2);
    return explosive_machine01;
}

}
