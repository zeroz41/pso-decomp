#ifndef PSO_SYSTEM_TASK_TMAINTASK_H
#define PSO_SYSTEM_TASK_TMAINTASK_H

/* TMainTask - Main game loop task manager.
 * Derived from pso-gc-reference decomp (mrb0nk500).
 * Adapted for GPOE8P (PSO EP I&II Plus, MWCC 2.6).
 *
 * TMainTask is the root of the scene graph. Its children are the
 * Task Layer (TL) objects that handle different rendering/update
 * passes (camera, geometry, particles, UI, etc.).
 */

#include "pso/forward.h"
#include "pso/macros.h"
#include "pso/system/task/TObject.h"

#define X_OR_Y_CHILD(flags, old_flags, one_prefix, zero_prefix, suffix) \
    if (flags != old_flags) { \
        TMainTask *child; \
        u32 bit = 1; \
        FOREACH_NODE_NODECL_MULTI_ITER(TMainTask, main_task.m_down, child, bit <<= 1) { \
            if (flags & bit) { \
                child->one_prefix##_##suffix(); \
            } else { \
                child->zero_prefix##_##suffix(); \
            } \
        } \
        old_flags = flags; \
    }

#define PAUSE_OR_RESUME_CHILD(flags, old_flags) \
    X_OR_Y_CHILD(flags, old_flags, pause, resume, update)

#define DISALLOW_OR_ALLOW_CHILD(flags, old_flags, flag_name) \
    X_OR_Y_CHILD(flags, old_flags, allow, disallow, flag_name)

#define ALLOW_OR_DISALLOW_CHILD(flags, old_flags, flag_name) \
    X_OR_Y_CHILD(flags, old_flags, disallow, allow, flag_name)

#define o(var, name) extern const char *var##_name;
TL_OBJECTS
#undef o

/* Task layers: children of main_task, named by the game's own "TL_*" strings.
 * Roles below come from the objects parented to each layer and the pass
 * that draws it.
 *   tl_su            scene/system control (quest threads, loading, challenge)
 *   tl_00            scene sequencers: logos, quest controllers
 *   tl_camera        camera controllers; updated alone by run_tl_camera_tasks
 *   tl_01            game-mode controllers, window manager, boss controllers
 *   tl_02            map geometry and floors (TScene, set manager)
 *   tl_03            players and NPCs (drawn again by render_deferred_nodes)
 *   tl_item_equip    equipped weapon/item models, drawn with chunk flags
 *   tl_loc_start     lock-on cursor
 *   tl_04            enemies and bosses
 *   tl_05            map objects, items, traps
 *   tl_06            player-attached effects, collision, grass
 *   tl_07            techniques and effects (translucent pass)
 *   tl_loc_end       lock-on and main cursors
 *   tl_window        UI windows
 *   tl_particle      particle effects
 *   tl_particlemodel particle models (also drawn in the shadow pass)
 *   tl_radermap      radar map
 *   tl_clipout       2D menus drawn in the screen overlay
 *   tl_fade          screen fades
 *   tl_fadeafter     drawn over the fade (dialog message windows)
 */
#define o(var, name) extern TObject *var;
TL_OBJECTS
#undef o

extern u32 render_pass;
extern u32 update_flags;
extern u32 old_update_flags;
extern u32 render_flags;
extern u32 old_render_flags;
extern u32 render_shadow_flags;
extern u32 old_render_shadow_flags;

enum main_task_flags {
    MAIN_TASK_UPDATING          = 0x001, // inside run_task / run_tl_camera_tasks
    MAIN_TASK_RENDERING         = 0x002, // inside render / render_clipout_and_fade
    MAIN_TASK_SCENE_PASSES      = 0x010, // inside render_scene_passes
    MAIN_TASK_OBJECT_LAYERS     = 0x020, // inside render_object_layers
    MAIN_TASK_LAYER_02          = 0x040, // inside render_task_layer_02
    MAIN_TASK_UPDATED           = 0x080, // run_task finished this frame
    MAIN_TASK_RENDERED          = 0x100, // render finished this frame
    MAIN_TASK_DEFERRED_OBJECTS  = 0x200  // inside render_objects
};

class TMainTask : public TObject {
public:
    u32 task_flags;
    u32 reserved_20; // only ever zeroed by the constructor
    u32 reserved_24;

public:
    TMainTask();
    void render_screen_overlay();
    void begin_frame();
    void toggle_pause_layers();
    void resume_layers();
    void delete_layer_children();
    void toggle_pause_game_layers();
    void resume_game_layers();
    void debug_render_overlay();
    void run_tl_camera_tasks();
    void render_after_scene();
    void render_objects();
    void render_ui();
    void render_particle_effects();
    void render_effects();
    void render_geometry();
    void render_task_layer_02();
    void render_object_layers(int mode);
    void render_scene_passes();
    void render_clipout_and_fade();
    void init_main_task();

    virtual ~TMainTask();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
public:
    static s32 get_render_pass();
};

#endif
