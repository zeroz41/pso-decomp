#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/enemy/recon/TObjEneRecon.h"

extern "C" {

s32 refresh_lobby_state__10TObjPlayerFv();
s32 send_entity_set_flags__9TObjEnemyFv();

void TObjEneRecon::handle_death_state(s32 arg1) {
    switch (arg1) {
    case 4:
        refresh_lobby_state__10TObjPlayerFv();
        *(s32 *)&this->m_428 = (s32) (*(s32 *)&this->m_428 | 1);
        TObjEneRecobox__sub_8031F1A8(this);
        this->vfunc_95();
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)this + 0x410) == 0) {
            send_entity_set_flags__9TObjEnemyFv();
            queue_destruction__7TObjectFv(this);
        }
    case 5:
    case 0:
        return;
    }
}

}
