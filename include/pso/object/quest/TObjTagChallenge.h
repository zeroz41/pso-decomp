#ifndef PSO_OBJECT_QUEST_TOBJTAGCHALLENGE_H
#define PSO_OBJECT_QUEST_TOBJTAGCHALLENGE_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjTagChallenge : public TObject {
public:
    TObjTagChallenge(TObject *parent);
    virtual ~TObjTagChallenge();
    virtual void run_task();
};

void *create_obj_tag_challenge(void *tag_challenge);

#endif
