#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/object/ambient/TObjRain.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
struct Vec_80197904 { f32 x, y, z; };

struct Drop_80197904 {
    s32 active;
    struct Vec_80197904 position;
    struct Vec_80197904 velocity;
    f32 floor_y;
};

struct Rain_80197904 {
    u8 pad00[0x1C];
    struct Drop_80197904 drops[16];
    u32 count;
};

struct Vec_801977D4 { f32 x, y, z; };

struct Drop_801977D4 {
    s32 active;
    struct Vec_801977D4 position;
    struct Vec_801977D4 velocity;
    f32 floor_y;
};

struct Rain_801977D4 {
    u8 pad00[0x1C];
    struct Drop_801977D4 drops[16];
    u32 count;
};

// inferred: TObjRain__streak_points and TObjRain__streak_colors, the points and colours of
// TObjRain__streak_line_list.
NJS_POINT3 TObjRain__streak_points[2] = {
    {0.0f, 0.0f, 0.0f},
    {0.0f, 9.0f, 0.0f},
};

__declspec(section ".data") u32 TObjRain__streak_colors[2] = {0x80808030, 0x70707020};

NJS_POINT3COL TObjRain__streak_line_list = {TObjRain__streak_points, TObjRain__streak_colors, NULL, 2};

extern "C" {
void vec3_add_to(void *, void *);
f32 xz_distance_squared(void *, void *);
void draw_line_list(void *, int, int);
void subtract_vector(void *, void *);
f32 normalize_vector(void *);
extern u8 *camera_ctrl_instance;

void TObjRain::draw_streaks() {
    struct Rain_801977D4 *self = (struct Rain_801977D4 *)this;
    struct Drop_801977D4 *drop;
    u32 i;
    set_additive_blend();
    drop = self->drops;
    for (i = 0; i < self->count; drop++, i++) {
        if (drop->active != 0) {
            set_line_width(5);
            VecCopy((Vec *)TObjRain__streak_line_list.p, (const Vec *)&drop->position);
            struct Vec_801977D4 pos = drop->position;
            if (xz_distance_squared(camera_ctrl_instance + 0x178, &pos) < 90000.0f) {
                struct Vec_801977D4 dir = drop->velocity;
                normalize_vector(&dir);
                dir.x *= 12.0f;
                dir.y *= 12.0f;
                dir.z *= 12.0f;
                subtract_vector(&pos, &drop->velocity);
                VecCopy((Vec *)(TObjRain__streak_line_list.p + 1), (const Vec *)&pos);
                draw_line_list(&TObjRain__streak_line_list, 1, 5);
            }
        }
    }
    reset_line_width();
    set_default_alpha_blend();
}

void TObjRain::update_drops() {
    s32 active = 0;
    struct Drop_80197904 *drop = ((struct Rain_80197904 *)this)->drops;
    u32 i;
    for (i = 0; i < ((struct Rain_80197904 *)this)->count; drop++, i++) {
        if (drop->active != 0) {
            vec3_add_to(&drop->position, &drop->velocity);
            if (drop->position.y < drop->floor_y) {
                drop->active = 0;
            } else {
                active++;
            }
        }
    }
    if (active == 0) {
        ((TObject *)((struct Rain_80197904 *)this))->queue_destruction();
    }
}

}
