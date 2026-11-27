#include "types.h"
#include "pso/object/container/TObjContainerIdoBase.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/object/container/TObjContainerIdo.h"

TObjContainerIdoBase::~TObjContainerIdoBase() {

}

TObjContainerIdoBase::TObjContainerIdoBase(TObject *parent) : TObjCollidable(parent) {
    view_far_depth = 400.0f;
    view_radius = 10.0f;
}
