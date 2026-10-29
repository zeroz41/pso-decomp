#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/misc/TMainCursor_8013F104.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804A7488.h"
#include "pso/misc/TUnk_804A7478.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TPlyPhotonChair.h"
#include "pso/TMainTask.h"
#include "pso/misc/TMainCursor.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"

extern char lbl_804796E0[];
extern char lbl_804796F4[];
extern char lbl_80479708[];
extern char lbl_8047971C[];
extern char lbl_80479734[];
extern const char *bm_ply_photon_chair_model_names[3];
extern const char *bm_ply_photon_chair_motion_names[3];
extern BmlResourceDescriptor photon_chair_resource_descriptor;

struct RecoveredGlobal_8035B2DC_lbl_804F1CB8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8035B2DC_lbl_804F1CB8_size[sizeof(RecoveredGlobal_8035B2DC_lbl_804F1CB8) == 0x10 ? 1 : -1];


struct RecoveredGlobal_8035B3C0_lbl_8047975C { s32 value; u8 remaining[0xA0]; };

struct RecoveredGlobal_8035B3C0___vt__15TPlyPhotonChair { s32 value; u8 remaining[0x34]; };

struct Vec_8035B058 { f32 x, y, z; };

struct Quat_8035B058 { f32 w, x, y, z; };

struct PBase_8035B058 { char pad[0x18]; };

struct Player_8035B058 : PBase_8035B058 {
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
    virtual void m63(s32, Vec_8035B058 *);
};

struct SBase_8035B058 { char pad[4]; };

struct Sub_8035B058 : SBase_8035B058 {
    virtual void s0();
    virtual void s1();
};

struct Chair_8035B058 {
    u8 pad0[0x24];
    s32 x24;
    u8 pad28[0x38 - 0x28];
    Vec_8035B058 pos;
    u8 pad44[0x5C - 0x44];
    u8 rot[4];
    s32 x60;
    u8 pad64[4];
    u8 x68[0x98 - 0x68];
    Sub_8035B058 a;
    u8 padA0[0xB4 - 0xA0];
    Sub_8035B058 b;
    u8 padBC[0xD0 - 0xBC];
    u8 parts[4];
};

extern "C" {
void *get_player_by_client_id(s32 i);
s32 is_mounted__15TPlyPhotonChairFv();
void TPlyPhotonChair__sub_8035B56C(void* p, f32 v);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TPlyPhotonChair__shared_model_resource;
s32 get_bml_motion(int, int);
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
s32 get_actor_section_id__15TPlyPhotonChairFv(int);
s32 get_rader_map__11TMainCursorFv(void *, void *);
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern RecoveredGlobal_8035B3C0_lbl_8047975C TPlyPhotonChair__section_id_color_table;
extern s32 __vt__15TPlyPhotonChair[];
extern s32 lbl_805D4418;
u8 *TPlyPhotonChair__ct(u8 *arg0, s32 arg1, s32 arg2);
int rotate_matrix_y(int, int);
int push_matrix();
int scale_current_matrix(void *);
int post_translate_matrix(void *);
int TPlyPhotonChair__sub_8035B520(void* p);
void *__dt__15TPlyPhotonChairFv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);

void TPlyPhotonChair::render() {
    Chair_8035B058 *self = (Chair_8035B058 *)this;
    Vec_8035B058 out;
    Quat_8035B058 q;
    Quat_8035B058 q2;
    Player_8035B058 *pl;
    pl = (Player_8035B058 *)get_player_by_client_id(((TPlyPhotonChair *)self)->sub_8035B530());
    if (pl != NULL) {
        TPlyPhotonChair::render(self->parts, &q);
        {
            q2.w = q.w;
            q2.x = 0.5f * q.x;
            q2.y = 0.5f * q.y;
            q2.z = 0.5f * q.z;
        }
        pl->m63(2, &out);
        self->pos.x = out.x;
        self->pos.y = out.y - 4.6f;
        self->pos.z = out.z;
        copy_xyz(self->rot, (u8 *)pl + 0x5C);
        if (((TObjPlayer *)pl)->is_inactive() != 0) {
            TPlyPhotonChair::update_parts2(self->parts);
            TObjFish::set_global_param(self->x24);
            push_matrix();
            post_translate_matrix(&self->pos);
            rotate_matrix_y(0, self->x60);
            scale_current_matrix(self->x68);
            if (TMainTask::get_render_pass() != 0) {
                TPlyPhotonChair::play_sound_with_arg(self->parts, &q);
                self->a.s1();
            } else {
                TPlyPhotonChair::play_sound_with_arg(self->parts, &q2);
                self->b.s1();
            }
            pop_matrix();
            TPlyPhotonChair::update_parts(self->parts);
        }
    }
}

