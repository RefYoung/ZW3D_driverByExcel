/**
@file zwapi_ui_combobox.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Combobox API
*/
/**
@defgroup zwapi_ui_combobox Combobox
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D Combobox API
*/

#pragma once
#ifndef ZW_API_COMBOBOX_H /* this ifndef surrounds entire header */
#define ZW_API_COMBOBOX_H

#include "zwapi_ui_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Combobox */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_combobox

    Get the item index in the combobox widget of a form.

    @param [in] sForm form name
    @param [in] fldId field id
    @param [out] curIdx current index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxComboCurrentItem(const char *sForm, int fldId, int *curIdx);

    /**
    @ingroup zwapi_ui_combobox

    Set the id of current selected item.

    @param [in] sForm form name
    @param [in] field field number
    @param [in] item index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxComboSetCurrentItem(const char *sForm, int field, int item);

    /**
    @ingroup zwapi_ui_combobox

    Get the item text in the combobox widget of a form.

    @param [in] sForm form name
    @param [in] idField field id
    @param [out] text current text
    @param [in] sizeText sizeof test

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxComboCurrentText(const char *sForm, int idField, char *text, int sizeText);

    /**
    @ingroup zwapi_ui_combobox

    Set the item text in the combobox widget of a form.

    @param [in] sForm form name
    @param [in] idField field id
    @param [in] text current text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxComboCurrentTextSet(const char *sForm, int idField, const char *text);

    /**
    @ingroup zwapi_ui_combobox

    Get the count of items in the combobox widget of a form.

    @param [in] sForm form name
    @param [in] idField field id
    @param [out] count count of items

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxComboItemCount(const char *sForm, int idField, int *count);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_COMBOBOX_H */
