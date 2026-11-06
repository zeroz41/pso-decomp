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
    static TObjWarnChime* create(TObject* parent);
};
#include <stddef.h>
typedef char WarnChimeBaseSize[(sizeof(TObject)==0x1C)?1:-1];
typedef char WarnChimeSize[(sizeof(TObjWarnChime)==0x38)?1:-1];
typedef char WarnChimeState[(offsetof(TObjWarnChime,m_state)==0x1C)?1:-1];
typedef char WarnChimeCountdown[(offsetof(TObjWarnChime,m_countdown)==0x20)?1:-1];
typedef char WarnChimeInterval[(offsetof(TObjWarnChime,m_chime_interval)==0x24)?1:-1];
typedef char WarnChimeRatios[(offsetof(TObjWarnChime,m_player_hp_ratios)==0x28)?1:-1];
#endif
