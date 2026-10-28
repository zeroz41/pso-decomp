#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/misc/TQuestThread.h"
#include "pso/object/TObjQuestColApc.h"

struct Obj_80196448 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0xac - 0x44]; f32 radius; };

extern "C" {
void *get_player_by_client_id(s32 i);
s32 obj_isState3_324__9TObjCharaFv(void *);
void TObjQuestColBase__ct(void *);
int destroy_board__17TQuestThreadBoardFv(void*);

int TObjQuestColApc::vfunc_16() { destroy_board__17TQuestThreadBoardFv(this); create__12TQuestThreadFi(this->m_b0); }

extern s32 __vt__15TObjQuestColApc[];
extern void *obj_quest_col_apc_class_name;

int TObjQuestColApc::vfunc_15() {
    Obj_80196448 *self = (Obj_80196448 *)this;
    s32 i;
    Obj_80196448 *p;
    for (i = 0; i < 12; i++) {
        p = (Obj_80196448 *)get_player_by_client_id(i);
        if (p != 0 && obj_isState3_324__9TObjCharaFv(p) == 1) {
            if (xyz_distance_squared((Vec *)p->pos, (Vec *)self->pos) < self->radius * self->radius) {
                return 1;
            }
        }
    }
    return 0;
}

void *TObjQuestColApc__ct(void *quest_col_apc) {
    TObjQuestColBase__ct(quest_col_apc);
    *(s32 **)((s8 *)quest_col_apc + 0x18) = __vt__15TObjQuestColApc;
    *(void * *)&((TObjQuestColApc *)quest_col_apc)->m_name = obj_quest_col_apc_class_name;
    return quest_col_apc;
}

}
