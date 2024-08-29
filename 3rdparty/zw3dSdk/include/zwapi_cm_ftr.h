/**
@file zwapi_cm_ftr.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D API of the Cam Features.
*/
/**
@defgroup zwapi_cm_ftr Cam Feature API
@ingroup CamModel
@brief
@details THE MODULE FOR THE ZW3D API of the Cam Features.
*/

#pragma once
#ifndef ZW_API_CAM_FEATURE_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_FEATURE_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Features Data */
    //====================================================================================================================
    /**
    @brief cam feature type
    @ingroup zwapi_cm_ftr
    */
    typedef enum evxCmFtrType
    {
        ZW_CAM_FEATURE_SOLID   = 1,  /**<@brief  solid feature */
        ZW_CAM_FEATURE_POCKET  = 2,  /**<@brief  pocket feature */
        ZW_CAM_FEATURE_HOLE    = 3,  /**<@brief  hole feature */
        ZW_CAM_FEATURE_SLOT    = 4,  /**<@brief  slot feature */
        ZW_CAM_FEATURE_PROFILE = 5,  /**<@brief  profile feature */
        ZW_CAM_FEATURE_STEP    = 6,  /**<@brief  step feature */
        ZW_CAM_FEATURE_SURFACE = 7,  /**<@brief  surface feature */
        ZW_CAM_FEATURE_CHAMFER = 8,  /**<@brief  chamfer feature */
        ZW_CAM_FEATURE_CRND    = 9,  /**<@brief  cround feature */
        ZW_CAM_FEATURE_FACE    = 10, /**<@brief  face feature */
        ZW_CAM_FEATURE_BOSS    = 11, /**<@brief  boss feature */
        ZW_CAM_FEATURE_FLAT    = 12  /**<@brief  flat region feature */
    } evxCmFtrType;

    /**
    @brief cam feature attribute
    @ingroup zwapi_cm_ftr
    */
    typedef enum evxCmFtrAttr
    {
        CM_FEATURE_TYPE
    } evxCmFtrAttr;

    /**
    @brief cam profile feature type
    @ingroup zwapi_cm_ftr
    */
    typedef enum evxCmFtrProfileType
    {
        PART,
        CONTAIN
    } evxCmFtrProfileType;

    /**
    @brief cam profile feature curve attribute
    @ingroup zwapi_cm_ftr
    */
    typedef enum evxCmProfileCuvAttr
    {
        V_CM_PRF_OFFSET  = 0, /**<@brief curve's offset */
        V_CM_PRF_DRAFT   = 1, /**<@brief curve's draft */
        V_CM_PRF_TOOLLOC = 2, /**<@brief curve's tool location */
    } evxCmProfileCuvAttr;

    /**
    @brief cam profile feature tool location type
    @ingroup zwapi_cm_ftr
    */
    typedef enum evxCmProfileTolLoc
    {
        V_CM_PRF_ON   = 0, /**<@brief tool is on curve */
        V_CM_PRF_TAN  = 1, /**<@brief tool is tangent curve */
        V_CM_PRF_PAST = 2, /**<@brief tool is past curve */
    } evxCmProfileTolLoc;

    //====================================================================================================================
    /** @name Cam Features Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cm_ftr

    Add a feature in the component.

    @param [in] ftrType type of the feature
    @param [in] idx_CmComp index of the component
    @param [in] cnt count of the geometries
    @param [in] geom geometry indexes
    @param [out] idx_FtrGrp index of feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    */
    extern evxErrors cvxCmFtrInsert(evxCmFtrType ftrType, int idx_CmComp, int cnt, int *geom, int *idx_FtrGrp);

    /**
    @ingroup zwapi_cm_ftr

    Add a feature in the component.

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] ftrType type of the feature
    @param [in] cnt count of the geometries
    @param [in] geom geometry indexes
    @param [in] depths depths of holes
    @param [out] idx_FtrGrp index of feature

    */
    extern evxErrors cvxCmFtrInsertNew(evxCmFtrType ftrType, int cnt, int *geom, double *depths, int *idx_FtrGrp);

    /**
    @ingroup zwapi_cm_ftr

    Add a feature in the component.
    This function provides the ability to generate features other than holes.
    Currently, profile,surface,chamfer and cround are supported.

    @param [in] ftrType type of the feature
    @param [in] ftrName feature name which needs to be added to the new member
    @param [in] cnt count of the geometries
    @param [in] geom geometry indexes
    @param [out] idxFtrGrp index of feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CAM_GETCMCOMP_ERROR
    -        ZW_API_CAM_GETCOMPVDATA_ERROR
    -        ZW_API_CAM_GUITOTXT_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFtrInsertWithoutHoles(evxCmFtrType ftrType, const vxName ftrName, int cnt, int *geom, int *idxFtrGrp);

    /**
    @ingroup zwapi_cm_ftr

    Add a feature in the sketch.

    @param [in] ftrType type of the feature
    @param [in] ftrName feature name which needs to be added to the new member
    @param [in] idxSk index of the sketch where the geom is located.
    @param [in] cnt feature data
    @param [in] geom index of geom
    @param [out] idxFtrGrp index of feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CAM_GETCMCOMP_ERROR
    -        ZW_API_CAM_GETCOMPVDATA_ERROR
    -        ZW_API_CAM_GUITOTXT_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFtrInsertSK(evxCmFtrType ftrType, const vxName ftrName, int idxSk, int cnt, int *geom, int *idxFtrGrp);

    /**
    @ingroup zwapi_cm_ftr

    Get component's geom index.

    The idxComp output array must be deallocated with cvxMemFree().
    @param [out] comp_cnt count of components
    @param [out] idxComp index of components

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFtrGetComp(int *comp_cnt, int **idxComp);

    /**
    @ingroup zwapi_cm_ftr

    Get curves' index in part

    @param [out] numLine number of curve
    @param [out] lstLines list of curve id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmGetCrvId(int *numLine, int **lstLines);

    /**
    @ingroup zwapi_cm_ftr

    Add a hole feature in the component.

    @param [in] ftrName feature name
    @param [in] cnt count of the geometries
    @param [in] geom geometry indexes
    @param [in] depths depths of holes
    @param [out] idxFtrGrp index of feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CAM_GETCMCOMP_ERROR
    -        ZW_API_CAM_GETCOMPVDATA_ERROR
    -        ZW_API_CAM_GUITOTXT_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFtrInsertHole(const vxName ftrName, int cnt, int *geom, double *depths, int *idxFtrGrp);

    /**
    @ingroup zwapi_cm_ftr

    Set cam plan display mode.

    @param [in] iMode display mode

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmPlanDispSetMode(evxCmPlanDispMode iMode);

    /**
    @ingroup zwapi_cm_ftr

    Reset cam plan display mode to CM_ACTIVE_PROCESS.

    @param

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmPlanDispResetMode();

    /**
    @ingroup zwapi_cm_ftr

    Delete the feature.

    @param [in] idx_ftrgrp index of the feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFtrDelete(int idx_ftrgrp);

    /**
    @ingroup zwapi_cm_ftr

    Inquire the attribute of the feature.

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] idx_ftrgrp index of the feature
    @param [in] cnt count of the attributes
    @param [in] attr Attributes of interest
    @param [out] value the values return; user needs to free the memory

    */
    extern evxErrors cvxCmFtrGetAttr(int idx_ftrgrp, int cnt, evxCmFtrAttr *attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_ftr

    Modify the attribute of the feature.

    @verbatim
    value->type:   ZW_CAM_ATTR_VALUE_TYPE_INTEGER
    value->cnt:    1
    value->data:   0("part")
                   1("contain")
    @endverbatim

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] idx_ftrgrp index of the feature
    @param [in] cnt count of the attributes
    @param [in] attr Attributes of interest
    @param [in] value values to assign to the feature

    */
    extern evxErrors cvxCmFtrSetAttr(int idx_ftrgrp, int cnt, evxCmFtrAttr *attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_ftr

    Change the feature name.

    @param [in] idx_ftr cam tree index
    @param [in] newFtrName new name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFtrRename(int idx_ftr, vxLongName newFtrName);

    /**
    @ingroup zwapi_cm_ftr

    Change the profile curve parameters

    @param [in] prof_idx profile feature index
    @param [in] curve_idx curve in profile feature index
    @param [in] newOffset offset value
    @param [in] newDraft draft value
    @param [in] tolloc tool location value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETFTRGRP_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmProfSetAttr(int prof_idx, int curve_idx, double newOffset, double newDraft, int tolloc);


    /**
    @ingroup zwapi_cm_ftr

    Inquire the type of feature

    @param[in] idx_Ftr profile feature index
    @param [out] ftrType feature class

    @retval succeeds
    - ZW_API_NO_ERROR
    @retval fail
    - ZW_API_GENERAL_ERROR
    - ZW_API_INVALID_OUTPUT
    - ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmFtrInqType(int idx_Ftr, evxCmFtrType *ftrType);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_FEATURE_H */
