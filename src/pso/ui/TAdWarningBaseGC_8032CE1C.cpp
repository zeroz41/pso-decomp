#include "types.h"
#include "pso/ui/TUnk_804EDBD0.h"
#include "pso/ui/TAdWarningBaseGC_8032CE1C.h"
#include "pso/misc/TLobby.h"

extern "C" {
u8 ad_warning_arq_request[32];
}


struct TAdWarningBaseGC {
    char pad0[0x1C];
    s32 state;
    void enter_request_state();
    void request_aram_load_state(void *);
    void wait_aram_request();
    void destroy();
};
typedef TAdWarningBaseGC TAdWarningBaseGC_8032CEB4;
typedef void (TAdWarningBaseGC_8032CEB4::*Act_8032CEB4)();

s32 *get_quest_download_file_header(void);
extern "C" {
void DCInvalidateRange(void *, u32);
void ARQPostRequest(void *, u32, u32, u32, u32, u32, u32, void (*)(u32));
void clear_aram_request_busy(u32);
extern u8 ad_warning_arq_request[];
extern u32 ad_warning_aram_base;
extern s32 warning_aram_load_done_flag;
extern int TAdWarningBaseGC__aram_alloc_size;
extern s32 aram_request_busy_flag;
void DCFlushRange(void *, u32);
extern u32 TAdWarningBaseGC__aram_capacity;
void __ct__7TObjectFP7TObject(void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

void wait_aram_request__16TAdWarningBaseGCFv(void *arg0) {
    if ((s32) aram_request_busy_flag == 0) {
        *(s32 *)((s8 *)arg0 + 0x1C) = 3;
        warning_aram_load_done_flag = 1;
    }
}

void request_aram_load_state__16TAdWarningBaseGCFPv(u8 *arg0) {
    s32 temp_r4;
    u32 buf;
    u8 *temp_r3;
    temp_r3 = (u8 *)(get_quest_download_file_header());
    if (temp_r3 != NULL) {
        temp_r4 = *(s32 *)((s8 *)temp_r3 + 0x34);
        if (temp_r4 > 0) {
            buf = *(u32 *)((s8 *)temp_r3 + 0x38);
            if ((buf != 0U) && (post_aram_request__16TAdWarningBaseGCFii((s32)((s32) buf), temp_r4) != 0)) {
                *(s32 *)((s8 *)arg0 + 0x1C) = 2;
                return;
            }
        }
    }
    *(s32 *)((s8 *)arg0 + 0x1C) = 3;
}

void enter_request_state__16TAdWarningBaseGCFv(void* p) { *(s32*)((char*)p + 0x1c) = 1; }

void TUnk_804EDBD0::run_task() {
    TAdWarningBaseGC_8032CEB4 *self = (TAdWarningBaseGC_8032CEB4 *)this;
    static Act_8032CEB4 tbl[4] = {
        &TAdWarningBaseGC::enter_request_state,
        (Act_8032CEB4)&TAdWarningBaseGC::request_aram_load_state,
        &TAdWarningBaseGC::wait_aram_request,
        &TAdWarningBaseGC::destroy,
    };
    (self->*tbl[self->state])();
}

s32 load_from_aram_sync__16TAdWarningBaseGCFi(s32 arg0) {
    u32 size;
    if (warning_aram_load_done_flag == 0) {
        return 0;
    }
    size = ((*(s32 *)&TAdWarningBaseGC__aram_alloc_size) + 0x1F) & ~0x1F;
    DCInvalidateRange((void *)arg0, size);
    aram_request_busy_flag = 1;
    ARQPostRequest(ad_warning_arq_request, 4, 1, 1, ad_warning_aram_base, arg0, size, clear_aram_request_busy);
loop:
    if (aram_request_busy_flag != 0) {
        TLobby::run_frame();
        goto loop;
    }
    DCInvalidateRange((void *)arg0, size);
    return 1;
}

int get_alloc_size__16TAdWarningBaseGCFv(void) {  return TAdWarningBaseGC__aram_alloc_size; }

int TAdWarningBaseGC__sub_8032D020(void) {  return ((TAdWarningBaseGC__aram_alloc_size + 0x1f) & 0xffffffe0); }

extern s32 __vt__13TUnk_804EDBD0[];

s32 post_aram_request__16TAdWarningBaseGCFii(s32 buf, s32 arg1) {
    u32 size;
    size = (arg1 + 0x1F) & ~0x1F;
    (*(s32 *)&TAdWarningBaseGC__aram_alloc_size) = arg1;
    if (size > TAdWarningBaseGC__aram_capacity) {
        return 0;
    }
    DCFlushRange((void *)buf, size);
    aram_request_busy_flag = 1;
    ARQPostRequest(ad_warning_arq_request, 4, 0, 1, buf, ad_warning_aram_base, size, clear_aram_request_busy);
    return 1;
}

}
TUnk_804EDBD0::~TUnk_804EDBD0() {

}
extern "C" {

void *TUnk_804EDBD0::init_vtable() {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804EDBD0;
    *(u32 *)&this->unk_1C = 0;
    return this;
}
}
