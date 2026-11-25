#ifndef PSO_OBJECT_AMBIENT_TOBJGRASSWEB_H
#define PSO_OBJECT_AMBIENT_TOBJGRASSWEB_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

// The web a TObjGrass spits at its target (TObjGrass::update_web_attack); it
// applies its effect to the player it hit, then waits out a timer.
struct TObjGrassWeb : public TObjBase {
    TObjGrassWeb(TObject *parent, TObjCollidable *target);
    virtual ~TObjGrassWeb();
    virtual void run_task();
    virtual void render();
    u32 state;  // 0 apply the web to the player, 1 hold, 2 done
    u8 _pad94[0x10];
    u16 target_id;  // entity id of the player it holds
    void queue_destruction();
    void apply_to_player();
    // Plays the area's web sound and counts set_params[0] down to the end of the hold.
    void update_hold();
    u8 unk_A6[0x2];
};

LAYOUT_ASSERT(TObjGrassWeb_size, sizeof(TObjGrassWeb) == 0xA8);
#endif
