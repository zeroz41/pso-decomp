#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "types.h"
#include "pso/unk/TLobbyEventTheme.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

TLobbyEventTheme *TLobbyEventTheme::instance;
NJS_TEXLIST *lobby_main_texture_gvm;

void TLobbyEventTheme::sub_80351DF8(s32 theme) {}

s32 TLobby::get_filtered_event_theme() {
    switch (event_theme_id) {
    case 1: case 3: case 4: case 5: case 7: case 8: case 9: case 10: case 11: case 12: case 13:
        return event_theme_id;
    }
    return 0;
}

s32 is_lobby_event_active(void) {
    return TLobby::get_filtered_event_theme() != 0;
}

s32 TLobbyEventTheme::ended() {
    if (instance != NULL) {
        return (instance->change_flags >> 2) & 1;
    }
    return 0;
}

s32 TLobbyEventTheme::started() {
    if (instance != NULL) {
        return (instance->change_flags >> 1) & 1;
    }
    return 0;
}

NJS_TEXLIST *TLobby::get_lobby_texlist() { return lobby_main_texture_gvm; }

void TLobbyEventTheme::run_task() {
    s32 current = TLobby::get_filtered_event_theme();
    change_flags &= ~(CHANGED | STARTED | ENDED);
    if (theme != current) {
        change_flags |= CHANGED;
        if (theme == 0) {
            change_flags |= STARTED;
        } else if (current == 0) {
            change_flags |= ENDED;
        }
        theme = current;
    }
    sub_80351DF8(current);
}

void TLobbyEventTheme::create() {
    instance = new TLobbyEventTheme();
}

TLobbyEventTheme::~TLobbyEventTheme() {
    queue_destruction();
    instance = NULL;
}

TLobbyEventTheme::TLobbyEventTheme() : TObject(tl_00) {
    theme = TLobby::get_filtered_event_theme();
    change_flags = 0;
}

void free_obj_lobby_main() {
    if (lobby_main_texture_gvm != NULL) {
        release_texture_list(lobby_main_texture_gvm);
        safe_free(lobby_main_texture_gvm);
        lobby_main_texture_gvm = NULL;
    }
}

void load_obj_lobby_main() {
    lobby_main_texture_gvm = load_gvm_texture_file("obj_lobby_main.GVM");
}

s32 get_theme_lobby_type() {
    s32 theme = TLobby::get_filtered_event_theme();
    switch (theme) {
    case 12:
        theme = 0;
        break;
    case 13:
        theme = 8;
        break;
    }
    return theme;
}
