#ifndef PSO_OBJECT_SWITCH_TOCHATSENSOR_H
#define PSO_OBJECT_SWITCH_TOCHATSENSOR_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOChatSensor : public TObjBase {
    TOChatSensor(TObject *parent, ObjectSetData *set_data);
    virtual ~TOChatSensor();
    u32 kind;         // rotation_x: 0 runs a quest script when the phrase is said, 1 sets a floor switch
    union {
        s32 script_label;  // kind 0: set_params[0], the quest label its script thread runs
        u16 switch_id;     // kind 1: set_params[0], the floor switch it sets (0xFFFF when over 0x100)
    };
    u32 match_mode;   // rotation_y: 0 needs the trigger text, 1 any chat message
    f32 range_squared;  // scale.x squared: how near the local player must stand
    s32 player_inside;  // 1 while the local player is in range
    char trigger_text[0x20];  // the phrase (ChatSensor.prs text, first line)
    TObject *script_thread;  // the quest script thread it started
    s32 state;            // 0 listening, 1 its script is running
    s32 text_index;       // set_params[1]: which ChatSensor.prs text (1-based), 0 none
    static void dispatch_chat_message_to_children(char *message);
    static void destroy_global();
    void check_player_proximity();
    void set_trigger_text(const char *trigger_text);
    void handle_chat_message(char *message);
    void init_params();
    virtual void render();
    virtual void run_task();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TOChatSensor_size, sizeof(TOChatSensor) == 0xD0);

void chat_sensor_on_floor_free(void);
void chat_sensor_on_floor_load(void);

void load_chat_sensor();
// ChatSensor.prs: how many trigger texts there are and the texts (a sensor's text_index picks one, from 1).
struct ChatSensorTable {
    s32 count;
    char **texts;
};

#endif
