/**
@file zwapi_cmd_sk_create_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Sketch
Creation Command functions.
*/
/**
@defgroup zwapi_cmd_sk_create_data Create Sketch Commands Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the Sketch
Creation Command functions.
*/

#pragma once
#ifndef ZW_API_SKETCH_CREATE_DATA /* this ifndef surrounds entire header */
#define ZW_API_SKETCH_CREATE_DATA

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Creation Data */
    //====================================================================================================================
    /**
    @brief sketch definition data
    @ingroup zwapi_cmd_sk_create_data
    */
    typedef struct svxSketchData
    {
        svxEntPath Plane; /**<@brief  pick path of insertion to locate the sketch (datum plane,planar face,sketch) */

        /*  The following parameters are used to define the Y-axis direction of the sketch */
        int RedefUpDir;  /**<@brief  whether to redefine Y-axis of sketch
                          (0: use the default direction of the insertion plane
                          1: use input data to redefine the Y-axis of sketch) */
        int idUpEnt;     /**<@brief  specify the entity used to define the Y-axis, 0 to ignore (edge,curve,axis,datum plane) */
        int idUpParam;   /**<@brief  specify direction of Y-axis
                          (0: use the positive direction of the edge or curve, or X-axis of datum plane
                          1: use the negative direction of the edge or curve, or Y-axis of datum plane) */
        svxVector UpDir; /**<@brief  direction of Y-axis, can be ignored if idUpEnt > 0 */

        /*  The following parameters are used to define the XY origin of the sketch */
        int RedefOrigin;        /**<@brief  whether to redefine origin of sketch
                          (0: use the default origin of the insertion plane
                          1: use centroid of the insertion plane as the origin of sketch
                          2: use input data to redefine the origin of sketch) */
        int idOrgEnt;           /**<@brief  specify the parent entity where the origin locate, 0 to ignore (edge,curve,face,datum plane,point) */
        evxGeomCritPnt critPnt; /**<@brief  specify the critical point of edge or curve */
        int idPnt;              /**<@brief  id of the control point of the spline (starting from 0), only used when critPnt is VX_SPLINE_DEFINING_POINT */
        svxPoint Origin;        /**<@brief  origin of sketch, can be ignored if idOrgEnt > 0 and use the critical point of entity */

        int xDirRev; /**<@brief  whether to reverse X-axis direction */
    } svxSketchData;

    /**
    @brief hatch pattern method Note: These hatch patterns cannot be described. Please open the ZW3D cosmetic-sketch or cross-hatch command to see.
    @ingroup zwapi_cmd_sk_create_data
    */
    typedef enum evxHatchPtnType
    {
        VX_HATCH_PATTERN_ANSI31,         /**<@brief  ANSI31 */
        VX_HATCH_PATTERN_ANSI32,         /**<@brief  ANSI32 */
        VX_HATCH_PATTERN_ANSI33,         /**<@brief  ANSI33 */
        VX_HATCH_PATTERN_ANSI34,         /**<@brief  ANSI34 */
        VX_HATCH_PATTERN_ANSI35,         /**<@brief  ANSI35 */
        VX_HATCH_PATTERN_ANSI36,         /**<@brief  ANSI36 */
        VX_HATCH_PATTERN_ANSI37,         /**<@brief  ANSI37 */
        VX_HATCH_PATTERN_ANSI38,         /**<@brief  ANSI38 */
        VX_HATCH_PATTERN_SHADOW_PLATE,   /**<@brief  SHADOW_PLATE */
        VX_HATCH_PATTERN_BRICK,          /**<@brief  BRICK */
        VX_HATCH_PATTERN_CORK,           /**<@brief  CORK */
        VX_HATCH_PATTERN_CROSS,          /**<@brief  CROSS */
        VX_HATCH_PATTERN_DASH,           /**<@brief  DASH */
        VX_HATCH_PATTERN_LIMESTONE,      /**<@brief  LIMESTONE */
        VX_HATCH_PATTERN_DOTS,           /**<@brief  DOTS */
        VX_HATCH_PATTERN_EARTH,          /**<@brief  EARTH */
        VX_HATCH_PATTERN_EXPANSION,      /**<@brief  EXPANSION */
        VX_HATCH_PATTERN_GRASS,          /**<@brief  GRASS */
        VX_HATCH_PATTERN_GRATE,          /**<@brief  GRATE */
        VX_HATCH_PATTERN_HEXAGON,        /**<@brief  HEXAGON */
        VX_HATCH_PATTERN_HONEYCOMB,      /**<@brief  HONEYCOMB */
        VX_HATCH_PATTERN_SQUARES,        /**<@brief  SQUARES */
        VX_HATCH_PATTERN_MOONYANG,       /**<@brief  MOONYANG */
        VX_HATCH_PATTERN_BOX,            /**<@brief  BOX */
        VX_HATCH_PATTERN_BRASS,          /**<@brief  BRASS */
        VX_HATCH_PATTERN_BRSTONE,        /**<@brief  BRSTONE */
        VX_HATCH_PATTERN_CLAY,           /**<@brief  CLAY */
        VX_HATCH_PATTERN_ESCHER,         /**<@brief  ESCHER */
        VX_HATCH_PATTERN_GRAVEL,         /**<@brief  GRAVEL */
        VX_HATCH_PATTERN_HOUND,          /**<@brief  HOUND */
        VX_HATCH_PATTERN_INSUL,          /**<@brief  INSUL */
        VX_HATCH_PATTERN_ACAD_ISO02W100, /**<@brief  ACAD_ISO02W100 */
        VX_HATCH_PATTERN_ACAD_ISO03W100, /**<@brief  ACAD_ISO03W100 */
        VX_HATCH_PATTERN_ACAD_ISO04W100, /**<@brief  ACAD_ISO04W100 */
        VX_HATCH_PATTERN_ACAD_ISO05W100, /**<@brief  ACAD_ISO05W100 */
        VX_HATCH_PATTERN_ACAD_ISO06W100, /**<@brief  ACAD_ISO06W100 */
        VX_HATCH_PATTERN_ACAD_ISO07W100, /**<@brief  ACAD_ISO07W100 */
        VX_HATCH_PATTERN_ACAD_ISO08W100, /**<@brief  ACAD_ISO08W100 */
        VX_HATCH_PATTERN_ACAD_ISO09W100, /**<@brief  ACAD_ISO09W100 */
        VX_HATCH_PATTERN_ACAD_ISO10W100, /**<@brief  ACAD_ISO10W100 */
        VX_HATCH_PATTERN_ACAD_ISO11W100, /**<@brief  ACAD_ISO11W100 */
        VX_HATCH_PATTERN_ACAD_ISO12W100, /**<@brief  ACAD_ISO12W100 */
        VX_HATCH_PATTERN_ACAD_ISO13W100, /**<@brief  ACAD_ISO13W100 */
        VX_HATCH_PATTERN_ACAD_ISO14W100, /**<@brief  ACAD_ISO14W100 */
        VX_HATCH_PATTERN_ACAD_ISO15W100, /**<@brief  ACAD_ISO15W100 */
        VX_HATCH_PATTERN_JIS_LC_20,      /**<@brief  JIS_LC_20 */
        VX_HATCH_PATTERN_JIS_LC_20A,     /**<@brief  JIS_LC_20A */
        VX_HATCH_PATTERN_JIS_LC_8A,      /**<@brief  JIS_LC_8A */
        VX_HATCH_PATTERN_JIS_LC_8,       /**<@brief  JIS_LC_8 */
        VX_HATCH_PATTERN_JIS_RC_10,      /**<@brief  JIS_RC_10 */
        VX_HATCH_PATTERN_JIS_RC_15,      /**<@brief  JIS_RC_15 */
        VX_HATCH_PATTERN_JIS_RC_18,      /**<@brief  JIS_RC_18 */
        VX_HATCH_PATTERN_JIS_RC_30,      /**<@brief  JIS_RC_30 */
        VX_HATCH_PATTERN_JIS_STN_1E,     /**<@brief  JIS_STN_1E */
        VX_HATCH_PATTERN_JIS_STN_2_5,    /**<@brief  JIS_STN_2_5 */
        VX_HATCH_PATTERN_JIS_WOOD,       /**<@brief  JIS_WOOD */
        VX_HATCH_PATTERN_LINE,           /**<@brief  LINE */
        VX_HATCH_PATTERN_MUDST,          /**<@brief  MUDST */
        VX_HATCH_PATTERN_NET,            /**<@brief  NET */
        VX_HATCH_PATTERN_NET3,           /**<@brief  NET3 */
        VX_HATCH_PATTERN_PLAST,          /**<@brief  PLAST */
        VX_HATCH_PATTERN_PLASTI,         /**<@brief  PLASTI */
        VX_HATCH_PATTERN_SACNCR,         /**<@brief  SACNCR */
        VX_HATCH_PATTERN_STARS,          /**<@brief  STARS */
        VX_HATCH_PATTERN_STEEL,          /**<@brief  STEEL */
        VX_HATCH_PATTERN_SWAMP,          /**<@brief  SWAMP */
        VX_HATCH_PATTERN_TRANS,          /**<@brief  TRANS */
        VX_HATCH_PATTERN_TRIANG,         /**<@brief  TRIANG */
        VX_HATCH_PATTERN_ZIGZAG,         /**<@brief  ZIGZAG */
        VX_HATCH_PATTERN_SOLID,          /**<@brief  SOLID */
    } evxHatchPtnType;

    /**
    @brief cosmetic sketch hatch pattern definition data
    @ingroup zwapi_cmd_sk_create_data
    */
    typedef struct svxHatchPtnData
    {
        evxHatchPtnType pattern; /**<@brief  hatch pattern method
                                       default: VX_HATCH_PATTERN_ANSI31 */
        double angle;            /**<@brief  angle attribute
                                       default: 0.0 */
        double space;            /**<@brief  spacing attribute
                                       default: 3.175 */
        evxColor color;          /**<@brief  color attribute
                                       default: VX_COLOR_BLACK */
    } svxHatchPtnData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SKETCH_CREATE_DATA */
