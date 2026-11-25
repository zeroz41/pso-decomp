#include "pso/enemy/TObjEneBeastBase.h"

void TObjEneBeastBase::beast_update_appear() { mode = 1; }
void TObjEneBeastBase::update_attack_trail() {}
void TObjEneBeastBase::spawn_death_effect() {}
void TObjEneBeastBase::play_alert_sound() {}
void TObjEneBeastBase::play_attack_sound() {}
void TObjEneBeastBase::play_hurt_sound() {}
void TObjEneBeastBase::play_death_sound() {}
void TObjEneBeastBase::run_demo_task() {}

u16 get_enemy_target_id(TObjEnemy *enemy) { return enemy->targetId; }
