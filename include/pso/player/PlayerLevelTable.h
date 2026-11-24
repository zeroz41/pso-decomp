#ifndef PSO_PLAYER_PLAYERLEVELTABLE_H
#define PSO_PLAYER_PLAYERLEVELTABLE_H

#include "types.h"
#include <stddef.h>

struct stats;
struct player_stats;

struct PlayerLevelTableRow {
    u8 growth[6];
    u8 reserved[2];
    s32 experience;
};

LAYOUT_ASSERT(PlayerLevelTableRowSize, sizeof(PlayerLevelTableRow) == 0xC);
LAYOUT_ASSERT(PlayerLevelTableExperienceOffset, offsetof(PlayerLevelTableRow, experience) == 0x8);

PlayerLevelTableRow *get_ply_level_table_row(s32 class_index, s32 level);
void load_ply_level_tbl(void);
void free_ply_level_tbl(void);

extern "C" {
stats *get_class_base_stats(s32 class_index);
const player_stats *get_class_stat_caps(s32 class_index);
void apply_class_level_growth(s32 class_index, s32 level, stats *out);
void copy_stats__10TObjPlayerFPv(stats *out, const stats *source);
s32 get_level_row_exp_threshold(const PlayerLevelTableRow *row);
u8 get_char_class__10TObjPlayerFv(const PlayerLevelTableRow *row);
u8 get_team_id__10TObjPlayerFv(const PlayerLevelTableRow *row);
u8 get_byte_2(const PlayerLevelTableRow *row);
u8 get_byte_3(const PlayerLevelTableRow *row);
u8 get_byte_4__10TObjPlayerFv(const PlayerLevelTableRow *row);
u8 get_field_5__10TObjPlayerFv(const PlayerLevelTableRow *row);
}
#endif
