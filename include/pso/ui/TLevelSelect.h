#ifndef PSO_UI_TLEVELSELECT_H
#define PSO_UI_TLEVELSELECT_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdSelectCurGC;
class TAdGuideTxtGC;

// The difficulty select screen: one line per unlocked difficulty.
class TLevelSelect : public TObject {
public:
    TLevelSelect();
    virtual ~TLevelSelect();
    virtual void run_task();
    virtual void render();
public:
    static s32 get_difficulty_flag_bit(s32 n, s32 flag);
    int count_unlocked_difficulties();

    s32 m_unlocked_count;
    TAdSelectCurGC *m_cursor;
    TAdGuideTxtGC *m_guide;
};

LAYOUT_ASSERT(TLevelSelect_size, sizeof(TLevelSelect) == 0x28);

extern "C" {
extern s32 game_difficulty_selection;
}

#endif
