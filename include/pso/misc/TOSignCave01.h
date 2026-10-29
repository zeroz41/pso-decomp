#ifndef PSO_MISC_TOSIGNCAVE01_H
#define PSO_MISC_TOSIGNCAVE01_H
#include "pso/misc/CaveSignModel.h"
#include "pso/misc/TUnk_804AFBF8.h"

class TOSignCave01 : public TUnk_804AFBF8 {
public:
    TOSignCave01(TObject *parent, void *set_data);
    virtual ~TOSignCave01();
    virtual void render();
public:
    static void *create(void *arg0);
    static void unload_static_data();
    static void load_shared_resource();
};
typedef char TOSignCave01_size[sizeof(TOSignCave01) == 0xC8 ? 1 : -1];

#endif
