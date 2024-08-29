/**
@file zwapi_cm_folder.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D API of the Cam Folder.
*/
/**
@defgroup zwapi_cm_folder Cam Folder API
@ingroup CamModel
@brief
@details THE MODULE FOR THE ZW3D API of the Cam Folder.
*/

#pragma once
#ifndef ZW_API_CAM_FOLDER_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_FOLDER_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Folder Data */
    //====================================================================================================================
    /**
    @brief cam folder attribute
    @ingroup zwapi_cm_folder
    */
    typedef enum evxCmFolderAttr
    {
        CM_FOLDER_NAME,
        CM_FOLDER_SUB
    } evxCmFolderAttr;

    //====================================================================================================================
    /** @name Cam Folder Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cm_folder

    Inquire the attributes of the folder. Its value is output via "value".

    @verbatim
    value->type    &  value->cnt  &  value->data depend on "attr"
    ZW_CAM_ATTR_VALUE_TYPE_STRING    <=32                 CM_FOLDER_NAME
    ZW_CAM_ATTR_VALUE_TYPE_INTEGER   number      index    CM_FOLDER_SUB
    @endverbatim

    User needs to allocate memory for "value", and free memory for "value->data".

    @param [in] idx_folder index of the folder
    @param [in] cnt cout of the attributes
    @param [in] attr list of evxCmFolderAttr user wanna get
    @param [out] value list of values return

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CAM_OPTYPE_ERROR
    */
    extern evxErrors cvxCmFolderGetAttr(int idx_folder, int cnt, int *attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_folder

    Get all operations under a folder node.

    @param [in] folder_name folder name
    @param [out] op_cnt count of operations in the folder
    @param [out] op_list operations' index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFolderInqOps(const vxLongPath folder_name, int *op_cnt, int **op_list);

    /**
    @ingroup zwapi_cm_folder

    Insert a Folder to the OPS item.

    @param [out] idx_out index of folder

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmOpInsFolder(int *idx_out);

    /**
    @ingroup zwapi_cm_folder

    Get tree index by object db index.

    @param [in] idx_in object index
    @param [out] tree_id tree index
    @param [in] treeType tree node type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CAM_GETOPNAME_ERROR
    -        ZW_API_CAM_GETCMCOMP_ERROR
    -        ZW_API_CAM_GETFOLDERNAME_ERROR
    -        ZW_API_CAM_GETFTR_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmObjGetTreeId(int idx_in, int *tree_id, evxCmTreeType treeType);

    /**
    @ingroup zwapi_cm_folder

    Get object's ui position by object db index and object tree-type.

    @param [in] idx_in object index
    @param [out] ui_pos tree index
    @param [in] treeType tree node type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETOPNAME_ERROR
    -        ZW_API_CAM_GETCMCOMP_ERROR
    -        ZW_API_CAM_GETFOLDERNAME_ERROR
    -        ZW_API_CAM_GETFTR_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmObjGetUiPos(int idx_in, int *ui_pos, evxCmTreeType treeType);


    /**
    @ingroup zwapi_cm_folder

    Change the folder name.

    @param [in] idx_fld folder index
    @param [in] fld_newName new folder name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFldRename(int idx_fld, vxLongName fld_newName);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_FOLDER_H */
