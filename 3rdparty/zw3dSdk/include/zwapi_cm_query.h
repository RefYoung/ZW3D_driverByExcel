/**
@file zwapi_cm_query.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D API of the Cam Query.
*/
/**
@defgroup zwapi_cm_query Cam Query
@ingroup CamModel
@brief
@details THE MODULE FOR THE ZW3D API of the Cam Query.
*/

#pragma once
#ifndef ZW_API_CAM_QUERY_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_QUERY_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Query Data */
    //====================================================================================================================
    /**
    @brief cam object type
    @ingroup zwapi_cm_query
    */
    typedef enum evxCmObjType
    {
        CM_OPERATION,
        CM_OPFOLDER,
        CM_TOOL,
        CM_MACHINE,
        CM_CMCOMP,
        CM_FTR,
        CM_FRAME,
        CM_OUT
    } evxCmObjType;

    //====================================================================================================================
    /** @name Cam Query Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cm_query

    Inquire the indexes of this type in the active CamPlan.

    @param [in] type cam object type
    @param [out] cnt the amount this type of objects
    @param [out] idx_obj the index of the object list, user is response to free this memory

    @retval succeeds
    -         ZW_API_NO_ERROR
    @retval fail
    -         ZW_API_GENERAL_ERROR
    -         ZW_API_CAM_GETSETUP_ERROR
    -         ZW_API_CAM_GETMACH_ERROR
    -         ZW_API_CAM_GETFOLDER_ERROR
    -         ZW_API_CAM_GETTACTIC_ERROR
    -         ZW_API_CAM_GETTOOL_ERROR
    -         ZW_API_CAM_GETCMCOMP_ERROR
    -         ZW_API_CAM_GETFTR_ERROR
    -         ZW_API_CAM_GETFRAME_ERROR
    -         ZW_API_CAM_GETOUT_ERROR
    -         ZW_API_INVALID_INPUT
    -         ZW_API_INVALID_OUTPUT
    -         ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmInqAl(evxCmObjType type, int *cnt, int **idx_obj);

    /**
    @ingroup zwapi_cm_query

    Verify all operations. There must be a stock.

    @param [out] gouge check gouge value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmSolidVerify(int *gouge);

    /**
    @ingroup zwapi_cm_query

    Detect clash of operations, the operations should have been calculated.
    If clash happened, corresponding toolpath will change its color.

    @param [in] partIdx idx of part
    @param [in] stockIdx idx of stock
    @param [in] cnt number of operations
    @param [in] idx_op index list of operations

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETSETUP_ERROR
    */
    extern evxErrors cvxCmClashDetect(int partIdx, int stockIdx, int cnt, int *idx_op);

    /**
    @ingroup zwapi_cm_query

    Detect gouge of operations, the operations should have been calculated.
    If gouge happened, corresponding toolpath will change its color.

    @param [in] partIdx idx of part
    @param [in] stockIdx idx of stock
    @param [in] cnt number of operations
    @param [in] idx_op index list of operations

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETSETUP_ERROR
    */
    extern evxErrors cvxCmGougeDetect(int partIdx, int stockIdx, int cnt, int *idx_op);

    /**
    @ingroup zwapi_cm_query

    You can only specify either dbstring or guistring but not both. Whichever
    one is not specified is returned as output. If the requested string cannot
    be found then the input string is returned as output.

    @param [in] form form name
    @param [in] field field id number
    @param [in] casesensitive case sensitive comparison flag
    @param [in,out] dbstring DB string
    @param [in,out] guistring GUI string
    @param [out] ifound flag to see if item was found

    @retval succeeds
    -         ZW_API_NO_ERROR
    @retval fail
    -         ZW_API_GENERAL_ERROR
    -         ZW_API_INVALID_INPUT
    -         ZW_API_INVALID_OUTPUT
    -         ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmConfigFileGetString(const char *form, int field, int casesensitive,
                                              char *dbstring, char *guistring, int *ifound);

    /**
    @ingroup zwapi_cm_query

    Inquire the name of the operation.

    @param [in] idx_op index of the operation
    @param [out] opName name of the operation

    @retval succeeds
    -         ZW_API_NO_ERROR
    @retval fail
    -         ZW_API_GENERAL_ERROR
    -         ZW_API_INVALID_OUTPUT
    -         ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmInqOpName(int idx_op, vxLongName opName);

    /**
    @ingroup zwapi_cm_query

    Get the object index for the object with the specified name.

    @param [in] objClass class of object
    @param [in] sName name of object
    @param [out] index index of object found (or -1 if not found)

    @retval succeeds
    -         ZW_API_NO_ERROR
    @retval fail
    -         ZW_API_GENERAL_ERROR
    -         ZW_API_CAM_GETSETUP_ERROR
    -         ZW_API_CAM_GETMACH_ERROR
    -         ZW_API_CAM_GETOPERATION_ERROR
    -         ZW_API_CAM_GETFOLDER_ERROR
    -         ZW_API_CAM_GETTACTIC_ERROR
    -         ZW_API_CAM_GETTOOL_ERROR
    -         ZW_API_CAM_GETCMCOMP_ERROR
    -         ZW_API_CAM_GETFTR_ERROR
    -         ZW_API_CAM_GETFRAME_ERROR
    -         ZW_API_CAM_GETOUT_ERROR
    -         ZW_API_INVALID_INPUT
    -         ZW_API_INVALID_OUTPUT
    -         ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmInqIndexFromName(evxCmObjType objClass, vxLongName sName, int *index);

    /**
    @ingroup zwapi_cm_query

    In CAM Environment, get the Component CAD index.

    @param [in] comp_name Component name
    @param [out] comp_index CAD index of Component found (or -1 if not found)

    @retval succeeds
    -         ZW_API_NO_ERROR
    @retval fail
    -         ZW_API_CAM_GETCMCOMP_ERROR
    -         ZW_API_INVALID_OUTPUT
    -         ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmCompGetIdxFromName(const char *comp_name, int *comp_index);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_QUERY_H */
