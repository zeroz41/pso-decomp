#ifndef PSO_MISC_TOFENCEANCIENT04_H
#define PSO_MISC_TOFENCEANCIENT04_H

#include "types.h"
#include "pso/player/TUnk_804B1B80.h"

struct BmlResource;

// The Ruins' 6x4 fence (fd_obj_n_saku_6x4).
struct TOFenceAncient04 : public TUnk_804B1B80 {
    TOFenceAncient04(TObject *parent, void *set_data);
    virtual ~TOFenceAncient04();
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

typedef char TOFenceAncient04_size[sizeof(TOFenceAncient04) == 0xD8 ? 1 : -1];
#endif
