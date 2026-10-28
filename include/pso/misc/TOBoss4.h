#ifndef PSO_MISC_TOBOSS4_H
#define PSO_MISC_TOBOSS4_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TOBoss4 : public TObjBase {
    virtual ~TOBoss4();
    static void free_instance();
    static void load_static_resource();
    u8 unk_90[0x4];
    f32 m_94;
};

typedef char TOBoss4_size[sizeof(TOBoss4) == 0x98 ? 1 : -1];
#endif
