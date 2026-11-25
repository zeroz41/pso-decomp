#ifndef PSO_QUEST_TQUESTCOLCTRL_H
#define PSO_QUEST_TQUESTCOLCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct ObjectSetData;
struct Vec;
struct TObjQuestColBase;
struct TObjQuestCol;
struct TObjQuestColA;
struct TObjQuestColALock;
struct TObjQuestColApc;
struct TObjQuestColApcIN;
struct TObjQuestColApcINW;

extern "C" {
TObjQuestCol *create_quest_col(ObjectSetData *set, s32 *out_id);
TObjQuestColA *create_quest_col_a(ObjectSetData *set, s32 *out_id);
TObjQuestColALock *create_quest_col_alock(ObjectSetData *set, s32 *out_id);
TObjQuestColApc *create_quest_col_apc(ObjectSetData *set, s32 *out_id);
TObjQuestColApcIN *create_quest_col_apc_in(ObjectSetData *set, s32 *out_id);
TObjQuestColApcINW *create_quest_col_apc_inw__6TLobbyFPvPv(ObjectSetData *set, s32 *out_id);
void send_quest_collision_warp();
Vec *set_quest_col_warp_position(TObjQuestColApcINW *trigger, const Vec *position);
}

extern s32 quest_collision_warp_pending;  // set by TObjQuestColApcINW's trigger check

struct TQuestColCtrl : public TObject {
    TQuestColCtrl(TObject *parent);
    virtual ~TQuestColCtrl();
    virtual void render();
    virtual void run_task();
    static TObjQuestColBase *find_by_id(u16 entity_id);
    static void delete_by_param(s32 id);
    static void init();
    static void sub_80196EC0();  // clears quest_collision_warp_pending
};

LAYOUT_ASSERT(TQuestColCtrl_size, sizeof(TQuestColCtrl) == 0x1C);
#endif
