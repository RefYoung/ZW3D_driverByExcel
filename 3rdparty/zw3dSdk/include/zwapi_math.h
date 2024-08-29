/**
@file zwapi_math.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Math API
*/
/**
@defgroup zwapi_math Math Common API
@ingroup MathModel
@brief
@details THE MODULE FOR THE ZW3D Math API
*/

#pragma once
#ifndef ZW_API_MATH_H /* this ifndef surrounds entire header */
#define ZW_API_MATH_H

#include "zwapi_math_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Round Number */
    //====================================================================================================================
    /**
    @ingroup zwapi_math

    Return rounded number.  
    "Rounding" in this case means the number is
    adjusted to a value that is a whole-number multiple of the incremental
    step size Step.  
    For example, if Step is 0.25, this function returns
    values such as -0.5, -0.25, 0.0, 0.25, 0.5, 0.75, 1.0, and so on.  
    To round a number to the nearest integer value, set Step to 1.

    If Step is effectively 0 or negative, the incremental step size is so
    small that no rounding occurs and the return value is Num.

    If the rounding direction Dir is 0, Num is rounded to the nearest
    whole-number multiple of Step, which may be greater or less than Num.  
    For example, if Step is 1, an input value of 3.4 is rounded down to
    3.0, and an input value of 3.6 is rounded up to 4.0.

    If Dir is +1, the magnitude of Num is rounded up.  For example, if
    Step is 1, an input value of 3.4 is rounded to 4.0, and an input value
    of -3.4 is rounded to -4.0.

    If Dir is -1, the magnitude of Num is rounded down.  For example, if
    Step is 1, an input value of 3.6 is rounded to 3.0, and an input value
    of -3.6 is rounded to -3.0.

    The tolerance Tol helps to avoid unintended rounding.  
    If Num is within Tol of a whole-number multiple of Step, Num is rounded to the
    latter value regardless of the rounding direction specified by Dir.  
    For example, suppose Step is 1 and Dir is -1, but Num is 3.99999 when
    Tol is 0.01.  
    The result will be rounded up to 4.0 because Num is is
    effectively the same as 4.0 within the given tolerance, despite Dir
    indicating that Num should be rounded down.

    The step size Step should be much larger than the tolerance Tol.

    If Num is a value that represents a distance or an angle, all three
    inputs Num, Step and Tol should have the same units.
    @param [in] Num Number to round.
    @param [in] Step Incremental step size, may be 0.
    @param [in] Tol Tolerance for two values to be the same.
    @param [in] Dir Rounding direction (0 nearest, -1 down, +1 up).

    */
    extern double cvxRoundNumber(double Num, double Step, double Tol, int Dir);

    //====================================================================================================================
    /** @name Parallel Check */
    //====================================================================================================================
    /**
    @ingroup zwapi_math

    Check if curve lies on a plane parallel to the specified plane. if so output the distance
    between the curve and the plane.

    @param [in] plnPnt point on check plane
    @param [in] plnNormal normal of check plane
    @param [in] Crv curve to check for parallelism
    @param [in] tol 3D proximity tolerance(mm) (0.0 for default)
    @param [out] isParallel flag (1: parallel; 0: NOT parallel)
    @param [out] Distance the distance between curve and plane, valid output only if parallel flag is true (NULL to ignore)  
                          +: curve is on side of plane pointed to by normal   
                          -: curve is on the opposite side of plane pointed to by normal

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxCrvPlaneParallelChk(const svxPoint *plnPnt, const svxVector *plnNormal, const svxCurve *Crv, double tol, int *isParallel, double *Distance);

    //====================================================================================================================
    /** @name Distance Computes */
    //====================================================================================================================
    /**
    @ingroup zwapi_math

    Computes the closest point between two 3D axes.

    If the axes intersect (Flag is 0), ParamOnAxis1 & ParamOnAxis1 define
    parametric locations of intersection point on the two axes.

    If the axes are parallel (Flag is 1), ParamOnAxis1 & ParamOnAxis1 are undefined.

    If the axes are not co-planar and they do not intersect (Flag is 2), ParamOnAxis1
    & ParamOnAxis1 define the parametric locations of the closest points.

    @param [in] Axis1 the first axis
    @param [in] Axis2 the second axis
    @param [out] PntOnAxis1 the parameter of the closet point on the first axis (NULL to ignore)
    @param [out] PntOnAxis2 the parameter of the closet point on the second axis (NULL to ignore)
    @param [out] Flag flag of the two axes position relationship (NULL to ignore)  
                      0: axes intersect  
                      1: axes are parallel  
                      2: axes are not parallel(no intersection and not coplanar) 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxAxisDistance(const svxAxis *Axis1, const svxAxis *Axis2, svxPoint *PntOnAxis1, svxPoint *PntOnAxis2, int *Flag);

    /**
    @ingroup zwapi_math_point

    Gets the minimum distance from curve to an infinite line defined by point and direction.

    @param [in] Axis axis defined by a point and a direction
    @param [in] Crv curve to measure distance to
    @param [out] pntOnAxis the closest point on the axis (NULL to ignore)
    @param [out] pntOnCrv the closest point on the curve (NULL to ignore)
    @param [out] Distance the minimum distance (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxAxisCrvDistance(const svxAxis *Axis, const svxCurve *Crv, svxPoint *pntOnAxis, svxPoint *pntOnCrv, double *Distance);

    /**
    @ingroup zwapi_math

    Gets the distance between two infinite planes and outputs 0.0 if the two
    planes intersect or coincide.

    @param [in] PntOnPln1 point on plane1
    @param [in] NormalOfPln1 normal of plane1
    @param [in] PntOnPln2 point on plane2
    @param [in] NormalOfPln2 normal of plane2
    @param [out] Distance the distance

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPlaneDistance(const svxPoint *PntOnPln1, const svxVector *NormalOfPln1, const svxPoint *PntOnPln2, const svxVector *NormalOfPln2, double *Distance);

    /**
    @ingroup zwapi_math

    Get the distance between 2 entities in part environment,
    the entity type includes face, curve, edge, datum plane, point.

    @param [in] ent1 index of entity 1
    @param [in] ent2 index of entity 2
    @param [out] p1 point on entity 1 (NULL to ignore)
    @param [out] p2 point on entity 2 (NULL to ignore)
    @param [out] dist distance of p1 and p2

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxEntGetDistance(int ent1, int ent2, svxPoint *p1, svxPoint *p2, double *dist);

    /**
    @ingroup zwapi_math

    Get the minimum distance between 2 entities in part environment,
    the entity type includes shape and component.

    @param [in] EntPath1 the pick path of the first entity
    @param [in] EntPath2 the pick path of the second entity
    @param [out] Point1 Location on second entity at point of closest contact.(NULL to ignore)
    @param [out] Point2 Location on second entity at point of closest contact.(NULL to ignore)
    @param [out] MinDistance the minimum distance.(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxEntGetDistanceByPath(svxEntPath *EntPath1, svxEntPath *EntPath2, svxPoint *Point1, svxPoint *Point2, double *MinDistance);

    //====================================================================================================================
    /** @name Entity Calculate */
    //====================================================================================================================
    /**
    @ingroup zwapi_math

    Get the angle between 2 entities.the entity type includes line, curve, edge,
    datum plane, planar face, sketch.

    @note
    ent1 and ent2 must are defined as "curve-curve" or "planar face-planar face".
    when entities are curve, the angle between the tangent direction of the starting
    point of the line is calculated.

    @param [in] ent1 index of entity 1
    @param [in] ent2 index of entity 2
    @param [out] angle angle (radians) between entities

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxEntGetAngle(int ent1, int ent2, double *angle);

    /**
    @ingroup zwapi_general_ent

    Inquires a planar area bounded by curves in 3d space.

    The input boundaries may consist of 3d-curves, edges,
    sketch profiles, and curve lists.

    The input just support one plane face.

    @note
       The calling procedure MUST deallocate the output(pAreaRef and pAreaCA) with cvxMemFree().  
       Use cvxPartInqEntsAreaByPath() to inquire the area of the entities of sketch/component.

    @param [in] cnt count of curves/face (only one face)
    @param [in] crvList id list of curves/face
    @param [out] areaProp area property

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqEntsArea(int cnt, int *crvList, svxAreaProp *areaProp);

    /**
    @ingroup zwapi_math

    Inquires a planar area bounded by curves in 3d space.

    The input boundaries may consist of 3d-curves, 2d-curves, edges,
    and all of them in the component.

    The input just support one plane face.

    @note
       The calling procedure MUST deallocate the output(pAreaRef and pAreaCA) with cvxMemFree().  
       Use cvxPartInqEntsArea() to inquire the area of the entities of current part.

    @param [in] cnt count of curves/face (only one face)
    @param [in] crvList entity path list of curves/face
    @param [out] areaProp area property

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ENT_PATH_ERROR
    */
    extern evxErrors cvxPartInqEntsAreaByPath(int cnt, svxEntPath *crvList, svxAreaProp *areaProp);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_MATH_H */
