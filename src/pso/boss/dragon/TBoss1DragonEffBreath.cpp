#include "pso/boss/dragon/TBoss1DragonEffBreath.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"

extern "C" {
extern const char TBoss1DragonEffBreath__class_name_string[] = "TBoss1DragonEffBreath";
const char *TBoss1DragonEffBreath__name = TBoss1DragonEffBreath__class_name_string;
}

void TBoss1DragonEffBreath::render() {}

void TBoss1DragonEffBreath::run_task() {
    vec3_add_to(&position, &velocity);
    f32 height = position.y;
    if (height < -10.0f) {
        queue_destruction();
        return;
    }
    if (height < 30.0f) {
        ((TBoss1Dragon *)TBoss1Dragon::get_instance())->deliver_breath_attack(
            (saddr)&position, (saddr)attack_history);
    }
}

TBoss1DragonEffBreath::~TBoss1DragonEffBreath() {
    delete attack_history;
    attack_history = NULL;
}

TBoss1DragonEffBreath::TBoss1DragonEffBreath(TObject *parent, void *initial_position,
                                          void *direction) : TObject(parent) {
    m_name = TBoss1DragonEffBreath__name;
    VecCopy(&position, (const Vec *)initial_position);
    VecCopy(&velocity, (const Vec *)direction);
    velocity.x *= 5.0f;
    velocity.y *= 5.0f;
    velocity.z *= 5.0f;
    attack_history = new AreaAttackHistory(4);
}
