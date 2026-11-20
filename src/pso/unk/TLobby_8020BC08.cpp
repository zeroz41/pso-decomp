#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"
#include "pso/map/FloorPopulation.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" {
void clear_floor_event_flags(void);
int create_objects__6TLobbyFl(void);
int attach_objects_by_id__6TLobbyFl(void);

void destroy_child_recursive__6TLobbyFPvPv(TObject *arg0, TObject *arg1) {
    TObject *p = arg0->m_down;
    TObject *cur;
    while (arg0->m_down != 0 && p != 0) {
        cur = p;
        p = p->m_next;
        if (cur == arg1) {
            cur->queue_destruction();
        } else {
            destroy_child_recursive__6TLobbyFPvPv(cur, arg1);
        }
    }
}
}
void init_switch_table(void);
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"

void TLobby::init_scene_objects() { TLobby::init_sub_objects(); TLobby::reset_id_tables(); clear_floor_event_flags(); init_switch_table(); TRaderMapCore::set_piece_flags(1); get_current_floor(); attach_objects_by_id__6TLobbyFl(); get_current_floor(); create_objects__6TLobbyFl(); TQuestThread::create_for_floor(); }
