#include "pso/player/TUnk_804928CC.h"
#include "pso/player/TObjPlayer_801542CC.h"

CollisionBody construct_collision_body_parts = {
    {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0, 0x9D03, {0.0f, 0.0f, 0.0f}, 0.0f
};

TUnk_804928CC::~TUnk_804928CC() {
    free_collision_body_parts(this);
}

TUnk_804928CC::TUnk_804928CC(TObject *parent, TObjBase *owner,
                           const CollisionBody *parts, s32 count)
    : TObjCollidable(parent) {
    init_collision_body_parts(this, parts, count);
    this->owner = (u32)owner;
}

TUnk_804928CC::TUnk_804928CC(TObject *parent, TObjBase *owner)
    : TObjCollidable(parent) {
    init_collision_body_parts(this, &construct_collision_body_parts, 1);
    if (owner != NULL) {
        sub_800BC3E8((u8 *)owner);
    } else {
        this->owner = 0;
    }
}
