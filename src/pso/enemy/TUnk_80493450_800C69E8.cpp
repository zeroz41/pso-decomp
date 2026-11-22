#include "pso/enemy/TUnk_80493450.h"

void TUnk_80493450::beast_update_appear() { mode = 1; }
void TUnk_80493450::update_attack_trail() {}
void TUnk_80493450::spawn_death_effect() {}
void TUnk_80493450::play_alert_sound() {}
void TUnk_80493450::play_attack_sound() {}
void TUnk_80493450::play_hurt_sound() {}
void TUnk_80493450::play_death_sound() {}
void TUnk_80493450::run_demo_task() {}

u16 get_enemy_target_id(TObjEnemy *enemy) { return enemy->targetId; }
