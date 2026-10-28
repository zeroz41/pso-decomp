#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/TUnk_8049EFB8.h"
#include "pso/unk/text_80107D4C.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/item/TItemEffArmor_80107DA4.h"
#include "pso/object/TObjLight_80133568.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/item/TItemEffArmor.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/TItemLoad.h"

extern "C" {
u16 obj_getField1c(void *);
s32 get_field_3e0__12TBoss3VoloptFv();
s32 TObjPlayer__sub_80117E50();
void *get_player_by_client_id(s32 i);
s32 is_item_area_enabled();

}

struct RecoveredGlobal_80107DA4_lbl_8049EFB8 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_80107DF0_lbl_8050BEC0 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_80107DF0_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
u16 obj_getField1c(void *);

void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_80107DA4_lbl_8049EFB8 __vt__13TUnk_8049EFB8;
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 draw_ginja_model_with_motion(int, int, f32);
extern RecoveredGlobal_80107DF0_lbl_8050BEC0 saved_model_draw_color;
extern RecoveredGlobal_80107DF0_lbl_8058D4C0 model_material_color;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;

typedef char RecoveredGlobal_80107DA4_lbl_8049EFB8_size[sizeof(RecoveredGlobal_80107DA4_lbl_8049EFB8) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_80107DF0_lbl_8050BEC0_size[sizeof(RecoveredGlobal_80107DF0_lbl_8050BEC0) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_80107DF0_lbl_8058D4C0_size[sizeof(RecoveredGlobal_80107DF0_lbl_8058D4C0) == 0x10 ? 1 : -1];

}

struct Vec_80108164 { f32 x, y, z; };

struct Base_80108164 { u8 pad[0x18]; };

struct Player_80108164 : Base_80108164 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void get_pos(s32 id, Vec_80108164 *out);
};

struct Quest_80108164 { u8 pad[0x10]; f32 f10; };

struct Vec_80108020 { f32 x, y, z; };

struct Parm_80108020 { u8 pad[0x1c]; f32 f1C; f32 f20; };

struct Self_80108020 {
    s32 f0;
    u8 pad4[0x14];
    void *vt;
    s32 f1C;
    u8 pad20[4];
    f32 f24;
    f32 f28;
    u8 pad2c[0x38 - 0x2c];
    u8 v38[0x58 - 0x38];
    f32 f58;
    f32 f5C;
    f32 f60;
    f32 f64;
    s32 f68;
    u8 *f6C;
    u8 f70[4];
    u8 f74[4];
    u8 f78[4];
};

extern "C" {
void play_sound_effect(u32, void *, s32, s32);
f32 xyz_distance(Vec_80108164 *, Vec_80108164 *);
void *__nw__7TObjectFUl(u32);
Quest_80108164 *get_quest_id__12TQuestListVMFv(Player_80108164 *);

void *create_particle_emitter(void *pos, s32 id);

void construct_actor_light_task(void *, void *, void *, s32, u8 *, f32, s32);
extern u8 lbl_8043E140[];
extern Vec_80108020 lbl_8043E160[];
extern void *__vt__13TItemEffArmor[];
extern Parm_80108020 default_scene_light_config;
extern s32 TItemEffArmor__class_name;
extern s32 tl_07;

Self_80108020 *TItemEffArmor__ct(Self_80108020 *self, u8 *obj, f32 a, f32 b);

}

#pragma defer_codegen on

void TObjPlayer::spawn_appearance_effect(s32 idx) {
    Player_80108164 *p = (Player_80108164 *)get_player_by_client_id((u16)idx);
    if (p != 0) {
        Quest_80108164 *q = get_quest_id__12TQuestListVMFv(p);
        if (q != 0) {
            f32 v = q->f10;
            Vec_80108164 a;
            Vec_80108164 b;
            f32 s;
            void *o;
            p->get_pos(0x28, &a);
            p->get_pos(0x1B, &b);
            s = 1.2f * (xyz_distance(&a, &b) / 2e+01f);
            o = __nw__7TObjectFUl(0x7C);
            if (o != 0) {
                TItemEffArmor__ct((Self_80108020 *)(o), (u8 *)p, s, v);
            }
            play_sound_effect(0x4000B20A, (u8 *)p + 0x38, 0, 0);
        }
    }
}

