#ifndef PSO_OBJECT_TSCENEDIRECTIONALLIGHT_H
#define PSO_OBJECT_TSCENEDIRECTIONALLIGHT_H
#include "types.h"
#include "pso/object/TSceneLight.h"

// The scene's environment light (init_map_lights / init_menu_scene_lights create it).
class TSceneDirectionalLight : public TSceneLight {
public:
    TSceneDirectionalLight(TObject *parent);
    virtual void render();
    virtual ~TSceneDirectionalLight();
    void set_scene_light_diffuse();
    void submit_scene_light_direction();
    void update_stub();
};
LAYOUT_ASSERT(TSceneDirectionalLight_size, sizeof(TSceneDirectionalLight) == 0x1C);

#endif
