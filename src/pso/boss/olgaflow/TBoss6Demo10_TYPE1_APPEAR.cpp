#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/system/PadRumble.h"
#include "pso/boss/olgaflow/Boss6Type1Appearance.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/olgaflow/TBoss6Demo10_TYPE1_APPEAR.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"


extern "C" {
extern Vec lbl_80477DEC;
extern ModelNodePositionEntry boss6_type1_appear_node_desc[];
extern Boss6StripDesc boss6_type1_appear_model_node_descriptors[];
extern CameraAngles lbl_80477E30;
extern CameraPlayback lbl_80477E3C;
extern s32 lbl_804DF614[];
extern s32 boss6_type1_appear_motion_indices[];
extern const s32 __vt__25TBoss6Demo10_TYPE1_APPEAR[];
struct AppearanceClassTag { const char *value; u32 padding; };
__declspec(section ".sdata") extern AppearanceClassTag TBoss6Demo10_TYPE1_APPEAR__name;
struct AppearanceZero { f32 value; u32 padding; };
__declspec(section ".sdata2") extern const AppearanceZero lbl_805DFA50;
TBoss6Demo10_TYPE1_APPEAR *__ct__25TBoss6Demo10_TYPE1_APPEARFP14TBoss6PlotFalz(TBoss6Demo10_TYPE1_APPEAR *demo, TBoss6PlotFalz *plot);
void post_translate_matrix(const f32 *);

void TBoss6Demo10_TYPE1_APPEAR::sub_8033C7C8() {
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&lbl_80477DEC.x);
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(parts[0].texture));
    draw_model_motion(parts[0].model, parts[0].motion, frame);
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(parts[1].texture));
    capture->install();
    draw_model_motion(parts[1].model, parts[1].motion, frame);
    capture->clear();
    clear_motion_packed_rotation();
    pop_matrix();
}

void render__25TBoss6Demo10_TYPE1_APPEARFv(void* p) { ((TBoss6Demo10_TYPE1_APPEAR *)p)->sub_8033C7C8(); }

#pragma push
#pragma opt_common_subs off
void run_task__25TBoss6Demo10_TYPE1_APPEARFv(TBoss6Demo10_TYPE1_APPEAR *boss6_demo10_type1_appear) {
    s32 temp_r0_3;
    Vec *effect_position;
    if ((boss6_demo10_type1_appear->frame += 0.7f) > 349.0f) {
        boss6_demo10_type1_appear->frame = 349.0f;
    }
    boss6_demo10_type1_appear->scroll_strips.scroll_strips_uv(8, 0);
    if ((s32) boss6_demo10_type1_appear->timer == 0x78) {
        play_sound_effect(0x4003A105, 0, 0, 0);
    }
    switch (boss6_demo10_type1_appear->timer) {
    case 0x1B8:
    case 0xFA:
        play_sound_effect(0x4003A811, 0, 0, 0);
        break;
    case 0x154:
        play_sound_effect(0x40031222, 0, 0, 0);
        break;
    }
    switch (boss6_demo10_type1_appear->timer) {
    case 0x14:
    case 0xC6:
    case 0xFA:
    case 0x13F:
    case 0x1B8:
        start_pad_rumble_all(0xC0, 0xF);
        break;
    }
    temp_r0_3 = boss6_demo10_type1_appear->timer;
    effect_position = &boss6_demo10_type1_appear->effect_position;
    switch (temp_r0_3) {
    case 0x1:
        boss6_demo10_type1_appear->emitter = create_particle_emitter(effect_position, 0x210);
        if (boss6_demo10_type1_appear->emitter != NULL) {
            boss6_demo10_type1_appear->emitter->set_flags(0x40);
        }
        break;
    case 0x1AC:
    case 0x8E:
        if (boss6_demo10_type1_appear->emitter != NULL) {
            TParticleCtrl::release(boss6_demo10_type1_appear->emitter);
            boss6_demo10_type1_appear->emitter = NULL;
        }
        boss6_demo10_type1_appear->emitter = create_particle_emitter(effect_position, 0x211);
        if (boss6_demo10_type1_appear->emitter != NULL) {
            boss6_demo10_type1_appear->emitter->set_flags(0x40);
        }
        break;
    case 0x11D:
        if (boss6_demo10_type1_appear->emitter != NULL) {
            TParticleCtrl::release(boss6_demo10_type1_appear->emitter);
            boss6_demo10_type1_appear->emitter = NULL;
        }
        boss6_demo10_type1_appear->emitter = create_particle_emitter(effect_position, 0x210);
        if (boss6_demo10_type1_appear->emitter != NULL) {
            boss6_demo10_type1_appear->emitter->set_flags(0x40);
        }
        break;
    }
    if (boss6_demo10_type1_appear->emitter != NULL) {
        boss6_demo10_type1_appear->emitter->set_position(effect_position);
    }
    boss6_demo10_type1_appear->timer = (boss6_demo10_type1_appear->timer + 1);
    if (((s32) boss6_demo10_type1_appear->timer >= 0x1F4) || (boss6_demo10_type1_appear->plot->get_scene_state() != 1)) {
        boss6_demo10_type1_appear->queue_destruction();
    }
}
#pragma pop

}
TBoss6Demo10_TYPE1_APPEAR::~TBoss6Demo10_TYPE1_APPEAR() {
    restore_player_cameras();
    TBoss6PlotFalz::refresh_players_equipment();
    scroll_strips.free_buffer_pairs();
    if (capture != NULL) {
        ModelNodePositionCapture::destroy((ModelNodePositionCapture *)capture);
        capture = NULL;
    }
    if (emitter != NULL) {
        TParticleCtrl::release(emitter);
        emitter = NULL;
    }
}

