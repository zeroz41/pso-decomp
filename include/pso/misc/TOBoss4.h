#ifndef PSO_MISC_TOBOSS4_H
#define PSO_MISC_TOBOSS4_H

#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/BmlResource.h"

// Shared base of the Vol Opt arena scenery: the birds, the tower and the
// falling rocks all draw from bm_o_boss4.bml.
struct TOBoss4 : public TObjBase {
    TOBoss4();
    virtual ~TOBoss4();
    static void free_instance();
    static void load_static_resource();
    static const char *class_name;
    static BmlResource *model_resource;
    f32 view_range;
    f32 model_radius;
};

typedef char TOBoss4_size[sizeof(TOBoss4) == 0x98 ? 1 : -1];
#endif
