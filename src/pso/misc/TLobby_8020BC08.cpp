#include "types.h"
#include "pso/quest/TQuestThread.h"

struct Obj_8020BBA0 { u8 pad[0xC]; Obj_8020BBA0 *next; u8 pad2[4]; Obj_8020BBA0 *child; };

extern "C" {
void queue_destruction__7TObjectFv(void *);
void destroy_child_recursive__6TLobbyFPvPv(Obj_8020BBA0 *arg0, Obj_8020BBA0 *arg1);
s32 get_current_floor(void);
void clear_floor_event_flags(void);
int create_objects__6TLobbyFl(void);
int attach_objects_by_id__6TLobbyFl(void);

void destroy_child_recursive__6TLobbyFPvPv(Obj_8020BBA0 *arg0, Obj_8020BBA0 *arg1) {
    Obj_8020BBA0 *p = arg0->child;
    Obj_8020BBA0 *cur;
    while (arg0->child != 0 && p != 0) {
        cur = p;
        p = p->next;
        if (cur == arg1) {
            queue_destruction__7TObjectFv(cur);
        } else {
            destroy_child_recursive__6TLobbyFPvPv(cur, arg1);
        }
    }
}
}
void init_switch_table(void);
#include "pso/misc/TLobby.h"
#include "pso/misc/TRaderMapCore.h"

void TLobby::init_scene_objects() { TLobby::init_sub_objects(); TLobby::reset_id_tables(); clear_floor_event_flags(); init_switch_table(); TRaderMapCore::set_piece_flags(1); get_current_floor(); attach_objects_by_id__6TLobbyFl(); get_current_floor(); create_objects__6TLobbyFl(); TQuestThread::create_for_floor(); }
