#ifndef PSO_OBJECT_TOBJCHALLENGERETRY_H
#define PSO_OBJECT_TOBJCHALLENGERETRY_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMessage;
struct TWindowSubComCardList;

class TObjChallengeRetry : public TObject {
public:
    s32 state;
    s32 is_designated;  // is_designated_client(), refreshed every frame
    s32 selection_sent;  // set once the retry choice went out
    s32 countdown;
    TWindowSubComCardList *menu;
    TWindowMessage *message;

public:
    TObjChallengeRetry(TObject *parent);
    virtual ~TObjChallengeRetry();
    static TObjChallengeRetry *create(TObject *parent);
    void sub_8007313C();
    void handle_challenge_retry_confirm();
    void update_challenge_retry();
    void handle_loss_sequence();
    void update_destroy_countdown();
    void open_loss_menu();
    void close_window_2c();
    void open_message();
    void close_message();
    // Hides the local player's window slot, then play_player_default_effect.
    void show_ctrl_and_play_effect();
    // Disables the local client's main menu, then play_player_default_effect.
    void play_default_effect();
    // Puts the local player on hold (send_impose_hold) unless it already is.
    void play_player_default_effect();
    s32 is_designated_client();
    void send_45_and_close_windows();
    virtual void run_task();
};

s32 is_ready_to_draw();

#endif
