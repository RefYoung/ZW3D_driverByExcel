/**
@file zwapi_message.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Message API
*/
/**
@defgroup zwapi_message Message
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D Message API
*/

#pragma once
#ifndef ZW_API_MSG_H /* this ifndef surrounds entire header */
#define ZW_API_MSG_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Message Disable Data */
    //====================================================================================================================
    /**
    @brief dialog form type of user prompt
    @ingroup zwapi_message
    */
    typedef enum evxDialogType
    {
        VX_DIALOG_SAVE_AS = 1 /**<@brief  dialog of saveas */
    } evxDialogType;

    //====================================================================================================================
    /** @name Message Disable */
    //====================================================================================================================
    /**
    @ingroup zwapi_message

    Disable display of error messages in the ZW3D message area.

    The application that uses this function is ALWAYS responsible
    for re-enabling error message display using cvxErrEnable().

    */
    extern void cvxErrDisable(void);

    /**
    @ingroup zwapi_message

    Re-enable display of error messages in the ZW3D message area.

    */
    extern void cvxErrEnable(void);

    /**
    @ingroup zwapi_message

    Disable display of general messages in the ZW3D message area.

    The application that uses this function is ALWAYS responsible  
    for re-enabling general message display using cvxMsgEnable().

    Use cvxErrDisable() to disable display of error messages.  
    Use cvxPromptDisable() to disable display of command prompts. 

    */
    extern void cvxMsgDisable(void);

    /**
    @ingroup zwapi_message

    Re-enable display of general messages in the ZW3D message area.

    */
    extern void cvxMsgEnable(void);

    /**
    @ingroup zwapi_message

    Enable/Disable display the warning message when API function fails.

    @note
    Default is disabled

    @param [in] enable 1 - enable the warning message, else 0

    */
    extern void cvxLastWarningMsgEnable(int enable);

    /**
    @ingroup zwapi_message

    Disables the display of command prompts (when it is possible).

    */
    extern void cvxPromptDisable(void);

    /**
    @ingroup zwapi_message

    Re-enables display of command prompts.

    */
    extern void cvxPromptEnable(void);

    /**
    @ingroup zwapi_message

    Disables the translator status window.  
    Always pair a call to this function with a subsequent  
    call to cvxTranslatorStatusEnable(). 

    */
    extern void cvxTranStatusDisable(void);

    /**
    @ingroup zwapi_message

    Re-enables the translator status window.  
    A call to cvxTranslatorStatusDisable() should always  
    be paired with a subsequent call to this function.

    */
    extern void cvxTranStatusEnable(void);

    /**
    @ingroup zwapi_message

    Get the value of prompt dialog status. This function must be called before  
    cvxUserActionStatusSet().  
    @param [out] disableStatus current disable status

    */
    extern void cvxUserActionStatusGet(int *disableStatus);

    /**
    @ingroup zwapi_message

    Set the status of prompt dialog.
    disable: 0-enable  
             2-disable: the default action is "Yes"  
             3-disable: the default action is "Yes All", if the option does not have this,  
               it is "Yes"  
             -1-disable: the default action is "Cancel" ,if the option does not have this,  
               it is "No"  
             -2-disable: the default action is "No"

    If the option is "Continue", as long as disable is non-zero, it will choice the action "Continue".

    Make sure cvxUserActionStatusGet()has been called before you call this function.  
    After your operation finished, please called this function again to restore the status.  
    The "integer" value (disable) should be output by cvxUserActionStatusGet().  
    @param [in] disable disable or enable the prompt dialog

    */
    extern void cvxUserActionStatusSet(int disable);

    /**
    @ingroup zwapi_message

    Disable the crash prompt dialog.  
    @see cvxCrashPromptEnable() to enable.

    */
    extern void cvxCrashPromptDisable();

    /**
    @ingroup zwapi_message

    Enable the crash prompt dialog.  
    @see cvxCrashPromptDisable() to disable.

    */
    extern void cvxCrashPromptEnable();

    /**
    @ingroup zwapi_message

    Enhanced API for disable or enable the prompt dialog, as cvxUserActionStatusSet() could only set yes / no.

    Type:
    When type is VX_DIALOG_SAVE_AS, parameter value controls the prompt dialog for "Save as the file":                         
       value == 0: Prompt dialog                                                                                               
       value == 3: The default action is select "Save as new and replace original one" then push ok button, not prompt dialog   
       value == 4: The default action is select "Save as copy and close", then push ok button, not prompt dialog               
       value == 5: The default action is select "Save as copy and open" then push ok button, not prompt dialog                 
       value == 6: The default action is "Cancel", not prompt dialog  

    Other values for parameter type are reserved for future usage.

    @param [in] type prompt window type
    @param [in] value flag value to disable or enable the prompt dialog

    @retval return
    -        Old value before set.
    */
    extern int cvxUserActionStatusSet2(evxDialogType type, int value);


    //====================================================================================================================
    /** @name Message Area State */
    //====================================================================================================================
    /**
    @ingroup zwapi_message

    Closes the ZW3D message area.

    */
    extern void cvxMsgAreaClose(void);

    /**
    @ingroup zwapi_message

    Opens the ZW3D message area.

    */
    extern void cvxMsgAreaOpen(void);

    /**
    @ingroup zwapi_message

    Calling this function with "Disable=1" prevents the message  
    window from automatically opening.

    Calling the function again with "Disable=0" re-enables the  
    normal operation of the message window.

    This function MUST always be called in pairs -- the first  
    call with "Disable=1" and the second call with "Disable=0".

    */
    extern void cvxMsgAreaState(int);

    /**
    @ingroup zwapi_message

    Get the hidden or displayed status of the output list   
    through this interface.

    @param [out] action  action; 1-displayed, 2-hidden

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxMsgAreaStateGet(int *action);


    //====================================================================================================================
    /** @name Message Display */
    //====================================================================================================================
    /**
    @ingroup zwapi_message

    Load the messages in the specified file (File) in memory  
    and return an id (idFile) that identifies the file.

    @param [in] File path to message file
    @param [out] idFile loaded message file id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxMsgFileLoad(const vxLongPath File, int *idFile);

    /**
    @ingroup zwapi_message

    Returns a pointer to a static memory area containing the text of  
    the message identified by "idFile" and "MessageNum".

    @param [in] idFile message file id (see cvxMsgFileLoad())
    @param [in] MessageNum message number within message file

    @retval return
    -        a pointer to a static memory area
    */
    extern char *cvxMsgPtr(int idFile, int MessageNum);

    /**
    @ingroup zwapi_message

    Displays the specified text in the ZW3D message area.  
    @param [in] Text text string

    */
    extern void cvxMsgDisp(const char *Text);

    /**
    @ingroup zwapi_message

    Displays the specified text in the output area with specified level.  

    @verbatim
    level: 0-information
           1-note
           2-debug
           3-warning
           4-alert
           5-error
           6-fatal
    @endverbatim

    @param [in] Text text string
    @param [in] level message level (0-6)

    */
    extern void cvxMsgDisp2(const char *Text, int level);

    /**
    @ingroup zwapi_message

    Function to display message window. A message window is used for common  
    interaction tasks, which include giving information, asking questions, and  
    reporting errors.

    Valid MsgType is shown below: 

    MsgType=1: An error window warns users of action consequences and
    gives them  a choice of resolutions.   

    MsgType=2: An information window gives the user information, such
    as the status of  an action. 

    MsgType=3: A message window is used for common interaction tasks. 

    MsgType=4: A Question window is used to get the answer to a
    question from the user. 

    MsgType=5: A warning window warns users of action consequences and
    gives them a choice of resolutions. 

    MsgType=6: A working window informs users that there is atime-consuming
    operation in progress and allows them to cancel the operation.

    @param [in] MsgType Message box type
    @param [in] WndMode 0 = modeless, 1 = full application modal
    @param [in] Title Window title; set to NULL if not applicable
    @param [in] Message Message string
    @param [in] Btn1Str Button1 string; set to NULL if not applicable
    @param [in] Btn2Str Button2 string; set to NULL if not applicable
    @param [out] Action Action

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxMessageBox(int MsgType, int WndMode, const char *Title, const char *Message,
                                   const char *Btn1Str, const char *Btn2Str, int *Action);

    //====================================================================================================================
    /** @name Function Fail Message */
    //====================================================================================================================
    /**
    @ingroup zwapi_message

    Get the last error type.


    @retval return
    -        The last error type.
    */
    extern evxErrors cvxLastErrGet();

    /**
    @ingroup zwapi_message

    Set the last error type.
    @param [in] error set the last error type

    */
    extern void cvxLastErrSet(evxErrors error);

    /**
    @ingroup zwapi_message

    Return the error message, return NULL if fails to get.

    @param [in] error Get the error message

    @retval return
    -        error message or NULL.
    */
    extern const char *cvxErrMsgGet(evxErrors error);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_MSG_H */
