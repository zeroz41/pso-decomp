#ifndef PSO_MAP_CSN_GROUND_CANDIDATES_H
#define PSO_MAP_CSN_GROUND_CANDIDATES_H

struct CsnGroup;

// The collision groups csnVectorUnder last found under an object; ground
// probes search these first.
struct CsnGroundCandidates {
    CsnGroundCandidates();
    void clear();
    CsnGroup *groups[16];
};

#endif
