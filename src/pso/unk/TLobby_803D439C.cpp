#include "types.h"
#include "pso/unk/TLobby_803D439C.h"

extern s32 mfci_error_callback;
extern s32 mfci_error_callback_context;

void mfci_set_error_callback(s32 arg0, s32 arg1) {
    mfci_error_callback = arg0;
    mfci_error_callback_context = arg1;
}
