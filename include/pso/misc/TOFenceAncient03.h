#ifndef PSO_MISC_TOFENCEANCIENT03_H
#define PSO_MISC_TOFENCEANCIENT03_H

#include "types.h"
#include "pso/misc/TOFenceBase.h"

struct BmlResource;

// The Ruins' 4x4 fence (fd_obj_n_saku_4x4).
struct TOFenceAncient03 : public TOFenceBase {
    TOFenceAncient03(TObject *parent, void *set_data);
    virtual ~TOFenceAncient03();
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

typedef char TOFenceAncient03_size[sizeof(TOFenceAncient03) == 0xD8 ? 1 : -1];
#endif
