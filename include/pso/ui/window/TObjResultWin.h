#ifndef PSO_UI_WINDOW_TOBJRESULTWIN_H
#define PSO_UI_WINDOW_TOBJRESULTWIN_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct ChallengeResultSummary {
    s32 stage_index;
    s32 reserved;
    s32 total_time;
};
struct ChallengeResultEntry {
    s32 time;
    char award_name[12];
    s32 rank;
};
struct ChallengeResultRecord {
    ChallengeResultSummary summary;
    ChallengeResultEntry previous;
    ChallengeResultEntry current;
};

class TObjResultWin : public TObject {
public:
    u32 m_window;
    s32 m_close_requested;
    s32 m_countdown;
    char m_text[0x100];
    ChallengeResultRecord m_result;

    TObjResultWin(TObject* parent, const ChallengeResultRecord* result);
    virtual ~TObjResultWin();
    virtual void run_task();
    void build_result_text();
    void create_window();
    static TObjResultWin* create(const ChallengeResultRecord* result);
};
#include <stddef.h>
typedef char ResultSummarySize[(sizeof(ChallengeResultSummary)==12)?1:-1];
typedef char ResultEntrySize[(sizeof(ChallengeResultEntry)==20)?1:-1];
typedef char ResultRecordSize[(sizeof(ChallengeResultRecord)==52)?1:-1];
typedef char ResultBaseSize[(sizeof(TObject)==0x1C)?1:-1];
typedef char ResultWindowSize[(sizeof(TObjResultWin)==0x15C)?1:-1];
typedef char ResultWindowField[(offsetof(TObjResultWin,m_window)==0x1C)?1:-1];
typedef char ResultCloseField[(offsetof(TObjResultWin,m_close_requested)==0x20)?1:-1];
typedef char ResultTimerField[(offsetof(TObjResultWin,m_countdown)==0x24)?1:-1];
typedef char ResultTextField[(offsetof(TObjResultWin,m_text)==0x28)?1:-1];
typedef char ResultRecordField[(offsetof(TObjResultWin,m_result)==0x128)?1:-1];

extern "C" {
int TObjNewFloorWin__sub_8007410C(void);
}
ChallengeResultRecord *copy_challenge_result_record(ChallengeResultRecord *destination, const ChallengeResultRecord *source);

// --- C functions defined in TObjResultWin.cpp ---
extern "C" {
int TObjNewFloorWin__sub_8007410C(void);
}
// --- end of C functions

#endif
