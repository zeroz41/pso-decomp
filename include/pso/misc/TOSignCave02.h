#ifndef PSO_MISC_TOSIGNCAVE02_H
#define PSO_MISC_TOSIGNCAVE02_H
#include "pso/misc/CaveSignModel.h"
#include "pso/misc/TUnk_804AFBF8.h"

class TOSignCave02 : public TUnk_804AFBF8 {
public:
    TOSignCave02(TObject *parent, void *set_data);
    virtual ~TOSignCave02();
    virtual void render();
public:
    static void *create(void *arg0);
    static void free_static_model();
    static void load_shared_resource();
};
typedef char TOSignCave02_size[sizeof(TOSignCave02) == 0xC8 ? 1 : -1];

#endif
