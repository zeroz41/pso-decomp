#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_80336054.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"

extern "C" {

u32 __nw__7TObjectFUl(s32);

    extern int lobby_game_mode_state;
int TAdSinglePlyChrSelectGC::get_data() {  return lobby_game_mode_state; }

int TAdSinglePlyChrSelectGC__sub_8033605C(void) { return 0; }

extern s32 queue_destruction_and_cleanup__6TLobbyFv[];
extern s32 tl_fade;

s32 TAdSinglePlyChrSelectGC::start_offline_seq() {
    s32 *temp_r3;
    if (!(this->m_3c & 2)) {
        temp_r3 = (s32 *) __nw__7TObjectFUl(0x28);
        if (temp_r3 != NULL) {
            ((THunterGuildSeqOffline *)temp_r3)->init((void *)tl_fade, (void *)queue_destruction_and_cleanup__6TLobbyFv);
        }
        this->m_3c = (s32) (this->m_3c | 2);
    }
    return this->m_3c & 4;
}

}
