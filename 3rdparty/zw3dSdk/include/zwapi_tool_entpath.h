/**
@file zwapi_tool_entpath.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE API of the Entity Path.
*/
/**
@defgroup zwapi_tool_entpath Entity Path
@ingroup ToolModel
@brief
@details
*/

#pragma once
#ifndef ZW_API_TOOL_ENTPATH_H /* this ifndef surrounds entire header */
#define ZW_API_TOOL_ENTPATH_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Entity Path Basic Function */
    //====================================================================================================================
    /**
    @ingroup zwapi_tool_entpath

    Outputs the entity path of the specified entity relative to the currently active root object,
    the entity must be an entity under the currently active root object.

    @param [in] idEntity index of entity
    @param [in] idParent index of parent of entity (sketch, curve list, 0 to ignore)
    @param [out] entPath entity path of entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxEntPathInit(int idEntity, int idParent, svxEntPath *entPath);

    /**
    @ingroup zwapi_tool_entpath

    Outputs current active entity path.

    @param [out] entPath entity path of entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ENT_PATH_ERROR
    */
    extern evxErrors cvxEntPathInqActive(svxEntPath *entPath);

    /**
    @ingroup zwapi_tool_entpath

    Appends an entity to the end of the specified entity path.

    @param [in,out] entPath entity path
    @param [in] idEntity index of entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ENT_PATH_ERROR
    */
    extern evxErrors cvxEntPathAppendEnt(svxEntPath *entPath, int idEntity);

    /**
    @ingroup zwapi_tool_entpath

    Appends an entity path to the end of the specified entity path.

    @param [in,out] dstPath entity path that be appended
    @param [in] srcPath the appended entity path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ENT_PATH_ERROR
    */
    extern evxErrors cvxEntPathAppendPath(svxEntPath *dstPath, const svxEntPath *srcPath);

    /**
    @ingroup zwapi_tool_entpath

    Converts the input entity path from a path that is defined relative to the active 
    target object to an "absolute" path that begins with the parent file of the target object.
    It is assumed that the entity path is an evaluated (i.e. non-persistent) entity path.  
    For example:  
    If the input EntPath's Id[0] = -1, such as Id = { -1, COMP, COMP, FACE};  
       the output EntPath's Id = { -2, PART, COMP, PART COMP, PART, FACE};

    @param [in,out] EntPath entity path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ENT_PATH_ERROR
    */
    extern evxErrors cvxEntPathToRoot(svxEntPath *EntPath);

    /**
    @ingroup zwapi_tool_entpath

    The subroutine is used for comparison two entity paths.

    @param [in] EntPath1 entity path
    @param [in] EntPath2 entity path

    @retval return
    -       0 - the two entity paths are the same
    -       2 - entity path EntPath1 include entity path EntPath2
    -      -2 - entity path EntPath2 include entity path EntPath1
    -       1 - otherwise
    @warning
    -       ZW_API_INVALID_ENT_PATH
    */
    extern int cvxEntPathCmp(const svxEntPath *EntPath1, const svxEntPath *EntPath2);

    /**
    @ingroup zwapi_tool_entpath

    Outputs the entity path of the parent component of the specified entity path.

    @param [in] entPath entity path
    @param [out] parentComp entity path of parent component

    @retval succeeds
    -        ZW_API_NO_ERROR - the entity path has no parent component. 
    -        1 - the entity path has parent component.
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern int cvxEntPathGetParentComp(const svxEntPath *entPath, svxEntPath *parentComp);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_TOOL_ENTPATH_H */
