/**
@file zwapi_brep_face.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Face API
*/
/**
@defgroup zwapi_brep_face Face API
@ingroup BrepEntityModel
@brief
@details THE MODULE FOR THE ZW3D Face API
*/

#pragma once
#ifndef ZW_API_FACE_H /* this ifndef surrounds entire header */
#define ZW_API_FACE_H

#include "zwapi_brep_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Face Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_brep_face

    Outputs display attributes of the specified face or shape. Attributes for a shape
    are grabbed from the first face in the shape.

    It is assumed the specified face or shape (idFace) resides in the active part.

    @param [in] idFace face or shape id
    @param [out] At face/shape display attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqFaceAt(int idFace, svxFaceAt *At);

    /**
    @ingroup zwapi_brep_face

    Outputs shader attributes of the specified face.
    "Sh->name[0]" is set to "0" (i.e. empty string)
    if no shader is defined for the face.

    @code
    //Checkerboard Shader:
       Sh->name = "Checker"
       Sh->color[0] = first checkerboard square color
       Sh->color[1] = second checkerboard square color
       Sh->param[0] = scale factor for checkerboard squares

    //Chrome Shader:
       Sh->name = "Chrome"
       Sh->image = optional image file reflected on chrome finish
       Sh->param[0] = reflectance (0.0 - 1.0)

    //Granite Shader:
       Sh->name = "Granite"
       Sh->param[0] = scale factor (0.0 - 2.0)
       Sh->param[1] = noise (0.0 - 10.0)

    //Marble Shader:
       Sh->name = "Marble"
       Sh->color[0] = marble base color
       Sh->color[1] = marble vein color
       Sh->param[0] = scale factor (0.0 - 200.0)

    //Wood Shader:
       Sh->name = "Wood"
       Sh->color[0] = light wood color
       Sh->color[1] = dark wood color
       Sh->param[0] = frequency of wood rings (0.0 - 10.0)
       Sh->param[1] = overall noisiness of wood grain (0.0 - 6.0)
       Sh->param[2] = noise in X direction (0.0 - 1.0)
       Sh->param[3] = noise in Y direction (0.0 - 1.0)
       Sh->param[4] = noise in Z direction (0.0 - 1.0)
       Sh->param[5] = scale factor (0.0 - 4.0)
    @endcode

    It is assumed the specified face (idFace) resides in the active part.

    @param [in] idFace face id
    @param [out] Sh face shader attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartInqFaceSh(int idFace, svxShaderAt *Sh);

    /**
    @ingroup zwapi_brep_face

    Outputs texture attributes of the specified face.

    If a texture image file is embedded in a Z3 file, it is automatically
    extracted to a "temp" sub-folder in the Z3 runtime folder.  The path
    the temp file is output via "Tx->file".

    It is assumed the specified face (idFace) resides in the active part.

    @see cvxPartInqFaceTxFile().

    @param [in] idFace face id
    @param [out] Tx face texture attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartInqFaceTx(int idFace, svxTextureAt *Tx);

    /**
    @ingroup zwapi_brep_face

    Get the face area of the face which id is "faceId" in the db.

    @param [in] faceId The face id in the db
    @param [in] tolerance The tolerance
    @param [out] area The area of the face to return

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxFaceGetArea(const int faceId, const double tolerance, double *area);

    /**
    @ingroup zwapi_brep_face

    Evaluate curvature information on a surface at a specified uv
    location in the maximum curvature direction.

    @param [in] faceId face Id in the db
    @param [in] uvPoint U,V coordinate to evaluate
    @param [out] point 3D point on surface at the uv location (NULL to ignore)
    @param [out] normal Surface normal at UV location (NULL to ignore)
    @param [out] direction Surface direction(NULL to ignore)
    @param [out] minCurvature minimum curvature at the uv location (NULL to ignore)
    @param [out] maxCurvature maximum curvature at the uv location (NULL to ignore)
    @param [out] curvature curvature (NULL to ignore)
    @param [out] curvatureDirection curvature direction vector (NULL to ignore)
    @param [out] curvatureCenter curvature center (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxFaceGetMaxCurvature(const int faceId, const svxPoint2 uvPoint,
                                            svxPoint *point, svxPoint *normal, svxPoint *direction, double *minCurvature,
                                            double *maxCurvature, double *curvature, svxPoint *curvatureDirection, svxPoint *curvatureCenter);

    /**
    @ingroup zwapi_brep_face

    Initialize the parameters of the cvxPartSetFaceAt().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data face display attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartSetFaceAtInit(svxFaceAt *data);

    /**
    @ingroup zwapi_brep_face

    Changes display attributes of the specified faces or shapes.
    It is assumed the specified faces or shapes reside in the active part.

    @note
    Interface cvxPartSetFaceAtInit() can initialize variables of this function.

    @param [in] Count number of faces (or shapes)
    @param [in] idFaces list of face or shape id's
    @param [in] At face display attributes

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
    extern evxErrors cvxPartSetFaceAt(int Count, int *idFaces, const svxFaceAt *At);

    /**
    @ingroup zwapi_brep_face

    Set texture attributes of the specified face.

    It is assumed the specified face (idFace) resides in the active part.
    The 'opt' field of svxTextureAt structure is not supported now.

    @param [in] idFace face id
    @param [in] Tx face texture attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartSetFaceTx(int idFace, const svxTextureAt *Tx);

    /**
    @ingroup zwapi_brep_face

    Remove a texture or a texture map previously assigned to the specified
    shape or the specified face. it is assumed the specified face or shape
    (idFace) resides in the active part.

    @param [in] Count number of faces (or shapes)
    @param [in] idFaces list of face or shape id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartDelFaceTx(int Count, const int *idFaces);

    //====================================================================================================================
    /** @name Face Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_brep_face

    Outputs path to the original image file if a texture map has been
    applied to a face.  Unlike cvxPartInqFaceTx(), which may output the
    path to a copy of the original image file that ZW3D has put in its
    temp directory, this function outputs the path that was originally
    used to create the texture map.  The file might no longer exist,
    although the image may still exist as an embedded object.

    It is assumed the specified face (idFace) resides in the active part.

    ZW3D's native texture map command (!CdTMap) does not save the path to
    the original image file when a texture map is applied to a face with
    the embed option selected.  For faces that have been assigned a
    texture map using the texture map command rather than the
    cvxPartSetFaceTx() function, this function outputs the path that the
    texture map command saves with the face, which will be the path to a
    copy of the image file in ZW3D's temp directory.

    @see cvxPartInqFaceTx() for a function that outputs all texture map
    attributes.

    @param [in] idFace face id
    @param [out] Path path to texture map's original image file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqFaceTxFile(int idFace, vxPath Path);

    /**
    @ingroup zwapi_brep_face

    Outputs path to the original image file if a texture map has been  
    applied to a face.  Unlike cvxPartInqFaceTx(), which may output the  
    path to a copy of the original image file that ZW3D has put in its  
    temp directory, this function outputs the path that was originally  
    used to create the texture map.  The file might no longer exist,  
    although the image may still exist as an embedded object.  

    It is assumed the specified face (idFace) resides in the active part.

    ZW3D's native texture map command (!CdTMap) does not save the path to  
    the original image file when a texture map is applied to a face with  
    the embed option selected.  For faces that have been assigned a  
    texture map using the texture map command rather than the  
    cvxPartSetFaceTx() function, this function outputs the path that the  
    texture map command saves with the face, which will be the path to a  
    copy of the image file in ZW3D's temp directory.

    A Path that is too long (longer than "sizePath") is truncated.

    It is assumed that the input "Path" is no longer than 512 bytes.

    @see cvxPartInqFaceTx() for a function that outputs all texture map
    attributes.
    @see cvxPartInqFaceTxFile()

    @param [in] idFace face id
    @param [out] Path path to texture map's original image file
    @param [in] sizePath max size of Path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqFaceTxFileByLongPath(int idFace, char *Path, int sizePath);

    /**
    @ingroup zwapi_brep_face

    Gets the bounding box of the specified face in the active file.

    @see cvxPartInqEntBox,cvxPartInqShapeBox,cvxEntBndBox. The three interfaces have
    similar functions.

    @param [in] idFace face id
    @param [out] Box face bounding box

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqFaceBox(int idFace, svxBndBox *Box);

    /**
    @ingroup zwapi_brep_face

    Outputs a list of the trim curves that bound a face in the active part.
    The calling application must sort these curves into inner and outer loops
    as desired.  To get the them in sorted order, you must traverse the face
    and its loops using cvxPartInqFaceLoops(), cvxPartInqLoopEdges() and
    cvxPartInqEdgeCrv().

    The calling procedure MUST deallocate the internal data in each
    element of the output list by calling cvxCurveFree(), after which the
    output list MUST be deallocated using cvxMemFree((void**)TrimCurves).

    @param [in] idFace face id
    @param [out] Count number of trim curves
    @param [out] TrimCurves list of trim curves

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqFaceCrvs(int idFace, int *Count, svxCurve **TrimCurves);

    /**
    @ingroup zwapi_brep_face

    Outputs a list of indices of the edges that bound a face
    in the active file.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idFace face id
    @param [out] Count number of edges
    @param [out] Edges list of edge id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqFaceEdges(int idFace, int *Count, int **Edges);

    /**
    @ingroup zwapi_brep_face

    Outputs a list of indices of the loops (outer and inner) that belong
    to a face in the active file.

    Outer loops proceed counterclockwise relative to the natural normal
    of the parent surface.  Inner loops are clockwise.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idFace face id
    @param [in] Inner 1 to include inner loops; 0 for just the outer loops
    @param [out] Count number of loops
    @param [out] Loops list of loop id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqFaceLoops(int idFace, int Inner, int *Count, int **Loops);

    /**
    @ingroup zwapi_brep_face

    Outputs the untrimmed NURBS surface geometry of the specified face.
    The calling procedure is responsible for deallocating the memory
    assigned by this function to the "Srf" structure using cvxSurfaceFree().

    It is assumed the specified face (idFace) resides in the active part.

    @param [in] idFace face id
    @param [out] Srf face's untrimmed NURBS surface geometry

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqFaceSrf(int idFace, svxSurface *Srf);

    /**
    @ingroup zwapi_brep_face

    Frees memory associated with the specified surface structure.

    @param [in] Srf NURB surface structure

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxSurfaceFree(svxSurface *Srf);

    /**
    @ingroup zwapi_brep_face

    Gets surface geometry for the specified face entity. It is assumed the specified
    face (idFace) resides in the active part.

    The calling procedure is responsible for deallocating the memory assigned by this
    function to the "SrfPrim" structure using cvxSurfaceFree(&SrfPrim->srfData.srf) when
    SrfPrim->srfType = VX_SF_PRIM_NURB.

    @param [in] idFace face id
    @param [out] SrfPrim face's untrimmed NURBS surface geometry

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MODELIG_DATA_ERROR
    */
    extern evxErrors cvxPartInqFaceSrfPrim(int idFace, svxSrfPrim *SrfPrim);

    /**
    @ingroup zwapi_brep_face

    Frees memory associated with the specified svxSrfPrim structure.

    @param [in] SrfPrim surface structure

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxSrfPrimFree(svxSrfPrim *SrfPrim);

    /**
    @ingroup zwapi_brep_face

    Gets the id of the specified face's parent shape (within the active file).

    @param [in] idFace face id
    @param [out] idShape id face's parent shape

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqFaceShape(int idFace, int *idShape);

    /**
    @ingroup zwapi_brep_face

    Outputs the face's geometry index.

    @param [in] idFace face id
    @param [out] idGeom geometry index of the face

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqFaceGeom(int idFace, int *idGeom);

    /**
    @ingroup zwapi_brep_face

    Get the flag indicating if the specified face is a fillet face.

    @param [in] idFace face id
    @param [out] isFilletFace fillet flag (1 is fillet face, else is 0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqFaceFillet(int idFace, int *isFilletFace);

    /**
    @ingroup zwapi_brep_face

    Get the radius of specified face, only revolved surfaces
    (cylinder and sphere) are valid.

    @param [in] idFace face entity id
    @param [out] Radius radius

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxFaceRadius(int idFace, double *Radius);

    /**
    @ingroup zwapi_brep_face

    Get bend information of specified face.

    @param [in] idFace index of face
    @param [out] bendFlag whether the face is a bending surface (1 to yes; 0 to no)
    @param [out] bendRad bend radius (NULL to ignore)
    @param [out] neutralRad neutral radius (NULL to ignore)
    @param [out] angle bend angle (NULL to ignore)
    @param [out] thick thickness (NULL to ignore)
    @param [out] kFactor K-factor (NULL to ignore)
    @param [out] flatTol flat tolerance (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxFaceInqBend(int idFace, int *bendFlag, double *bendRad, double *neutralRad,
                                    double *angle, double *thick, double *kFactor, double *flatTol);

    /**
    @ingroup zwapi_brep_face

    Check if the specified face is a concave or convex face. the function
    is only applicable to a small subset of surfaces are universally convex
    or concave, such as surfaces approximating cylinders and cones and spheres.

    @param [in] idFace index of face

    @retval return
    -       0: the specified face is a convex face
    -       1: the specified face is a concave face
    -       -1: the id is not a face or function fails
    -       ZW_API_INVALID_INPUT
    -       ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern int cvxFaceIsConcave(int idFace);

    /**
    @ingroup zwapi_brep_face

    Check if the specified face is real planar face.

    @note
    The face of the VX_SRF_GEN type may also be a planar face.

    @param [in] idFace index of face

    @retval return
    -       0: the specified face is not planar or error occurs
    -       1: the specified face is planar
    @warning
    -       ZW_API_INVALID_INPUT
    -       ZW_API_INPUT_TYPE_ERROR
    */
    extern int cvxFaceIsPlanar(int idFace);

    /**
    @ingroup zwapi_brep_face

    Gets the extreme point of face in the specified direction, if the farthest
    end of the specified direction are face or edges, the function also outputs
    the list of face or edges, in this case, the extreme point output is only any
    point on a face or edge.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idFace id of face in active part
    @param [in] Dir direction
    @param [out] Count number of face or edges (NULL to ignore)
    @param [out]  idEnts list of face or edges (NULL to ignore)
    @param [out] Point extreme point (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxFaceInqExtreme(int idFace, const svxVector *Dir, int *Count, int **idEnts, svxPoint *Point);

    //====================================================================================================================
    /** @name Face Eval */
    //====================================================================================================================
    /**
    @ingroup zwapi_brep_face

    Evaluates the NURBS representation of the face entity
    specified by "idFace".  Outputs the 3D point coordinates (Point)
    and normal direction (Normal) at the specified U,V location
    on the surface.  Use cvxFaceParam() to get the face's parameter
    limits.

    @note
    The direction of "Normal" is set to reflect the outward
    normal of the face, where "outward" means the direction that points
    towards the outside of the shape that the face is associated with.
    This may be opposite the natural normal of the NURBS surface associated
    with the face.   
    If you want the natural normal of the NURBS surface associated with
    the face, call cvxPartInqFaceSrf() to get the "Srf", and if Srf->OutNormal=
    0, call cvxVecReverse() to reverse the "Normal".

    @param [in] idFace face entity id
    @param [in] U U parameter value on face
    @param [in] V V parameter value on face
    @param [out] Point point on face (input NULL to ignore)
    @param [out] Normal normal at point on face (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxFaceEval(int idFace, double U, double V, svxPoint *Point, svxVector *Normal);

    /**
    @ingroup zwapi_brep_face

    Evaluates the NURBS representation of the face entity
    specified by "idFace".  Outputs the 3D point coordinates (Point),
    normal direction (Normal) and UV tangent directions at the
    specified U,V location on the surface.   Use cvxFaceParam() to
    get the face's parameter limits.

    @note
    The direction of "Normal" is set to reflect the outward
    normal of the face, where "outward" means the direction that points
    towards the outside of the shape that the face is associated with.
    This may be opposite the natural normal of the NURBS surface associated
    with the face.  
    If you want the natural normal of the NURBS surface associated with
    the face, call cvxPartInqFaceSrf() to get the "Srf", and if Srf->OutNormal=
    0, call cvxVecReverse() to reverse the "Normal".

    @param [in] idFace face entity id
    @param [in] U U parameter value on face
    @param [in] V V parameter value on face
    @param [out] Point point on face (input NULL to ignore)
    @param [out] Normal normal at point on face (input NULL to ignore)
    @param [out] Utan U tangent direction (input NULL to ignore)
    @param [out] Vtan V tangent direction (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxFaceEval2(int idFace, double U, double V, svxPoint *Point, svxVector *Normal, svxVector *Utan, svxVector *Vtan);

    /**
    @ingroup zwapi_brep_face

    Outputs the minimum and maximum parameter values of the
    NURBS representation of the specified face entity.

    @param [in] idFace face entity id
    @param [out] U min/max U values
    @param [out] V min/max V values

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxFaceParam(int idFace, svxLimit *U, svxLimit *V);

    /**
    @ingroup zwapi_brep_face

    Determines the location of the specified point on the specified face
    relative to the face's trim boundaries.

    @param [in] idFace face entity id
    @param [in] U U parameter value on face
    @param [in] V V parameter value on face
    @param [out] Loc point location relative to face boundaries

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxFacePntLoc(int idFace, double U, double V, evxPntLocation *Loc);

    /**
    @ingroup zwapi_brep_face

    Outputs the UV coordinates of the projection of the input XYX
    point onto the NURBS representation of the specified face.
    It is assumed that "Point" lies on or very close to the face.

    @param [in] idFace face entity id
    @param [in] Point XYZ point on/near face
    @param [out] U U coordinate of point-on-face
    @param [out] V V coordinate of point-on-face

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxFacePntProj(int idFace, svxPoint *Point, double *U, double *V);

    /**
    @ingroup zwapi_brep_face

    Get radial integrity ratio value of specified surface. the ratio value
    is set to 0.0 when it is invalid, and then function is only applicable to
    cylinder, cone and torus.

    @param [in] idFace face entity id
    @param [out] URatio radial integrity ratio value in U
    @param [out] VRatio radial integrity ratio value in V

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxFaceRadialIntegrity(int idFace, double *URatio, double *VRatio);

    /**
    @ingroup zwapi_brep_face

    Evaluates the NURBS representation of the face entity specified by "idFace".
    Use cvxFaceParam() to get the face's parameter limits.

    "Level" specifies the level of evaluation. The higher the level, more
    data gets returned (at the expense of greater computation).
    @verbatim
                          level
         |  0  |     1     |     2      |      3      |       4
         +-----+-----------+------------+-------------+-------------
         | pnt |  normal   | partial_uu | partial_uuu   partial_uuuu
                 partial_u   partial_uv   partial_vuu   partial_vuuu
                 partial_v   partial_vv   partial_uvv   partial_uuvv
                                          partial_vvv   partial_uvvv
                                                        partial_vvvv
    @endverbatim

    @note
    The direction of normal is set to reflect the outward
    normal of the face, where "outward" means the direction that points
    towards the outside of the shape that the face is associated with.
    This may be opposite the natural normal of the NURBS surface associated
    with the face.

    @param [in] idFace face entity id
    @param [in] U U parameter value on face
    @param [in] V V parameter value on face
    @param [in] Level level of evaluation(0 ~ 4). See description below
    @param [out] EvalSrf Result

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxFaceEvalGeom(int idFace, double U, double V, int Level, svxEvalSurf *EvalSrf);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FACE_H */
