#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"


void TQuestThreadBoard::destroy_board() {
    if (quest_thread_board != NULL) {
        quest_thread_board->queue_destruction();
    }
}

