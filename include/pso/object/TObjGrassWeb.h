#ifndef PSO_OBJECT_TOBJGRASSWEB_H
#define PSO_OBJECT_TOBJGRASSWEB_H

#include "types.h"
#include "pso/object/TObjMotion.h"

// The web a TObjGrass spits at its target (TObjGrass::update_web_attack); it
// applies its effect to the player it hit, then waits out a timer.
struct TObjGrassWeb : public TObjBase {
    TObjGrassWeb(TObject *parent, TObjCollidable *target);
    virtual ~TObjGrassWeb();
    virtual void run_task();
    virtual void render();
    u32 m_90;
    u8 _pad94[0x10];
    u16 m_a4;
    void queue_destruction();
    void apply_to_player();
    u8 unk_A6[0x2];
};

typedef char TObjGrassWeb_size[sizeof(TObjGrassWeb) == 0xA8 ? 1 : -1];
#endif
