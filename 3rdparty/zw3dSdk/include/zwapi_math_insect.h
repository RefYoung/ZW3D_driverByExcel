/**
@file zwapi_math_insect.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Intersection API
*/
/**
@defgroup zwapi_math_insect Entities Intersection API
@ingroup MathModel
@brief
@details THE MODULE FOR THE ZW3D Intersection API
*/

#pragma once
#ifndef ZW_API_INSECT_H /* this ifndef surrounds entire header */
#define ZW_API_INSECT_H

#include "zwapi_math_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Curve And Curve/Face */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_insect

    Outputs a list of the points where the two input curves intersect.
    The calling procedure MUST deallocate the output list.

    @param [in] idCurve1 first curve
    @param [in] idCurve2 second curve
    @param [in] TangentOk 1 to include points of tangency; else 0
    @param [out] Count number of intersection points
    @param [out] Points list of intersection points

    @retval succeeds
    -        ZW_API_NO_ERROR - one or more intersection points are found.
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or no intersection point is found.
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxIsectCrvCrv(int idCurve1, int idCurve2, int TangentOk, int *Count, svxPoint **Points);

    /**
    @ingroup zwapi_math_insect

    Outputs a list of the points where the input curve and face intersect.  
    The calling procedure MUST deallocate the output list.

    @param [in] idCurve id of curve entity in active file
    @param [in] idFace id of face entity in active file
    @param [in] Trim 1 to intersect trimmed face; 0 to intersect entire untrimmed surface
    @param [in] TangentOk 1 to include points of tangency; else 0
    @param [out] Count number of intersection points
    @param [out] Points list of intersection points

    @retval succeeds
    -        ZW_API_NO_ERROR - one or more intersection points are found.
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or no intersection point is found.
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxIsectCrvFace(int idCurve, int idFace, int Trim, int TangentOk, int *Count, svxPoint **Points);

    /**
    @ingroup zwapi_math_insect

    Outputs a list of curves where the two input faces intersect.  
    the output Curves data can be added to the active part with
    the cvxPartCurve() function.

    The calling procedure MUST deallocate the internal data in each
    element of the output list by calling cvxCurveFree(), after which the
    output list MUST be deallocated using cvxMemFree((void**)Curves).

    @param [in] idFace1 id of the first face entity in active file
    @param [in] idFace2 id of the second face entity in active file
    @param [in] Trim face trim-curve option
    @param [in] TangentOk 1 to include curves of tangency; else 0
    @param [out] Count number of intersection curves
    @param [out] Curves list of intersection curves

    @retval succeeds
    -        ZW_API_NO_ERROR - one or more intersection curves are found
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or no intersection curves is found.
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxIsectFaceFace(int idFace1, int idFace2, evxFaceTrim Trim, int TangentOk, int *Count, svxCurve **Curves);


    //====================================================================================================================
    /** @name Ray With Objects */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_insect

    Outputs a list of the points where the input ray and curve intersect.  
    The calling procedure MUST deallocate the output list.

    @param [in] Ray ray defined by a point and a direction
    @param [in] idCurve curve entity
    @param [in] TangentOk 1 to include points of tangency; else 0
    @param [out] Count number of intersection points
    @param [out] Points list of intersection points

    @retval succeeds
    -        ZW_API_NO_ERROR - one or more intersection points are found.
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or no intersection point is found.
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxIsectRayCrv(svxAxis *Ray, int idCurve, int TangentOk, int *Count, svxPoint **Points);

    /**
    @ingroup zwapi_math_insect

    Intersects the input ray with the input face and outputs the
    point closest to the ray startpoint (Ray->Pnt).

    @note
    The ray only extends in the specified direction from the startpoint.
    Intersections in the other direction are not considered.  
    The "Trim" option is used to determine what portions of
    the face are checked against the ray.

    @param [in] idFace id of face in active file
    @param [in] Trim face trim option
    @param [in] Ray ray defined by a point and a direction
    @param [out] Point intersection point (NULL to ignore)
    @param [out] UV U,V coordinates (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR - intersection point successfully found
    @retval fail
    -        ZW_API_GENERAL_ERROR - fails or no intersection is found
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxIsectRayFace(int idFace, evxFaceTrim Trim, svxAxis *Ray, svxPoint *Point, svxPoint2 *UV);

    /**
    @ingroup zwapi_math_insect

    Intersects the input ray with the input face and outputs all
    intersection points to the ray start point (Ray->Pnt).

    The "Trim" option is used to determine what portions of
    the face are checked against the ray.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idFace id of shape in active part
    @param [in] Trim face trim option
    @param [in] Ray ray defined by a point and a direction
    @param [in] Infinite 1 to check both directions of ray,
                         0 to check positive direction of ray only
    @param [out] Number number of points
    @param [out]  Pnts list of intersection points (NULL to ignore)
    @param [out]  UVs list of U,V coordinates (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR - intersection point successfully found
    @retval fail
    -        ZW_API_GENERAL_ERROR - fails or no intersection is found
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxIsectRayFaceInfinite(int idFace, evxFaceTrim Trim, const svxAxis *Ray, int Infinite, int *Number, svxPoint **Pnts, svxPoint2 **UVs);

    /**
    @ingroup zwapi_math_insect

    Intersects the input ray with the XY plane of the specified
    transformation matrix and outputs the point of intersection.

    @param [in] Ray ray defined by a point and a direction
    @param [in] Plane plane transformation matrix (XY plane)
    @param [out] Point intersection point

    @retval succeeds
    -        ZW_API_NO_ERROR - intersection point successfully found.
    -        1 - if the ray is parallel to, and on the plane.
    -        2 - if the ray is parallel to, but off the plane.
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern int cvxIsectRayPlane(svxAxis *Ray, svxMatrix *Plane, svxPoint *Point);

    /**
    @ingroup zwapi_math_insect

    Intersects the input ray with the input shape and outputs the
    point closest to the ray start point (Ray->Pnt).

    @note
    The ray only extends in the specified direction from the start point.
    Intersections in the other direction are not considered.  
    If an intersection is found, the id of the intersected face is
    optionally output.  
    The "Trim" option is used to determine what portions of
    the shapes' faces are checked against the ray.

    @param [in] idShape id of shape in active part
    @param [in] Trim face trim option
    @param [in] Ray ray defined by a point and a direction
    @param [out] Point closest intersection point (NULL to ignore)
    @param [out] idFace id of face that intersection point lies on
                        (input NULL to ignore this output)

    @retval succeeds
    -        ZW_API_NO_ERROR - intersection point successfully found.
    @retval fail
    -        ZW_API_GENERAL_ERROR - fails or no intersection is found.
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxIsectRayShape(int idShape, evxFaceTrim Trim, svxAxis *Ray, svxPoint *Point, int *idFace);

    /**
    @ingroup zwapi_math_insect

    Intersects the input ray with the input shapes and outputs the intersection points.

    @note
    The positive and negative directions of the ray will be involved in the calculation.  
    The "Trim" option is used to determine what portions of the shape's faces are
    checked against the ray.  
    This function allocates memory for the array output via "Points" and "FacePaths".   
    The calling procedure is responsible for deallocating the memory.

    @param [in] nShapes number of shapes
    @param [in] idShapes index of shapes
    @param [in] Trim face trim option
    @param [in] Ray ray defined by a point and a direction
    @param [out] Number number of intersection point
    @param [out] Points list of intersection points (NULL to ignore)
    @param [out] idFaces list of face ids that intersection point lies (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR - intersection point successfully found.
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or no intersection is found.
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxIsectRayShapes(int nShapes, int *idShapes, evxFaceTrim Trim, svxAxis *Ray, int *Number, svxPoint **Points, int **idFaces);

    /**
    @ingroup zwapi_math_insect

    Intersects the input ray with all faces of the active part and
    outputs the point closest to the ray startpoint (Ray->Pnt).

    @note
    The ray only extends in the specified direction from
    the startpoint.  
    Intersections in the other direction are not considered.  
    If an intersection is found, the id of the intersected
    face is optionally output.  
    Use cvxPartInqFaceShape() to get the id of the face's parent shape.

    The "Trim" option is used to determine what portions of
    the parts's faces are checked against the ray.

    @param [in] Trim face trim option
    @param [in] Ray ray defined by a point and a direction
    @param [out] Point closest intersection point (NULL to ignore)
    @param [out] idFace id of face that intersection point lies on
                        (input NULL to ignore this output)

    @retval succeeds
    -        ZW_API_NO_ERROR - intersection point successfully found.
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or no intersection is found.
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxIsectRayPart(evxFaceTrim Trim, svxAxis *Ray, svxPoint *Point, int *idFace);

    /**
    @ingroup zwapi_math_insect

    This function is the same as cvxIsectRayPart(), except that it
    only considers visible faces.  
    That is, it ignores faces that belong to blanked shapes.

    @param [in] Trim face trim option
    @param [in] Ray ray defined by a point and a direction
    @param [out] Point closest intersection point (NULL to ignore)
    @param [out] idFace id of face that intersection point lies on
                        (input NULL to ignore this output)

    @retval succeeds
    -        ZW_API_NO_ERROR - intersection point successfully found.
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or no intersection is found.
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxIsectRayPartVis(evxFaceTrim Trim, svxAxis *Ray, svxPoint *Point, int *idFace);

    /**
    @ingroup zwapi_math_insect

    Intersects the input ray with the specified component in the
    active part and outputs the point closest to the ray
    startpoint (Ray->Pnt).  
    The output point coordinates are given in the space of the active part.

    @note
    The ray only extends in the specified direction from the startpoint.  
    Intersections in the other direction are not considered.  
    The "Trim" option is used to determine what portions of
    the component's faces are checked against the ray.

    @param [in] idComp component id
    @param [in] Trim face trim option
    @param [in] Ray ray defined by a point and a direction
    @param [out] Point closest intersection point (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR - intersection point successfully found.
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or no intersection is found.
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxIsectRayComp(int idComp, evxFaceTrim Trim, svxAxis *Ray, svxPoint *Point);

    /**
    @ingroup zwapi_math_insect

    Intersects the input ray with the input components and outputs the intersection points.

    @note
    The positive and negative directions of the ray will be involved in the calculation.  
    The "Trim" option is used to determine what portions of the shape's faces are
    checked against the ray.

    This function allocates memory for the array output via "Points" and "FacePaths".  
    The calling procedure is responsible for deallocating the memory.

    @param [in] nComps number of components
    @param [in] CompPaths pick path of components
    @param [in] Trim face trim option
    @param [in] Ray ray defined by a point and a direction
    @param [out] Number number of intersection point
    @param [out] Points list of intersection points (NULL to ignore)
    @param [out] FacePaths list of face pick paths that intersection
                           point lies (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR - intersection point successfully found.
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or no intersection is found.
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxIsectRayComps(int nComps, svxEntPath *CompPaths, evxFaceTrim Trim,
                                      svxAxis *Ray, int *Number, svxPoint **Points, svxEntPath **FacePaths);

    /**
    @ingroup zwapi_math_insect

    Outputs a list of indices of the components that belong
    the active part and are intersected by the specified
    ray.   
    Only intersections within "Dist" of the ray's
    start point (Ray->Pnt) are considered.

    The "Trim" option is used to determine what portions of
    the component faces are checked against the ray.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] Trim face trim option
    @param [in] Ray ray defined by a point and a direction
    @param [in] Dist distance from start of ray along direction of ray
    @param [in] SkipBlank 1 to skip blanked components; else 0
    @param [out] Count number of components
    @param [out] Comps list of component id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxCompFind(evxFaceTrim Trim, svxAxis *Ray, double Dist, int SkipBlank, int *Count, int **Comps);

    /**
    @ingroup zwapi_math_insect

    Intersect an infinite line with a bounding box.   
    the intersection point given
    is the farthest point on the ray along the opposite direction of the ray.

    @param [in] Ray ray defined by a point and a direction
    @param [in] Box the bounding box
    @param [out] IsectPnt the intersection point (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR - No intersection point found.
    -        1 - Intersection point found.
    @retval fail
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxIsectRayBndBox(const svxAxis *Ray, const svxBndBox *Box, svxPoint *IsectPnt);

    //====================================================================================================================
    /** @name Intersecting of Shapes */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_insect

    Determine exist or not exist intersection between the input two shapes.

    @param [in] idBaseShape the need check intersection shape 1
    @param [in] idOpShape the need check intersection shape 2

    @retval return
    -        1 - found shape isect
    -        0 - no shape isect or error occurs
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern int cvxPartIsectShpChk(int idBaseShape, int idOpShape);

    /**
    @ingroup zwapi_math_insect

    Determine exist or not exist intersection between the input two shapes.  
    If should check the two shapes are closed, it will return 0 if any shape
    of them is not closed.

    @param [in] idBaseShape the need check intersection shape 1
    @param [in] idOpShape the need check intersection shape 2
    @param [in] fClosedChk option to control whether check the open shell
                           1 is excluding the open shell. otherwise is 0

    @retval return
    -        1 - found shape isect
    -        0 - no shape isect or error occurs
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern int cvxPartIsectShpChk2(int idBaseShape, int idOpShape, int fClosedChk);

    /**
    @ingroup zwapi_math_insect

    Gets the intersecting curves of two shapes(comps).

    @param [in] basePath path of the first shape
    @param [in] opPath path of the second shape
    @param [in] trim face trim option
    @param [out] count count of "curves"
    @param [out] curves list of intersection curves

    @retval return
    -        2 - basePath is the same as opPath.
    -        3 - not intersect.
    -        0 - success,intersection exists.
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern int cvxCompIsectShpShp(const svxEntPath *basePath, const svxEntPath *opPath, evxFaceTrim trim, int *count, svxCurve **curves);

    /**********************************************************************
    *! -Interference Check- : zwapi_cmd_assembly.h
    *  extern evxErrors cvxCompIsectShpChk(svxEntPath* BaseShpPath, svxEntPath* OpShpPath, int* fInterfer);
    *  extern evxErrors cvxCompIsectShpChk2(svxEntPath* BaseShpPath, svxEntPath* OpShpPath, int fClosedChk, int* fInterfer);
    **********************************************************************/

    //====================================================================================================================
    /** @name Intersecting of bounding box and plane*/
    //====================================================================================================================

    /**
    @ingroup zwapi_math_insect

    Check whether two bounding boxes intersect.

    @param [in] Box1 the first bounding box
    @param [in] Box2 the second bounding box

    @retval succeeds
    -        ZW_API_NO_ERROR - Boxes do NOT intersect.
    -        1 - Boxes do intersect.
    @retval fail
    -        ZW_API_INVALID_INPUT
    @retval return
    -        -1: Errors.
    */
    extern int cvxIsectBndBoxBndBox(const svxBndBox *Box1, const svxBndBox *Box2);

    /**
    @ingroup zwapi_math_insect

    Check whether two bounding boxes intersect.

    @param [in] Box the bounding box
    @param [in] PntOnPln point on plane
    @param [in] NormalOfPln normal of plane

    @retval succeeds
    -        ZW_API_NO_ERROR - Box and plane do NOT intersect.
    -        1 - Box and plane do intersect.
    @retval fail
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxIsectBndBoxPlane(const svxBndBox *Box, const svxPoint *PntOnPln, const svxVector *NormalOfPln);

    /**
    @ingroup zwapi_math_insect

    Gets the intersection line of two planes both defined by a point and normal.

    @param [in] PntOnPln1 the bounding box
    @param [in] NormalOfPln1 point on plane
    @param [in] PntOnPln2 normal of plane
    @param [in] NormalOfPln2 normal of plane2
    @param [out] IsectLine intersection line

    @retval succeeds
    -        ZW_API_NO_ERROR - Valid intersection line found.
    -        1 - Planes are parallel and distinct.
    -        2 - Planes are identical.
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern int cvxIsectPlanePlane(const svxPoint *PntOnPln1, const svxVector *NormalOfPln1, const svxPoint *PntOnPln2, const svxVector *NormalOfPln2, svxAxis *IsectLine);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_INSECT_H */
