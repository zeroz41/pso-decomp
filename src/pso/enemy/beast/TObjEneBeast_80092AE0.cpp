#include "types.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/system/BmlResource.h"

extern BmlResource *ene_beast_bml_resource;

void TObjEneBeast::select_model_record(s32 i) {
    model = ene_beast_bml_resource->models[i].model;
    texlist = ene_beast_bml_resource->models[i].texlist;
}