TBoss6Demo10_TYPE1_APPEAR::TBoss6Demo10_TYPE1_APPEAR(TBoss6PlotFalz *plot) : TObject(plot) {
    s32 k;
    BmlResource *archive;
    saddr i;
    m_name = TBoss6Demo10_TYPE1_APPEAR__name.value;
    this->plot = plot;
    archive = TBoss6PlotFalz::get_scene_archive();
    for (i = 0; i < 2; i++)
    {
      k = lbl_804DF614[i];
      k = k & 0xFFFFFFFFu;
      parts[i].model = (NJS_OBJECT *)get_bml_model(archive, k);
      parts[i].texture = (GinjaTextureList *)get_bml_texlist(archive, k);
      parts[i].motion = get_bml_motion(archive, boss6_type1_appear_motion_indices[i]);
    }
    capture = ModelNodePositionCapture::create(boss6_type1_appear_node_desc, (Vec *)&effect_position);
    emitter = NULL;
    scroll_strips.build_tables(boss6_type1_appear_model_node_descriptors, 2);
    activate_camera_mode(5);
    set_scripted_camera_pose(&lbl_80477DEC, &lbl_80477DEC, &lbl_80477E30);
    lbl_80477E3C.cache_target_and_forward(0x416C);
    frame = lbl_805DFA50.value;
    timer = 0;
}

TBoss6Demo10_TYPE1_APPEAR *TBoss6Demo10_TYPE1_APPEAR::create(TBoss6PlotFalz *plot) {
    TBoss6Demo10_TYPE1_APPEAR *demo = (TBoss6Demo10_TYPE1_APPEAR *)TObject::operator new(sizeof(TBoss6Demo10_TYPE1_APPEAR));
    if (demo != NULL) {
        demo = __ct__25TBoss6Demo10_TYPE1_APPEARFP14TBoss6PlotFalz(demo, plot);
    }
    return demo;
}

extern const char TBoss6Demo10_TYPE1_APPEAR__class_name[];
__declspec(section ".rodata") const char TBoss6Demo10_TYPE1_APPEAR__class_name[] ATTRIBUTE_ALIGN(4) = "TBoss6Demo10_TYPE1_APPEAR";
__declspec(section ".rodata") Vec lbl_80477DEC = {0.0f, 25.0f, 75.0f};
__declspec(section ".rodata") ModelNodePositionEntry boss6_type1_appear_node_desc[] = {{0}, {-1}};
__declspec(section ".rodata") Boss6StripDesc boss6_type1_appear_model_node_descriptors[] = {{3, 1, 0}, {6, 1, 0}};
__declspec(section ".rodata") CameraAngles lbl_80477E30 = {0, 0, 0};
__declspec(section ".rodata") CameraPlayback lbl_80477E3C = {1, 2, 0, 0.0f, 0.7f};
s32 boss6_type1_appear_motion_indices[] = {35, 36};
extern __declspec(section ".data") const s32 __vt__25TBoss6Demo10_TYPE1_APPEAR[];
__declspec(section ".sdata") AppearanceClassTag TBoss6Demo10_TYPE1_APPEAR__name = {TBoss6Demo10_TYPE1_APPEAR__class_name, 0};
__declspec(section ".sdata2") const AppearanceZero lbl_805DFA50 = {0.0f, 0};
