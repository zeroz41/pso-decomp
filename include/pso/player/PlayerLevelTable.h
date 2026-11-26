#ifndef PSO_PLAYER_PLAYERLEVELTABLE_H
#define PSO_PLAYER_PLAYERLEVELTABLE_H

#include "types.h"
#include <stddef.h>

struct stats;
struct player_stats;

// One level of a class's growth table: stat gains and the experience the level needs.
struct PlayerLevelTableRow {
    u8 growth[6];  // atp, mst, evp, hp, dfp, ata
    u8 reserved[2];
    s32 experience;

    u8 get_ata_growth() const;
    u8 get_dfp_growth() const;
    u8 get_hp_growth() const;
    u8 get_evp_growth() const;
    u8 get_mst_growth() const;
    u8 get_atp_growth() const;
    s32 get_exp_threshold() const;
};

LAYOUT_ASSERT(PlayerLevelTableRowSize, sizeof(PlayerLevelTableRow) == 0xC);
LAYOUT_ASSERT(PlayerLevelTableExperienceOffset, offsetof(PlayerLevelTableRow, experience) == 0x8);

PlayerLevelTableRow *get_ply_level_table_row(s32 class_index, s32 level);
void load_ply_level_tbl(void);
void free_ply_level_tbl(void);

stats *get_class_base_stats(s32 class_index);
const player_stats *get_class_stat_caps(s32 class_index);
void apply_class_level_growth(s32 class_index, s32 level, stats *out);
void copy_stats(stats *out, const stats *source);
#endif
