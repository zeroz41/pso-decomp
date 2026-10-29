#ifndef PSO_MISC_TOREVLIGHTCAVE01_H
#define PSO_MISC_TOREVLIGHTCAVE01_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

class TORevlightCave01 : public TUnk_804AFBF8 {
public:
    TORevlightCave01(TObject *parent, void *set_data);
    virtual ~TORevlightCave01();
    u32 m_c8;
    u32 m_cc;
    static void *create(void *arg0);
    static void release_static_instance();
    static void load_shared_resource();
    virtual void run_task();
    virtual void render();
};

typedef char TORevlightCave01_size[sizeof(TORevlightCave01) == 0xD0 ? 1 : -1];
#endif
