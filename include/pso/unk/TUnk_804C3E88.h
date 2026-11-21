#ifndef PSO_UNK_TUNK_804C3E88_H
#define PSO_UNK_TUNK_804C3E88_H
#include "types.h"
#include "pso/system/task/TObject.h"

// A task that counts down delay_frames, then plays an area music track and destroys itself.
// TLobby::start_duel_battle and TPlayerBattleCtrl4P::start_duel create it with the duel music and 0x2D.
class TUnk_804C3E88 : public TObject {
public:
    TUnk_804C3E88(TObject *parent, const char *name, s32 delay);
    virtual ~TUnk_804C3E88();
    virtual void run_task();

    s32 delay_frames;      // name inferred
    char music_name[0x20]; // passed to play_area_music
};
LAYOUT_ASSERT(TUnk_804C3E88_size, sizeof(TUnk_804C3E88) == 0x40);

#endif
