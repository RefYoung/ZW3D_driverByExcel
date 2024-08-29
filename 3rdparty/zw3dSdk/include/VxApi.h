/*
** (C) Copyright 2012, ZWSOFT., Proprietary and Trade Secret
**
*********************************************************************
**
** THE OLD HEADER FILE FOR THE ZW3D API
**
** Note -- This header had been replaced by the following heads since
**         R2800. User can use the ZwApi**.h file directly.
**
*********************************************************************
**
*/

#pragma once
#ifndef VX_API_H /* this ifndef surrounds entire header */
#define VX_API_H

#include "zwapi_config.h"
#include "zwapi_dim.h"
#include "zwapi_display.h"
#include "zwapi_layer.h"
#include "zwapi_license.h"
#include "zwapi_memory.h"
#include "zwapi_message.h"
#include "zwapi_root.h"
#include "zwapi_userinput.h"
#include "zwapi_var.h"
#include "zwapi_view.h"
#include "zwapi_xn.h"
#include "zwapi_text.h"
#include "zwapi_global_apply.h"
#include "zwapi_general_ent.h"
#include "zwapi_asm_comp.h"
#include "zwapi_asm_constraint.h"
#include "zwapi_asm_comp_attribute.h"
#include "zwapi_asm_reuselibrary.h"
#include "zwapi_brep_data.h"
#include "zwapi_brep_shape.h"
#include "zwapi_brep_face.h"
#include "zwapi_brep_edge.h"
#include "zwapi_brep_preedge.h"
#include "zwapi_brep_loop.h"
#include "zwapi_brep_vertex.h"
#include "zwapi_dwg_drawing.h"
#include "zwapi_dwg_view.h"
#include "zwapi_dwg_dim.h"
#include "zwapi_dwg_geometry.h"
#include "zwapi_dwg_symbol.h"
#include "zwapi_dwg_table.h"
#include "zwapi_dwg_attribute.h"
#include "zwapi_file.h"
#include "zwapi_file_path.h"
#include "zwapi_math_nurbscurve.h"
#include "zwapi_math_nurbssurface.h"
#include "zwapi_math_data.h"
#include "zwapi_math.h"
#include "zwapi_math_bndbox.h"
#include "zwapi_math_insect.h"
#include "zwapi_math_point.h"
#include "zwapi_math_vector.h"
#include "zwapi_math_matrix.h"
#include "zwapi_part_datum_query.h"
#include "zwapi_part_history.h"
#include "zwapi_part_hole.h"
#include "zwapi_part_attribute.h"
#include "zwapi_part_facets.h"
#include "zwapi_part_config.h"
#include "zwapi_part_dim.h"
#include "zwapi_part_objs.h"
#include "zwapi_part_var.h"
#include "zwapi_part_sheetmetal_attribute.h"
#include "zwapi_part_view.h"
#include "zwapi_sk_objs.h"
#include "zwapi_sk_attribute.h"
#include "zwapi_sk_dim.h"
#include "zwapi_sk_var.h"
#include "zwapi_ui_combobox.h"
#include "zwapi_ui_form.h"
#include "zwapi_ui_guiset.h"
#include "zwapi_ui_listwidget.h"
#include "zwapi_ui_popupform.h"
#include "zwapi_ui_tablewidget.h"
#include "zwapi_ui_treeview.h"
#include "zwapi_ui_ribbon.h"
#include "zwapi_cmd_dwg_dimension.h"
#include "zwapi_cmd_dwg_drawing.h"
#include "zwapi_cmd_dwg_layout.h"
#include "zwapi_cmd_ecadboard.h"
#include "zwapi_cmd.h"
#include "zwapi_cmd_paramdefine_tpl.h"
#include "zwapi_cmd_paramdefine_param.h"
#include "zwapi_asm_opts.h"
#include "zwapi_cmd_assembly.h"
#include "zwapi_cmd_dataexchange.h"
#include "zwapi_cmd_datum.h"
#include "zwapi_cmd_freeform.h"
#include "zwapi_part_opts.h"
#include "zwapi_cmd_pmi.h"
#include "zwapi_cmd_direct_edit.h"
#include "zwapi_cmd_shape.h"
#include "zwapi_cmd_sheetmetal.h"
#include "zwapi_cmd_sk_create.h"
#include "zwapi_cmd_udf.h"
#include "zwapi_cmd_wireframe.h"
#include "zwapi_cmd_sk_cmds.h"
#include "zwapi_sk_opts.h"
#include "zwapi_cmd_sk_app.h"
#include "zwapi_cmd_subcmd.h"
#include "zwapi_cm_comp.h"
#include "zwapi_cm_folder.h"
#include "zwapi_cm_forms.h"
#include "zwapi_cm_frame.h"
#include "zwapi_cm_ftr.h"
#include "zwapi_cm_query.h"
#include "zwapi_cm_machine.h"
#include "zwapi_cm_op.h"
#include "zwapi_cm_tool.h"
#include "zwapi_tool_entpath.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef V_VXAPILOC_H
#include "api/inc/VxApiLoc.h"
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VX_API_H */
