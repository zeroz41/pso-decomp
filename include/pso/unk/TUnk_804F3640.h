#ifndef PSO_UNK_TUNK_804F3640_H
#define PSO_UNK_TUNK_804F3640_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/chat/SymbolChatPayload.h"

// Holds the last symbol chat each of the four clients sent (handle_6x07_symbol_chat)
// for 0x78 frames; a quest creates it and reads the slots back.
class TUnk_804F3640 : public TObject {
public:
    TUnk_804F3640(TObject *parent);
    virtual ~TUnk_804F3640();
    virtual void run_task();
    void send_slot_entity(u16 slot, saddr buf);
    void start_entry_timer(u16 slot, saddr src);

    SymbolChatPayload *entries;
    s32 timers[4];
};
LAYOUT_ASSERT(TUnk_804F3640_size, sizeof(TUnk_804F3640) == 0x30);

extern TUnk_804F3640 *slot_entity_dispatcher_instance;

#endif
