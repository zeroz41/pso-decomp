#include "pso/menu/TQuestBgmCtrl.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/quest/TQuestThread.h"

s32 TQuestBgmCtrl__bgm_issued_flag;
s32 TQuestBgmCtrl__bgm_forced_flag;
s32 TQuestBgmCtrl__area_bgm_index;
TQuestBgmCtrl* TQuestBgmCtrl__instance;
extern "C" const char* TQuestBgmCtrl__class_name;

extern s32 quest_mission_manager;
extern void *quest_bgm_area_filename_table[];

extern "C" __declspec(section ".rodata") const char quest_bgm_epi1_filename[] = "epi1.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_epi2_filename[] = "epi2.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_ed_piano_filename[] = "ED_PIANO.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_matter_filename[] = "matter.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_open_filename[] = "open.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_dreams_filename[] = "dreams.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_mambo_filename[] = "mambo.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_carnaval_filename[] = "carnaval.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_hearts_filename[] = "hearts.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_smile_filename[] = "smile.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_nomal_filename[] = "nomal.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_chu_f_filename[] = "chu_f.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_ending_loop_filename[] = "ENDING_LOOP.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_dreams_kids_filename[] = "DreamS_KIDS.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_escape_filename[] = "ESCAPE.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_live_filename[] = "LIVE.adx";
extern "C" __declspec(section ".rodata") const char quest_bgm_miles_filename[] = "MILES.adx";
extern "C" __declspec(section ".rodata") const char TQuestBgmCtrl_class_name_string[] = "TQuestBgmCtrl";
void TQuestBgmCtrl::force_bgm(int index) {
    TQuestBgmCtrl__area_bgm_index = index;
    TQuestBgmCtrl__bgm_issued_flag = 0;
    TQuestBgmCtrl__bgm_forced_flag = 1;
    if (TQuestBgmCtrl__instance != NULL) {
        TQuestBgmCtrl__instance->run_task();
    }
}

void TQuestBgmCtrl::defer_bgm(int index) {
    TQuestBgmCtrl__area_bgm_index = index;
    TQuestBgmCtrl__bgm_issued_flag = 0;
}

void TQuestBgmCtrl::run_task() {
    if (((s32) TQuestBgmCtrl__bgm_issued_flag == 0) && ((TQuestThread::get_register((u8 *)quest_mission_manager, 0xFF) != 0) || ((s32) TQuestBgmCtrl__bgm_forced_flag != 0)) && ((s32) TQuestBgmCtrl__area_bgm_index > 0) && ((s32) TQuestBgmCtrl__area_bgm_index <= 0x11)) {
        play_area_music((char *)quest_bgm_area_filename_table[TQuestBgmCtrl__area_bgm_index - 1]);
        TQuestBgmCtrl__bgm_issued_flag = 1;
    }
}

extern "C" void *quest_bgm_area_filename_table[17] = {
    (void *)&quest_bgm_epi1_filename, (void *)&quest_bgm_epi2_filename, (void *)&quest_bgm_ed_piano_filename, (void *)&quest_bgm_matter_filename,
    (void *)&quest_bgm_open_filename, (void *)&quest_bgm_dreams_filename, (void *)&quest_bgm_mambo_filename, (void *)&quest_bgm_carnaval_filename,
    (void *)&quest_bgm_hearts_filename, (void *)&quest_bgm_smile_filename, (void *)&quest_bgm_nomal_filename, (void *)&quest_bgm_chu_f_filename,
    (void *)&quest_bgm_ending_loop_filename, (void *)&quest_bgm_dreams_kids_filename, (void *)&quest_bgm_escape_filename, (void *)&quest_bgm_live_filename,
    (void *)&quest_bgm_miles_filename,
};

TQuestBgmCtrl::~TQuestBgmCtrl() {
    TQuestBgmCtrl__bgm_issued_flag = 0;
    TQuestBgmCtrl__bgm_forced_flag = 0;
    TQuestBgmCtrl__area_bgm_index = 0;
    TQuestBgmCtrl__instance = 0;
}

TQuestBgmCtrl::TQuestBgmCtrl(TObject* parent) : TObject(parent) {
    m_name = TQuestBgmCtrl__class_name;
    TQuestBgmCtrl__bgm_issued_flag = 0;
    TQuestBgmCtrl__bgm_forced_flag = 0;
    TQuestBgmCtrl__area_bgm_index = 0;
    TQuestBgmCtrl__instance = this;
}

extern "C" const char* TQuestBgmCtrl__class_name = TQuestBgmCtrl_class_name_string;
