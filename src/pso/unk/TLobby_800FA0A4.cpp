#include "pso/unk/TLobby.h"
#include "pso/unk/text_800FA464.h"

void TLobby::notify_and_close() {
    s32 *completion = async_file_read_current_request->completion;
    if (completion != NULL) {
        *completion = 1;
    }
    AsyncFileReadCallback callback = async_file_read_current_request->callback;
    if (callback != NULL) {
        callback(async_file_read_current_request->params);
    }
    TLobby::pop_and_close();
    async_file_read_state = 0;
}
