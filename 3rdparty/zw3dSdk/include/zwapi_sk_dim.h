/**
@file zwapi_sk_dim.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sketch Dimension API
*/
/**
@defgroup zwapi_sk_dim Sketch Dimension API
@ingroup SketchObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Sketch Dimension API
*/

#pragma once
#ifndef ZW_API_SK_DIM_H /* this ifndef surrounds entire header */
#define ZW_API_SK_DIM_H

#include "zwapi_sk_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Dimension Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_sk_dim

    Outputs a list of indices of dimension entities in the active sketch.

    The calling procedure MUST deallocate the output list.

    @param [out] Count number of dimensions
    @param [out] idEnts list of dimension entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqDim(int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_dim

    Get the type(evxConsDimType) of specified dimension constraint.  
    It can't get the corresponding type if "*type = VX_SK_CONSDIM_UNKNOW".

    @param [in] idDim index of dimension constraint
    @param [out] type type of dimension constraint

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxSkInqDimType(int idDim, evxConsDimType *type);

    /**
    @ingroup zwapi_sk_dim

    Outputs the reference flag that belong to the specified id.  
    1-reference flag, 0-no, -1-function fails.

    @param [in] idDim id of dimension to inquire
    @param [out] refFlag reference dimension flag

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
    extern evxErrors cvxSkInqDimRefFlag(int idDim, int *refFlag);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SK_DIM_H */
