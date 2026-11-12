#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/ambient/TObjMistCtrl.h"
#include "pso/unk/text_803E29B0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803DA798.h"

#include "pso/player/TPlayerFootStamp.h"
#include "pso/object/ambient/TObjMistCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject.h"


struct RecoveredGlobal_802AF7C0___vt__12TObjMistCtrl {
    s32 value;
    u8 remaining[0x34];
};


extern "C" {
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 __vt__12TObjMistCtrl[];
extern s32 lbl_805D3E80;
void __dl__7TObjectFPv(void *);

void TObjMistCtrl::run_task() { { (void)(sub_802AF64C()); return; } }

}
TObjMistCtrl::~TObjMistCtrl() {
    if (*(void **)((s8 *)this + 0x90) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x90)))->queue_destruction(); *(s32 *)((s8 *)this + 0x90) = 0; }
}
extern "C" {


typedef char RecoveredGlobal_802AF7C0___vt__12TObjMistCtrl_size[sizeof(RecoveredGlobal_802AF7C0___vt__12TObjMistCtrl) == 0x38 ? 1 : -1];
u8 *TObjMistCtrl__ct(u8 *mist_ctrl, s32 parent, u32 arg2) {
    __ct__8TObjBaseFP7TObject((void *)mist_ctrl, (void *)parent);
    *(s32 **)((s8 *)mist_ctrl + 0x18) = &(*(RecoveredGlobal_802AF7C0___vt__12TObjMistCtrl *)&__vt__12TObjMistCtrl).value;
    *(s32 *)((s8 *)mist_ctrl + 0) = (s32) lbl_805D3E80;
    if (arg2 != 0U) {
        ((TObjMistCtrl *)(mist_ctrl))->apply_object_set_data((void *)arg2);
    }
    *(s32 *)((s8 *)mist_ctrl + 0x90) = (s32)spawn_continuous_particle_effect_with_flags((mist_ctrl + 0x38), 0x200, 0x800);
    return mist_ctrl;
}


}
