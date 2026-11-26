#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801C50A8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TBattleProximitySound.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/player/PlayerSlots.h"
#define PSO_SDK_COMPACT_MATH
#include "pso/render/NinjaUtil.h"
#undef PSO_SDK_COMPACT_MATH

    extern int duel_result_window;
TObject *ad_single_ply_chr_select_instance;
void TAdSinglePlyChrSelectGC::set_active_disconnect_count(int a0) { active_character_save_record->online_battle.disconnect_count = a0; }
u16 TAdSinglePlyChrSelectGC::get_active_disconnect_count() {
    return active_character_save_record->online_battle.disconnect_count;
}
void set_active_fourth_place_count(int value) { active_character_save_record->online_battle.place_counts[3] = value; }
u16 get_active_fourth_place_count(void) {
    return active_character_save_record->online_battle.place_counts[3];
}
void set_active_third_place_count(int value) { active_character_save_record->online_battle.place_counts[2] = value; }
u16 get_active_third_place_count(void) {
    return active_character_save_record->online_battle.place_counts[2];
}
void set_active_second_place_count(int value) { active_character_save_record->online_battle.place_counts[1] = value; }
u16 get_active_second_place_count(void) {
    return active_character_save_record->online_battle.place_counts[1];
}
void set_active_first_place_count(int value) { active_character_save_record->online_battle.place_counts[0] = value; }
u16 get_active_first_place_count(void) {
    return active_character_save_record->online_battle.place_counts[0];
}
void clear_duel_result_window(void) { duel_result_window = 0; }
void TAdSinglePlyChrSelectGC::destroy() {
    if (ad_single_ply_chr_select_instance != NULL) {
        ad_single_ply_chr_select_instance->queue_destruction();
    }
}
void clear_battle_proximity_sound(void) { ad_single_ply_chr_select_instance = NULL; }
s32 TAdSinglePlyChrSelectGC::create_if_key_pressed() {
    s32 area;
    area = get_current_floor_area();
    if ((area != AREA_BATTLE1) && (area != AREA_BATTLE2)) {
        return 0;
    }
    if (ad_single_ply_chr_select_instance != NULL) {
        return 0;
    }
    ad_single_ply_chr_select_instance = new TBattleProximitySound(tl_00);
    return 1;
}


struct Ply_801C51D4 { u8 pad[0x30]; u32 flags; u8 pad34[4]; f32 pos[3]; };

struct Self_801C51D4 { u8 pad[0x1C]; s32 life; s32 timer; Ply_801C51D4 *owner; };

extern "C" {
void *play_sound_effect(s32, s32, s32, s32, f32);

#pragma push
#pragma fp_contract on
void TBattleProximitySound::run_task() {
    Self_801C51D4 *self = (Self_801C51D4 *)this;
    s32 i;
    Ply_801C51D4 *p;
    f32 min;
    f32 d;
    f32 f;
    if (--self->life <= 0) {
        ((TObject *)self)->queue_destruction();
        return;
    }
    if (self->life > 0x5A) {
        if (--self->timer <= 0) {
            min = 2250000.0f;
            for (i = 0; i < 4; i++) {
                p = (Ply_801C51D4 *)get_player_by_client_id(i);
                if (p != NULL && p != self->owner && !(p->flags & 0x800)) {
                    d = xz_distance_squared((const Vec *)self->owner->pos, (const Vec *)p->pos);
                    min = min < d ? min : d;
                }
            }
            f = newton_sqrtf(min) > 200.0f ? newton_sqrtf(min) : 200.0f;
            f -= 200.0f;
            min = 1.0f - 0.00076923077f * f;
            set_sound_pitch_request((saddr)play_sound_effect(0x23230, 0, 0, 0, f), (256.0f * min), 0);
            self->timer = (s32)(-53.0f * min) + 0x3C;
        }
    }
}
#pragma pop

}

TBattleProximitySound::~TBattleProximitySound() {
    ad_single_ply_chr_select_instance = NULL;
}

TBattleProximitySound::TBattleProximitySound(TObject *parent) : TObject(parent) {
    life = 0x3DE;
    timer = 0x1E;
    owner = (saddr)get_local_player();
}
