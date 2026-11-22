#ifndef PSO_BOSS_GOLDRAGON_TOBJBOSS8PILLER_H
#define PSO_BOSS_GOLDRAGON_TOBJBOSS8PILLER_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

struct AnimationMotion;
struct NJS_OBJECT;

// A Gol Dragon pillar: plays its motion once, then removes itself.
class TObjBoss8Piller : public TObject {
public:
    TObjBoss8Piller(TObject *parent, Vec *pos, f32, u16 dragon_id);
    virtual ~TObjBoss8Piller();
    virtual void run_task();
    virtual void render();
public:
    static void free_held_object();
    static void load_resource_descriptor();

    Vec position;
    f32 frame;
    AnimationMotion *motion;
    u16 dragon_id;  // entity id; run_task passes that entity's pillar attack to TBoss8Dragon::apply_pillar_attack
};

#endif
