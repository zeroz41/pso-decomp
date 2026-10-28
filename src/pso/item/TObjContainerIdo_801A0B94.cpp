#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/item/TObjContainerIdo.h"

extern "C" {
int __ct__14TObjCollidableFP7TObject(void);
extern s32 lbl_804B97C0[];
    extern const float lbl_805DC078;
    extern const float lbl_805DC07C;
void __dl__7TObjectFPv(void *);

void *TUnk_804B97C0::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804B97C0;
        __dt__14TObjCollidableFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
void*TUnk_804B97C0::init_positions() { __ct__14TObjCollidableFP7TObject(); *(int*)((char*)this + 0x18) = (int)((unsigned char *)&lbl_804B97C0); *(float *)&this->unk_AC = lbl_805DC078; this->m_b0 = lbl_805DC07C; return this; }

}