Self_80108020 *TItemEffArmor__ct(Self_80108020 *self, u8 *obj, f32 a, f32 b) {
    void *p;
    __ct__7TObjectFP7TObject(self, (void *)tl_07);
    self->vt = __vt__13TItemEffArmor;
    self->f0 = TItemEffArmor__class_name;
    self->f24 = 0.0f;
    TItemLoad::get_item_params((s32 *)self->f70, (s32 *)self->f78, (s32 *)self->f74);
    self->f28 = a;
    self->f58 = b;
    self->f6C = obj;
    self->f68 = 0;
    self->f5C = default_scene_light_config.f20;
    self->f60 = default_scene_light_config.f1C;
    self->f64 = (1.0f - self->f5C) / 14.5f;
    self->f1C = (s32)create_particle_emitter(self->f6C + 0x38, 0x1BA);
    copy_argb((NJS_ARGB *)self->v38, (NJS_ARGB *)lbl_8043E140);
    {
        Vec_80108020 v = lbl_8043E160[0];
        p = __nw__7TObjectFUl(0x64);
        if (p != NULL) {
            construct_actor_light_task(p, lbl_8043E140, &v, 0x3A, obj, 0.2f, tl_07);
        }
    }
    return self;
}

TItemEffArmor::~TItemEffArmor() {
    TBoss4Type2::request_destroy((u32)(*(void **)((s8 *)this + 0x1C)));
}

void TItemEffArmor::run_task() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r4;
    this->m_68 = (this->m_68 + 0x139D);
    temp_r4 = (u8 *)this->m_6c;
    if (temp_r4 != NULL) {
        VecCopy((Vec *)(arg0 + 0x2C), (const Vec *)(temp_r4 + 0x38));
    }
    *(f32 *)((s8 *)arg0 + 0x30) = (f32) (*(f32 *)((s8 *)arg0 + 0x30) + ((this->m_24 * this->m_58) / 29.0f));
    temp_r3 = (u8 *)this->m_1c;
    if (temp_r3 != NULL) {
        ((TNowLoading *)temp_r3)->copy_pos((u8 *)&this->m_2c);
    }
    *(f32 *)&this->m_38 = (f32) (1.0f - (this->m_24 / 29.0f));
    temp_r3_2 = (u8 *)this->m_6c;
    if (temp_r3_2 != NULL) {
        publish_actor_light_scalars((obj_getField1c(temp_r3_2)), this->m_60, (f32) (*(f32 *)&this->unk_5C));
    }
    if (*(f32 *)&this->unk_5C >= 1.0f) {
        *(f32 *)&this->unk_64 = (f32) ((-1.0f) * *(f32 *)&this->unk_64);
    }
    *(f32 *)&this->unk_5C = (f32) (*(f32 *)&this->unk_5C + *(f32 *)&this->unk_64);
    if (29.0f == this->m_24) {
        queue_destruction__7TObjectFv(arg0);
    }
    this->m_24 += 1.0f;
}

void TItemEffArmor::render() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    push_matrix();
    post_translate_matrix((u8 *)&this->m_2c);
    rotate_matrix_y(0, this->m_68);
    temp_f1 = *(f32 *)&this->unk_28;
    scale_matrix(0, temp_f1, 1.0f, temp_f1);
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    copy_argb((NJS_ARGB *)&saved_model_draw_color.value, (NJS_ARGB *)&model_material_color.value);
    set_constant_material((const NJS_ARGB *)((arg0 + 0x38)));
    TObjPlayer::notify_fish_if_valid(this->m_78);
    draw_ginja_model_with_motion(this->m_70, this->m_74, this->m_24);
    copy_argb((NJS_ARGB *)&model_material_color.value, (NJS_ARGB *)&saved_model_draw_color.value);
    model_render_flags = saved_model_render_flags;
    pop_matrix();
}

u8 *fn_80107DA4(u8 *arg0, u8 *arg1, s16 arg2) {
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TUnk_8049EFB8.value;
    *(s32 *)((s8 *)arg0 + 0x1C) = 0;
    *(s16 *)&((TUnk_8049EFB8 *)arg0)->m_20 = arg2;
    return arg0;
}

TUnk_8049EFB8::~TUnk_8049EFB8() {

}

void TUnk_8049EFB8::run_task() {
    s32 player;
    if (120.0f <= (f32) *(s32 *)&this->unk_1C) {
        player = (s32)get_player_by_client_id((this->m_20));
        if (player != 0) {
            get_field_3e0__12TBoss3VoloptFv();
            if (is_item_area_enabled() == 1) {
                obj_getField1c((void *)player);
                if (TObjPlayer__sub_80117E50() != 0) {
                    spawn_particle_effect((void *)(player + 0x2FC), 0x1BE);
                }
            }
        }
        *(s32 *)&this->unk_1C = 0;
    }
    *(s32 *)&this->unk_1C = (s32) (*(s32 *)&this->unk_1C + 1);
}

#pragma defer_codegen off
