#include "pso/system/ControllerInput.h"
#include "pso/system/memory.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/ui/frontend/OpeningMovie.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/frontend/TOpeningMovie.h"
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_CardSequence.h"
#include "pso/ui/Language.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/audio/SoundRequests.h"
#include "pso/audio/MusicControl.h"
#include "pso/system/AsyncFileRead.h"
#include "pso/system/movie/TMovie.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/ui/TCharSaveSequence.h"
#include "pso/system/MallocLoadFilePrc.h"


s32 opening_movie_selector = 1;
s8 movie_finished_flag;
s8 opening_movie_purpose;
s32 game_files_modified_flag;

// File size and CRC-32 of the files checked by verify_game_file_integrity (crc 0: size check only).
FileIntegrityEntry file_integrity_table[11] = {
    {"ending_normal.sfd", 0x75C7800, 0},
    {"psogc_j.sfd", 0x35FC7D8, 0},
    {"psogc_j2.sfd", 0x512229E, 0},
    {"ult01.sfd", 0x15FA000, 0},
    {"ult02.sfd", 0x1940000, 0},
    {"ult03.sfd", 0x1973000, 0},
    {"ult04.sfd", 0x541000, 0},
    {"ItemPMT.prs", 0x3D39, 0x67F7CD63},
    {"itemrt.gsl", 0x3F000, 0x55A2BDA0},
    {"itempt.gsl", 0xA3000, 0x976CE1D9},
    {"PlyLevelTbl.cpt", 0x2DFE, 0x4A62F666},
};

// [opening_movie_selector][current_language]
const char *opening_movie_path_table[10] = {
    "psogc_j.sfd", "psogc_j.sfd", "psogc_j.sfd", "psogc_j.sfd", "psogc_j.sfd",
    "psogc_j2.sfd", "psogc_j2.sfd", "psogc_j2.sfd", "psogc_j2.sfd", "psogc_j2.sfd",
};


s32 verify_game_file_integrity(void) {
    s32 i;
    u32 size;
    u8 *buf;
    u8 *p;
    u32 crc;
    s32 j;
    s32 k;
    for (i = 0; i < 11; i++) {
        size = get_disc_file_size(file_integrity_table[i].file);
        if (size != file_integrity_table[i].size) {
            game_files_modified_flag = 1;
            return 1;
        }
        if (file_integrity_table[i].size <= 1000000) {
            buf = load_disc_file(file_integrity_table[i].file);
            if (buf == NULL) {
                safe_free(buf);
                game_files_modified_flag = 0;
                return 0;
            }
            crc = 0xFFFFFFFF;
            for (j = 0; j < (s32)size; j++) {
                crc ^= buf[j] << 24;
                for (k = 0; k < 8; k++) {
                    if (crc & 0x80000000) {
                        crc = (crc << 1) ^ 0x04C11DB7;
                    } else {
                        crc = crc << 1;
                    }
                }
            }
            safe_free(buf);
            if (~crc != file_integrity_table[i].crc) {
                game_files_modified_flag = 1;
                return 1;
            }
        }
    }
    game_files_modified_flag = 0;
    return 0;
}

s8 get_opening_movie_purpose(void) { return opening_movie_purpose; }

void set_opening_movie_purpose(int a0) { opening_movie_purpose = a0; }


void exit_movie_phase(void) {
    main_task.delete_layer_children();
    render_tick();
}

void update_movie_phase(void) {
    controller_stuff();
    update_keyboard_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    noop();
    if (movie_finished_flag == 1) {
        request_queued_main_phase();
    }
    if (static_cast<s8>(poll_reset_request()) != 0) {
        switch_to_fallback_main_phase();
    }
    if (is_ready() != 0) {
        request_main_phase(0);
    }
    render_tick();
}

void init_movie_phase(void) {
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    set_fallback_main_phase(2);
    switch (opening_movie_purpose) {
    case 0:
        set_queued_main_phase(1);
        set_fallback_main_phase(9);
        break;
    case 1:
        update_keyboard_menu();
        init_fresh_character_card();
        free_keyboard_soft_resources();
        set_queued_main_phase(5);
        break;
    }
    movie_finished_flag = 0;
    new TOpeningMovie;
    render_tick();
}

void TOpeningMovie::render() {  }
void TOpeningMovie::run_task() {  }
void set_movie_finished_flag(TMovie *) { movie_finished_flag = 1; }
TOpeningMovie::~TOpeningMovie() {

}

// Plays the opening movie (or, from the lobby keyboard path, the movie of
// opening_movie_purpose) and raises movie_finished_flag when it ends.
TOpeningMovie::TOpeningMovie() : TObject(tl_01) {
    update_menu_cursor();
    if ((TAdSinglePlyChrSelectGC::get_data() == 1) && (TAdSelectGameModeGC::get_mode_data() == 1)) {
        set_movie_finished_flag(NULL);
        return;
    }
    if (opening_movie_purpose == 0) {
        new TMovie(tl_00, opening_movie_path_table[current_language + (opening_movie_selector * 5)], set_movie_finished_flag, 1, 1, 0);
        opening_movie_selector = 1 - opening_movie_selector;
    } else {
        new TMovie(tl_00, opening_movie_path_table[current_language], set_movie_finished_flag, 1, 1, 0);
    }
}

int TAdSelectGameModeGC::get_mode_data() { return TAdSelectGameModeGC::cached_mode_value; }
