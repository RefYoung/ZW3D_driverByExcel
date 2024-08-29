/**
@file zwapi_cm_machine.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D API of the Cam Machine.
*/
/**
@defgroup zwapi_cm_machine Cam Machine
@ingroup CamModel
@brief
@details THE MODULE FOR THE ZW3D API of the Cam Machine.
*/

#pragma once
#ifndef ZW_API_CAM_MACH_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_MACH_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Machine Data */
    //====================================================================================================================
    /**
    @brief cam machine class
    @ingroup zwapi_cm_machine
    */
    typedef enum evxCmMachClass
    {
        TWO_AXIS_MC,
        THREE_AXIS_MC
    } evxCmMachClass;

    /**
    @brief cam machine type
    @ingroup zwapi_cm_machine
    */
    typedef enum evxCmMachType
    {
        CM_MACH_TYPE_VERTICAL,
        CM_MACH_TYPE_HORIZNTAL
    } evxCmMachType;

    /**
    @brief cam machine sub type
    @ingroup zwapi_cm_machine
    */
    typedef enum evxCmMachSubType
    {
        CM_MACH_SUBTYPE_ROTATING_HEAD,
        CM_MACH_SUBTYPE_ROTATING_TABLE
    } evxCmMachSubType;

    /**
    @brief cam machine cut type
    @ingroup zwapi_cm_machine
    */
    typedef enum evxCmMachCutCompenation
    {
        CM_MACH_CUT_COMPENSATION_NONE,
        CM_MACH_CUT_COMPENSATION_LENGTH,
        CM_MACH_CUT_COMPENSATION_CENTER
    } evxCmMachCutCompenation;

    /**
    @brief cam machine attribute
    @ingroup zwapi_cm_machine
    */
    typedef enum evxCmMachAttr
    {
        /*  Definition Form */
        CM_MACH_NAME,
        CM_MACH_CLASS,
        CM_MACH_TYPE,
        CM_MACH_SUBTYPE,
        CM_MACH_POST_CONFIGURATION,
        CM_MACH_CUT_COMPENSATION,
        /*  Others */
    } evxCmMachAttr;

    //====================================================================================================================
    /** @name Cam Machine Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cm_machine

    Insert a machine to the cam plan.

    @param [in] machine_class machine class
    @param [in] machine_type machine type
    @param [in] sub_type machine sub_type
    @param [out] idx_machine index of machine

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_FORMDEFINE_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_CAM_GETMACHNAME_ERROR
    -        ZW_API_CAM_GETMACH_ERROR
    -        ZW_API_CAM_GETFORMITEM_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_CAM_GUITOTXT_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmMachineInsert(evxCmMachClass machine_class, evxCmMachType machine_type, evxCmMachSubType sub_type, int *idx_machine);

    /**
    @ingroup zwapi_cm_machine

    Set the machine to active.

    @param [in] idx_machine machine index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CAM_GETMACHNAME_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmMachineActive(int idx_machine);

    /**
    @ingroup zwapi_cm_machine

    Delete the machine.

    @param [in] idx_machine machine index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmMachineDelete(int idx_machine);

    /**
    @ingroup zwapi_cm_machine

    Get attribute of a machine.

    @param [in] idx_machine index of machine
    @param [in] attr type of attribute
    @param [out] value value of attribute, user need to free the memory

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETMACHNAME_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmMachineGetAttr(int idx_machine, evxCmMachAttr attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_machine

    Modify the machine's attribute .

    @verbatim
    "value->type"          &     "value->cnt"   &value->data depends on     "attr", as follows:
    ZW_CAM_ATTR_VALUE_TYPE_STRING       <=32                                CM_MACH_NAME
                                                                            CM_MACH_POST_CONFIGURATION
    ZW_CAM_ATTR_VALUE_TYPE_INTEGER      1       evxCmMachClass              CM_MACH_CLASS
                                                evxCmMachType               CM_MACH_TYPE
                                                evxCmMachSubType            CM_MACH_SUBTYPE
                                                evxCmMachCutCompenation     CM_MACH_CUT_COMPENSATION
    @endverbatim

    @param [in] idx_machine index of the machine
    @param [in] attr type of attribute
    @param [in] value value of attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmMachineSetAttr(int idx_machine, evxCmMachAttr attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_machine

    Insert a tool to the active machine's tool changer.

    @param [in] idx_toolchanger tool index
    @param [in] Location location
    @param [in] Diameter cutter compensation along Diameter
    @param [in] Height cutter compensation along Hight

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxCmToolChangerInsert(int idx_toolchanger, int Location, int Diameter, int Height);

    /**
    @ingroup zwapi_cm_machine

    Delete the tool changer in the active machine.

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.

    @param [in] idx_toolchanger tool index

    */
    extern evxErrors cvxCmToolChangerDelete(int idx_toolchanger);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_MACH_H */
