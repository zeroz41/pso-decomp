#ifndef PSO_MISC_TOSIGNCAVE03_H
#define PSO_MISC_TOSIGNCAVE03_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

// A cave signboard: its model tree drawn node by node, each branch below the
// root node drawn in the effect pass.
class TOSignCave03 : public TObjMapObject {
public:
    TOSignCave03(TObject *parent, void *set_data);
    virtual ~TOSignCave03();
    virtual void render();
    static void *create(void *set_data);
    static void release_static_resource();
    static void load_shared_resource();
};

typedef char TOSignCave03_size[sizeof(TOSignCave03) == 0xC8 ? 1 : -1];
#endif
