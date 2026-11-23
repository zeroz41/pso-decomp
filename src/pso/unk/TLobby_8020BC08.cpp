#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"
#include "pso/map/FloorPopulation.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby_80207DA8.h"

extern "C" {

void destroy_child_recursive__6TLobbyFPvPv(TObject *task, TObject *object) {
    TObject *p = task->m_down;
    TObject *cur;
    while (task->m_down != 0 && p != 0) {
        cur = p;
        p = p->m_next;
        if (cur == object) {
            cur->queue_destruction();
        } else {
            destroy_child_recursive__6TLobbyFPvPv(cur, object);
        }
    }
}
}
void init_switch_table(void);
#include "pso/unk/TLobby.h"
#include "pso/map/TSetManager.h"
#include "pso/ui/hud/TRaderMapCore.h"

void TLobby::init_scene_objects() { TLobby::init_sub_objects(); reset_id_tables(); clear_floor_event_flags(); init_switch_table(); TRaderMapCore::set_piece_flags(1); TLobby::attach_objects_by_id((s32)get_current_floor()); TLobby::create_objects((s32)get_current_floor()); TQuestThread::create_for_floor(); }
