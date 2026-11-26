#ifndef PSO_OBJECT_TOBJCHALLENGE4PRETRY_H
#define PSO_OBJECT_TOBJCHALLENGE4PRETRY_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMessage;
struct TWindowSubComCardList;

class TObjChallenge4PRetry : public TObject {
public:
    s32 state;
    s32 m_20;
    s32 m_24;
    s32 countdown;
    TWindowSubComCardList *menu;
    TWindowMessage *message;

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
    static void *create(TObject *parent);
};

// --- C functions defined in TLobby_80299C4C.cpp ---
u8 is_designated_client(void);
extern "C" {
s32 init_jungle_area(void);
void send_giveup_to_all_players__6TLobbyFv(void);
}
// --- end of C functions

s32 initialize_boss_scene(void);

void start_challenge_countdown();
void update_floor_state_deferred();
void update_scene_alt();

s32 is_multi_ready();

#endif
