#ifndef PSO_OBJECT_TOBJDFDEMO0_H
#define PSO_OBJECT_TOBJDFDEMO0_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjDFDemo0 : public TObjBase {
    virtual ~TObjDFDemo0();
    u32 m_90;
    void* m_94;
    u8 unk_98[0x78];
    static void *create(void *arg0);
};

typedef char TObjDFDemo0_size[sizeof(TObjDFDemo0) == 0x110 ? 1 : -1];
#endif
