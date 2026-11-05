#include "pso/TAdSoniclogo.h"

#include "types.h"
#include "pso/TLogo.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdBackGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TAdSoniclogo.h"

extern "C" {
extern void *sonic_logo_object;
extern int TAdSoniclogo__state;
extern int TLogo__exit_requested_flag;
extern const char *TAdSoniclogo__class_name;
extern void *tl_00;
int queue_destruction__7TObjectFv(void);

void TAdSoniclogo::request_destroy() { queue_destruction__7TObjectFv(); TAdSoniclogo__state = 1; }

}

s32 get_logo_texture_e_handle(void);

void TAdSoniclogo::render() {
    render_logo_with_default(sonic_logo_object, 16, -1, -150.0f);
}
void TAdSoniclogo::run_task() {
    switch (TAdSoniclogo__state) {
    case 0:
        break;
    case 1:
        if (++m_wait_frames > 0x3c) {
            void *p;
            TAdSoniclogo__state = 2;
            p = TObject::operator new(0x28);
            if (p != 0) {
                ((THunterGuildSeqOffline *)p)->init(tl_00, (void *)TLogo::request_exit);
            }
        }
        break;
    case 2:
        break;
    }
}
TAdSoniclogo::~TAdSoniclogo() {}

TAdSoniclogo::TAdSoniclogo(TObject *parent) : TObject(parent) {
    void *o;
    m_name = TAdSoniclogo__class_name;
    m_wait_frames = 0;
    TAdSoniclogo__state = 0;
    TLogo__exit_requested_flag = 0;
    TAdSinglePlyChrSelectGC::init_logo_state(1);
    o = TObject::operator new(0x28);
    if (o != NULL) {
        ((TLobby *)o)->init_fade(tl_00, (void *)request_destroy);
    }
}

extern "C" {

void TLogo__sub_8001C360(void) {  }

void TLogo__sub_8001C364(void) { sonic_logo_object = (void *)get_logo_texture_e_handle(); }

}
