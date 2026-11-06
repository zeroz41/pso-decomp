#ifndef PSO_SYSTEM_TMEMBERCHECK_H
#define PSO_SYSTEM_TMEMBERCHECK_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TMemberCheck : public TObject {
public:
    TMemberCheck(TObject* parent);
    virtual ~TMemberCheck();
    void update_member_proximity();
    void open_member_name_window();
    virtual void run_task();

    u32 m_1C;
    u8  m_20[0x60];
};

#endif
