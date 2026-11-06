#ifndef PSO_OBJECT_TOBJCHALLENGE4PRETRY_H
#define PSO_OBJECT_TOBJCHALLENGE4PRETRY_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjChallenge4PRetry : public TObject {
public:
 u8 _pad1c[0x04];
 s32 m_20;
 s32 m_24;

public:
    TObjChallenge4PRetry(TObject *parent);
    virtual ~TObjChallenge4PRetry();
    void update_giveup();
    void update_challenge_4p_retry();
    void handle_retry_menu_select();
    void countdown_and_destroy();
    void open_giveup_window();
    void close_window();
    void open_message_window();
    void close_window_field30();
    virtual void run_task();
public:
    static void *create(void *arg0);
};

#endif
