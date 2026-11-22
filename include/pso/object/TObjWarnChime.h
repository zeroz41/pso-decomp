#ifndef PSO_OBJECT_TOBJWARNCHIME_H
#define PSO_OBJECT_TOBJWARNCHIME_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TObjWarnChime : public TObject {
public:
    s32 m_state;
    s32 m_countdown;
    s32 m_chime_interval;
    f32 m_player_hp_ratios[4];

    TObjWarnChime(TObject* parent);
    virtual ~TObjWarnChime();
    virtual void run_task();
    void update_chime_countdown();
    void update_player_hp_ratios();
    void update_when_camera_active();
    void reset_state();
    // Whether the chime may run: the local player is up (outside split screen, in a quest)
    // and the floor is not Pioneer 2, the lobby or a battle stage.
    static s32 should_update();
    static TObjWarnChime* create(TObject* parent);
};
#include <stddef.h>
LAYOUT_ASSERT(WarnChimeBaseSize, sizeof(TObject)==0x1C);
LAYOUT_ASSERT(WarnChimeSize, sizeof(TObjWarnChime)==0x38);
LAYOUT_ASSERT(WarnChimeState, offsetof(TObjWarnChime,m_state)==0x1C);
LAYOUT_ASSERT(WarnChimeCountdown, offsetof(TObjWarnChime,m_countdown)==0x20);
LAYOUT_ASSERT(WarnChimeInterval, offsetof(TObjWarnChime,m_chime_interval)==0x24);
LAYOUT_ASSERT(WarnChimeRatios, offsetof(TObjWarnChime,m_player_hp_ratios)==0x28);
#endif
