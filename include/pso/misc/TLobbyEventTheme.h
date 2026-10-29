#ifndef PSO_MISC_TLOBBYEVENTTHEME_H
#define PSO_MISC_TLOBBYEVENTTHEME_H

#include "types.h"
#include "pso/TObject.h"
#include "pso/system/GinjaTexture.h"

// The lobby task that follows TLobby's event theme (TLobby::get_filtered_event_theme)
// and flags, for the frame it changes, whether an event started or ended. The
// lobby objects poll started() / ended() to show or hide themselves.
class TLobbyEventTheme : public TObject {
public:
    enum {
        CHANGED = 1 << 0,
        STARTED = 1 << 1,
        ENDED = 1 << 2,
    };

    TLobbyEventTheme();
    virtual ~TLobbyEventTheme();
    virtual void run_task();

    void sub_80351DF8(s32 theme);

    static void create();
    static s32 ended();
    static s32 started();

    static TLobbyEventTheme *instance;

    u32 change_flags;
    s32 theme;
};
typedef char TLobbyEventTheme_size[sizeof(TLobbyEventTheme) == 0x24 ? 1 : -1];

// The lobby texture list (obj_lobby_main.GVM), loaded and freed with the lobby.
extern GinjaTextureList *lobby_main_texture_gvm;

void load_obj_lobby_main();
void free_obj_lobby_main();
s32 get_theme_lobby_type();

extern "C" {
s32 is_lobby_event_active(void);
}

#endif
