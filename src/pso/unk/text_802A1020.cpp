#include "types.h"
#include "pso/unk/text_802A1020.h"
#include "pso/unk/text_802A1144.h"
#include "pso/unk/text_802A1154.h"
#include "pso/ui/keyboard/TKeyBoardControl_802A1180.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TUnk_804DCB64.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"

typedef struct Entry_802A1020 {
    const char *file;
    u32 size;
    u32 crc;
} Entry_802A1020;

extern "C" {
u8 *set_stream_and_load_file__6TLobbyFi(const char *);
u32 get_file_size__6TLobbyFv(const char *);
s32 TKeyBoardControl__sub_8000F92C();
s32 request_queued_main_phase();
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
s8 func_801A5E54__Fv();
s32 init_fresh_character_card();
void TKeyBoardControl__sub_8000F90C(s32 arg0);
void TKeyBoardControl__sub_8000F91C(s32 arg0);
void reset_controller_input_state(void);
s32 set_copy_clear_color_argb(s32, s32, s32);
u8 *__ct__6TMovieFP7TObjectPSclll(void *, void *, const char *, void (*)(s32), s32, s32, s32);
u8 *__nw__7TObjectFUl(s32);
extern s32 lobby_cursor_active_flag;
extern s8 movie_finished_flag;
extern s32 opening_movie_selector;
extern const char lbl_80466240[]; // "ending_normal.sfd"
extern const char lbl_80466254[]; // "psogc_j.sfd"
extern const char lbl_80466260[]; // "psogc_j2.sfd"
extern const char lbl_80466270[]; // "ult01.sfd"
extern const char lbl_8046627C[]; // "ult02.sfd"
extern const char lbl_80466288[]; // "ult03.sfd"
extern const char lbl_80466294[]; // "ult04.sfd"
extern const char lbl_804662A0[]; // "ItemPMT.prs"
extern const char lbl_804662AC[]; // "itemrt.gsl"
extern const char lbl_804662B8[]; // "itempt.gsl"
extern const char lbl_804662C4[]; // "PlyLevelTbl.cpt"
}
void process_async_file_reads(void);
void update_sound_request_slots(void);
extern u8 opening_movie_purpose;

// File size and CRC-32 of the files checked by verify_game_file_integrity (crc 0: size check only).
Entry_802A1020 file_integrity_table[11] = {
    {lbl_80466240, 0x75C7800, 0},
    {lbl_80466254, 0x35FC7D8, 0},
    {lbl_80466260, 0x512229E, 0},
    {lbl_80466270, 0x15FA000, 0},
    {lbl_8046627C, 0x1940000, 0},
    {lbl_80466288, 0x1973000, 0},
    {lbl_80466294, 0x541000, 0},
    {lbl_804662A0, 0x3D39, 0x67F7CD63},
    {lbl_804662AC, 0x3F000, 0x55A2BDA0},
    {lbl_804662B8, 0xA3000, 0x976CE1D9},
    {lbl_804662C4, 0x2DFE, 0x4A62F666},
};

// [opening_movie_selector][current_language]
const char *opening_movie_path_table[10] = {
    lbl_80466254, lbl_80466254, lbl_80466254, lbl_80466254, lbl_80466254,
    lbl_80466260, lbl_80466260, lbl_80466260, lbl_80466260, lbl_80466260,
};

extern "C" {
s32 verify_game_file_integrity(void) {
    s32 i;
    u32 size;
    u8 *buf;
    u8 *p;
    u32 crc;
    s32 j;
    s32 k;
    for (i = 0; i < 11; i++) {
        size = get_file_size__6TLobbyFv(file_integrity_table[i].file);
        if (size != file_integrity_table[i].size) {
            lobby_cursor_active_flag = 1;
            return 1;
        }
        if (file_integrity_table[i].size <= 1000000) {
            buf = set_stream_and_load_file__6TLobbyFi(file_integrity_table[i].file);
            if (buf == NULL) {
                TAdSinglePlyChrSelectGC::safe_free((u32)buf);
                lobby_cursor_active_flag = 0;
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
            TAdSinglePlyChrSelectGC::safe_free((u32)buf);
            if (~crc != file_integrity_table[i].crc) {
                lobby_cursor_active_flag = 1;
                return 1;
            }
        }
    }
    lobby_cursor_active_flag = 0;
    return 0;
}
}

unsigned char get_opening_movie_purpose(void) { return opening_movie_purpose; }

void set_opening_movie_purpose(int a0) { opening_movie_purpose = a0; }

extern "C" {
void fn_802A1154(void) {
    main_task.delete_layer_children();
    render_tick();
}
}

void update_movie_phase(void) {
    controller_stuff();
    TKeyBoardControl::update_input_frame();
    main_task.begin_frame();
    main_task.run_task();
    main_task.render();
    main_task.render_screen_overlay();
    process_async_file_reads();
    update_sound_request_slots();
    TAdSinglePlyChrSelectGC::noop();
    if ((s32) (*(u8 *)&movie_finished_flag) == 1) {
        request_queued_main_phase();
    }
    if (func_801A5E54__Fv() != 0) {
        TKeyBoardControl__sub_8000F92C();
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        TKeyBoardControl__sub_8000F9CC(0);
    }
    render_tick();
}

void TKeyBoardControl::update_menu_scene() {
    set_copy_clear_color_argb(0, 0, 0);
    reset_controller_input_state();
    TKeyBoardControl__sub_8000F90C(2);
    switch ((s8) opening_movie_purpose) {
    case 0:
        TKeyBoardControl__sub_8000F91C(1);
        TKeyBoardControl__sub_8000F90C(9);
        break;
    case 1:
        TLobby::update_keyboard_menu();
        init_fresh_character_card();
        TLobby::free_keyboard_soft_resources();
        TKeyBoardControl__sub_8000F91C(5);
        break;
    }
    movie_finished_flag = 0;
    new TUnk_804DCB64;
    render_tick();
}

void TUnk_804DCB64::render() {  }
void TUnk_804DCB64::run_task() {  }
void set_movie_finished_flag(s32) { (*(unsigned char *)&movie_finished_flag) = 1; }
TUnk_804DCB64::~TUnk_804DCB64() {

}

// Plays the opening movie (or, from the lobby keyboard path, the movie of
// opening_movie_purpose) and raises movie_finished_flag when it ends.
TUnk_804DCB64::TUnk_804DCB64() : TObject(tl_01) {
    TLobby::update_menu_cursor();
    if ((TAdSinglePlyChrSelectGC::get_data() == 1) && (TAdSelectGameModeGC::get_mode_data() == 1)) {
        set_movie_finished_flag(0);
        return;
    }
    if ((s8) opening_movie_purpose == 0) {
        u8 *movie = __nw__7TObjectFUl(0x4C);
        if (movie != NULL) {
            __ct__6TMovieFP7TObjectPSclll(movie, tl_00, opening_movie_path_table[current_language + (opening_movie_selector * 5)], set_movie_finished_flag, 1, 1, 0);
        }
        opening_movie_selector = 1 - opening_movie_selector;
    } else {
        u8 *movie = __nw__7TObjectFUl(0x4C);
        if (movie != NULL) {
            __ct__6TMovieFP7TObjectPSclll(movie, tl_00, opening_movie_path_table[current_language], set_movie_finished_flag, 1, 1, 0);
        }
    }
}
