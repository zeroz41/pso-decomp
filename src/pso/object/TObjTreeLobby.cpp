#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMapObject.h"
#include "pso/object/TUnk_804F2B60.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjTreeLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_8047A068[];
extern char lbl_8047A080[];
extern const char *bm_obj_lobby_tree_model_names[2];
extern BmlResourceDescriptor TObjTreeLobby_resource_descriptor;
extern const char *bm_obj_lobby_tree_motion_names[1];

struct RecoveredGlobal_80364A1C_lbl_804F2B18 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80364A1C_lbl_804F2B18_size[sizeof(RecoveredGlobal_80364A1C_lbl_804F2B18) == 0x10 ? 1 : -1];

struct Base_80364B6C { char pad[0x18]; };

struct Ctrl_80364B6C : Base_80364B6C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(void *, void *, s32, s32, s32);
};

struct P_80364B6C { s32 a; f32 b; };

struct Obj_80364B6C { u8 pad0[0x1C]; f32 f1C; u16 h20; };


extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TObjTreeLobby__instance;
extern s32 tree_lobby_type;
void TLobby__sub_8001FE7C(void*, int);
s32 post_translate_matrix(void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
void *get_player_by_client_id(s32 i);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 is_lobby_event_active();
extern const char *TObjTreeLobby__class_name;
extern s32 lbl_804F2B60[];

void TObjTreeLobby::render() {
    f32 temp_f1;

    if ((s32) this->fade_state != 0) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->fade_state != 3) {
            temp_f1 = this->fade_scale;
            scale_matrix(0, temp_f1, (f32) (1.0f), temp_f1);
        }
        draw_ginja_object(this->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

extern void *tl_05;

void TObjTreeLobby::run_task() {
    switch (this->fade_state) {
    case 0:
        if (TLobby::is_connected() != 0) {
            this->fade_state = 2;
        }
        break;
    case 2:
        this->fade_scale += 0.1f;
        if (this->fade_scale >= 1.0f) {
            this->fade_scale = 1.0f;
            this->fade_state = 3;
        }
        break;
    case 1:
        this->fade_scale -= 0.1f;
        if (this->fade_scale <= 0.0f) {
            this->fade_scale = 0.0f;
            this->fade_state = 0;
        }
        break;
    case 3:
    default:
        if (TLobby::is_lobby_obj_active() != 0) {
            this->fade_state = 1;
        }
        break;
    }
}

void *TObjTreeLobby::create(void *arg0) {
    return new TObjTreeLobby((TObject *)tl_05, arg0);
}

void TObjTreeLobby::destroy_static_instance() {
    if ((u32) TObjTreeLobby__instance != 0U) {
        TLobby__sub_8001FE7C((void*)TObjTreeLobby__instance, 1);
        TObjTreeLobby__instance = 0U;
    }
}
void TObjTreeLobby::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &TObjTreeLobby_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjTreeLobby__instance) = var_r0;
    tree_lobby_type = TLobby::get_lobby_type();
}

TObjTreeLobby::~TObjTreeLobby() {}

TObjTreeLobby::TObjTreeLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TObjTreeLobby__class_name;
    apply_object_set_data(set_data);
    if (is_lobby_event_active() != 0) {
        fade_state = 0;
    } else {
        fade_state = 3;
    }
    fade_scale = 1.0f;
    model = (void *)*(s32 *)((s8 *)(*(void **)((s8 *)((void *)TObjTreeLobby__instance) + 0x42C)) + 8);
    texlist = (s32) tree_lobby_type;
}
void TUnk_804F2B60::run_task() {
    Obj_80364B6C *arg0 = (Obj_80364B6C *)this;
    Ctrl_80364B6C *c = (Ctrl_80364B6C *)get_player_by_client_id(arg0->h20);
    if (c != 0) {
        P_80364B6C sp10;
        sp10.a = 0x15;
        sp10.b = arg0->f1C;
        P_80364B6C sp8 = sp10;
        c->v21(c, &sp8, 0, -1, -1);
        queue_destruction__7TObjectFv(arg0);
    }
}

void *__dt__13TUnk_804F2B60Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F2B60;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

__declspec(section ".data") const char *bm_obj_lobby_tree_model_names[2] = { lbl_8047A068, NULL };
BmlResourceDescriptor TObjTreeLobby_resource_descriptor = { lbl_8047A080, bm_obj_lobby_tree_model_names, bm_obj_lobby_tree_motion_names, 1, 0 };
__declspec(section ".sdata") const char *bm_obj_lobby_tree_motion_names[1] = { NULL };
}
