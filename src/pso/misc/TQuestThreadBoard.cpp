#include "types.h"
#include "pso/quest/TQuestThread.h"

extern "C" {

void queue_destruction__7TObjectFv(void *arg0);

extern u32 quest_thread_board;

void TQuestThreadBoard::destroy_board() {
    if ((u32) quest_thread_board != 0U) {
        queue_destruction__7TObjectFv((void *)quest_thread_board);
    }
}

}
