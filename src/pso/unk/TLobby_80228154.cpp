#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/item/TUnk_804CC048.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby_80207644.h"
#include <stddef.h>
#include "pso/system/scene/TScene.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/model_render_state.h"


struct RecoveredGlobal_80228634_lbl_804CBE98 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_80228754_lbl_804CBE98 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_802286C4_lbl_804CBE98 {
    s32 value;
    u8 remaining[0x1AC];
};


extern "C" {
s32 select_area_entrance(void *arg0);
s32 lookup_scene_object__6TLobbyFPv(s32, void *);
extern RecoveredGlobal_80228634_lbl_804CBE98 area_initializer_dispatch_table;
void run_area_scene_cleanup(u8 *arg0);
void promote_area_floor(u8 *arg0);
void load_area_scene_and_init(u8 *arg0);
s32 get_floor_map_terrain(s32);


// One frame of a sprite sheet: its size, the offset of its origin, its
// texture coordinates in 1/256 units and its texture.
struct SpriteFrame_80228154 {
    s16 width;
    s16 height;
    s16 origin_x;
    s16 origin_y;
    s16 u0;
    s16 v0;
    s16 u1;
    s16 v1;
    s16 texture;
    u8 pad_12[0x14 - 0x12];
};

struct Sprite_80228154 {
    f32 x;
    f32 y;
    u8 pad_8[0xC - 0x8];
    f32 scale_x;
    f32 scale_y;
    s32 angle;
    u32 texture_list;
    SpriteFrame_80228154 *frames;
};

// The screen quad draw_textured_quad_at_depth reads.
struct ScreenQuad_80228154 {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

union SpriteColor_80228154 {
    struct { u8 a, r, g, b; } channels;
    u32 packed;
};

// Draws one frame of a sprite on the screen; flags 1 rotates the quad by the
// sprite's angle, 2 tints it with the model material colour, 0x20 blends.
void TLobby__sub_80228154(Sprite_80228154 *sprite, s32 frame_index, s32 flags, f32 depth) {
    ScreenQuad_80228154 quad;
    union SpriteColor_80228154 color;
    if (sprite == NULL) {
        return;
    }
    if (sprite->texture_list == 0) {
        return;
    }
    TObjFish::set_global_param(sprite->texture_list);
    SpriteFrame_80228154 *frame = &sprite->frames[frame_index];
    f32 left = -frame->origin_x;
    f32 top = -frame->origin_y;
    f32 right = left + frame->width;
    f32 bottom = top + frame->height;
    left *= sprite->scale_x;
    right *= sprite->scale_x;
    top *= sprite->scale_y;
    bottom *= sprite->scale_y;
    quad.x0 = sprite->x + left;
    quad.y0 = sprite->y + top;
    quad.x1 = sprite->x + right;
    quad.y1 = sprite->y + bottom;
    quad.u0 = frame->u0 / 256.0f;
    if (1.0f < quad.u0) {
        quad.u0 = 1.0f;
    }
    quad.v0 = frame->v0 / 256.0f;
    if (1.0f < quad.v0) {
        quad.v0 = 1.0f;
    }
    quad.u1 = frame->u1 / 256.0f;
    if (1.0f < quad.u1) {
        quad.u1 = 1.0f;
    }
    quad.v1 = frame->v1 / 256.0f;
    if (1.0f < quad.v1) {
        quad.v1 = 1.0f;
    }
    color.packed = 0xFFFFFFFF;
    if (flags & 1) {
        Vec offset;
        f32 cx = (quad.x1 + quad.x0) / 2.0f;
        f32 cy = (quad.y1 + quad.y0) / 2.0f;
        offset.x = quad.x0 - cx;
        offset.y = quad.y0 - cy;
        offset.z = 0.0f;
        push_matrix_from(identity_matrix);
        rotate_matrix_z(NULL, sprite->angle);
        rotate_vector_by_matrix(0, &offset, &offset);
        pop_matrix();
        quad.x0 = cx + offset.x;
        quad.y0 = cy + offset.y;
        quad.x1 = cx - offset.x;
        quad.y1 = cy - offset.y;
    }
    if (flags & 2) {
        color.channels.b = 255.0f * model_material_color.b;
        color.channels.g = 255.0f * model_material_color.g;
        color.channels.r = 255.0f * model_material_color.r;
        color.channels.a = 255.0f * model_material_color.a;
    }
    if (flags & 4) {
        quad.u1 = quad.u0;
        quad.u0 = quad.u1;
    }
    if (flags & 8) {
        quad.v1 = quad.v0;
        quad.u0 = quad.v1;
    }
    depth = -1.0f / depth;
    begin_screen_draw((flags & 0x20) == 0x20);
    set_draw_texture_and_color(frame->texture, color.packed);
    draw_textured_quad_at_depth(&quad.x0, depth);
    TWindowSubStatusDisp::get_player();
}

void TLobby::clear_ready_flag_unless_locked() {
    if (get_current_floor_area() != AREA_LOBBY) {
        *(s32 *)((s8 *)this + 0x20) = (s32) (*(s32 *)((s8 *)this + 0x20) & 0xFFFFFFFE);
    }
}

void TLobby::set_area(s32 arg1) {
    *(s32 *)&this->m_next = arg1;
    *(s32 *)((s8 *)this + 0x18) = get_floor_map_terrain(*(s32 *)&this->m_next);
}

#pragma push
#pragma fp_contract on
s32 select_area_entrance(void *arg0) {
    s32 temp_r0;
    s32 temp_r3;
    if ((s32) *(s32 *)((s8 *)arg0 + 0) > 0x11) {
        return 4;
    }
    if (*(s32 *)((s8 *)arg0 + 0x20) & 1) {
        return 2;
    }
    if ((TLobby::get_instance() == 0) && (get_floor_area(*(s32 *)((s8 *)arg0 + 0)) == 0xD)) {
        switch (get_floor_area(*(s32 *)((s8 *)arg0 + 4))) {
        case 8:
        case 9:
        case 10:
            return 1;
        default:
            return 0;
        }
    }
    temp_r0 = *(s32 *)((s8 *)arg0 + 4) - *(s32 *)((s8 *)arg0 + 0);
    if (temp_r0 >= 0) {
        return 1;
    }
    return (temp_r0 < 0) ? 0 : 4;
}
#pragma pop

typedef char RecoveredGlobal_80228634_lbl_804CBE98_size[sizeof(RecoveredGlobal_80228634_lbl_804CBE98) == 0x1B0 ? 1 : -1];
void run_area_scene_cleanup(u8 *arg0) {
    s32 sp8;
    s32 (*var_r12)(s32);
    s32 *var_r4;
    s32 var_r3;
    u8 *var_r31;
    var_r4 = &sp8;
    var_r31 = arg0;
    var_r3 = *(s32 *)((s8 *)arg0 + 4);
    if (lookup_scene_object__6TLobbyFPv(var_r3, var_r4) != 0) {
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 += sp8 * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    } else {
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 = (s32) &area_initializer_dispatch_table.value;
        var_r3 += *(s32 *)((s8 *)var_r31 + 4) * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    }
    *(s32 *)((s8 *)var_r31 + 4) = 0;
    *(s32 *)((s8 *)var_r31 + 8) = 0;
    *(s32 *)((s8 *)var_r31 + 0xC) = 0;
}

typedef char RecoveredGlobal_80228754_lbl_804CBE98_size[sizeof(RecoveredGlobal_80228754_lbl_804CBE98) == 0x1B0 ? 1 : -1];

typedef char RecoveredGlobal_802286C4_lbl_804CBE98_size[sizeof(RecoveredGlobal_802286C4_lbl_804CBE98) == 0x1B0 ? 1 : -1];
void load_area_scene_and_init(u8 *arg0) {
    s32 sp8;
    s32 (*var_r12)(s32);
    s32 *var_r4;
    s32 var_r3;
    u8 *var_r31;
    var_r31 = arg0;
    var_r3 = *(s32 *)((s8 *)arg0 + 4);
    set_current_floor_area((var_r3));
    var_r3 = *(s32 *)((s8 *)var_r31 + 0x10);
    TScene::set_scene(var_r3);
    var_r3 = *(s32 *)((s8 *)var_r31 + 4);
    var_r4 = &sp8;
    if (lookup_scene_object__6TLobbyFPv(var_r3, var_r4) != 0) {
        var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 += sp8 * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 4);
        var_r12(var_r3);
        return;
    }
    var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
    var_r3 = (s32) &(*(RecoveredGlobal_802286C4_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
    var_r3 += *(s32 *)((s8 *)var_r31 + 4) * 0xC;
    var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 4);
    var_r12(var_r3);
}

void promote_area_floor(u8 *arg0) {
    s32 sp8;
    s32 (*var_r12)(s32);
    s32 *var_r4;
    s32 var_r3;
    u8 *var_r31;
    var_r4 = &sp8;
    var_r31 = arg0;
    var_r3 = *(s32 *)((s8 *)arg0 + 4);
    if (lookup_scene_object__6TLobbyFPv(var_r3, var_r4) != 0) {
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 += sp8 * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    } else {
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 = (s32) &(*(RecoveredGlobal_80228754_lbl_804CBE98 *)&area_initializer_dispatch_table).value;
        var_r3 += *(s32 *)((s8 *)var_r31 + 4) * 0xC;
        var_r12 = *(s32 (**)(s32))((s8 *)var_r3 + 8);
        var_r12(var_r3);
    }
    *(s32 *)((s8 *)var_r31 + 0) = (s32) *(s32 *)((s8 *)var_r31 + 4);
    *(s32 *)((s8 *)var_r31 + 4) = (s32) *(s32 *)((s8 *)var_r31 + 0xC);
    *(s32 *)((s8 *)var_r31 + 0x10) = (s32) *(s32 *)((s8 *)var_r31 + 0x18);
    TLobby::reset_story_select_state();
}
}

Obj_80515BA0 lbl_80515BA0;
