#ifndef CMARK_GFM_CORE_EXTENSIONS_H
#define CMARK_GFM_CORE_EXTENSIONS_H

#include <stdint.h>
#include "cmark-gfm-extension_api.h"
#include "export.h"

struct cmark_syntax_extension;
struct cmark_node;

#ifdef __cplusplus
extern "C" {
#endif

CMARK_GFM_EXPORT
void cmark_gfm_core_extensions_ensure_registered(void);

#ifdef __cplusplus
}
#endif

#endif
