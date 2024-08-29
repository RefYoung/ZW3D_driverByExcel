/**
@file zwapi_cmd_freeform.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Free Form Commands API
*/
/**
@defgroup zwapi_cmd_freeform Free Form Commands
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Free Form Commands API
*/

#pragma once
#ifndef ZW_API_FREEFORM_FTR_H /* this ifndef surrounds entire header */
#define ZW_API_FREEFORM_FTR_H

#include "zwapi_cmd_freeform_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Basic Face */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartFilletBlend().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data freeForm filletBlend data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartFilletBlendInit(svxFilletBlendData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Use this function to create an intelligent blend face.

    @note
    Interface cvxPartFilletBlendInit() can initialize variables of this function.

    @param [in] FilletBlend filletBlend input data
    @param [out] idFilletBlend id of FilletBlend feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartFilletBlend(const svxFilletBlendData *FilletBlend, int *idFilletBlend);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartNSided().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command N-sided data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartNSidedInit(svxNSidedData *data);

    /**
    @ingroup zwapi_cmd_freeform

    This API is to do the N-sided function for entities.
    The id of entity newly created is output by idShape.

    @note
    Interface cvxPartNSidedInit() can initialize variables of this function.

    @param [in]  NSidedData input boundary
    @param [out] idShape id of new shape(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_ONJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxPartNSided(const svxNSidedData *NSidedData, int *idShape);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartTrimmedPlane().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Trimmed Plane data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartTrimmedPlaneInit(svxTrimPlnData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Use this command to create a planar face trimmed to a set of bounding curves.
    Required inputs include the boundary curves to trim to.
    Optional inputs include a datum plane or planar face to project to.

    This function can output the new surface if data->sew is 0 and *newShp is not null.

    @note
    Interface cvxPartTrimmedPlaneInit() can initialize variables of this function.

    @param [in] data input data
    @param [out] newShp id of new shape(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartTrimmedPlane(svxTrimPlnData *data, int *newShp);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartRuled().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data ruled data to create a new ruled face

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartRuledInit(svxRuledData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Use the function to create a ruled face with linear cross-sections between two path curves. 

    @note
    Interface cvxPartRuledInit() can initialize variables of this function.

    @param [in] data ruled data to create a new ruled face
    @param [out] idFace index of new face (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartRuled(const svxRuledData *data, int *idFace);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartCircularBiRail().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] method circular bi rail method
    @param [out] data circular bi rail data to create a new circular face

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCircularBiRailInit(evxCircularBiRailMethod method, svxCircularBiRailData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Use the function to create a face of circular cross-section between two sets of path curves. 
    The radii of the cross-sections are determined by the creation method and are used to define
    a circle that intersects both boundary curves.

    @note
    Interface cvxPartCircularBiRailInit() can initialize variables of this function.

    @param [in] data circular bi rail data to create a new circular face
    @param [out] idFace id of new face (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCircularBiRail(const svxCircularBiRailData *data, int *idFace);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartConicBiRail().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] method conic bi rail method
    @param [out] data conic bi rail data to create a new conic face

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartConicBiRailInit(evxConicBiRailMethod method, svxConicBiRailData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Use the function to create a face with conic cross-sections between two path curves.
    The radii of the cross-sections are determined by the creation method.  This radius
    defines a circle that intersects both boundary curves.  Tangent lines to the circle
    at the intersection points, along with a conic ratio, define the conic cross-sections.

    @note
    Interface cvxPartConicBiRailInit() can initialize variables of this function.

    @param [in] data conic bi rail data to create a new conic face
    @param [out] idFace id of new face (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartConicBiRail(const svxConicBiRailData *data, int *idFace);

    //====================================================================================================================
    /** @name Edit Face */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartFacesOffset().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data faces offset data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartFacesOffsetInit(svxFcsOffsetData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Use this function to create a new face offset from a face at a specified distance.
    Multiple faces can be offset at the same time.

    @note
    Interface cvxPartFacesOffsetInit() can initialize variables of this function.

    @param [in] data face offset data
    @param [out] idFtr feature id (pass in NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartFacesOffset(const svxFcsOffsetData *data, int *idFtr);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartExtendFace().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Extend Face data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartExtendFaceInit(svxExtendData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Extend the specified face.

    @note
    Interface cvxPartExtendFaceInit() can initialize variables of this function.

    @param [in] data extend face data
    @param [out] newFtr index of new feature(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxPartExtendFace(svxExtendData *data, int *newFtr);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartTrimToFaces().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data data of trim to faces

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartTrimToFacesInit(svxTrimToFacesData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Trim away part of a face or shape where it intersects with Trimming.

    @note
    Interface cvxPartTrimToFacesInit() can initialize variables of this function.

    @param [in]  data trimtofaces_data definition
    @param [out] idTrim trim id (NULL to ignore )

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartTrimToFaces(const svxTrimToFacesData *data, int *idTrim);

    /**
    @ingroup zwapi_cmd_freeform

    Use this function to trim a face or shape to a curve or set of curves.

    @param [in] trimData trim to curves data
    @param [out] idTrim trim feature id (pass in NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartTrimToCrvs(const svxTrimToCurvesData *trimData, int *idTrim);

    /**
    @ingroup zwapi_cmd_freeform

    Use the function to orient the view direction of selected faces. 

    @param [in] count count of faces (0 to orient all faces)
    @param [in] idFaces list of face ids (NULL to orient all faces)
    @param [in] dir direction of faces (NULL to use the positive z-axis)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSetFaceDir(int count, int *idFaces, const svxVector *dir);

    /**
    @ingroup zwapi_cmd_freeform

    Reverses the direction of the natural normal of the input faces by swapping the U and V parameter
    directions of each face's surface.

    Each face's normal direction also reverses to keep it consistently
    oriented with respect to the surface normal and ensure a closed shape's inside and outside remain unchanged.

    This function also modifies each face's pre-edges to keep them properly located in the modified UV domain.
    This function ignores any face ID that is less than 1.

    @see cvxFaceReverseDir().

    @param [in] numFaces number of faces in input list
    @param [in] idFaces pointer to array of integer face id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxFaceReverse(int numFaces, int *idFaces);

    /**
    @ingroup zwapi_cmd_freeform

    Reverses the normal direction of each input face, without changing its surface or trim loops.
    If a face initially bounds a closed shape, this flips the inside and outside with respect to that shape.

    Each ID in the idFaces array may refer to a face or a shape.
    When an ID refers to a shape, this function reverses all of the shape's faces.

    @see cvxFaceReverse().

    @param [in] numFaces number of faces in input list
    @param [in] idFaces pointer to array of integer face id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_aPI_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxFaceReverseDir(int numFaces, int *idFaces);

    /**
    @ingroup zwapi_cmd_freeform

    Use the function to modify the number of iso-lines of the specified faces.

    @param [in] count number of faces
    @param [in] idFaces list of face ids
    @param [in] Uisoline number of iso-lines displayed in the U directions
    @param [in] Visoline number of iso-lines displayed in the V directions

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartModifyIsolineNum(int count, int *idFaces, int Uisoline, int Visoline);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartExplode().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data data of explode command

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartExplodeInit(svxExplodeData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Explode faces from the active topology table.

    @note
    Interface cvxPartExplodeInit() can initialize variables of this function.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] ExplodeData explode_data definition
    @param [out] numShape number of resulting shapes (NULL to ignore)
    @param [out] idShapes list of id's of resulting shapes (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_ONJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxPartExplode(const svxExplodeData *ExplodeData, int *numShape, int **idShapes);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartFacesetSew().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data faces sew data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartFacesetSewInit(svxSewData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Sew the specified shapes.

    @note
    Interface cvxPartFacesetSewInit() can initialize variables of this function.

    @see cvxPartSewForce()
    The difference between cvxPartFacesetSew and cvxPartSewForce is this function can 
    input the specified shapes and set the svxSewData by themselves.

    @param [in] count count of shapes
    @param [in] shapes id list of shapes
    @param [in] param parameter value (NULL to use default)
    @param [out] newFtr id of new feature(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartFacesetSew(int count, int *shapes, svxSewData *param, int *newFtr);

    /**
    @ingroup zwapi_cmd_freeform

    Matches and sews free edges in the active part using the input proximity
    tolerance.  If "Tol" is input as 0.0, the active part's default proximity
    tolerance is used. Unlike cvxPartSew(), this function attempts to "force"
    open edges to sew to adjacent edges that are "close" but not within
    tolerance.

    @see cvxPartFacesetSew()
    The difference between cvxPartSewForce and cvxPartFacesetSew is this function doesn't need to 
    input the shapes and set "force object to sew into solid" to 1.

    @param [in] Tol 3D proximity tolerance (mm) (0.0 for default)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSewForce(double Tol);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartEnlargeFace().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data enlarge face data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartEnlargeFaceInit(svxEnlargeFaceData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Use the function to remove all the loops from the selected face and enlarge the 
    new face by extending each edge.

    @note
    Interface cvxPartEnlargeFaceInit() can initialize variables of this function.

    @param [in] data enlarge face data
    @param [out] idFace id of new face (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartEnlargeFace(const svxEnlargeFaceData *data, int *idFace);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartExtendShape().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data extend shape data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartExtendShapeInit(svxExtendShapeData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Use the function to extend the face edges of an open shape or solid shape.

    @note
    Interface cvxPartExtendShapeInit() can initialize variables of this function.

    @param [in] data extend shape data
    @param [out] idFtr id of new feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartExtendShape(const svxExtendShapeData *data, int *idFtr);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartSplitWithCrv().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data split faces with curves data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSplitWithCrvInit(svxSplitWithCrvData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Use the function to split a face or shape at a curve or set of curves. If the curves
    intersect each other, the spurs are reflected in the resulting faces.  If you split 
    one face, a shape will be the result. Splitting one shape will result in the same 
    shape having additional faces.

    @note
    Interface cvxPartSplitWithCrvInit() can initialize variables of this function.

    @param [in] data split faces with curves data
    @param [out] idFtr id of new feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSplitWithCrv(const svxSplitWithCrvData *data, int *idFtr);

    /**
    @ingroup zwapi_cmd_freeform

    Initialize the parameters of the cvxPartCurveMesh().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data curve mesh data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCurveMeshInit(svxCurveMeshData *data);

    /**
    @ingroup zwapi_cmd_freeform

    Use the function to create a face by blending through a mesh of U and V curves.

    @note
    Interface cvxPartCurveMeshInit() can initialize variables of this function.

    @see cvxPartCurveMeshInit

    @param [in] data curve mesh data
    @param [out] idFace face id to be created (can be NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCurveMesh(const svxCurveMeshData *data, int *idFace);

    //====================================================================================================================
    /** @name Basic Editing */
    //====================================================================================================================
/**********************************************************************
*! -Pattern Geometry- : zwapi_cmd_shape.h
*  extern int cvxPartPatternGeom(int Count, int* idEnts, const svxPtnGeom* Pattern, int* idPattern);
**********************************************************************/

/**********************************************************************
*! -Pattern Feature- : zwapi_cmd_shape.h
*  extern int cvxPartPatternFtr(int Count, int* idFtrs, const svxPtnFtr* Pattern, int* idPattern);
**********************************************************************/

/**********************************************************************
*! -Mirror Geometry- : zwapi_cmd_shape.h
*  extern int cvxPartMirrorGeom(svxMirrorGeom* Mirror, int* NumNewEnts, int** idNewEnts);
**********************************************************************/

/**********************************************************************
*! -Mirror Feature- : zwapi_cmd_shape.h
*  extern int cvxPartMirrorFtr(svxMirrorFtr* Mirror, int* idFtr);
**********************************************************************/

/**********************************************************************
*! -Move-  : zwapi_cmd_shape.h
*  extern int cvxPartMove(const svxMoveData *Move, int *idMove);
**********************************************************************/

/**********************************************************************
*! -Copy-  : zwapi_cmd_shape.h
*  extern int cvxPartCopy(const svxCopyData *Copy, int *idCopy);
**********************************************************************/

/**********************************************************************
*! -Scale-  : zwapi_cmd_shape.h
*  extern int cvxPartScale(int Count, int* idEnts, double X, double Y, double Z, int idDatum);
*  extern int cvxPartScale2(int Count, int* idEnts, double X, double Y, double Z, int idDatum, svxPoint* CentPnt);
**********************************************************************/

    //====================================================================================================================
    /** @name Datum */
    //====================================================================================================================
/**********************************************************************
*! -Datum Axis- : zwapi_datum.h
*  extern int cvxPartAxisNew(svxAxisData *Axis, int *idAxis);
**********************************************************************/

/**********************************************************************
*! -Datum Plane- : zwapi_datum.h
*  extern int cvxPartDatum(svxMatrix* Frame, int* idDatum);
*  extern int cvxPartDatum2(svxMatrix* Frame, int iCode, int* idDatum);
*  extern int cvxPartNewDatum(svxMatrix* Frame, int* idDatum);
*  extern int cvxPartPlnCrv(int idCrv, svxPoint* Origin, svxPoint* Xaxis, int* idPln);
*  extern int cvxPartPlnCrv2(int idCrv, svxData* Origin, svxData* Xaxis, int Flip, int* idPln);
*  extern int cvxPartPlnSrf(int idFace, svxPoint* Origin, int* idPln);
*  extern int cvxPartPlnSrf2(int idFace, svxPoint* Origin, svxPoint* XZ, int Flip, int* idPln);
*  extern int cvxPartPlaneNew(svxPlaneData* Plane, int* idPlane);
*  extern int cvxPartPlaneAddInit(evxNewPlaneMethods method, svxNewPlaneData* data);
*  extern int cvxPartPlaneAdd(const svxNewPlaneData* plane, int* idPlane);
**********************************************************************/

/**********************************************************************
*! -Datum CSYS- : zwapi_datum.h
*  extern int cvxPartCSYSNewInit(evxCSYSMethods method, svxCSYSData* data);
*  extern int cvxPartCSYSNew(svxCSYSData* CSYS, int* idCSYS);
**********************************************************************/

/**********************************************************************
*! -LCS- : zwapi_datum.h
*  extern int cvxPartActiveAsLCS(int id);
**********************************************************************/

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef V_VXAPILOC_H
#include "api/inc/VxApiLoc.h"
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FREEFORM_FTR_H */
