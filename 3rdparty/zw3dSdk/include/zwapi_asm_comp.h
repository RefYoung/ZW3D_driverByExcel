/**
@file zwapi_asm_comp.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Component Query API
Including query the components of the assembly, component's part/state
and query the objects of the component etc..
*/
/**
@defgroup zwapi_asm_comp Assembly Component API
@ingroup AssemblyObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Component Query API
Including query the components of the assembly, component's part/state
and query the objects of the component etc..
*/

#pragma once
#ifndef ZW_API_ASM_COMP_H /* this ifndef surrounds entire header */
#define ZW_API_ASM_COMP_H

#include "zwapi_asm_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Assembly */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_comp

    Outputs a list of indices of the assembly folders in the specified assembly file.

    The assembly file does not exist by default and can only be obtained after the user create it.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] File object file name (File[0]=0 or NULL for active file)
    @param [in] Part root object name (Part[0]=0 or NULL for active target object)
    @param [in] type folder type (0: component folder; 1: cosntraint folder; 2: feature folder)
    @param [out] count number of assembly folders
    @param [out] Folders list of assembly folders

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartInqAsmFolders(const vxLongPath File, const vxRootName Part, int type, int *count, int **Folders);


    /**
    @ingroup zwapi_asm_comp

    Outputs a list of indices of the entities in the specified assembly folder.

    The idFolder can be obtained through the cvxPartInqAsmFolders interface.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] File   object file name (File[0]=0 or NULL for active file)
    @param [in] Part   root object name (Part[0]=0 or NULL for active target object)
    @param [in] idFolder  index of assembly folder
    @param [in] incSubFld    0 exclude sub folders; 1 include sub folders; 2 only sub folders
    @param [out] count    number of entities in specified assembly folder
    @param [out] Ents  list of entities in specified assembly folder

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartInqAsmFldChildEnts(const vxLongPath File, const vxRootName Part, int idFolder, int incSubFld, int *count, int **Ents);

    //====================================================================================================================
    /** @name Assembly Feature */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_comp

    Outputs a list of database id's of assembly features in the specified part.
    If there are no features, "*Count" is output as zero and "*Features" as NULL.

    This function allocates memory for the array output via "Features". The calling
    procedure is responsible for deallocating the memory with cvxMemFree().

    @param [in] File   object file name (File[0]=0 or NULL for active file)
    @param [in] Part   part/root object name (Part[0]=0 or NULL for active target object)
    @param [out] Count   number of assembly features in the specified part
    @param [out] Features   list of id's of assembly features in the specified part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartInqAsmFtrList(const vxLongPath File, const vxRootName Part, int *Count, int **Features);

    //====================================================================================================================
    /** @name Query Components */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_comp

    Outputs a list of indices of the components that belong
    to the specified part.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] File part file name (File[0]=0 or NULL for active file)
    @param [in] Part part/root name (Part[0]=0 or NULL for active part)
    @param [out] Count number of components
    @param [out] Comps list of component id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartInqComps(const vxLongPath File, const vxRootName Part, int *Count, int **Comps);

    /**
    @ingroup zwapi_asm_comp

    According to the Option to output a list of indices of the components
    that belong to the specified part.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] File part file name (File[0]=0 or NULL for active file)
    @param [in] Part part name (Part[0]=0 or NULL for active part)
    @param [in] Option 1 for filter suppressed components, otherwise for 0
    @param [out] Count number of components
    @param [out] Comps list of component id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartInqComps2(const vxLongPath File, const vxRootName Part, int Option, int *Count, int **Comps);

    /**
    @ingroup zwapi_asm_comp

    Outputs 2 lists of path and root object name of the components that belong
    to the specified part.

    The difference between cvxPartInqComps() and cvxPartInqCompsInfo() is
    cvxPartInqComps() just get the file name and part name,
    and cvxPartInqCompsInfo() get the path(include file name) and part name.

    @note
    Just file name output as the path if the components haven't been saved.
    The calling procedure MUST deallocate the output lists.

    @code
      cvxMemFree((void**)Paths);

      cvxMemFree((void**)Names);
    @endcode

    @param [in] Path full file path (Null to the active file)
    @param [in] Name root object name (Null to all root objects)
    @param [out] Count number of components
    @param [out]  Paths list of components' path
    @param [out]  Names list of components' root object name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartInqCompsInfo(const vxPath Path, const vxRootName Name, int *Count, vxPath **Paths, vxRootName **Names);

    /**
    @ingroup zwapi_asm_comp

    Outputs 2 lists of path and root object name of the components that belong
    to the specified part.

    The difference between cvxPartInqComps() and cvxPartInqCompsInfo() is
    cvxPartInqComps() just get the file name and part name,
    and cvxPartInqCompsInfo() get the path(include file name) and part name.

    @note
    Just file name output as the path if the components haven't been saved.
    The calling procedure MUST deallocate the output lists.

    @code
      cvxMemFree((void**)Paths);

      cvxMemFree((void**)Names);
    @endcode

    @param [in] Path full file path (Null to the active file)
    @param [in] Name root object name (Null to all root objects)
    @param [out] Count number of components
    @param [out]  Paths list of components' path
    @param [out]  Names list of components' root object name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartInqCompsInfoByLongPath(const vxLongPath Path, const vxRootName Name, int *Count, vxLongPath **Paths, vxRootName **Names);

    /**
    @ingroup zwapi_asm_comp

    Traverse all pick-paths of components start with CompPath and store them into lstPath.

    The memory referenced by "lstPath" is allocated by this function.
    The calling procedure is responsible to free it (cvxMemFree((void**)lstPath)).

    @param [in] CompPath pick-path to start traversal, NULL to traverse current active part
    @param [in] Depth depth of traversing, -1 to traverse all pick paths
    @param [in] IgnoreHidden whether to ignore the hidden and suppressed components
    @param [out] PathCnt number of component paths
    @param [out] lstPath list of component paths

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxCompInqPaths(svxEntPath *CompPath, int Depth, int IgnoreHidden, int *PathCnt, svxEntPath **lstPath);

    //====================================================================================================================
    /** @name Component's Part */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_comp

    Gets the names of the file and part referenced by the
    specified component.

    @see cvxCompInqPartByPath

    @param [in] idComp id of component in active file
    @param [out] File name of the file instanced by the component
    @param [in] nFileBytes string size of file name
    @param [out] Part name of the part instanced by the component
    @param [in] nPartBytes string size of part name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxCompInqPart(int idComp, char *File, int nFileBytes, char *Part, int nPartBytes);

    /**
    @ingroup zwapi_asm_comp

    Gets the names of the file and part referenced by the 
    pick path of specified component.

    @see cvxCompInqPart

    @param [in] CompPath pick path of component in active file
    @param [out] fileName name of the file instanced by the component
    @param [out] partName name of the part instanced by the component

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_aPI_ENT_PATH_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxCompInqPartByPath(const svxEntPath *CompPath, vxPath fileName, vxRootName partName);

    /**
    @ingroup zwapi_asm_comp

    Gets the names of the file and part referenced by the
    pick path of specified component.

    A fileName that is too long (longer than "sizefile") is truncated.

    It is assumed that the input "fileName" is no longer than 512 bytes.

    @param [in] CompPath pick path of component in active file
    @param [out] fileName name of the file instanced by the component
    @param [in] sizeDir max size of fileName
    @param [out] partName name of the part instanced by the component

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_aPI_ENT_PATH_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxCompInqPartByPathByLongPath(const svxEntPath *CompPath, char *fileName, int sizeDir, vxRootName partName);

    /**
    @ingroup zwapi_asm_comp

    Get the file names and part names in the active assembly or part.  This function determines
    the number of unique parts referenced by the active assembly or part and assigns that value
    to *Count, then allocates arrays of that size for BinName and RootName, and fills them with
    the referenced parts' file names and root names, respectively.

    The caller is responsible for freeing the output arrays with the cvxMemFree() function.

    If an error occurs, *Count will be 0, but either or both BinName and RootName might be a non-NULL
    pointer to an array that the caller must free.

    @param [out] Count the number of names in each output array
    @param [out] BinName array of "*Count" files referenced by active part
    @param [out] RootName array of "*Count" part names referenced by active part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxCompGetRefPart(int *Count, vxPath **BinName, vxRootName **RootName);

    /**
    @ingroup zwapi_asm_comp

    Get the file names and part names in the active assembly or part.  This function determines
    the number of unique parts referenced by the active assembly or part and assigns that value
    to *Count, then allocates arrays of that size for BinName and RootName, and fills them with
    the referenced parts' file names and root names, respectively.

    The caller is responsible for freeing the output arrays with the cvxMemFree() function.

    If an error occurs, *Count will be 0, but either or both BinName and RootName might be a non-NULL
    pointer to an array that the caller must free.

    @param [out] Count the number of names in each output array
    @param [out] BinName array of "*Count" files referenced by active part
    @param [out] RootName array of "*Count" part names referenced by active part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxCompGetRefPartByLongPath(int *Count, vxLongPath **BinName, vxRootName **RootName);


    //====================================================================================================================
    /** @name Component's State */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_comp

    Determine whether the component is flexible.

    @see cvxPartInqAsmIsFlexByPath

    @param [in] idComp index of component
    @param [out] isFlexible 1 if flexible; 0 if not

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqAsmIsFlex(int idComp, int *isFlexible);

    /**
    @ingroup zwapi_asm_comp

    Determine whether the component is flexible.

    @param [in] AsmPath pick-path of component
    @param [out] isFlexible 1 if flexible; 0 if not

    @see cvxPartInqAsmIsFlex

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_APPI_ENT_PATH_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqAsmIsFlexByPath(svxEntPath AsmPath, int *isFlexible);

    /**
    @ingroup zwapi_asm_comp

    Outputs the suppress state of specified component.  
    1-suppressed 0-unsuppressed.

    @param [in] idComp component id
    @param [out] suppress the component suppress state

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxCompSuppressGet(int idComp, int *suppress);

    /**
    @ingroup zwapi_asm_comp

    Outputs the suppress state of specified component path.  
    1-suppressed 0-unsuppressed.

    @param [in] path component path
    @param [out] suppress the component suppress state

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_OBJ
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxCompSuppressGetByPath(svxEntPath *path, int *suppress);

    /**
    @ingroup zwapi_asm_comp

    Get all the component object visibility of active part and encode the pick path and mode.

    The caller is responsible for releasing the memory.

    @param [out] nSize number of int in ppath_mode
    @param [out] ppath_mode sum,cnt,pick_path,mode,cnt,pick_path ,mode...

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxAssemCompVisAll(int *nSize, int **ppath_mode);

    /**
    @ingroup zwapi_asm_comp

    Get the visibility of specified component.

    @see cvxAssemCompVisAll

    @param [in] CompPath pick-path of component
    @param [out] Vis 1-visible, 0-blank

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_APPI_ENT_PATH_ERROR
    */
    extern evxErrors cvxCompVisGet(svxEntPath *CompPath, int *Vis);

    /**********************************************************************
    *! -Blank/Unblank- : zwapi_asm_opts.h
    *  extern int cvxCompVisSet(svxEntPath* CompPath, int Vis);
    **********************************************************************/
    /**
    @ingroup zwapi_asm_comp

    Highlights the specified component.

    @param [in] CompPath pick-path of component
    @param [in] color color of object to display (NULL to use default)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern void cvxCompHighlight(svxEntPath *CompPath, svxColor *color);

    /**
    @ingroup zwapi_asm_comp

    Un-Highlight the specified component.

    @param [in] CompPath pick-path of component

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern void cvxCompUnHighlight(svxEntPath *CompPath);

    /**
    @ingroup zwapi_asm_comp

    Make a component into a virtual component.

    @param [in] CompPath pick path of component

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompMakeVirtual(svxEntPath *CompPath);

    /**
    @ingroup zwapi_asm_comp

    Judge whether a component is a virtual component.

    @param [in] CompPath pick path of component
    @param [out] isVirtual true if component is virtual

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxCompIsVirtual(svxEntPath *CompPath, int *isVirtual);

    /**
    @ingroup zwapi_asm_comp

    Judge whether a component is envelope.

    @param [in] compPath entity path of component
    @param [out] isEnvelope 1 if component is envelope, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxCompIsEnvelope(const svxEntPath *compPath, int *isEnvelope);

    /**
    @ingroup zwapi_asm_comp

    Get component render mode.

    @param [in] CompPath pick path of component
    @param [out] RenderMode render mode

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ENT_PATH_ERROR
    */
    extern evxErrors cvxCompInqRenderMode(svxEntPath *CompPath, evxRenderMode *RenderMode);

    /**********************************************************************
    *! -Display- : zwapi_asm_opts.h
    *  extern int cvxCompSetRenderMode(svxEntPath* CompPath, evxRenderMode RenderMode);
    **********************************************************************/

    /**
    @ingroup zwapi_asm_comp

    Get component unplaced state.

    @see cvxCompIsUnplacedByPath

    @param [in] idx_Comp index of component
    @param [out] isUnplaced component unplaced state(1 is unplaced, else 0.)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERRORS
    */
    extern evxErrors cvxCompIsUnplaced(int idx_Comp, int *isUnplaced);

    /**
    @ingroup zwapi_asm_comp

    Get component unplaced state by pick-path.

    @see cvxCompIsUnplaced

    @param [in] path pick path of component
    @param [out] isUnplaced 1 is unplaced, 0 is not unplaced

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_tYPE_ERROR
    */
    extern evxErrors cvxCompIsUnplacedByPath(const svxEntPath *path, int *isUnplaced);

    /**
    @ingroup zwapi_asm_comp

    Determine whether the component file is missing.

    @param [in] path path of component
    @param [out] isFileLost 1= file is lost; 0= file is not lost.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxCompIsFileLost(const svxEntPath *path, int *isFileLost);

    /**
    @ingroup zwapi_asm_comp

    Check whether the specified node is expanded.

    @param [in] path component path
    @param [out] isExpand 1 is expand state, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_TYPE_ERROR
    */
    extern evxErrors cvxCompExpandStateGet(const svxEntPath *path, int *isExpand);

    /**
    @ingroup zwapi_asm_comp

    Update whether the specified node's expanded status.

    @param [in] path component path
    @param [in] expand 1 is expanded state ; 0 is collapsed state.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxCompExpandStateSet(const svxEntPath *path, int expand);

    /**
    @ingroup zwapi_asm_comp

    Check whether the specified node is selected.

    @param [in] path component path
    @param [out] isSelected 1 is selected, 0 is non-selected

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxCompSelectedStateGet(const svxEntPath *path, int *isSelected);

    /**
    @ingroup zwapi_asm_comp

    Update whether the specified node's selected status.

    @warning
    Because this function has an internal call to the "cvxDispRedraw()" function,
    it must be called on the main thread.

    @param [in] path component path
    @param [in] selected 1 is selected state ; 0 is non-selected state.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxCompSelectedStateSet(const svxEntPath *path, int selected);

    /**
    @ingroup zwapi_asm_comp

    Outputs the Exclude state of specified component.
    1-excluded 0-included.
    The 3D BOM table allows user to exclude and include components.

    @param [in] EntPath component pick path
    @param [out] exclude the component Exclude state

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ENT_PATH_ERROR
    */
    extern evxErrors cvxCompBomExcludedGet(svxEntPath EntPath, int *exclude);

    /**
    @ingroup zwapi_asm_comp

    Get the display content of the 3D BOM table through the interface.

    @param [out] data  settings data of 3d bom table

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_FORM_CREATE_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FORM_INIT_ERROR
    -        ZW_API_TABLE_GETDATA_ERROR
    */
    extern evxErrors cvxCompBomSettingGet(svx3DBomSettingsData *data);

    /**
    @ingroup zwapi_asm_comp

    Set the display content of the 3D BOM table through the interface.

    @param [in] data  settings data of 3d bom table

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_FORM_CREATE_FAIL
    -        ZW_API_FUCNTION_CB_EXECUTION_ERROR
    -        ZW_API_FUNCTION_CB_GET_ERROR
    -        ZW_API_FUCNTION_CB_EXIST_ERROR
    -        ZW_API_FORM_INIT_ERROR
    -        ZW_API_TABLE_SETDATA_ERROR
    */
    extern evxErrors cvxCompBomSettingSet(svx3DBomSettingsData *data);

    /**
    @ingroup zwapi_asm_comp

    Get row infos for display in bom table.
    The calling procedure MUST deallocate the output list with cvxBomDataFree.

    @param [out] data  table data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_FORM_INIT_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_TABLE_GETDATA_ERROR
    */
    extern evxErrors cvxCompBomDispDataGet(svx3DBomData *data);

    /**
    @ingroup zwapi_asm_comp

    Frees memory associated with the specified svx3DBomData structure.

    @param [in,out] data  svx3DBomData structure

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxBomDataFree(svx3DBomData *data);

    /**
    @ingroup zwapi_asm_comp

    Get the pick path of the specified part in the BOM table.

    @param [in] part  part name in the bom table.
    @param [out] cnt  count of paths
    @param [out] paths  list of path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_STRING
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_FORM_CREATE_FAIL
    -        ZW_API_FORM_INIT_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCompBomPathByPart(const vxLongName part, int *cnt, svxEntPath **paths);

    /**
    @ingroup zwapi_asm_comp

    Flags the input component to regen (Regen=1) or not regen (Regen=0)
    the part it instances when the it's parent part is regenerated.

    The specified component (idComp) should belong to the active part.

    @param [in] idComp component entity id
    @param [in] Regen 1 to enable component regen; 0 to disable it

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
    extern evxErrors cvxCompRegenSet(int idComp, int Regen);

    /**********************************************************************
    * *! -Dissolve Assembly- : zwapi_asm_opts.h
    *  extern int cvxAsmDissolve(const svxEntPath* path);
    **********************************************************************/

    //====================================================================================================================
    /** @name Component Query */
    //====================================================================================================================

    /**
    @ingroup zwapi_asm_comp

    Output specified transformation matrix by pick-path. 
    This interface can be used to query the matrix of flexible assembly.

    @param [in] AsmPath pick-path of assembly
    @param [out] AsmMat transformation matrix of assembly

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ENT_PATH_ERROR
    */
    extern evxErrors cvxPartInqFlexAsmMat(svxEntPath AsmPath, svxMatrix *AsmMat);

    /**
    @ingroup zwapi_asm_comp

    Get the open shapes in input components or shape.

    @param [in] CompPath pick path of the component/shape in the component, NULL to check all components
    @param [in] IgnoreHide whether to ignore hidden components and hidden shapes(1 is ignore hidden, 0 is not ignore hidden)
    @param [out] numShps number of open shapes
    @param [out] shpPaths pick-paths of open shapes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCompInqOpenShapes(svxEntPath *CompPath, int IgnoreHide, int *numShps, svxEntPath **shpPaths);

    /**
    @ingroup zwapi_asm_comp

    Get the open edges of the input shape.

    @param [in] ShpPath pick path of the shape in the component
    @param [out] numEdg number of open edges
    @param [out] edgPaths path of open edges

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCompShapeInqOpenEdges(svxEntPath *ShpPath, int *numEdg, svxEntPath **edgPaths);

    /**
    @ingroup zwapi_asm_comp

    Get the id of the specified component configuration.

    @param [in] path pick path of component
    @param [out] idCfg config id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxCompCfgIdGet(const svxEntPath *path, int *idCfg);

    /**
    @ingroup zwapi_asm_comp

    Insert components to a new folder using specific name (null to use default name).

    Make sure all the components belong to the same parents.
    Folder' ids are consisted of start and end, idFolder returns folder start id.

    @param [in] cnt count of component
    @param [in] idCom id of component
    @param [in] folderName folder name(fileName[0]=0 or NULL for default name)
    @param [out] idFolder id of folder(pass in NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxCompFolderIns(int cnt, const int *idCom, const vxLongName folderName, int *idFolder);

    /**********************************************************************
    * *! -Configurations- : zwapi_asm_opts.h
    *  extern int cvxCompCfgIdSet(const svxEntPath* path, int idCfg);
    **********************************************************************/

    /**
    @ingroup zwapi_asm_comp

    Determine whether component are generated through assembly feature.

    The cvxPartInqEntFtr interface can obtain the feature id through the component id.

    The cvxPartInqFtrTemplate interface can obtain the template command of the 
    feature and determine the feature type through the template command.

    @verbatim
    Asm Feature Type | Template Command
    assembly pattern | AsmPtnAll
    assembly mirror  | AsmMirrorAll
    pulley           | AsMcmPulley
    spur gear        | CdSpurGear
    bevel gear       | CdBevelGear
    @endverbatim

    @param [in] path  pick path of component
    @param [out] isFromAsmFtr  1 if this component is from assembly feature. else 0.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_ENT_PATH_ERROR
    */
    extern evxErrors cvxCompFromAsmFtr(svxEntPath *path, int *isFromAsmFtr);

    //====================================================================================================================
    /** @name Assembly Reorder */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_comp

    Reorder the specified assembly object. the function only modifies the order of objects in the assembly
    tree and does not add new objects. if the previous entity (idPreEnt) is a group folder object, the
    location refers to the specified folder, otherwise, the location refers to the assembly tree.

    @param [in] fileName file name (fileName[0] = 0 or NULL for active file)
    @param [in] rootName part name (rootName[0] = 0 or NULL for active file or single object file)
    @param [in] idEnt index of entity to reorder (component, assembly feature, assembly constraint are support)
    @param [in] reorderLoc reorder location method
    @param [in] idPreEnt index of the previous entity (0 to ignore, component, assembly feature, assembly constraint, group folder are support)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxAsmReorder(const vxLongPath fileName, const vxRootName rootName, int idEnt, evxReorderLoc reorderLoc, int idPreEnt);

    //====================================================================================================================
    /** @name sub-part */
    //====================================================================================================================
    /**
    @ingroup zwapi_asm_comp

    If "isSubPart = 1", the specified part is flagged as a sub-part. It will be
    skipped when gathering parts for a BoM or assembly-part-list.  It will not be
    displayed in the parent file's root object list.

    If "isSubPart = -1", the specified part is flagged as a pseudo sub-part. It is
    hidden in the root object list, but is still counted as a free-standing part
    for BoM or assembly-part-list purposes.

    If "isSubPart = 0", the part is assumed to be a standalone part (i.e. not a
    sub-part inextricably linked to its parent part).

    Generally speaking, this function should not be used to change the status of
    a genuine sub-part unless you 100% know what you are doing, but it may be used
    to suppress display of a regular part in the root object list (isSubPart = -1).

    @note
    This interface had been discarded because the platform can no longer support this operation.
    If there is a need to get a sub-part, use cvxSubPartIns() to do it.

    @param [in] File part file name (File[0]=0 or NULL for active file)
    @param [in] Part part name (Part[0]=0 or NULL for active part)
    @param [in] isSubPart 1=sub-part; 0=ordinary part; -1=ordinary part hidden in
                root object list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxSubPartFlag(const vxLongPath File, const vxRootName Part, int isSubPart);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_ASM_COMP_H */
