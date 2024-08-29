/**
@file zwapi_cm_frame.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D API of the Cam Frame.
*/
/**
@defgroup zwapi_cm_frame Cam Frame API
@ingroup CamModel
@brief
@details THE MODULE FOR THE ZW3D API of the Cam Frame.
*/

#pragma once
#ifndef ZW_API_CAM_FRAME_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_FRAME_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Frame Data */
    //====================================================================================================================
    /**
    @brief cam frame attribute
    @ingroup zwapi_cm_frame
    */
    typedef enum evxCmFrameAttr
    {
        /*  Definition Form */
        CM_FRAME_NAME,
        CM_FRAME_CLEAR_Z,
        CM_FRAME_APPROACH_Z,
        CM_FRAME_RETRACT_Z
    } evxCmFrameAttr;

    //====================================================================================================================
    /** @name Cam Frame Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cm_frame

    Insert the Frame based on Cartesian coordinate system in the active CamPlan.
    The 3 svxPoints are not used at this version.

    @param [in] frame_name fame name wanna set
    @param [in] origin_point origin point to construct the coordinate system
    @param [in] x_point point in axis X
    @param [in] y_point point in axis Y
    @param [out] idx_frame index of the frame

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CAM_FORMDEFINE_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_CAM_GETFORMITEM_ERROR
    */
    extern evxErrors cvxCmFrameInsert(vxName frame_name, svxPoint origin_point, svxPoint x_point, svxPoint y_point, int *idx_frame);

    /**
    @ingroup zwapi_cm_frame

    Delete the frame in CamPlan.

    @param [in] idx_frame index of the frame

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFrameDelete(int idx_frame);

    /**
    @ingroup zwapi_cm_frame

    Inquire the Frame attributes.

    @param [in] idx_frame index of the frame
    @param [in] attr enumeration of the attribute
    @param [out] value return value; user needs to free the memory

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFrameGetAttr(int idx_frame, evxCmFrameAttr attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_frame

    Set the Frame attributes.

    @verbatim
    "value->type"                 &     "value->cnt" depends on "attr", as follows:
    ZW_CAM_ATTR_VALUE_TYPE_STRING       <=32     CM_FRAME_NAME
    ZW_CAM_ATTR_VALUE_TYPE_DOUBLE       1        CM_FRAME_CLEAR_Z
                                                 CM_FRAME_APPROACH_Z
                                                 CM_FRAME_RETRACT_Z
    @endverbatim

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] idx_frame index of the frame
    @param [in] attr enumeration of the attribute
    @param [in] value the value wanna set

    */
    extern evxErrors cvxCmFrameSetAttr(int idx_frame, evxCmFrameAttr attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_frame

    Insert the Frame based on Cartesian coordinate system in the active CamPlan.
    The 3 svxPoints are not used at this version.

    @param [in] frame_name frame name wanna set
    @param [in] frame_mat frame matrix
    @param [out] idx_frame index of the frame

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_FORMDEFINE_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFrameInsert2(const vxName frame_name, svxMatrix frame_mat, int *idx_frame);

    /**
    @ingroup zwapi_cm_frame

    Insert the Frame into the operation

    @param [in] idxOp index of the operation
    @param [in] idxFrame index of the frame

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETFRAME_ERROR
    -        ZW_API_CAM_GETTACTIC_ERROR
    -        ZW_API_CAM_GETOPERATION_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmOpAddFrame(int idxOp, int idxFrame);

    /**
    @ingroup zwapi_cm_frame

    Get the frame matrix.

    @param [in] idxFrame index of the frame
    @param [out] frameMat frame matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETFRAME_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFrameGetMatrix(int idxFrame, svxMatrix *frameMat);

    /**
    @ingroup zwapi_cm_frame

    Get the index of active frame

    @param [out] idx_actFrame index of active frame

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETFRAME_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */

    extern evxErrors cvxCmFrameGetActive(int *idx_actFrame);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_FRAME_H */
