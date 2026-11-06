#include "types.h"
#include "pso/object/quest/TObjQuestCol_80196B3C.h"
#include "pso/object/quest/TObjQuestColBase.h"
#include "pso/object/quest/TObjQuestCol.h"

extern "C" {

void TObjQuestColBase__ct(void *);
s32 is_within_range__16TObjQuestColBaseFf(f32);

extern s32 __vt__12TObjQuestCol[];
extern void *TObjQuestCol__class_name;

void *TObjQuestCol__ct(void *quest_col) {
    TObjQuestColBase__ct(quest_col);
    *(s32 **)((s8 *)quest_col + 0x18) = __vt__12TObjQuestCol;
    *(void * *)&((TObjQuestCol *)quest_col)->m_name = TObjQuestCol__class_name;
    return quest_col;
}

s32 TObjQuestColBase::update_trigger_state(f32 farg0) {
    if (is_within_range__16TObjQuestColBaseFf(farg0 * farg0) != 0) {
        if ((s32) this->m_b4 != 0) {
            this->m_b4 = 0;
            return 1;
        }
        return 0;
    }
    if ((s32) this->m_b4 != 0) {
        return 2;
    }
    this->m_b4 = 1;
    return 3;
}

}
