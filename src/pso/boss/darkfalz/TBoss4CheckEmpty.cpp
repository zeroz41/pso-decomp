#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/darkfalz/TBoss4CheckEmpty.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/system/task/TObject_80019A50.h"

#include "types.h"
#include "pso/boss/darkfalz/TBoss4Thanks.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"

#pragma readonly_strings on

extern "C" {
s32 is_door_open_and_ready__12TBoss4ThanksFv();
}
void init_music_sequencer(s32 program);
const char *TBoss4CheckEmpty__name = "TBoss4CheckEmpty";
void TBoss4CheckEmpty::render() {  }
void TBoss4CheckEmpty::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TBoss4Type2::is_active() != 0) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    this->m_wait_frames = (s32) (this->m_wait_frames + 1);
    if ((s32) this->m_wait_frames > 0x5A) {
        if (is_door_open_and_ready__12TBoss4ThanksFv() != 0) {
            TBoss4Thanks::create();
            play_area_music((char *)("T1.adx"));
        } else {
            init_music_sequencer(4);
        }
        ((TObject *)arg0)->queue_destruction();
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
