#ifndef PSO_UI_CITY_THUNTERGUILDWARNING_H
#define PSO_UI_CITY_THUNTERGUILDWARNING_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMessage;

class THunterGuildWarning : public TObject {
public:
    THunterGuildWarning(TObject *arg1, void *arg2);
    virtual ~THunterGuildWarning();
    virtual void run_task();
public:
    static void queue_destruction();
    static void create_instance(s32 arg0);
    static u8 is_active();
    void close_windows();
    void sub_80211774(void *arg);

    s32 mode;                    // 0x1C: message set; 0 and 1 warn the local player, 2 the others
    s32 timer;                   // 0x20: frames left before the task destroys itself
    TWindowMessage *windows[4];  // 0x24: one message window per player
};

extern "C" {
void THunterGuildWarning__sub_802119CC(THunterGuildWarning *self);
void THunterGuildWarning__sub_80211700(void);
void THunterGuildWarning__sub_8021170C(void);
}

#endif
