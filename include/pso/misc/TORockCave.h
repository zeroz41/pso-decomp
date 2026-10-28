#ifndef PSO_MISC_TOROCKCAVE_H
#define PSO_MISC_TOROCKCAVE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TORockCave : public TObjCollidable {
    TORockCave();
    virtual ~TORockCave();
    virtual void vfunc_14();
    virtual void vfunc_15();
    void draw_model();
    static void free_instances();
    static void load_resources();
    u8 unk_AC[0x4];
    f32 m_b0;
};

typedef char TORockCave_size[sizeof(TORockCave) == 0xB4 ? 1 : -1];
#endif
