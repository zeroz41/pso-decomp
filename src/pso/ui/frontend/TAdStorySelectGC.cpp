#include "types.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"

extern s32 story_select_pending_state;

s32 request_story_select_state(s32 arg0) {
    if ((s32) story_select_pending_state == -1) {
        story_select_pending_state = arg0;
        return 1;
    }
    return 0;
}

extern s32 selected_episode;

void TAdStorySelectGC::set_state(s32 arg0) {
    selected_episode = arg0;
    switch (arg0) {
    case 0:
        init_floor_map_registry();
        return;
    case 1:
        TLobby__sub_80207BB0();
        return;
    }
}
