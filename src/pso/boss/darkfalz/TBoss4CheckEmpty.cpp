#include "pso/boss/darkfalz/TBoss4CheckEmpty.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/system/task/TObject_80019A50.h"

#include "types.h"
#include "pso/boss/darkfalz/TBoss4Thanks.h"

extern "C" {
s32 is_active__11TBoss4Type2Fv();
s32 is_door_open_and_ready__12TBoss4ThanksFv();
}
void init_music_sequencer(s32 program);
extern s32 lbl_804789DC[];
extern const char *TBoss4CheckEmpty__name;
void TBoss4CheckEmpty::render() {  }
void TBoss4CheckEmpty::run_task() {
    u8 *arg0 = (u8 *)this;
    if (is_active__11TBoss4Type2Fv() != 0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) (*(s32 *)((s8 *)arg0 + 0x1C) + 1);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x1C) > 0x5A) {
        if (is_door_open_and_ready__12TBoss4ThanksFv() != 0) {
            TBoss4Thanks::create();
            play_area_music((char *)(lbl_804789DC));
        } else {
            init_music_sequencer(4);
        }
        queue_destruction__7TObjectFv((arg0));
    }
}
TBoss4CheckEmpty::~TBoss4CheckEmpty() {}

TBoss4CheckEmpty::TBoss4CheckEmpty(TObject *parent) : TObject(parent) {
    m_name = TBoss4CheckEmpty__name;
    m_wait_frames = 0;
}

void *TBoss4CheckEmpty::create() {
    return new TBoss4CheckEmpty(tl_02);
}
