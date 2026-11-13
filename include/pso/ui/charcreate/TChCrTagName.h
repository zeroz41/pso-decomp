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

    f32 m_3c;
    f32 m_40;
    s32 m_44;
    vec2f pos;
};

typedef char TChCrTagName_size[sizeof(TChCrTagName) == 0x50 ? 1 : -1];

extern "C" {
s32 TChCrTagName__vt4(TChCrTagName *tag);
void *create__12TChCrTagNameFPv(void *arg0);
void create_all__12TChCrTagNameFv(void);
void draw_tag_sprites__12TChCrTagNameFPv(TChCrTagName *tag);
void render__12TChCrTagNameFv(TChCrTagName *tag);
void run_task__12TChCrTagNameFv(TChCrTagName *tag);
void update_slide_in__12TChCrTagNameFPv(TChCrTagName *tag);
}

#endif
