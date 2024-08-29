/**
@file zwapi_cmd_paramdefine_tpl.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Command Container API
*/
/**
@defgroup zwapi_cmd_paramdefine_tpl Template API
@ingroup TemplateCommand
@brief
@details THE MODULE FOR THE ZW3D Command Container API
*/

#pragma once
#ifndef ZW_API_TPL_H /* this ifndef surrounds entire header */
#define ZW_API_TPL_H

#include "zwapi_cmd_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Command Execute */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Passes "idData" to the evaluation function identified by "Name".
    It is assumed the function has been registered with ZW3D (see cvxCmdFunc()).
    The function should be of type "int function(int idData, int *idOutput)".
    Undo-redo transaction logging is managed by this command.

    Use cvxDataInit() and cvxDataSet() to set up "idData".  Unlike
    cvxCmdExec(), "idData" is not deleted by this function.  The calling
    procedure is responsible for cleaning up "idData" using cvxDataFree().

    When an echo has been initiated with cvxEchoStart(),
    this function will call the echo_obj function associated with
    idData and add the objects to the echo instead of adding
    them to the database.

    When in echo mode (cvxEchoStart() called)

    @param [in] Name name of evaluation function
    @param [in] idData id of command data container

    @retval succeeds
    -        0 : Success
    @retval fail
    -        1 : Internal error
    -        2 : There is no active command
    -        3 : The active command does not have an echo_obj function
    -        4 : There is no echo object associated with the active command
    -        5 : The template associated with "idData" could not be found in Forms.Z3
    -        6 : The template associated with "idData" does not have an echo_obj function
    -        7 : The echo_obj function associated with "idData" was not registered
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxCmdEval(vxName Name, int idData);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Executes the command defined by "idData".  Use cvxDataInit() and
    cvxDataSet() to set up "idData".  "idData" is always deleted by
    this function, even if it fails.

    When an echo has been initiated with cvxEchoStart(),
    this function will call the echo_obj function associated with
    the command and add the objects to the echo instead of adding
    them to the database.

    Automatic creation of feature-sets is disabled while this function
    is executing.

    When in echo mode (cvxEchoStart() called)

    @param [in] idData id of command data container

    @retval succeeds
    -        0 : Success
    @retval fail
    -        1 : Internal error
    -        2 : There is no active command
    -        3 : The active command does not have an echo_obj function
    -        4 : There is no echo object associated with the active command
    -        5 : The template associated with "idData" could not be found in Forms.Z3
    -        6 : The template associated with "idData" does not have an echo_obj function
    -        7 : The echo_obj function associated with "idData" was not registered
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxCmdExec(int idData);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Same as cvxCmdExec(), except that the VDATA object was not deleted when
    the command outputs its input.

    @param [in] idData id of command data container

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxCmdExec2(int idData);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Same as cvxCmdExec2(), except that the function output the index of output data object.

    @param [in] idData id of command data container
    @param [out] idOut id of output data object (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxCmdExecWithOut(int idData, int *idOut);

    //====================================================================================================================
    /** @name Command Operation */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Uses the specified template to gather input data.  Waits in this
    function until the data has been collected.  Then outputs the
    id of the collected data via "idxDataOut".

    Assigns the input data to a new data object if "idDataIn < 1".
    Otherwise, uses new input data to modify the data object defined
    by "idDataIn".  It is assumed that "idDataIn" was created by
    cvxDataInit().

    If "idDataOut" is output as 0, "idDataIn" is automatically deleted.
    This means the user tried to execute another command while this
    function was waiting for input.

    @param [in] Name command template name
    @param [in] idDataIn optional data container id (0 if undefined)
    @param [out] idDataOut output data container id (0 if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxCmdInput(const vxName Name, int idDataIn, int *idDataOut);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Executes the specified command in interactive input mode
    (i.e. those commands that would preceded by an exclamation
    mark when executed from the command line).  The user is
    prompted for the command's inputs, then the command is
    executed.

    @param [in] Name command template name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxCmdInteract(const vxName Name);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Outputs the name of the active command input form.

    @param [out] Name name of active command input form

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxCmdInqActive(vxName Name);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Log undo-redo markers for the active template-driven command.

    If "Okay" defines a valid marker, ZW3D will automatically undo to
    the marker when input for the active command is accepted by the
    user.

    This undo will happen BEFORE the evaluation function
    associated with the command is executed.

    If the user cancels the active command while input is being gathered, ZW3D will
    automatically undo to the "Cancel" marker, if it is defined.

    Input a blank string or NULL if a marker is not defined for
    either the "Okay" or "Cancel" case.

    Undo-redo markers (see cvxUndoRedoMarker()) may be used with this
    function to manage automatic deletion of entities created during
    the user input gathering phase of a template-based command.

    @param [in] Okay undo to this marker on "Okay" (or input NULL)
    @param [in] Cancel undo to this marker on "Cancel" (or input NULL)
    */
    extern void cvxCmdMarker(const vxName Okay, const vxName Cancel);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Get the state of the command.

    @param [in] CmdName command name
    @param [out] State state of the command

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxCmdStateGet(vxName CmdName, evxCmdState *State);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Set the state of the command.

    @param [in] CmdName command name
    @param [in] State state of the command

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxCmdStateSet(vxName CmdName, evxCmdState State);


    //====================================================================================================================
    /** @name Template Register/Un-register */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Loads, compiles and registers the command template(s) defined in
    the specified file.

    If "File" does not define a full path to the template file,
    ZW3D searches for the file in the runtime directory, the directories
    defined in "vxpaths", and the installation directories.

    When ZW3D session management is enabled, dynamically-loaded templates
    are deleted when a session is cleared.   
    So that ZW3D can automatically reload the templates on-demand, register the directory that contains
    your template files using cvxPathAdd().   
    Each template file should have the same name (minus the .t extension) as the command defined
    inside of it.  For example, if "TEMPLATE=MyCommand", the container
    file should be named "MyCommand.t".

    A command template defines the input data required by a command
    and the name of the function the data is passed to for command
    execution.   
    The template also has information that tells the
    ZW3D Input Manager how to interactively prompt the user for the
    inputs required by the command.   
    These input fields may have callback functions associated with them.   
    All functions and variables referenced by a command template must be registered
    with cvxCmdFunc(), cvxCmdCallback() or cvxCmdVariable().   
    See the "Virtual Forms" online help topic for more information
    about the definition of command templates.

    When a command template is used to define an "Options" form
    (i.e. opt_form), fields of the "opt_form" may be managed using
    some cvxFieldXXX() and cvxItemXXX() functions.   
    This is done by inputting "OptForm" for the "Form" argument of the form
    management functions.

    Another way to dynamically define a template is to write it to
    a file in the ZW3D "temp" directory (see cvxPathTemp()) and then
    use this function to load/compile it.   
    When a session is cleared, ZW3D reloads command templates from the "temp" directory on-demand
    -- as long as the template file name is the command name defined
    inside the file by "TEMPLATE=...".   
    Template files in the "temp" directory are automatically deleted when ZW3D exits.

    If developer wants to unload the DLL plug in file dynamically.
    It is a MUST to run cvxCmdTemplateUnload() in the exit function.

    @param [in] File file that contains command template(s)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxCmdTemplate(const vxLongPath File);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Unload the command template(s) defined in the specified file and
    registered via cvxCmdTemplate() or cvxFormTemplate() if developer
    wants to unload the DLL plug in file dynamically. The input file
    path must be the same as the one used in cvxCmdTemplate().

    @param [in] File file that contains command template(s)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxCmdTemplateUnload(const vxLongPath File);

    //====================================================================================================================
    /** @name Echo Function */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Gets the active wireframe color of the dynamic echo.

    @param [out] Color active wireframe color for dynamic echo

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxEchoColorGet(evxColor *Color);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Sets the active color (wireframe and shaded) for dynamic echo.

    @param [in] Color active color for dynamic echo

    @warning
    -        ZW_API_GENERAL_ERROR
    */
    extern void cvxEchoColorSet(evxColor Color);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Set display attributes echo.

    @param [in] at display attributes

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxEchoColorAtSet(svxWireAt *at);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Return display attributes stored at echo.

    @param [out] at display attributes

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxEchoColorAtGet(svxWireAt *at);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    cvxEchoCustomStart() should only be called at the beginning
    of the "echo_obj" function associated with the currently
    executing command template.   
    It should ALWAYS be paired
    with a call to cvxEchoCustomEnd() at the end of the
    "echo_obj" function.

    Calling this function at the beginning of an "echo_obj"
    function sets up the environment so that you can use
    other API functions to edit the target object inside
    the "echo_obj" function.   
    Those edits will persist until
    the next time the "echo_obj" function is called, at which
    time the edits will automatically be undone prior to the
    next round of edits to the target object.

    The function prototype for a custom echo function looks like the
    following:

    void MyCustomEcho(int idData, void *echo)

    The "idData" passed to MyCustomEcho() is the id of the same
    container of command input data that is passed to the evaluation
    function associated with the currently executing command template.

    The "void *echo" argument is currently not used but should be
    included in the echo function's argument list as shown.

    Register a pointer to the custom echo function as follows:

    cvxCmdFunc("MyCustomEcho",(void*)MyCustomEcho,0.0);

    The custom echo function is registered in the custom command
    template as follows:

    <property name="echo_obj">MyCustomEcho</property>

    This function should not be used in conjunction with cvxEchoStart().

    */
    extern void cvxEchoCustomStart();

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    cvxEchoEnd MUST be called at the end of the function that
    called cvxEchoCustomStart. Failure to do so could leave
    aspects of the GUI disabled (including error display)
    and could also mess up undo-redo.

    */
    extern void cvxEchoCustomEnd();

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Draw the echo data of the active form.

    */
    extern void cvxEchoDraw();

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Instructs the API to start sending entities to the echo
    rather than to the database. The function should always
    be paired with a call to cvxEchoEnd().

    cvxEchoStart() should only be called from within the
    "echo_obj" function associated with the currently
    executing command template.

    */
    extern void cvxEchoStart();

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Instructs the API to stop sending entities to the echo
    and start sending them to the database again.

    cvxEchoEnd() MUST be called at the end of the echo that
    called cvxEchoStart(). Failure to do so will cause most
    API functions to quit working.

    */
    extern void cvxEchoEnd();

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Disable checking for certain escapes that ZW3D may issue while an echo
    function is executing.  This function does not disable checking for
    escapes issued by the user.

    Each call to this function must be paired with a call to
    cvxEchoEscRestore().

    Use of this function is discouraged.  It is intended for special
    situations in which a long-running echo function would otherwise
    trigger an automatic escape.   
    Usually such escapes should be allowed
    to occur to keep the user interface responsive during echo.  An
    appropriate use of this function, for example, would be to disable
    escape checking to make an expensive calculation once in an echo
    function, after which the echo function might cache the results and
    restore escape checking so future calls to the echo function can
    execute quickly and respond normally to ZW3D's built-in automatic
    escapes.

    */
    extern void cvxEchoEscDisable();

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Restore escape checking previously disabled by a call to
    cvxEchoEscDisable().

    */
    extern void cvxEchoEscRestore();


    //====================================================================================================================
    /** @name Template Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Gets the name of the custom function associated with the specified template.

    @param [in] Name template name
    @param [in] NumBytes no. bytes of function name
    @param [out] FnName name of custom function

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTplInqFnCust(vxName Name, int NumBytes, char *FnName);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Gets the name of the &quot;echo&quot; function associated with the specified template.

    @param [in] Name template name
    @param [in] NumBytes no. bytes of function name
    @param [out] FnName name of echo function

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTplInqFnEcho(vxName Name, int NumBytes, char *FnName);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Gets the name of the "init" function associated with the specified template.

    @param [in] Name template name
    @param [in] NumBytes no. bytes of function name
    @param [out] FnName name of initialization function

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTplInqFnInit(vxName Name, int NumBytes, char *FnName);

    /**
    @ingroup zwapi_cmd_paramdefine_tpl

    Gets the name of the "term" function associated with the specified template.

    @param [in] Name template name
    @param [in] NumBytes no. bytes of function name
    @param [out] FnName name of termination function

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTplInqFnTerm(vxName Name, int NumBytes, char *FnName);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_TPL_H */
