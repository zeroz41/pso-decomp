#ifndef PSO_OBJECT_TOBJHASHIVERSUS1_H
#define PSO_OBJECT_TOBJHASHIVERSUS1_H
#include "types.h"
#include "pso/object/TObjHashiBase.h"

struct BmlResource;

// A TObjHashiBase: the versus-mode bridge, two collision boxes.
class TObjHashiVersus1 : public TObjHashiBase {
public:
    TObjHashiVersus1(TObject *parent, void *set_data);
    virtual ~TObjHashiVersus1();
    static void *create(void *set_data);
    static void load_shared_resource();
    static void unload_static_data();
    static const char *class_name;
    static BmlResource *bml_resource;
};
#endif
