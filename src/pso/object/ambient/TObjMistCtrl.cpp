#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/ambient/TObjMistCtrl.h"
#include "pso/unk/text_803E29B0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803DA798.h"

#include "pso/player/TPlayerFootStamp.h"

#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on


struct RecoveredGlobal_802AF7C0___vt__12TObjMistCtrl {
    s32 value;
    u8 remaining[0x34];
};


extern "C" {
const char *lbl_805D3E80 = "TObjMistCtrl";

void TObjMistCtrl::run_task() { { (void)(sub_802AF64C()); return; } }

}
TObjMistCtrl::~TObjMistCtrl() {
    if (*(void **)((s8 *)this + 0x90) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x90)))->queue_destruction(); *(s32 *)((s8 *)this + 0x90) = 0; }
}


typedef char RecoveredGlobal_802AF7C0___vt__12TObjMistCtrl_size[sizeof(RecoveredGlobal_802AF7C0___vt__12TObjMistCtrl) == 0x38 ? 1 : -1];
TObjMistCtrl::TObjMistCtrl(s32 parent, u32 arg2) : TObjBase((TObject *)((void *)parent)) {
    this->m_name = lbl_805D3E80;
    if (arg2 != 0U) {
        ((TObjMistCtrl *)(((u8 *)this)))->apply_object_set_data((void *)arg2);
    }
    *(s32 *)((s8 *)this + 0x90) = (s32)spawn_continuous_particle_effect_with_flags((((u8 *)this) + 0x38), 0x200, 0x800);
}


