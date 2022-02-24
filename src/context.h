#pragma once

#include "common.h"

#define CTX_ZOOM 3

// Target (fixed) delta time.
#define CTX_DT (1.0 / 60.0)

// f32 ContextGetDeltaTime();
f64 ContextGetTotalTime();
void ContextSetTotalTime(f64 value);
f32 ContextGetAlpha();
void ContextSetAlpha(f32 value);
