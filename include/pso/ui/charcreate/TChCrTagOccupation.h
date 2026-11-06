#ifndef PSO_UI_CHARCREATE_TCHCRTAGOCCUPATION_H
#define PSO_UI_CHARCREATE_TCHCRTAGOCCUPATION_H

#include "pso/ui/charcreate/TChCrTag.h"
#include "types.h"

class TChCrTagOccupation : public TChCrTag {
public:
    virtual ~TChCrTagOccupation();
    virtual void render();
    void sub_802A2DF4();
public:
    static void *create(void *arg0);
    static void create_all();
};

extern "C" {
void *__ct__17TChCrTagOccHeaderFv(void *self, TObject *parent, void *arg);
u8 *__ct__18TChCrTagOccupationFv(u8 *self, TObject *parent, void *arg);
void *__dt__17TChCrTagOccHeaderFv(void *self, s16 m);
void *__dt__18TChCrTagOccupationFv(void *self, s16 m);
}
void create_all_ch_cr_tag_headers(void);
void *create_ch_cr_tag_occ_header(void *arg0);

#endif
