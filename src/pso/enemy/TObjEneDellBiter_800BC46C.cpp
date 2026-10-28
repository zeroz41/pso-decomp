#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/TObjEneDellBiter.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, void *);

extern "C" {

void init_collision_body_parts(void *, void *, void *);

extern s32 collision_body_vtable[];

void *TUnk_804928CC::init_instance(void *arg1, void *ac, void *arg3, void *count) {
    __ct__14TObjCollidableFP7TObject(this, arg1);
    *(s32 **)((s8 *)this + 0x18) = collision_body_vtable;
    init_collision_body_parts(this, arg3, count);
    *(void * *)&this->m_ac = ac;
    return this;
}

}
