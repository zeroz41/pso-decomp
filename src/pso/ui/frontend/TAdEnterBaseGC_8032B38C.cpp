#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdEnterBaseGC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdEnterBaseGC_8032B38C.h"
#include "pso/system/task/TObject.h"


struct RecoveredGlobal_8032B390_lbl_80477198 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_8032B390_lbl_804771B8 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
u32 __nw__7TObjectFUl(int);
s32 __ct__9TAdBackGCFv(int, void *);
s32 __ct__12TAdBackTxtGCFv(int, void *);
u32 __ct__14TAdSelectCurGCFv(int, int, void *, void *);
extern RecoveredGlobal_8032B390_lbl_80477198 lbl_80477198;
extern RecoveredGlobal_8032B390_lbl_804771B8 lbl_804771B8;
extern s32 tl_clipout;
extern int TAdEnterBaseGC__entry_mode;
void __ct__7TObjectFP7TObject(void *);

void TAdEnterBaseGC::run_task() {  }

    extern int password_entry_keyboard_control;

typedef char RecoveredGlobal_8032B390_lbl_80477198_size[sizeof(RecoveredGlobal_8032B390_lbl_80477198) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_8032B390_lbl_804771B8_size[sizeof(RecoveredGlobal_8032B390_lbl_804771B8) == 0x10 ? 1 : -1];
void TAdEnterBaseGC::create_parts() {
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r3_3;
    u32 temp_r3_4;
    u32 var_r0;
    u32 var_r0_2;
    temp_r3 = __nw__7TObjectFUl(0x24);
    if (temp_r3 != 0U) {
        __ct__9TAdBackGCFv(temp_r3, this);
    }
    temp_r3_2 = __nw__7TObjectFUl(0x28);
    if (temp_r3_2 != 0U) {
        __ct__12TAdBackTxtGCFv(temp_r3_2, this);
    }
    if ((s32) (*(s32 *)&TAdEnterBaseGC__entry_mode) == 3) {
        temp_r3_3 = __nw__7TObjectFUl(0x708);
        var_r0 = temp_r3_3;
        if (var_r0 != 0U) {
            var_r0 = __ct__14TAdSelectCurGCFv(temp_r3_3, tl_clipout, (void *) ((u8 *)&lbl_80477198.value + 0x10), (void *) ((u8 *)&lbl_804771B8.value + 8));
        }
        *(u32 *)&this->unk_2C = var_r0;
        return;
    }
    temp_r3_4 = __nw__7TObjectFUl(0x708);
    var_r0_2 = temp_r3_4;
    if (var_r0_2 != 0U) {
        var_r0_2 = __ct__14TAdSelectCurGCFv(temp_r3_4, tl_clipout, &lbl_80477198.value, &lbl_804771B8.value);
    }
    *(u32 *)&this->unk_2C = var_r0_2;
}

void TAdEnterBaseGC::sub_8032B460(int a1) { *(int *)&this->m_24 = 0; this->m_20 = 0; TAdEnterBaseGC__entry_mode = a1; *(int*)((char*)this + 0x38) = 0; *(int*)((char*)this + 0x3c) = 0; this->m_28 = 0; *(int *)&this->unk_2C = 0; this->m_30 = 0; *(int *)&this->unk_34 = 0; password_entry_keyboard_control = 0; }

extern s32 __vt__14TAdEnterBaseGC[];

}
TAdEnterBaseGC::~TAdEnterBaseGC() {
    if (*(void **)((s8 *)this + 0x2C) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x2C)))->queue_destruction(); *(s32 *)((s8 *)this + 0x2C) = 0; }
    if (*(void **)((s8 *)this + 0x30) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x30)))->queue_destruction(); this->m_30 = 0; }
    if (*(void **)((s8 *)this + 0x34) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x34)))->queue_destruction(); *(s32 *)((s8 *)this + 0x34) = 0; }
}


extern void *lbl_805D41E0;

void *TAdEnterBaseGC__ct(void *ad_enter_base_gc) {
    __ct__7TObjectFP7TObject(ad_enter_base_gc);
    *(s32 **)((s8 *)ad_enter_base_gc + 0x18) = __vt__14TAdEnterBaseGC;
    *(void * *)&((TAdEnterBaseGC *)ad_enter_base_gc)->m_name = lbl_805D41E0;
    ((TAdEnterBaseGC *)ad_enter_base_gc)->sub_8032B460(0);
    return ad_enter_base_gc;
}

extern s32 TAdPsoPassSaveGC__data_805D6E80;

s32 TAdPsoPassSaveGC__sub_8032B584(void) {
    return TAdPsoPassSaveGC__data_805D6E80;
}

