#ifndef PSO_UI_CHARCREATE_TCHCRTAG_H
#define PSO_UI_CHARCREATE_TCHCRTAG_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrTag : public TObject {
public:
    TChCrTag(TObject *parent, void *arg);
    virtual ~TChCrTag();
    virtual void render();
    virtual s32 vt4();

    s32 m_1c;
    s32 m_20;
    f32 m_24;
    f32 m_28;
    f32 m_2c;
    f32 m_30;
    f32 m_34;
    f32 m_38;
};

typedef char TChCrTag_size[sizeof(TChCrTag) == 0x3C ? 1 : -1];

// TChCrTag's destructor, run_task slot and slot 6 are still written as C functions.
extern "C" {
void *__dt__8TChCrTagFv(void *self, s16 flag);
void update_fade__8TChCrTagFPv(TChCrTag *tag);
int TChCrTag__vt4(void);
}

#endif
