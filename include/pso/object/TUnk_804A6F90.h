#ifndef PSO_OBJECT_TUNK_804A6F90_H
#define PSO_OBJECT_TUNK_804A6F90_H
#include "types.h"
#include "pso/object/TUnk_804A6FC0.h"

// The scene's environment light (init_map_lights / init_menu_scene_lights create it).
class TUnk_804A6F90 : public TUnk_804A6FC0 {
public:
    TUnk_804A6F90(TObject *parent);
    virtual void render();
    virtual ~TUnk_804A6F90();
    void set_scene_light_diffuse();
    void submit_scene_light_direction();
    void sub_8013397C();
};
LAYOUT_ASSERT(TUnk_804A6F90_size, sizeof(TUnk_804A6F90) == 0x1C);

#endif
