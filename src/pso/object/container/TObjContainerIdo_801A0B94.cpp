#include "types.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/object/container/TObjContainerIdo.h"

TUnk_804B97C0::~TUnk_804B97C0() {

}

TUnk_804B97C0::TUnk_804B97C0(TObject *parent) : TObjCollidable(parent) {
    view_far_depth = 400.0f;
    view_radius = 10.0f;
}
