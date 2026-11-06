#ifndef PSO_UI_CITY_THUNTERGUILDSEQONLINETASK_H
#define PSO_UI_CITY_THUNTERGUILDSEQONLINETASK_H

#include "pso/system/task/TObject.h"
#include "types.h"

class THunterGuildSeqOnlineTask : public TObject {
public:
    virtual ~THunterGuildSeqOnlineTask();
    virtual void run_task();
};

#endif
