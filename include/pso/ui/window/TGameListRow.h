#ifndef PSO_UI_WINDOW_TGAMELISTROW_H
#define PSO_UI_WINDOW_TGAMELISTROW_H

#include "types.h"
#include "pso/unk/TWindowLayoutRect.h"

// One game of the game list: the lock icon, the game name, its level, mark and difficulty
// columns and the player count (case 12 of init_window_layout_entries).
class TGameListRow : public TWindowLayoutRect {
public:
    s32 index;
    s8 icon;
    s8 level;
    s8 mark;
    s8 difficulty;
    s8 player_count;
    s8 max_players;
    char *text;

    TGameListRow(u8 *rec, s32 client);
    virtual ~TGameListRow();
    virtual void update();
    virtual void render(WindowDrawContext *context);
    void fill(s32 locked, const char *name, s8 player_count, s8 max_players, s8 difficulty, s8 mark, s8 level, s32 index);
    const char *get_difficulty_name(s8 difficulty);
    const char *get_game_mode_name(s8 mark);
    const char *get_episode_name(s8 level);
    int get_flag_4_bit();
};

LAYOUT_ASSERT(TGameListRow_size, sizeof(TGameListRow) == 0x28);

extern "C" {
// TGameListRow::TGameListRow(u8 *, s32), called by init_window_layout_entries.
void *__ct__12TGameListRowFPUcl(void *p, u8 *rec, s32 client);
}

#endif
