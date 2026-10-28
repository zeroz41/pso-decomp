#include "types.h"
#include "pso/misc/TRaderMapCore_801FB964.h"
#include "pso/misc/TRaderMapCore.h"

extern "C" {

s32 get_bml_model(s32);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

    extern const float TRaderMapCore__data_805DC528;
    extern const float TRaderMapCore__data_805DC534;
void TRaderMapCore::reset() { *(float *)&this->m_prev = TRaderMapCore__data_805DC528; *(float *)&this->m_flags = TRaderMapCore__data_805DC528; *(float *)&this->m_name = TRaderMapCore__data_805DC528; *(int *)&this->m_next = 0; *(float *)&this->m_up = TRaderMapCore__data_805DC534; *(short *)&this->m_down = 0; *(short*)((char*)this + 0x16) = -1; *(float *)&this->texture_id = TRaderMapCore__data_805DC534; *(float *)&this->m_20 = TRaderMapCore__data_805DC534; *(float *)&this->entity_id = TRaderMapCore__data_805DC534; *(float*)((char*)this + 0x18) = TRaderMapCore__data_805DC534; }

extern s32 TRaderMapCore__frame_model_resource;

void TRaderMapCore::init_map_ptr() {
    get_bml_model(TRaderMapCore__frame_model_resource);
}

extern s32 lbl_804C88A8[];

void *__dt__13TUnk_804C88A8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804C88A8;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
