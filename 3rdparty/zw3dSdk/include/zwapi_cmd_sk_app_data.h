/**
@file zwapi_cmd_sk_app_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the All
Commands of Sketch functions.
*/
/**
@defgroup zwapi_cmd_sk_cmds_data Sketch Commands Data
@ingroup SketchCommands
@brief
@details Interface data corresponding to the functions in the app module in the sketch.
*/

#pragma once
#ifndef ZW_API_SK_APP_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_SK_APP_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch App Data */
    //====================================================================================================================

    /**
    @brief  profile data of Sketch Nesting
    @details 
    @ingroup zwapi_cmd_sk_cmds_data
    */
    typedef struct svxSkNestingProfileData
    {
        int cnt;                /**<@brief count of listProfile */
        int *listProfile;       /**<@brief list of entity id.Select sketch entities to define a profile,
                               the selected sketch entities must meet the following rules:
                               Inner and outer loops must be closed and cannot intersect, and inner loop cannot be nested. */
        int quantity;           /**<@brief Define how much the profile defined above is planned to nest. If the blank is big enough,
                               the profile will be nested as the plan quantity, but if not, 
                               the actual nesting quantity will be less than the plan.default:1(min=1,max=100000) */
        double margin;          /**<@brief Define the gap around the profile.default:0 */
        double minAngle;        /**<@brief Specify the angle range allowing the profile rotating during nesting
                               if needed to accommodate the profile as much as possible.default:0(min=0,max=360) */
        double maxAngle;        /**<@brief Specify the angle range allowing the profile rotating during nesting
                               if needed to accommodate the profile as much as possible.default:360.(min=0,max=360) */
        int flip;               /**<@brief Define whether the profile can be flip around during nest when necessary.1 if flip,else 0. default:0 */
        int priority;           /**<@brief Define the nest sequence when multiple profiles are about to nest.the range is 1~5.The highest priority is 1.default:1 */
        vxLongName profileName; /**<@brief Specify each profile a name to distinguish each other.If not specified, a default name is specified. */
    } svxSkNestingProfileData;

    /**
    @brief blank data of Sketch Nesting
    @details 
    @ingroup zwapi_cmd_sk_app_data
    */
    typedef struct svxSkNestingBlankData
    {
        int cnt;              /**<@brief count of listBlank */
        int *listBlank;       /**<@brief list of entity id. Select sketch entities to define a blank,
                            the selected sketch entities also must meet the following rules:
                            Inner and outer loops must be closed and cannot intersect, and inner loop cannot be nested. */
        double margin;        /**<@brief Define the gap in 4 directions of blank.The fields is valid only when selecting rectangle method.default:0 */
        double topMargin;     /**<@brief Define the gap top the blank.This field is valid only when selecting custom method.default:0 */
        double bottomMargin;  /**<@brief Define the gap bottom the blank.This field is valid only when selecting custom method.default:0 */
        double leftMargin;    /**<@brief Define the gap left the blank.This field is valid only when selecting custom method.default:0 */
        double rightMargin;   /**<@brief Define the gap right the blank.This field is valid only when selecting custom method.default:0 */
        int method;           /**<@brief "Blank Margin" offers 2 ways to define: even and uneven margin in 4 directions.
                            0 is rectangle, 1 is custom.default:1 */
        vxLongName blankName; /**<@brief Specify each blank a name to distinguish each other.If not specified, a default name is specified. */
    } svxSkNestingBlankData;

    /**
    @brief Nesting data of sketch
    @details 
    @ingroup zwapi_cmd_sk_app_data
    */
    typedef struct svxSkNestingData
    {
        int cntPrf;                        /**<@brief count of profiles */
        svxSkNestingProfileData *profiles; /**<@brief list of profile data */
        int cntBlk;                        /**<@brief count of blanks */
        svxSkNestingBlankData *blanks;     /**<@brief list of blank data */
        double timeToNest;                 /**<@brief Specify the time to be calculated for nesting.Nesting result can be different basing on how long the nesting time is using.
                                         Normally the longer the time is, the better the result is.
                                         Users can input a suitable time balancing the result and time cost. */
        vxName reportName;                 /**<@brief Specify a name for nesting report.If not specified, a default name is specified. */
        vxLongName reportDir;              /**<@brief Specify save path and file name for nesting report.If not specified,
                                         the default save path and file name will be used.  
                                         for example: reportDir="D:\ZW3D\Nesting result.html".  
                                         "D:\ZW3D\" is the path where the file is saved. It can be changed according to the user's wishes.  
                                         "Nesting result" is name. It can be changed.  
                                         but,the reportDir must contain ".html",otherwise the interface cannot be used normally.
                                         */
    } svxSkNestingData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SK_CMD_DATA_H */