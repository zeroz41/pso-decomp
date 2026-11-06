#ifndef PSO_OBJECT_TOBJEZBONEROTBASE_H
#define PSO_OBJECT_TOBJEZBONEROTBASE_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjEZBoneRotBase : public TObject {
public:
    virtual ~TObjEZBoneRotBase();
    void sub_800FED0C();
    void sub_800FEC40(u8 *);
};

#endif
