#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/goldragon/TBoss8DragonEffBreath.h"

#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/system/vector.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjControl.h"
#include "pso/system/MatrixOps.h"

#pragma readonly_strings on

extern "C" {
const char *TBoss8DragonEffBreath::name = "TBoss8DragonEffBreath";

void TBoss8DragonEffBreath::render() {  }


void TBoss8DragonEffBreath::run_task() {
    f32 y;
    uaddr ent;

    vec3_add_to(&position, &velocity);
    y = position.y;
    if (y < -10.0f) {
        queue_destruction();
        return;
    }
    if ((y < 30.0f) && ((ent = (uaddr)get_enemy_entity(owner_entity_id)) != 0U)) {
        ((TBoss8Dragon *)ent)->setup_breath_instance(&position, attack_kind, attack_history);
    }
}

}
TBoss8DragonEffBreath::~TBoss8DragonEffBreath() {
    delete attack_history;
    attack_history = 0;
}
TBoss8DragonEffBreath::TBoss8DragonEffBreath(TObject *parent, Vec *pos, Vec *direction, s32 kind, u16 owner) : TObject(parent) {
    m_name = TBoss8DragonEffBreath::name;
    VecCopy(&position, pos);
    VecCopy(&velocity, direction);
    velocity.x *= 5.0f;
    velocity.y *= 5.0f;
    velocity.z *= 5.0f;
    attack_kind = kind;
    owner_entity_id = owner;
    attack_history = new AreaAttackHistory(4);
}
