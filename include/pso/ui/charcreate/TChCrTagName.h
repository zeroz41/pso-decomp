#ifndef PSO_UI_CHARCREATE_TCHCRTAGNAME_H
#define PSO_UI_CHARCREATE_TCHCRTAGNAME_H

#include "types.h"
#include "pso/math/TMath.h"
#include "pso/ui/charcreate/TChCrTag.h"

class TChCrTagName : public TChCrTag {
public:
    TChCrTagName(TObject *parent, void *arg);
    virtual void render_shadows();
    virtual ~TChCrTagName();
    void update_slide_in();
    f32 calc_highlight_scale();
    void draw_tag_sprite();
    void sub_802A226C();
    void draw_tag_sprites();

    f32 m_3c;
    f32 m_40;
    s32 m_44;
    vec2f pos;
public:
    static void *create(void *arg0);
    static void create_all();
};

LAYOUT_ASSERT(TChCrTagName_size, sizeof(TChCrTagName) == 0x50);

extern "C" {
s32 TChCrTagName__vt4(TChCrTagName *tag);
void *create__12TChCrTagNameFPv(void *arg0);
void create_all__12TChCrTagNameFv(void);
void draw_tag_sprites__12TChCrTagNameFv(TChCrTagName *tag);
void render__12TChCrTagNameFv(TChCrTagName *tag);
void run_task__12TChCrTagNameFv(TChCrTagName *tag);
void update_slide_in__12TChCrTagNameFv(TChCrTagName *tag);
}

// --- C functions defined in TChCrTagName.cpp ---
extern "C" {
s32 TChCrTagName__vt4(TChCrTagName *tag);
void render__12TChCrTagNameFv(TChCrTagName *tag);
void run_task__12TChCrTagNameFv(TChCrTagName *tag);
}
// --- end of C functions

#endif
