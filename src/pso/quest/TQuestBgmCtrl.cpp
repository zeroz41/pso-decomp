#include "pso/unk/TQuestManager.h"
#include "pso/quest/TQuestBgmCtrl.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/quest/TQuestThread.h"

s32 quest_bgm_ctrl_bgm_issued_flag;
s32 quest_bgm_ctrl_bgm_forced_flag;
s32 quest_bgm_ctrl_area_bgm_index;
TQuestBgmCtrl* quest_bgm_ctrl_instance;
extern "C" const char* quest_bgm_ctrl_class_name;

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
    quest_bgm_ctrl_area_bgm_index = index;
    quest_bgm_ctrl_bgm_issued_flag = 0;
    quest_bgm_ctrl_bgm_forced_flag = 1;
    if (quest_bgm_ctrl_instance != NULL) {
        quest_bgm_ctrl_instance->run_task();
    }
}

void TQuestBgmCtrl::defer_bgm(int index) {
    quest_bgm_ctrl_area_bgm_index = index;
    quest_bgm_ctrl_bgm_issued_flag = 0;
}

void TQuestBgmCtrl::run_task() {
    if ((quest_bgm_ctrl_bgm_issued_flag == 0) && ((TQuestThread::get_register(quest_mission_manager, 0xFF) != 0) || (quest_bgm_ctrl_bgm_forced_flag != 0)) && (quest_bgm_ctrl_area_bgm_index > 0) && (quest_bgm_ctrl_area_bgm_index <= 0x11)) {
        play_area_music((char *)quest_bgm_area_filename_table[quest_bgm_ctrl_area_bgm_index - 1]);
        quest_bgm_ctrl_bgm_issued_flag = 1;
    }
}

void *quest_bgm_area_filename_table[17] = {
    (void *)&quest_bgm_epi1_filename, (void *)&quest_bgm_epi2_filename, (void *)&quest_bgm_ed_piano_filename, (void *)&quest_bgm_matter_filename,
    (void *)&quest_bgm_open_filename, (void *)&quest_bgm_dreams_filename, (void *)&quest_bgm_mambo_filename, (void *)&quest_bgm_carnaval_filename,
    (void *)&quest_bgm_hearts_filename, (void *)&quest_bgm_smile_filename, (void *)&quest_bgm_nomal_filename, (void *)&quest_bgm_chu_f_filename,
    (void *)&quest_bgm_ending_loop_filename, (void *)&quest_bgm_dreams_kids_filename, (void *)&quest_bgm_escape_filename, (void *)&quest_bgm_live_filename,
    (void *)&quest_bgm_miles_filename,
};

TQuestBgmCtrl::~TQuestBgmCtrl() {
    quest_bgm_ctrl_bgm_issued_flag = 0;
    quest_bgm_ctrl_bgm_forced_flag = 0;
    quest_bgm_ctrl_area_bgm_index = 0;
    quest_bgm_ctrl_instance = 0;
}

TQuestBgmCtrl::TQuestBgmCtrl(TObject* parent) : TObject(parent) {
    m_name = quest_bgm_ctrl_class_name;
    quest_bgm_ctrl_bgm_issued_flag = 0;
    quest_bgm_ctrl_bgm_forced_flag = 0;
    quest_bgm_ctrl_area_bgm_index = 0;
    quest_bgm_ctrl_instance = this;
}

extern "C" const char* quest_bgm_ctrl_class_name = TQuestBgmCtrl_class_name_string;
