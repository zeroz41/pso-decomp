#ifndef PSO_ENEMY_ENEMYSTATERECORD_H
#define PSO_ENEMY_ENEMYSTATERECORD_H

#include "types.h"
#include <stddef.h>

// One set entry's enemy state as the lobby keeps it (TSetManager allocates 0xB50 of them): what
// TObjEnemy::exchange_object_state copies out (mode 1) or stores (mode 0), what send_6x0A_enemy_state
// sends and what apply_enemy_state applies.
struct EnemyStateRecord {
    s32 flags;  // the enemy's actorFlags
    u16 drop_id;  // TLobby::init_id_tables numbers the entries; 0xFFFF once the drop is taken
    s16 damage;  // hpmax - hp
    u8 attack_status;  // 9 or 11, applied by apply_attack_stat_status
    u8 attack_status_level;
    u8 defense_status;  // 10 or 12, applied by apply_defense_stat_status
    u8 defense_status_level;
    void copy_header(const EnemyStateRecord *source);
    void bswap();
};

LAYOUT_ASSERT(EnemyStateRecord_size, sizeof(EnemyStateRecord) == 0xC);
LAYOUT_ASSERT(EnemyStateRecord_damage_offset, offsetof(EnemyStateRecord, damage) == 6);
LAYOUT_ASSERT(EnemyStateRecord_attack_status_offset, offsetof(EnemyStateRecord, attack_status) == 8);

extern EnemyStateRecord *TLobby__data_805D6144;

#endif
