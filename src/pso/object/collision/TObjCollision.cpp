#include "types.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/object/collision/TObjCollision.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

extern "C" {
u32 init_collision_body_parts(void *, saddr, s32);
}
const char *lbl_805D2830 = "TObjCollision";

void TObjCollision::render() {  }
void TObjCollision::run_task() {  }


void *TObjCollision::create(void *arg0) {
    return new TObjCollision(tl_06, arg0);
}
TObjCollision::~TObjCollision() {
    free_collision_body_parts(this);
    this->unregister_object_by_id();
}

TObjCollision::TObjCollision(TObject *parent, void *arg2_) : TObjCollidable(parent) {
    s32 var_r0;
    saddr arg2 = (saddr)arg2_;
    this->m_name = lbl_805D2830;
    VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(arg2 + 0xC));
    copy_xyz(((u8 *)this) + 0x5C, (void *)(arg2 + 0x18));
    VecCopy((Vec *)(((u8 *)this) + 0x68), (const Vec *)(arg2 + 0x24));
    this->actorFlags = (s32) (this->actorFlags | 0x02000000);
    *(f32 *)((s8 *)((u8 *)this) + 0xAC) = 0.0f;
    *(f32 *)((s8 *)((u8 *)this) + 0xB0) = 0.0f;
    this->m_b4 = 0.0f;
    *(f32 *)((s8 *)((u8 *)this) + 0xB8) = (f32) this->scale.x;
    this->m_bc = (f32) this->scale.y;
    if (*(f32 *)((s8 *)((u8 *)this) + 0x70) < 0.0f) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    this->m_c0 = var_r0;
    this->m_c4 = 0x10001;
    if (fabs_float(*(f32 *)((s8 *)((u8 *)this) + 0x70)) < 1000.0f) {
        this->m_c4 = (s32) (this->m_c4 & 0xFFFFFEFF);
    } else {
        this->m_c4 = (s32) (this->m_c4 | 0x100);
    }
    init_collision_body_parts(((u8 *)this), (saddr)(((u8 *)this) + 0xAC), 1);
    this->register_object_by_id();
}

