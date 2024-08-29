/**
@file zwapi_config.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Global Config API,
the input "Name" of the following functions defined in "zw3d installation dir\\supp\\config.xml".
*/
/**
@defgroup zwapi_config Configuration
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D Global Config API, 
the input "Name" of the following functions defined in "zw3d installation dir\\supp\\config.xml".
*/

#pragma once
#ifndef ZW_API_CONFIG_H /* this ifndef surrounds entire header */
#define ZW_API_CONFIG_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Config Get */
    //====================================================================================================================
    /**
    @ingroup zwapi_config

    Outputs the value of a setting from the Configuration form/config
    file.

    VX_COLOR_BLACK is output if the variable value is not one of the
    standard color names.

    This function should not be used to get the color from a variable
    whose value is a 3-integer RGB color.

    Use the cvxConfigGetRgb() function for variables 
    whose values are defined by their RGB components.

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [out] Color value of the specified variable

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    */
    extern void cvxConfigGetColor(const char *Name, evxColor *Color);

    /**
    @ingroup zwapi_config

    Outputs the value of a setting from the Configuration form/config
    file.  The variable value is assumed to be an integer (0 is assigned
    to "Value" when the value is not a number).

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [out] Value value of the specified variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR - variable does not exist and set "value" to 0
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxConfigGetInteger(const char *Name, int *Value);

    /**
    @ingroup zwapi_config

    Outputs the value of a setting from the Configuration form/config
    file.  The variable value is assumed to be a number (0 is assigned to
    "Value" when the value is not a number).

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [out] Value value of the specified variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR - variable does not exist and set "value" to 0
    -        ZW_API_INVALID_OUPUT
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxConfigGetNumber(const char *Name, double *Value);

    /**
    @ingroup zwapi_config

    Given the variable name of a setting in the config file, look up the
    variable and compare its value as a string to the sub-strings    
    contained in the comma-delimited "Options" string, and return the
    index (numbered from 1) of the matching sub-string.  The string
    comparison is case-insensitive.

    For example, if "Options" is "mm,meter,mil,inch" and the value of the
    config file variable of interest is "meter", this function will return 2.

    If the value of the config file variable is "foot", this function
    will return 0.

    The "Options" string should have no more than 32 sub-strings, no
    sub-string should be longer than 31 bytes, and the sub-strings should
    not contain blank spaces.      
    If "Options" has more than 32 sub-strings,
    only the first 32 will be compared to the variable value.    
    If any sub-string is longer than 31 bytes, only its first 31 bytes will be
    compared to the variable value (the variable value must also be 31
    bytes or less).

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [in] Options 0-terminated, comma-delimited allowed values

    @retval return
    -        the index (numbered from 1) of the matching sub-string.
    -        0 - either the variable or sub-string cannot be found
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALD_NAME
    -
    */
    extern int cvxConfigGetOption(const char *Name, const char *Options);

    /**
    @ingroup zwapi_config

    Outputs the value of a setting from the Configuration form/config file.  

    The variable value is assumed to be the RGB components of a color, 
    i.e. a comma-separated list of 3 integers between 0 and 255.

    This function should not be used to get the color from a variable whose 
    value is one of the standard color names rather than a 3-integer RGB color.  

    Use the cvxConfigGetColor() function for variables whose values are color names.

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [out] Rgb value of the specified variable

    @retval succeeds
    -        ZW_API_NO_ERROR - variable exists and has a value of 3 integers
    @retval fail
    -        ZW_API_GENERAL_ERROR - variable does not exist and set "Rgb" to 0, 0, 0 (black)
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxConfigGetRgb(const char *Name, svxColor *Rgb);

    /**
    @ingroup zwapi_config

    Outputs the value of a setting from the Configuration form/config
    file.  The variable value is simply copied as a string to "Str".  
    If the value is longer than nBytes-1, the value is truncated to fit "Str".

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [out] Str 0-terminated value of the specified variable
    @param [in] nBytes max size of Str array in bytes

    @retval succeeds
    -        ZW_API_NO_ERROR - variable exists
    @retval fail
    -        ZW_API_GENERAL_ERROR - variable does not exist and outputs an empty string
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxConfigGetString(const char *Name, char *Str, int nBytes);

    /**
    @ingroup zwapi_config

    Outputs the value of a setting from the Configuration form/config
    file.  The variable value must be one of the strings "Yes" or "No"
    (case is ignored).  If the value is "Yes", 1 is output.  If the value
    is "No", 0 is output.

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [out] YesNo 1 if value is "Yes", 0 if value is "No"

    @retval succeeds
    -        ZW_API_NO_ERROR - variable exists and has a value that is either "Yes" or "No"
    @retval fail
    -        ZW_API_GENERAL_ERROR - variable does not exist and sets the output to 0
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxConfigGetYesNo(const char *Name, int *YesNo);

    /**
    @ingroup zwapi_config

    Get config path for api developer.
    Api developers should save their config files here, if they have.

    A path that is too long (longer than "sizepath") is truncated.

    It is assumed that the input "path" is no longer than 512 bytes.

    @param [out] path config path
    @param [in] sizepath max size of path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxConfigPathGet(char *path, int sizepath);


    //====================================================================================================================
    /** @name Config Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_config

    Sets the value of a setting from the Configuration form/config
    file.

    This function should not be used to set the color from a variable
    whose value is a 3-integer RGB color.  Use the cvxConfigSetRgb()
    function for variables whose values are defined by their RGB
    components.

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [in] Color value of the specified variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxConfigSetColor(const char *Name, evxColor Color);

    /**
    @ingroup zwapi_config

    Sets the value of a setting from the Configuration form/config
    file.  The variable value is assumed to be an integer (0 is assigned
    to "Value" when the value is not a number).

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [in] Value value of the specified variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxConfigSetInteger(const char *Name, int Value);

    /**
    @ingroup zwapi_config

    Sets the value of a setting from the Configuration form/config
    file.  The variable value is assumed to be a number (0 is assigned to
    "Value" when the value is not a number).

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [in] Value value of the specified variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxConfigSetNumber(const char *Name, double Value);

    /**
    @ingroup zwapi_config

    Sets the value of a setting from the Configuration form/config file.

    The "Option" should not be longer than 31 bytes, and it should
    not contain blank spaces.

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [in] Option value of the specified variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxConfigSetOption(const char *Name, const char *Option);

    /**
    @ingroup zwapi_config

    Sets the value of a setting from the Configuration form/config
    file.  The variable value is assumed to be the RGB components of a
    color, i.e. a comma-separated list of 3 integers between 0 and 255.

    This function should not be used to set the color from a variable
    whose value is one of the standard color names rather than a 3-integer
    RGB color.  Use the cvxConfigSetColor() function for variables whose
    values are color names.

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [in] Rgb value of the specified variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxConfigSetRgb(const char *Name, svxColor *Rgb);

    /**
    @ingroup zwapi_config

    Sets the string value of a setting from the Configuration form/config
    file.

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [in] Str value of the specified variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxConfigSetString(const char *Name, char *Str);

    /**
    @ingroup zwapi_config

    Sets the value of a setting from the Configuration form/config
    file. The variable value must be one of the strings "Yes" or "No"
    (case is ignored).
    1-Yes, 0-No.

    @note
    The input "Name" is defined in "zw3d installation dir\\supp\\config.xml.

    @param [in] Name name of config file variable
    @param [in] YesNo value of the specified variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxConfigSetYesNo(const char *Name, int YesNo);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_CONFIG_H */
