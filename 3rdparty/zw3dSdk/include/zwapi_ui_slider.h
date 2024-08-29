/**
@file zwapi_ui_slider.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Combobox API
*/
/**
@defgroup zwapi_ui_slider Slider
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D Combobox API
*/

#pragma once
#ifndef ZW_API_SLIDER_H /* this ifndef surrounds entire header */
#define ZW_API_SLIDER_H

#include "zwapi_ui_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Slider */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_slider

    Use this function to get slider's minimum and maximum.  
    Activate the form before calling this function.

    @see cvxSliderLimitSet().

    @param [in] Form form name 
    @param [in] idfield id of field 
    @param [out] min slider minimum 
    @param [out] max slider maximum

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxSliderLimitGet(const char *Form, int idfield, double *min, double *max);

    /**
    @ingroup zwapi_ui_slider

    Use this function to set slider's minimum and maximum.  
    Activate the form before calling this function.

    @see cvxSliderLimitGet().

    @param [in] Form form name
    @param [in] idfield id of field
    @param [in] min slider minimum
    @param [in] max slider maximum

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxSliderLimitSet(const char *Form, int idfield, double min, double max);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SLIDER_H */
