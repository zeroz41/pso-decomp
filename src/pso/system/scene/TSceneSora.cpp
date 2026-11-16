#include "types.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/unk/TLobby_80131794.h"
#include "pso/unk/TLobby_80140FF4.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/TLobby.h"
#include "pso/system/scene/TSceneSora.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/scene/TScene.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/system/MatrixStack.h"

struct RecoveredGlobal_802075F8_lbl_80515BA0 {
    s32 value;
    u8 remaining[0x24];
};

struct SkyMotion_80207238 { u32 rows; u32 frame_count; };

struct TSceneSora_80207238 {
    u8 pad[0x60];
    s32 yaw;
    u8 pad64[0x94 - 0x64];
    SkyMotion_80207238 *motion;
    void *textures;
    f32 rate;
    f32 frame;
};

struct Ref_80207478 { s32 id; s32 idx; s32 pad; };

struct Ent_80207478 { s32 f0; char *name; };

struct Res_80207478 { void *buf; s32 n; };

#pragma readonly_strings on

extern "C" {
s32 TSceneSora__sky_active_flag = 1;
const char *TSceneSora__name = "TSceneSora";
s32 TSceneSora__instance;
u32 TSceneSora__sky_bml_resource;
s32 TSceneSora__has_sky_motion;

u8 * free_bin_model_request(void *, s16);
void TSceneSora__sub_80207430(void);
s32 get_bml_motion(int, int);
s32 get_bml_texlist(int, int);
s32 get_bml_model(int, int);
u8 *__ct__10TSceneSoraFl(TSceneSora *arg0, s32 _w1);
void draw_ginja_model_with_motion(void *model, void *motion, f32 frame);
s32 rotate_matrix_y(int, int);
s32 set_global_param__8TObjFishFl();
void *get_current_floor();
u32 init_bin_model_request(void *, int, Res_80207478 *, Res_80207478 *, int, int, int);
s32 lookup_scene_object__6TLobbyFPv(void *, Ref_80207478 *);
void *adxf_open__6TLobbyFUii(char *, int);
extern char sky_model_ext_s_njm[];
extern char sky_model_ext_sm_gj[];
extern char sky_model_ext_s_gj[];
void TLobby__sub_802075F4(void);
s32 __nw__7TObjectFUl(s32);

extern s32 tl_05;

void TSceneSora::render() {
    if ((s32) TSceneSora__sky_active_flag != 0) {
        TParticleCtrl::begin_effect_render();
        get_bml_texlist((int) ((*(s32 *)&TSceneSora__sky_bml_resource)), 0);
        set_global_param__8TObjFishFl();
        push_matrix();
        rotate_matrix_y(0, this->rotation_y);
        if ((u32) this->m_94 != 0U) {
            draw_ginja_model_with_motion((void *)this->m_90, (void *)this->m_94, (f32)this->m_a0);
        } else {
            draw_ginja_object((void *)this->m_90);
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TSceneSora::run_task() {
    TSceneSora_80207238 *sky = (TSceneSora_80207238 *)this;
    if (sky->motion != NULL) {
        sky->frame += sky->rate;
        if (sky->frame > (sky->motion->frame_count - 1)) {
            sky->frame = 0.0f;
        }
    } else {
        switch (get_current_floor_area()) {
        case AREA_FOREST1:
        case AREA_FOREST2:
            sky->yaw++;
            break;
        }
    }
}

}
TSceneSora::~TSceneSora() {
    TSceneSora__instance = 0;
}
TSceneSora::TSceneSora(s32 _w1) : TObjBase((TObject *)_w1) {
    this->m_name = TSceneSora__name;
    this->m_90 = get_bml_model((int) ((*(s32 *)&TSceneSora__sky_bml_resource)), 0);
    if (TSceneSora__has_sky_motion != 0) {
        this->m_94 = get_bml_motion((int) ((*(s32 *)&TSceneSora__sky_bml_resource)), 0);
    } else {
        this->m_94 = 0;
    }
    this->m_98 = get_bml_texlist((int) ((*(s32 *)&TSceneSora__sky_bml_resource)), 0);
    *(f32 *)((s8 *)this + 0x9C) = 0.1f;
    this->m_a0 = 0.0f;
}
extern "C" {

void TSceneSora::create_instance() {
    s32 scene_sora;

    if ((u32) TSceneSora__sky_bml_resource != 0U) {
        scene_sora = __nw__7TObjectFUl(0xA4);
        if (scene_sora != 0) {
            scene_sora = ((s32)__ct__10TSceneSoraFl((TSceneSora *)((u8 *)scene_sora), (s32)tl_05));
        }
        TSceneSora__instance = scene_sora;
        return;
    }
    TSceneSora__instance = 0;
}

void TSceneSora__sub_80207430(void) {
    TSceneSora__sky_active_flag = 1;
    if ((void *) (*(u8 * *)&TSceneSora__sky_bml_resource) != NULL) {
        free_bin_model_request((*(u8 * *)&TSceneSora__sky_bml_resource), 1);
        (*(u8 * *)&TSceneSora__sky_bml_resource) = NULL;
    }
    TSceneSora__instance = 0;
}

void TSceneSora::load_sky_resources() {
    char name2[0x20];
    char name1[0x20];
    Ref_80207478 ref;
    Res_80207478 b;
    Res_80207478 a;
    Ent_80207478 *tbl;
    s32 ok;
    void *p;
    u32 o;
    TSceneSora__instance = 0;
    TSceneSora__sky_bml_resource = 0;
    TSceneSora__has_sky_motion = 0;
    if (lookup_scene_object__6TLobbyFPv(get_current_floor(), &ref) != 0) {
        ok = 0;
        tbl = (Ent_80207478 *)get_floor_scene_table(ref.id);
        replace_file_extension__6TLobbyFPvPvPv(name1, tbl[ref.idx].name, sky_model_ext_s_njm);
        if (TRaderMapCore::is_not_split_screen() == 1) {
            replace_file_extension__6TLobbyFPvPvPv(name2, tbl[ref.idx].name, sky_model_ext_sm_gj);
            ok = ((TScene *)name2)->update_lobby_scene();
        }
        if (ok <= 0) {
            replace_file_extension__6TLobbyFPvPvPv(name2, tbl[ref.idx].name, sky_model_ext_s_gj);
        }
        p = adxf_open__6TLobbyFUii(name2, 0);
        if (p != NULL) {
            b.buf = name2;
            ((TLobby *)p)->close_adxf_handle();
        } else {
            return;
        }
        p = adxf_open__6TLobbyFUii(name1, 0);
        if (p != NULL) {
            a.buf = name1;
            TSceneSora__has_sky_motion = 1;
            ((TLobby *)p)->close_adxf_handle();
        } else {
            a.buf = NULL;
        }
        b.n = 0;
        a.n = 0;
        o = (u32)(int)::operator new(0x440);
        if (o != 0) {
            o = init_bin_model_request((void *)o, 1, &b, &a, 0, 0, 0);
        }
        TSceneSora__sky_bml_resource = o;
        TSceneSora__sky_active_flag = 1;
    }
}

void TLobby__sub_802075F4(void) {  }
}
extern RecoveredGlobal_802075F8_lbl_80515BA0 lbl_80515BA0;
extern s32 pending_adventure_map_floor;
void prepare_adventure_maps(void);
typedef char RecoveredGlobal_802075F8_lbl_80515BA0_size[sizeof(RecoveredGlobal_802075F8_lbl_80515BA0) == 0x28 ? 1 : -1];
void prepare_adventure_maps(void) {
    randomize_adventure_maps();
    if ((s32) pending_adventure_map_floor != -1) {
        TLobby__sub_80141038((u8 *)&lbl_80515BA0.value, pending_adventure_map_floor, get_floor_map_terrain(pending_adventure_map_floor));
        pending_adventure_map_floor = -1;
    }
}