void TPlyPhotonChair::run_task() {
    u8 *arg0 = (u8 *)this;
    if (get_player_by_client_id((((TPlyPhotonChair *)arg0)->sub_8035B530())) == 0U) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    if (((u32) this->m_94 == 0U) && (is_mounted__15TPlyPhotonChairFv() == 0)) {
        this->m_94 = 1U;
        ((TPlyPhotonChair *)(arg0 + 0x98))->set_state_ready();
        TPlyPhotonChair__sub_8035B56C((u8 *)&this->m_98, 2.0f);
        ((TPlyPhotonChair *)(arg0 + 0xB4))->set_state_ready();
        TPlyPhotonChair__sub_8035B56C((u8 *)&this->m_b4, 2.0f);
    }
    switch ((s32) this->m_94) {
    case 0:
        ((TUnk_804A7478 *)(arg0 + 0x98))->play_forward();
        ((TUnk_804A7478 *)(arg0 + 0xB4))->play_forward();
        return;
    case 1:
        ((TUnk_804A7478 *)(arg0 + 0x98))->play_backward();
        ((TUnk_804A7478 *)(arg0 + 0xB4))->play_backward();
        if (((TUnk_804A7478 *)(arg0 + 0x98))->get_frame() <= 0.0f) {
            queue_destruction__7TObjectFv((arg0));
        }
        return;
    }
}

void TPlyPhotonChair::free_static_model() {
    if ((u32) TPlyPhotonChair__shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TPlyPhotonChair__shared_model_resource, 1);
        TPlyPhotonChair__shared_model_resource = 0U;
    }
}

s32 TPlyPhotonChair::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &photon_chair_resource_descriptor, 0, 0, 0));
    }
    (*(u8 * *)&TPlyPhotonChair__shared_model_resource) = (unsigned char *) ((void *) var_r0);
    if ((u32) var_r0 == 0U) {
        return 0;
    }
    return 1;
}

void *__dt__15TPlyPhotonChairFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TPlyPhotonChair;
        ((TMainCursor *)((s8 *)arg0 + 0xD0))->destroy(-1);
        ((TUnk_804A7478 *)((s8 *)arg0 + 0xB4))->TUnk_804A7478::~TUnk_804A7478();
        ((TUnk_804A7478 *)((s8 *)arg0 + 0x98))->TUnk_804A7478::~TUnk_804A7478();
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TPlyPhotonChair__ct(u8 *ply_photon_chair, s32 arg1, s32 parent) {
    u32 player;
    __ct__8TObjBaseFP7TObject((void *)ply_photon_chair, (void *)parent);
    *(s32 **)((s8 *)ply_photon_chair + 0x18) = &(*(RecoveredGlobal_8035B3C0___vt__15TPlyPhotonChair *)&__vt__15TPlyPhotonChair).value;
    ((TUnk_804A7478 *)(ply_photon_chair + 0x98))->init();
    ((TUnk_804A7478 *)(ply_photon_chair + 0xB4))->init();
    TMainCursor__sub_8013F1F0((ply_photon_chair + 0xD0));
    *(s32 *)((s8 *)ply_photon_chair + 0) = (s32) lbl_805D4418;
    ((TPlyPhotonChair *)ply_photon_chair)->set_field90(arg1);
    ((TPlyPhotonChair *)ply_photon_chair)->m_92 = 0;
    ((TPlyPhotonChair *)ply_photon_chair)->m_94 = 0;
    player = (u32)get_player_by_client_id((s32)((void *) ((s32) (u16) arg1)));
    if (player == 0U) {
        queue_destruction__7TObjectFv((ply_photon_chair));
        return ply_photon_chair;
    }
    get_rader_map__11TMainCursorFv(ply_photon_chair + 0xD0, (void *) ((u8 *)&TPlyPhotonChair__section_id_color_table.value + (get_actor_section_id__15TPlyPhotonChairFv(player) * 0x10)));
    ((TPlyPhotonChair *)ply_photon_chair)->texlist = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TPlyPhotonChair__shared_model_resource)), 1);
    ((TPlyPhotonChair *)(ply_photon_chair + 0x98))->set_type((s32)((int) (get_bml_model((int) ((*(s32 *)&TPlyPhotonChair__shared_model_resource)), 1))));
    ((TPlyPhotonChair *)(ply_photon_chair + 0x98))->set_field_8((s32)((int) (get_bml_motion((int) ((*(s32 *)&TPlyPhotonChair__shared_model_resource)), 1))));
    ((TPlyPhotonChair *)(ply_photon_chair + 0x98))->sync_field10_from_child();
    TPlyPhotonChair__sub_8035B56C(ply_photon_chair + 0x98, 1.0f);
    ((TPlyPhotonChair *)(ply_photon_chair + 0x98))->set_state_ready();
    ((TPlyPhotonChair *)(ply_photon_chair + 0xB4))->set_type((s32)((int) (get_bml_model((int) ((*(s32 *)&TPlyPhotonChair__shared_model_resource)), 0))));
    ((TPlyPhotonChair *)(ply_photon_chair + 0xB4))->set_field_8((s32)((int) (get_bml_motion((int) ((*(s32 *)&TPlyPhotonChair__shared_model_resource)), 0))));
    ((TPlyPhotonChair *)(ply_photon_chair + 0xB4))->sync_field10_from_child();
    TPlyPhotonChair__sub_8035B56C(ply_photon_chair + 0xB4, 1.0f);
    ((TPlyPhotonChair *)(ply_photon_chair + 0xB4))->set_state_ready();
    return ply_photon_chair;
}

