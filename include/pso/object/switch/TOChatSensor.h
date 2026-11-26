#ifndef PSO_OBJECT_SWITCH_TOCHATSENSOR_H
#define PSO_OBJECT_SWITCH_TOCHATSENSOR_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOChatSensor : public TObjBase {
    TOChatSensor(TObject *parent, void *set_data);
    virtual ~TOChatSensor();
    u32 kind;         // rotation_x: 0 runs a quest script when the phrase is said, 1 sets a floor switch
    u16 id;
    u8 unk_96[0x2];
    u32 match_mode;   // rotation_y: 0 needs the trigger text, 1 any chat message
    f32 range_squared;  // scale.x squared: how near the local player must stand
    s32 player_inside;  // 1 while the local player is in range
    char trigger_text[0x20];  // the phrase (ChatSensor.prs text, first line)
    uaddr script_thread;  // the quest script thread it started
    u32 state;            // 0 listening, 1 its script is running
    u32 text_index;       // set_params[1]: which ChatSensor.prs text (1-based), 0 none
    static void dispatch_chat_message_to_children(saddr message);
    static void destroy_global();
    void check_player_proximity();
    void set_trigger_text(void *trigger_text);
    void handle_chat_message(void *message);
    void init_params();
    virtual void render();
    virtual void run_task();
    void send_state();
    void swap_state_endian();
    void init_packet_type();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOChatSensor_size, sizeof(TOChatSensor) == 0xD0);

#endif
