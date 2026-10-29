#ifndef PSO_OBJECT_TOBJHASHIVERSUS2_H
#define PSO_OBJECT_TOBJHASHIVERSUS2_H
#include "types.h"
#include "pso/object/TObjHashiBase.h"

struct BmlResource;

// A TObjHashiBase: the second versus-mode bridge, two collision boxes; it starts lowered by its scale x.
class TObjHashiVersus2 : public TObjHashiBase {
public:
    TObjHashiVersus2(TObject *parent, void *set_data);
    virtual ~TObjHashiVersus2();
    static void *create(void *set_data);
    static void load_shared_resource();
    static void unload_static_data();
    static const char *class_name;
    static BmlResource *bml_resource;
};
#endif
