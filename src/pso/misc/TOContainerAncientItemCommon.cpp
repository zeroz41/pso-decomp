#include "types.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/object/TObjChip.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_8015C534.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/player/TUnk_804B08BC.h"
#include "pso/misc/TOContainerAncientItemCommon.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/item/TObjContainerItem.h"

struct Desc_8015C234 {
    u8 pad0[0xC];
    f32 x;
    f32 y;
    f32 z;
    u8 pad18[0x38 - 0x18];
    f32 y2;
    u8 pad3C[0x40 - 0x3C];
    s32 a;
    s32 b;
    u8 pad48[0x4C - 0x48];
};
struct Obj_8015C234 {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0x326 - 0x44];
    s16 f326;
};
struct Ids_8015C234 { s32 f0; s32 a; s32 b; };

struct Obj_8015C48C { u8 pad[0x326]; s16 a326; u8 pad2[0x364 - 0x328]; s32 a364; };

extern "C" {
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
int is_quest_active(void);
s32 __nw__7TObjectFUl(int);
extern s32 enable_v2_features;
void submit_cursor_candidate(Obj_8015C48C *self, s32 x);
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
}
void play_container_break_sound(s32 arg0);
extern Desc_8015C234 fish_break_debris_desc;
extern Desc_8015C234 lbl_8044074C;
extern s32 lbl_805D2F00;
extern Ids_8015C234 *ancient_container_fragment_texture_lists;
extern u8 *tl_05;
struct Base_8015C098 { char pad[0x18]; };
struct VObj_8015C098 : Base_8015C098 {
    virtual void m0();
    virtual void m1();  virtual void m2();  virtual void m3();  virtual void m4();
    virtual void m5();  virtual void m6();  virtual void m7();  virtual void m8();
    virtual void m9();  virtual void m10(); virtual void m11(); virtual void m12();
    virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16();
    virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20();
    virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28();
    virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32();
    virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36();
    virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40();
    virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48();
    virtual void m49(); virtual void m50(); virtual void m51(); virtual void m52();
    virtual void m53(); virtual void m54(); virtual void m55(); virtual void m56();
    virtual void m57(); virtual void m58(); virtual void m59(); virtual void m60();
    virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68();
    virtual void m69(); virtual void m70(); virtual void m71(); virtual void m72();
    virtual void m73(); virtual void m74(); virtual void m75(); virtual void m76();
    virtual void m77();
};
extern "C" {

void __dl__7TObjectFPv(void *);

void TOContainerAncientItemCommon::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 1) {
        if (arg2 != 0) {
            ((struct VObj_8015C098 *) this)->m77();
            this->spawn_item((s32)this);
        }
        this->mode = 1;
        set_flag8();
        queue_destruction__7TObjectFv(this);
    }
}

extern s32 __vt__28TOContainerAncientItemCommon[];

s32 TOContainerAncientItemCommon::create() {
    s32 arg0 = (s32)this;
    s32 container_ancient_item_common;
    s32 temp_r3_2;
    s32 var_r0;
    s32 var_r0_2;
    if (((s32) enable_v2_features == 1) && (get_game_play_mode() == 1) && (is_quest_active() == 1)) {
        container_ancient_item_common = __nw__7TObjectFUl(0x368);
        var_r0_2 = container_ancient_item_common;
        if (var_r0_2 != 0) {
            var_r0_2 = ((s32)TOContainerAncientItemCommon__ct((void *)container_ancient_item_common, (void *)arg0));
        }
        return var_r0_2;
    }
    temp_r3_2 = __nw__7TObjectFUl(0x368);
    var_r0 = temp_r3_2;
    if (var_r0 != 0) {
        var_r0 = ((s32)TOContainerAncientItemCommon__ct((void *)temp_r3_2, (void *)arg0));
    }
    return var_r0;
}

void *__dt__28TOContainerAncientItemCommonFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__28TOContainerAncientItemCommon;
        ((TUnk_804B08BC *)arg0)->destroy_ancient_container(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *lbl_805D2EFC;

void *TOContainerAncientItemCommon__ct(void *container_ancient_item_common, void * _w1) {
    init_ancient_container((u8 *)container_ancient_item_common, (s32)_w1);
    *(s32 **)((s8 *)container_ancient_item_common + 0x18) = __vt__28TOContainerAncientItemCommon;
    *(void * *)&((TOContainerAncientItemCommon *)container_ancient_item_common)->m_name = lbl_805D2EFC;
    return container_ancient_item_common;
}
void TUnk_804B08BC::vfunc_79() {
    Obj_8015C234 *self = (Obj_8015C234 *)this;
    extern const u32 ancient_container_resource_bundle;
    if (this->mode == 1) {
        return;
    }
    Desc_8015C234 a = fish_break_debris_desc;
    a.x = self->x;
    a.y = self->y;
    a.z = self->z;
    a.y2 = a.y;
    a.a = get_bml_model((void *)ancient_container_resource_bundle, 1);
    a.b = TObjFish__sub_8001EDB0((void *)ancient_container_resource_bundle, 1);
    Desc_8015C234 b = lbl_8044074C;
    b.x = self->x;
    b.y = self->y;
    b.z = self->z;
    b.y2 = b.y;
    b.a = get_bml_model((void *)ancient_container_resource_bundle, 2);
    b.b = TObjFish__sub_8001EDB0((void *)ancient_container_resource_bundle, 2);
    if (check_value_equals__13TUnk_804B6C24Fl(self, lbl_805D2F00) != 0) {
        a.b = ancient_container_fragment_texture_lists->a;
        b.b = ancient_container_fragment_texture_lists->b;
    }
    {
        u8 *o = (u8 *)__nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams(o, tl_05, (u8 *)&a);
        }
    }
    {
        u8 *o = (u8 *)__nw__7TObjectFUl(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams(o, tl_05, (u8 *)&b);
        }
    }
    spawn_particle_effect(&self->x, 0x45);
    spawn_particle_effect(&self->x, 0x46);
    play_container_break_sound((s32)self);
}

void TUnk_804B08BC::vfunc_81() {
    extern u32 ancient_container_resource_bundle;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    if ((u32) ancient_container_resource_bundle != 0U) {
        switch (this->mode) {
        case 0:
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(this->texlist);
            temp_r31 = (unsigned char *) (this->model);
            push_matrix();
            post_translate_matrix(temp_r31 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
            temp_r31_2 = (unsigned char *) (*(void **)((s8 *)temp_r31 + 0x2C));
            push_matrix();
            post_translate_matrix(temp_r31_2 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
            pop_matrix();
            temp_r31_3 = (unsigned char *) (*(void **)((s8 *)temp_r31_2 + 0x30));
            push_matrix();
            post_translate_matrix(temp_r31_3 + 8);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
            TParticleCtrl::end_effect_render();
            pop_matrix();
            pop_matrix();
            pop_matrix();
            break;
        }
    }
}
void TUnk_804B08BC::vfunc_80() {
    Obj_8015C48C *self = (Obj_8015C48C *)this;
    switch (this->mode) {
    case 0:
        if (this->m_364 != 0) {
            submit_cursor_candidate(self, -1);
        }
        break;
    }
}
}
