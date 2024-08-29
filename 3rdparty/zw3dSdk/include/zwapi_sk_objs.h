/**
@file zwapi_sk_objs.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note */
/**
@defgroup zwapi_sk_objs Sketch Object API
@ingroup SketchObjectsModel
@brief
@details some query interfaces in the sketch.
*/

#pragma once
#ifndef ZW_API_SK_H /* this ifndef surrounds entire header */
#define ZW_API_SK_H

#include "zwapi_sk_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Query/Edit */
    //====================================================================================================================
    /**
    @ingroup zwapi_sk_objs

    Get the insertion plane of the specified sketch.

    @param [in] idSketch id of sketch in active file
    @param [out] plnPath pick path of the sketch insertion plane

    @retval succeeds
    -        ZW_API_NO_ERROR
    -        -1 - no error, but no entity was retrieved.
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUT_PUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern int cvxSkInqPlane(int idSketch, svxEntPath *plnPath);

    /**
    @ingroup zwapi_sk_objs

    The function of this interface is to obtain the plane on which   
    the sketch is attached.

    If the plane attached to the sketch does not exist, the split   
    sub face of the plane attached to the original sketch is obtained.

    The cvxSkInqPlane interface can obtain the surface attached to the sketch,   
    but once the attached surface is divided and the original surface does not   
    exist, the interface cannot be obtained.

    The cvxSkInqPlanes interface has all the function of the interfaced cvxSkInqPlane,   
    and when the cvxSkInqPlane cannot obtain the plane, the cvxSkInqPlanes interface   
    can obtain the sub split plane of the original plane.

    @param [in] idSketch  id of sketch
    @param [out] count    count of idFaces 
    @param [out] idFaces  list of idFace 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkInqPlanes(int idSketch, int *count, int **idFaces);

    /**
    @ingroup zwapi_sk_objs

    This function is to determine whether the sketch is cosmetic.

    @param [in] IdSketch d of sketch

    @retval succeeds
    -        1 - indicates it is cosmetic
    -        0 - indicates it is not cosmetic or error occurs;
    @warning
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxSkIsCosmetic(int IdSketch);

    /**
    @ingroup zwapi_sk_objs

    This function is to determine whether the sketch is external sketch.

    @param [in] IdSketch id of sketch

    @retval succeeds
    -        1 - indicating that it is external Sketch
    -        0 - indicating that it is not external Sketch or error occurs
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern int cvxSkIsExternal(int IdSketch);

    /**
    @ingroup zwapi_sk_objs

    Get information about the source sketch associated with the specified  
    external sketch, including file name, root name and sketch name.

    @param [in] idSketch id of external sketch
    @param [out] fileName file name of source sketch
    @param [out] rootName root name of source sketch (output an empty string
                          when file is a single object file)
    @param [out] skName name of sketch entity (output an empty string
                        when root object is a sketch)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxSkInqExternalSk(int idSketch, vxPath fileName, vxRootName rootName, vxLongName skName);

    /**
    @ingroup zwapi_sk_objs

    Get information about the source sketch associated with the specified
    external sketch, including file name, root name and sketch name.

    A fileName that is too long (longer than "sizefile") is truncated.

    It is assumed that the input "fileName" is no longer than 512 bytes.

    @param [in] idSketch id of external sketch
    @param [out] fileName file name of source sketch
    @param [in] sizefile max size of fileName
    @param [out] rootName root name of source sketch (output an empty string
                          when file is a single object file)
    @param [out] skName name of sketch entity (output an empty string
                        when root object is a sketch)


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxSkInqExternalSkByLongPath(int idSketch, char *fileName, int sizefile, vxRootName rootName, vxLongName skName);

    /**
    @ingroup zwapi_sk_objs

    Calculates the area properties of closed profile(2D).  
    If the third argument (innerPnt) is V_NULL, aboutRf will be calculated  
    about (0,0).

    @param [in] nCrv number of curve list
    @param [in] idCrvs list of boundary curves
    @param [in] innerPnt reference point (the inner point)
    @param [out] aboutCM Area properties about centroid
    @param [out] aboutRf Area properties about ref

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    @retval other
    -        2 - curve list is not closed
    */
    extern int cvxSkInqArea(int nCrv, int *idCrvs, svxPoint2 *innerPnt, svxPrfAreaProp *aboutCM, svxPrfAreaProp *aboutRf);

    /**
    @ingroup zwapi_sk_objs

    Inquire the overlap geometries in active sketch.

    The calling procedure MUST deallocate the output list.

    @param [out] count number of groups of overlapping geometries
    @param [out] overlapGeoms list of overlapping geometries

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxSkInqOverlap(int *count, svxSkOverlapGeom **overlapGeoms);

    /**
    @ingroup zwapi_sk_objs

    Activates the specified sketch for query or editing.

    Call this function with "idSketch = 0" to exit the
    sketch back to its parent object.

    @param [in] idSketch id of sketch in active file (0 to exit active sketch)
    @param [in] UpdateGUI 1 to update GUI; 0 to leave GUI unchanged

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_INPUT_ERROR
    */
    extern evxErrors cvxSkActivate(int idSketch, int UpdateGUI);


    //====================================================================================================================
    /** @name Sketch Geometry Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_sk_objs

    Get index of the default x and y axis of the specified sketch.  
    if the specified default axis is not found, the value is assigned  
    to -1, such as *xAxis = -1.

    @param [in] idSketch index of sketch (-1 to inquire active sketch)
    @param [out] xAxis index of X axis
    @param [out] yAxis index of Y axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxSkInqAxis(int idSketch, int *xAxis, int *yAxis);

    /**
    @ingroup zwapi_sk_objs

    Output the axis list of current sketch.  
    The calling procedure MUST deallocate the output list.

    @param [out] Count number of Axis
    @param [out] idEnts list of Axis entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxSkInqAllAxis(int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Output the axis list of specified sketch.  
    The calling procedure MUST deallocate the output list.

    @param [in] idSketch id of sketch
    @param [out] count number of Axis
    @param [out]  idEnts list of Axis entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxSkInqAllAxisById(int idSketch, int *count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Get the direction associated with the specified object (idAxis).

    @param [in] idAxis index of 2d axis
    @param [out] pPnt start point of axis
    @param [out] pDir direction of axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkInqAxisDir(int idAxis, svxPoint2 *pPnt, svxPoint2 *pDir);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of geometry entities in the active sketch.

    The calling procedure MUST deallocate the output list.

    @param [out] Count number of geometry entities
    @param [out] idEnts list of geometry entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqGeom(int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of geometry entities in specified sketch.

    The calling procedure MUST deallocate the output list.

    @param [in] idSketch id of sketch
    @param [out] count number of geometry entities
    @param [out]  idEnts list of geometry entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqGeomById(int idSketch, int *count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of construction geometry entities in the active sketch.

    The calling procedure MUST deallocate the output list.

    @param [out] Count number of construction geometry entities
    @param [out] idEnts list of construction geometry entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqGeomX(int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of construction geometry entities in specified sketch.

    The calling procedure MUST deallocate the output list.

    @param [in] idSketch id of sketch
    @param [out] count number of construction geometry entities
    @param [out]  idEnts list of construction geometry entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqGeomXById(int idSketch, int *count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of point entities in the active sketch.

    The calling procedure MUST deallocate the output list.

    @param [out] Count number of point entities
    @param [out] idEnts list of point entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqPnt(int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of point entities in specified sketch.

    The calling procedure MUST deallocate the output list.

    @param [in] idSketch id of sketch
    @param [out] count number of point entities
    @param [out] idEnts list of point entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqPntById(int idSketch, int *count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of external reference entities in the active sketch.

    The calling procedure MUST deallocate the output list.

    @param [out] Count number of external reference entities
    @param [out] idEnts list of external reference entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqRef(int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of external reference entities in specified sketch.

    The calling procedure MUST deallocate the output list.

    @param [in] idSketch id of sketch
    @param [out] count number of external reference entities
    @param [out]  idEnts list of external reference entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqRefById(int idSketch, int *count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of text entities in the active sketch.

    The calling procedure MUST deallocate the output list.

    @param [out] Count number of text entities
    @param [out] idEnts list of text entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqText(int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of text entities in specified sketch.

    The calling procedure MUST deallocate the output list.

    @param [in] idSketch id of sketch
    @param [out] count number of text entities
    @param [out]  idEnts list of text entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqTextById(int idSketch, int *count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of constraint entities in the active sketch.

    The calling procedure MUST deallocate the output list.

    @param [out] Count number of constraints
    @param [out] idEnts list of constraint entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqCns(int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of constraint entities in specified sketch.

    The calling procedure MUST deallocate the output list.

    @param [in] idSketch id of sketch
    @param [out] count number of constraints
    @param [out]  idEnts list of constraint entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqCnsById(int idSketch, int *count, int **idEnts);


    //====================================================================================================================
    /** @name Sketch Curve Type */
    //====================================================================================================================
    /**
    @ingroup zwapi_sk_objs

    Output the count of unmatched and over-matched points of specified list.

    @param [in] iCount count of input curves
    @param [in] idCrvs id list of curves
    @param [out] iUnMatch count of unmatched points
    @param [out] iOverMatch count of over-matched points

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkInqCrvConnect(int iCount, int *idCrvs, int *iUnMatch, int *iOverMatch);

    /**
    @ingroup zwapi_sk_objs

    Outputs the construct type of specified entity.  
    1-the entity is construct line, 0-no.

    @param [in] entId id of entity
    @param [out] type wire type of specified entity, 1-construct, 0-no

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkEntWireType(int entId, int *type);

    /**
    @ingroup zwapi_sk_objs

    Change geometry wire type, from 2D geometry(lines, arcs, circles, curves, axis) to construction  
    geometry, or change construction geometry to 2D geometry.

    @param [in] nEnt number of entity
    @param [in] idEnt list of id's of entity
    @param [in] type wire type (1-construct line, 0-solid line)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkSetWireType(int nEnt, int *idEnt, int type);


    //====================================================================================================================
    /** @name Sketch Ready Text */
    //====================================================================================================================
    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of ready sketch text entities in the active sketch.

    The calling procedure MUST deallocate the output list.

    @param [in] idSketch index of sketch (-1 to inquire active sketch)
    @param [out] Count number of ready sketch text entities
    @param [out] idEnts list of ready sketch text entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqReadyText(int idSketch, int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of curve the specified ready sketch text.

    The calling procedure MUST deallocate the output list.

    @param [in] idRdText index of the ready sketch text
    @param [out] Count number of curves in the ready sketch text
    @param [out] idCrvs list of curve id's in the ready sketch text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxSkReadyTextInqCrvs(int idRdText, int *Count, int **idCrvs);

    /**
    @ingroup zwapi_sk_objs

    Get string of the specified ready sketch text.

    This function allocates memory for the text string. The memory MUST  
    be deallocated by the calling procedure using cvxReadyTextFree().

    @param [in] idRdText index of the ready sketch text
    @param [out] RdText data of ready sketch text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxSkReadyTextInqText(int idRdText, svxReadyText *RdText);

    /**
    @ingroup zwapi_sk_objs

    Set string of the specified ready sketch text.

    @param [in] idRdText index of the ready sketch text
    @param [in] RdText data of ready sketch text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_APPI_OUT_OF_RANGE
    */
    extern evxErrors cvxSkReadyTextModText(int idRdText, svxReadyText *RdText);

    /**
    @ingroup zwapi_sk_objs

    Frees memory associated with the specified ready sketch text structure.

    @param [in] RdText ready sketch text structure

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxReadyTextFree(svxReadyText *RdText);


    //====================================================================================================================
    /** @name Sketch Block */
    //====================================================================================================================
    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of sketch block reference entities  
    in the specified sketch or sketch block.

    The calling procedure MUST deallocate the output list.

    @param [in] idSketch id of sketch or sketch block in active file (<1 for active one)
    @param [out] Count number of sketch block reference entities
    @param [out] idEnts list of sketch block reference entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkInqBlockReferences(int idSketch, int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of the names of all sketch block objects in the active file.  
    Also outputs a list of indices of them if needed.

    The list referenced by "**Names" or "**idEnts" is allocated by this function and  
    MUST be deallocated by the calling procedure.

    @param [out] Count no. of sketch blocks in active file
    @param [out] idEnts list of sketch block object id's (NULL to ignore)
    @param [out] Names list of sketch block object names (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxSkInqSketchBlocks(int *Count, int **idEnts, vxRootName **Names);

    /**
    @ingroup zwapi_sk_objs

    Activates the specified 2d sketch block for query or editing.

    In addition, idBlock can also be the index of a sketch block reference.  
    In this case the definition sketch block will be activated at the position  
    of the block reference.

    Call this function with "idBlock = 0" to exit the sketch block  
    back to its parent object or previous target object.

    @param [in] idBlock id of 2d sketch block in active file (0 to exit active sketch block)
    @param [in] UpdateGUI 1 to update GUI; 0 to leave GUI unchanged

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxSkBlockActivate(int idBlock, int UpdateGUI);

    /**
    @ingroup zwapi_sk_objs

    Output the index of the inner sketch of the sketch block, which is invisible in the feature list.

    It can be used to generate the pick path of the entity in the block which is formated as  
    (-1, idBlockReference, idBlock, idSketch, idEntity).

    @param [in] idBlock id of 2d sketch block
    @param [out] idSketch id of the inner sketch of the sketch block

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkBlockGetSketch(int idBlock, int *idSketch);

    /**
    @ingroup zwapi_sk_objs

    Output the index of the definition sketch block of the specified block reference.

    @param [in] idRef id of sketch block reference
    @param [out] idBlock id of the definition sketch block

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkBlockRefGetDefinition(int idRef, int *idBlock);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of geometry entities that belong to the specified block.

    The calling procedure MUST deallocate the output list.

    @param [in] blockName block name
    @param [out] Count number of geometry entities
    @param [out] idEnts list of geometry entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkBlockInqGeom(const vxRootName blockName, int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of point entities that belong to the specified block.

    The calling procedure MUST deallocate the output list.

    @param [in] blockName block name
    @param [out] Count number of point entities
    @param [out] idEnts list of point entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkBlockInqPnt(const vxRootName blockName, int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of dimension entities that belong to the specified block.

    The calling procedure MUST deallocate the output list.

    @param [in] blockName block name
    @param [out] Count number of dimension entities
    @param [out] idEnts list of dimension entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DTA_GET_ERROR
    */
    extern evxErrors cvxSkBlockInqDim(const vxRootName blockName, int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of indices of construction geometry entities that belong to the specified block.

    The calling procedure MUST deallocate the output list.

    @param [in] blockName block name
    @param [out] Count number of geometry entities
    @param [out] idEnts list of geometry entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxSkBlockInqGeomX(const vxRootName blockName, int *Count, int **idEnts);

    /**
    @ingroup zwapi_sk_objs

    Outputs a list of sketch block reference entity id's that belong to the specified block.

    The calling procedure MUST deallocate the output list.

    @param [in] idBlock id of 2d sketch block
    @param [out] count number of sketch block reference entities
    @param [out] idEnts list of sketch block reference entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxSkBlockInqRefs(int idBlock, int *count, int **idEnts);


    //====================================================================================================================
    /** @name Sketch Constraint */
    //====================================================================================================================
    /**
    @ingroup zwapi_sk_objs

    Get the type(evxGeomConsType) of specified geometry constraint.
    It can't get the corresponding type if "*type = VX_SK_CONS_UNKNOWN".

    @param [in] idCons index of geometry constraint
    @param [out] type type of geometry constraint
    @param [out] subType coordinate constraint type, only fix constraint and  
                        point to midpoint constraint is valid:  
                        0: both the X and Y coordinates are constrained  
                        1: only the X coordinate is constrained  
                        2: only the Y coordinate is constrained  
                        3: point to arc midpoint constraint, used only VX_SK_CONS_MID

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxSkInqCnsType(int idCons, evxGeomConsType *type, int *subType);

    /**
    @ingroup zwapi_sk_objs

    Outputs the geom data array of entities associated with the specified  
    geometry constraint.

    The calling procedure MUST deallocate the output list.

    @param [in] idCons index of geometry constraint
    @param [out] Count number of geometry entities
    @param [out] geoms data of geometry entities

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxSkInqCnsGeoms(int idCons, int *Count, svxConsGeom **geoms);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SK_H */
