#ifndef PSO_UI_WINDOW_TWINDOWOPTIONCTRL_H
#define PSO_UI_WINDOW_TWINDOWOPTIONCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"
class TWindowMessageYesNo;

class TAdPlayerLoadGC;
class TWindowBase;
class TWindowMenuIconLine;
struct TWindowMenu;
struct TWindowSoundBalance;
struct TWindowSnapShot;
struct TWindowMessageYesNo;
class TSnapshotFileSetup;
struct TWindowSoundBalance;
struct TWindowSnapShot;
struct NJS_POINT2;
class TWindowCheckBox;

struct TWindowOptionCtrl : public TObject {
    TWindowOptionCtrl(TObject *parent);
    virtual ~TWindowOptionCtrl();
    s8 state;
    u8 flags;
    s16 saved_sound_mode; // the sound output mode when the window opened
    s16 sound_mode;
    u8 pad_22[0x2];
    s32 dial_selection; // read by TAdDialingSelectGC: 1 network setup, 3 license purchase (web mode), 4 none
    TWindowMenu *main_menu;
    TWindowMenu *sub_menu;
    TWindowMenu *confirm_menu;
    TWindowCheckBox *option_menu;
    TWindowSoundBalance *sound_balance_window;
    TWindowSnapShot *snap_shot_window;
    TWindowMessageYesNo *yes_no_window;
    TWindowBase *serial_info_window;
    TSnapshotFileSetup *card_format_dialog;
    TAdPlayerLoadGC *player_load; // memory-card watcher made by the ctor

    static const char *class_name;
    void set_sound_balance(s16 music_gain, s16 sound_effect_gain);
    void apply_selection_change();
    void init_selection_indices();
    void apply_and_close(s32 bgm_index);
    s32 handle_input(s32 language);
    s32 get_dial_selection();
    int is_finished();
    static void set_udp_option(s32 unused, s16 option);
    static s32 get_udp_option(); // 0 auto, 1 UDP on, 2 UDP off
    static const char *text_or_default(const char *text);
    static saddr create_serial_info_window(const NJS_POINT2 *pos, s32 kind);
    TWindowMessageYesNo *open_yes_no_window(s32 message_id, s32 index);
    TWindowCheckBox *create_udp_option_menu();
    saddr create_sub_menu_window();
    TWindowSnapShot *create_snap_shot_window();
    TWindowSoundBalance *create_sound_balance_window();
    TWindowCheckBox *create_sound_mode_menu();
    saddr create_list_window();
    TWindowCheckBox *create_select_menu_window();
    saddr create_menu();
    virtual void render();
    virtual void run_task();
    static saddr get_chr_select_base_plus_1154c();
    static const NJS_POINT2 *get_option_entry(int a0);
};

LAYOUT_ASSERT(TWindowOptionCtrl_size, sizeof(TWindowOptionCtrl) == 0x50);
#endif
