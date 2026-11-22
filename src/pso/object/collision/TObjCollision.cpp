#include "types.h"
#include "pso/object/collision/TObjCollision.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

extern "C" {
u32 init_collision_body_parts(void *, saddr, s32);
const char *lbl_805D2830 = "TObjCollision";
void free_collision_body_parts(void *);

void TObjCollision::render() {  }
void TObjCollision::run_task() {  }


void *TObjCollision::create(void *arg0) {
    return new TObjCollision(tl_06, arg0);
}

}
TObjCollision::~TObjCollision() {
    free_collision_body_parts(this);
    this->unregister_object_by_id();
}

#define arg0 ((u8 *)this)
TObjCollision::TObjCollision(TObject *parent, void *arg2_) : TObjCollidable(parent) {
    s32 var_r0;
    saddr arg2 = (saddr)arg2_;
    ((TObjCollision *)arg0)->m_name = lbl_805D2830;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg2 + 0xC));
    copy_xyz(arg0 + 0x5C, (void *)(arg2 + 0x18));
    VecCopy((Vec *)(arg0 + 0x68), (const Vec *)(arg2 + 0x24));
    ((TObjCollision *)arg0)->actorFlags = (s32) (((TObjCollision *)arg0)->actorFlags | 0x02000000);
    *(f32 *)((s8 *)arg0 + 0xAC) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0xB0) = 0.0f;
    ((TObjCollision *)arg0)->m_b4 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0xB8) = (f32) ((TObjCollision *)arg0)->scale.x;
    ((TObjCollision *)arg0)->m_bc = (f32) ((TObjCollision *)arg0)->scale.y;
    if (*(f32 *)((s8 *)arg0 + 0x70) < 0.0f) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    ((TObjCollision *)arg0)->m_c0 = var_r0;
    ((TObjCollision *)arg0)->m_c4 = 0x10001;
    if (fabs_float(*(f32 *)((s8 *)arg0 + 0x70)) < 1000.0f) {
        ((TObjCollision *)arg0)->m_c4 = (s32) (((TObjCollision *)arg0)->m_c4 & 0xFFFFFEFF);
    } else {
        ((TObjCollision *)arg0)->m_c4 = (s32) (((TObjCollision *)arg0)->m_c4 | 0x100);
    }
    init_collision_body_parts(arg0, (saddr)(arg0 + 0xAC), 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
}
#undef arg0

