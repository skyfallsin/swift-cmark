#ifndef CMARK_GFM_CORE_EXTENSIONS_H
#define CMARK_GFM_CORE_EXTENSIONS_H

#include <stdint.h>
#include "export.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "cmark-gfm-extension_api.h"
#include "../table.h"
#include "../tasklist.h"
#include "../strikethrough.h"
#include "../tagfilter.h"
#include "../autolink.h"

CMARK_GFM_EXPORT
void cmark_gfm_core_extensions_ensure_registered(void);

#ifdef __cplusplus
}
#endif

#endif
