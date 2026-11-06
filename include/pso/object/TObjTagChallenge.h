#ifndef PSO_OBJECT_TOBJTAGCHALLENGE_H
#define PSO_OBJECT_TOBJTAGCHALLENGE_H

#include "pso/TObject.h"
#include "types.h"

class TObjTagChallenge : public TObject {
public:
    virtual ~TObjTagChallenge();
    virtual void run_task();
};

extern "C" {
void *TObjTagChallenge__ct(void *tag_challenge);
}

#endif
