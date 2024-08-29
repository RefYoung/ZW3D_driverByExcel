/**
@file zwapi_asm_constraint.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Component Constraints Query API
Including query the constraints of the components.
*/
/**
@defgroup zwapi_asm_constraint Assembly Constraint API
@ingroup AssemblyObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Component Constraints Query API
Including query the constraints of the components.
*/

#pragma once
#ifndef ZW_API_ASM_CONSTRAINT_H /* this ifndef surrounds entire header */
#define ZW_API_ASM_CONSTRAINT_H

#include "zwapi_asm_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Assembly Constraint */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_constraint

    Get the constraint type of specified constraint.

    @param [in] idCons index of constraint
    @param [out] consType constraint type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_ONJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DAT_GET_ERROR
    */
    extern evxErrors cvxConsInqType(int idCons, evxConsType *consType);

    /**
    @ingroup zwapi_asm_constraint

    Outputs a list of pick path of entities associated with the specified constraint.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idCons index of constraint
    @param [out] count number of entities associated with constraint
    @param [out] entPaths list of entity paths associated with constraint

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_ONJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_tYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxConsInqRefEnts(int idCons, int *count, svxEntPath **entPaths);

    /**
    @ingroup zwapi_asm_constraint

    Get custom data of the specified constraint.

    @param [in] idCons index of common constraint
    @param [out] ConsData data of common constraint

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_ONJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxConsInqConsData(int idCons, svxConsData *ConsData);

    /**
    @ingroup zwapi_asm_constraint

    Get the constraint state of specified component.

    @param [in] idComp index of component or shape
    @param [out] consState constraint state of component

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_ONJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxCompInqConsState(int idComp, evxConsState *consState);

    /**
    @ingroup zwapi_asm_constraint

    Outputs a list of indices of the constraints associated with the specified component.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] CompPath pick-path of component
    @param [out] count number of constraints
    @param [out] cons list of constraint ids

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ENT_PATH_ERROR
    */
    extern evxErrors cvxCompInqConstraints(svxEntPath *CompPath, int *count, int **cons);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_ASM_CONSTRAINT_H */
