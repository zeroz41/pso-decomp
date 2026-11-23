#ifndef PSO_OBJECT_TOBJLOBBYPIGEON_H
#define PSO_OBJECT_TOBJLOBBYPIGEON_H
#include "types.h"
#include "pso/object/TObjPathObj.h"

struct NJS_OBJECT;
struct AnimationMotion;

class TObjLobbyPigeon : public TObjPathObj {
public:
    TObjLobbyPigeon(TObject *parent, void *set_data);
    static void *create(void *set_data);
    static void load_static_resource();
    static void destroy_instance();
    virtual ~TObjLobbyPigeon();
    s32 initialize_lobby_pigeon_path();
    s32 advance_lobby_pigeon_path();
    void update_lobby_pigeon_visibility();
    void select_lobby_pigeon_model();
    virtual void draw();
    virtual void update();
    s32 phase;                 // 0 hidden, 2 growing in, 3 shown, 1 shrinking out
    f32 scale;
    s32 model_index;           // 0 pigeon, 1 crow (set_params[2])
    s32 theme;                 // the lobby event theme it shows in (set_params[1])
    NJS_OBJECT *model;
    AnimationMotion *motion;   // the model's own motion
    AnimationMotion *path;     // the path motion of the profile
    f32 path_frame;
    f32 motion_frame;
    Vec path_position;         // the path's root node at path_frame, from position
    s32 path_yaw;
    s32 path_pitch;
    s32 path_roll;             // banks into turns, up to 0x2000
    s32 roll_speed;
    s32 profile;               // index into the path profiles, set_params[0] clamped
    s32 random_delay;          // 150 to 270 frames
};
LAYOUT_ASSERT(TObjLobbyPigeon_size, sizeof(TObjLobbyPigeon) == 0xE0);

#endif
