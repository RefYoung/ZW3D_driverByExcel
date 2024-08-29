/**
@file zwapi_math_point.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Point Math API
*/
/**
@defgroup zwapi_math_point Point Math API
@ingroup MathModel
@brief
@details THE MODULE FOR THE ZW3D Point Math API
*/

#pragma once
#ifndef ZW_API_POINT_H /* this ifndef surrounds entire header */
#define ZW_API_POINT_H

#include "zwapi_math_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Point On Entity */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_point

    This function is to determine whether the pnt is the critical point of   
    the 2D curve with index idCurve in Drawing Sheet.

    Meaning of critical point is the point with start, end, middle or center position  
    of the curve.

    @param [in] pnt point
    @param [in] idCurve index of 2D curve

    @retval return
    -        1 - it is a critical point
    -        0 - it is not a critical point or error
    @warning
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxPntIsCritical(svxPoint *pnt, int idCurve);

    /**
    @ingroup zwapi_math_point

    @param [in] Pnt point
    @param [in] idEntity id of curve, edge, face or plane entity

    @retval return
    -        1 - the input point lies within the active proximity tolerance of the input entity
    -        0 - otherwise
    @warning
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxPntIsOn(svxPoint *Pnt, int idEntity);

    /**
    @ingroup zwapi_math_point

    Calculates a 3D point on the specified curve entity    
    (in the active object) at the input fraction of the   
    curve's length from its startpoint.

    @param [in] idCurve id of curve in the active object
    @param [in] Fraction fraction of curve length (0.0 to 1.0)
    @param [out] Point point on curve

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPntOnCrv(int idCurve, double Fraction, svxPoint *Point);

    /**
    @ingroup zwapi_math_point

    Calculates a point on the specified face at the midpoint of  
    the face's bounding box in UV parameter space.  The 3D point  
    coordinates are output in the space of the active part, even  
    if the face belongs to a child component of the part (idComp > 0).  
    The corresponding U,V parameters are output as Param[0] and Param[1].  

    @param [in] idComp id of component that contains face (0 if undefined)
    @param [in] idFace id of face in active part or specified component
    @param [out] Param[2] u,v parameter values
    @param [out] Point point on face (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPntOnFace(int idComp, int idFace, double Param[2], svxPoint *Point);

    /**
    @ingroup zwapi_math_point

    Projects "Pnt" onto the specified curve, edge, face or plane  
    and outputs the result as "ProjPnt".

    @param [in] Pnt point to project
    @param [in] idEntity id of curve, edge, face or plane entity
    @param [out] ProjPnt projected point on entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPntProject(svxPoint *Pnt, int idEntity, svxPoint *ProjPnt);

    /**
    @ingroup zwapi_math_point

    Determine if a given point lies inside, outside or on the boundary of a given curve,  
    edge, face or shape.

    @param [in] Pnt point coordinates of the inquiry
    @param [in] idEntity entity id (only curve, edge, face and shape are supported)
    @param [out] PntLoc returned status of the point on the entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxPntEntLoc(svxPoint *Pnt, int idEntity, evxPntLocation *PntLoc);

    /**
    @ingroup zwapi_math_point

    Project point onto infinite line defined by point and direction.

    @param [in] Axis axis defined by a point and a direction
    @param [in] Pnt point to project
    @param [out] ProjPnt point projected on axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxAxisPntProject(const svxAxis *Axis, const svxPoint *Pnt, svxPoint *ProjPnt);

    /**
    @ingroup zwapi_math_point

    Project point onto infinite plane by point and direction.

    @param [in] PlnPnt point on plane
    @param [in] PlnNormal normal of plane 
    @param [in] Point point to project
    @param [in] ProjectDir projection direction (NULL to use normal of plane)
    @param [out] ProjPnt point projected on plane

    @retval succeeds
    -        ZW_API_NO_ERROR
    -        1 - The projection direction is parallel to the plane normal and point is on the plane.
    -        2 - The projection direction is parallel to the plane normal and point is not in the plane.
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern int cvxPlanePntProject(const svxPoint *PlnPnt, const svxVector *PlnNormal, const svxPoint *Point, const svxVector *ProjectDir, svxPoint *ProjPnt);

    //====================================================================================================================
    /** @name Point Distance */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_point

    Translates "Point" along "Vector" by "Distance".  
    This function assumes that "Vector" is normalized.

    @param [in,out] Point point
    @param [in] Vector direction vector
    @param [in] Distance distance

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxPntTranslate(svxPoint *Point, svxVector *Vector, double Distance);

    /**
    @ingroup zwapi_math_point

    Returns the distance between two points.

    @param [in] Point1 first point
    @param [in] Point2 second point

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern double cvxPntDist(const svxPoint *Point1, const svxPoint *Point2);

    /**
    @ingroup zwapi_math_point

    Acquire the minimum distance between the point and the target entity,  
    the target entity type includes shape, face, curve, edge, datum plane, point.

    @param [in] Point point coordinates of the inquiry
    @param [in] idEntity index of target entity
    @param [out] TargetPnt the closest point on target entity (NULL to ignore)
    @param [out] Distance the minimum distance (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOR_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPntEntDist(const svxPoint *Point, int idEntity, svxPoint *TargetPnt, double *Distance);

    /**
    @ingroup zwapi_math_point

    Acquire the minimum distance between the point and the curve on face, the difference  
    from cvxPntEntDist() is that the function will be output the closest point on the UV line  
    of the face. 

    @param [in] Point point coordinates of the inquiry
    @param [in] idPreEdge index of pre-edge
    @param [out] T parameter value at closest point (NULL to ignore)
    @param [out] TargetPnt coordinates of closest point (NULL to ignore)
    @param [out] Distance the minimum distance (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxPntPreEdgeDist(const svxPoint *Point, int idPreEdge, double *T, svxPoint *TargetPnt, double *Distance);

    /**
    @ingroup zwapi_math_point

    Gets the minimum distance from a point to an infinite line defined by point and direction.

    @param [in] Axis axis defined by a point and a direction
    @param [in] Pnt point to measure distance to
    @param [out] Distance the minimum distance

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxAxisPntDistance(const svxAxis *Axis, const svxPoint *Pnt, double *Distance);

    /**
    @ingroup zwapi_math_point

    Get the minimum distance form a point to an infinite plane by point and direction.

    @param [in] PlnPnt point on plane
    @param [in] PlnNormal normal of plane
    @param [in] Point point to measure distance to
    @param [out] Distance the minimum distance
    @param [out] ProjPnt point projected on plane (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPlanePntDistance(const svxPoint *PlnPnt, const svxVector *PlnNormal, const svxPoint *Point, double *Distance, svxPoint *ProjPnt);

    //====================================================================================================================
    /** @name Point Evaluation */
    //====================================================================================================================

    /**
    @ingroup zwapi_math_point

    Get point on axis at a specified distance from origin of axis.

    @param [in] Axis axis defined by a point and a direction
    @param [in] Distance distance    
                         > 0: along direction of axis  
                         < 0: the opppsite direction of axis  
    @param [out] Point point on the axis at specified distance

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxAxisEvalPoint(const svxAxis *Axis, double Distance, svxPoint *Point);

    /**
    @ingroup zwapi_math_point

    Get point on plane that offset the origin by a specified distance in the x-direction and y-direction.

    @param [in] Origin origin of plane
    @param [in] xAxis x-direction of plane
    @param [in] yAxis y-direction of plane 
    @param [in] xDist distance of x-direction (> 0: in same direction; < 0: in opppsite direction) 
    @param [in] yDist distance of y-direction (> 0: in same direction; < 0: in opppsite direction) 
    @param [out] Point point on the axis at specified distance

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPlaneEvalPoint(const svxPoint *Origin, const svxVector *xAxis, const svxVector *yAxis, double xDist, double yDist, svxPoint *Point);

    //====================================================================================================================
    /** @name Plane/Polygon */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_point

    Given "PntCount" points, this function computes the least squares plane  
    fitted through these points. It then checks to see if the points are  
    contained within this plane such that for any point (X,Y,Z) in the plane,  
    the following equation holds true:

    Normal.x * X + Normal.y * Y + Normal.z * Z + D = 0

    @param [in] PntCount number of points in point list
    @param [in] PntList list of points
    @param [out] Normal unit length vector normal to the plane
    @param [out] D the last term in the plane equation (see description below)

    @retval succeeds
    -        -2 : line or point in xy-plane (points do not define a plane).
    -        -1 : line or point not in xy-plane (points do not define a plane).
    -        0 : points do not lie in a unique plane.
    -        1 : points lie in a unique plane (not the xy-plane).
    -        2 : points lie in the xy-plane.
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern int cvxPlnThruPnts(int PntCount, svxPoint *PntList, svxVector *Normal, double *D);

    /**
    @ingroup zwapi_math_point

    Given an array of points "PntList" defining the coordinates of a  
    polygon's vertices, this function decomposes the polygon into  
    triangles.  The triangles are defined by an array of vertex indices  
    "VtxList", which is an int list of indices into the PntList array.  
    Every three elements in the output list define one triangle,  
    i.e. VtxList[0], VtxList[1] and VtxList[2] contain the PntList array  
    indices of the first triangle's vertices, VtxList[3], VtxList[4] and  
    VtxList[5] contain the PntList array indices of the second triangle,  
    and so on.  The total number of triangle vertices is output in  
    VtxCount.  The total number of triangles for the given polygon will be  
    (*VtxCount)/3.

    The points in PntList are assumed to be in vertex order around the   
    perimeter of the polygon.  The polygon may be concave.

    This function allocates the output array VtxList.  The caller is  
    responsible for freeing VtxList using cvxMemFree().

    @param [in] PntCount number of points in point list
    @param [in] PntList point list of polygon vertex coordinates
    @param [out] VtxCount number of triangle vertex indices in vertex list
    @param [out] VtxList vertex list of triangle vertex indices (see description below)

    @retval succeeds
    -        ZW_API_NO_ERROR - the polygon is successfully tessellated into triangles.
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPolyToTri(int PntCount, svxPoint *PntList, int *VtxCount, int **VtxList);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_POINT_H */
