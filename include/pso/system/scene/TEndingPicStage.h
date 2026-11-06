#ifndef PSO_SYSTEM_SCENE_TENDINGPICSTAGE_H
#define PSO_SYSTEM_SCENE_TENDINGPICSTAGE_H
#include "pso/system/task/TObject.h"
#include "pso/player/PlayerClassFlags.h"

class TEndingPicStage : public TObject {
public:
    TEndingPicStage(TObject *parent);
    virtual ~TEndingPicStage();
    virtual void render();
    virtual void run_task();
    void publish_light();
    void set_camera();
    static void pose_player(player_class_type class_type, s8 picture);
    static void set_picture(s32 picture);
};

#endif
