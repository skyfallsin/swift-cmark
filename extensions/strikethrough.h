#ifndef CMARK_GFM_STRIKETHROUGH_H
#define CMARK_GFM_STRIKETHROUGH_H

#include "export.h"
#include "cmark-gfm-core-extensions.h"

#ifdef __cplusplus
extern "C" {
#endif

extern cmark_node_type CMARK_NODE_STRIKETHROUGH;

cmark_syntax_extension *create_strikethrough_extension(void);

#ifdef __cplusplus
}
#endif

#endif
