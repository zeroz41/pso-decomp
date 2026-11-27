#ifndef PSO_UI_CITY_THUNTERGUILDWARNING_H
#define PSO_UI_CITY_THUNTERGUILDWARNING_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMessage;
class TObjPlayer;

class THunterGuildWarning : public TObject {
public:
    static THunterGuildWarning * instance;
    THunterGuildWarning(TObject *object, s32 initial_mode);
    virtual ~THunterGuildWarning();
    virtual void run_task();
public:
    static void queue_destruction();
    static void create_instance(s32 mode);
    static s32 is_active();
    static s32 get_party_not_ready_reason(s32 client_id);
    void close_windows();
    void open_warning_windows(s32 unused);

    s32 mode;                    // 0x1C: message set; 0 and 1 warn the local player, 2 the others
    s32 timer;                   // 0x20: frames left before the task destroys itself
    TWindowMessage *windows[4];  // 0x24: one message window per player
};

void update_hunter_guild_phase();

void clear_windows(THunterGuildWarning *warning);
void clear_guild_warning_on_guild_exit(void);
void clear_guild_warning_on_quest_exit(void);

s32 get_guild_quest_list_stage(void);
s32 is_in_hunter_guild(s32 client_id);

void *create_lobby_object_05(TObjPlayer *player);
s32 handle_main_phase(saddr player);

#endif
