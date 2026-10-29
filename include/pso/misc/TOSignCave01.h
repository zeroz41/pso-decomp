#ifndef PSO_MISC_TOSIGNCAVE01_H
#define PSO_MISC_TOSIGNCAVE01_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

// A cave signboard: its model tree drawn node by node, each branch below the
// root node drawn in the effect pass.
class TOSignCave01 : public TObjMapObject {
public:
    TOSignCave01(TObject *parent, void *set_data);
    virtual ~TOSignCave01();
    virtual void render();
    static void *create(void *set_data);
    static void release_static_resource();
    static void load_shared_resource();
};

typedef char TOSignCave01_size[sizeof(TOSignCave01) == 0xC8 ? 1 : -1];
#endif
