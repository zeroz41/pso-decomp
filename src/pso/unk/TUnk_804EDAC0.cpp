#include "types.h"
#include "pso/unk/TUnk_804EDAC0.h"

// Own TU: the .data vtable at 0x804EDAC0 starts 8-aligned after TAdEnterPasswordGC's vtable and its 4-byte pad,
// the .sbss instance pointer starts 8-aligned after TAdEnterPasswordGC's PMF guard, and every function from
// 0x8032BBF0 to 0x8032BE50 works on this object.

TUnk_804EDAC0 *TUnk_804EDAC0::instance;

void TUnk_804EDAC0::clear_password() {
    s32 i;
    for (i = 0; i < 24; i++) {
        queued[i] = NULL;
    }
    queued_count = 0;
}

void TUnk_804EDAC0::update_children() {
    s32 i;
    for (i = 0; i < queued_count; i++) {
        if (queued[i] != NULL && queued[i]->all_parents_unqueued_for_destruction() != 0) {
            queued[i]->render();
        }
    }
}

void TUnk_804EDAC0::sub_8032BC94(TObject *object) {
    if (queued_count < 24) {
        queued[queued_count] = object;
        queued_count++;
    }
}

s32 TUnk_804EDAC0::dispatch_input_to_instance(TObject *object) {
    if (TUnk_804EDAC0::instance != NULL) {
        if (TUnk_804EDAC0::instance->get_confirm_state() != 0) {
            return 0;
        }
        TUnk_804EDAC0::instance->sub_8032BC94(object);
        return 1;
    }
    return 0;
}

void TUnk_804EDAC0::render() {
    rendering = 1;
    update_children();
    rendering = 0;
    clear_password();
}

TUnk_804EDAC0::~TUnk_804EDAC0() {
    instance = NULL;
}

TUnk_804EDAC0::TUnk_804EDAC0(TObject *parent) : TObject(parent) {
    s32 i;
    queued_count = 0;
    instance = this;
    for (i = 0; i < 24; i++) {
        queued[i] = NULL;
    }
    rendering = 0;
}

void TLobby__sub_8032BE30(void) { TUnk_804EDAC0::instance = NULL; }

void TLobby__sub_8032BE3C(void) { TUnk_804EDAC0::instance = NULL; }

s32 TUnk_804EDAC0::get_confirm_state() { return rendering; }
