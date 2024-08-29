/**
@file zwapi_math_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the All
Math functions.
*/
/**
@defgroup zwapi_math_data Math Data
@ingroup MathModel
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the All
Math functions.
*/

#pragma once
#ifndef ZW_API_MATH_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_MATH_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Intersection of Curve/Face Data */
    //====================================================================================================================
    /**
    @brief face trim-curve option
    @ingroup zwapi_math_data
    */
    typedef enum evxFaceTrim
    {
        VX_TRIM_NONE  = 0, /**<@brief  ignore all trim boundaries */
        VX_TRIM_ALL   = 1, /**<@brief  use all face trim boundaries */
        VX_TRIM_OUTER = 2  /**<@brief  use only the outer trim boundaries */
    } evxFaceTrim;

    //====================================================================================================================
    /** @name Curve Evaluate Data */
    //====================================================================================================================
    /**
    @brief curve evaluate
    @ingroup zwapi_math_data
    */
    typedef struct svxEvalCurv
    {
        int level;        /**<@brief  level of evaluation                       */
        svxPoint pnt;     /**<@brief  level 0 - x,y,z (or u,v)                  */
        svxPoint deriv_1; /**<@brief  level 1 - x',y' (or u',v')                */
        svxPoint deriv_2; /**<@brief  level 2 - x'',y'' (or u'',v'')            */
        svxPoint deriv_3; /**<@brief  level 3 - x''',y''',z''' (or u''',v''')   */
    } svxEvalCurv;

    //====================================================================================================================
    /** @name Surface Find Face/Edge Data */
    //====================================================================================================================
    /**
    @brief face search types
    @ingroup zwapi_math_data
    */
    typedef enum evxFaceFindType
    {
        VX_FIND_BOSS,   /**<@brief  find the faces that have the geometric characteristics of a boss */
        VX_FIND_POCKET, /**<@brief  find the faces that have the geometric characteristics of a pocket */
        VX_FIND_HOLE,   /**<@brief  find the faces that have the geometric characteristics of a hole */
        VX_FIND_FILLET, /**<@brief  find the faces that have the geometric characteristics of a network of fillet chains */
        VX_FIND_CUSTOM, /**<@brief  find the faces based on the stop conditions set (evxFindRule) */
        VX_FIND_FINDER, /**<@brief  base on seed face, find the faces that conforms to the set rules (evxFindRule) */
    } evxFaceFindType;

    /**
    @brief face search data
    @ingroup zwapi_math_data
    */
    typedef struct svxFaceFind
    {
        int numSeeds;           /**<@brief  number of seed faces */
        int *idSeeds;           /**<@brief  list of seed faces */
        evxFaceFindType Option; /**<@brief  type of face to search for */
        int Rule;               /**<@brief  face search rules(evxFindRule),like this:VX_STOP_FACE_FILLET | VX_STOP_FACE_FILLET,
                              used only for VX_FIND_CUSTOM & VX_FIND_FINDER(evxFaceFindType) type */
        int numEdges;           /**<@brief  number of stop edges, used only for VX_FIND_CUSTOM(evxFaceFindType) type  */
        int *idEdges;           /**<@brief  list of stop edges, used only for VX_FIND_CUSTOM(evxFaceFindType) type */
        int AdjCnt;             /**<@brief  adjacency count(>0), used only when Rule contain VX_STOP_ADJACENCY_LEVEL */
        int numFaces;           /**<@brief  number of stop faces, used only when Rule contain VX_STOP_BOUNDARY_FACE */
        int *idFaces;           /**<@brief  list of stop faces, used only when Rule contain VX_STOP_BOUNDARY_FACE */
    } svxFaceFind;

    /**
    @brief type of loop in which the edge is located
    @ingroup zwapi_math_data
    */
    typedef enum evxEdgeLoopType
    {
        VX_EDGE_LOOP_INNER    = 0, /**<@brief  inner loop edges */
        VX_EDGE_LOOP_OUTER    = 1, /**<@brief  outer loop edges */
        VX_EDGE_LOOP_ALL      = 2, /**<@brief  all edges */
        VX_EDGE_LOOP_SHARED   = 3, /**<@brief  shared edges */
        VX_EDGE_LOOP_BOUNDARY = 4  /**<@brief  boundary edges */
    } evxEdgeLoopType;


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_MATH_DATA_H */
