#include "pso/player/TPlayerFootStamp.h"

TPlayerFootStamp::~TPlayerFootStamp() {}

#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 release_texture_list(void*);
void *__ct__16TPlayerFootStampFv(void *, void *, void *);
void *__nw__7TObjectFUl(int);

void *TPlayerFootStamp::create(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0xC4);
    if (o != NULL) {
        o = __ct__16TPlayerFootStampFv(o, arg0, arg1);
    }
    return o;
}

extern u32 player_footstamp_texture_gvm_handle;

void TPlayerFootStamp::free_instance() {
    if ((u32) player_footstamp_texture_gvm_handle != 0U) {
        release_texture_list((void*)player_footstamp_texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(player_footstamp_texture_gvm_handle);
        player_footstamp_texture_gvm_handle = 0U;
    }
}

}
