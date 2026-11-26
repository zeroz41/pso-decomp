#include "types.h"
#include "pso/unk/TDeferredRenderQueue.h"

// Own TU: the .data vtable starts 8-aligned after TAdEnterPasswordGC's vtable and its 4-byte pad,
// the .sbss instance pointer starts 8-aligned after TAdEnterPasswordGC's PMF guard, and every function of this unit
// works on this object.

TDeferredRenderQueue *TDeferredRenderQueue::instance;

void TDeferredRenderQueue::clear_queue() {
    s32 i;
    for (i = 0; i < 24; i++) {
        queued[i] = NULL;
    }
    queued_count = 0;
}

void TDeferredRenderQueue::render_queued() {
    s32 i;
    for (i = 0; i < queued_count; i++) {
        if (queued[i] != NULL && queued[i]->all_parents_unqueued_for_destruction() != 0) {
            queued[i]->render();
        }
    }
}

void TDeferredRenderQueue::enqueue(TObject *object) {
    if (queued_count < 24) {
        queued[queued_count] = object;
        queued_count++;
    }
}

s32 TDeferredRenderQueue::enqueue_in_instance(TObject *object) {
    if (TDeferredRenderQueue::instance != NULL) {
        if (TDeferredRenderQueue::instance->is_rendering() != 0) {
            return 0;
        }
        TDeferredRenderQueue::instance->enqueue(object);
        return 1;
    }
    return 0;
}

void TDeferredRenderQueue::render() {
    rendering = 1;
    render_queued();
    rendering = 0;
    clear_queue();
}

TDeferredRenderQueue::~TDeferredRenderQueue() {
    instance = NULL;
}

TDeferredRenderQueue::TDeferredRenderQueue(TObject *parent) : TObject(parent) {
    s32 i;
    queued_count = 0;
    instance = this;
    for (i = 0; i < 24; i++) {
        queued[i] = NULL;
    }
    rendering = 0;
}

void TLobby__sub_8032BE30(void) { TDeferredRenderQueue::instance = NULL; }

void TLobby__sub_8032BE3C(void) { TDeferredRenderQueue::instance = NULL; }

s32 TDeferredRenderQueue::is_rendering() { return rendering; }
