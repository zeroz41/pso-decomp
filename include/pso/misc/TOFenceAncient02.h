#ifndef PSO_MISC_TOFENCEANCIENT02_H
#define PSO_MISC_TOFENCEANCIENT02_H

#include "types.h"
#include "pso/misc/TOFenceBase.h"

struct BmlResource;

// The Ruins' 6x2 fence (fd_obj_n_saku_6x2).
struct TOFenceAncient02 : public TOFenceBase {
    TOFenceAncient02(TObject *parent, void *set_data);
    virtual ~TOFenceAncient02();
    virtual void open();
    virtual void close();
    virtual void update_demo();

    static void *create(void *set_data);
    static void unload_resources();
    static void load_resources();

    static const char *class_name;
    static BmlResource *model_resource;
    static s32 *texlists;  // read_texture_variant's four texture lists
    static const char texture_file_b[];
    static const char texture_file_g[];
    static const char texture_file_p[];
};

typedef char TOFenceAncient02_size[sizeof(TOFenceAncient02) == 0xD8 ? 1 : -1];
#endif
