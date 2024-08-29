/**
@file zwapi_root.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Root API
*/
/**
@defgroup zwapi_root File Root
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D Root API
*/

#pragma once
#ifndef Zw_API_ROOT_H /* this ifndef surrounds entire header */
#define Zw_API_ROOT_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Root Edit Data */
    //====================================================================================================================
    /**
    @brief root object type
    @ingroup zwapi_root
    */
    typedef enum evxRootType
    {
        VX_ROOT_NULL         = 0,
        VX_ROOT_PART         = 89,            /**<@brief  part */
        VX_ROOT_PART_NEW     = -VX_ROOT_PART, /**<@brief  part */
        VX_ROOT_SHEET        = 90,            /**<@brief  sheet */
        VX_ROOT_DRAWING      = 91,            /**<@brief  drawing */
        VX_ROOT_SKETCH       = 70,            /**<@brief  sketch */
        VX_ROOT_EQUATION_SET = 121,           /**<@brief  eqution set */
        VX_ROOT_CAM_PLAN     = 200            /**<@brief  cam plan */
    } evxRootType;

    //====================================================================================================================
    /** @name Root Query Data */
    //====================================================================================================================
    /**
    @brief root object preview mode
    @ingroup zwapi_root
    */
    typedef enum evxPreviewMode
    {
        VX_PREVIEW_OFF    = 0, /**<@brief  off */
        VX_PREVIEW_GEOM   = 1, /**<@brief  geom */
        VX_PREVIEW_ATTRIB = 2  /**<@brief  attribute */
    } evxPreviewMode;

    //====================================================================================================================
    /** @name Root Activate */
    //====================================================================================================================
    /**
    @ingroup zwapi_root

    Activates the specified root object in the active file for editing.

    @param [in] Name root object name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_CMMD_INIT_ERROE
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxRootActivate(vxRootName Name);

    /**
    @ingroup zwapi_root

    Activates the root object specified by "File" and "Root" as the  
    target object and backs up information about the current target  
    object to an internal stack (up to 16 calls deep).

    This function will activate the specified file in the memory and  
    the target object will be activated. cvxFileActivate() will activate  
    the file and open it in the window.

    When this function is called with "File=NULL" and "Root=NULL",  
    the last target object on the stack is restored.  The calling  
    application MUST reliably pair calls to this function to set  
    and restore target objects.

    When this function is called with "File="*" and "Name=NULL",  
    the stack is cleared.

    @verbatim
    for example:
    ...(coding)
    cvxRootActivate2(File,Name);
    ...(coding)
    ...(when no code is needed to execute in the current environment, the interface closure file needs to be called again)
    cvxRootActivate2(NULL,NULL);
    ...(coding)
    @endverbatim

    @note
    If cvxRootActivate2(NULL,NULL) is not called,unpredictable errors can occur.

    @param [in] File root object file
    @param [in] Name root object name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxRootActivate2(const vxLongPath File, const vxRootName Name);

    /**
    @ingroup zwapi_root

    Activates the root object specified by "File" and "Name" as the  
    target object and backs up information about the current target  
    object to an internal stack (up to 16 calls deep).

    When this function is called with "File=NULL" and "Name=NULL",  
    the last target object on the stack is restored.  
    When this function is called with "File="*" and "Name=NULL",  
    the stack is cleared.

    The calling application MUST reliably pair calls to this function to set  
    and restore target objects.

    @verbatim
    for example:
    ...(coding)
    cvxRootActivateLoadAsmCtx(File,Name,1);
    ...(coding)
    ...(when no code is needed to execute in the current environment, the interface closure file needs to be called again)
    cvxRootActivateLoadAsmCtx(NULL,NULL,1);
    ...(coding)
    @endverbatim

    @note
    If cvxRootActivateLoadAsmCtx(NULL,NULL,) is not called,unpredictable errors can occur.  
    cvxRootActivateLoadAsmCtx(File,Name,0) and cvxRootActivate2(File,Name) have the same function.

    @param [in] File root object file
    @param [in] Name root object name
    @param [in] isLoad 1 is load assembly context data, 0 is not load

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxRootActivateLoadAsmCtx(const vxLongPath File, const vxRootName Name, int isLoad);

    //====================================================================================================================
    /** @name Root Edit */
    //====================================================================================================================
    /**
    @ingroup zwapi_root

    Creates and inserts a root object of the specified type  
    in the active file.   It becomes the active object for
    editing.

    @note
    User need to call cvxRootExit() after one root  
    object is added if inserts two root objects at the  
    same time, for example:  
    @code
       err1 = cvxRootAdd(VX_ROOT_PART, "Part001", NULL);
       cvxRootExit();
       err2 = cvxRootAdd(VX_ROOT_PART, "Part002", NULL);
    @endcode
    An optional template object name may be input for a part,  
    sheet or plan.  If it is specified, the new root object  
    is a copy of the template object.  It is assumed that  
    the template object resides in the template file registered  
    with cvxRootTemplateFile() before this function is called.

    @param [in] Type root object type
    @param [in] Name root object name
    @param [in] Template optional template object name (or NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxRootAdd(evxRootType Type, vxRootName Name, const char *Template);

    /**
    @ingroup zwapi_root

    The function is same as cvxRootAdd() but add a parameter Description to add  
    description for part

    @param [in] Type root object type
    @param [in] Name root object name
    @param [in] Template optional template object name (or NULL)
    @param [in] Description optional object description (or NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxRootAdd2(evxRootType, vxRootName Name, const char *Template, char *Description);

    /**
    @ingroup zwapi_root

    Adds a root object into the "background" of the active file -- that is, the new root object  
    is not displayed in the file's root object list. If a root object with the input name already  
    exists in the active file, a new root object is not added.

    Presently, this function only supports part objects (Type = VX_ROOT_PART).

    @param [in] Type root object type (presently only VX_ROOT_PART is supported)
    @param [in] Name part name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    @retval other
    -        2 - if a root object with the specified name already exists
    */
    extern int cvxRootAdd2Bg(evxRootType Type, vxRootName Name);

    /**
    @ingroup zwapi_root

    Copies the specified root object from "SourceFile" to "DestFile".  
    Both files must already exist and must reside in one of the  
    directories specified in "vxpaths" (see cvxPathAdd() and  
    cvxPathSearchFirst()).

    Normally, when a root object is copied, the unique id's in the copied  
    object are the same as the original object.  When "UpdateUid=1", the  
    the unique id's of the copied object are updated so they are different  
    from the original object.  You should input "UpdateUid=0", unless you  
    have a specific purpose for generating copies with different unique id's.  
    In normal usage, ZW3D is able to differentiate entities in a copied object  
    from the original object without changing unique id's.

    @param [in] SourceFile name of file to copy from
    @param [in] SourceName name of root object in source file
    @param [in] DestFile name of file to copy to
    @param [in] DestName name to assign copied root object
    @param [in] Overwrite 0 = upgrade DestName to avoid naming conflict,  
                          1 = prompt before overwriting existing object.  
                          -1 = automatically overwrite existing object.
    @param [in] UpdateUid 1 to make UID's of copied geometry unique, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxRootCopy(const vxLongPath SourceFile, const vxRootName SourceName,
                                 const vxLongPath DestFile, vxRootName DestName, int Overwrite, int UpdateUid);

    /**
    @ingroup zwapi_root

    Deletes the specified root object from the active file.

    @param [in] Name root object name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxRootDel(vxRootName Name);

    /**
    @ingroup zwapi_root

    Exits the active root object to either the parent object
    or the parent file.

    */
    extern void cvxRootExit(void);


    //====================================================================================================================
    /** @name Root Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_root

    Gets the database id of the specified root object (Name) in  
    the active file.  "idRoot = 0" is output if root object is  
    not found.

    @param [in] Name root object name
    @param [out] idRoot root object id
    @param [out] Type root object type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxRootId(vxRootName Name, int *idRoot, evxRootType *Type);

    /**
    @ingroup zwapi_root

    Outputs the name of the active root object.  
    Outputs "Name[0]=0" if there is not an active root object.

    @param [out] Name name of active root object
    @param [in] nBytes string max size of root object name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxRootInqActive(char *Name, int nBytes);

    /**
    @ingroup zwapi_root

    Outputs the name of the top root object in assembly.  
    Outputs "Name[0]=0" if error.

    @param [out] Name name of top root object in assembly
    @param [in] nBytes string max size of root object

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxRootInqAsm(char *Name, int nBytes);

    /**
    @ingroup zwapi_root

    Outputs 1 if the active root object has been modified since it was  
    last activated, otherwise outputs 0.

    @see cvxRootInqModSinceRegen() and cvxFileIsModified().

    @param [out] Mod 1 if active root object has been modified

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -
    */
    extern evxErrors cvxRootInqMod(int *Mod);

    /**
    @ingroup zwapi_root

    Outputs 1 if the specified root object has been modified since it was  
    last activated, otherwise outputs 0.

    @see cvxRootInqModSinceRegen() and cvxFileIsModified().

    @param [in] fileName Z3/VX file name (fileName[0]=0 or NULL for active file)
    @param [in] rootName root object name (rootName[0]=0 or NULL for active object)
    @param [out] mod 1 if active root object has been modified

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -
    */
    extern evxErrors cvxRootInqModByName(const vxLongPath fileName, const vxRootName rootName, int *mod);

    /**
    @ingroup zwapi_root

    Outputs 1 if the active root object has been modified since it was  
    regenerated, otherwise outputs 0.

    @see also cvxRootInqMod() and cvxFileIsModified().

    @param [out] Mod 1 if active root object has been modified since last regen

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -
    */
    extern evxErrors cvxRootInqModSinceRegen(int *Mod);

    /**
    @ingroup zwapi_root

    If "file" is input as NULL, this function gets a list of the symbol names in the active file.

    If the path of a valid ZW3D file is input via "file", this function gets a  
    list of symbol names in the specified file.

    The list referenced by "**names" is allocated by this function and must  
    be deallocated by the calling procedure.  A NULL pointer is output if  
    no data is found.

    @param [in] file file path (pass in NULL if undefined)
    @param [out] iCount number of symbol names
    @param [out] names list of symbol names

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxRootInqSymbol(const vxLongPath file, int *iCount, vxRootName **names);

    /**
    @ingroup zwapi_root

    Get the type of part root object: part or assembly.

    @param [in] File part file name (File[0]=0 or NULL for active file)
    @param [in] Part part name (Part[0]=0 or NULL for active part)
    @param [out] isAsm 1 = Assembly; 0 = Part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxRootIsAsm(const vxLongPath File, const vxRootName Part, int *isAsm);

    /**
    @ingroup zwapi_root

    if "File" is input as NULL, this function gets a list of the names of all  
    the root objects in the active file.

    If the path of a valid ZW3D file is input via "File", this function gets a  
    list of the root objects in the specified file.

    The list referenced by "**Names" is allocated by this function and must  
    be deallocated by the calling procedure.  A NULL pointer is output if  
    no data is found.

    @param [in] File optional ZW3D file path (pass in NULL if undefined)
    @param [out] Count no. of root objects output via "Names"
    @param [out] Names list of root object names

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxRootList(const vxLongPath File, int *Count, vxRootName **Names);

    /**
    @ingroup zwapi_root

    Determine whether a graphical root object preview is enabled.


    @retval return
    -       1 - if a graphical root object preview is enabled.
    -       0 - Otherwise .
    */
    extern evxPreviewMode cvxRootPreviewGet(void);

    /**
    @ingroup zwapi_root

    Displays the specified preview for the specified root object.

    @param [in] Mode preview mode
    @param [in] File file (NULL if VX_PREVIEW_OFF)
    @param [in] Object object (NULL if VX_PREVIEW_OFF)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxRootPreviewSet(evxPreviewMode Mode, const vxLongPath File, vxRootName Object);

    /**
    @ingroup zwapi_root

    Registers the specified object file name as the file from  
    which cvxRootAdd() retrieves template objects.  The file  
    should reside in one of the active search directories  
    (see cvxPathAdd()).  Input NULL or a blank string to  
    use the default template file name (defined in config).

    @param [in] File template object file name (NULL for default name)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxRootTemplateFile(const vxLongPath File);


    //====================================================================================================================
    /** @name File/Root Rename */
    //====================================================================================================================
    /**
    @ingroup zwapi_root

    Renames a root object in the active file.  If "Update" is input  
    as a non-zero value, references to "Name" in the active file are  
    changed to "NewName".

    It's also can be used to rename the 2d sketch block in the active file.

    @note
    Can only rename the root name of .Z3 File.

    @param [in] Name name of root object to rename (in active file)
    @param [in] NewName new name for root object
    @param [in] Update 1 to update references by name, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxRootRename(vxRootName Name, vxRootName NewName, int Update);

    /**
    @ingroup zwapi_root

    Renames a root object in the active file and assigns the specified  
    description to it (if defined).  If "Update" is input as a non-zero  
    value, references to "Name" in the active file are changed to "NewName".  
    Passing in a blank string for "Descript" will clear the current  
    description associated with the specified root object.

    @note
    Can only rename the root name of .Z3 File.

    @param [in] Name name of root object to rename (in active file)
    @param [in] NewName new name for root object
    @param [in] Descript new description for root object (NULL if undefined)
    @param [in] Update 1 to update references by name, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxRootRename2(vxRootName Name, vxRootName NewName, char *Descript, int Update);


    /**
    @ingroup zwapi_root

    Rename the given files and/or root objects. If neither the new file name nor the new root object name
    is specified, the function does nothing and returns ZW_API_INVALID_INPUT.

    In the active file and files referenced by the active file, references to the given names are updated to
    use the new names.

    Renaming a root object with this function clears the object's description.  Refer to cvxRootRename2()
    for a function that can assign a description to a root object while renaming it.

    When files are renamed, a new copy of each file is saved using the new name rather than actually changing
    the name of the original file.  If the fDelOriginal argument is 1, this function deletes the original files
    for which new files have been created.  If fDelOriginal is 0, the original files are preserved.

    If a n error does occur, some files and objects might be renamed and others might
    still have their original names when this function returns.

    @param [in] Count the number of names in each input array
    @param [in] FileName array of "Count" file names or full paths to rename.
                         each file that needs to be renamed must have add file name or full path to the array.
    @param [in] RootName array of "Count" root object names to rename, may be NULL.
                         multi-objects files must specify the root object to be renamed.
                         single-object files do not need to be specified.
    @param [in] NewFileName array of "Count" new file names or full paths, may be NULL.
                            if don't specify new file name, the original file name is used by default.
                            single-object file should always specify new file name.
    @param [in] NewRootName array of "Count" new root object names, may be NULL.
                            if no new root object name is specified for multi-objects file, the original root object name is used by default.
                            single-object files do not need to be specified.
    @param [in] fDelOriginal 1 to delete original files after renaming, 0 to keep them

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxRootRenameMulti(int Count, const vxPath *FileName, const vxRootName *RootName, const vxPath *NewFileName, const vxRootName *NewRootName, int fDelOriginal);
    /**
    @ingroup zwapi_root

    Rename the given files and/or root objects. If neither the new file name nor the new root object name  
    is specified, the function does nothing and returns ZW_API_INVALID_INPUT.

    In the active file and files referenced by the active file, references to the given names are updated to  
    use the new names.

    Renaming a root object with this function clears the object's description.  Refer to cvxRootRename2()  
    for a function that can assign a description to a root object while renaming it.

    When files are renamed, a new copy of each file is saved using the new name rather than actually changing  
    the name of the original file.  If the fDelOriginal argument is 1, this function deletes the original files  
    for which new files have been created.  If fDelOriginal is 0, the original files are preserved.

    If an error does occur, some files and objects might be renamed and others might  
    still have their original names when this function returns.  

    @note
    Normally, this function is used to rename components/roots in the current activate file.  
    Don't use cvxRootActivate2 to active the files you want to rename!!!  
    This function will active them inside.

    @param [in] Count the number of names in each input array
    @param [in] FileName array of "Count" file names or full paths to rename.    
                         each file that needs to be renamed must have add file name or full path to the array.
    @param [in] RootName array of "Count" root object names to rename, may be NULL.    
                         multi-objects files must specify the root object to be renamed.  
                         single-object files do not need to be specified.
    @param [in] NewFileName array of "Count" new file names or full paths, may be NULL.  
                            if don't specify new file name, the original file name is used by default.  
                            single-object file should always specify new file name.
    @param [in] NewRootName array of "Count" new root object names, may be NULL.  
                            if no new root object name is specified for multi-objects file, the original root object name is used by default.  
                            single-object files do not need to be specified.
    @param [in] fDelOriginal 1 to delete original files after renaming, 0 to keep them

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxRootRenameMultiByLongPath(int Count, const vxLongPath *FileName, const vxRootName *RootName, const vxLongPath *NewFileName, const vxRootName *NewRootName, int fDelOriginal);


    //====================================================================================================================
    /** @name Root Variable */
    //====================================================================================================================
    /**
    @ingroup zwapi_root

    Searches the specified root object in the active file  
    for the variable named "Variable->Name".

    The value of the specified variable is output via  
    "Variable->Value" in database units (mm, deg).  
    The "isDistance" parameter is not set by this function.

    If "Variable->Name" is a string variable, the associated  
    text is output via "Variable->Expression".  Strings longer  
    than 256 bytes are truncated.

    @note
    "Variable->Expression" is not used to output the  
    expression that defines a variable.  It is used to output  
    text associated with a "string" variable.

    @param [in] Name root object name
    @param [in,out] Variable variable data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxRootVarGet(vxRootName Name, svxVariable *Variable);

    /**
    @ingroup zwapi_root

    Updates the variables (e.g. dimensions, parameters) specified  
    by "Variables" in the specified root object within the active  
    file.  The root object is then regenerated.

    You can disable the object regeneration normally performed by  
    this function by inputing "Working = -1".

    A field of a history operation's input data is identified by a  
    variable name encoded as follows (brackets included):

          <operation_name:field_number>

    Part attributes may be modified using the following variable names,  
    with the new attribute value or data assigned to the "Expression" field  
    of the "svxVariable" data structure.

          part_number, part_class, part_designer, part_cost, part_supplier  
          part_description, part_keyword, part_manager, part_material  

    User-defined data stored in a part's attributes can be modified  
    using a variable name composed from "part_" and a user-data label.  
    For example, if an item of user data were labeled "my_data", the  
    corresponding variable name would be "part_my_data".  The new user  
    data would be defined via the "Expression" field of the "svxVariable"  
    data structure.

    The part "density" attribute is modified via the variable name "part_density".  
    The new density (kg/mm3) is defined via the "Value" field of the "svxVariable"  
    data structure.

    The color of all faces in a part may be modified via the "part_color"  
    variable with "Expression" set to "Aluminum", "Brass", "Bronze", "Copper",  
    "Silver", "Steel", "Stainless", "Gold", "Gray", "Red", "Green", "Blue",  
    "Brown", "Orange" or RGB values (0-255) encoded as "R.G.B" (e.g. 136.255.0).

    Custom variables :  
    Expression format of string type :"\"str\"";  
    Expression format of point type :"Point(1,2,3)";  
    Expression format of vector type :"Vector(1,2,3)";  

    If the type of variable is set to 0,then the sub_type must be set,else ignore.  
    If the sub_type of variable is set to 1 or 2,then the unit_type must be set,else ignore.

    evxUnitType for length unit and evxAngUnitType for angle unit.

    @param [in] Name root object name
    @param [in] Count number of variables
    @param [in] Var list of variables
    @param [in] Working 1 to display "Working..." message, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxRootVarSet(vxRootName Name, int Count, svxVariable *Var, int Working);


    //====================================================================================================================
    /** @name Root Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_root

    If "Visible = 0", suppress display of the specified  
    root object in the root object browser.

    If "Visible = 1", enable display of the specified  
    root object in the root object browser.

    If is assumed "Name" identifies a valid root object  
    in the active file.

    @param [in] Name root object name
    @param [in] Visible 1 to show; 0 to hide

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_NAME
    */
    extern void cvxRootVisibility(vxRootName Name, int Visible);

    /**
    @ingroup zwapi_root

    Check that whether there is sheet metal in specified part.

    @param [in] file file name (file[0]=0 or NULL for active file)
    @param [in] part part name (part[0]=0 or NULL for active part)
    @param [out] shtMetal whether there is sheet metal in the part (1: exist; 0: NOT exist)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxRootInqSheetMetal(const vxLongPath file, const vxRootName part, int *shtMetal);

    /**
    @ingroup zwapi_root

    Outputs an attribute from a specified root.

    The itemId includes the following items of evxAtItemId:
       VX_AT_USER
       VX_AT_NAME
       VX_AT_NUMBER
       VX_AT_DESIGNER
       VX_AT_MANAGER
       VX_AT_SUPPLIER
       VX_AT_KEYWORD
       VX_AT_DESCRIPT
       VX_AT_START
       VX_AT_END

    When itemId is VX_AT_USER, the name of the user-defined attribute
    must be assigned to at->label before calling this function. For all
    other itemId values, at->label can be an empty string (at->label[0]=0)
    when this function is called.

    If the specified file is not already open, this function will open
    it to access the attribute, and will then close the file. If you
    want to keep the file open, use the cvxFileKeep() function, before
    calling this function, to set a flag that prevents cvxRootAtItemGet()
    and cvxRootAtItemSet() from closing the files that they open. (Files
    that are already open before cvxRootAtItemGet() or cvxRootAtItemSet()
    is called are never closed by these functions.) Keeping files open
    is a more efficient way to access multiple attributes in a file, but
    you must remember to call cvxFileKeep() again to reset the flag after
    you have finished your calls to cvxRootAtItemGet() and cvxRootAtItemSet(),
    and you also become responsible for closing the files, for example by
    using one of the cvxFileClose() or cvxFileSave() functions.

    @param [in] file object file name (file[0]=0 or NULL for active file)
    @param [in] root root object name (root[0]=0 or NULL for active target object)
    @param [in] itemId item id
    @param [in,out] at part item attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOCATE_FAIL
    */
    extern evxErrors cvxRootAtItemGet(const vxLongPath file, const vxRootName root, evxAtItemId itemId, svxAttribute *at);

    /**
    @ingroup zwapi_root

    Sets an attribute value in a specified root.

    The itemId includes the following items of evxAtItemId:
       VX_AT_USER
       VX_AT_NAME
       VX_AT_NUMBER
       VX_AT_DESIGNER
       VX_AT_MANAGER
       VX_AT_SUPPLIER
       VX_AT_KEYWORD
       VX_AT_DESCRIPT

    When itemId is VX_AT_USER, the name of the user-defined attribute
    must be assigned to at->label before calling this function. For all
    other itemId values, at->label can be an empty string (at->label[0]=0)
    when this function is called.

    If the specified file is not already open, this function will open
    it to access the attribute, and will then close the file. If you
    want to keep the file open, use the cvxFileKeep() function, before
    calling this function, to set a flag that prevents cvxRootAtItemGet()
    and cvxRootAtItemSet() from closing the files that they open. (Files
    that are already open before cvxRootAtItemGet() or cvxRootAtItemSet()
    is called are never closed by these functions.) Keeping files open
    is a more efficient way to access multiple attributes in a file, but
    you must remember to call cvxFileKeep() again to reset the flag after
    you have finished your calls to cvxRootAtItemGet() and cvxRootAtItemSet(),
    and you also become responsible for closing the files, for example by
    using one of the cvxFileClose() or cvxFileSave() functions.

    @param [in] file object file name (file[0]=0 or NULL for active file)
    @param [in] root root object name (root[0]=0 or NULL for active target object)
    @param [in] itemId item id
    @param [in] at part item attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOCATE_FAIL
    */
    extern evxErrors cvxRootAtItemSet(const vxLongPath file, const vxRootName root, evxAtItemId itemId, svxAttribute *at);

    /**
    @ingroup zwapi_root

    Set user custom data to a specific root object of an existing ZW3D file.  
    Program will overwrite the first custom data if root object already has custom data.

    @param [in] file ZW3D or VX file name (file[0]=0 or NULL for active file)
    @param [in] objectName root object name (objName[0]=0 or NULL for active object)
    @param [in] data customization data
    @param [in] dataLength length of customization data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxRootCustomDataSet(const vxLongPath file, vxRootName objectName, char *data, int dataLength);

    /**
    @ingroup zwapi_root

    Get the first user custom data from a existing root object of an existing ZW3D file.  
    The list referenced by "**data" is allocated by this function and must  
    be deallocated by the calling procedure by cvxMemFree() function.  A NULL  
    pointer is output if no data is found.

    @param [in] file ZW3D or VX file name (file[0]=0 or NULL for active file)
    @param [in] objectName root object name (objName[0]=0 or NULL for active object)
    @param [out] data customization data
    @param [out] dataLength length of customization data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxRootCustomDataGet(const vxLongPath file, const vxRootName objectName, char **data, int *dataLength);

    /**
    @ingroup zwapi_root

    Delete the first user custom data from a existing root object of an existing ZW3D file.

    @param [in] file ZW3D or VX file name (file[0]=0 or NULL for active file)
    @param [in] objectName root object name (objName[0]=0 or NULL for active object)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxRootCustomDataDel(const vxLongPath file, vxRootName objectName);

    /**
    @ingroup zwapi_root

    Add user custom data to a specific root object of an existing ZW3D file.

    @param [in] file ZW3D file name (file[0]=0 or NULL for active file)
    @param [in] root root object name (root[0]=0 or NULL for active object)
    @param [in] data customization data (pointer to null-terminated ascii string)
    @param [out] idCustomData index of new customization data object (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_STRING
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOCATE_FAIL
    */
    extern evxErrors cvxRootCustomDataAdd(const vxLongPath file, const vxRootName root, const char *data, int *idCustomData);

    /**
    @ingroup zwapi_root

    Outputs a list of indices of the customization data that belong to a existing
    root object of an existing ZW3D file. The calling procedure MUST deallocate
    the output list with cvxMemFree.

    @param [in] file ZW3D file name (file[0]=0 or NULL for active file)
    @param [in] root root object name (root[0]=0 or NULL for active object)
    @param [out] count number of customization data
    @param [out] idCustomDatas id's list of customization data objects

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_OBJ
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxRootInqCustomData(const vxLongPath file, const vxRootName root, int *count, int **idCustomDatas);

    /**
    @ingroup zwapi_root

    Get all customization data from a existing root object of an existing ZW3D file.  
    The referenced by "***data" and "**dataLength" is allocated by this function and   
    must be deallocated by the calling procedure by cvxMemFree() function. the use case  
    is as follows:

    @code
    int count = 0;
    char** data = NULL;
    cvxRootCustomDataGetAll(NULL, NULL, &count, &data);
    ...
    for (int i = 0; i < count; i++)
       {
       cvxMemFree((void**)&data[i]);
       }
    cvxMemFree((void**)&data);
    @endcode

    @param [in] file ZW3D file name (file[0]=0 or NULL for active file)
    @param [in] root root object name (root[0]=0 or NULL for active object)
    @param [out] count number of customization data
    @param [out] data list of customization data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_INVALID_OBJ
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxRootCustomDataGetAll(const vxLongPath file, const vxRootName root, int *count, char ***data);

    /**
    @ingroup zwapi_root

    Get specified customization data from a existing root object of an existing ZW3D file.  
    The referenced by "**data" is allocated by this function and must be deallocated by the  
    calling procedure by cvxMemFree() function. NULL pointer is output if no data is found.

    @param [in] file ZW3D file name (file[0]=0 or NULL for active file)
    @param [in] root root object name (root[0]=0 or NULL for active object)
    @param [in] idCustomData index of customization data object
    @param [out] data customization data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxRootCustomDataGetById(const vxLongPath file, const vxRootName root, int idCustomData, char **data);

    /**
    @ingroup zwapi_root

    Modify specified customization data from a existing root object of an existing ZW3D file.

    @param [in] file ZW3D file name (file[0]=0 or NULL for active file)
    @param [in] root root object name (root[0]=0 or NULL for active object)
    @param [in] idCustomData index of customization data object
    @param [in] data customization data (pointer to null-terminated ascii string)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxRootCustomDataModById(const vxLongPath file, const vxRootName root, int idCustomData, const char *data);

    /**
    @ingroup zwapi_root

    Delete specified customization data from a existing root object of an existing ZW3D file.

    @param [in] file ZW3D file name (file[0]=0 or NULL for active file)
    @param [in] root root object name (root[0]=0 or NULL for active object)
    @param [in] count number of customization data (0 to delete all)
    @param [in] idCustomDatas index list of customization data (NULL to delete all)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxRootCustomDataDelById(const vxLongPath file, const vxRootName root, int count, const int *idCustomDatas);

    //====================================================================================================================
    /** @name root separate */
    //====================================================================================================================

    /**
    @brief separate root to file
    @ingroup zwapi_root
    */
    typedef struct svxRootSepData
    {
        int cntRoots;      /**<@brief count of roots */
        vxLongName *roots; /**<@brief list of root */
        int keep;          /**<@brief 1 is keep the objects in original file, else 0.default:1 */
        int oneObj;        /**<@brief 1 is one object per file, else 0. default:1 */
        int openSepFile;   /**<@brief 1 is open the separate files,else 0. default:0 */
        vxPath dir;        /**<@brief save directory of separate files */
        int option;        /**<@brief when the file name is repeated, 0 is auto rename, 1 is manual rename, 2 is skip.default:0 */
        vxLongName name;   /**<@brief file name.apply it if option=1. */
    } svxRootSepData;

    /**
    @ingroup zwapi_root

    The function of this interface is to split the selected roots in multiple files into
    multiple single files.

    Interface cvxRootSeparateInit can initialize the structure.

    @param [in] data  separate data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxRootSeparate(svxRootSepData *data);

    /**
    @ingroup zwapi_root

    Initialize the structure svxRootSepData.

    @see cvxRootSeparate

    @param [out] data separate data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        
    */
    extern evxErrors cvxRootSeparateInit(svxRootSepData *data);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* Zw_API_ROOT_H */
