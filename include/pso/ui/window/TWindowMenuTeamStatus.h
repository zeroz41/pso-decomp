#ifndef PSO_UI_WINDOW_TWINDOWMENUTEAMSTATUS_H
#define PSO_UI_WINDOW_TWINDOWMENUTEAMSTATUS_H

#include "pso/ui/window/TWindowShop.h"

// Named from the "TWindowMenuTeamStatus" class-name string init stores to m_name.
class TWindowMenuTeamStatus : public TWindowShop {
public:
    static TWindowMenuTeamStatus *create(void *tbl);
    TWindowMenuTeamStatus(s32 arg);
    virtual ~TWindowMenuTeamStatus();
    virtual void init(u32 count, s32 id);

    // Fills the next free row with one game of the game list.
    void add_entry(s32 locked, const char *name, s8 player_count, s8 max_players, s8 difficulty, s8 mark, s8 level, s32 index);
};

LAYOUT_ASSERT(TWindowMenuTeamStatus_size, sizeof(TWindowMenuTeamStatus) == 0x8C);

#endif
