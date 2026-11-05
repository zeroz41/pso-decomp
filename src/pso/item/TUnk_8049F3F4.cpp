#include "types.h"
#include "pso/item/TUnk_8049F3F4.h"
#include "pso/item/TItemLoad_8010F3D8.h"
#include "pso/TItemLoad.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);
s32 free_texture_if_valid(void *, void *);

extern s32 lbl_8049F3F4[];
extern void *item_texture_archive_loader;
extern void *item_model_chunk_loader;

void *__dt__13TUnk_8049F3F4Fv(void *arg0, s16 arg1) {
    void **temp_r3;

    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_8049F3F4;
        switch (((TUnk_8049F3F4 *)arg0)->m_20) {
        case 2:
            ((TItemLoad *)item_model_chunk_loader)->reset_ring_state();
            break;
        case 3:
            ((TItemLoad *)item_texture_archive_loader)->reset_ring_state();
            break;
        }
        temp_r3 = *(void ***)((s8 *)arg0 + 0x3C);
        if ((temp_r3 != NULL) && ((u32) *(u32 *)((s8 *)(*temp_r3) + 8) != 0U)) {
            free_texture_if_valid(temp_r3, *temp_r3);
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TUnk_8049F3F4::init(void *arg1, void *arg2, void *arg3, void *arg4) {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_8049F3F4;
    *(void * *)&this->unk_1C = arg2;
    this->m_20 = 0;
    *(void * *)&this->unk_24 = arg3;
    *(void * *)&this->m_28 = arg4;
    ((TItemLoad *)((char *)this + 44))->clear_slots();
    this->m_20 = 1;
    return this;
}

void TItemLoad::update_all() {
    void *temp_r3;
    temp_r3 = item_texture_archive_loader;
    if (temp_r3 != 0) {
        ((TItemLoad *)temp_r3)->update_state();
    }
    temp_r3 = item_model_chunk_loader;
    if (temp_r3 != 0) {
        ((TItemLoad *)temp_r3)->update_state();
    }
}

}
