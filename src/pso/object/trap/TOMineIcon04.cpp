#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/trap/TOMine.h"
#include "pso/object/trap/TOMineIcon04.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"

extern s32 game_difficulty_selection;
extern void *tl_05;

const char *TOMineIcon04__name = "TOMineIcon04";

// -inline deferred: functions are written last-to-first.
#pragma push
#pragma fp_contract on
TOMineIcon04::TOMineIcon04(TObject *parent, void *set_data) : TOMine(parent) {
    m_name = TOMineIcon04__name;
    apply_object_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    calc_attach_pos();
    model = (void *)get_bml_model(lbl_805D5A50, 7);
    texlist = TObjFish__sub_8001EDB0(lbl_805D5A50, 7);
    m_374 = get_bml_model(lbl_805D5A50, 3);
    m_378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 3);
    mode = 0;
    if (set_params[0] < 0) {
        set_params[0] = 0;
    }
    if (set_params[1] < 0) {
        set_params[1] = 0;
    } else if (set_params[1] > 5) {
        set_params[1] = 5;
    }
    if (set_params[2] < 0) {
        set_params[2] = 0;
    }
    attack.power = (f32)set_params[0] * (2.0f * (f32)game_difficulty_selection + 1.0f);
    if (game_difficulty_selection == 3) {
        attack.power *= 2.0f;
    }
    attack.kind = set_params[1];
    pad_34C = 0.5f * scale.x + 60.0f;
    m_350 = 0.5f * scale.y + 120.0f;
    update_state();
    m_35c = 0xFFFF;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, mine_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
}
#pragma pop

TOMineIcon04::~TOMineIcon04() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TOMineIcon04::create() {
    return new TOMineIcon04((TObject *)tl_05, this);
}

void TOMineIcon04::vfunc_80() {
    s32 arg0 = (s32)this;
    u32 area;
    area = get_current_floor_area();
    switch (area) {
    case AREA_FOREST1:
    case AREA_FOREST2:
        play_sound_effect(0x4C111, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_sound_effect(0x44110, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_MINE1:
    case AREA_MINE2:
        play_sound_effect(0x4004C10A, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_sound_effect(0x4004C111, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4BC07, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004BC07, (void *)(arg0 + 0x38), 0, 0);
        return;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x4BC19, (void *)(arg0 + 0x38), 0, 0);
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004BC19, (void *)(arg0 + 0x38), 0, 0);
    default:
        return;
    }
}

void TOMineIcon04::vfunc_82() { spawn_particle_effect((char*)this + 0x2fc, 140); }
void TOMineIcon04::vfunc_84() {  }
