#ifndef PSO_MISC_TOSIGNCAVE03_H
#define PSO_MISC_TOSIGNCAVE03_H
#include "pso/misc/CaveSignModel.h"
#include "pso/misc/TUnk_804AFBF8.h"

class TOSignCave03 : public TUnk_804AFBF8 {
public:
    TOSignCave03(TObject *parent, void *set_data);
    virtual ~TOSignCave03();
    virtual void render();
public:
    static void *create(void *arg0);
    static void close_dialog_window();
    static void load_shared_resource();
};
typedef char TOSignCave03_size[sizeof(TOSignCave03) == 0xC8 ? 1 : -1];

#endif
