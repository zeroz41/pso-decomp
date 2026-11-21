#ifndef PSO_OBJECT_SWITCH_TOCHATSENSORCAPTURE_H
#define PSO_OBJECT_SWITCH_TOCHATSENSORCAPTURE_H

#include "pso/system/task/TObject.h"
#include <stddef.h>

class TOChatSensorCapture : public TObject {
public:
    s32 lifetime[4];
    char *messages[4];

    static s32 check_keyword(u16 client, const char *keyword);
    static void capture_message(u16 client, const char *message);
    virtual void run_task();
    virtual ~TOChatSensorCapture();
    TOChatSensorCapture(TObject *parent);
    static void create_instance(void *parent);
};

LAYOUT_ASSERT(ChatCaptureSize, sizeof(TOChatSensorCapture) == 0x3C);
LAYOUT_ASSERT(ChatCaptureLifetimes, offsetof(TOChatSensorCapture, lifetime) == 0x1C);
LAYOUT_ASSERT(ChatCaptureMessages, offsetof(TOChatSensorCapture, messages) == 0x2C);
#endif
