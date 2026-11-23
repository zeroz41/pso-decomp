#ifndef PSO_UI_CHAT_TSYMBOLCHATCAPTURE_H
#define PSO_UI_CHAT_TSYMBOLCHATCAPTURE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/chat/SymbolChatPayload.h"

// Holds the last symbol chat each of the four clients sent (handle_6x07_symbol_chat)
// for 0x78 frames; a quest creates it and reads the slots back.
class TSymbolChatCapture : public TObject {
public:
    TSymbolChatCapture(TObject *parent);
    virtual ~TSymbolChatCapture();
    virtual void run_task();
    void get_recent_symbol_chat(u16 slot, saddr buf);
    void capture_symbol_chat(u16 slot, saddr src);

    SymbolChatPayload *entries;
    s32 timers[4];
};
LAYOUT_ASSERT(TSymbolChatCapture_size, sizeof(TSymbolChatCapture) == 0x30);

extern TSymbolChatCapture *slot_entity_dispatcher_instance;

#endif
