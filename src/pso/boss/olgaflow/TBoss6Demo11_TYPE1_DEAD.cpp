#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_80087278.h"
#include "pso/boss/olgaflow/TBoss6Demo11_TYPE1_DEAD.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/object/ambient/TObjFish_800E2FFC.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/effect/particle/TParticleCtrl.h"

// Frame window -> effect point that carries the smoke emitter.
struct FishSpawnEntry {
    s32 start;
    s32 end;
    s32 point;
};

// One node of the list TObjFish__sub_800E3124 reads (node -1 ends it).
struct EffectNodeDesc {
    s32 node;
    Vec offset;
};

extern s32 lbl_804DF614[]; // model ids, defined in TBoss6Type1.cpp

const char lbl_80477E48[] = "TBoss6Demo11_TYPE1_DEAD";
static s32 lbl_804EF9D8[2] = {4, 5};          // motion ids
static Vec lbl_804EF9E0 = {0.0f, 0.0f, 70.0f}; // start position
const char *lbl_805D42A0 = lbl_80477E48;

void *TBoss6PlotFalz::create(void *parent, void *arg) {
    return new TBoss6Demo11_TYPE1_DEAD((TObject *)parent, arg);
}

TBoss6Demo11_TYPE1_DEAD::TBoss6Demo11_TYPE1_DEAD(TObject *parent, void *arg) : TObject(parent) {
    static const EffectNodeDesc lbl_80477E60[] = {
        {0, {0.0f, 0.0f, 0.0f}},
        {4, {0.0f, 0.0f, 0.0f}},
        {6, {0.0f, 0.0f, 0.0f}},
        {0x19, {0.0f, 0.0f, 0.0f}},
        {0x31, {0.0f, 0.0f, 0.0f}},
        {-1, {0.0f, 0.0f, 0.0f}},
    };
    static const CameraAngles lbl_80477EC0 = {0, 0, 0};
    static const CameraPlayback lbl_80477ECC = {1, 0, 0, 0.0f, 0.7f};
    BmlResource *resource;
    s32 i;
    m_name = lbl_805D42A0;
    owner = (TObjFish *)parent;
    VecCopy(&position, &lbl_804EF9E0);
    resource = (BmlResource *)TObjFish::get_fish_count();
    for (i = 0; i < 2; i++) {
        s32 model_id = lbl_804DF614[i];
        parts[i].model = get_bml_model(resource, model_id);
        parts[i].texture = TObjFish__sub_8001EDB0(resource, model_id);
        parts[i].motion = get_bml_motion(resource, lbl_804EF9D8[i]);
    }
    node_effect = (TObjFish *)TObjFish__sub_800E3124((u8 *)lbl_80477E60, (s32)effect_points);
    emitter = NULL;
    activate_camera_mode(5);
    set_scripted_camera_pose(&position, &position, &lbl_80477EC0);
    ((TCameraCtrl *)&lbl_80477ECC)->cache_target_and_forward(0x416C);
    frame = 0.0f;
    timer = 0;
}

TBoss6Demo11_TYPE1_DEAD::~TBoss6Demo11_TYPE1_DEAD() {
    restore_player_cameras();
    if (node_effect != NULL) {
        TObjFish::init_state_1(node_effect);
        node_effect = NULL;
    }
    if (emitter != NULL) {
        TParticleCtrl::release(emitter);
        emitter = NULL;
    }
}

void TBoss6Demo11_TYPE1_DEAD::run_task() {
    static const FishSpawnEntry fish_spawn_entry_table[4] = {
        {0x07, 0x2A, 4},
        {0x47, 0x80, 3},
        {0x6B, 0x89, 1},
        {0x8E, 0xB9, 2},
    };
    s32 found;
    s32 i;
    Vec *p;
    Vec *q;
    const FishSpawnEntry *t;
    if ((frame += 0.7f) > 179.0f) {
        frame = 179.0f;
    }
    switch (timer) {
    case 0x98:
        play_sound_effect(0x40032104, 0, 0, 0);
        break;
    case 0xF9:
        play_sound_effect(0x40032B25, 0, 0, 0);
        break;
    case 0x1E:
        play_sound_effect(0x4003A811, 0, 0, 0);
        break;
    case 0x3C:
    case 0x5A:
    case 0x14:
    case 0xA:
        play_sound_effect(0x40032E23, 0, 0, 0);
        break;
    }
    if (timer >= 0x89) {
        play_persistent_sound(0x4003A424, (s32)this, 0, 0, 0);
    }
    switch (timer) {
    case 0xE:
        q = &effect_points[4];
        spawn_particle_effect_with_flags(q, 0x21C, 0x40);
        spawn_particle_effect_with_flags(q, 0x21D, 0x40);
        break;
    case 0x4E:
        q = &effect_points[3];
        spawn_particle_effect_with_flags(q, 0x21C, 0x40);
        spawn_particle_effect_with_flags(q, 0x21D, 0x40);
        break;
    }
    if (timer >= 0xB9 && !(timer & 3)) {
        q = &effect_points[0];
        spawn_particle_effect_with_flags(q, 0x13C, 0x40);
        spawn_particle_effect_with_flags(q, 0x13D, 0x40);
    }
    found = 0;
    for (i = 0; i < 4; i++) {
        t = &fish_spawn_entry_table[i];
        if (timer >= t->start && timer < t->end) {
            p = &effect_points[t->point];
            if (emitter == NULL) {
                emitter = create_particle_emitter(p, 0x21F);
                if (emitter != NULL) {
                    emitter->set_flags(0x40);
                }
            } else {
                emitter->set_position(p);
            }
            found = 1;
            break;
        }
    }
    if (found == 0 && emitter != NULL) {
        TParticleCtrl::release(emitter);
        emitter = NULL;
    }
    switch (timer) {
    case 5:
    case 0x19:
    case 0x46:
    case 0x5F:
    case 0x6E:
    case 0x8C:
    case 0xBE:
    case 0xFF:
        start_pad_rumble_all(0xC0, 0xF);
        break;
    }
    timer++;
    if (timer >= 0x101 || owner->get_phase() != 3) {
        queue_destruction();
    }
}

void TBoss6Demo11_TYPE1_DEAD::render() { render_fade_model(); }

void TBoss6Demo11_TYPE1_DEAD::render_fade_model() {
    f32 fade;
    if (timer < 0xBF) {
        fade = 1.0f;
    } else if (timer >= 0xCC) {
        fade = 0.0f;
    } else {
        fade = (f32)(0xCC - timer) / 13.0f;
    }
    if (0.0f != fade) {
        if (fade < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(fade);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&position.x);
        TObjFish::set_global_param(parts[0].texture);
        draw_model_motion((void *)parts[0].model, parts[0].motion, frame);
        TObjFish::set_global_param(parts[1].texture);
        node_effect->set_draw_callback_list();
        draw_model_motion((void *)parts[1].model, parts[1].motion, frame);
        node_effect->clear_render_callback();
        clear_motion_packed_rotation();
        pop_matrix();
        if (fade < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}
