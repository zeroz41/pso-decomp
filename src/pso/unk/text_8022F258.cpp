#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject_80019A50.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/technique/TechniqueBoost.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TUnk_804CC74C.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/vector.h"
#include "pso/system/SoundEffect.h"
#include "pso/technique/TTecDeband.h"
u32 dark_technique_charge_effect_ids[3] = {0x1E7, 0x1E8, 0x1EF};
TechniqueBoostTable::TechniqueBoostTable() {
    clear();
}

void TUnk_804CC74C::run_task() {
    ++m_age;
    if(m_age%10==0) {
        for(int i=0;i<3;++i)spawn_particle_effect(&m_position,dark_technique_charge_effect_ids[i]);
    }
    if(!m_actor->check_flag_0x80())queue_destruction();
    else if(m_age>=180)queue_destruction();
}

TUnk_804CC74C::~TUnk_804CC74C() {
    stop_sound_request(m_sound_handle);
}

struct Obj_8022F42C { u8 pad[0xA6]; s16 state; };

TUnk_804CC74C::TUnk_804CC74C(TObjPlayer *actor, TObject *parent) : TObject(parent) {
    m_actor = actor;
    VecCopy(&m_position, &m_actor->body_center);
    m_age = 0;
    m_sound_handle = play_sound_effect(0x4002BB1F, &m_position, 0, 0);
}

void TTecDeband::play_state_sound() {
    Obj_8022F42C *arg0 = (Obj_8022F42C *)this;
    s32 r;
    switch (band) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002AA16, reinterpret_cast<Vec *>(reinterpret_cast<u8 *>(arg0) + 0x20), 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002AA16, reinterpret_cast<Vec *>(reinterpret_cast<u8 *>(arg0) + 0x20), 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002AA16, reinterpret_cast<Vec *>(reinterpret_cast<u8 *>(arg0) + 0x20), 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
}
