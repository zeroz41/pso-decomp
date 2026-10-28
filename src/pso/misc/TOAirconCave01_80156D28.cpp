#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/system/memory.h"
#include "pso/misc/TUnk_804AF8D8.h"
#include "pso/misc/TOAirconCave01.h"

struct RecoveredGlobal_80156D70_lbl_8050BEC0 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_80156D70_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
extern unsigned char saved_model_draw_color[];
extern unsigned char model_material_color[];
extern int saved_model_render_flags;
extern int saved_chunk_polygon_flags_and_mask;
extern int saved_chunk_polygon_flags_or_mask;
extern int chunk_polygon_flags_or_mask;
extern int chunk_polygon_flags_and_mask;
extern int model_render_flags;
void TObjPlayer__sub_800D9718(void *);

void TUnk_804AF8D8::clear_flag_and_notify() { ((TRaderMapCore *)model_material_color)->copy_vec4(saved_model_draw_color); chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask; chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask; model_render_flags = saved_model_render_flags; }

extern s32 lbl_804AF8D8[];

typedef char RecoveredGlobal_80156D70_lbl_8050BEC0_size[sizeof(RecoveredGlobal_80156D70_lbl_8050BEC0) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_80156D70_lbl_8058D4C0_size[sizeof(RecoveredGlobal_80156D70_lbl_8058D4C0) == 0x10 ? 1 : -1];
void TUnk_804AF8D8::set_flags_and_apply_damage_color() {
    u8 *arg0 = (u8 *)this;
    (*(s32 *)&saved_model_render_flags) = (*(s32 *)&model_render_flags);
    (*(s32 *)&saved_chunk_polygon_flags_and_mask) = (*(s32 *)&chunk_polygon_flags_and_mask);
    (*(s32 *)&saved_chunk_polygon_flags_or_mask) = (*(s32 *)&chunk_polygon_flags_or_mask);
    ((TRaderMapCore *)(&(*(RecoveredGlobal_80156D70_lbl_8050BEC0 *)&saved_model_draw_color).value))->copy_vec4((&(*(RecoveredGlobal_80156D70_lbl_8058D4C0 *)&model_material_color).value));
    (*(s32 *)&model_render_flags) |= 0x8021;
    ((TUnk_80494AE0 *)arg0)->set_chunk_material_color();
    set_color_blend_mode(1, 4, 5, 0);
}

void *TUnk_804AF8D8::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 * *)&(*(TObject * *)((u8 *)this + 0x14)) = lbl_804AF8D8;
        __dt__13TUnk_80494AE0Fv(this, 0);
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

void *TUnk_804AF8D8::init_vtable_804AF8D8() {
    TObjPlayer__sub_800D9718(this);
    *(s32 * *)&(*(TObject * *)((u8 *)this + 0x14)) = lbl_804AF8D8;
    sub_80156CEC();
    return this;
}

}
