#include "types.h"
#include "pso/ui/TUnk_804F3428.h"
#include "pso/ui/frontend/TAdDialingMessageWindow_8036A064.h"

#include "pso/ui/frontend/TAdDialingMessageWindow.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);

void TUnk_804F3428::run_task() {
    u32 temp_r3;
    void *temp2_r3;

    if ((u32) this->m_20 != 0U) {
        temp_r3 = *(u32 *)&this->unk_1C;
        if (temp_r3 != 0U) {
            *(u32 *)&this->unk_1C = (temp_r3 - 1);
            if ((u32) *(u32 *)&this->unk_1C == 0U) {
                temp2_r3 = *(void * *)&this->m_20;
                if ((u32) temp2_r3 != 0U) {
                    ((TAdDialingMessageWindow *)temp2_r3)->set_flag_and_notify();
                }
            }
        }
        ((TAdDialingMessageWindow *)(this->m_20))->run_child_tasks();
    }
}

extern s32 __vt__13TUnk_804F3428[];

}
TUnk_804F3428::~TUnk_804F3428() {

}


void *TUnk_804F3428::init(void *arg1, void *arg2, void *arg3) {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804F3428;
    *(void * *)&this->m_20 = arg2;
    *(void * *)&(this->unk_1C) = arg3;
    return this;
}

