/**
@file zwapi_cm_comp.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D API of the Cam Components.
*/
/**
@defgroup zwapi_cm_comp Cam Component API
@ingroup CamModel
@brief
@details THE MODULE FOR THE ZW3D API of the Cam Components.
*/

#pragma once
#ifndef ZW_API_CAM_COMP_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_COMP_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Component Data */
    //====================================================================================================================
    /**
    @brief cam component class
    @ingroup zwapi_cm_comp
    */
    typedef enum evxCmCompClass
    {
        ZW_CAM_COMP_CLASS_PART,
        ZW_CAM_COMP_CLASS_CLAMP,
        ZW_CAM_COMP_CLASS_STOCK,
        ZW_CAM_COMP_CLASS_TABLE,
        ZW_CAM_COMP_CLASS_TOOLHOLDER,
        ZW_CAM_COMP_CLASS_ATTACHMENT
    } evxCmCompClass;

    /**
    @brief cam component attribute
    @ingroup zwapi_cm_comp
    */
    typedef enum evxCmCompAtrr
    {
        ZW_CAM_COMP_ATTR_FACES,
        ZW_CAM_COMP_ATTR_CLASS,
        ZW_CAM_COMP_ATTR_CDCOMP
    } evxCmCompAtrr;

    //====================================================================================================================
    /** @name Cam Component Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cm_comp

    Insert the component into active CamPlan. Its id is output via "idx_cmcomp".

    @param [in] fileName name of file for object selection
    @param [in] shapeName name of shape in file for object selection
    @param [out] idx_CmComp the index of the component object

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmCompInsert(char *fileName, char *shapeName, int *idx_CmComp);

    /**
    @ingroup zwapi_cm_comp

    Delete the component in active CamPlan.

    @param [in] idx_CmComp index of the component

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmCompDelete(int idx_CmComp);

    /**
    @ingroup zwapi_cm_comp

    Inquire the component's attributes. Its value is output via "pValue".

    If ZW_CAM_COMP_ATTR_CDCOMP is one value of attr, the data of pValue could be used for APIs of
    "assembly component" in VxApiPart.c(e.g. cvxCompInqPart()...).

    If ZW_CAM_COMP_ATTR_CLASS is one value of attr, the data of pValue is one of evxCmCompClass.

    The data of svxCmAttrValue should be converted according to the type of svxCmAttrValue.

    @param [in] idx_Cmcomp index of the component
    @param [in] cnt count of attributes user wanna inquire
    @param [in] attr the enumerations user wanna inquire
    @param [out] pValue the values return; user needs to free the memory

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_GETCOMPVDATA_ERROR
    -        ZW_API_CAM_GETCOMPINDEX_ERROR
    -        ZW_API_OBJ_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_GETCOMPCLASS_ERROR
    -        ZW_API_CAM_GETCOMPINDEX_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmCompGetAttr(int idx_Cmcomp, int cnt, evxCmCompAtrr *attr, svxCmAttrValue **pValue);

    /**
    @ingroup zwapi_cm_comp

    Set the component attributes.  
    "attr" should not be "ZW_CAM_COMP_ATTR_FACES".  
    value->type:   ZW_CAM_ATTR_VALUE_TYPE_INTEGER   
    value->cnt:    1   
    value->data:   evxCmCompClass

    @param [in] idx_Cmcomp index of the component
    @param [in] cnt count of attributes user wanna set
    @param [in] attr the enumerations user wanna set
    @param [in] value the values needed

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmCompSetAttr(int idx_Cmcomp, int cnt, evxCmCompAtrr *attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_comp

    Get the components' information, including name and file path.

    @param [out] compCnt number of components
    @param [out] compNames name of components
    @param [out] compPaths path of components

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmCompInqInfo(int *compCnt, vxPath **compNames, vxPath **compPaths);

    /**
    @ingroup zwapi_cm_comp

    Get the components' information, including name and file path.

    @param [out] compCnt number of components
    @param [out] compNames name of components
    @param [out] compPaths path of components

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmCompInqInfoByLongPath(int *compCnt, vxLongPath **compNames, vxLongPath **compPaths);

    /**
    @ingroup zwapi_cm_comp

    Adds a new sketch to the active cam plan, aligned with the
    specified insertion plane.  The sketch is activated for
    editing.

    If "idSketch" is not NULL, the id of the new sketch is
    output.

    @param [in] Plane sketch insertion plane
    @param [out] idSketch id of new sketch

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCmPlanSkNew(svxMatrix *Plane, int *idSketch);

    /**
    @ingroup zwapi_cm_comp

    Update the Status of Geometries.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETCOMPVDATA_ERROR
    */
    extern evxErrors cvxCmGeomUpdata();

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_COMP_H */
