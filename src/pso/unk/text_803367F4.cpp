#include "types.h"

// Mirror of TLobby state-handler members (era names open_keyboard__6TLobbyFv
// etc. — file-local mirror only, shared header untouched; A41C precedent).
class TLobby {
public:
    void open_keyboard();
    void request_change_game_mode();
    void enter_game_mode_change();
    void enter_chg_game_mode();
};

typedef void (TLobby::*TLobbyStateHandler)();

extern "C" {
extern const char lbl_80477668[];
extern const char lbl_80477670[];
extern const char lbl_80477680[];
extern const char lbl_80477690[];
extern const char lbl_804776A4[];
extern const char lbl_804776B8[];
extern const char lbl_804776CC[];
extern const char lbl_804776E0[];
extern const char lbl_804776F4[];
extern const char lbl_80477708[];
extern const char lbl_8047771C[];
extern const char lbl_80477730[];
extern const char lbl_80477740[];
extern const char lbl_80477750[];
extern const char lbl_80477764[];
extern const char lbl_80477778[];
extern const char lbl_8047778C[];
extern const char lbl_804777A0[];
extern const char lbl_804777B4[];
extern const char lbl_804777C8[];
extern const char lbl_804777DC[];
extern void TLobby__sub_80335E74(void);
extern void TLobby__sub_80335E78(void);
extern void TLobby__sub_80335FE0(void);
extern void TLobby__sub_80335FE4(void);
extern void TLobby__sub_80336E44(void);
extern void clear_lobby_global_flags__Fv(void);
extern void TLobby__sub_80336E64(void);
extern void TLobby__sub_80336E68(void);
}

struct TitleTextureEntry {
    const char* name;
    s32 field4;
    s32 field8;
};

struct TitleTextureList {
    TitleTextureEntry* entries;
    s32 count;
};

typedef void (*TLobbyLoadCallback)(void);

// One file-scope blob so every member lands in .data (a lone 8-byte global
// would be routed to .sdata and shift the blob tails by -8).
struct TitleLobbyBootData {
    TitleTextureEntry entries[21];
    TitleTextureList list;
};

TitleLobbyBootData title_texture_entries = {
    {
        {lbl_80477668, 0, 0},
        {lbl_80477670, 0, 0},
        {lbl_80477680, 0, 0},
        {lbl_80477690, 0, 0},
        {lbl_804776A4, 0, 0},
        {lbl_804776B8, 0, 0},
        {lbl_804776CC, 0, 0},
        {lbl_804776E0, 0, 0},
        {lbl_804776F4, 0, 0},
        {lbl_80477708, 0, 0},
        {lbl_8047771C, 0, 0},
        {lbl_80477730, 0, 0},
        {lbl_80477740, 0, 0},
        {lbl_80477750, 0, 0},
        {lbl_80477764, 0, 0},
        {lbl_80477778, 0, 0},
        {lbl_8047778C, 0, 0},
        {lbl_804777A0, 0, 0},
        {lbl_804777B4, 0, 0},
        {lbl_804777C8, 0, 0},
        {lbl_804777DC, 0, 0},
    },
    {(TitleTextureEntry*)&title_texture_entries, 21},
};

TLobbyLoadCallback lobby_load_callback_table[8] = {
    TLobby__sub_80335E78,
    TLobby__sub_80335E74,
    clear_lobby_global_flags__Fv,
    TLobby__sub_80336E44,
    TLobby__sub_80335FE4,
    TLobby__sub_80335FE0,
    TLobby__sub_80336E68,
    TLobby__sub_80336E64,
};

TLobbyStateHandler TLobby__state_handler_pmf_table[4] = {
    &TLobby::enter_chg_game_mode,
    &TLobby::enter_game_mode_change,
    &TLobby::request_change_game_mode,
    &TLobby::open_keyboard,
};
