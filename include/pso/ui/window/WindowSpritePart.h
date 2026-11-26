#ifndef PSO_UI_WINDOW_WINDOWSPRITEPART_H
#define PSO_UI_WINDOW_WINDOWSPRITEPART_H

#include "types.h"

struct NJS_TEXLIST;

#include "pso/unk/TWindowLayoutEntry.h"
#include <stddef.h>

struct SpritePartLayoutRecord;
struct DirectSpritePartLayoutRecord;

class WindowSpritePart : public TWindowLayoutEntry {
public:
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 depth;
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    s32 color;
    NJS_TEXLIST **texture_list_slot;
    s32 kind;

    WindowSpritePart(SpritePartLayoutRecord *source, s32 client);
    WindowSpritePart(DirectSpritePartLayoutRecord *source, s32 client);
    virtual ~WindowSpritePart();
    virtual void update();
    virtual void render(WindowDrawContext *context);

    void swap_sprite_v_edges();
    void swap_sprite_u_edges();
    void set_sprite_uv_bounds(f32 u0, f32 v0, f32 u1, f32 v1);
    void set_sprite_uv_from_pixels(f32 x, f32 y);
    void set_sprite_dimensions(f32 width, f32 height);
};

LAYOUT_ASSERT(WindowSpritePartSize, sizeof(WindowSpritePart) == 0x38);
LAYOUT_ASSERT(WindowSpritePartUvOffset, offsetof(WindowSpritePart, u0) == 0x1C);
LAYOUT_ASSERT(WindowSpritePartKindOffset, offsetof(WindowSpritePart, kind) == 0x34);

extern "C" {
// The two WindowSpritePart constructors. init_window_layout_entries cannot use new: calc_bar_width
// stays pure (slot 0 of the vtable), so the class is abstract.
void *__ct__16WindowSpritePartFP22SpritePartLayoutRecordl(void *p, SpritePartLayoutRecord *source, s32 client);
void *__ct__16WindowSpritePartFP28DirectSpritePartLayoutRecordl(void *p, DirectSpritePartLayoutRecord *source, s32 client);
}

#endif
