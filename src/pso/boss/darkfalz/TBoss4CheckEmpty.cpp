#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/darkfalz/TBoss4CheckEmpty.h"
#include "pso/system/task/TMainTask.h"
#include "pso/audio/MusicControl.h"

#include "types.h"
#include "pso/boss/darkfalz/TBoss4Thanks.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/audio/SoundRequests.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"

#pragma readonly_strings on

const char *TBoss4CheckEmpty::name = "TBoss4CheckEmpty";
void TBoss4CheckEmpty::render() {  }
void TBoss4CheckEmpty::run_task() {
    if (TBoss4DarkFalz::has_instance() != 0) {
        queue_destruction();
        return;
    }
    this->m_wait_frames = (s32) (this->m_wait_frames + 1);
    if ((s32) this->m_wait_frames > 0x5A) {
        if (TBoss4Thanks::is_door_open_and_ready() != 0) {
            TBoss4Thanks::create();
            play_area_music((char *)("T1.adx"));
        } else {
            init_music_sequencer(4);
        }
        queue_destruction();
    }
}
TBoss4CheckEmpty::~TBoss4CheckEmpty() {}

TBoss4CheckEmpty::TBoss4CheckEmpty(TObject *parent) : TObject(parent) {
    m_name = TBoss4CheckEmpty::name;
    m_wait_frames = 0;
}

void *TBoss4CheckEmpty::create() {
    return new TBoss4CheckEmpty(tl_02);
}
