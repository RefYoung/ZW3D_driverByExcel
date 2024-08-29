/**
@file zwapi_ui_tabwidget.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Tab Widget API
*/
/**
@defgroup zwapi_ui_tabwidget Tab Widget
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D Tab Widget API
*/

#pragma once
#ifndef ZW_API_TAB_WIDGET_H /* this ifndef surrounds entire header */
#define ZW_API_TAB_WIDGET_H

#include "zwapi_ui_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Tab Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_tabwidget

    Set the visibility of the specific(tab widget) field's specialized item.
    cvxItemVisibleSet has the similar function also.

    @param [in] Form form name
    @param [in] tabIdField id of the tab widget
    @param [in] tabIndex tab index ,start from 0
    @param [in] bVisible true is visible ,false is hide

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTabWidgetItemVisibleSet(const char *Form, int tabIdField, int tabIndex, char bVisible);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_TAB_WIDGET_H */
