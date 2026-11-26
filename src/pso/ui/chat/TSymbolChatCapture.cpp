#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/chat/TSymbolChatCapture.h"
#include "pso/ui/chat/SymbolChatCommand.h"
#include "pso/network/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

TSymbolChatCapture *slot_entity_dispatcher_instance;

void send_slot_entity_or_local(u16 slot, SymbolChatPayload *buf) {
    if (slot_entity_dispatcher_instance != NULL && slot < 4) {
        slot_entity_dispatcher_instance->get_recent_symbol_chat(slot, buf);
        return;
    }
    buf->clear();
}

void capture_slot_symbol_chat(u16 slot, SymbolChatPayload *chat) {
    if (slot_entity_dispatcher_instance != NULL && slot < 4) {
        slot_entity_dispatcher_instance->capture_symbol_chat(slot, chat);
    }
}

void TSymbolChatCapture::get_recent_symbol_chat(u16 slot, SymbolChatPayload *buf) {
    if (entries != NULL) {
        TLobby::copy_symbol_chat_entry(buf, &entries[slot]);
        return;
    }
    buf->clear();
}

void TSymbolChatCapture::capture_symbol_chat(u16 slot, SymbolChatPayload *chat) {
    if (entries != NULL) {
        s32 i = slot;
        TLobby::copy_symbol_chat_entry(&entries[i], chat);
        timers[i] = 0x78;
    }
}

void TSymbolChatCapture::run_task() {
    s32 i;
    for (i = 0; i != 4; i++) {
        if (timers[i] != 0) {
            timers[i]--;
            if (timers[i] == 0) {
                entries[i].clear();
            }
        }
    }
}

TSymbolChatCapture::~TSymbolChatCapture() {
    mem_free(entries);
    slot_entity_dispatcher_instance = NULL;
}

TSymbolChatCapture::TSymbolChatCapture(TObject *parent) : TObject(parent) {
    s32 i;
    entries = (SymbolChatPayload *)mem_alloc(4 * sizeof(SymbolChatPayload));
    if (entries != NULL) {
        for (i = 0; i != 4; i++) {
            entries[i].clear();
            timers[i] = 0;
        }
    } else {
        queue_destruction();
    }
    slot_entity_dispatcher_instance = this;
}

void TSymbolChatCapture::create_singleton(TObject *parent) {
    if (slot_entity_dispatcher_instance == NULL) {
        new TSymbolChatCapture(parent);
    }
}

void symbol_chat_capture_on_floor_free(void) {  }
void symbol_chat_capture_on_floor_load(void) {  }
