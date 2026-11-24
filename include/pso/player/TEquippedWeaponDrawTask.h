#ifndef PSO_PLAYER_TEQUIPPEDWEAPONDRAWTASK_H
#define PSO_PLAYER_TEQUIPPEDWEAPONDRAWTASK_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

// Draws the equipped weapons TItemWeapon::render_equipped queues (weapon flag 0x800) in two
// draw-list passes, and scrolls the texture of drop model 5 each frame.
class TEquippedWeaponDrawTask : public TObject {
public:
    virtual ~TEquippedWeaponDrawTask();
    TEquippedWeaponDrawTask(TObject *parent);
    virtual void render();
    virtual void run_task();

    static void create(TObject *parent);
    static void create_queue();
    static void destroy_queue();
    static void queue_weapon(s32 item_id);
    // Save and restore the model render state around a faded item draw.
    static void save_model_render_state();
    static void restore_model_render_state();
    static void push_fade_color(NJS_ARGB *color);
    static void pop_fade_color();
    static void set_fade_alpha(f32 alpha);
    static void end_fade();
};
LAYOUT_ASSERT(TEquippedWeaponDrawTask_size, sizeof(TEquippedWeaponDrawTask) == 0x1C);

#endif
