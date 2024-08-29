/**
@file zwapi_cmd.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Command Common API
*/
/**
@defgroup zwapi_cmd Command API
@ingroup CommandParameters
@brief
@details THE MODULE FOR THE ZW3D Command Common API
*/

#pragma once
#ifndef ZW_API_CMD_H /* this ifndef surrounds entire header */
#define ZW_API_CMD_H

#include "zwapi_cmd_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Command Send */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd

    Displays buffered error messages and resets the GUI to
    prompt the user for a new command.  Generally you would
    call this function at the end of your custom API code
    before returning control to ZW3D -- unless your code is
    automatically called by a custom command template.

    */
    extern void cvxNewCommand(void);

    /**
    @ingroup zwapi_cmd

    Buffers the input command string for execution after the current command and
    any previously-buffered command events are finished executing.

    If "Priority" is input as 1, the input command string is given higher priority
    for execution than command strings buffered with "Priority = 0".

    For example, if you register a pointer to a "void MyFunction(void)" callback
    function using cvxCmdFunc(), you can cause the function to be invoked after
    pending commands have executed using cvxCmdBuffer("~MyFunction").

    @param [in] String command string
    @param [in] Priority priority of execution (0 or 1)

    */
    extern void cvxCmdBuffer(const char *String, int Priority);

    /**
    @ingroup zwapi_cmd

    Executes the input command string. If "String = NULL", the event queue
    is polled for buffered command strings, which are allowed to execute in
    the order they were buffered. When this function is called, any current
    thread of execution is suspended until pending command strings are processed,
    after which this function returns control to the calling procedure.

    @param [in] CommandString null-terminated ascii command string

    */
    extern void cvxCmdSend(char *CommandString);

    //====================================================================================================================
    /** @name Command Operation */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd

    Check whether license is valid.

    @param [in] Name Command name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxCmdChkLic(const vxName Name);

    /**
    @ingroup zwapi_cmd

    Set a callback function. When processing the target command option,
    the callback function will be called.

    If this function called many times with the same 'type', only
    the last will take effect.

    If param or param->pfn is NULL, the original callback function, if there
    exists, will be removed.

    If type is VX_CMD_START, param->pfn should return 0 if the specified command can be
    started, else return 1.

    @note
    If one call this function to register a callback in a dll module,
    he must call this function again, with argument param set as NULL,
    to unregister the callback for each action before the dll module exit.
    Usually we can do this in the exit function of the dll module.

    @param [in] type action type
    @param [in] param callback function (NULL to remove the callback)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -
    */
    extern evxErrors cvxCmdAction(evxCmdAction type, svxCmdActionParam *param);

    //====================================================================================================================
    /** @name Function Register/Un-register */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd

    Registers a function referenced by the "function=" or "custom="
    fields in a command template definition.  The function is
    registered with a ZW3D licensing code.  ZW3D ensures the user has
    the appropriate license before allowing access to the function.

    Callback functions should be registered in the "Init" function
    called when your library is dynamically loaded by ZW3D at runtime.

    For a standard command operation, the function should be the following type:

    int StandardCommand(int idInputData, int *idOutputData)

    For a custom command operation, the function should be the following type:

    int CustomOperation(int idInputData)

    For a callback function invoked by a command string that is the function
    name preceded by a "tilda" (e.g. ~MyFunction), the function should be one
    of the following types:

    void MyFunction(void) or...

    void MyFunction(char *string) invoked by sending the string "~MyFunction("text string")"
    using cvxCmdSend() or cvxCmdBuffer().

    The API functions beginning with cvxData...() are used to compose and
    to query the data containers referenced by "idInputData" or "idOutputData".

    For documentation on the the callback function registered in the header of
    a GUI template, see cvxFormFunc().

    If developer wants to unload the DLL plug in file dynamically. It is a MUST to
    run cvxCmdFuncUnload() in the exit function.

    In this case, the pre-existing symbol is kept and the input function is ignored.

    @param [in] Name function name
    @param [in] Function function pointer
    @param [in] Code ZW3D licensing code (e.g. VX_CODE_ADV_MODELING or VX_CODE_GENERAL)

    @retval succeeds
    -        ZW_API_NO_ERROR : the input function was successfully registered
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_FUN_REGISTER_ERROR : a symbol with the same name as the input function already exists.
                                         In this case, the pre-existing symbol is kept and the input function is ignored.
    */
    extern evxErrors cvxCmdFunc(const vxName Name, void *Function, double Code);

    /**
    @ingroup zwapi_cmd

    Registers a pointer to an auxiliary callback function used by
    a command template.  The function does not require a licensing
    code.  The "init=", "exit=", "echo_obj=" and "callback=" fields reference
    auxiliary callback functions.

    Function pointers should be registered in the "Init" function
    called when your library is dynamically loaded by ZW3D at runtime.

    The callback function should be of the following type:

    int Callback(char *TemplateName, int idField, int idData)

    The echo_obj function should be of the following type:
    void Echo(int idData, void *ptr)

    If developer wants to unload the DLL plug in file dynamically.
    It is a MUST to run cvxCmdFuncUnload() in the exit function.

    @param [in] Name function name
    @param [in] Function function pointer

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_FUN_REGISTER_ERROR
    */
    extern void cvxCmdCallback(const vxName Name, void *Function);

    /**
    @ingroup zwapi_cmd

    Unload specified function registered via cvxCmdFunc()/cvxCmdCallback()/
    cvxFormFunc()/cvxFormCallback() if developer wants to unload the DLL
    plug in file dynamically. The input name must be the same as the one
    used in cvxCmdFunc()/cvxCmdCallback()/cvxFormFunc()/cvxFormCallback().

    @param [in] Name function name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FUN_UNLOAD_ERROR
    */
    extern evxErrors cvxCmdFuncUnload(const vxName Name);

    /**
    @ingroup zwapi_cmd

    Registers a pointer to a global variable (i.e. the variable's address)
    referenced in a command template "options" string.

    Global variables should be registered in the "Init" function
    called when your library is dynamically loaded by ZW3D at runtime.

    If developer wants to unload the DLL plug in file dynamically.
    It is a MUST to run cvxCmdVariableUnload() in the exit function.

    @param [in] Name global variable name
    @param [in] Variable pointer to global variable

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    */
    extern void cvxCmdVariable(vxName Name, void *Variable);

    /**
    @ingroup zwapi_cmd

    Unload the variable registered via cvxCmdVariable() if developer
    wants to unload the DLL plug in file dynamically. The input name
    must be the same as the one used in cvxCmdVariable().

    @param [in] Name Variable name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxCmdVariableUnload(const vxName Name);

    /**
    @ingroup zwapi_cmd

    Register a Qt resource file(rcc file).The rcc file contains the resources
    used in dll.If developer wants to unregister the rcc file in file dynamically.
    It is a MUST to run cvxCmdUnRegisterRcc() in the exit function.

    @param [in] File file name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxCmdRegisterRcc(vxName File);

    /**
    @ingroup zwapi_cmd

    Unregister the Qt resource file(rcc file) registered via cvxCmdRegisterRcc().
    If developer wants to unload the DLL plug in file dynamically. The input name
    must be the same as the one used in cvxCmdRegisterRcc().

    @param [in] File file name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxCmdUnRegisterRcc(vxName File);

    //====================================================================================================================
    /** @name Macro */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd

    "Input" is interpreted as a string of one or more newline-delimted macro
    command strings -- without the macro/endmacro keywords.  A new macro
    is started, the encoded macro commands are executed and the macro is
    terminated.

    The contents of variables created by the macro commands are output
    via "Output" as a single comma-delimited, null-terminated ascii string.
    The first item in the string is the total number of variables encoded
    in the string.  This is followed by an encoding of each variable.
    Each variable is encoded with its name first, followed by the number
    of array elements in the variable, followed by the array values.
    Values are either ascii-encoded floating point numbers, or strings
    enclosed in double quotemarks.  The following is an example:

    @verbatim
       # variables
       Num = 25
       Strings = {"hello dolly", "hello world"}
       Array = {100,125,150}

       # ascii-encoded variable data
       3,Num,1,25,Strings,2,"hello dolly","hello world",Array,3,100,125,150
    @endverbatim

    Memory for "Output" is allocated by this function.  The memory must be
    deallocated by the calling procedure.  If there is no output data, a
    NULL pointer is output.

    @note
    If user enter a new environment, user need to use the
    cvxDispSceneUpdate() interface to update the environment.  
    If this function errors out anywhere along the way, the string "ERROR"
    will be output via "Output" and this function will return 1.  Otherwise,
    it will return 0.

    @param [in] Input null-terminated ascii string of macro commands
    @param [out] Output pointer to of output data string (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxCmdMacro(char *Input, char **Output);

    /**
    @ingroup zwapi_cmd

    Runs a macro of specified path.

    @note
    If user enter a new environment, user need to use the
    cvxDispSceneUpdate() interface to update the environment.

    @param [in] path macro file path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxCmdMacro2(char *path);

    /**
    @ingroup zwapi_cmd

    Gets the path and file name of the currently running macro.
    If no running macro, path[0] = 0 and file[0] = 0.
    The path and file cannot both be NULL.

    @param [out] path path of macro (NULL to ignore)
    @param [out] file file name of macro (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxMacroInqPath(vxPath path, vxPath file);


    /**
    @ingroup zwapi_cmd

    Gets the path and file name of the currently running macro.
    If no running macro, path[0] = 0 and file[0] = 0.
    The path and file cannot both be NULL.

    A path that is too long (longer than "sizepath") is truncated.
    A file that is too long (longer than "filesize") is truncated.

    It is assumed that the input "name" and "file" are no longer than 512 bytes.

    @param [out] path path of macro (NULL to ignore)
    @param [in] sizepath max size of path
    @param [out] file file name of macro (NULL to ignore)
    @param [in] filesize max size of file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxMacroInqPathByLongPath(char *path, int sizepath, char *file, int filesize);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_CMD_H */
