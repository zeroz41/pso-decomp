#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/system/SoundEffect.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/boss/galgryphon/TObjBoss5FloorGrass.h"
#include "pso/boss/galgryphon/TObjBoss5FloorStone.h"
#include "pso/boss/galgryphon/TObjBoss5PillarCtrl.h"
#include "pso/player/TObjPlayer_80011014.h"

#pragma readonly_strings on
#pragma fp_contract on


extern "C" {
s32 is_room_enemy_set_cleared(s32, s32);
const char *lbl_805D2828 = "TObjBoss5Ctrl";
}

void TObjBoss5Ctrl::run_task() {
    if (sound_countdown-- <= 0) {
        play_sound_effect(0x40033215, NULL, 0, 0);
        sound_countdown = (s16)(60.0f * ((1.0f / 32768.0f) * (f32)rand()) + 90.0f);
    }
}

TObjBoss5Ctrl::~TObjBoss5Ctrl() {
    if (pillar_demo != NULL) {
        pillar_demo->queue_destruction();
        pillar_demo = NULL;
    }
    if (pillar_controller != NULL) {
        pillar_controller->queue_destruction();
        pillar_controller = NULL;
    }
    if (floor_stone != NULL) {
        floor_stone->queue_destruction();
        floor_stone = NULL;
    }
    if (floor_grass != NULL) {
        floor_grass->queue_destruction();
        floor_grass = NULL;
    }
    boss5_ctrl_instance = NULL;
}

TObjBoss5Ctrl::TObjBoss5Ctrl(TObject *parent) : TObject(parent) {
    m_name = lbl_805D2828;
    floor_grass = NULL;
    floor_stone = NULL;
    pillar_controller = NULL;
    pillar_demo = NULL;
    sound_countdown = (s16)(60.0f * ((1.0f / 32768.0f) * (f32)rand()) + 90.0f);
    if (is_room_enemy_set_cleared(get_current_floor(), 1) == 0) {
        if (is_split_screen() == 0) {
            if (floor_grass == NULL) {
                floor_grass = (TObject *)TObjBoss5FloorGrass::create();
            }
            if (floor_stone == NULL) {
                floor_stone = (TObjBoss5FloorStone *)TObjBoss5FloorStone::create();
            }
            if (pillar_controller == NULL) {
                pillar_controller = TObjBoss5PillarCtrl::create(this);
            }
        }
        if (pillar_demo == NULL) {
            pillar_demo = TObjBoss5PillarDemo::create();
        }
    }
}
