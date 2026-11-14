#ifndef PSO_UI_CHARCREATE_TCHCRTAGINFORMATION_H
#define PSO_UI_CHARCREATE_TCHCRTAGINFORMATION_H

#include "types.h"
#include "pso/ui/charcreate/TChCrTag.h"

struct TChCrTagInformation : public TChCrTag {
    TChCrTagInformation(TObject *parent, void *arg);
    virtual ~TChCrTagInformation();
    void draw_char_info_sprites();
    void render();
    void update_selected_char();
    void run_task();
    virtual s32 vt4();
    static void *create(void *arg0);
    static void *create_default();
};

typedef char TChCrTagInformation_size[sizeof(TChCrTagInformation) == 0x3C ? 1 : -1];

#endif
