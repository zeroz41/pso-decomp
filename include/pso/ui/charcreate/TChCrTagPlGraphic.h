#ifndef PSO_UI_CHARCREATE_TCHCRTAGPLGRAPHIC_H
#define PSO_UI_CHARCREATE_TCHCRTAGPLGRAPHIC_H
#include "pso/TChCrTag.h"
#include "types.h"

class TChCrTagPlGraphic : public TChCrTag {
public:
    virtual ~TChCrTagPlGraphic();
    virtual void render();
    virtual void run_task();
    virtual s32 vt4();
public:
    static void *create(void *arg0);
    static void create_matching_tags();
    void draw_class_illustration();
};

#endif
