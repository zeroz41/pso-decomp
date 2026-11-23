#ifndef PSO_OBJECT_TOBJCHALLENGERETRY_H
#define PSO_OBJECT_TOBJCHALLENGERETRY_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMessage;
struct TWindowSubComCardList;

class TObjChallengeRetry : public TObject {
public:
    s32 state;
    s32 m_20;
    s32 m_24;
    s32 countdown;
    TWindowSubComCardList *menu;
    TWindowMessage *message;

public:
    TObjChallengeRetry(TObject *parent);
    virtual ~TObjChallengeRetry();
    void sub_8007313C();
    void handle_challenge_retry_confirm();
    void update_challenge_retry();
    void handle_loss_sequence();
    void update_destroy_countdown();
    void open_loss_menu();
    void close_window_2c();
    void sub_80072BB0();
    void sub_80072B70();
    virtual void run_task();
};

#endif
