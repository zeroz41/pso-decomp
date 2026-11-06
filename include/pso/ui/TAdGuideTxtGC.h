#ifndef PSO_UI_TADGUIDETXTGC_H
#define PSO_UI_TADGUIDETXTGC_H

#include "pso/TObject.h"
#include "types.h"
#include "pso/TMath.h"

class TAdGuideTxtGC : public TObject {
public:
    const char *text[2];
    const char *previous_text[2];
    vec2f position[2];
    u32 alpha[2];
    virtual ~TAdGuideTxtGC();
    virtual void render();
    virtual void run_task();
};

typedef char TAdGuideTxtGCSize[sizeof(TAdGuideTxtGC) == 0x44 ? 1 : -1];

extern "C" {
void reset__15TLobby_802D2F7CFPv(u8 *arg0);
}

#endif
