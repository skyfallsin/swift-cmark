#ifndef CMARK_GFM_TABLE_H
#define CMARK_GFM_TABLE_H

#include <stdint.h>
#include "cmark-gfm-extension_api.h"
#include "export.h"

struct cmark_syntax_extension;
struct cmark_node;

#ifdef __cplusplus
extern "C" {
#endif

extern cmark_node_type CMARK_NODE_TABLE, CMARK_NODE_TABLE_ROW,
    CMARK_NODE_TABLE_CELL;

CMARK_GFM_EXPORT
cmark_syntax_extension *create_table_extension(void);

CMARK_GFM_EXPORT
uint16_t cmark_gfm_extensions_get_table_columns(cmark_node *node);

CMARK_GFM_EXPORT
int cmark_gfm_extensions_set_table_columns(cmark_node *node, uint16_t n_columns);

CMARK_GFM_EXPORT
uint8_t *cmark_gfm_extensions_get_table_alignments(cmark_node *node);

CMARK_GFM_EXPORT
int cmark_gfm_extensions_set_table_alignments(cmark_node *node, uint16_t ncols, uint8_t *alignments);

CMARK_GFM_EXPORT
int cmark_gfm_extensions_get_table_row_is_header(cmark_node *node);

CMARK_GFM_EXPORT
int cmark_gfm_extensions_set_table_row_is_header(cmark_node *node, int is_header);

CMARK_GFM_EXPORT
int cmark_gfm_extensions_set_table_cell_colspan(cmark_node *node, unsigned colspan);

CMARK_GFM_EXPORT
int cmark_gfm_extensions_set_table_cell_rowspan(cmark_node *node, unsigned rowspan);

CMARK_GFM_EXPORT
unsigned cmark_gfm_extensions_get_table_cell_colspan(cmark_node *node);

CMARK_GFM_EXPORT
unsigned cmark_gfm_extensions_get_table_cell_rowspan(cmark_node *node);

#ifdef __cplusplus
}
#endif

#endif
