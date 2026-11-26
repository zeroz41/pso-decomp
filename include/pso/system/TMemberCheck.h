#ifndef PSO_SYSTEM_TMEMBERCHECK_H
#define PSO_SYSTEM_TMEMBERCHECK_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TWindowCheckBox;

class TMemberCheck : public TObject {
public:
    static s32 previous_member_count;
    TMemberCheck(TObject* parent);
    virtual ~TMemberCheck();
    void update_member_proximity();
    void open_member_name_window();
    virtual void run_task();

    TWindowCheckBox *member_window;
    char names[4][0x18];
};

#endif
