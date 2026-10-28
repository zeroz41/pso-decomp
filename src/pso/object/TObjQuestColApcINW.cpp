#include "types.h"
#include "pso/misc/TQuestThread.h"
#include "pso/system/vector.h"
#include "pso/object/TObjQuestColApcINW.h"
#include "pso/object/TObjQuestColBase.h"
#include "pso/object/TObjQuestCol.h"

struct Pl_801960F8 { u8 pad0[0x38]; f32 pos[3]; };

struct Col_801960F8 { u8 pad0[0xAC]; f32 fAC; u8 padB0[0xC]; f32 fBC; f32 fC0[3]; };

extern "C" {
f32 xz_distance_squared(void *, void *);
void *get_player_by_client_id(s32 i);
extern u8 quest_col_apc_warp_target_pos[];
extern s32 local_client_id;
extern s32 quest_collision_warp_pending;
void TObjQuestColBase__ct(void *);
int destroy_board__17TQuestThreadBoardFv(void*);

int TObjQuestColApcINW::vfunc_16() { destroy_board__17TQuestThreadBoardFv(this); create__12TQuestThreadFi(this->m_b0); }

extern const f32 lbl_805DBF04;
extern s32 __vt__18TObjQuestColApcINW[];
extern void *lbl_805D3400;

int TObjQuestColApcINW::vfunc_15() {
    Col_801960F8 *arg0 = (Col_801960F8 *)this;
    if (((TObjQuestColBase *)arg0)->update_trigger_state(arg0->fAC) == 1) {
        Pl_801960F8 *p = (Pl_801960F8 *)get_player_by_client_id(local_client_id);
        if (p == 0) {
            return 0;
        }
        s32 i;
        for (i = 0; i < 12; i++) {
            if (i != local_client_id) {
                Pl_801960F8 *q = (Pl_801960F8 *)get_player_by_client_id(i);
                if (q != 0) {
                    if (xz_distance_squared(q->pos, p->pos) > arg0->fBC * arg0->fBC) {
                        quest_collision_warp_pending = 1;
                        VecCopy((Vec *)quest_col_apc_warp_target_pos, (const Vec *)arg0->fC0);
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}

void *TObjQuestColApcINW__ct(TObjQuestColApcINW *quest_col_apc_inw) {
    TObjQuestColBase__ct(quest_col_apc_inw);
    *(s32 **)((s8 *)quest_col_apc_inw + 0x18) = __vt__18TObjQuestColApcINW;
    *(void * *)&quest_col_apc_inw->m_name = lbl_805D3400;
    *(f32 *)((s8 *)quest_col_apc_inw + 0xBC) = quest_col_apc_inw->scale.y;
    quest_col_apc_inw->m_c8 = lbl_805DBF04;
    *(f32 *)((s8 *)quest_col_apc_inw + 0xC4) = lbl_805DBF04;
    *(f32 *)((s8 *)quest_col_apc_inw + 0xC0) = lbl_805DBF04;
    return quest_col_apc_inw;
}

}
