#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/chat/TSymbolChatCapture.h"
#include "pso/unk/text_80076E84.h"
#include "pso/unk/TLobby_8036B204.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

extern "C" {
s32 TLobby__sub_8036B1AC(saddr payload);
}

TSymbolChatCapture *slot_entity_dispatcher_instance;

void TLobby::send_slot_entity_or_local(u16 slot, s32 buf) {
    if (slot_entity_dispatcher_instance != NULL && slot < 4) {
        slot_entity_dispatcher_instance->get_recent_symbol_chat(slot, buf);
        return;
    }
    TLobby__sub_8036B1AC(buf);
}

void TLobby::dispatch_by_index(u16 slot, int src) {
    if (slot_entity_dispatcher_instance != NULL && slot < 4) {
        slot_entity_dispatcher_instance->capture_symbol_chat(slot, src);
    }
}

void TSymbolChatCapture::get_recent_symbol_chat(u16 slot, saddr buf) {
    if (entries != NULL) {
        TLobby::copy_symbol_chat_entry((void *)buf, &entries[slot]);
        return;
    }
    TLobby__sub_8036B1AC(buf);
}

void TSymbolChatCapture::capture_symbol_chat(u16 slot, saddr src) {
    if (entries != NULL) {
        s32 i = slot;
        TLobby::copy_symbol_chat_entry(&entries[i], (void *)src);
        timers[i] = 0x78;
    }
}

void TSymbolChatCapture::run_task() {
    s32 i;
    for (i = 0; i != 4; i++) {
        if (timers[i] != 0) {
            timers[i]--;
            if (timers[i] == 0) {
                TLobby__sub_8036B1AC((saddr)&entries[i]);
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
            TLobby__sub_8036B1AC((saddr)&entries[i]);
            timers[i] = 0;
        }
    } else {
        queue_destruction();
    }
    slot_entity_dispatcher_instance = this;
}

void TLobby::create_singleton(void *parent) {
    if (slot_entity_dispatcher_instance == NULL) {
        new TSymbolChatCapture((TObject *)parent);
    }
}

void TLobby__sub_8036B50C(void) {  }
void TLobby__sub_8036B510(void) {  }
