/**
@file zwapi_part_dim.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Part Dimension API
*/
/**
@defgroup zwapi_part_dim Part Dimension API
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Part Dimension API
*/

#pragma once
#ifndef ZW_API_PART_DIM_H /* this ifndef surrounds entire header */
#define ZW_API_PART_DIM_H

#include "zwapi_part_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Dimension */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_dim

    Outputs a list of dimensions that belong to the specified part.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] File part file name (File[0]=0 or NULL for active file)
    @param [in] Part part name (Part[0]=0 or NULL for active part)
    @param [out] Count number of variables
    @param [out] Variables list of variables

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqDims(const vxLongPath File, const vxRootName Part, int *Count, svxVariable **Variables);

    /**
    @ingroup zwapi_part_dim

    Outputs the pick path list of entities associated with the specified
    PMI dimension.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idDim id of PMI dimension
    @param [out] Count number of entities associated with the dimension
    @param [out] EntPaths pick path of entities associated with the dimension

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqPMIDimEnts(int idDim, int *Count, svxEntPath **EntPaths);

    /**
    @ingroup zwapi_part_dim

    Outputs a list of dimensions' id that belong to the specified part.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] File part file name (File[0]=0 or NULL for active file)
    @param [in] Part part name (Part[0]=0 or NULL for active part)
    @param [out] Count number of dimensions
    @param [out]  IdList list of the dimension's index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqDimIdxs(const vxLongPath File, const vxRootName Part, int *Count, int **IdList);

    //====================================================================================================================
    /** @name PMI */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_dim

    Outputs a list of PMI objects that belong to the currently active part.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] type PMI type to inquire
    @param [out] count number of PMI
    @param [out]  idPMIs list of index of PMI

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqPMIs(evxPMIEntType type, int *count, int **idPMIs);

    /**
    @ingroup zwapi_part_dim

    Get the type(evxPMIEntType) of specified PMI entity.  
    It can't get the corresponding type if "*type = VX_PMI_ALL".

    @param [in] idPMI index of PMI or base object of PMI
    @param [out] type type of PMI

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPMIInqType(int idPMI, evxPMIEntType *type);

    /**
    @ingroup zwapi_part_dim

    Get index of base object of specified PMI entity.

    @param [in] idPMI index of PMI
    @param [out] idBaseObj index of base object of PMI

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
    extern evxErrors cvxPMIInqBaseEnt(int idPMI, int *idBaseObj);

    /**
    @ingroup zwapi_part_dim

    Outputs the pick path list of entities associated with the specified  
    PMI entity. the function has the same function as cvxPartInqPMIDimEnts(),  
    but the function can get the associated entities of all types of PMI.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idPMI index of PMI or base object of PMI
    @param [out] count number of entities associated with the PMI
    @param [out]  entPaths pick path of entities associated with the PMI

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPMIInqAssoEnts(int idPMI, int *count, svxEntPath **entPaths);

    /**
    @ingroup zwapi_part_dim

    Check whether the PMI is valid.

    @param [in] idPMI index of PMI
    @param [out] isValid whether PMI is valid (1: valid; 0: invalid)

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
    extern evxErrors cvxPMIInqValid(int idPMI, int *isValid);


    //====================================================================================================================
    /** @name Symbol */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_dim

    Get the reference point coordinate of specified symbol object.


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxSymInqRefPnt(int idSym, svxPoint *RefPnt);

    /**
    @ingroup zwapi_part_dim

    Outputs a list of leader curves of specified symbol.

    @note
    all points in svxCurve are the points in Frame that the local  
    coordinate system of the curve, the function cvxPntTransform() can be  
    used to convert points into points in the global coordinate system.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idSym index of symbol or PMI of symbol type
    @param [out] count number of leader curves
    @param [out]  LeadCrvs list of leader curves

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
    extern evxErrors cvxSymInqLeadLines(int idSym, int *count, svxCurve **LeadCrvs);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PART_DIM_H */
