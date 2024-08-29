/**
@file zwapi_cmd_paramdefine_param.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Command Parameter API
*/
/**
@defgroup zwapi_cmd_paramdefine_param Template Field API
@ingroup TemplateCommand
@brief
@details THE MODULE FOR THE ZW3D Command Parameter API
*/

#pragma once
#ifndef ZW_API_PARAM_H /* this ifndef surrounds entire header */
#define ZW_API_PARAM_H

#include "zwapi_cmd_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Command Initialization */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_paramdefine_param

    Creates and initializes a data container for the specified command.
    The calling procedure is responsible for deleting the container and
    its contents using cvxDataFree().

    @param [in] Template command template name
    @param [out] idData id of data container

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDataInit(const vxName Template, int *idData);

    //====================================================================================================================
    /** @name Data Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_paramdefine_param

    Set all bytes of the input "Data" structure to zero.

    @param [in,out] Data pointer to data structure

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxDataZero(svxData *Data);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Assigns the specified item of data to the specified field of the
    specified data container.  If "idField" is defined as a list in
    the command template used to initialize "idData", the new item
    of data is appended to items already associated with the field.
    If the field is not defined as a list, any existing item is
    replaced.

    @note
    For set list widget, it could be set idEntity to input
    the command VDATA that could be created by cvxDataInit().

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] Data data item

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDataSet(int idData, int idField, svxData *Data);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    If the corresponding color widget's type is index color, find the color index by input "Color" rgb value.  
    If the rgb value is not one of index color, it will return 1, otherwise set the index into specified VDATA field.  
    If type is true color, encodes the input RGB color values as an integer stored in VDATA field.  
    Use cvxDataGetColor() to retrieve RGB color from the field.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] Color rgb color

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxDataSetColor(int idData, int idField, svxColor *Color);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Append the specified entity to the specified field of the specified
    data container.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] Ent entity pick path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxDataSetPath(int idData, int idField, svxEntPath *Ent);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    If "Promote" is input as a non-zero value, the point-on-entity pick
    stored in the specified input field is flagged to tell ZW3D to
    promote the pick to the parent of the entity instead of the entity
    itself. 

    If "Promote" is input as zero, the point-on-entity pick
    is flagged to tell ZW3D not to promote the pick to its parent.

    A common case is the promotion of a curve pick to its parent sketch
    or curve list.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] Promote 1 to promote entity pick to parent, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxDataSetPromote(int idData, int idField, int Promote);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Logs a "point on curve" pick to the specified field of the specified
    data container.  Projects the specified point (Pnt) onto the specified
    curve. The point should lie on or near the curve.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] idCrv id of curve in active root object
    @param [in] Pnt point on or near the curve or key point of curve
                    (NULL to use the start point of the curve )

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
    extern evxErrors cvxDataSetPntOnCrv(int idData, int idField, int idCrv, svxPoint *Pnt);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Logs a "point on face" pick to the specified field of the specified
    data container.  Uses a point on the specified face at the midpoint
    of the face's bounding box in UV parameter space.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] idComp id of component in active part (0 to ignore)
    @param [in] idFace id of face in active part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDataSetPntOnFace(int idData, int idField, int idComp, int idFace);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Logs a "point on face" pick to the specified field of the specified
    data container.  Projects the specified point (Pnt) onto the face.
    The point should lie on or very near to the face in a location that
    can be projected onto the face along a face normal.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] idFace id of face in active part
    @param [in] Pnt point on or near the face

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDataSetPntOnFace2(int idData, int idField, int idFace, svxPoint *Pnt);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Add the specified point (pnt) as the Nth element (N = idField)
    of the specified data object (VDATA). 

    If the Nth element is already defined (and it is a list), the point is appended to a
    list of points referenced by the Nth element.

    If the NTh element is defined (and it is not a list), the point is overwritten.

    @note
    The id of path must start with -2 if you use "CdCnsCoin" command
    for a secondary development.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] entPath the entity pick path
    @param [in] pnt point on the entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxDataSetPntByPath(int idData, int idField, svxEntPath *entPath, svxPoint *pnt);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Add the specified point on curve as the Nth element (N = idField)
    of the specified data object (VDATA).

    If the Nth element is already defined (and it is a list), the point is appended to a
    list of points referenced by the Nth element.

    If the NTh element is defined (and it is not a list), the point is overwritten.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] critPnt whether to map point to critical point of curve
    @param [in] crvPath pick path of curve
    @param [in] pnt point on the curve

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxDataSetPntOnCrvPath(int idData, int idField, int critPnt, const svxEntPath *crvPath, const svxPoint *pnt);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Log the point/direction on the entity or point/direction to the specified field.

    If you want to log the critical point to the field, you should set useCritPnt to 1 and
    set one type to critTyp.

    The point can be on the curve or the surface.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] pntData point on entity data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDataSetPntOnEnt(int idData, int idField, const svxPntOnEnt *pntData);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Log the point on the entity or point to the specified field.
    The point can be on the curve or the surface, datum plane.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] pntData point on entity data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_INPUT_ERROR
    */
    extern evxErrors cvxDataSetPntOnEntPath(int idData, int idField, const svxPntOnEntPath *pntData);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Log the direction of point on the entity or direction to the specified field.
    The point can be on the curve or the surface, datum plane.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] dirData direction data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_INPUT_ERROR
    */
    extern evxErrors cvxDataSetDirOnEntPath(int idData, int idField, const svxDirOnEntPath *dirData);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Logs a "mat" pick to the specified field of the specified
    data container.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] mat entity matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxDataSetMatrix(int idData, int idField, const svxMatrix *mat);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    When a feature is logged to the history, a copy of its driving VDATA is
    converted to a persistent state and recorded with the feature.

    After that, any modification you make to the original VDATA is not reflected into the
    VDATA recorded in the history.

    This function is used to update the VDATA associated with the specified feature
    (idFeature) with the contents of the input VDATA (idData). 

    If "idFeature < 1", the VDATA of the feature created by the active feature operation (CustomOp) is
    updated.

    If "ExcludeRegen != 0", this function does nothing if it is called during
    history regeneration.

    Before the contents of "iData" are assigned to the specified feature, an
    attempt is made to make all entity picks/references in the "iData" persistent.

    This requires finding the specified entities in the active part in order to
    lookup their persistent labels. If the entities cannot be found in the current
    part state, this function will fail.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idFeature id of feature in active part (0 for active feature operation)
    @param [in] ExcludeRegen 1 to disable the action of this function during regen, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxDataToFeature(int idData, int idFeature, int ExcludeRegen);


    //====================================================================================================================
    /** @name Data Get */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets the first item of data associated with the specified field of
    the specified data container.

    When the data come from a numeric input field in an option form, any
    expression entered by the user will be evaluated to determine a
    value for the number; the numeric value will be output in "Data->Num"
    and the expression will be output in "Data->Text".

    When the data come from a text input field, the raw text is output in
    "Data->Text" without replacing expressions.  If you wish to support
    variable reference expressions such as "[$VAR]" where VAR is the name
    of a variable in the active target, the output string from this
    function can be given to the cvxPartVarSubstitute() function to
    replace the "[$VAR]" expressions with the values of the variables.
    For example:

    @code
       svxData Data;
       if (!cvxDataGet(idData, idField, &Data) && Data.isText)
          cvxPartVarSubstitute(Data.Text, sizeof(Data.Text), NULL);
    @endcode

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] Data first data item associated with "idField"

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDataGet(int idData, int idField, svxData *Data);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets the RGB color values in the specified VDATA field as an integer or one index value.
    Use cvxDataSetColor() to encode RGB color as an integer or one index value into VDATA field.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] Color rgb color

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDataGetColor(int idData, int idField, svxColor *Color);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets the entity id associated with the specified field of the
    specified data container. Input NULL for "idParent" if you are
    not interested in getting parent information.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] idEnt id of entity associated with field (0 if undefined)
    @param [out] idParent id of entity parent (0 if undefined; NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDataGetEnt(int idData, int idField, int *idEnt, int *idParent);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets the list of entity id's associated with the specified field of
    the specified data container.  The list referenced by "**idEnts" is
    allocated by this function and must be deallocated by the calling
    procedure.  A NULL pointer is output if no data is found.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] Count data item count
    @param [out] idEnts list of entity id's associated with field

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CMMD_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDataGetEnts(int idData, int idField, int *Count, int **idEnts);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets the list of data items associated with the specified field of
    the specified data container.  The list referenced by "**Data" is
    allocated by this function and must be deallocated by the calling
    procedure.  A NULL pointer is output if no data is found.

    @note
    For set list widget, idEntity to output the VDATA list
    associated with "idField"

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] Count data item count
    @param [out] Data list of data items associated with "idField"

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CMMD_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxDataGetList(int idData, int idField, int *Count, svxData **Data);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets the double precision number associated with the specified field of
    the specified data container.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] Number double precision number associated with "idField"

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDataGetNum(int idData, int idField, double *Number);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Returns the integer option number associated with the specified field.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field

    @return
    -        the integer option number associated with the specified field
    -        0 - if no number is associated with the specified field or function fails
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxDataGetOpt(int idData, int idField);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Get the entity pick-path associated with "idField" of "idData".

    This function does not activate the pick-path.

    If "*FirstEnt=1", the first pick is retrieved, "*FirstEnt" is set to
    zero and static variables inside this function are set up to enable
    retrieval of the next pick when this function is called again with
    "*FirstEnt=0".  If a pick is successfully retrieved, this function
    returns 0.  If no pick was retrieved, it returns -1.  If there was
    a fatal error, it returns 1.

    If "FirstEnt=NULL", the first entity is retrieved without setting
    things up to get a "next" entity.

    This function should not be called recursively, but no checking is
    done to insure it.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in,out] FirstEnt 1 for first entity; 0-subsequent entities
    @param [out] Ent entity pick path

    @retval succeeds
    -        0 - no error and an entity was retrieved successfully
    -       -1 - no error, but no entity was retrieved.
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVAID_ENT_PATH
    -        ZW_API_ENT_PATH_ERROR
    */
    extern int cvxDataGetPath(int idData, int idField, int *FirstEnt, svxEntPath *Ent);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Get the entity pick-paths associated with "idField" of "idData".
    "**paths" is allocated by this function and must be deallocated
    by the calling procedure.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] count count of paths
    @param [out]  paths list of entity pick path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CMMD_DATA_ERROR
    -        ZW_aPI_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDataGetPaths(int idData, int idField, int *count, svxEntPath **paths);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets the point coordinates associated with the specified field
    of the specified data container.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] Pnt point associated with field

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDataGetPnt(int idData, int idField, svxPoint *Pnt);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets the list of point coordinates associated with the specified
    field of the specified data container.  The list referenced by
    "**Pnts" is allocated by this function and must be deallocated
    by the calling procedure.  A NULL pointer is output if no data
    is found.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] Count data item count
    @param [out] Pnts list of points associated with field

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CMMD_DATA_ERROR
    -        ZW_APPI_MEMORY_ERROR
    */
    extern evxErrors cvxDataGetPnts(int idData, int idField, int *Count, svxPoint **Pnts);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets the point coordinates and path of point on entity associated with the specified field
    of the specified data container.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] pnt point associated with field
    @param [out] path path of point on entity(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDataGetPntOnEnt(int idData, int idField, svxPoint *pnt, svxEntPath *path);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets the list of point coordinates and list of paths associated with the specified
    field of the specified data container.
    The list referenced by
    "**paths" and "**pnts" are allocated by this function and must be deallocated
    by the calling procedure.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] count data item count
    @param [out]  pnts list of points associated with field
    @param [out]  paths list of paths associated with points(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CMMD_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDataGetPntsOnEnts(int idData, int idField, int *count, svxPoint **pnts, svxEntPath **paths);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Outputs "Promote=1", if the pick associated with the point-on-entity
    stored in the specified input field should be promoted to pick the
    parent of the entity instead of the entity itself.  If not, "Promote=0"
    is output.

    A common case is the promotion of a curve pick to its parent sketch
    or curve list.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] Promote 1 to promote entity to parent, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDataGetPromote(int idData, int idField, int *Promote);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets the null-terminated ascii text string associated with the
    specified field of the specified data container.

    If necessary, the string copied to the memory referenced by "Text" is
    truncated based on the value of "NumBytes".

    The calling procedure is responsible for allocating and deallocating
    the memory referenced by "Text".

    @note
    This function outputs the raw text contained in the specified field.    
    Expressions embedded in the text to reference ZW3D
    variables are not automatically replaced by the variable values.   
    If you wish to support variable references of the form "[$VAR]" where VAR
    is the name of a variable in the active target, the output string from
    this function can be given to the cvxPartVarSubstitute() or
    cvxPartVarSubstituteResize() function to replace the "[$VAR]"
    expressions with the values of the variables.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] NumBytes number of bytes of memory referenced by "Text"
    @param [out] Text null-terminated ascii string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxDataGetText(int idData, int idField, int NumBytes, char *Text);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Get the transformation matrix associated with the specified field of
    the specified data container.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] Matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDataGetMatrix(int idData, int idField, svxMatrix *Matrix);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Get a list of data item indices associated with the specified field of
    the specified data container.

    The list referenced by "**idItems" is allocated by this function and
    must be deallocated by the calling procedure.  A NULL pointer is
    output if no data is found.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [out] Count data item count
    @param [out] idItems list of data item indices associated with field

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CMMD_DATA_ERROR
    */
    extern evxErrors cvxDataGetItemList(int idData, int idField, int *Count, int **idItems);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Get data of associated with specified data item.

    @param [in] idItem index of data item
    @param [out] Data data of associated with specified data item

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDataGetItemData(int idItem, svxData *Data);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets data for all field in which valid data exists associated with
    the specified data container.

    If using cvxPartInqFtrData() to get idData prior to calling this function, set cvxPartInqFtrData()'s
    iNoEval input argument to 0 to ensure idData will contain evaluated data.

    The calling procedure is responsible for deallocating the memory
    assigned by this function to the "fldData" structure using cvxFldDataFree().

    @param [in] idData id of data container (i.e. VDATA)
    @param [out] numFld number of fields in which valid data exists
    @param [out] fldData list of field data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CMMD_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxDataGetAll(int idData, int *numFld, svxFldData **fldData);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Frees memory associated with the specified field data structure.

    @param [in] Count number of field data
    @param [in] fldData list of field data

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxFldDataFree(int Count, svxFldData **fldData);


    //====================================================================================================================
    /** @name Data Clear */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_paramdefine_param

    Deletes data associated with the specified field (idField) of the
    specified data container (idData).

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxDataClear(int idData, int idField);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Delete the data associated with the specified field of the
    specified data container.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxDataDel(int idData, int idField);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Delete specified input data item associated with the specified
    field (data_id) of the specified VDATA object (idx_data) which
    is assumed to reside in PRJ_BIN.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] iEnt entity to delete

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxDataDelItem(int idData, int idField, int iEnt);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Delete the data associated with the specified field of the
    specified data container.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxDataDelUnHi(int idData, int idField);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Deletes a data container created by cvxDataInit(),
    freeing the memory associated with it.

    @param [in] idData id of data container (i.e. VDATA)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxDataFree(int idData);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Remove the specified data item from specified field.

    @param [in] idData id of data container (i.e. VDATA)
    @param [in] idField id of data field
    @param [in] idItem index of data item

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_DATA_ERROR
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxDataGrpRem(int idData, int idField, int idItem);


    //====================================================================================================================
    /** @name Data Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_paramdefine_param

    Get the index of the data container associated with the active form.
    If no form is activated, idData is set to -1.

    @param [out] idData id of data container

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDataInqActive(int *idData);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Get the index of the data container associated with the parent of an
    active form. if no form is activated or active form has no parent form,
    idData is set to -1.

    @param [out] idData id of data container 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDataInqParent(int *idData);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Gets form name by VDATA.

    @param [in] idData id of data container (i.e. VDATA)

    @return 
    -      Form name;
    -      NULL if function fails.
    @warning
    -      ZW_API_INVALID_INPUT
    */
    extern char *cvxDataName(int idData);


    //====================================================================================================================
    /** @name Aux Frame */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_paramdefine_param

    Show or hide Aux Frame by the input init values.
    Aux frame is displayed when idData equals to the id of data container.
    Aux frame is hidden when idData equals to -1.

    @param [in] idData id of data container
    @param [in] entField id of entity field, to store selected entities
    @param [in] matField id of matrix field, to store matrix data for aux frame

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxAuxFrameShow(int idData, int entField, int matField);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Set origin position of Aux Frame.

    @param [in] Origin origin of aux frame

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxAuxFrameSetOrigin(const svxPoint *Origin);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Set direction of Aux Frame.

    @param [in] AxisType axis type
    @param [in] AxisDir direction

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxAuxFrameSetAxisVec(evxAxisType AxisType, const svxVector *AxisDir);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Set buddy field of Aux Frame. the function must be called after cvxAuxFrameShow function.

    @param [in] idData VDATA
    @param [in] idXFld x field
    @param [in] idYFld y field
    @param [in] idZFld z field
    @param [in] idOrgFld origin field

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxAuxFrameSetDirXYZOrgBuddy(int idData, int idXFld, int idYFld, int idZFld, int idOrgFld);

    /**
    @ingroup zwapi_cmd_paramdefine_param

    Show element of AuxFrame. Set 0 to show all(except QuadrantArea). 
    Otherwise add below for "iElem": 
    -  AUXFRAME_X_AXIS   0x1 
    -  AUXFRAME_Y_AXIS   0x2 
    -  AUXFRAME_Z_AXIS   0x4 
    -  AUXFRAME_XY_QUA   0x8 
    -  AUXFRAME_YZ_QUA   0x10 
    -  AUXFRAME_ZX_QUA   0x20 
    -  AUXFRAME_ORIGIN   0x40 
    -  AUXFRAME_XY_AREA  0x80 
    -  AUXFRAME_YZ_AREA  0x100 
    -  AUXFRAME_ZX_AREA  0x200 

    @param [in] iElem Set which element to show in AuxFrame

    */
    extern void cvxMoveSetAuxFrameElem(int iElem);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PARAM_H */
