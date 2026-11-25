#ifndef PSO_UNK_TDELAYEDAREAMUSIC_H
#define PSO_UNK_TDELAYEDAREAMUSIC_H
#include "types.h"
#include "pso/system/task/TObject.h"

// A task that counts down delay_frames, then plays an area music track and destroys itself.
// TLobby::start_duel_battle and TPlayerBattleCtrl4P::start_duel create it with the duel music and 0x2D.
class TDelayedAreaMusic : public TObject {
public:
    TDelayedAreaMusic(TObject *parent, const char *name, s32 delay);
    virtual ~TDelayedAreaMusic();
    virtual void run_task();

    s32 delay_frames;      // name inferred
    char music_name[0x20]; // passed to play_area_music
};
LAYOUT_ASSERT(TDelayedAreaMusic_size, sizeof(TDelayedAreaMusic) == 0x40);

#endif
