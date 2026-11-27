#include "types.h"
#include "pso/unk/TBattleProximitySound.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/unk/TBattleMusicGainTask.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/TObjPlayer.h"
#include "pso/audio/SoundRequests.h"
#include "pso/player/PlayerSlots.h"
#define PSO_SDK_COMPACT_MATH
#include "pso/render/NinjaUtil.h"
#undef PSO_SDK_COMPACT_MATH

TBattleProximitySound *TBattleProximitySound::instance;

void set_active_disconnect_count(u16 count) { active_character_save_record->online_battle.disconnect_count = count; }
u16 get_active_disconnect_count() { return active_character_save_record->online_battle.disconnect_count; }
void set_active_fourth_place_count(u16 count) { active_character_save_record->online_battle.place_counts[3] = count; }
u16 get_active_fourth_place_count() { return active_character_save_record->online_battle.place_counts[3]; }
void set_active_third_place_count(u16 count) { active_character_save_record->online_battle.place_counts[2] = count; }
u16 get_active_third_place_count() { return active_character_save_record->online_battle.place_counts[2]; }
void set_active_second_place_count(u16 count) { active_character_save_record->online_battle.place_counts[1] = count; }
u16 get_active_second_place_count() { return active_character_save_record->online_battle.place_counts[1]; }
void set_active_first_place_count(u16 count) { active_character_save_record->online_battle.place_counts[0] = count; }
u16 get_active_first_place_count() { return active_character_save_record->online_battle.place_counts[0]; }

void clear_duel_result_window() { duel_result_window = NULL; }

void TBattleProximitySound::destroy() {
    if (instance != NULL) {
        instance->queue_destruction();
    }
}

void TBattleProximitySound::clear_battle_proximity_sound() { instance = NULL; }

s32 TBattleProximitySound::create() {
    s32 area;
    area = get_current_floor_area();
    if ((area != AREA_BATTLE1) && (area != AREA_BATTLE2)) {
        return 0;
    }
    if (instance != NULL) {
        return 0;
    }
    instance = new TBattleProximitySound(tl_00);
    return 1;
}

#pragma push
#pragma fp_contract on
void TBattleProximitySound::run_task() {
    s32 i;
    TObjPlayer *p;
    f32 min;
    f32 d;
    f32 f;
    if (--life <= 0) {
        queue_destruction();
        return;
    }
    if (life > 0x5A) {
        if (--timer <= 0) {
            min = 2250000.0f;
            for (i = 0; i < 4; i++) {
                p = get_player_by_client_id(i);
                if (p != NULL && p != owner && !(p->actorFlags & 0x800)) {
                    d = xz_distance_squared(&owner->position, &p->position);
                    min = min < d ? min : d;
                }
            }
            f = newton_sqrtf(min) > 200.0f ? newton_sqrtf(min) : 200.0f;
            f -= 200.0f;
            min = 1.0f - 0.00076923077f * f;
            set_sound_pitch_request(play_sound_effect(0x23230, NULL, 0, 0), (256.0f * min), 0);
            timer = (s32)(-53.0f * min) + 0x3C;
        }
    }
}
#pragma pop

TBattleProximitySound::~TBattleProximitySound() {
    instance = NULL;
}

TBattleProximitySound::TBattleProximitySound(TObject *parent) : TObject(parent) {
    life = 0x3DE;
    timer = 0x1E;
    owner = get_local_player();
}
