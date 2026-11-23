#ifndef PSO_ITEM_TUNK_804F0BF0_H
#define PSO_ITEM_TUNK_804F0BF0_H

#include <stddef.h>
#include <dolphin/mtx.h>
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"

struct GinjaTextureList;
struct S_8035016C;
struct TItemEffPG;
class TParticleCtrl;

class TUnk_804F0BF0 : public TObject {
public:
    TUnk_804F0BF0(TItemEffPG *parent, S_8035016C *params);
    virtual ~TUnk_804F0BF0();
    virtual void render();
    virtual void run_task();
    void begin_fade();

    s32 item_id;
    NJS_OBJECT *model;  // drawn turning by rotation_y, its child by child_rotation_y
    GinjaTextureList *texture_list;
    NJS_ARGB color;
    TParticleCtrl *particle;
    s32 rotation_y;
    s32 child_rotation_y;
    f32 max_scale;
    Vec scale;
    f32 scale_step;
    s32 fading;  // set by begin_fade: color.a falls until the effect ends
    Vec position;
};

LAYOUT_ASSERT(TUnk_804F0BF0_size, sizeof(TUnk_804F0BF0) == 0x68);
LAYOUT_ASSERT(TUnk_804F0BF0_color_offset, offsetof(TUnk_804F0BF0, color) == 0x28);
LAYOUT_ASSERT(TUnk_804F0BF0_scale_offset, offsetof(TUnk_804F0BF0, scale) == 0x48);
LAYOUT_ASSERT(TUnk_804F0BF0_position_offset, offsetof(TUnk_804F0BF0, position) == 0x5C);

#endif
