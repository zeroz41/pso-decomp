#include "pso/player/TPlyDispData.h"

// The display config's constructor and destructor are this file's only
// out-of-line definitions. Built with -inline off, each in-class inline they
// call comes out right after its first caller: ~TPlyDispConfigSmth and
// ~gc_tag after the destructor, TPlyDispConfigSmth(), gc_tag() and
// gc_tag::init() after the constructor (0x80071E4C-0x80072048).

TPlyDispConfig::~TPlyDispConfig() {}

TPlyDispConfig::TPlyDispConfig() {}
