#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/object/TObjFish_800E2FFC.h"
#include "pso/boss/Boss6Type1Appearance.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/TBoss6Demo10_TYPE1_APPEAR.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"

struct Ent_8033CB4C
{
  s32 a;
  s32 b;
  s32 c;
};

struct Fish_8033CB4C
{
  s32 x0;
  u8 pad4[0x18 - 4];
  const s32 *vt;
  Ent_8033CB4C tbl[2];
  f32 x34;
  s32 x38;
  s32 x3C;
  u8 x40[0x54 - 0x40];
  u8 x54[0x60 - 0x54];
  s32 x60;
  s32 x64;
};

extern "C" {
void *create_particle_emitter(void *pos, s32 id);
s32 play_sound_effect(int, int, int, int);
extern const f32 lbl_805DFA48;
extern const f32 lbl_805DFA4C;
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
int set_scripted_camera_pose(void *, void *, void *);
int build_tables__14TBoss6PlotFalzFPvPvi(void *, void *, int);
extern s32 lbl_80477DEC[];
extern s32 boss6_type1_appear_node_desc[];
extern s32 boss6_type1_appear_model_node_descriptors[];
extern s32 lbl_80477E30[];
extern s32 lbl_80477E3C[];
extern s32 lbl_804DF614[];
extern s32 boss6_type1_appear_motion_indices[];
extern const s32 __vt__25TBoss6Demo10_TYPE1_APPEAR[];
struct AppearanceClassTag { const char *value; u32 padding; };
__declspec(section ".sdata") extern AppearanceClassTag TBoss6Demo10_TYPE1_APPEAR__name;
struct AppearanceZero { f32 value; u32 padding; };
__declspec(section ".sdata2") extern const AppearanceZero lbl_805DFA50;
Fish_8033CB4C *__ct__25TBoss6Demo10_TYPE1_APPEARFP7TObject(Fish_8033CB4C *self, void *parent);
s32 refresh_players_equipment__14TBoss6PlotFalzFPv();
s32 post_translate_matrix(s32 *);
s32 push_matrix();
void *__nw__7TObjectFUl(int);
s32 clear_render_callback__8TObjFishFv(s32);

void TBoss6Demo10_TYPE1_APPEAR::sub_8033C7C8() {
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(lbl_80477DEC);
    TObjFish::set_global_param(this->m_20);
    draw_model_motion((void *)(*(s32 *)((s8 *)this + 0x1C)), (void *)(*(s32 *)((s8 *)this + 0x24)), *(f32 *)((s8 *)this + 0x34));
    TObjFish::set_global_param(*(s32 *)((s8 *)this + 0x2C));
    ((TObjFish *)(this->m_60))->set_draw_callback_list();
    draw_model_motion((void *)this->m_28, (void *)this->m_30, *(f32 *)((s8 *)this + 0x34));
    clear_render_callback__8TObjFishFv(this->m_60);
    clear_motion_packed_rotation();
    pop_matrix();
}

void render__25TBoss6Demo10_TYPE1_APPEARFv(void* p) { ((TBoss6Demo10_TYPE1_APPEAR *)p)->sub_8033C7C8(); }

#pragma push
#pragma opt_common_subs off
void run_task__25TBoss6Demo10_TYPE1_APPEARFv(TBoss6Demo10_TYPE1_APPEAR *boss6_demo10_type1_appear) {
    f32 temp_f1;
    s32 temp_r0_3;
    u8 *temp_r30;
    temp_f1 = *(f32 *)((s8 *)boss6_demo10_type1_appear + 0x34) + lbl_805DFA48;
    *(f32 *)((s8 *)boss6_demo10_type1_appear + 0x34) = temp_f1;
    if (temp_f1 > lbl_805DFA4C) {
        *(f32 *)((s8 *)boss6_demo10_type1_appear + 0x34) = (f32) lbl_805DFA4C;
    }
    ((TBoss6PlotFalz *)((u8 *)boss6_demo10_type1_appear + 0x40))->scroll_strips_uv(8, 0);
    if ((s32) boss6_demo10_type1_appear->m_38 == 0x78) {
        play_sound_effect(0x4003A105, 0, 0, 0);
    }
    switch (boss6_demo10_type1_appear->m_38) {
    case 0x1B8:
    case 0xFA:
        play_sound_effect(0x4003A811, 0, 0, 0);
        break;
    case 0x154:
        play_sound_effect(0x40031222, 0, 0, 0);
        break;
    }
    switch (boss6_demo10_type1_appear->m_38) {
    case 0x14:
    case 0xC6:
    case 0xFA:
    case 0x13F:
    case 0x1B8:
        start_pad_rumble_all(0xC0, 0xF);
        break;
    }
    temp_r0_3 = boss6_demo10_type1_appear->m_38;
    temp_r30 = (u8 *)boss6_demo10_type1_appear + 0x54;
    switch (temp_r0_3) {
    case 0x1:
        *(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64) = (u32)create_particle_emitter((temp_r30), 0x210);
        if ((u32) *(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64) != 0U) {
            ((TParticleCtrl *)(*(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64)))->set_flags(0x40);
        }
        break;
    case 0x1AC:
    case 0x8E:
        if ((u32) *(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64) != 0U) {
            TParticleCtrl::release(*(void **)((s8 *)boss6_demo10_type1_appear + 0x64));
            *(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64) = 0U;
        }
        *(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64) = (u32)create_particle_emitter((temp_r30), 0x211);
        if ((u32) *(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64) != 0U) {
            ((TParticleCtrl *)(*(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64)))->set_flags(0x40);
        }
        break;
    case 0x11D:
        if ((u32) *(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64) != 0U) {
            TParticleCtrl::release(*(void **)((s8 *)boss6_demo10_type1_appear + 0x64));
            *(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64) = 0U;
        }
        *(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64) = (u32)create_particle_emitter((temp_r30), 0x210);
        if ((u32) *(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64) != 0U) {
            ((TParticleCtrl *)(*(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64)))->set_flags(0x40);
        }
        break;
    }
    if ((u32) *(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64) != 0U) {
        ((TParticleCtrl *)*(u32 *)((s8 *)boss6_demo10_type1_appear + 0x64))->set_position((void*)temp_r30);
    }
    boss6_demo10_type1_appear->m_38 = (boss6_demo10_type1_appear->m_38 + 1);
    if (((s32) boss6_demo10_type1_appear->m_38 >= 0x1F4) || (((TObjFish *)(*(s32 *)((s8 *)boss6_demo10_type1_appear + 0x3C)))->get_phase() != 1)) {
        queue_destruction__7TObjectFv((boss6_demo10_type1_appear));
    }
}
#pragma pop

}
TBoss6Demo10_TYPE1_APPEAR::~TBoss6Demo10_TYPE1_APPEAR() {
    restore_player_cameras();
    refresh_players_equipment__14TBoss6PlotFalzFPv();
    ((TBoss6PlotFalz *)(((u8 *)this) + 0x40))->free_buffer_pairs();
    if ((u32) this->m_60 != 0U) {
        TObjFish::init_state_1(*(void **)((s8 *)this + 0x60));
        this->m_60 = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x64) != 0U) {
        TParticleCtrl::release(*(void **)((s8 *)this + 0x64));
        *(u32 *)((s8 *)this + 0x64) = 0U;
    }
}

