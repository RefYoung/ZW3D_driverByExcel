/**
@file zwapi_asm_comp_attribute.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Component Attribute API
Including query the user attribute and display attributes of the components.
*/
/**
@defgroup zwapi_asm_comp_attribute Component Attribute
@ingroup AssemblyObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Component Attribute API
Including query the user attribute and display attributes of the components.
*/

#pragma once
#ifndef ZW_API_COMP_AT_H /* this ifndef surrounds entire header */
#define ZW_API_COMP_AT_H

#include "zwapi_asm_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Component Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_comp_attribute

    Retrieves user attribute data of the specified component in the current active file.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] Comp pick path of component
    @param [out] Count number of user attributes
    @param [out]  UserAt list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCompUserAtGet(svxEntPath *Comp, int *Count, svxAttribute **UserAt);

    /**
    @ingroup zwapi_asm_comp_attribute

    Set user attribute data of the specified component in the current active file.
    a new user attribute is inserted if the user attribute for the specified label
    does not exist.

    @param [in] Comp pick path of component
    @param [in] Count number of user attributes
    @param [in] UserAt list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxCompUserAtSet(svxEntPath *Comp, int Count, svxAttribute *UserAt);

    /**
    @ingroup zwapi_asm_comp_attribute

    Delete user attribute of the specified component in the current active file.
    the function does not delete any attributes if the specified label is an empty
    string or the attribute specified label is not found.

    @param [in] Comp pick path of component
    @param [in] Count number of user attributes (0 to delete all user attributes)
    @param [in] UserAt list of user attributes (NULL to delete all user attributes)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxCompUserAtDel(svxEntPath *Comp, int Count, svxAttribute *UserAt);

    /**
    @ingroup zwapi_asm_comp_attribute

    Outputs display attributes of the specified component. Attributes
    are grabbed from the first face in the component.

    @param [in] CompPath pick path of component
    @param [out] At face attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    */
    extern evxErrors cvxCompFaceAtGet(const svxEntPath *CompPath, svxFaceAt *At);

    /**
    @ingroup zwapi_asm_comp_attribute

    Changes display attributes of the specified components.
    It is assumed the specified components reside in the active part.

    @param [in] Count number of component
    @param [in] CompPath list of pick path of components
    @param [in] At face attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCompFaceAtSet(int Count, svxEntPath *CompPath, svxFaceAt *At);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_COMP_AT_H */
