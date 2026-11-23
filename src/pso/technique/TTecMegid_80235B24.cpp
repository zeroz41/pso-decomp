#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TUnk_804CCA90.h"
#include "pso/system/SoundEffect.h"

void TUnk_804CCA90::run_task() {
    m_timer++;
    if (m_timer > m_delay) {
        play_sound_effect(m_sound_id, &m_pos, 0, 0);
        queue_destruction();
    }
}

TUnk_804CCA90::~TUnk_804CCA90() {
}

TUnk_804CCA90::TUnk_804CCA90(Vec *pos, s16 delay, s32 sound_id, TObject *parent) : TObject(parent) {
    m_delay = delay;
    m_timer = 0;
    m_sound_id = sound_id;
    VecCopy(&m_pos, pos);
}
