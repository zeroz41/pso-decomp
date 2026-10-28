#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/quest/TQuestThread.h"
#include "pso/object/TObjQuestColApcIN.h"

struct Pl_801962B4 { u8 pad0[0x38]; f32 pos[3]; };

struct Col_801962B4 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x68]; f32 fAC; u8 padB0[0xC]; f32 fBC; };

extern "C" {
void *get_player_by_client_id(s32 i);
extern s32 local_client_id;
void TObjQuestColBase__ct(void *);

int TObjQuestColApcIN::vfunc_16() { TQuestThreadBoard::destroy_board(); TQuestThread::create(this->m_b0); }

extern s32 __vt__17TObjQuestColApcIN[];
extern void *lbl_805D33FC;

int TObjQuestColApcIN::vfunc_15() {
    Col_801962B4 *arg0 = (Col_801962B4 *)this;
    Pl_801962B4 *p = (Pl_801962B4 *)get_player_by_client_id(local_client_id);
    if (p != 0) {
        if (xyz_distance_squared((Vec *)p->pos, (Vec *)arg0->pos) < arg0->fAC * arg0->fAC) {
            s32 i;
            for (i = 0; i < 12; i++) {
                if (i != local_client_id) {
                    Pl_801962B4 *q = (Pl_801962B4 *)get_player_by_client_id(i);
                    if (q != 0) {
                        if (xyz_distance_squared((Vec *)p->pos, (Vec *)q->pos) < arg0->fBC * arg0->fBC) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void *TObjQuestColApcIN__ct(void *quest_col_apc_in) {
    TObjQuestColBase__ct(quest_col_apc_in);
    *(s32 **)((s8 *)quest_col_apc_in + 0x18) = __vt__17TObjQuestColApcIN;
    *(void * *)&((TObjQuestColApcIN *)quest_col_apc_in)->m_name = lbl_805D33FC;
    *(f32 *)((s8 *)quest_col_apc_in + 0xBC) = ((TObjQuestColApcIN *)quest_col_apc_in)->scale.y;
    return quest_col_apc_in;
}

}
