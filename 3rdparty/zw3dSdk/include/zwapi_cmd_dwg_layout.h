/**
@file zwapi_cmd_dwg_layout.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Layout of Drawing API
*/
/**
@defgroup zwapi_cmd_dwg_layout Layout Commands
@ingroup DrawingCommands
@brief
@details THE MODULE FOR THE ZW3D Layout of Drawing API
*/

#pragma once
#ifndef ZW_API_LAYOUT /* this ifndef surrounds entire header */
#define ZW_API_LAYOUT

#include "zwapi_cmd_dwg_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name View */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_dwg_layout

    Initialize the parameters of the cvxDwgViewLayout().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data drawing view layout data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgViewLayoutInit(svxViewLayoutData *data);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Insert view layout.
    This function can create a 1 to 7 view layout of a 3D part.
    This interface is used in the engineering drawing environment.

    @note
    Interface cvxDwgViewLayoutInit() can initialize variables of this function.

    @param [in] data layout setting info

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgViewLayout(svxViewLayoutData *data);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Initialize the parameters of the cvxDwgViewStandard().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data drawing view standard data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgViewStandardInit(svxViewStandardData *data);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Insert Standard View.
    Use this function to create a standard orthographic layout view from a 3D part.
    If the part has named views created using the View Manager, they can also be inserted as a standard view.
    This interface is used in the engineering drawing environment.

    @note
    Interface cvxDwgViewStandardInit() can initialize variables of this function.

    @param [in] data standard setting info
    @param [out] idView id of standard view(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgViewStandard(const svxViewStandardData *data, int *idView);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Insert projection view.
    This function can create a view projected from another existing 3D layout view.
    This interface is used in the engineering drawing environment.

    @note
    The value of "ViewAttr" can be obtained through cvxDwgViewAtGet().
    The default value of "ViewAttr" can be obtained through "cvxDwgViewAtGet(-1,ViewAttr)".

    @param [in] idBaseView id of base view
    @param [in] location location of projection view
    @param [in] Projection 1 if 1st angle, 2 if 3rd angle
    @param [in] DimType 0 if projected, 1 if true
    @param [in] ViewAttr view attribute(NULL to use default)
    @param [out] idProjView id of projection view (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgViewProjection(int idBaseView, svxPoint2 *location, int Projection, int DimType, svxViewAt *ViewAttr, int *idProjView);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Initialize the parameters of the cvxDwgViewAuxiliary().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Auxiliary view data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgViewAuxiliaryInit(svxAuxViewData *data);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Create an auxiliary view for base view in drawing.

    @note
    Interface cvxDwgViewAuxiliaryInit() can initialize variables of this function.

    @param [in] auxViewData auxiliary view data
    @param [out] idView id of the view created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgViewAuxiliary(const svxAuxViewData *auxViewData, int *idView);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Initialize the parameters of the cvxDwgViewFullSection().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data full section view data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgViewFullSectionInit(svxFulSecViewData *data);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Create a full section view for base view in drawing.

    @note
    Interface cvxDwgViewFullSectionInit() can initialize variables of this function.

    @param [in] fulSecViewData full section view data
    @param [out] idView id of the view created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_OBJ
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgViewFullSection(const svxFulSecViewData *fulSecViewData, int *idView);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Initialize the parameters of the cvxDwgViewAlignedSection().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data aligned section view data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgViewAlignedSectionInit(svxAlignSecViewData *data);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Create a aligned section view for base view in drawing.

    @note
    Interface cvxDwgViewAlignedSectionInit() can initialize variables of this function.

    @param [in] alignSecViewData aligned section view data
    @param [out] idView id of the view created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgViewAlignedSection(const svxAlignSecViewData *alignSecViewData, int *idView);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Initialize the parameters of the cvxDwgViewBrokenSection().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Drawing Broken Section input infos

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgViewBrokenSectionInit(svxDwgBrokenSectionData *data);

    /**
    @ingroup zwapi_cmd_dwg_layout

    This interface function is broken section.
    A broken section is a cut-away view of the interior of a part.
    It is a section view displayed inside a 2D boundary where an existing view of the part has been cut away.

    Interface cvxDwgViewBrokenSectionInit() can initialize variables of this function.

    @note
    @verbatim
    | type(evxDwgDepthType)  | The following variables must be defined                                            |
    | VX_DEPTH_POINT         | method,idView,bPoints,countBPs,isShow,isDynamicHatch,dPoint,idCrv,dOffset          |
    | VX_DEPTH_SECTION_PLANE | method,idView,bPoints,countBPs,isShow,isDynamicHatch,dPoint,dView,oPoints,countOPs |
    | VX_DEPTH_3D_NAMED      | method,idView,bPoints,countBPs,isShow,isDynamicHatch,name                          |

    | method(evxDwgBndMethod) | the range of values of "countBPs" |
    | VX_RECTANGULAR_BOUNDARY |    countBPs == 2                  |
    | VX_CIRCULAR_BOUNDARY    |    countBPs == 2                  |
    | VX_POLYLINE_BOUNDARY    |    countBPs >= 3                  |
    @endverbatim

    @param [in] data broken section data
    @param [out] idView id of section view (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgViewBrokenSection(svxDwgBrokenSectionData *data, int *idView);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Initialize the parameters of the cvxDwgViewDetail().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Drawing Detail input infos

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgViewDetailInit(svxDwgDetailData *data);

    /**
    @ingroup zwapi_cmd_dwg_layout

    This function creates a local detail view.

    @note
    Interface cvxDwgViewDetailInit() can initialize variables of this function.

    @param [in] data detail data
    @param [out] idView id of detail view (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgViewDetail(const svxDwgDetailData *data, int *idView);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Initialize the parameters of the cvxDwgViewBrkLine().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data information we need when create break line

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgViewBrkLineInit(svxBrkLineData *data);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Create a break line.

    @note
    Interface cvxDwgViewBrkLineInit() can initialize variables of this function.

    @param [in] brkLineInfo information needed when create break line
    @param [out] brkLnViewId id of break line that will create (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgViewBrkLine(const svxBrkLineData *brkLineInfo, int *brkLnViewId);


    //====================================================================================================================
    /** @name Table */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_dwg_layout

    Initialize the parameters of the cvxDwgTableBom().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data BOM table data(drawing)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgTableBomInit(svxDwgBom *data);

    /**
    @ingroup zwapi_cmd_dwg_layout

    This function is used to create BOM table

    @note
    Interface cvxDwgTableBomInit() can initialize variables of this function.  
    After creating the BOM table, use interface cvxDwgTableInsert to insert the BOM table into the current drawing.
    VX_DWG_CON_USER_TEXT won't take effect in this Api.

    @code
    // 1. Initialize settings
    svxDwgBom bomData = {};
    cvxDwgTableBomInit(&bomData);

    //2. Create BOM table
    ...
    int idBom = 0;
    evxErrors err = cvxDwgTableBom(&bomData, &idBom);

    //3. Insert BOM table to drawing
    svxDwgTblInsert ins = {};
    ins.idTable = idBom;
    ...
    cvxDwgTableInsert(&ins);
    @endcode

    @param [in] pData data of BOM
    @param [out] idTbl id of BOM table (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxDwgTableBom(const svxDwgBom *pData, int *idTbl);

    /**
    @ingroup zwapi_cmd_dwg_layout

    This function is used to insert table

    @param [in] pData data of table

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxDwgTableInsert(const svxDwgTblInsert *pData);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Create a user table.
    Output the table id if idTable is not NULL.

    Variable origin specifies where the table is inserted, valid values are as follows: 
    - origin=0: Top-Left 
    - origin=1: Top-Center 
    - origin=2: Top-Right 
    - origin=3: Mid-Left 
    - origin=4: Mid-Center 
    - origin=5: Mid-Right 
    - origin=6: Bottom-Left 
    - origin=7: Bottom-Center 
    - origin=8: Bottom-Right

    @param [in] name table name
    @param [in] iRow number of rows
    @param [in] iCol number of columns
    @param [in] pnt the coordinate of the origin of table
    @param [in] origin indicate the insertion position(0-8)
    @param [out] idTable id of new table(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgUserTableCreate(const vxName name, int iRow, int iCol, svxPoint2 *pnt, int origin, int *idTable);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Create a user table through a template.
    Output the table id if idTable is not NULL.

    Variable origin specifies where the table is inserted, valid values are as follows: 
    - origin=0: Top-Left 
    - origin=1: Top-Center 
    - origin=2: Top-Right 
    - origin=3: Mid-Left 
    - origin=4: Mid-Center 
    - origin=5: Mid-Right 
    - origin=6: Bottom-Left 
    - origin=7: Bottom-Center 
    - origin=8: Bottom-Right

    @param [in] name table name
    @param [in] tplPath template file full path
    @param [in] pnt the coordinate of the origin of table
    @param [in] origin indicate the insertion position(0-8)
    @param [out] idTable id of new table(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_APPI_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgUserTableCreateByTemplate(const vxName name, const vxLongPath tplPath, svxPoint2 *pnt, int origin, int *idTable);

    //====================================================================================================================
    /** @name Edit View */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_dwg_layout

    Initialize the parameters of the cvxDwgRotateView().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Rotate View data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgRotateViewinit(svxDwgRotView *data);

    /**
    @ingroup zwapi_cmd_dwg_layout

    This function is used to Rotate View.

    @note
    Interface cvxDwgRotateViewInit() can initialize variables of this function.

    @param [in] pData data of Rotate View

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxDwgRotateView(const svxDwgRotView *pData);

    /**
    @ingroup zwapi_cmd_dwg_layout

    Rotate the view with specify angle.

    @param [in] idView id of view
    @param [in] angle degree angle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgViewRotate(int idView, double angle);


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

#endif /* ZW_API_LAYOUT */
