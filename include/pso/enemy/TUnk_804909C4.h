#ifndef PSO_ENEMY_TUNK_804909C4_H
#define PSO_ENEMY_TUNK_804909C4_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;

// A shot of the Dark Gunner (TObjEneDarkGunner::update_attack fires it at its
// target). It flies straight at the gunner's float parameter 3 per frame until
// it hits a player or its range to the first wall runs out.
class TUnk_804909C4 : public TObjCollidable {
public:
    TUnk_804909C4(u8 *owner, saddr start, saddr target);
    virtual ~TUnk_804909C4();
    // Runs the collisions with the owner's bodies masked out; on a player
    // contact it deals int parameter 3 to every player hit and returns 1.
    s32 check_player_hits(u16 owner);
    virtual void run_task();

    Vec velocity;
    s32 trail_rotation[3];  // the trail's angles: none, the heading, a quarter turn
    s32 lifetime;           // frames left until it reaches the wall in its path
    u16 owner_id;           // get_entity_id of the gunner that fired it
    u8 pad_ca[0x2];
    s32 trail_particle_id;  // 0xDA for a death gunner, else 0xD5
    TParticleCtrl *trail;
};
LAYOUT_ASSERT(TUnk_804909C4_size, sizeof(TUnk_804909C4) == 0xD4);

#endif
