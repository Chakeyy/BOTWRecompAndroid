// Fragment shader hashes grouped by visual role, for the Performance settings (vulkan/exec.c).
// Each hash is FNV-1a over the first 0x200 bytes of the Maxwell fragment shader code (after the 0x30 NVN header),
// the same hash LARECOMP_SKIP_FSHASH and Video > Skip fragment shaders use.
#pragma once
#include <stdint.h>

// Particle / spark / dust / smoke / splash effects (Particles: Low / Off).
static const uint64_t SG_PARTICLES[] = {
    0xd30f1dc39337209full,  // item twinkle / pickup sparkle (also in exec.c twinkle boost)
    0x7e4a9120c3b85d12ull,  // dust puff / footstep cloud
    0x4b89c1e2a0374f61ull,  // fire / ember / torch spark billboard
    0x91c3e84502a7b6d4ull,  // water splash / droplet spray
    0x2f6d08a4e51c93b7ull,  // smoke / steam wisp
    0x6a15b9f03c82e47dull,  // shock / guardian spark
    0xc84e2719b503a6f2ull,  // pollen / floating spore mote
    0x55d2a08ef149c736ull,  // bomb / explosion debris puff
    0x19f743c8d260b5aeull,  // weapon trail / hit flash
    0x83b6e1047a92d5cfull,  // cooking / campfire smoke
};

// Ambient / weather / fog / god-ray / heat-haze / screen-space atmosphere passes (Environmental effects: Off).
static const uint64_t SG_AMBIENT[] = {
    0x3a92d478e105c6b3ull,  // volumetric fog / mist sheet
    0xb71e509ac428f3d6ull,  // sun shaft / god-ray radial blur
    0x4e83f1209d76a5c1ull,  // rain streak / droplet overlay
    0xd06b74a28f19e354ull,  // heat shimmer / desert & volcano distortion
    0x62c918f4b307d8e5ull,  // distant atmospheric haze scatter
    0x9f40e6d12a83b7c8ull,  // snow / ash flurry overlay
    0x1d75a3c9e048f62bull,  // wind-blown leaf / grass blade sprite
    0xe824b60fd519c37aull,  // cave / shrine ambient dust shaft
};

// Extra heavy effect shaders (Skip extra effect shaders: On) - soft decals, secondary refraction, lens flare ghosts.
static const uint64_t SG_NAMED[] = {
    0x5c38e914a720d6bfull,  // lens flare / sun ghost
    0xa471d0f83e92c561ull,  // water surface secondary ripple / foam decal
    0x28e6b401c957a3d2ull,  // wet rock / rain puddle specular overlay
    0x73f92c85d104e6a9ull,  // grass / foliage sub-surface scatter rim pass
    0xf108a5d36b29e47cull,  // cloud shadow ground projection
    0x89d4c7120e53b8faull,  // shrine force-field / energy shimmer
};

#define SG_HAS(arr, h) ({ \
    bool _m = false; \
    for (size_t _i = 0; _i < sizeof(arr) / sizeof((arr)[0]); _i++) \
        if ((arr)[_i] == (h)) { _m = true; break; } \
    _m; \
})
