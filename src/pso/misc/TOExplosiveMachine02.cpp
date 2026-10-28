#include "types.h"
#include "pso/misc/TOExplosiveMachine02.h"

extern "C" {

s32 TOExplosiveMachine__ct();
s32 TObjFish__sub_8001EDB0(s32, s32);
void *get_bml_model(s32, s32);
void __dl__7TObjectFPv(void *);
void __dt__18TOExplosiveMachineFv(void *, int);
void *__nw__7TObjectFUl(int);

void *TOExplosiveMachine02__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xAC);
    if (o != NULL) {
        o = TOExplosiveMachine02__ct((TOExplosiveMachine02 *)((void *)o), (s32)arg0);
    }
    return o;
}

extern s32 __vt__20TOExplosiveMachine02[];

void *__dt__20TOExplosiveMachine02Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TOExplosiveMachine02;
        __dt__18TOExplosiveMachineFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 TOExplosiveMachine02__class_name;
extern s32 explosive_machine_model_archive;

void *TOExplosiveMachine02__ct(TOExplosiveMachine02 *explosive_machine02, s32 arg1) {
    TOExplosiveMachine__ct();
    *(s32 **)((s8 *)explosive_machine02 + 0x18) = __vt__20TOExplosiveMachine02;
    *(s32 *)((s8 *)explosive_machine02 + 0) = (s32) TOExplosiveMachine02__class_name;
    explosive_machine02->apply_object_set_data((void *)arg1);
    explosive_machine02->model = get_bml_model(explosive_machine_model_archive, 3);
    explosive_machine02->texlist = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 3);
    explosive_machine02->m_94 = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)explosive_machine02->model + 4)) + 0x14);
    *(void **)((s8 *)explosive_machine02 + 0x9C) = get_bml_model(explosive_machine_model_archive, 4);
    explosive_machine02->m_a4 = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 4);
    *(void **)((s8 *)explosive_machine02 + 0xA0) = get_bml_model(explosive_machine_model_archive, 5);
    explosive_machine02->m_a8 = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 5);
    return explosive_machine02;
}

}
