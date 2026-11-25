#ifndef PSO_BOSS_DARKFALZ_TBOSS4FADE_H
#define PSO_BOSS_DARKFALZ_TBOSS4FADE_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

class TBoss4Fade : public TObject {
public:
    TBoss4Fade(TObject *parent);
    virtual ~TBoss4Fade();
    virtual void run_task();
    virtual void render();
    // Fades the screen to color at alpha (0..1) this frame.
    void set_fade(s32 color, f32 alpha);

    struct FadeFrame {
        s32 active;
        u32 color;
        f32 alpha;
    };

    s32 write_index;
    FadeFrame frames[2];
    static f32 fullscreen_vertices[4][2];
    static const char *name;
};

LAYOUT_ASSERT(TBoss4Fade_size, sizeof(TBoss4Fade) == 0x38);
LAYOUT_ASSERT(TBoss4Fade_write_index_offset, offsetof(TBoss4Fade, write_index) == 0x1C);
LAYOUT_ASSERT(TBoss4Fade_frames_offset, offsetof(TBoss4Fade, frames) == 0x20);

struct TBoss4DarkFalz;

TBoss4Fade *create_boss4_fade();

typedef struct Quad_803594EC
{
  void *tex;
  u32 *colors;
  s32 a;
  s32 b;
  u32 col[4];
} Quad_803594EC;

#endif
