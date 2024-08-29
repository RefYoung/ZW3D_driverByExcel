/**
@file zwapi_ui_ribbon.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Ribbon API
*/
/**
@defgroup zwapi_ui_ribbon Ribbon
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D Ribbon API
*/

#pragma once
#ifndef ZW_API_RIBBON_H /* this ifndef surrounds entire header */
#define ZW_API_RIBBON_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Ribbon */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_ribbon

    Enable or disable the ribbon.

    @param [in] enable 1: enable the ribbon. 0: disable the ribbon

    @warning
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxRibbonSetStatus(int enable);

    /**
    @ingroup zwapi_ui_ribbon

    Set the append string to display after the title area of the base GUI window.  
    pStr is NULL or a blank string to clear the append title string.  
    @param [in] pStr Set/clear the string to display after the window title

    */
    extern void cvxSetTitleAppend(const char *pStr);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_RIBBON_H */
