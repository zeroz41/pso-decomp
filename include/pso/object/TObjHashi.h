#ifndef PSO_OBJECT_TOBJHASHI_H
#define PSO_OBJECT_TOBJHASHI_H
#include "types.h"
#include "pso/object/TObjHashiBase.h"

struct BmlResource;

// A TObjHashiBase: the forest bridge, one collision box.
class TObjHashi : public TObjHashiBase {
public:
    TObjHashi(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjHashi();
    static void *create(ObjectSetData *set_data);
    static void load_shared_resource();
    static void unload_static_data();
    static const char *class_name;
    static BmlResource *bml_resource;
};

// Packet 6x78: toggles the 300-frame timer of one of twelve slots.
struct G_Unknown_6x78;
void handle_6x78(G_Unknown_6x78 *cmd);
void set_handle_6x78_entry(u16 index, s32 value);
s32 get_handle_6x78_entry(u16 index);
void start_handle_6x78_entry(u16 index);

#endif
