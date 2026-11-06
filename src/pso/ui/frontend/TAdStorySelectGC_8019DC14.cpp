#include "types.h"
#include "pso/ui/frontend/TAdStorySelectGC_8019DC14.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/object/warp/TObjMapForceWarp.h"

extern "C" {

int get_bml_motion(void*, void*);
int get_bml_model(void*, void*);

    extern int lbl_805D67C0;
int TAdStorySelectGC__sub_8019DC14(void) {  return lbl_805D67C0; }

    extern int forest_warp_texture_list;
int TAdStorySelectGC::get_story_select() {  return forest_warp_texture_list; }

    extern int forest_warp_bml_resource;
void TAdStorySelectGC::register_area_warp_object(void* a0) { get_bml_motion((void*)forest_warp_bml_resource, a0); }

void TObjMapForceWarp::register_warp(void* a0) { get_bml_model((void*)forest_warp_bml_resource, a0); }

void TObjMapForceWarp::slot3C() {  }

}
