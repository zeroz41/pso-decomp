#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/goldragon/TBoss8DragonEffBreath.h"

#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"
#include "pso/system/vector.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjControl.h"

#pragma readonly_strings on

extern "C" {
const char *TBoss8DragonEffBreath__name = "TBoss8DragonEffBreath";
s32 vec3_add_to(void *, void *);

void TBoss8DragonEffBreath::render() {  }


void TBoss8DragonEffBreath::run_task() {
    f32 y;
    uaddr ent;

    vec3_add_to(&m_1c, &m_28);
    y = m_1c.y;
    if (y < -10.0f) {
        queue_destruction();
        return;
    }
    if ((y < 30.0f) && ((ent = (uaddr)get_enemy_entity(m_38)) != 0U)) {
        ((TBoss8Dragon *)ent)->setup_breath_instance(&m_1c, m_34, m_3c);
    }
}

}
TBoss8DragonEffBreath::~TBoss8DragonEffBreath() {
    delete m_3c;
    m_3c = 0;
}
TBoss8DragonEffBreath::TBoss8DragonEffBreath(TObject *parent, Vec *pos, Vec *velocity, s32 kind, u16 owner) : TObject(parent) {
    m_name = TBoss8DragonEffBreath__name;
    VecCopy(&m_1c, pos);
    VecCopy(&m_28, velocity);
    m_28.x *= 5.0f;
    m_28.y *= 5.0f;
    m_28.z *= 5.0f;
    m_34 = kind;
    m_38 = owner;
    m_3c = new AreaAttackHistory(4);
}
