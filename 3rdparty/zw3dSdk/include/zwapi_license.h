/**
@file zwapi_license.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D License API
*/
/**
@defgroup zwapi_license License
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D License API
*/

#pragma once
#ifndef ZW_API_LIC_H /* this ifndef surrounds entire header */
#define ZW_API_LIC_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name License */
    //====================================================================================================================
    /**
    @ingroup zwapi_license

    Get current authorized module list, the "szModules" is split by '\n', e.g. "ZW3D_BASE_MODULES\nZW3D_2AXIS_TURNING\nZW3D_3AXIS_TURNING".
    If fail to check current license, the license is trial(szModules will be set to "Trial").

    @param [out] szModules[1024] the module name list to be return.(e.g. "ZW3D_BASE_MODULES\nZW3D_2AXIS_TURNING\nZW3D_3AXIS_TURNING").

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxLicModulesGet(char szModules[1024]);

    /**
    @ingroup zwapi_license

    Get current valid license identifier string.

    @param [out] szIdentifier[36] the license identifier string.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxLicIdentifierGet(char szIdentifier[36]);

    /**
    @ingroup zwapi_license

    Get days before trial license expired.  
    cvxLicStandaloneEvaluationGet() has the similar function as well.

    @param [out] szEvaluation[36] currently not used, leave it as NULL

    @retval return
    -       > 0 number of days before trial license expired.
    -       = 0 the trial license has been expired.
    -       < 0 fail to get expire days.
    @warning
    -       ZW_API_INVALID_OUTPUT
    */
    extern int cvxLicEvaluationGet(char szEvaluation[36]);

    /**
    @ingroup zwapi_license

    Get days before standalone license expired.  
    cvxLicEvaluationGet() has the similar function as well.

    @retval return
    -       > 0 number of days before standalone license expired.
    -       = 0 the standalone license has been expired.
    -       < 0 fail to get expire days.
    @warning
    -       ZW_API_GENERAL_ERROR
    */
    extern int cvxLicStandaloneEvaluationGet();

    /**
    @ingroup zwapi_license

    Activate license by entitlement.  
    See cvxLicRemove() to remove the license for the current ZW3D session.

    @param [in] pzEntitlement the license entitlement.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxLicActivate(const char *pzEntitlement);

    /**
    @ingroup zwapi_license

    Remove license by entitlement.  
    See cvxLicActivate() to activate the license for the current ZW3D session.

    @param [in] pzEntitlement the license entitlement.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxLicRemove(const char *pzEntitlement);

    /**
    @ingroup zwapi_license

    Check the current authorization type.  
    It can check the type except when using trial license.


    @retval return
    -       0  The current authorization type is Soft-key license.(include Soft-key Singleton license and Floating license)
    -       1  The current authorization type is Dongle license.
    -       -1 Check failed.
    */
    extern int cvxLicTypeCheck();


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_LIC_H */
