#pragma once

#ifdef ST_EXPORT
#define STAPI __declspec(dllexport)
#else
#define STAPI __declspec(dllimport)
#endif
