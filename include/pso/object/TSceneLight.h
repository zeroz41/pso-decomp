#ifndef PSO_OBJECT_TSCENELIGHT_H
#define PSO_OBJECT_TSCENELIGHT_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TSceneLight : public TObject {
public:
    TSceneLight(TObject *parent);
    virtual ~TSceneLight();
};

#endif
