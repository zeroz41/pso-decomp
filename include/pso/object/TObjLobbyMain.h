#ifndef PSO_OBJECT_TOBJLOBBYMAIN_H
#define PSO_OBJECT_TOBJLOBBYMAIN_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

class TParticleCtrl;
struct BmlResource;
struct NJS_CNK_MODEL;

// The lobby's centre piece: one model per event theme (the set data picks the
// one shown with no event), faded out and back in when the theme changes,
// with two bubble emitters for the fish tank and the computer screens'
// scrolling UVs.
struct TObjLobbyMain : public TObjMapObject {
    TObjLobbyMain(TObject *parent, void *set_data);
    virtual ~TObjLobbyMain();
    void demo_step();
    void resolve_theme_index();
    void set_mode_index_from_state();
    void update_emitter_positions();
    void update_particles();
    void update_computer_machines();
    void advance_motion_frame();
    void update_fade_in();
    void update_fade();
    void check_event_theme();
    s32 fade_state;       // 0 fading out, 1 fading in, 2 shown
    s32 event_theme;      // the theme resolve_theme_index last read
    s16 model_index;      // the model (and motion) shown
    s16 set_model_index;  // the model the set data picks with no event
    f32 fade_scale;       // 0..1, the xz scale it fades out and in with
    TParticleCtrl *emitter0;
    TParticleCtrl *emitter1;
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
    static void free_resources();
    static void load_resources();

    static BmlResource *model_resource;
    static u32 lobby_texlist;  // the lobby's shared texture list
    // The two computer-screen meshes whose UVs scroll once per frame.
    static NJS_CNK_MODEL *computer_screen_model;
    static NJS_CNK_MODEL *computer_screen_model_b;
    static s32 computer_last_frame_tick;
};

typedef char TObjLobbyMain_size[sizeof(TObjLobbyMain) == 0xE0 ? 1 : -1];
#endif
