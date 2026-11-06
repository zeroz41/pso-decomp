#ifndef PSO_OBJECT_TOBJEZROPEBASE_H
#define PSO_OBJECT_TOBJEZROPEBASE_H

#include "pso/TObject.h"
#include "types.h"

class TObjEZRopeBase : public TObject {
public:
    u8 unk_1C[0x4];
    void * m_20;
    u8 unk_24[0x4];
    u32 m_28;
 void* m_2c;
public:
    virtual ~TObjEZRopeBase();
    void sub_800FF8CC(void *, void *, s32);
    void sub_800FF788(void *);
};

extern "C" {
void *TObjEZRopeBase__ct(void *arg0);
}

// --- C functions defined in TObjEZRopeBase.cpp ---
extern "C" {
void *TObjEZRopeBase__ct(void *obj_ez_rope_base);
}
// --- end of C functions

#endif
