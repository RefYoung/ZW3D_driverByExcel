/**
@file zwapi_ui_guiset.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D UI Setting API
*/
/**
@defgroup zwapi_ui_guiset Gui Set
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D UI Setting API
*/

#pragma once
#ifndef ZW_API_GUI_SET_H /* this ifndef surrounds entire header */
#define ZW_API_GUI_SET_H

#include "zwapi_ui_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Role management */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_guiset

    Get the count of ui settings

    */
    extern int cvxUiSettingsCount(void);

    /**
    @ingroup zwapi_ui_guiset

    Create a new ui settings based on the given settings

    @param [in] Name the name of the Settings
    @param [in] Base the name of the base Settings

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxUiSettingsCreate(char *Name, char *Base);

    /**
    @ingroup zwapi_ui_guiset

    Rename the specified ui settings to the given name

    @param [in] Name the name of the Settings to be renamed
    @param [in] Dest the new name of the Settings

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxUiSettingsRename(char *Name, char *Dest);

    /**
    @ingroup zwapi_ui_guiset

    Remove the specified ui settings

    @param [in] Name the name of the Settings to be removed

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxUiSettingsRemove(char *Name);

    /**
    @ingroup zwapi_ui_guiset

    Import the ui settings file

    @param [in] Path the path of the settings file to be imported

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxUiSettingsImport(char *Path);

    /**
    @ingroup zwapi_ui_guiset

    Export the specified ui settings to a given path

    @param [in] Name the name of the settings to be exported
    @param [in] Path the path of the settings file exported

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxUiSettingsExport(char *Name, char *Path);

    /**
    @ingroup zwapi_ui_guiset

    Test the existence of ui setting by the given name

    @param [in] Name the name of the settings

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxUiSettingsExists(char *Name);

    /**
    @ingroup zwapi_ui_guiset

    Apply the specified ui settings

    @param [in] Name the name of the Settings

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxUiSettingsApply(char *Name);

    /**
    @ingroup zwapi_ui_guiset

    Set the specified ui settings to its original state

    @param [in] Name the name of the settings

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxUiSettingsReset(char *Name);

    /**
    @ingroup zwapi_ui_guiset

    Get the ui settings name by the given index.

    @param [in] i the index of the settings to be fetched
    @param [out] Name the name of the settings to be fetched

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxUiSettingsFetch(int i, char *Name);


    //====================================================================================================================
    /** @name Cursor Management */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_guiset

    Changes the active mouse cursor to the specified type.  
    A call to this function should always be paired with  
    a subsequent callto cvxCursorRestore().
    @param [in] Type cursor type

    */
    extern void cvxCursorSet(evxCursorType Type);

    /**
    @ingroup zwapi_ui_guiset

    Restores the cursor type that was active prior to the last
    call to cvxCursorSet.

    */
    extern void cvxCursorRestore(void);

    /**
    @ingroup zwapi_ui_guiset

    Invoke GUI callback function to display percent progress  
    or to clear the progress meter if "iprogress < 0".  
    @param [in] iprogress percent progress (0-100)

    */
    extern void cvxProgress(int iprogress);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_GUI_SET_H */
