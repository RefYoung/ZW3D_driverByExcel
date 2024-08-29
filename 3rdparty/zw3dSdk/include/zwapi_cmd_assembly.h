/**
@file zwapi_cmd_assembly.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Assembly Commands API
*/
/**
@defgroup zwapi_cmd_assembly Assembly Commands
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Assembly Commands API
*/

#pragma once
#ifndef ZW_API_ASSEMBLY_FTR_H /* this ifndef surrounds entire header */
#define ZW_API_ASSEMBLY_FTR_H

#include "zwapi_cmd_assembly_data.h"
#include "zwapi_cmd_shape_data.h"


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Component */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_assembly

    Inserts a new component in the active part.  If "idComp"
    is not NULL, the id of the new component is output.

    If this function is called from a custom history operation,
    the component will be associated with the custom operation
    and will be deleted automatically when the custom operation
    is regenerated and re-inserts the component.

    @note
    Interface cvxCompInsInit() can initialize component data
    of this function.

    This function has updated in ZW3D 2024 SP(28.05), and svxCompData is very different from previous version,
    you may meet some compatibility issues.
    If you have used Comp->Copy or Comp->CopyPart before, you need to change to Comp->InstanceData.CopyPart now.
    If you have used Comp->Align and Comp->AlignData before, you need to change to Comp->IdxAlignFaceDatum now.

    When this function is called from within a custom history
    operation, if "idComp" is not NULL, "*idComp" must be a value
    greater than 0, and if this function is Cyclically called
    from within a custom history operation, "*idComp" CAN'T BE
    THE SAME in every calling, otherwise this function will return
    "ZW_API_INPUT_ERROR". value will be encoded in the component's 
    persistent label to differentiate it from other components
    added by the custom operation. After the value of "idComp"
    is used to label the new component, the database id of the
    new component will be output via "idComp".

    @param [in] Comp component data
    @param [in,out] id of new component,as input when this function is called from custom history operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_SINGLE_MULTI_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxCompIns(const svxCompData *Comp, int *idComp);

    /**
    @ingroup zwapi_cmd_assembly

    Inserts a new component(using auto hole match) in the active part.  If "idComp"
    is not NULL, the id of the new component is output.

    If this function is called from a custom history operation,
    the component will be associated with the custom operation
    and will be deleted automatically when the custom operation
    is regenerated and re-inserts the component.

    @note
    When this function is called from within a custom history
    operation, if "idComp" is not NULL, "*idComp" must be a value
    greater than 0, and if this function is Cyclically called
    from within a custom history operation, "*idComp" CAN'T BE
    THE SAME in every calling, otherwise this function will return
    "ZW_API_INPUT_ERROR". value will be encoded in the component's
    persistent label to differentiate it from other components
    added by the custom operation. After the value of "idComp"
    is used to label the new component, the database id of the
    new component will be output via "idComp".

    @param [in] Comp component insertion data(auto hole match)
    @param [in,out] id of new component,as input when this function is called from custom history operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_SINGLE_MULTI_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_GET_NEW_OBJ_FAIL
    */
    extern evxErrors cvxCompAutoHoleMatchIns(const svxCompInsHoleMatchData *Comp, int *idComp);

    /**
    @ingroup zwapi_cmd_assembly

    Inserts a new component in the active part.  If "idComp"
    is not NULL, the id of the new component is output.

    If this function is called from a custom history operation,
    the component will be associated with the custom operation
    and will be deleted automatically when the custom operation
    is regenerated and re-inserts the component.

    @note
    When this function is called from within a custom history
    operation, if "idComp" is not NULL, "*idComp" must be a value
    greater than 0, and if this function is Cyclically called
    from within a custom history operation, "*idComp" CAN'T BE
    THE SAME in every calling, otherwise this function will return
    "ZW_API_INPUT_ERROR". value will be encoded in the component's
    persistent label to differentiate it from other components
    added by the custom operation. After the value of "idComp"
    is used to label the new component, the database id of the
    new component will be output via "idComp".

    @param [in] Comp component insertion data(with layout)
    @param [in,out] id of new component,as input when this function is called from custom history operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_SINGLE_MULTI_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_GET_NEW_OBJ_FAIL
    */
    extern evxErrors cvxCompWithLayoutIns(const svxCompInsWithLayoutData *Comp, int *idComp);

    /**
    @ingroup zwapi_cmd_assembly

    Include an unplaced component in the active part.  If "idComp"
    is not NULL, the id of the new component is output.

    @param [in] Comp component data
    @param [out] idComp id of new component (NULL to ignore) 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    */
    extern evxErrors cvxCompInclude(const svxCompIncludeData *Comp, int *idComp);

    /**
    @ingroup zwapi_cmd_assembly

    Merges a component with the active part using the specified
    combination method.  Only the component's top-level geometry
    is merged.  Sub-components of the component are not merged.

    Use cvxCompShift() to merge the component and its sub-components.

    If "idShape" is not NULL, the id of the last shape created by
    merging the component is output.  "isShape=0" is output if no
    shape was created by the merge.

    @note
    Merging a component
    could add multiple shapes, or other types of geometry, to the
    active part.  If there is a possibility that the merge created
    more than a single shape, use cvxEntNewList() to retrieve the
    new entities created by the merge.  
    This function can be overloaded to force merging of component
    dimensions by inputting the component id with a negative sign.

    @param [in] Combine combination method
    @param [in] idComp component id (0 for last feature)
    @param [out] idShape shape id (pass in NULL to ignore)

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
    extern evxErrors cvxCompMerge(evxBoolType Combine, int idComp, int *idShape);

    /**
    @ingroup zwapi_cmd_assembly

    Merges a component with the active part using the specified
    combination method.  Only the component's top-level geometry
    is merged.  Sub-components of the component are not merged.

    Use cvxCompShift() to merge the component and its sub-components.

    If "idShape" is not NULL, the id of the last shape created by
    merging the component is output.  "isShape=0" is output if no
    shape was created by the merge.

    @note
    Merging a component
    could add multiple shapes, or other types of geometry, to the
    active part.  If there is a possibility that the merge created
    more than a single shape, use cvxEntNewList() to retrieve the
    new entities created by the merge.

    @param [in] Combine combination method
    @param [in] idComp component id (0 for last feature)
    @param [in] MergeDim 1 to merge component part dimensions into active part, else 0
    @param [in] MergeWire 1 to merge component part wireframe geometry into active part, else 0
    @param [out] idShape shape id (pass in NULL to ignore)

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
    extern evxErrors cvxCompMerge2(evxBoolType Combine, int idComp, int MergeDim, int MergeWire, int *idShape);

    /**
    @ingroup zwapi_cmd_assembly

    Extracts a shape from the active part into a new part that is
    instanced back into the active part as a component (i.e. converts
    a shape into a component).  If the shape was merged from a pre-existing
    component, "Frame" and "Name" are ignored and the shape is extracted to
    the original component using its local frame and name.

    If "Frame" is input as NULL, the identity matrix is used.

    If "Name" is input as NULL, a default name is assigned to the component.

    If "idComp" is not NULL, the id of the new component is output.

    @param [in] idShape id of shape to extract
    @param [in] Frame local coordinate frame to map shape into part space
    @param [in] Name name of new part/component
    @param [in] NewFile 1 to put new part in a new file; 0 for active file
    @param [in] Overwrite response to "overwrite existing part?" query
    @param [out] idComp id of new component (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CCMD_EXEC_ERROR
    */
    extern evxErrors cvxCompExtract(int idShape, svxMatrix *Frame, vxLongName Name, int NewFile, evxResponse Overwrite, int *idComp);

    /**
    @ingroup zwapi_cmd_assembly

    Exports the specified geometry from the active target part to an
    external part.  If the destination part does not exist, it is
    created.  If the destination part already exists, the geometry
    is added to it.

    @param [in] Data data that defines geometry to be exported

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CCMD_EXEC_ERROR
    */
    extern evxErrors cvxPartGeomExport(svxGeomExport *Data);

    /**
    @ingroup zwapi_cmd_assembly

    Exports the specified geometry from the active target part to an
    external part.  If the destination part does not exist, it is
    created.  If the destination part already exists, the geometry
    is added to it.

    @param [in] Data data that defines geometry to be exported

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CCMD_EXEC_ERROR
    */
    extern evxErrors cvxPartGeomExportII(svxGeomExport *Data);

    /**
    @ingroup zwapi_cmd_assembly

    Copy and insert the specified part at the specified location.
    Outputs a list of indices of the new shapes.  The calling
    procedure MUST deallocate the output list with cvxMemFree().

    Interface cvxMemZero() can initialize variables of this function.

    @param [in] Part component data
    @param [out] Count number of shapes (NULL to ignore)
    @param [out] ShapeList list of shape id's (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CCMD_EXEC_ERROR
    */
    extern evxErrors cvxPartIns(svxPartInstData *Part, int *Count, int **ShapeList);


    //====================================================================================================================
    /** @name Common Constraint */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a coincident constraint, the components
    will remain coincident.

    @param [in] Ent1 pick-path of first entity (edge,curve,face,datum,point,datum axis)
    @param [in] Pnt1 coordinate of the coincidence point on the first entity (NULL to ignore)
    @param [in] Ent2 pick-path of second entity (edge,curve,face,datum,point,datum axis)
    @param [in] Pnt2 coordinate of the coincidence point on the second entity (NULL to ignore)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddCoincidentCons(svxEntPath *Ent1, svxPoint *Pnt1, svxEntPath *Ent2, svxPoint *Pnt2, svxConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a tangent constraint.

    @param [in] Ent1 pick-path of first entity (edge,curve,face,datum,point,datum axis)
    @param [in] Ent2 pick-path of second entity (edge,curve,face,datum,point,datum axis)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddTangentCons(svxEntPath *Ent1, svxEntPath *Ent2, svxConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a concentric constraint.

    @param [in] Ent1 pick-path of first entity (edge,curve,face,datum,point,datum axis)
    @param [in] Pnt1 coordinate of the coincidence point on the first entity (NULL to ignore)
    @param [in] Ent2 pick-path of second entity (edge,curve,face,datum,point,datum axis)
    @param [in] Pnt2 coordinate of the coincidence point on the second entity (NULL to ignore)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddConcentricCons(svxEntPath *Ent1, svxPoint *Pnt1, svxEntPath *Ent2,
                                              svxPoint *Pnt2, svxConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a parallel constraint.

    @param [in] Ent1 pick-path of first entity (edge,curve,face,datum,point,datum axis)
    @param [in] Ent2 pick-path of second entity (edge,curve,face,datum,point,datum axis)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddParallelCons(svxEntPath *Ent1, svxEntPath *Ent2, svxConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a perpendicular constraint.

    @param [in] Ent1 pick-path of first entity (edge,curve,face,datum,point,datum axis)
    @param [in] Ent2 pick-path of second entity (edge,curve,face,datum,point,datum axis)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddPerpendicularCons(svxEntPath *Ent1, svxEntPath *Ent2, svxConsData *ConsData, int *idCons);
                 
    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a angular constraint.

    @param [in] Ent1 pick-path of first entity (edge,curve,face,datum,point,datum axis)
    @param [in] Ent2 pick-path of second entity (edge,curve,face,datum,point,datum axis)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddAngularCons(svxEntPath *Ent1, svxEntPath *Ent2, svxConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a lock constraint.

    @param [in] Comp1 pick-path of first component
    @param [in] Comp2 pick-path of second component
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddLockCons(svxEntPath *Comp1, svxEntPath *Comp2, svxConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a distance constraint.

    @param [in] Ent1 pick-path of first entity (edge,curve,face,datum,point,datum axis)
    @param [in] Pnt1 coordinate of the coincidence point on the first entity (NULL to ignore)
    @param [in] Ent2 pick-path of second entity (edge,curve,face,datum,point,datum axis)
    @param [in] Pnt2 coordinate of the coincidence point on the second entity (NULL to ignore)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddDistanceCons(svxEntPath *Ent1, svxPoint *Pnt1, svxEntPath *Ent2,
                                            svxPoint *Pnt2, svxConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a middle constraint.

    @param [in] BaseEnt1 pick-path of first base entity (face,datum)
    @param [in] BaseEnt2 pick-path of second base entity (face,datum)
    @param [in] nCenter number of center entities (1 or 2)
    @param [in] CenterEnts list of center entities (edge,curve,face,datum)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddMiddleCons(svxEntPath *BaseEnt1, svxEntPath *BaseEnt2, int nCenter,
                                          svxEntPath *CenterEnts, svxConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a symmetry constraint.

    @param [in] Plane pick-path of plane (face,datum)
    @param [in] SymEnt1 pick-path of first symmetric entity(edge,curve,face,datum,point,datum axis)
    @param [in] SymEnt2 pick-path of second symmetric entity(edge,curve,face,datum,point,datum axis)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddSymmetryCons(svxEntPath *Plane, svxEntPath *SymEnt1, svxEntPath *SymEnt2, svxConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a frame constraint.

    @param [in] Datum1 pick-path of first datum (datum plane, datum CSYS)
    @param [in] Datum2 pick-path of second datum (datum plane, datum CSYS)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddFrameCons(svxEntPath *Datum1, svxEntPath *Datum2, svxConsData *ConsData, int *idCons);


    //====================================================================================================================
    /** @name Mechanical Constraint */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a gear constraint.

    @param [in] Gear1 pick-path of first entity (edge, curve, face, datum plane, point, datum axis)
    @param [in] Gear2 pick-path of second entity (edge, curve, face, datum plane, point, datum axis)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddGearCons(const svxEntPath *Gear1, const svxEntPath *Gear2, const svxGearConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a path constraint. If multiple curves or edges are input as 
    constraint paths, all curves or edges are required to come from the same component and
    G1 continuous between curves or edges.

    @param [in] Pnt point on component (edge, curve, face, datum plane, point)
    @param [in] nPaths number of paths
    @param [in] Paths pick-path list of paths to align to, the curves must be G1 continuous (edge, curve)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddPathCons(const svxPntOnEntPath *Pnt, int nPaths, const svxEntPath *Paths, const svxPathConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a linear couple constraint.

    @param [in] Comp1 pick-path of the first component
    @param [in] Dir1 pick-path of the entity to specify the first component move direction (edge, curve, face, datum, point)
    @param [in] Comp2 pick-path of the second component
    @param [in] Dir2 pick-path of the entity to specify the second component move direction (edge, curve, face, datum, point)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddLinearCoupleCons(const svxEntPath *Comp1, const svxEntPath *Dir1,
                                                const svxEntPath *Comp2, const svxEntPath *Dir2, const svxLinearCpData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a rack and pinion constraint.

    @param [in] Rack pick-path of first entity (edge, curve, face, datum plane, point, datum axis)
    @param [in] Pinion pick-path of second entity (edge, curve, face, datum plane, point, datum axis)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddRackPinionCons(const svxEntPath *Rack, const svxEntPath *Pinion, const svxRackPinionData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a screw constraint.

    @param [in] ScrewEnt pick-path of screw entity (edge, curve, face, datum plane, point, datum axis)
    @param [in] LinearEnt pick-path of linear entity (edge, curve, face, datum plane, point, datum axis)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddScrewCons(const svxEntPath *ScrewEnt, const svxEntPath *LinearEnt, const svxScrewConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a slot constraint.

    @param [in] Ent pick-path of the first entity (edge, curve, face, datum plane, point, datum axis)
    @param [in] nSlots number of slot faces
    @param [in] Slots pick-path list of slot faces
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddSlotCons(const svxEntPath *Ent, int nSlots, const svxEntPath *Slots, const svxSlotConsData *ConsData, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a Cam constraint.

    @param [in] Ent pick-path of the first entity (edge, curve, face, datum plane, point, datum axis)
    @param [in] nCamFaces number of cam faces
    @param [in] CamFaces pick-path list of cam faces
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddCamCons(const svxEntPath *Ent, int nCamFaces, const svxEntPath *CamFaces, int *idCons);

    /**
    @ingroup zwapi_cmd_assembly

    Use the function to create a universal joint constraint.

    @param [in] Shaft1 pick-path of first cross or propeller entity (edge, curve, face, datum axis)
    @param [in] HingePnt1 the first hinge point on entity (edge, curve, face, datum, point) (NULL to ignore)
    @param [in] Shaft2 pick-path of second cross or propeller entity (edge, curve, face, datum axis)
    @param [in] HingePnt2 the second hinge point on entity (edge, curve, face, datum, point) (NULL to ignore)
    @param [in] ConsData constraint custom data (NULL to use default value)
    @param [out] idCons index of new constraint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompAddUniJointCons(const svxEntPath *Shaft1, const svxPntOnEntPath *HingePnt1, const svxEntPath *Shaft2, const svxPntOnEntPath *HingePnt2, const svxUniJointData *ConsData, int *idCons);

    //====================================================================================================================
    /** @name Other Constraint */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_assembly

    Creates an alignment constraint between two shapes or components.

    @param [in] Align alignment constraint

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartAlign(svxAlign *Align);

    /**
    @ingroup zwapi_cmd_assembly

    Anchors the specified component or shape so that it does not
    move when alignment constraints are created between it and
    another component/shape.

    @param [in] idEntity component or shape id in active part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartAnchor(int idEntity);

    //====================================================================================================================
    /** @name Basic Editing */
    //====================================================================================================================

    /**
    @ingroup zwapi_cmd_assembly

    Initialize the svxAsmPtnData structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type  assembly pattern type
    @param [out] data assembly pattern data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxCompPtnInit(evxAsmPatternType type, svxAsmPtnData *data);

    /**
    @ingroup zwapi_cmd_assembly

    Use this function to bulid assembly pattern.Six different methods 
    of pattern are available, each method requires different types of 
    input.

    @note
    Interface cvxAsmPtnInit() can initialize variables assembly pattern
    of this function.

    @param [in] data        assembly pattern input data
    @param [out] idPattern  id of pattern feature (NULL to ignore) 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompPtn(const svxAsmPtnData *data, int *idPattern);

    /**
    @ingroup zwapi_cmd_assembly

    Initialize the svxAsmMoveData structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type   assembly move type
    @param [out] data  assembly move data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxCompMoveInit(evxAsmMoveType type, svxAsmMove *data);

    /**
    @ingroup zwapi_cmd_assembly

    Use this function to build assembly move. Six different methods 
    of pattern are available, each method requires different types of 
    input.

    @note
    Interface cvxCompMoveInit() can initialize variables assembly move 
    of this function.

    @param [in] data  assembly move input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxCompMove(const svxAsmMove *data);

    /**
    @ingroup zwapi_cmd_assembly

    Initialize the svxAsmMirror structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type   assembly mirror type
    @param [out] data  assembly mirror data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxCompMirrorInit(evxAsmMirrorType type, svxAsmMirror *data);

    /**
    @ingroup zwapi_cmd_assembly

    Use this function to build assembly mirror. Two different methods 
    of mirror are available, each method requires different types of 
    input.

    @note
    Interface cvxCompMirrorInit() can initialize variables assembly mirror 
    of this function.

    @param [in] data  assembly mirror input data
    @param [out] idMirror  id of mirror feature (NULL to ignore)

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
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxCompMirror(const svxAsmMirror *data, int *idMirror);

    /**
    @ingroup zwapi_cmd_assembly

    Initialize the svxAsmCut structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data  assembly cut data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxAsmCutInit(svxAsmCut *data);

    /**
    @ingroup zwapi_cmd_assembly

    Use this function to build assembly cut.

    @note
    Interface cvxAsmCutInit() can initialize variables assembly cut
    of this function.

    @param [in] data    assembly mirror input data
    @param [out] idCut  id of cut feature (NULL to ignore)

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
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxAsmCut(const svxAsmCut *data, int *idCut);

    /**
    @ingroup zwapi_cmd_assembly

    Initialize the svxAsmFllt structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type  assembly fillet type
    @param [out] data assembly fillet data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxAsmFilletInit(evxChamFlltType type, svxAsmFllt *data);

    /**
    @ingroup zwapi_cmd_assembly

    Use this function to build assembly fillet. Three different methods 
    of fillet are available, each method requires different types of 
    input.

    @note
    Interface cvxAsmFilletInit() can initialize variables assembly fillet 
    of this function.

    @param [in] data    assembly fillet input data
    @param [out] idFllt id of fillet feature (NULL to ignore) 

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
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxAsmFillet(const svxAsmFllt *data, int *idFllt);

    /**
    @ingroup zwapi_cmd_assembly

    Initialize the svxAsmChmf structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type  assembly chamfer type
    @param [out] data assembly chamfer data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxAsmChamferInit(evxAsmChmfType type, svxAsmChmf *data);

    /**
    @ingroup zwapi_cmd_assembly

    Use this function to build assembly chamfer. Two different methods 
    of chamfer are available, each method requires different types of 
    input.

    @note
    Interface cvxAsmChamferInit() can initialize variables assembly chamfer
    of this function.

    @param [in] data     assembly chamfer input data
    @param [out] idChmf  id of chamfer feature (NULL to ignore)

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
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxAsmChamfer(const svxAsmChmf *data, int *idChmf);

    //====================================================================================================================
    /** @name Inquire */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_assembly

    Determine exist or not exist intersection between the
    input two shapes which come from two components.

    @param [in] BaseShpPath the first shape in a component
    @param [in] OpShpPath the second shape in other component
    @param [out] fInterfer if found interference, output V_TRUE, otherwise output V_FALSE

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCompIsectShpChk(svxEntPath *BaseShpPath, svxEntPath *OpShpPath, int *fInterfer);

    /**
    @ingroup zwapi_cmd_assembly

    Determine exist or not exist intersection between the
    input two shapes which come from two components.

    @param [in] BaseShpPath the first shape in a component
    @param [in] OpShpPath the second shape in other component
    @param [in] fClosedChk option to control whether check the open shell
                           1 is excluding the open shell. otherwise is 0
    @param [out] fInterfer if found interference, output V_TRUE, otherwise output V_FALSE

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCompIsectShpChk2(svxEntPath *BaseShpPath, svxEntPath *OpShpPath, int fClosedChk, int *fInterfer);

    /**
    @ingroup zwapi_cmd_assembly

    Check if there is interference between the input components and output the interference result.
    all components in current assembly are checked when both of the input component paths are NULL.

    @note
    The memory referenced by "IferResults" is allocated by this function.
    The calling procedure is responsible to free it (cvxMemFree((void**)&IferResults)).

    @deprecated Please use cvxCompInterferenceCheck instead.
    @see cvxCompInterferenceCheck

    @param [in] BaseComp pick path of the first Component, can be NULL
    @param [in] ChkComp pick path of the second Component, can be NULL
    @param [in] SubAsmAsWhole 1:sub-assembly as a whole, don't check interference inside sub-assembly
                              0:check interference inside sub-assembly
    @param [in] IgnoreHidden whether to ignore the hidden components within the sub-assembly
    @param [out] IferCnt number of interference
    @param [out] IferResults pointer to list of interference result data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCompIferCheck(svxEntPath *BaseComp, svxEntPath *ChkComp, int SubAsmAsWhole,
                                      int IgnoreHidden, int *IferCnt, svxIferChkResData **IferResults);

    /**
    @ingroup zwapi_cmd_assembly

    Check if there is interference between the input components and output the interference result.
    all components in current assembly are checked when both of the input component paths are NULL.

    @note
    The memory referenced by "IferResults" is allocated by this function.
    The calling procedure is responsible to free it (cvxCompIfterDataFree(IferCnt, (void**)&IferResults)).

    @param [in] BaseComp pick path of the first Component, can be NULL
    @param [in] ChkComp pick path of the second Component, can be NULL
    @param [in] SubAsmAsWhole 1:sub-assembly as a whole, don't check interference inside sub-assembly
                              0:check interference inside sub-assembly
    @param [in] IgnoreHidden whether to ignore the hidden components within the sub-assembly
    @param [in] saveInterferenceGeometry whether to save interference geometry, 1-save, 0-not save
    @param [out] IferCnt number of interference
    @param [out] IferResults pointer to list of interference result data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCompInterferenceCheck(svxEntPath *BaseComp, svxEntPath *ChkComp, int SubAsmAsWhole,
                                              int IgnoreHidden, int saveInterferenceGeometry, int *IferCnt, svxIferChkResData **IferResults);

    /**
    @ingroup zwapi_cmd_assembly

    Free the data that allocated by cvxCompIferCheck.

    @param [in] count count of data to free
    @param [in] resData data to free

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxCompIfterDataFree(int count, svxIferChkResData **resData);

    /**
    @ingroup zwapi_cmd_assembly

    Calculate the clearance between the input components and output the clearance result.
    all components in current assembly are checked when the input component paths are NULL.

    The memory referenced by "ClrDatas" is allocated by this function.
    The calling procedure is responsible to free it (cvxMemFree((void**)ClrDatas)).

    @param [in] Count number of components or shapes (0 to check the whole assembly)
    @param [in] Comps list of components or shapes (NULL to check the whole assembly)
    @param [in] Clear clearance threshold, only results with clearance value less than the threshold are output
    @param [in] ChkCompShp whether to check clearance between component and top shape (0 = no, 1 = yes)
    @param [in] IgnoreHidden whether to ignore hidden components (0 = no, 1 = yes)
    @param [in] ChkSubAsm whether to check sub-assembly internal parts clearance (0 = no, 1 = yes)
    @param [out] ClrCnt number of clearance check results
    @param [out] ClrDatas list of clearance check results

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCompClearCheck(int Count, svxEntPath *Comps, double Clear, int ChkCompShp, int IgnoreHidden,
                                       int ChkSubAsm, int *ClrCnt, svxClrChkData **ClrDatas);

    /**
    @ingroup zwapi_cmd_assembly

    Initialize the parameters of svxCompData.

    @note
    Do not assign a value to variable "Comp" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] PlacementType placement type.
    @param [out] Comp component data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxCompInsInit(svxCompData *Comp);

    /**
    @ingroup zwapi_cmd_assembly

    Initialize the parameters of svxCompWithLayoutData.

    @note
    Do not assign a value to variable "Comp" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] LayoutType layout type.
    @param [in] PositionType position type.
    @param [out] Comp component insertion data(With Layout)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxCompWithLayoutInsInit(evxLayoutType LayoutType, evxPositionType PositionType, svxCompInsWithLayoutData *Comp);

    /**
    @ingroup zwapi_cmd_assembly

    Initialize the parameters of svxCompInsHoleMatchData.

    @note
    Do not assign a value to variable "Comp" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] Comp component insertion data(Auto Hole Match)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxCompAutoHoleMatchInsInit(svxCompInsHoleMatchData *Comp);

    //====================================================================================================================
    /** @name Reference */
    //====================================================================================================================
/**********************************************************************
*! -Reference- : zwapi_cmd_dataexchange.h
*  extern evxErrors cvxPartRefGeom(svxEntPath*, int Associative, int* idGeom);
**********************************************************************/

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_ASSEMBLY_FTR_H */
