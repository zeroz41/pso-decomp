#ifndef PSO_OBJECT_LOBBY_TOBJBUTTERFLYLOBBY_H
#define PSO_OBJECT_LOBBY_TOBJBUTTERFLYLOBBY_H

#include <stddef.h>
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct NJS_TEXLIST;
struct ObjectSetData;

struct TObjButterflyLobby : public TObjBase {
    TObjButterflyLobby(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjButterflyLobby();
    // 0 hidden while a lobby event runs, 2 growing back, 3 shown, 1 shrinking away.
    s32 appear_state;
    f32 appear_scale;
    Vec hover_origin;  // its start position; y is the height it bobs around
    Vec velocity;
    f32 animation_frame;
    f32 animation_speed;
    f32 lift;  // vertical push toward the bobbing height
    s16 state_timer;
    s16 bob_phase;
    u8 flight_state;  // 0 hovering, 1 drifting, 2 turning
    u8 rising;
    u8 turn_dir;
    NJS_OBJECT *lobby_model;
    NJS_TEXLIST *model_textures;
    static void free_singleton_805D4E6C();
    static void alloc_scene_buffer();
    void init_params();
    void draw_butterfly();
    virtual void render();
    void update_fade();
    virtual void run_task();
    static void destroy_instance();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjButterflyLobby_hover_origin, offsetof(TObjButterflyLobby, hover_origin) == 0x98);
LAYOUT_ASSERT(TObjButterflyLobby_turn_dir, offsetof(TObjButterflyLobby, turn_dir) == 0xC2);
LAYOUT_ASSERT(TObjButterflyLobby_size, sizeof(TObjButterflyLobby) == 0xCC);
#endif
