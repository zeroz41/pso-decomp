#ifndef PSO_UI_CITY_THUNTERGUILDSEQONLINETASK_H
#define PSO_UI_CITY_THUNTERGUILDSEQONLINETASK_H

#include "pso/system/task/TObject.h"
#include "types.h"

class THunterGuildSeqOnlineTask : public TObject {
public:
    virtual ~THunterGuildSeqOnlineTask();
    virtual void run_task();
};

// TObject::m_name strings of the online hunter-guild sequence classes (.sdata, defined in
// THunterGuildSeqOnlineTask.cpp in this order).
extern const char *THunterGuildSeqOnlineTask__name;
extern const char *THunterGuildSeqOnline_Server__name;
extern const char *THunterGuildSeqOnline_Client__name;

#endif
