#ifndef PSO_PLAYER_TPLYPHOTONCHAIR_H
#define PSO_PLAYER_TPLYPHOTONCHAIR_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TMotionModel.h"
#include "pso/ui/hud/MarkerColor.h"

// The photon chair a lobby player sits on: two animated seat models that unfold
// while the owner is mounted and fold away (then the chair is destroyed) once
// the owner gets up, and a marker tinted with the owner's section id colour.
struct TPlyPhotonChair : public TObjBase {
    TPlyPhotonChair(s32 owner_id, TObject *parent);
    virtual ~TPlyPhotonChair();
    u16 get_owner_id();
    u16 owner_id;  // client id of the seated player
    u16 m_92;
    u32 owner_dismounted;  // set once the owner stands up; the seat then folds away
    TMotionModel lobby_seat;  // fs_obj_lobby_isu, drawn in the second render pass
    TMotionModel meka_seat;   // fs_obj_isu_meka, drawn at half colour otherwise
    MarkerColor marker;
    virtual void render();
    virtual void run_task();
    static void free_static_model();
    static s32 load_resources();
    void set_owner_id(s32 owner_id);
    static void free_instance();
    // Whether the owner still sits in it (owner_dismounted is clear).
    int is_owner_seated();

    static const char *class_name;
    // The photon chair models and motions, loaded by load_resources.
    static BmlResource *shared_model_resource;
};

LAYOUT_ASSERT(TPlyPhotonChair_size, sizeof(TPlyPhotonChair) == 0xE4);
#endif
