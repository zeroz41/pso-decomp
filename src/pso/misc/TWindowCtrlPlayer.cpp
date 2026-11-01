#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowCtrlPlayer.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"

#include "pso/TObject.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjLuker.h"

struct Ctl_8024E2A8 {
    s32 f0;
    u8 pad4[0x18 - 4];
    s32 *vt;
    s16 f1c, f1e, f20;
    s32 f24;
    void *f28;
    void *f2c;
    void *f30;
    void *f34;
    void *f38;
    void *f3c;
};

extern "C" {

void run_all_updates__11TWindowCtrlFv(void* p);

s32 is_split_screen(void);
void *__nw__7TObjectFUl(u32);
void *TWindowActionPalette__ct(void *, s32);
s32 get_window_layout_position(s32);
void *TWindowMainMenu1P__ct(void *, void *, s32);
void *TWindowMainMenu4P__ct(void *, void *, s32);
extern u8 lbl_8044EC4C[];
extern s32 TWindowCtrlPlayer__name;

void TWindowCtrlPlayer::render() {  }
void TWindowCtrlPlayer::run_task() { sub_8024E0F0(); run_all_updates__11TWindowCtrlFv(this); }


}
TWindowCtrlPlayer::~TWindowCtrlPlayer() {
    if (*(void **)((s8 *)this + 0x3C) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x3C)); this->m_3c = 0; }
    if (*(void **)((s8 *)this + 0x38) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x38)))->close(); this->m_38 = 0; }
    if (*(void **)((s8 *)this + 0x34) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x34)))->close(); this->m_34 = 0; }
    if (*(void **)((s8 *)this + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x30)))->close(); this->m_30 = 0; }
    if (*(void **)((s8 *)this + 0x2C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x2C)))->close(); this->m_2c = 0; }
    if (*(void **)((s8 *)this + 0x28) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x28)); this->m_28 = 0; }
}
s32 create_message_information_window(s32 arg0, s32 arg1, s32 arg2);
s32 create_status_window(s32 arg0);
TWindowCtrlPlayer::TWindowCtrlPlayer(TObject *parent, s32 arg2) : TObject(parent) {
    void *p;
    ((struct Ctl_8024E2A8 *)this)->f0 = TWindowCtrlPlayer__name;
    ((struct Ctl_8024E2A8 *)this)->f1c = 0;
    ((struct Ctl_8024E2A8 *)this)->f1e = 0;
    ((struct Ctl_8024E2A8 *)this)->f20 = 0;
    ((struct Ctl_8024E2A8 *)this)->f24 = arg2;
    ((struct Ctl_8024E2A8 *)this)->f28 = 0;
    ((struct Ctl_8024E2A8 *)this)->f2c = 0;
    ((struct Ctl_8024E2A8 *)this)->f30 = 0;
    ((struct Ctl_8024E2A8 *)this)->f34 = 0;
    ((struct Ctl_8024E2A8 *)this)->f38 = 0;
    ((struct Ctl_8024E2A8 *)this)->f3c = 0;
    if (is_split_screen() != 0) {
        p = __nw__7TObjectFUl(0x60);
        if (p != 0) {
            p = TWindowMainMenu4P__ct(p, ((struct Ctl_8024E2A8 *)this), ((struct Ctl_8024E2A8 *)this)->f24);
        }
        ((struct Ctl_8024E2A8 *)this)->f28 = p;
    } else {
        p = __nw__7TObjectFUl(0xAC);
        if (p != 0) {
            p = TWindowMainMenu1P__ct(p, ((struct Ctl_8024E2A8 *)this), ((struct Ctl_8024E2A8 *)this)->f24);
        }
        ((struct Ctl_8024E2A8 *)this)->f28 = p;
    }
    ((struct Ctl_8024E2A8 *)this)->f2c = (void *)create_message_information_window((s32)(get_window_layout_position(0x20)), (s32)lbl_8044EC4C, (s32)(((struct Ctl_8024E2A8 *)this)->f24));
    ((struct Ctl_8024E2A8 *)this)->f30 = (void *)create_status_window(((struct Ctl_8024E2A8 *)this)->f24);
    ((TObject *)(((struct Ctl_8024E2A8 *)this)->f30))->suspend_update();
    p = __nw__7TObjectFUl(0x78);
    if (p != 0) {
        p = TWindowActionPalette__ct(p, ((struct Ctl_8024E2A8 *)this)->f24);
    }
    ((struct Ctl_8024E2A8 *)this)->f34 = p;
    ((TObject *)(((struct Ctl_8024E2A8 *)this)->f34))->suspend_update();
}
