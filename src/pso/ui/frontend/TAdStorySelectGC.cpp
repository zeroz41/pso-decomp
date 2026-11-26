#include "types.h"
#include "pso/map/FloorMapSelection.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"

extern s32 story_select_pending_state;

s32 request_story_select_state(s32 state) {
    if ((s32) story_select_pending_state == -1) {
        story_select_pending_state = state;
        return 1;
    }
    return 0;
}

void TAdStorySelectGC::set_state(s32 episode) {
    selected_episode = episode;
    switch (episode) {
    case 0:
        init_floor_map_registry();
        return;
    case 1:
        reset_floor_map_registry();
        return;
    }
}
