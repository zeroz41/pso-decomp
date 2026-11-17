#ifndef PSO_QUEST_TQUESTVMDOWNLOADSERVER_803E5668_H
#define PSO_QUEST_TQUESTVMDOWNLOADSERVER_803E5668_H

#include "types.h"

// keyboard_soft_dispatch_fn_table handlers, named by the first request id they serve
// (0x16-0x17, 0x1E-0x1F and 0x25-0x2C share one handler each).
extern "C" {
s32 OSFillFPUContext(s32 *arg0);
s32 quest_download_request_unassigned(s32 *);
s32 quest_download_request_0x25(s32 *arg0);
s32 quest_download_request_0x24(s32 *arg0);
s32 quest_download_request_0x23(s32 *arg0);
s32 quest_download_request_0x22(s32 *arg0);
s32 quest_download_request_0x21(s32 *arg0);
s32 quest_download_request_0x20(s32 *arg0);
s32 quest_download_request_0x1E(s32 *arg0);
s32 quest_download_request_0x19(s32 *arg0);
s32 quest_download_request_0x18(s32 *arg0);
s32 quest_download_request_0x16(s32 *arg0);
}

// Request senders for the keyboard_soft_dispatch_fn_table handlers (same TU).
extern "C" {
void TWindowKeyBoardSoft__sub_803E67D4(s32 a, s32 b);
void TWindowKeyBoardSoft__sub_803E6868(s32 a, s32 b);
}

// quest_convert_string: layout known from its uses only.
struct QuestConvertString { s32 value; u8 remaining[0x7C]; };
extern QuestConvertString quest_convert_string;

#endif
