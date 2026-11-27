#ifndef PSO_UI_WINDOW_TWINDOWSUBLOG_H
#define PSO_UI_WINDOW_TWINDOWSUBLOG_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/chat/ChatShortcut.h"
#include "pso/system/CharacterSaveRecordLookup.h"

struct TWindowMainMenu;
struct TWindowMessageLog;
class TWindowChat;
struct TWindowMessageLog;

struct TWindowSubLog : public TObject {
    TWindowSubLog(TObject *parent, s32 client);
    virtual ~TWindowSubLog();
    static const char *class_name;
    s32 client;
    TWindowMainMenu *parent_menu;
    TWindowMessageLog *log_window;
    TWindowChat *chat;
    ChatShortcut submission; // what chat writes back; run_task hands it to chat_accept_submission
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubLog_size, sizeof(TWindowSubLog) == 0x80);


// --- C functions defined in TWindowSubLog.cpp ---
// --- end of C functions

#endif
