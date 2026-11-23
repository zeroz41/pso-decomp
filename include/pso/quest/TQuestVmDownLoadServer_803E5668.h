#ifndef PSO_QUEST_TQUESTVMDOWNLOADSERVER_803E5668_H
#define PSO_QUEST_TQUESTVMDOWNLOADSERVER_803E5668_H

#include "types.h"

// keyboard_soft_dispatch_fn_table handlers, named by the first request id they serve
// (0x16-0x17, 0x1E-0x1F and 0x25-0x2C share one handler each).
extern "C" {
s32 OSFillFPUContext(saddr *arg0);
s32 quest_download_request_unassigned(saddr *);
s32 quest_download_request_0x25(saddr *arg0);
s32 quest_download_request_0x24(saddr *arg0);
s32 quest_download_request_0x23(saddr *arg0);
s32 quest_download_request_0x22(saddr *arg0);
s32 quest_download_request_0x21(saddr *arg0);
s32 quest_download_request_0x20(saddr *arg0);
s32 quest_download_request_0x1E(saddr *arg0);
s32 quest_download_request_0x19(saddr *arg0);
s32 quest_download_request_0x18(saddr *arg0);
s32 quest_download_request_0x16(saddr *arg0);
}

// Request senders for the keyboard_soft_dispatch_fn_table handlers (same TU).
extern "C" {
void TWindowKeyBoardSoft__sub_803E67D4(s32 a, s32 b);
void TWindowKeyBoardSoft__sub_803E6868(s32 a, s32 b);
}

struct QuestConvertString {
    char value[0x80];
};

LAYOUT_ASSERT(QuestConvertStringSize, sizeof(QuestConvertString) == 0x80);
extern QuestConvertString quest_convert_string ATTRIBUTE_ALIGN(4);

#endif