#pragma push
#pragma opt_common_subs off
typedef struct Ent_8033CB4C Ent_8033CB4C;
typedef struct Fish_8033CB4C Fish_8033CB4C;
TBoss6Demo10_TYPE1_APPEAR::TBoss6Demo10_TYPE1_APPEAR(TObject *parent) : TObject(parent) {
    s32 k;
    s32 n;
    s32 i;
    ((Fish_8033CB4C *)this)->x0 = (s32)TBoss6Demo10_TYPE1_APPEAR__name.value;
    ((Fish_8033CB4C *)this)->x3C = (s32) parent;
    n = TObjFish::get_fish_count();
    for (i = 0; i < 2; i++)
    {
      k = lbl_804DF614[i];
      k = k & 0xFFFFFFFFu;
      ((Fish_8033CB4C *)this)->tbl[i].a = get_bml_model(n, k);
      ((Fish_8033CB4C *)this)->tbl[i].b = TObjFish__sub_8001EDB0(n, k);
      ((Fish_8033CB4C *)this)->tbl[i].c = get_bml_motion(n, boss6_type1_appear_motion_indices[i]);
    }
    ((Fish_8033CB4C *)this)->x60 = TObjFish__sub_800E3124((u8 *)boss6_type1_appear_node_desc, (s32)(((Fish_8033CB4C *)this)->x54));
    ((Fish_8033CB4C *)this)->x64 = 0;
    build_tables__14TBoss6PlotFalzFPvPvi(((Fish_8033CB4C *)this)->x40, boss6_type1_appear_model_node_descriptors, 2);
    activate_camera_mode(5);
    set_scripted_camera_pose(lbl_80477DEC, lbl_80477DEC, lbl_80477E30);
    ((TCameraCtrl *)lbl_80477E3C)->cache_target_and_forward(0x416C);
    ((Fish_8033CB4C *)this)->x34 = lbl_805DFA50.value;
    ((Fish_8033CB4C *)this)->x38 = 0;
}

#pragma pop

void *TBoss6Demo10_TYPE1_APPEAR__create(void *parent) {
    void *o = __nw__7TObjectFUl(0x68);
    if (o != NULL) {
        o = __ct__25TBoss6Demo10_TYPE1_APPEARFP7TObject((Fish_8033CB4C *)(o), parent);
    }
    return o;
}

extern const char TBoss6Demo10_TYPE1_APPEAR__class_name[];
__declspec(section ".rodata") const char TBoss6Demo10_TYPE1_APPEAR__class_name[] ATTRIBUTE_ALIGN(4) = "TBoss6Demo10_TYPE1_APPEAR";
__declspec(section ".rodata") s32 lbl_80477DEC[] = {0x00000000, 0x41C80000, 0x42960000};
__declspec(section ".rodata") s32 boss6_type1_appear_node_desc[] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000};
__declspec(section ".rodata") s32 boss6_type1_appear_model_node_descriptors[] = {0x00000003, 0x00000001, 0x00000000, 0x00000006, 0x00000001, 0x00000000};
__declspec(section ".rodata") s32 lbl_80477E30[] = {0x00000000, 0x00000000, 0x00000000};
__declspec(section ".rodata") s32 lbl_80477E3C[] = {0x01020000, 0x00000000, 0x3F333333};
s32 boss6_type1_appear_motion_indices[] = {35, 36};
extern __declspec(section ".data") const s32 __vt__25TBoss6Demo10_TYPE1_APPEAR[];
__declspec(section ".sdata") AppearanceClassTag TBoss6Demo10_TYPE1_APPEAR__name = {TBoss6Demo10_TYPE1_APPEAR__class_name, 0};
__declspec(section ".sdata2") const f32 lbl_805DFA48 = 0.7f;
__declspec(section ".sdata2") const f32 lbl_805DFA4C = 349.0f;
__declspec(section ".sdata2") const AppearanceZero lbl_805DFA50 = {0.0f, 0};
