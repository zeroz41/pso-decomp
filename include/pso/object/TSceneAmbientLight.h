#ifndef PSO_OBJECT_TSCENEAMBIENTLIGHT_H
#define PSO_OBJECT_TSCENEAMBIENTLIGHT_H
#include "types.h"
#include "pso/object/TSceneLight.h"

class TSceneAmbientLight : public TSceneLight {
public:
    TSceneAmbientLight(TObject *parent);
    virtual void render();
    virtual ~TSceneAmbientLight();
    void update_stub();
    void submit_scene_ambient_color();
    void init_stub();
};
LAYOUT_ASSERT(TSceneAmbientLight_size, sizeof(TSceneAmbientLight) == 0x1C);

#endif
