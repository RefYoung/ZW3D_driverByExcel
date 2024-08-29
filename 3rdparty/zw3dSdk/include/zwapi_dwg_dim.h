/**
@file zwapi_dwg_dim.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing Dimension API
*/
/**
@defgroup zwapi_dwg_dim Drawing Dimension API
@ingroup DrawingObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Drawing Dimension API
*/

#pragma once
#ifndef ZW_API_DWG_DIM_H /* this ifndef surrounds entire header */
#define ZW_API_DWG_DIM_H

#include "zwapi_dwg_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Drawing Dimension */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_dim

    Outputs a list of the dimension entity IDs in the special drawing.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idDrawing drawing id
    @param [in] dimTypeList dimension type list (NULL to get all dimensions)
    @param [in] dimTypeCount dimension type count (0 to get all dimensions)
    @param [out] count count of the object
    @param [out] dims dimension list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgInqDims(int idDrawing, evxDimType *dimTypeList, int dimTypeCount, int *count, int **dims);

    /**
    @ingroup zwapi_dwg_dim

    Outputs the id list of entities associated with the specified dimension.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idDim index of dimension
    @param [out] count number of list
    @param [out] idEnts pointer to pointer of entities array

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPR_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgInqDimEnts(int idDim, int *count, int **idEnts);

    /**
    @ingroup zwapi_dwg_dim

    Get grip point coordinates of the specified dimension.

    The calling procedure MUST deallocate the output list.

    @param [in] idDim id of dimension
    @param [out] Num number of grip points of dimension
    @param [out] Pnts list of grip point coordinates of dimension

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgInqDimGripPnts(int idDim, int *Num, svxPoint **Pnts);

    /**
    @ingroup zwapi_dwg_dim

    Get width, height, slope, position for a dimension text box in drawing sheet.

    @param [in] idDim the index of the dimension object
    @param [out] tbWid text box width
    @param [out] tbHgt text box height
    @param [out] chSlp text box slope
    @param [out] txtPt text box position

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgGetDimTextBox(int idDim, double *tbWid, double *tbHgt, double *chSlp, svxPoint2 *txtPt);

    /**
    @ingroup zwapi_dwg_dim

    Get dimension id by view id.

    @note
    Dimensions and other annotations created prior to version 27.00 (VX_API_VERSION < 2700) might have been
    attached to either a drawing or to a view within the drawing. Beginning in version 27.00, ZW3D always
    attaches new dimensions and annotations to the drawing.

    @note
    The cvxDwgInqDimByView() function gets only those older entities that are still attached to a view;    
    The cvxDwgInqDimByDrawing() function gets entities that are directly attached to the drawing, regardless
    of the version in which the entity was created.   
    The cvxDwgInqDims() function gets all dimension and annotation entities from a drawing regardless of whether
    they are attached to the drawing or attached to a view within the drawing.

    @param [in] idView view id
    @param [out] count count of "idDims"
    @param [out]  idDims list of dimension id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgInqDimByView(int idView, int *count, int **idDims);

    /**
    @ingroup zwapi_dwg_dim

    Get dimension id by drawing id.

    @note
    Dimensions and other annotations created prior to version 27.00 (VX_API_VERSION < 2700) might have been
    attached to either a drawing or to a view within the drawing. Beginning in version 27.00, ZW3D always
    attaches new dimensions and annotations to the drawing.

    @note
    The cvxDwgInqDimByDrawing() function gets entities that are directly attached to the drawing, regardless
    of the version in which the entity was created.    
    The cvxDwgInqDimByView() function gets only those older entities that are still attached to a view;     
    The cvxDwgInqDims() function gets all dimension and annotation entities from a drawing regardless of whether
    they are attached to the drawing or attached to a view within the drawing.

    @param [in] idDrawing drawing id
    @param [out] count count of "idDims"
    @param [out]  idDims list of dimension id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgInqDimByDrawing(int idDrawing, int *count, int **idDims);

    /**
    @ingroup zwapi_dwg_dim

    Get information about the dimension bundle.

    The memory referenced by "data" is allocated by this function.

    @param [in] idDim dimension id
    @param [out] count count of data
    @param [out]  data dimension bundle data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgInqBundleDataByDim(int idDim, int *count, svxDwgBundleDimData **data);


    //====================================================================================================================
    /** @name Drawing Dimension Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_dim

    Gets the attributes data of specified dimension.

    @param [in] idDim dimension id
    @param [out] dmAttr dimension attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgDimAtGet(int idDim, svxDimAttr *dmAttr);

    /**
    @ingroup zwapi_dwg_dim

    Sets the attributes data of specified dimension.
    To modify some of the attributes of a dimension, it's better to
    use cvxDwgGetDimAt() to get the origional attribtes first.

    @note
    This function must be called on the main thread.

    @param [in] idDim dimension id
    @param [in] dmAttr dimension attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgDimAtSet(int idDim, svxDimAttr *dmAttr);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DWG_DIM_H */
