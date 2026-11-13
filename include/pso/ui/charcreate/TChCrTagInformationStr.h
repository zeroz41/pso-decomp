#ifndef PSO_UI_CHARCREATE_TCHCRTAGINFORMATIONSTR_H
#define PSO_UI_CHARCREATE_TCHCRTAGINFORMATIONSTR_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrTagInformationStr : public TObject {
public:
    TChCrTagInformationStr(TObject *parent, s32 tag_index);
    virtual ~TChCrTagInformationStr();
    virtual void render();
    virtual void run_task();
public:
    static void *create(void *arg0, void *arg1);

    s32 state;
    // Compared with char_creation_tag_info_selected_index; picks the text block.
    s32 tag_index;
    s32 text_group;
    s32 first_text_entry;
    s32 delay;
    f32 alpha;
    s32 frame;
};

#endif
