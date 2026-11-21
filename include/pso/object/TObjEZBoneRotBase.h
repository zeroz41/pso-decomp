#ifndef PSO_OBJECT_TOBJEZBONEROTBASE_H
#define PSO_OBJECT_TOBJEZBONEROTBASE_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct EZBoneRotDesc;

class TObjEZBoneRotBase : public TObject {
public:
    TObjEZBoneRotBase(TObject *parent, void *root, EZBoneRotDesc *desc);
    virtual ~TObjEZBoneRotBase();
    void sub_800FED0C();
    void sub_800FEC40(u8 *);
    u8 pad_1C[0xA0 - 0x1C];
};

#endif
