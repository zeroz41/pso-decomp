#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"

extern "C" {

extern u32 quest_thread_board;

void TQuestThreadBoard::destroy_board() {
    if ((u32) quest_thread_board != 0U) {
        ((TObject *)quest_thread_board)->queue_destruction();
    }
}

}
