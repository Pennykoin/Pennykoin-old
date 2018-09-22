#pragma once

#if defined(_MSC_VER)
#define POD_CLASS struct
#else
#define POD_CLASS class
#endif
