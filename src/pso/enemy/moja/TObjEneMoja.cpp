#include "pso/unk/SampledMotionPoints.h"
#include "types.h"
#include "pso/enemy/moja/TObjEneMoja.h"

extern "C" {

void free_bin_model_request(void*, int);
void *__ct__11TObjControlFP7TObject(void *, void *);
void *TObjEneMoja__ct(void *, void *, void *);
void *__nw__7TObjectFUl(int);
void mem_free(void*);

extern void *tl_04;

void *TObjEneMoja::create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x40C);
    if (o2 != NULL) {
        o2 = TObjEneMoja__ct(o2, o, arg0);
    }
    return o2;
}

extern u32 lbl_805D50C8;
extern u32 lbl_805D50CC;
extern u32 lbl_805D50D0;
extern u32 lbl_805D50D4;
extern u32 lbl_805D50D8;
extern u32 lbl_805D50DC;

void TObjEneMoja::free_resources() {
    if ((u32) lbl_805D50C8 != 0U) {
        mem_free((void*)lbl_805D50C8);
        lbl_805D50C8 = 0U;
    }
    if ((u32) lbl_805D50CC != 0U) {
        mem_free((void*)lbl_805D50CC);
        lbl_805D50CC = 0U;
    }
    if ((u32) lbl_805D50D0 != 0U) {
        mem_free((void*)lbl_805D50D0);
        lbl_805D50D0 = 0U;
    }
    if ((u32) lbl_805D50D4 != 0U) {
        mem_free((void*)lbl_805D50D4);
        lbl_805D50D4 = 0U;
    }
    if ((u32) lbl_805D50DC != 0U) {
        delete (SampledMotionPoints *)lbl_805D50DC;
        lbl_805D50DC = 0U;
    }
    if ((u32) lbl_805D50D8 != 0U) {
        free_bin_model_request((void*)lbl_805D50D8, 1);
        lbl_805D50D8 = 0U;
    }
}

}
