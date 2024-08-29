/**
@file zwapi_text.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Text API
*/
/**
@defgroup zwapi_text Text Common API
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D Text API
*/

#pragma once
#ifndef ZW_API_TEXT_H /* this ifndef surrounds entire header */
#define ZW_API_TEXT_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Text Data */
    //====================================================================================================================
    /**
    @brief text location
    @ingroup zwapi_text
    */
    typedef struct svxTextLoc
    {
        unsigned char mirror;      /**<@brief  mirror flag 0-normal , 1-mirror */
        float text_radius;         /**<@brief  radius of arc that the text follows */
        float scale;               /**<@brief  text scale factor */
        svxPoint2f origin_point;   /**<@brief  text origin point */
        svxPoint2f align_point;    /**<@brief  text alignment point */
        svxPoint2f mirror_axis[2]; /**<@brief  two points defining mirror axis */
        svxPoint2f bbox[2];        /**<@brief  two points defining text bounding box */
    } svxTextLoc;

    //====================================================================================================================
    /** @name Text */
    //====================================================================================================================
    /**
    @ingroup zwapi_text

    Gets a copy of the null-terminated ascii text string associated with  
    the specified entity (idText) in the active target file.

    This function allocates memory for the text string and outputs a pointer  
    to the memory via "char **Text".  The calling procedure is responsible  
    for deallocating the memory.  A NULL pointer is output if no text is  
    found.

    @code
    int idText = XXX;
    char *Text=NULL;

    cvxEntTextInq(idText,&Text);
    printf("Text = %s",Text);
    cvxMemFree((void**)&Text);
    @endcode

    @param [in] idText id of text entity
    @param [out] Text copy of entity text string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxEntTextInq(int idText, char **Text);

    /**
    @ingroup zwapi_text

    Replaces the text currently associated with "idText" with the
    input text string (Text).

    @param [in] idText id of text entity
    @param [in] Text null-terminated ascii text string to assign to entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxEntTextMod(int idText, char *Text);

    /**
    @ingroup zwapi_text

    Outputs the attributes of specified text.

    @param [in] idText text id
    @param [out] At attributes if text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxEntTextAtGet(int idText, svxTextAt *At);

    /**
    @ingroup zwapi_text

    Sets the attributes of specified text.

    @param [in] idText text id
    @param [in] At attributes if text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZE_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxEntTextAtSet(int idText, svxTextAt *At);

    /**
    @ingroup zwapi_text

    Outputs the location of specified text.

    @param [in] idText text id
    @param [out] loc location

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxEntTextLocGet(int idText, svxTextLoc *loc);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_TEXT_H */
