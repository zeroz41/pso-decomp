#ifndef PSO_UNK_TBATTLEPROXIMITYSOUND_H
#define PSO_UNK_TBATTLEPROXIMITYSOUND_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TObjPlayer;

// The battle sonar: using a sonar item (TWindowSubItem, TWindowShortListCtrl) creates it in the battle
// areas; run_task plays a proximity sound by the distance from its owner to the nearest other player until
// its life runs out.
class TBattleProximitySound : public TObject {
public:
    TBattleProximitySound(TObject *parent);
    virtual ~TBattleProximitySound();
    virtual void run_task();
    // Creates the instance in the battle areas when none runs; returns 1 when it did.
    static s32 create();
    static void destroy();
    static void clear_battle_proximity_sound();
    static TBattleProximitySound *instance;
    s32 life;
    s32 timer;
    TObjPlayer *owner;
};
LAYOUT_ASSERT(TBattleProximitySound_size, sizeof(TBattleProximitySound) == 0x28);

// The active character's battle results (CharacterSaveRecord::online_battle): battles won in each place and
// battles left early. Defined in the same unit as TBattleProximitySound.
void set_active_disconnect_count(u16 count);
u16 get_active_disconnect_count();
void set_active_fourth_place_count(u16 count);
u16 get_active_fourth_place_count();
void set_active_third_place_count(u16 count);
u16 get_active_third_place_count();
void set_active_second_place_count(u16 count);
u16 get_active_second_place_count();
void set_active_first_place_count(u16 count);
u16 get_active_first_place_count();

#endif
