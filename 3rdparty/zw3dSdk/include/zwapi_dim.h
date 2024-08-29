/**
@file zwapi_dim.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Dimension API  
Note -- The common functions of dimension are defined in this header file.  
        The function declarations of the dimension in the part are defined in "ZwApiPart.h"  
        The function declarations of the dimension in the sketch are defined in "ZwApiSkDim.h"  
        The function declarations of the dimension in the drawing are defined in "zwapi_dwg_dim.h"
*/
/**
@defgroup zwapi_dim Dimension Common API
@ingroup CommonModel
@brief
@details THE Module For The ZW3D Dimension API  
Note -- The common functions of dimension are defined in this header file.  
        The function declarations of the dimension in the part are defined in "ZwApiPart.h"  
        The function declarations of the dimension in the sketch are defined in "ZwApiSkDim.h"  
        The function declarations of the dimension in the drawing are defined in "zwapi_dwg_dim.h"  
*/

#pragma once
#ifndef ZW_API_DIM_H /* this ifndef surrounds entire header */
#define ZW_API_DIM_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Dimension Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_dim

    Get the type(evxDimType) of specified dimension.
    It can't get the corresponding type if "*type = VX_DIM_LAST".

    @param [in] idDim the index of dimension
    @param [out] type the type of specified dimension

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxDimInqType(int idDim, evxDimType *type);

    /**
    @ingroup zwapi_dim

    Get the type(evxDimTypeEx) of specified dimension.

    It can't get the corresponding type if "*type = VX_DIM_EX_LAST".

    @param [in] idDim    the index of dimension 
    @param [out] typeEx  the type of specified dimension 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDimInqTypeEx(int idDim, evxDimTypeEx *typeEx);

    /**
    @ingroup zwapi_dim

    Determine whether the label is diameter or radius.

    @param [in] idDim the index of dimension
    @param [out] isRadius 1 is radius, 0 is diameter

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxDimIsRadius(int idDim, int *isRadius);

    /**
    @ingroup zwapi_dim

    Get the state(evxDimState) of specified dimension.

    @param [in] idDim the index of dimension
    @param [out] state the state of specified dimension

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDimInqState(int idDim, evxDimState *state);

    /**
    @ingroup zwapi_dim

    Outputs a list of indices of dimension bundles in specified dimension.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idDim index of dimension
    @param [out] Count number of dimension bundles in dimension
    @param [out] idBundles list of index of dimension bundles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDimInqDimBundles(int idDim, int *Count, int **idBundles);

    /**
    @ingroup zwapi_dim

    Get data of specified FCS dimension object.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idFCS index of FCS dimension
    @param [out] numOfFcs number of FCS data (NULL to ignore)
    @param [out]  FcsData list of FCS data (NULL to ignore)
    @param [out] Note1 FCS annotation text1 (NULL to ignore)
    @param [out] Note2 FCS annotation text2 (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDimFCSDataGet(int idFCS, int *numOfFcs, svxFCSData **FcsData, vxLongName Note1, vxLongName Note2);


    //====================================================================================================================
    /** @name Dimension value */
    //====================================================================================================================
    /**
    @ingroup zwapi_dim

    Outputs the variable that belong to the specified id.
    The parent of dimension can be part,sketch or drawing.

    @param [in] idDim id of dimension or dimension bundle to inquire
    @param [out] Var the variable of specified dimension

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_aPI_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDimInqVar(int idDim, svxVariable *Var);

    /**
    @ingroup zwapi_dim

    Modify the value of the specified dimension.

    The parent of dimension can be part or sketch.

    If the dimension belongs to a block and the expression is referenced by another file
    or current part, you can not use the expression name as the second parameter directly,
    use the correct form of the expression reference(File Name:Root Name:Expression or
    Root Name:Expression).

    @param [in] idDim the index of the dimension object
    @param [in] exp the expression of the dimension object

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxDimValMod(int idDim, char *exp);

    /**
    @ingroup zwapi_dim

    Modify the value of the specified dimension. it is similar to cvxDimValMod(),
    the difference is no update/eval/redraw in this function so as to speed up.
    It needs to call cvxDimValMod() for the last dim for update all previous changes.

    @param [in] idDim the index of the dimension object
    @param [in] exp the expression of the dimension object

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDimValModNoUpdate(int idDim, char *exp);


    //====================================================================================================================
    /** @name Dimension text */
    //====================================================================================================================
    /**
    @ingroup zwapi_dim

    This function is to inquire dimension text content for the dimension with index idDim.

    The calling procedure MUST deallocate the output string with cvxMemFree().

    @param [in] idDim id of dimension
    @param [in] subDim serial number of sub dimension(0,1,2...), refer to
                       evxHoleDimDataItem for sub-data item of hole dimension
    @param [out] pStr output destination text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDimInqText(int idDim, int subDim, char **pStr);

    /**
    @ingroup zwapi_dim

    This function is to modify dimension text for the dimension with index idDim.

    @param [in] idDim id of dimension
    @param [in] subDim number to indicate which sub-dimension to be modified.
                       The first sub-dimension starts from 0
    @param [in] pStr new destination text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDimModTxt(int idDim, int subDim, char *pStr);

    /**
    @ingroup zwapi_dim

    Get current user text type of specified dimension.

    @param [in] idDim index of dimension or dimension bundle
    @param [out] Type text type (0-value, 1-user text, 2-override value)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxDimInqTextType(int idDim, int *Type);

    /**
    @ingroup zwapi_dim

    Set user text type and text string or override expression of specified dimension.

    @param [in] idDim index of dimension or dimension bundle
    @param [in] Type text type (0-value, 1-user text, 2-override value)
    @param [in] text text string or override expression (NULL to ignore when Type=0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_INPUT_ERROR
    */
    extern evxErrors cvxDimModTextType(int idDim, int Type, char *text);

    /**
    @ingroup zwapi_dim

    Get dimension text point location of specified dimension.

    @param [in] idDim index of dimension
    @param [out] TextPnt dimension text origin

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDimInqTxtPnt(int idDim, svxPoint *TextPnt);

    /**
    @ingroup zwapi_dim

    This function is to modify dimension text point location of specified dimension.

    @param [in] idDim index of dimension or dimension bundle
    @param [in] center center flag (1-center, 0-not center)
    @param [in] TextPnt new dimension text origin

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDimModTxtPnt(int idDim, int center, svxPoint *TextPnt);


    //====================================================================================================================
    /** @name Dimension Point */
    //====================================================================================================================
    /**
    @ingroup zwapi_dim

    This function is to inquire the point which this dimension points to,
    The parent of dimension should be PMI in part.

    @param [in] idDim id of dimension
    @param [out] pPos stretchable point coordinate

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDimInqPos(int idDim, svxPoint *pPos);

    /**
    @ingroup zwapi_dim

    Outputs a list of dimension point coordinates of specified dimension.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idDim index of dimension or PMI of dimension type
    @param [out] count number of dimension points
    @param [out]  DimPnts list of dimension point coordinates

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDimInqDimPnts(int idDim, int *count, svxPoint **DimPnts);


    //====================================================================================================================
    /** @name Dimension Line */
    //====================================================================================================================
    /**
    @ingroup zwapi_dim

    Outputs a list of dimension curves of specified dimension.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @note
    All points in svxCurve are the points in Frame that the local
    coordinate system of the curve, the function cvxPntTransform() can be
    used to convert points into points in the global coordinate system.

    @param [in] idDim index of dimension or PMI of dimension type
    @param [out] count number of dimension curves
    @param [out]  DimCrvs list of dimension curves

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDimInqDimLines(int idDim, int *count, svxCurve **DimCrvs);

    /**
    @ingroup zwapi_dim

    Outputs a list of extension curves of specified dimension.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @note
    all points in svxCurve are the points in Frame that the local
    coordinate system of the curve, the function cvxPntTransform() can be
    used to convert points into points in the global coordinate system.

    @param [in] idDim index of dimension or PMI of dimension type
    @param [out] count number of extension curves
    @param [out]  DimCrvs list of extension curves

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDimInqExtLines(int idDim, int *count, svxCurve **DimCrvs);


    //====================================================================================================================
    /** @name Dimension Attribute */
    //====================================================================================================================
    /**********************************************************************
    *! -Dimension Attribute- : zwapi_dwg_dim.h
    *  extern evxErrors cvxDwgDimAtGet(int idDim, svxDimAttr* dmAttr);
    *  extern evxErrors cvxDwgDimAtSet(int idDim, svxDimAttr* dmAttr);
    **********************************************************************/
    /**
    @ingroup zwapi_dim

    Gets the attributes data of specified dimension.
    The different between this function and cvxDwgDimAtGet() is that this function get the
    element attribute of the input dimension.

    @param [in] idDim id of dimension
    @param [in] subDim serial number of sub dimension(0,1,2...), refer to
                       evxHoleDimDataItem for sub-data item of hole dimension
    @param [out] dmAttr dimension attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDimAtGetBySub(int idDim, int subDim, svxDimAttr *dmAttr);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DIM_H */
