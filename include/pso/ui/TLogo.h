#ifndef PSO_UI_TLOGO_H
#define PSO_UI_TLOGO_H
#include "pso/system/task/TObject.h"
#include "types.h"

// Boot logo sequence: video-mode check, modem check, then the SEGA, Sonic Team and ADX logos.
class TLogo : public TObject {
public:
    TLogo(TObject *parent);
    // render is declared first: it is the class's key function, so the vtable is emitted
    // with it (ahead of run_task's switch table), as in the original data.
    virtual void render();
    virtual ~TLogo();
    virtual void run_task();
public:
    static void free_held_object();
    static void request_exit();
    static s32 check_progressive_ready();
    static void run_frame();
    static void init_logo_scene();

    u8 pad_1C[4];
    u32 state;
    u32 vi_config;    // TAdVIConfigGC
    u32 modem_check;  // TAdTrialModemChkGC
    u32 sega_logo;    // TAdSEGAlogo
    u32 sonic_logo;   // TAdSoniclogo
    u32 adx_logo;     // TAdADXlogo
};
typedef char TLogoExtent[sizeof(TLogo) == 0x38 ? 1 : -1];

extern "C" {
void TLogo__sub_8013F5AC(void);
int TLogo__sub_8013F7E8(int _w0);
s32 TLogo__sub_8013F800(void *p);
int TLogo__sub_8013F808(void);
}

#endif
