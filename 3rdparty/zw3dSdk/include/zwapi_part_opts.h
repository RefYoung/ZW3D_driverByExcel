/**
@file zwapi_part_opts.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Part Menu Commands API
*/
/**
@defgroup zwapi_part_opts Part Objects Operation
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Part Menu Commands API
*/

#pragma once
#ifndef ZW_API_PART_OPTS_H /* this ifndef surrounds entire header */
#define ZW_API_PART_OPTS_H

#include "zwapi_part_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Part Exit */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_opts

    Exits the active part to its parent part if it was activated
    from within an assembly, to its parent CAM plan if it was
    activated from within a CAM plan, to its parent drawing sheet
    if it was activated from a drawing sheet view, or to the
    root object level of its parent file, if it was activated
    from the level of the root object list.

    */
    extern void cvxPartExit(void);


    //====================================================================================================================
    /** @name Explicit Operation */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_opts

    Inserts a "Backup" operation in the active part's history.


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartBackup(void);

    /**
    @ingroup zwapi_part_opts

    Backs up the current model state in a history operation.
    Saving model states in the history can speed up history
    rollback and regen.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxHistBackup(void);

    /**
    @ingroup zwapi_part_opts

    Encapsulates the active part's history.

    @param [in] Option 0 to encapsulate according to active configuration options;   
                       1 to force encapsulate to use StartData/ExplicitData;   
                       2 to force encapsulate to use ExplicitData and explicit shape features;   
                       3 to force encapsulate to use Explicit data with active config setting for explicit shape features
    @param [in] KeepDimen 1 to save feature dimensions with encapsulated data; 0 to delete them

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartEncapsulate(int Option, int KeepDimen);

    /**
    @ingroup zwapi_part_opts

    Encapsulate the geometries into static geometries. That is, the geometry cannot redefine any more.
    The operations associated with the selected geometry will be encapsulated together. 

    @param [in] count the count of geometries
    @param [in] geomList id list of geometries (includes Shape, Curve, Point and Point Block)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartDefeature(int count, const int *geomList);

    /**
    @ingroup zwapi_part_opts

    Defines a "static" feature (i.e. history operation) for program-generated
    geometry (e.g. faces) to attach to.  When you are done adding geometry,
    call cvxPartHistEnd().  This function will cause all existing part geometry
    and history to be bundled into a single static "StartData" history operation.

    @param [in] Name history operation (i.e. feature) name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_CMMD_INIT_ERROR
    */
    extern evxErrors cvxPartHistStart(vxName Name);

    /**
    @ingroup zwapi_part_opts

    Used in conjunction with cvxPartHistStart() to bundle all existing part
    geometry and history to be bundled into a single static "StartData" history
    operation.  It is the equivalent of cvxPartEncapsulate(1, 0).

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartHistEnd(void);


    //====================================================================================================================
    /** @name History Operation */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_opts

    Launches interactive redefinition of the specified history operation.

    @param [in] Operation name of history operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxHistRedefine(vxName Operation);

    /**
    @ingroup zwapi_part_opts

    Logs a history operation that will cause history replay to skip to the specified operation
    if the specified conditional expression evaluates to a non-zero number (i.e. TRUE).  If it
    evaluates to zero (i.e. FALSE), history execution continues without skipping anything.

    @param [in] Expression conditional expression (see documentation of "Skip To" command)
    @param [in] Operation name of history operation
    @param [in] idOp id of history operation created by this function (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxHistSkipTo(char *Expression, vxName Operation, int *idOp);

    /**
    @ingroup zwapi_part_opts

    Play the feature history to the top of specified feature.
    If the state is 1, rollback to the specified feature,
    else play to this feature.

    @param [in] idxFtrPlayTo id of feature play to
    @param [in] state state of feature(1-has played, 0-not)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartFtrPlayTo(int idxFtrPlayTo, int state);

    /**
    @ingroup zwapi_part_opts

    Suppress or unSuppress the specified feature (including assembly feature).

    @param [in] count count of idFeatures
    @param [in] idFeatures list of feature id
    @param [in] suppress 1-suppress, 0-unSuppress

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
    extern evxErrors cvxPartFtrSuppress(int count, int *idFeatures, char suppress);

    /**
    @ingroup zwapi_part_opts

    Group the specified history operations.

    @param [in] idFirst id of first history operation
    @param [in] idLast id of last history operation
    @param [in] Name group name (input NULL for default name)
    @param [in] Close 1 to close new group, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartHistGroup(int idFirst, int idLast, const vxName Name, int Close);

    /**
    @ingroup zwapi_part_opts

    Output the index of the group where the specified
    history object is located.

    Output -1 if the specified history object is not
    in any group.

    @param [in] idHistObj  all object ids in the history tree.
    @param [out] idGroup   group id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartHistInqGroup(int idHistObj, int *idGroup);

    /**
    @ingroup zwapi_part_opts

    Paste operations currently on the clipboard into the history of the active part.


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartHistPaste(void);

    /**
    @ingroup zwapi_part_opts

    Cuts or copies the specified operations from the history of the active part
    to the clipboard, replacing operations previously stored on the clipboard.

    @param [in] Cut 1 to cut; 0 to copy
    @param [in] Count number of history operations to cut or copy
    @param [in] Operations list of history operation id's

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
    extern evxErrors cvxPartHistClip(int Cut, int Count, int *Operations);

    /**
    @ingroup zwapi_part_opts

    Cuts or copies the specified path of the active part
    to the clipboard, replacing operations previously stored on the clipboard.

    @param [in] Cut 1 to cut; 0 to copy
    @param [in] Count number of history operations to cut or copy
    @param [in] paths list of history operation path

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
    extern evxErrors cvxPartHistClipbyPath(int Cut, int Count, svxEntPath *paths);

    /**
    @ingroup zwapi_part_opts

    Renames an operation in the history of the active part and assigns
    the specified description to it (if defined).  Passing in a blank
    string for "Descript" will clear the description currently assigned
    to "idOp".

    @param [in] idOp id of history operation (i.e. feature)
    @param [in] Name new operation name
    @param [in] Descript new description (NULL if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartHistRename(int idOp, vxName Name, char *Descript);

    /**
    @ingroup zwapi_part_opts

    Deletes the specified operations from the history of the active part.

    @param [in] Count number of history operations to delete
    @param [in] Operations list of history operation id's

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
    extern evxErrors cvxPartHistDel(int Count, int *Operations);

    /**
    @ingroup zwapi_part_opts

    Deletes the specified operations from the history of the active part.

    @param [in] Count number of history operations to delete
    @param [in] Operations list of history operation id's
    @param [in] OpType OpType=0 : prompt to the user   
                       OpType=1 : auto delete associated history operations   
                       OpType=2 : auto suppress failed feature

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
    extern evxErrors cvxPartHistDelUtil(int Count, int *Operations, int OpType);

    /**
    @ingroup zwapi_part_opts

    Delete the feature group.
    delFtrs: 1-delete the features in the folder   
             0-just delete the folder

    @note
    You need regen the history after deleting all the features.

    @param [in] idFtr feature group index
    @param [in] delFtrs delete the features in the folder or not

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartDelGrpFtr(int idFtr, int delFtrs);


    /**
    @ingroup zwapi_part_opts

    Make the specified profile/datum internal/external.

    @note
    The profile/datum must be used by only one feature.

    @param [in] idEnt index of the profile/datum to make internal/external
    @param [in] external  1-make external, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartMkEntExternal(int idEnt, int external);


    /**
    @ingroup zwapi_part_opts

    Disable history tree update.

    The application that uses this function is ALWAYS responsible
    for re-enabling history tree update using cvxHistEnable().

    */
    extern void cvxHistDisable(void);

    /**
    @ingroup zwapi_part_opts

    Re-enable history tree update.

    Calls to this function MUST ALWAYS be paired with a prior call
    to cvxHistDisable().

    */
    extern void cvxHistEnable(void);


    //====================================================================================================================
    /** @name Feature Creation */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_opts

    Add the feature defined by idData and FtrName in the active part. the function
    is used in the execution function of a template command. If a template command
    modifies or adds entities, a feature will be added to the history manager after
    the command is executed. the use case is as follows:

    @code
    int CmdFun(int idData)
       {
       vxName ftrName = "FtrName";
       cvxPartHistAdd(idData, ftrName, 1, NULL);
       svxSurface srf = {};
       ...
       cvxPartFace(&srf, 0, NULL, 1, 1, 0.0, NULL);
       return 0;
    }
    @endcode

    @param [in] idData index of data container
    @param [in] FtrName feature name
    @param [in] Option feature type
                       (0: feature may geometrically modify entities
                       1: feature may create new entities)
    @param [out] idFtr index of feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartHistAdd(const int idData, const vxName FtrName, const int Option, int *idFtr);


    //====================================================================================================================
    /** @name Entity Operations */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_opts

    Erase specified entities of current Part.

    @note
    This function is the same as cvxEntErase(), cvxEntErase() can
    erase the entities of part, sketch and drawing.

    @param [in] Count number of entities
    @param [in] idEnts list of entity id's

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
    extern evxErrors cvxPartErase(int Count, int *idEnts);

    /**
    @ingroup zwapi_part_opts

    Use this function to scroll to the feature in the history tree by the special entity.

    @param [in] idEnt located entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartHistScrollTo(int idEnt);

    //====================================================================================================================
    /** @name Publish Set Operations */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_opts

    Erase specified publication sets of current Part.

    @see cvxPartPublishSet(): create a publication set to publish the specified entities.
    @see cvxPartInqPublishSets(): get a list of indices of the publication set.
    @see cvxPartInqPublishSet(): query data of the specified publication set.

    @param [in] Count number of publication sets
    @param [in] idPubSets list of publication set id's

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
    extern evxErrors cvxPartPublishSetDel(int Count, const int *idPubSets);

    //====================================================================================================================
    /** @name Quick Display Edit Operations */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_opts

    Set attribute of specific entities which include face ,curve, point and so on.You can 
    set layer for entities in this command.

    @code
       evxQuickEditDisplayEntityType entityType;
       svxQuickEditDisplayData data;
       cvxPartQuickDisplayEditInit(&data);
       int shapeCount;
       int ids[]={ ... };
       ...
       cvxPartQuickDisplayEdit(&entityType,ids,shapeCount,&data)
    @endcode

    @param [in] entityType type of entities.
    @param [in] ids list of entities id.
    @param [in] count count of entities.
    @param [in] data quick edit display data.

    @note:
    Interface cvxPartQuickDisplayEditInit() can initialize variables of this function. 
    If you don't set the parameters to entityAttribute after calling cvxPartQuickDisplayEditInit(), 
    the unmodified properties will not change.
    The entities in the list must all be of the correct type.

    For different types of entities, the valid fields of svxQuickEditDisplayData are as follows:
    Shape       :  colorId, transparency, lineStyle, lineWidth, layerName.
    Face        :  colorId, transparency.
    Edge        :  colorId, lineStyle, lineWidth.
    Curve       :  colorId, lineStyle, lineWidth, layerName.
    Point       :  colorId, pointStyle, pointSize, layerName.
    Sketch      :  layerName.
    Datum CSYS  :  layerName.
    Datum Plane :  layerName.
    Datum Axis  :  layerName.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxPartQuickDisplayEdit(evxQuickEditDisplayEntityType entityType, const int *ids, int count, const svxQuickEditDisplayData *data);

    /**
    @ingroup zwapi_part_opts

    Initialize the parameters of the cvxPartQuickDisplayEdit().

    @param [in] entityAttribute entity attribute data.

    @note:
    Do not assign a value to variable "entityAttribute" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
     -       ZW_API_INVALID_OUTPUT
     -       ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxPartQuickDisplayEditInit(svxQuickEditDisplayData *entityAttribute);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PART_OPTS_H */
