#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/unk/TLobby.h"

extern s32 lbl_805D49B4;
extern s32 quest_download_server_ready;
extern s32 quest_download_in_progress;

s32 TQuestVmDownLoadServer::is_ready() {
    TLobby::wait_ready_loop();
    if ((s32) lbl_805D49B4 != 0) {
        return 0;
    }
    if ((s32) quest_download_in_progress != 0) {
        return 0;
    }
    return quest_download_server_ready ? 1 : 0;
}
