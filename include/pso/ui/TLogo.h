#ifndef PSO_UI_TLOGO_H
#define PSO_UI_TLOGO_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdADXlogo;
class TAdSEGAlogo;
class TAdSoniclogo;
struct TAdTrialModemChkGC;
struct TAdVIConfigGC;

// Boot logo sequence: video-mode check, modem check, then the SEGA, Sonic Team and ADX logos.
class TLogo : public TObject {
public:
    static int exit_requested_flag;
    TLogo(TObject *parent);
    // render is declared first: it is the class's key function, so the vtable is emitted
    // with it (ahead of run_task's switch table), as in the original data.
    virtual void render();
    virtual ~TLogo();
    virtual void run_task();
public:
    static void free_held_object();
    static void request_exit(TObject *fade);
    static s32 check_progressive_ready();
    static void run_frame();
    static void init_logo_scene();

    u8 pad_1C[4];
    u32 state;
    TAdVIConfigGC *vi_config;
    TAdTrialModemChkGC *modem_check;
    TAdSEGAlogo *sega_logo;
    TAdSoniclogo *sonic_logo;
    TAdADXlogo *adx_logo;
};
LAYOUT_ASSERT(TLogoExtent, sizeof(TLogo) == 0x38);

extern "C" {
void TLogo__sub_8013F5AC(void);
int TLogo__sub_8013F7E8(TAdADXlogo *logo);
s32 TLogo__sub_8013F800(void *p);
int TLogo__sub_8013F808(void);
}

#endif
