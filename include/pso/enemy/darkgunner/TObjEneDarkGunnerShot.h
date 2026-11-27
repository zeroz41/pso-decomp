#ifndef PSO_ENEMY_DARKGUNNER_TOBJENEDARKGUNNERSHOT_H
#define PSO_ENEMY_DARKGUNNER_TOBJENEDARKGUNNERSHOT_H
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;
struct TObjEneDarkGunner;

// A shot of the Dark Gunner (TObjEneDarkGunner::update_attack fires it at its
// target). It flies straight at the gunner's float parameter 3 per frame until
// it hits a player or its range to the first wall runs out.
class TObjEneDarkGunnerShot : public TObjCollidable {
public:
    TObjEneDarkGunnerShot(TObjEneDarkGunner *owner, Vec *start, Vec *target);
    virtual ~TObjEneDarkGunnerShot();
    // Runs the collisions with the owner's bodies masked out; on a player
    // contact it deals int parameter 3 to every player hit and returns 1.
    s32 check_player_hits(u16 owner);
    virtual void run_task();

    Vec velocity;
    Angle3 trail_rotation;  // the trail's angles: none, the heading, a quarter turn
    s32 lifetime;           // frames left until it reaches the wall in its path
    u16 owner_id;           // get_entity_id of the gunner that fired it
    u8 pad_ca[0x2];
    s32 trail_particle_id;  // 0xDA for a death gunner, else 0xD5
    TParticleCtrl *trail;
};
LAYOUT_ASSERT(TObjEneDarkGunnerShot_size, sizeof(TObjEneDarkGunnerShot) == 0xD4);

#endif
