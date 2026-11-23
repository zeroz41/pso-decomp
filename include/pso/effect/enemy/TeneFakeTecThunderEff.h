#ifndef PSO_EFFECT_ENEMY_TENEFAKETECTHUNDEREFF_H
#define PSO_EFFECT_ENEMY_TENEFAKETECTHUNDEREFF_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/NinjaTypes.h"

// The bolt's textures (set up by init_fake_tec_texlist) and the texture render draws with.
extern NJS_TEXLIST fake_tec_texlist;
extern u32 fake_tec_texture;

// A screen-space vertex of the bolt's strip.
struct TeneFakeTecThunderVertex {
    f32 x;
    f32 y;
    f32 z;
    f32 u;
    f32 v;
    u32 color;
};

// An enemy's lightning bolt (Dark Gunner, Dubchik): a jittering strip of up
// to 17 points from *from to *to, drawn additively while active.
class TeneFakeTecThunderEff : public TObject {
public:
    TeneFakeTecThunderEff(TObject *parent, Vec *from, Vec *to, s32 point_count);
    virtual ~TeneFakeTecThunderEff();
    virtual void render();
    virtual void run_task();
    void build_beam_points();
    void set_cancel_flag();
    void clear_counter();

    static const char *class_name;

    Vec origin;
    Vec delta;            // from origin to the far end
    f32 segment_length;
    s32 point_count;
    Vec base_points[17];  // evenly spaced along delta
    Vec points[17];       // base_points pushed out along jitter_dirs
    Vec jitter_dirs[17];  // unit vectors across the bolt
    f32 spacing[17];
    f32 jitter[17];       // how far each point is pushed out
    s32 timer;
    u32 color;
    s32 texture;  // index into fake_tec_texlist
    s32 pad_334;
    Vec *from;
    Vec *to;
    s32 active;  // drawn and updated only while set
    s32 target_point_count;
};
LAYOUT_ASSERT(TeneFakeTecThunderEff_size, sizeof(TeneFakeTecThunderEff) == 0x348);

#endif