int TPlyPhotonChair__sub_8035B520(void* p) { return *(u32*)((char*)p + 0x94) == 0; }
u16 TPlyPhotonChair::sub_8035B530() { return *(u16 *)&this->unk_90; }
void TPlyPhotonChair::set_field90(s32 v) { *(s16 *)&this->unk_90 = v; }
void TPlyPhotonChair::render(void* p, void* a1) { copy_argb((NJS_ARGB *)a1, (NJS_ARGB *)p); }
void TPlyPhotonChair__sub_8035B56C(void* p, f32 v) { *(f32*)((char*)p + 0x14) = v; }
void TPlyPhotonChair::set_state_ready() { *(s32*)((char*)this + 0x18) = 2; }

void TPlyPhotonChair::sync_field10_from_child() {
    void *prev;

    prev = this->m_prev;
    if (prev != NULL) {
        *(f32 *)&this->m_up = (f32) *(u32 *)((s8 *)prev + 4);
    }
}

void TPlyPhotonChair::set_field_8(s32 v) { *(s32 *)&this->m_prev = v; }
void TPlyPhotonChair::set_type(s32 v) { *(s32 *)&this->m_name = v; }


void *TUnk_804A7478::init() {
    init_parts();
    *(void **)((u8 *)this + 4) = __vt__13TUnk_804A7478;
    sub_8035B610();
    return this;
}

void TUnk_804A7478::sub_8035B610() {
    motion = NULL;
    frame = 0.0f;
    frame_count = 0.0f;
    speed = 0.0f;
    state = 0;
}

u8 *TUnk_804A7488::init_parts() {
    u8 *arg0 = (u8 *)this;
    *(void **)((u8 *)this + 4) = __vt__13TUnk_804A7488;
    ((TUnk_804A7488 *)arg0)->sub_8035B66C();
    return arg0;
}

void TUnk_804A7488::sub_8035B66C() { model = NULL; }

extern u32 chao_npc_instance_handle;

void TPlyPhotonChair::free_instance() {
    if ((u32) chao_npc_instance_handle != 0U) {
        TLobby__sub_8001FE7C((void*)chao_npc_instance_handle, 1);
        chao_npc_instance_handle = 0U;
    }
}

__declspec(section ".data") const char *bm_ply_photon_chair_model_names[3] = { lbl_804796E0, lbl_804796F4, NULL };
__declspec(section ".data") const char *bm_ply_photon_chair_motion_names[3] = { lbl_80479708, lbl_8047971C, NULL };
BmlResourceDescriptor photon_chair_resource_descriptor = { lbl_80479734, bm_ply_photon_chair_model_names, bm_ply_photon_chair_motion_names, 2, 2 };

u32 TPlyPhotonChair__shared_model_resource;
}
