#ifndef PSO_TECHNIQUE_TECHNIQUE_ID_H
#define PSO_TECHNIQUE_TECHNIQUE_ID_H

// Technique numbers: the index into a player's technique levels and the case
// TTecCtrl's cast switch creates each technique for. The names in brackets are
// the TTec classes' internal spellings.
enum TechniqueId {
    TECHNIQUE_FOIE     = 0,
    TECHNIQUE_GIFOIE   = 1,
    TECHNIQUE_RAFOIE   = 2,
    TECHNIQUE_BARTA    = 3,
    TECHNIQUE_GIBARTA  = 4,
    TECHNIQUE_RABARTA  = 5,
    TECHNIQUE_ZONDE    = 6,
    TECHNIQUE_GIZONDE  = 7,
    TECHNIQUE_RAZONDE  = 8,
    TECHNIQUE_GRANTS   = 9,
    TECHNIQUE_DEBAND   = 10,
    TECHNIQUE_JELLEN   = 11,  // TTecJelin
    TECHNIQUE_ZALURE   = 12,  // TTecZarua
    TECHNIQUE_SHIFTA   = 13,  // TTecSifta
    TECHNIQUE_RYUKER   = 14,  // TTecLuker
    TECHNIQUE_RESTA    = 15,
    TECHNIQUE_ANTI     = 16,
    TECHNIQUE_REVERSER = 17,
    TECHNIQUE_MEGID    = 18,
};

#endif
