#include "types.h"
#include "pso/ui/frontend/TAdExNetConfirmGC.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdExNetConfirmGC_8032C504.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/unk/text_80145A94.h"

#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/unk/TLobby.h"

struct Base_8032C504 { char pad[0x18]; };
struct VObj_8032C504 : Base_8032C504 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};
struct Base_8032C594_8032C504 { char pad[0x18]; };
struct VObj_8032C594_8032C504 : Base_8032C594_8032C504 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct RecoveredGlobal_8032C618___vt__17TAdExNetConfirmGC { s32 value; u8 remaining[0x24]; };
typedef char RecoveredGlobal_8032C618___vt__17TAdExNetConfirmGC_size[sizeof(RecoveredGlobal_8032C618___vt__17TAdExNetConfirmGC) == 0x28 ? 1 : -1];

extern "C" {
extern s32 __vt__17TAdExNetConfirmGC[];
extern s32 lbl_805D4200;
int request_scene_change__21TAdMultiChgGameModeGCFv(void*);

void TAdExNetConfirmGC::render() {
    struct VObj_8032C504 *o = (struct VObj_8032C504 *)this;
    o->m7();
}

void TAdExNetConfirmGC::vfunc_7() {
    if (TAdExNetConfirmGC::is_confirmed() != 0) {
        get_localized_text_entry(0x22, 1);
        return;
    }
    get_localized_text_entry(0x22, 0);
}

int TAdExNetConfirmGC::vfunc_6() { return request_scene_change__21TAdMultiChgGameModeGCFv(this); }

void TAdExNetConfirmGC::run_task() {
    struct VObj_8032C594_8032C504 *o = (struct VObj_8032C594_8032C504 *)this;
    o->m6();
}

}
TAdExNetConfirmGC::~TAdExNetConfirmGC() {

}

u8 *TAdExNetConfirmGC__ct(u8 *object) {
    TAdWarningBaseGC__ct((TAdWarningBaseGC *)object);
    *(s32 **)((s8 *)object + 0x18) = &(*(RecoveredGlobal_8032C618___vt__17TAdExNetConfirmGC *)&__vt__17TAdExNetConfirmGC).value;
    *(s32 *)((s8 *)object + 0) = (s32) lbl_805D4200;
    if ((TLobby__sub_80145DB4(1) != 0) || (TLobby__sub_80145DB4(4) != 0)) {
        if (TLobby__sub_80145A94() != 0) {
            TLobby::init_account_entries();
        } else {
            TKeyBoardControl__sub_8000F9CC(0x13);
        }
        queue_destruction__7TObjectFv(object);
        TAdMultiChgGameModeGC::set_game_mode();
        return object;
    }
    return object;
}

