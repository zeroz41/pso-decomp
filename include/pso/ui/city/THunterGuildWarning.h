#ifndef PSO_UI_CITY_THUNTERGUILDWARNING_H
#define PSO_UI_CITY_THUNTERGUILDWARNING_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMessage;

class THunterGuildWarning : public TObject {
public:
    static THunterGuildWarning * instance;
    THunterGuildWarning(TObject *object, void *initial_mode);
    virtual ~THunterGuildWarning();
    virtual void run_task();
public:
    static void queue_destruction();
    static void create_instance(saddr mode);
    static s32 is_active();
    void close_windows();
    void open_warning_windows(void *unused);

    saddr mode;                    // 0x1C: message set; 0 and 1 warn the local player, 2 the others
    s32 timer;                   // 0x20: frames left before the task destroys itself
    TWindowMessage *windows[4];  // 0x24: one message window per player
};

void update_hunter_guild_phase();

void clear_windows(THunterGuildWarning *warning);
extern "C" {
void THunterGuildWarning__sub_80211700(void);
void THunterGuildWarning__sub_8021170C(void);
}

extern "C" {
s32 TLobby__sub_80211C3C(void);
}
s32 is_in_hunter_guild(s32 client_id);

#endif
