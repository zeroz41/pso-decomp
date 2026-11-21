#ifndef PSO_BOSS_TUNK_804F1C88_H
#define PSO_BOSS_TUNK_804F1C88_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/CollisionBodySet.h"

class TUnk_804F1C88 : public TObject {
public:
    TUnk_804F1C88(TObject *parent, const Vec *origin);
    virtual ~TUnk_804F1C88();
    virtual void render();
    virtual void run_task();
    // A growing sphere at the laser's impact: each frame it reports the
    // players it touches to the parent De Rol Le (role inferred).
    CollisionBodySet hit_set;
    CollisionBody hit_body;

    // Empty load/unload pair in TBoss7DeRolLeC's resource table (names
    // inferred from the TBoss7Crawfish entry of the same table).
    static void destroy_instance();
    static void load_static_resource();
};
LAYOUT_ASSERT(TUnk_804F1C88_size, sizeof(TUnk_804F1C88) == 0x60);

#endif
