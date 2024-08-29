/**
@file zwapi_cmd_sk_app.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sketch App API
It contains the interfaces of the third-party functions expected to be hung in 
the sketch environment.
These interface need to be authorized to use.
*/
/**
@defgroup zwapi_cmd_sk_app Sketch Apps
@ingroup SketchCommands
@brief
@details THE MODULE FOR THE ZW3D Sketch App API
It contains the interfaces of the third-party functions expected to be hung in
the sketch environment.
These interface need to be authorized to use.
*/

#pragma once
#ifndef ZW_API_SK_APP_H /* this ifndef surrounds entire header */
#define ZW_API_SK_APP_H

#include "zwapi_cmd_sk_app_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


    //====================================================================================================================
    /** @name Nesting */
    //====================================================================================================================

    /**
    @ingroup zwapi_cmd_sk_app

    Initialize the structure svxSkNestingProfileData.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data  profile data of sketch nesting.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT

    */
    extern evxErrors cvxSkNestingProfileDataInit(svxSkNestingProfileData *data);

    /**
    @ingroup zwapi_cmd_sk_app

    Initialize the structure svxSkNestingBlankData.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data  blank data of sketch nesting.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT

    */
    extern evxErrors cvxSkNestingBlankDataInit(svxSkNestingBlankData *data);

    /**
    @ingroup zwapi_cmd_sk_app

    Initialize the parameters of the cvxSkNesting().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out]  data nesting data of sketch.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkNestingInit(svxSkNestingData *data);

    /**
    @ingroup zwapi_cmd_sk_app

    Nesting can directly pick any loop enclosed geometries 
    as Nesting Profiles and Blank to calculate nesting, 
    the result include a sketch block and a report file in HTML format.

    Users can use cvxSkNestingProfileDataInit() and cvxSkNestingBlankDataInit() to initialize the 
    structures svxSkNestingProfileData and svxSkNestingBlankData respectively.

    Then use cvxSkNestingInit() to initialize the structure svxSkNestingData.This interface will 
    not allocate space for the points in the structure, so the users need toassign values to the 
    sub structure pointers in the structure.

    @note
    Nesting command needs a specified dongle key inserted into user's PC to activate before starting.

    @param [in] data nesting data of sketch

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_LICENSE_NESTING_ERROR
    */
    extern evxErrors cvxSkNesting(const svxSkNestingData *data);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SK_APP_H */