#include "pso/TObject.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/misc/TEneEffHamon.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/vector.h"
#include "pso/misc/TeneFakeTecThunderEff.h"
class TEneEffHamon : public TObject {
public:
    virtual ~TEneEffHamon();
    virtual void run_task();
    virtual void render();
};

#include "types.h"
#include "pso/misc/TWindowDD.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_800A38A4___vt__12TEneEffHamon {
    s32 value;
    u8 remaining[0x14];
};

typedef struct Hamon_800A36A8 {
    u8 pad0[0x1C];
    u8 mtx1C[0x34 - 0x1C];
    f32 scale;
    u8 pad38[0x40 - 0x38];
    f32 f40;
    u8 pad44[0x4C - 0x44];
    s32 delay;
    u8 color50[0x10];
} Hamon_800A36A8;

typedef struct Cam_800A3D1C { u8 pad0[8]; f32 cx; f32 cy; u8 pad10[8]; f32 sw; f32 aspect; } Cam_800A3D1C;

extern "C" {
s32 queue_destruction__7TObjectFv();
extern const f32 lbl_805D99E0;
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_800A38A4___vt__12TEneEffHamon __vt__12TEneEffHamon;
extern s32 TEneEffHamon__name;
extern const f32 lbl_805D99E4;
extern const f32 lbl_805D99E8;
extern const f32 lbl_805D99EC;
extern s32 tl_06;
s32 scale_matrix(int, f32, f32, f32);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern u8 saved_model_draw_color[];
extern u8 model_material_color[];
extern int TEneEffHamon__fish_model;
extern int TEneEffHamon__fish_effect_param;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void render__12TEneEffHamonFv(Hamon_800A36A8 *o);
int TObjFish__sub_8001EDB0(void*, void*);
int get_bml_model(void*, void*);

void render__12TEneEffHamonFv(Hamon_800A36A8 *o) {
    f32 s;
    if (o->delay > 0) {
        return;
    }
    saved_model_render_flags = model_render_flags;
    ((TRaderMapCore *)saved_model_draw_color)->copy_vec4(model_material_color);
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= 0x810;
    set_chunk_material_override_pair(0xFFFF00FF, 0x800);
    TObjFish::set_global_param(TEneEffHamon__fish_effect_param);
    set_constant_material((const NJS_ARGB *)(((f32 *)o->color50)));
    push_matrix();
    post_translate_matrix(o->mtx1C);
    s = o->f40 * o->scale;
    scale_matrix(0, s, s, s);
    draw_chunk_object((void *)TEneEffHamon__fish_model);
    pop_matrix();
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    ((TRaderMapCore *)model_material_color)->copy_vec4(saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
}

void run_task__12TEneEffHamonFv(u8 *arg0) {
    s32 temp_r4;
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x4C);
    if (temp_r4 > 0) {
        *(s32 *)((s8 *)arg0 + 0x4C) = (temp_r4 - 1);
        return;
    }
    *(f32 *)((s8 *)arg0 + 0x34) = (f32) (*(f32 *)((s8 *)arg0 + 0x34) + *(f32 *)((s8 *)arg0 + 0x44));
    *(f32 *)((s8 *)arg0 + 0x50) = (f32) (*(f32 *)((s8 *)arg0 + 0x50) + *(f32 *)((s8 *)arg0 + 0x48));
    if (*(f32 *)((s8 *)arg0 + 0x50) <= lbl_805D99E0) {
        queue_destruction__7TObjectFv();
    }
}

void TEneEffHamon__sub_800A380C(void) {  }

    extern int player_effect_bml_resource;
void init_fish_effects__12TEneEffHamonFv(void) { TEneEffHamon__fish_model = get_bml_model((void*)player_effect_bml_resource, (void*)3); TEneEffHamon__fish_effect_param = TObjFish__sub_8001EDB0((void*)player_effect_bml_resource, (void*)3); }

}

TEneEffHamon::~TEneEffHamon() {}

typedef char RecoveredGlobal_800A38A4___vt__12TEneEffHamon_size[sizeof(RecoveredGlobal_800A38A4___vt__12TEneEffHamon) == 0x18 ? 1 : -1];
u8 *__ct__12TEneEffHamonFv(u8 *object, s32 arg1, s32 arg2, s32 arg3, f32 farg0) {
    __ct__7TObjectFP7TObject((void *)object, (void *)tl_06);
    *(s32 **)((s8 *)object + 0x18) = &__vt__12TEneEffHamon.value;
    *(s32 *)((s8 *)object + 0) = (s32) TEneEffHamon__name;
    *(s32 *)((s8 *)object + 0x30) = 0;
    *(s32 *)((s8 *)object + 0x2C) = 0;
    *(s32 *)((s8 *)object + 0x28) = 0;
    *(f32 *)((s8 *)object + 0x34) = (f32) lbl_805D99E4;
    VecCopy((Vec *)(object + 0x1C), (const Vec *)(arg1));
    *(f32 *)((s8 *)object + 0x40) = farg0;
    *(f32 *)((s8 *)object + 0x50) = (f32) lbl_805D99E8;
    *(f32 *)((s8 *)object + 0x54) = (f32) lbl_805D99E4;
    *(f32 *)((s8 *)object + 0x58) = (f32) lbl_805D99E4;
    *(f32 *)((s8 *)object + 0x5C) = (f32) lbl_805D99E4;
    *(s32 *)((s8 *)object + 0x4C) = arg3;
    if (arg2 <= 0) {
        arg2 = 1;
    }
    *(f32 *)((s8 *)object + 0x44) = (f32) (lbl_805D99E4 / (f32) arg2);
    *(f32 *)((s8 *)object + 0x48) = (f32) (lbl_805D99EC / (f32) arg2);
    return object;
}
