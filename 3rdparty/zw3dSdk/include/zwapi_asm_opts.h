/**
@file zwapi_asm_opts.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Assembly Menu Commands API
*/
/**
@defgroup zwapi_asm_opts Assembly Objects Operation
@ingroup AssemblyObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Assembly Menu Commands API
*/

#pragma once
#ifndef ZW_API_ASM_OPTS_H /* this ifndef surrounds entire header */
#define ZW_API_ASM_OPTS_H

#include "zwapi_asm_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Assembly Operations */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_opts

    Dissolve the picked sub-assembly

    @verbatim
    e.g, we have a asm-tree like this:
    A
    |- B
       |- D
       |- E
       |- F
    |- C
    @endverbatim
    then we dissolve "B", the asm-tree will look like:
    @verbatim
    A
    |- C
    |- D
    |- E
    |- F
    @endverbatim

    @param [in] path path of sub-assembly

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxAsmDissolve(const svxEntPath *path);

    /**
    @ingroup zwapi_asm_opts

    This function can create a sub-assembly with some several components,
    and also allow to save sub-assembly with new file format or new object.

    @note
    The consumer can initialize the structure using the \ref cvxMemZero((void*)data,sizeof(\ref  svxAsmGrpCompData)).  
    data.isPartOnly is used only for components in multi-object files.   
    data.isVirtual is used only for components in single-object files.   
    data.file is used only when data.isPartOnly is 0, otherwise data.file is ignored.

    e.g, we have a asm-tree like this:
    @verbatim
    A
    |- B
    |- C
    |- D
    @endverbatim
    then we group "C" and "D" as new component "G", the asm-tree will look like:
    @verbatim
    A
    |- B
    |- G
       |- C
       |- D
    @endverbatim
    If A is *.Z3 file, apply data.isPartOnly, else apply data.isVirtual.

    @param [in] data group as sub-assembly data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxAsmGrpComp(svxAsmGrpCompData *data);

    /**
    @ingroup zwapi_asm_opts

    Add the pick component to Favorites.

    @note 
    If the return value is ZW_API_INPUT_ERROR, you can use the interface cvxAsmFavoritesEnable()
    to determine the reason for the interface failure.

    @param [in] path  component pick path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxAsmAddToFavorites(svxEntPath *path);

    /**
    @ingroup zwapi_asm_opts

    Remove the pick component from Favorites.

    @note
    If the return value is ZW_API_INPUT_ERROR, you can use the interface cvxAsmFavoritesEnable()
    to determine the reason for the interface failure.

    @param [in] path  component pick path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxAsmRemoveFromFavorites(svxEntPath *path);

    /**
    @ingroup zwapi_asm_opts

    Determine whether the entered pick-path can be added to the favorites.

    @param [in] path component pick path

    @retval succeeds
    -        ZW_API_NO_ERROR : if the pick path can add to favorites.
    @retval other
    -        -1:if the pick path can remove from favorites.
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    -        2: if the pick path does not belong to the primary assembly node of the current file's assembly tree.
    -        3: if adding to favorites is not supported due to global configuration.
    */
    extern int cvxAsmFavoritesEnable(svxEntPath *path);

    /**
    @ingroup zwapi_asm_opts

    Traverse the assembly of the active part, find components that reference current file name and
    OldRootName, then replace the old reference (OldRootName) with the new one (NewRootName).

    @param [in] OldRootName the old root name of the target part
    @param [in] NewRootName the new root name of the target part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxAsmUpdateCompRef(const char *OldRootName, const char *NewRootName);

    //====================================================================================================================
    /** @name Component Operations */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_opts

    Activate the part instanced by the specified component for editing.
    It is assumed the component (idComp) resides in the active assembly.
    Use cvxPartExit() to exit the part to its parent assembly part.

    @see cvxCompEditPartByPath()

    @param [in] idComp id of component in active file

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
    extern evxErrors cvxCompEditPart(int idComp);

    /**
    @ingroup zwapi_asm_opts

    Activate the part instanced by the specified component path for editing.
    It is assumed the component (compPath) resides in the active assembly.
    Use cvxPartExit() to exit the part to its parent assembly part.

    @see cvxCompEditPart()

    @param [in] compPath path of component in active file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompEditPartByPath(const svxEntPath *compPath);

    /**
    @ingroup zwapi_asm_opts

    Regenerate specified component.
    This function activates the parent node of the this entity, if flag = 0.

    @param [in] Path pick path of component entity
    @param [in] flag 1 if activate back to the original node, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompRegen(svxEntPath *Path, int flag);

    /**
    @ingroup zwapi_asm_opts

    Changes the part instanced by the specified component in the active part.

    @param [in] idComp id of component in active file
    @param [in] File name of the file containing the part to instance
    @param [in] Part name of the part to instance from "File"

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
    extern evxErrors cvxCompSetPart(int idComp, const vxLongPath File, const vxRootName Part);

    /**
    @ingroup zwapi_asm_opts

    Check the specified component from compPath is a lightweight component or not.

    @param [in] compPath pick path of component in active file
    @param [out] isLightweight the status of specified component, 1 is lightweight and else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxCompIsLightweightByPath(const svxEntPath *compPath, int *isLightweight);

    /**
    @ingroup zwapi_asm_opts

    Set the components to be lightweight loading or not, this function tries to upgrade the loading status even if failed
    in some components.

    @param [in] compPaths pick paths of component in active file
    @param [in] compCount count of compPaths
    @param [in] load 0-make the components be light-weight loading, 1-load the components
    @param [in] isRecursive 1 if load the components recursively, else 0, the option is used when load=1

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxCompLightweightSetByPath(const svxEntPath *compPaths, int compCount, int load, int isRecursive);

    /**
    @ingroup zwapi_asm_opts

    Set component render mode.

    @param [in] CompPath pick path of component
    @param [in] RenderMode render mode

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxCompSetRenderMode(svxEntPath *CompPath, evxRenderMode RenderMode);

    /**
    @ingroup zwapi_asm_opts

    Moves sub-components of a selected component up to the active part.
    Also merges top-level geometry and/or alignments associated with the
    specified component (idComp) into the active part.

    @param [in] idComp component id

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
    extern evxErrors cvxCompShift(int idComp);

    /**
    @ingroup zwapi_asm_opts

    Suppress or unsuppress the specified component. idComp is the component of the top assembly.

    @see cvxCompSuppressByPath() to suppress the some components by the entity path.

    @param [in] idComp component id
    @param [in] suppress 1-suppress, 0-unsuppress

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompSuppress(int idComp, int suppress);

    /**
    @ingroup zwapi_asm_opts

    Suppress or unsuppress the specified components. CompPaths is some components from 
    different depth assembly.

    @see cvxCompSuppress() to suppress the sepicified component by id.

    @param [in] Count count of input components
    @param [in] CompPaths  pick-path of component
    @param [in] suppress 1-suppress, 0-unsuppress

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompSuppressByPath(int Count, svxEntPath *CompPaths, int suppress);

    /**
    @ingroup zwapi_asm_opts

    Set the visibility of specified component.

    @param [in] CompPath pick-path of component
    @param [in] Vis 1-visible, 0-blank

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompVisSet(svxEntPath *CompPath, int Vis);

    /**
    @ingroup zwapi_asm_opts

    Set the id of the specified component configuration.

    @param [in] path pick path of component
    @param [in] idCfg config id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxCompCfgIdSet(const svxEntPath *path, int idCfg);

    //====================================================================================================================
    /** @name Constraint Operations */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_opts

    Launches interactive redefinition of the specified assembly constraint.

    @param [in] idCons index of constraint

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_ONJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxConsRedefine(int idCons);

    /**
    @ingroup zwapi_asm_opts

    Enable or disable the specified constraints.

    @param [in] count count of constraints
    @param [in] idCons list of constraint ids
    @param [in] enable 1-enable, 0-disable

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
    extern evxErrors cvxConsEnable(int count, int *idCons, int enable);

    /**
    @ingroup zwapi_asm_opts

    Delete the specified constraints.

    @param [in] count count of constraints
    @param [in] idCons list of constraint ids

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
    extern evxErrors cvxConsDel(int count, int *idCons);

    //====================================================================================================================
    /** @name sub-part */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_opts

    Inserts and activates a sub-part in the active part.
    If "Name" is a blank string, a default name is assigned to the new sub-part.
    Use cvxPartExit() to exit the sub-part, re-activating its parent part.

    @note
    If "Name" is the name of an existing sub-part in the active part,
    the existing sub-part is activated.

    @param [in] Name sub-part name
    @param [in] AutoRegen 1 to tag sub-part for automatic regeneration, else 0
    @param [in] MergeDimen  1 to merge sub-part dimensions,
                            2 to merge sub-part wireframe entities,
                            3 to merge both (0 to merge neither dimensions nor wireframe

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
    extern evxErrors cvxSubPartIns(const vxRootName Name, int AutoRegen, int MergeDimen);

    /**
    @ingroup zwapi_asm_opts

    set text to specified component's Ecad_RefDes on assembly tree manager .

    @param [in] compPath specified component to set
    @param [in] text text set on Ecad_RefDes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INPUT_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxAsmTreeEcadRefDesSet(const svxEntPath *compPath, const char *text);

    /**
    @ingroup zwapi_asm_opts

    make component which is an assembly flexible in assembly.

    @note
    you can't set the component to flexible across levels.
    e.g.
    @verbatim
    A__     If A.Z3ASM is the active file, the component you can set to flexible is B.Z3ASM.
    |  |    If you want to set D.Z3ASM, you need to activate to B.Z3ASM first, then call this function.
    B  C
    |
    D
    |
    E
    @endverbatim

    if you want to make component which is a part flexible in assembly, @see cvxAsmFlexiblePartSet
    @param [in] compPath specified component to make flexiable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxAsmFlexibleAsmSet(const svxEntPath *compPath);

    /**
    @ingroup zwapi_asm_opts

    make component which is a part flexible in assembly.

    @note
    you can't set the component to flexible across levels.
    e.g.
    @verbatim
    A__     If A.Z3ASM is the active file, the component you can set to flexible is C.Z3PRT.
    |  |    If you want to set D.Z3PRT, you need to activate to B.Z3ASM first, then call this function.
    B  C
    |
    D
    @endverbatim

    if you want to make component which is a part flexible in assembly, @see cvxAsmFlexibleAsmSet

    @param [in] compPath specified component to make flexible
    @param [in] flexDesignData flexible design data to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxAsmFlexiblePartSet(const svxEntPath *compPath, svxAsmFlexDesignData flexDesignData);

    /**
    @ingroup zwapi_asm_opts

    get text from specified component's Ecad_RefDes on assembly tree manager.

    @param [in] compPath specified component to set
    @param [out] text text get on Ecad_RefDes
    @param [in] nbytes size of text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INPUT_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxAsmTreeEcadRefDesGet(const svxEntPath *compPath, char *text, int nbytes);

    /**
    @ingroup zwapi_asm_opts

    Set the auto regen state of specific components by svxEntPath.

    @param [in] compPath svxEntPath of component.
    @param [in] autoRegen the auto regen of the component.(0-None 1-Before assembly regen 2-After assembly regen)

    @note
    Use cvxEntPathInqActive(),cvxEntPathAppendPath() to get a correct svxEntPath.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxAsmAutoRegenStateSetByPath(const svxEntPath *compPath, int autoRegen);

    /**
    @ingroup zwapi_asm_opts

    Get the auto regen state of specific components by svxEntPath.

    @param [in] componentId id of component
    @param [out] autoRegen the auto regen of the component.(0-None 1-Before assembly regen 2-After assembly regen)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxAsmAutoRegenStateGetByPath(const svxEntPath *compPath, int *autoRegen);

    /**
    @ingroup zwapi_asm_opts

    Regenerate the assembly tree nodes and refresh the ui.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxAsmTreeRegen();

    /**
    @ingroup zwapi_asm_opts

    Get flexible data from specified component.

    @note
    The calling procedure MUST deallocate the output varList with cvxAsmFlexiblePartDataFree.

    @param [in] compPath specified component to make flexible
    @param [out] flexDesignData flexible design data to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxAsmFlexiblePartGet(const svxEntPath *compPath, svxAsmFlexDesignData *flexDesignData);

    /**
    @ingroup zwapi_asm_opts

    Free the assemble flexible data.

    @param [in] flexDesignData flexible design data to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxAsmFlexiblePartDataFree(svxAsmFlexDesignData *flexDesignData);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_ASM_OPTS_H */
