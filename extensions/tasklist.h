#ifndef CMARK_GFM_TASKLIST_H
#define CMARK_GFM_TASKLIST_H

#include "export.h"
#include "cmark-gfm-core-extensions.h"

#ifdef __cplusplus
extern "C" {
#endif

CMARK_GFM_EXPORT
cmark_syntax_extension *create_tasklist_extension(void);

CMARK_GFM_EXPORT
bool cmark_gfm_extensions_get_tasklist_item_checked(cmark_node *node);

CMARK_GFM_EXPORT
int cmark_gfm_extensions_set_tasklist_item_checked(cmark_node *node, bool is_checked);

#ifdef __cplusplus
}
#endif

#endif
