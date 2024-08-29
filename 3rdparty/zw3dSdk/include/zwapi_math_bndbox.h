/**
@file zwapi_math_bndbox.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Bounding Box API
*/
/**
@defgroup zwapi_math_bndbox Bounding Box Math API
@ingroup MathModel
@brief
@details THE MODULE FOR THE ZW3D Bounding Box API
*/

#pragma once
#ifndef ZW_API_BND_BOX_H /* this ifndef surrounds entire header */
#define ZW_API_BND_BOX_H

#include "zwapi_math_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Bounding Box */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_bndbox

    Initializes the specified bounding box to all values set to zero.

    @param [in,out] Box pointer to bounding box data

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxBndBoxInit(svxBndBox *Box);

    /**
    @ingroup zwapi_math_bndbox

    Initializes the specified bounding box "min" values to "positive infinity"
    and "max" values to "negative infinity".

    @param [in,out] Box pointer to bounding box data

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxBndBoxInit2(svxBndBox *Box);

    /**
    @ingroup zwapi_math_bndbox

    Outputs the corner points of the specified bounding box to the array
    referenced by "Pnts".  
    Memory for the array must be allocated by the calling procedure.  
    "Pnts" is a pointer to the start of the memory and
    must reference at least enough memory for 8 svxPoint structures.

    The corners are assigned to "Pnts" as follows, where "min" and "max"
    refer to the bounding box's minimum and maximum limits in the
    specified coordinate direction:  

      Pnts[0] = Xmin,Ymin,Zmin   
      Pnts[1] = Xmax,Ymin,Zmin   
      Pnts[2] = Xmax,Ymax,Zmin   
      Pnts[3] = Xmin,Ymax,Zmin   
      Pnts[4] = Xmin,Ymin,Zmax   
      Pnts[5] = Xmax,Ymin,Zmax   
      Pnts[6] = Xmax,Ymax,Zmax   
      Pnts[7] = Xmin,Ymax,Zmax   

    @param [in] Box pointer to bounding box data
    @param [in,out] Pnts pointer to array of 8 point structures

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxBndBoxPnts(svxBndBox *Box, svxPoint *Pnts);

    /**
    @ingroup zwapi_math_bndbox

    Gets the center of the specified bounding box.

    @param [in] Box the bounding box
    @param [out] CenterPnt the center point of bounding box

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxBndBoxCenter(const svxBndBox *Box, svxPoint *CenterPnt);

    /**
    @ingroup zwapi_math_bndbox

    Determine whether a given point lies inside, outside or on the specified bounding box.

    @param [in] Box the bounding box
    @param [in] Point point to measure distance to
    @param [out] PntLoc returned status of the point on the bounding box

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxBndBoxPntLoc(const svxBndBox *Box, const svxPoint *Point, evxPntLocation *PntLoc);

    /**
    @ingroup zwapi_math_bndbox

    "Grows" the specified bounding box to envelop the specified point.

    @param [in,out] Box pointer to bounding box data
    @param [in] Pnt point to add to bounding box

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxBndBoxAdd(svxBndBox *Box, svxPoint *Pnt);

    /**
    @ingroup zwapi_math_bndbox

    Merge two bounding boxes and output results to the second bounding box.

    @param [in] Box1 the first bounding box
    @param [in,out] Box2 the second bounding box

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxBndBoxMerge(const svxBndBox *Box1, svxBndBox *Box2);

    /**
    @ingroup zwapi_math_bndbox

    Returns the "size" of the specified bounding box -- that is,
    the length of its diagonal.

    @param [in] Box pointer to bounding box data
    */
    extern double cvxBndBoxSize(svxBndBox *Box);

    /**
    @ingroup zwapi_math_bndbox

    Returns the volume of the specified bounding box. the volume will be set
    to 0.0 if there is an error in the function such as Box is NULL or something.

    @param [in] Box pointer to bounding box data
    */
    extern double cvxBndBoxVolume(const svxBndBox *Box);

    /**
    @ingroup zwapi_math_bndbox

    Check whether the base bounding box is completely containing an other bounding box.

    @param [in] BaseBox the base bounding box
    @param [in] OtherBox the other bounding box

    @retval succeeds
    -        ZW_API_NO_ERROR - The base bounding box does not contain an other bounding box.
    -        1 - The base bounding box contains an other bounding box.
    @retval fail
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxBndBoxContain(const svxBndBox *BaseBox, const svxBndBox *OtherBox);

    /**********************************************************************
    *! -Bounding Box Transform- : zwapi_math_matrix.h
    *  extern void cvxBndBoxTransform(svxMatrix* Mat, svxBndBox* Box);
    **********************************************************************/


    //====================================================================================================================
    /** @name Bounding Box Distance */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_bndbox

    Compute the maximum and minimum distance between a point and a 3D bounding boxes.

    @param [in] Box the bounding box
    @param [in] Point point to measure distance to
    @param [out] DistMin minimum distance, 0 if overlap (NULL to ignore)
    @param [out] DistMax maximum distance (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxBndBoxPntDist(const svxBndBox *Box, const svxPoint *Point, double *DistMin, double *DistMax);

    /**
    @ingroup zwapi_math_bndbox

    Compute the maximum and minimum distance between a point and a 3D bounding boxes.

    @param [in] Box1 the first bounding box
    @param [in] Box2 the second bounding box
    @param [out] DistMin minimum distance between boxes, 0 if overlap (NULL to ignore)
    @param [out] DistMax maximum distance between boxes (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxBndBoxDist(const svxBndBox *Box1, const svxBndBox *Box2, double *DistMin, double *DistMax);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_BND_BOX_H */
