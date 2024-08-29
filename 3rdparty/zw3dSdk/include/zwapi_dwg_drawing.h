/**
@file zwapi_dwg_drawing.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing API
*/
/**
@defgroup zwapi_dwg_drawing Sheet/Drawing API
@ingroup DrawingObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Drawing API
*/

#pragma once
#ifndef ZW_API_DWG_H /* this ifndef surrounds entire header */
#define ZW_API_DWG_H

#include "zwapi_dwg_data.h"
#include "zwapi_cmd_dwg_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sheet Edit */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_drawing

    Add a new sheet.
    Output the sheet id if sheet is not NULL.
    If sheet name is NULL, the default sheet name is used.

    @param [in] Name sheet name (NULL to use default sheet name)
    @param [out] idSheet id of sheet (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgSheetAdd(vxLongName Name, int *idSheet);

    /**
    @ingroup zwapi_dwg_drawing

    Delete the specified sheets.

    @param [in] count count of sheets
    @param [in] idSheet list of sheet ids

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
    extern evxErrors cvxDwgSheetDel(int count, int *idSheet);

    /**
    @ingroup zwapi_dwg_drawing

    Get the scale of the specified sheet.

    @param [in] idSheet sheet id, 0(or -1) to use activated sheet
    @param [out] scale scale of specified sheet

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgSheetScaleGet(int idSheet, double *scale);

    /**
    @ingroup zwapi_dwg_drawing

    Set the scale of the specified sheet.

    @param [in] idSheet sheet id, 0(or -1) to use activated sheet
    @param [in] scale scale of specified sheet

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgSheetScaleSet(int idSheet, double scale);


    //====================================================================================================================
    /** @name Drawing Query/Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_drawing

    Outputs a list of the drawing IDs.
    The calling procedure MUST deallocate the output list with cvxMemFree().
    Use cvxRootId() to get idRoot.

    @param [in] idRoot root ID
    @param [out] count count of the list
    @param [out] idDrawings ID list of the drawings

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgInqList(int idRoot, int *count, int **idDrawings);

    /**
    @ingroup zwapi_dwg_drawing

    Get the name of the special drawing.

    @param [in] idDrawing drawing id
    @param [out] drawingName drawing name
    @param [in] nBytes string max size of active file name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgInqName(int idDrawing, char *drawingName, int nBytes);

    /**
    @ingroup zwapi_dwg_drawing

    Get the id of the special drawing in the current active file.
    if rootName=NULL, it means using the current sheet.

    @param [in] rootName root name
    @param [in] drawingName drawing name
    @param [out] idDrawing drawing id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgFind(const vxRootName rootName, const vxLongName drawingName, int *idDrawing);

    /**
    @ingroup zwapi_dwg_drawing

    Get index of border and title including block and sketch in specified drawing.

    @param [in] idDrawing index of drawing
    @param [out] idBorder index of Border block(NULL to ignore)
    @param [out] idBorderSkt index of Border sketch(NULL to ignore)
    @param [out] idTitle index of title block(NULL to ignore)
    @param [out] idTitleSkt index of title sketch(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxDwgInqBorderTitle(int idDrawing, int *idBorder, int *idBorderSkt, int *idTitle, int *idTitleSkt);

    /**
    @ingroup zwapi_dwg_drawing

    Outputs a list of associated parts .

    @param [in] rootName root name (rootName[0]=0 or NULL for active sheet)
    @param [out] iCount count of associated parts
    @param [out] partList part info(part name and file name) list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgInqPart(char *rootName, int *iCount, svxCompName **partList);

    /**
    @ingroup zwapi_dwg_drawing

    Set the referenced part for the specified drawing sheet. Root can be NULL if the file
    extension is .Z3DRW.

    If idxView is >0, only update the specified view, -1 to update all drawing views in the
    drawing sheet.

    If oldPart is not specified, suppose to update the referenced part of the specified view
    (if idxView>0) or the active view of the drawing sheet (mostly the first view).

    @param [in] File drawing sheet file name (NULL string for the active file)
    @param [in] Root drawing sheet root name (NULL string for the active target object)
    @param [in] idxView update the specified view, -1 for all in the sheet
    @param [in] oldPart old part name to be updated (can be NULL, see the description)
    @param [in] newPart new part name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgSetRefPart(const char *File, const char *Root, int idxView, svxCompName *oldPart, svxCompName *newPart);

    /**
    @ingroup zwapi_dwg_drawing

    Active the special drawing in the current open sheet.

    @param [in] drawingName drawing name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxDwgActivate(vxLongName drawingName);

    /**
    @ingroup zwapi_dwg_drawing

    Outputs the name of the active drawing.

    @param [out] drawingName drawing name
    @param [in] nBytes string max size of active file name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgInqActive(char *drawingName, int nBytes);

    /**
    @ingroup zwapi_dwg_drawing

    Regenerate drawing.

    @param [in] count count of idViews (count < 1, regen all views)
    @param [in] idViews list of idView
    @param [in] isRegenUnModifiedView 1 if regenerate unmodified views,else 0
    @param [in] isRegenTable 1 if regenerate tables,else 0
    @param [in] isPrompt 1 if auto prompt for view regen ,else 0
    @param [in] isRegenSketch 1 if regenerate standalone sketch ,else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgRegen(int count, int *idViews, int isRegenUnModifiedView, int isRegenTable, int isPrompt, int isRegenSketch);

    //====================================================================================================================
    /** @name Style Manager Data */
    //====================================================================================================================

    /**
    @ingroup zwapi_dwg_drawing

    Get the properties of the character text in the style manager.

    If the type is VX_STYLEMANAGER_TEXT,
       the data is defined by struct svxDwgStyleManagerText, 

    else if the type is VX_STYLEMANAGER_ANNO_LEADER~VX_STYLEMANAGER_DIM_ORDINATE,
       the data is defined by struct svxDwgStyleManagerAnnoDimText, 

    else if the type is VX_STYLEMANAGER_TABLE_USER~VX_STYLEMANAGER_TABLE_REVISION,
       the data is svxDwgStyleManagerTableText, 

    else if the type is VX_STYLEMANAGER_SYM_WELD or VX_STYLEMANAGER_SYM_SRF_FINISH,
       the data is svxDwgStyleManagerSymText. 

    else if the type is VX_STYLEMANAGER_VIEW_BASE~VX_STYLEMANAGER_VIEW_ALTERNATE,
       the data is svxDwgStyleManagerViewText.

    @param [in] type  style maneger method
    @param [out] data text attribute data 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgStyleManagerWithTextAtGet(evxDwgStyleManagerMethod type, void *data);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DWG_H */
