/**
@file zwapi_file.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D File API
*/
/**
@defgroup zwapi_file File
@ingroup FileModel
@brief
@details THE MODULE FOR THE ZW3D File API
*/

#pragma once
#ifndef ZW_API_FILE_H /* this ifndef surrounds entire header */
#define ZW_API_FILE_H

#include "zwapi_file_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name File New */
    //====================================================================================================================
    /**
    @ingroup zwapi_file

    Check and fix name without warning messages,  
    If the name contains some of \/:*?"<>|,~!@$# it is invalid,  
    this function will replace those character with _ to repair it.  

    It is assumed that the input "fileName" is no longer than 512 bytes.

    @note
    Normally, this function used to check the file name when new a file.

    @param [in,out] fileName  file name
    @param [in] nBytes max size of file name(no longer than 512 bytes)

    @retval return
    -       1 - if the input name is OK or repaired.
    -       0 - otherwise.
    */
    extern int cvxFileNameCheck(char *fileName, int nBytes);

    /**
    @ingroup zwapi_file

    Check and fix name without warning messages,  
    If the name contains some of \/:*?"<>|,~!@$# it is invalid,  
    this function will replace those character with _ to repair it.  

    It is assumed that the input "name" is no longer than 256 bytes.

    @note
    Normally, this function used to check the root name.

    @param [in,out] name  name to check
    @param [in] nBytes max size of the name

    @retval return
    -       1 - if the input name is OK or repaired.
    -       0 - otherwise.
    */
    extern int cvxNameValidCheck(char *name, int nBytes);

    /**
    @ingroup zwapi_file

    Creates a new ZW3D file with the specified name and makes it active,  
    add root object using cvxRootAdd() after creating the file. If you  
    need to create a single object file, cvxFileNewSingle() is recommended.  

    @note
    User can call cvxFileNameCheck() to check the Name first.

    @param [in] Name ZW3D file name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxFileNew(const vxLongPath Name);

    /**
    @ingroup zwapi_file

    This function is the same as cvxFileNew2(), but it also allows you  
    to assign a text string description to the new object file.  The  
    description must not be longer than 32 bytes, including the null-  
    terminator.

    @note
    User can call cvxFileNameCheck() to check the Name first.

    @param [in] Name ZW3D file name
    @param [in] Description optional object description (or NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxFileNew2(const vxLongPath Name, char *Description);

    /**
    @ingroup zwapi_file

    Creates a new single-root file with the specified name, file type, subtype, template name and description.  
    and makes it active.

    @note
    User can call cvxFileNameCheck() to check the Name first.

    @param [in] fileName file name
    @param [in] fileType single-root file type
    @param [in] fileSubtype single-root file subtype
    @param [in] templateName optional template object name (or NULL)
    @param [in] fileDescription optional object description (or NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxFileNewSingle(const vxLongPath fileName, evxFileType fileType, evxFileSubtype fileSubtype, const char *templateName, char *fileDescription);

    //====================================================================================================================
    /** @name File Open */
    //====================================================================================================================
    /**
    @ingroup zwapi_file

    Set the flag that allows files to remain open after certain functions  
    have accessed them.  When the cvxPartAtItemGetInFile() or  
    cvxPartAtItemSetInFile() function must open a file to access an  
    attribute, by default it will also close the file when that function  
    returns.  However, if cvxFileKeep(1) is called first,  
    cvxPartAtItemGetInFile() and cvxPartAtItemSetInFile() will leave the file  
    open, which makes subsequent calls more efficient when accessing other  
    attributes in the same file.  Calling cvxFileKeep(0) restores the  
    default behavior, i.e. cvxPartAtItemGetInFile() and  
    cvxPartAtItemSetInFile() will close any files that they must open.  

    This function does not affect files that are already open when  
    cvxPartAtItemGetInFile() or cvxPartAtItemSetInFile() is called.  Files  
    that are already open will remain open when accessed by those  
    functions, regardless of how the fKeepOpen flag is set.  

    This function returns the previous state of the fKeepOpen flag.  In  
    typical usage, the returned value should be given back to this  
    function the second time this function is called, which will restore  
    the original state of the flag. For example:  
    @code
       int fOldKeepOpen = cvxFileKeep(1);
       ... multiple calls to cvxPartAtItemGetInFile() or cvxPartAtItemSetInFile() ...;
       cvxFileOpen(fOldKeepOpen);
    @endcode

    @see cvxFileClose(), cvxFileSave(), and similarly named functions to close  
    files that may have been opened by cvxPartAtItemGetInFile() or  
    cvxPartAtItemSetInFile().
    @param [in] fKeepOpen 1 to keep files open, 0 to let files close

    */
    extern int cvxFileKeep(int fKeepOpen);

    /**
    @ingroup zwapi_file

    Opens an existing VX or ZW3D file.  It is assumed the file resides  
    somewhere in the active search directories (see cvxPathSet()).  
    Use cvxPathSearchFirst() to force a particular directory to  
    be searched first.

    @param [in] File ZW3D file name

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
    extern evxErrors cvxFileOpen(const vxLongPath File);

    /**
    @ingroup zwapi_file

    If the specified file is not in the memory, then just open it as
    cvxFileOpen().

    If the specified file is already opened in the memory, try to reload
    the data from the physical file.

    If to reopen an assembly file, you can call cvxAsmTreeRegen() to
    refresh the assembly tree.

    @param [in] Name ZW3D file name (not include file path)

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
    extern evxErrors cvxFileReOpen(const vxLongPath Name);

    /**
    @ingroup zwapi_file

    Replace the file data of filePath with newData. The newData file will be
    deleted if fDel is not 0.

    @note
    newData cannot be already located/opened in ZW3D.  
    The filePath and newData must the full path of the file.

    @param [in] filePath path of the file to be replaced
    @param [in] newData path of the file contains the new data
    @param [in] fDel 1 if want to delete newData, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxFileReplace(const vxLongPath filePath, const vxLongPath newData, int fDel);


    //====================================================================================================================
    /** @name File Save */
    //====================================================================================================================
    /**
    @ingroup zwapi_file

    Saves the active ZW3D file to the location it was previously saved at.

    @param [in] Close 1 = close file after saving it; 0 = leave it open

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxFileSave(int Close);

    /**
    @ingroup zwapi_file

    Saves the active ZW3D file and its relevant files to the location they were previously saved at.

    @param [in] Close 1 = close file after saving it; 0 = leave it open

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxFileSave2(int Close);

    /**
    @ingroup zwapi_file

    Saves the active file. You can control keep/close, pop-out/disable prompt and save the related files by parameters.

    @param [in] Close 1 = close file after saving it; 0 = leave it open
    @param [in] DisPrompt 1 = no prompt during saving it; 0 = leave it open
    @param [in] Related 1 = save the related files; 0 = save current file only

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxFileSave3(int Close, int DisPrompt, int Related);

    /**
    @ingroup zwapi_file

    Saves all active ZW3D files to the specified path/filename.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxFileSaveAll(void);

    /**
    @ingroup zwapi_file

    Saves the active ZW3D file to the specified path/filename.  
    If there is prompt dialog, please use "cvxUserActionStatusSet2()" to avoid interrupt.

    @param [in] File pathname to save file under

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxFileSaveAs(const vxLongPath File);

    /**
    @ingroup zwapi_file

    Saves the specified files in memory saved to the specified directory. The file
    name will not be changed.

    @note
    If the file is not opened in ZW3D and it can be found in the search path,
    just copy it to the specified directory.

    @param [in] Count count of the files list to save
    @param [in] FileList name list of files to save (only file name)
    @param [in] Path path to save files

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxFilesSaveTo(int Count, const vxPath *FileList, const vxPath Path);

    /**
    @ingroup zwapi_file

    Saves the specified files in memory saved to the specified directory. The file
    name will not be changed.

    @note
    If the file is not opened in ZW3D and it can be found in the search path,
    just copy it to the specified directory.

    @param [in] Count count of the files list to save
    @param [in] FileList name list of files to save (only file name)
    @param [in] Path path to save files

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxFilesSaveToByLongPath(int Count, const vxLongPath *FileList, const vxLongPath Path);

    /**
    @ingroup zwapi_file

    Saves the file referred by the specified component to the specified path/filename.

    UpdateFlag is 0 to just update the specified component only, 1 to update all the  
    components refer to the same part in the same parent assembly, and -1 to update all  
    as cvxFileSaveAs (no prompt, save as new and replace original one).

    @param [in] CompPath pick-path of component
    @param [in] UpdateFlag update flag, please see the description
    @param [in] File path name to save file (must include the new file name)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOACATE_FAIL
    -        ZW_aPI_FILE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxCompFileSaveAs(svxEntPath *CompPath, int UpdateFlag, const vxLongPath File);

    //====================================================================================================================
    /** @name File Close */
    //====================================================================================================================
    /**
    @ingroup zwapi_file

    Closes the active ZW3D file, prompting the user whether to save or discard
    changes before closing the file.

    @see cvxFileClose2() for a version of this function with more options.

    */
    extern void cvxFileClose(void);

    /**
    @ingroup zwapi_file

    Closes the specified file, whether or not it is the active file.  
    The active file will remain active after the specified file is closed.  
    If the specified file (Name) is the active file, no attempt is made to
    select another file for activation after "Name" is closed.

    @param [in] Name file name (input NULL or empty string to close the active file)
    @param [in] Option 0 - prompt whether to save or discard changes before closing file;  
                       1 - automatically save changes before closing file;  
                       2 - automatically discard changes before closing file; if the undo-redo  
                           log references the file, undo-redo information is cleared for all files  
                           in the active session.  
                       3 - automatically discard changes before closing file; existing undo-redo  
                           information will be kept, but will ignore the closed file; if you use this  
                           option, it is on you to be certain that no harm will come from undoing or  
                           redoing transactions without regard for how the closed file may have been  
                           involved in them.

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern void cvxFileClose2(const vxLongPath Name, int Option);


    //====================================================================================================================
    /** @name Session */
    //====================================================================================================================
    /**
    @ingroup zwapi_file

    Clears the active session.


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxSessionClear(void);

    /**
    @ingroup zwapi_file

    Removes unused files from the cache.

    @param [in] file file name (file[0]=0 or NULL to clear all unused files)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    */
    extern evxErrors cvxFileSessionClear(const vxLongPath file);

    /**
    @ingroup zwapi_file

    Saves the active session.


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxSessionSave(void);

    /**
    @ingroup zwapi_file

    Restores the last session backup.


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxSessionRestore(void);

    //====================================================================================================================
    /** @name File Import/Export */
    //====================================================================================================================
    /**
    @ingroup zwapi_file

    Initialize the parameters of the cvxFileImport().

    "general" supports initialization of the following import types, which correspond
    to the following data types:                                               
    If the type = VX_IMPORT_TYPE_UG, the general is svxImportUGData.           
    If the type = VX_IMPORT_TYPE_STEP, the general is svxImportSTEPData.       
    If the type = VX_IMPORT_TYPE_DWG_DXF, the general is svxImportDwgDxfData.  
    If the type = VX_IMPORT_TYPE_STL, the general is svxImportSTLData.
    if the Type = VX_IMPORT_PTS_FROM_FILE, the general is svxImportPTSData.

    @note
    Do not assign a value to variable "data" before calling this function.  
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data import file data
    @param [in] type import file type
    @param [out] general setting general properties(NULL to use default settings)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxFileImportInit(svxImportData *data, evxImportType type, void *general);

    /**
    @ingroup zwapi_file

    Import specified file to specified object.

    @note
    You can use function cvxOpCount() before importing the file,  
    and then use cvxEntNewList()/cvxEntNew() to get the new specified  
    entities after importing the file. This method is only available when 
    importData->importTo = 0.

    @note
    Interface cvxFileImportInit() can initialize variables of this function.

    @param [in] importData import data of specified file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxFileImport(svxImportData *importData);

    /**
    @ingroup zwapi_file

    Use this function to import non-ZW3D files types such as Catia V4, JT,NX etc.
    into ZW3D as parts, sketches, or drawing sheets. the files will be imported
    and save as Z3 file automatically.

    Currently, "Setting" only supports the following import type, and the data type
    matching the type is as follows:  
    If type = VX_IMPORT_TYPE_UG, Setting is svxImportUGData.  
    If type = VX_IMPORT_TYPE_STEP, Setting is svxImportSTEPData.  
    If type = VX_IMPORT_TYPE_DWG_DXF, Setting is svxImportDwgDxfData.  
    If type = VX_IMPORT_TYPE_STL, Setting is svxImportSTLData.

    @note
    VX_IMPORT_TYPE_JT and VX_IMPORT_PTS_FROM_FILE are not supported by the function.


    @param [in] Count count of files or directories list to import
    @param [in] PathList list of files or directories to import
    @param [in] SubFolder whether to include sub-folders files (1: yes; 0: no)
    @param [in] SavePath output path that does not contain file name, NULL to
                         output file to input folder
    @param [in] Type the import file types
    @param [in] Setting the import setting data (NULL to use default setting)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxFileImportMulti(int Count, const vxPath *PathList, int SubFolder, const vxPath SavePath, evxImportType Type, const void *Setting);

    /**
    @ingroup zwapi_file

    Use this function to import non-ZW3D files types such as Catia V4, JT,NX etc.  
    into ZW3D as parts, sketches, or drawing sheets. the files will be imported  
    and save as Z3 file automatically.

    Currently, "Setting" only supports the following import type, and the data type
    matching the type is as follows:                                   
    If type = VX_IMPORT_TYPE_UG, Setting is svxImportUGData.           
    If type = VX_IMPORT_TYPE_STEP, Setting is svxImportSTEPData.       
    If type = VX_IMPORT_TYPE_DWG_DXF, Setting is svxImportDwgDxfData.  
    If type = VX_IMPORT_TYPE_STL, Setting is svxImportSTLData.

    @note
    VX_IMPORT_TYPE_JT and VX_IMPORT_PTS_FROM_FILE are not supported by the function.

    @param [in] Count count of files or directories list to import
    @param [in] PathList list of files or directories to import
    @param [in] SubFolder whether to include sub-folders files (1: yes; 0: no)
    @param [in] SavePath output path that does not contain file name, NULL to
                         output file to input folder
    @param [in] Type the import file types
    @param [in] Setting the import setting data (NULL to use default setting)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxFileImportMultiByLongPath(int Count, const vxLongPath *PathList, int SubFolder, const vxLongPath SavePath, evxImportType Type, const void *Setting);

    /**
    @ingroup zwapi_file

    Import a STL file to active part.

    @param [in] path STL file path
    @param [out] idOut id of Imported STL Block

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxFileImportStl(const char *path, int *idOut);

    /**
    @ingroup zwapi_file

    Initialize the parameters of the cvxFileExport().

    Set "imgType" only when the "type" is VX_EXPORT_TYPE_IMG or VX_EXPORT_TYPE_PDF.
    Otherwise, set it to 0.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type type of export
    @param [in] imgType see description(evxImgType)
    @param [out] data data of file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxFileExportInit(evxExportType type, int imgType, void *data);

    /**
    @ingroup zwapi_file

    Exports the specified file to specified path.
    If the Type is VX_EXPORT_TYPE_IMG, the data is defined by struct svxImgData,
    else if the Type is VX_EXPORT_TYPE_PDF, the data is defined by struct svxPdfData,
    else if the Type is VX_EXPORT_TYPE_GRP, the data is svxGRPData(can be ignored),
    else if the Type is VX_EXPORT_TYPE_DWG, the data is svxDWGData.
    else if the Type is VX_EXPORT_TYPE_IGES, the data is svxIGESData.
    else if the Type is VX_EXPORT_TYPE_STEP, the data is svxSTEPData.
    else if the Type is VX_EXPORT_TYPE_JT, the data is svxJTData.
    else if the Type is VX_EXPORT_TYPE_PARA_TEXT, the data is svxPARAData.
    else if the Type is VX_EXPORT_TYPE_PARA_BINARY, the data is svxPARAData.
    else if the Type is VX_EXPORT_TYPE_CAT5_PART, the data is svxCAT5Data.
    else if the Type is VX_EXPORT_TYPE_CAT5_ASM, the data is svxCAT5Data.
    else if the Type is VX_EXPORT_TYPE_HTML, the data is svxHTMLData.
    else if the Type is VX_EXPORT_TYPE_STL, the data is svxSTLData.
    else if the Type is VX_EXPORT_TYPE_OBJ, the data is svxOBJData.
    else if the Type is VX_EXPORT_TYPE_IDF, the data is svxIDFData.

    Interface cvxFileExportInit() initializes the corresponding structure.

    @param [in] Type type of export
    @param [in] Path path of export file
    @param [in] Data data of file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxFileExport(evxExportType Type, const vxLongPath Path, void *Data);

    /**
    @ingroup zwapi_file

    Exports the specified files to specified path.                                      
    If the Type is VX_EXPORT_TYPE_IMG, the data is defined by struct svxImgData,        
    else if the Type is VX_EXPORT_TYPE_PDF, the data is defined by struct svxPdfData,   
    else if the Type is VX_EXPORT_TYPE_DWG, the data is svxDWGData.                     
    else if the Type is VX_EXPORT_TYPE_IGES, the data is svxIGESData.                   
    else if the Type is VX_EXPORT_TYPE_STEP, the data is svxSTEPData.                   
    else if the Type is VX_EXPORT_TYPE_JT, the data is svxJTData.                       
    else if the Type is VX_EXPORT_TYPE_PARA_TEXT, the data is svxPARAData.              
    else if the Type is VX_EXPORT_TYPE_PARA_BINARY, the data is svxPARAData.            
    else if the Type is VX_EXPORT_TYPE_CAT5_PART, the data is svxCAT5Data.              
    else if the Type is VX_EXPORT_TYPE_CAT5_ASM, the data is svxCAT5Data.               
    else if the Type is VX_EXPORT_TYPE_STL, the data is svxSTLData.

    Interface cvxFileExportInit() initializes the corresponding structure.

    @note
    VX_EXPORT_TYPE_GRP and VX_EXPORT_TYPE_HTML are not supported by the function.
    CAM Plan don't support export.

    @param [in] Count count of the files list to export (0 to export all currently open files)
    @param [in] FileList list of files to export (NULL to export all currently open and newly files)  
                         1. loaded file and newly created file need only file name  
                         2. unloaded file need the full path of file
    @param [in] Filter type of object to export, VX_FILE_ALL to export all object
    @param [in] Type type of export
    @param [in] Path destination path for exporting files (excluding file name)
    @param [in] Data export parameter

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxFileExportMulti(int Count, const vxPath *FileList, evxFileType Filter, evxExportType Type, const vxPath Path, void *Data);

    /**
    @ingroup zwapi_file

    Exports the specified files to specified path.
    If the Type is VX_EXPORT_TYPE_IMG, the data is defined by struct svxImgData,
    else if the Type is VX_EXPORT_TYPE_PDF, the data is defined by struct svxPdfData,
    else if the Type is VX_EXPORT_TYPE_DWG, the data is svxDWGData.
    else if the Type is VX_EXPORT_TYPE_IGES, the data is svxIGESData.
    else if the Type is VX_EXPORT_TYPE_STEP, the data is svxSTEPData.
    else if the Type is VX_EXPORT_TYPE_JT, the data is svxJTData.
    else if the Type is VX_EXPORT_TYPE_PARA_TEXT, the data is svxPARAData.
    else if the Type is VX_EXPORT_TYPE_PARA_BINARY, the data is svxPARAData.
    else if the Type is VX_EXPORT_TYPE_CAT5_PART, the data is svxCAT5Data.
    else if the Type is VX_EXPORT_TYPE_CAT5_ASM, the data is svxCAT5Data.
    else if the Type is VX_EXPORT_TYPE_STL, the data is svxSTLData.

    Interface cvxFileExportInit() initializes the corresponding structure.

    @note
    VX_EXPORT_TYPE_GRP and VX_EXPORT_TYPE_HTML are not supported by the function.
    CAM Plan don't support export.

    @param [in] Count count of the files list to export (0 to export all currently open files)
    @param [in] FileList list of files to export (NULL to export all currently open and newly files)
                         1. loaded file and newly created file need only file name
                         2. unloaded file need the full path of file
    @param [in] Filter type of object to export, VX_FILE_ALL to export all object
    @param [in] Type type of export
    @param [in] Path destination path for exporting files (excluding file name)
    @param [in] Data export parameter

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxFileExportMultiByLongPath(int Count, const vxLongPath *FileList, evxFileType Filter, evxExportType Type, const vxLongPath Path, void *Data);

    /**
    @ingroup zwapi_file

    Exports the specified flat solid to specified path.                               
    If the Type is VX_EXPORT_TYPE_IMG, the data is defined by struct svxImgData,      
    else if the Type is VX_EXPORT_TYPE_PDF, the data is defined by struct svxPdfData,  
    else if the Type is VX_EXPORT_TYPE_GRP, the data is svxGRPData(can be ignored),   
    else if the Type is VX_EXPORT_TYPE_DWG, the data is svxDWGData.                   
    else if the Type is VX_EXPORT_TYPE_IGES, the data is svxIGESData.                 
    else if the Type is VX_EXPORT_TYPE_STEP, the data is svxSTEPData.                 
    else if the Type is VX_EXPORT_TYPE_JT, the data is svxJTData.                     
    else if the Type is VX_EXPORT_TYPE_PARA_TEXT, the data is svxPARAData.            
    else if the Type is VX_EXPORT_TYPE_PARA_BINARY, the data is svxPARAData.          
    else if the Type is VX_EXPORT_TYPE_CAT5_PART, the data is svxCAT5Data.            
    else if the Type is VX_EXPORT_TYPE_CAT5_ASM, the data is svxCAT5Data.             
    else if the Type is VX_EXPORT_TYPE_HTML, the data is svxHTMLData.

    @param [in] idFlatten id of flatten
    @param [in] type export type
    @param [in] filePath file path
    @param [in] data data of file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartSmdFlatSolidExport(int idFlatten, evxExportType type, const vxLongPath filePath, void *data);

    /**
    @ingroup zwapi_file

    Exports the specified flat pattern to specified path.
    This function can only export *.dwg/*.dxf files.

    @note
    Interface cvxFileExportInit(VX_EXPORT_TYPE_DWG,0,data) can initialize variables of this function.

    @param [in] idFlatten id of flatten
    @param [in] filePath file path
    @param [in] data data of file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartSmdFlatPatternExport(int idFlatten, const vxLongPath filePath, const svxDWGData *data);

    //====================================================================================================================
    /** @name File Action */
    //====================================================================================================================
    /**
    @ingroup zwapi_file

       Set a callback function. When processing the target file option,
    the callback function will be called.

       If this function called many times with the same 'type', only
    the last will take effect.

       If param->pfn is null, the original callback function, if there
    exists, will be removed.

       If param->pfn isn't null, the first parameter is caller's data, it
    can be null, the second parameter is actual file, the last parameter
    may be null, it's used as the path for output file sometimes. lastly,
    if param->pfn invokes successes, the function will return 0, else 1.

    @note
    If one call this function to register a callback in a dll module,
    he must call this function again, with argument param set as NULL,
    to unregister the callback for each action before the dll module exit.  
    Usually we can do this in the exit function of the dll module.

    @param [in] type action type
    @param [in] param callback function

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxFileAction(evxDocAction type, svxDocActionParam *param);


    //====================================================================================================================
    /** @name File Query/Edit */
    //====================================================================================================================
    /**
    @ingroup zwapi_file

    Activates the specified ZW3D file for editing. The file must
    already have been opened, or it must reside in one of the
    default search directories (cvxPathSearchFirst()).  
    If the Name carries the specific path which is not in the default
    search path, this function will add it to the default search path and set
    it as the priority search path.

    @see cvxRootActivate2s() will activate the specified file in the memory and
    the target object will be activated.

    @param [in] Name ZW3D file name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FILE_LOACTE_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxFileActivate(const vxLongPath Name);

    /**
    @ingroup zwapi_file

    If the active file has been saved, the directory where it
    resides is output.  Otherwise, Dir[0]=0 is output.

    @param [out] Directory source directory for the active file

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxFileDirectory(vxPath Directory);

    /**
    @ingroup zwapi_file

    If the active file has been saved, the directory where it
    resides is output.  Otherwise, Dir[0]=0 is output.

    A Directory that is too long (longer than "sizeDire") is truncated.

    It is assumed that the input "Directory" is no longer than 512 bytes.

    @param [out] Directory source directory for the active file
    @param [int] sizeDire max size of Directory

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxFileDirectoryByLongPath(char *Directory, int sizeDire);

    /**
    @ingroup zwapi_file

    Outputs the name of the active file.  
    Outputs Name[0]=0 if there is no active file.

    @param [out] Name name of active file
    @param [in] nBytes string max size of active file name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxFileInqActive(char *Name, int nBytes);

    /**
    @ingroup zwapi_file

    Gets flag indicating whether the active file is multi-object or
    single object.

    @param [out] MultiObject 1=multi-object file; 0=single-object file

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern void cvxFileTypeGet(int *MultiObject);

    /**
    @ingroup zwapi_file

    Sets flag indicating whether the active file is multi-object or
    single object.

    @param [in] MultiObject 1=multi-object file; 0=single-object file

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern void cvxFileTypeSet(int MultiObject);

    /**
    @ingroup zwapi_file

    Get the specified file subtype.  
    If fileName is NULL or blank string, get current file subtype.

    @note
    Multi-object files do not have a subtype.

    @param [in] fileName file name (or NULL)
    @param [out] fileSubtype file subtype

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxFileInqSubType(const vxLongPath fileName, evxFileSubtype *fileSubtype);

    /**
    @ingroup zwapi_file

    Outputs the name of the open file.  
    Outputs Name[0]=0 if there is no open file.

    @param [out] Name name of active file
    @param [in] nBytes string max size of active file name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxFileInqOpen(char *Name, int nBytes);

    /**
    @ingroup zwapi_file

    Get all of the open file list.  
    The list referenced by "**fileList" is allocated by this function.  
    And must be deallocated by the calling procedure.  
    A NULL pointer is output if no data is found.

    @param [out] count count of the list
    @param [out] fileList file list

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxFileOpenList(int *count, vxPath **fileList);

    /**
    @ingroup zwapi_file

    Get all of the open file list.
    The list referenced by "**fileList" is allocated by this function.
    And must be deallocated by the calling procedure.
    A NULL pointer is output if no data is found.

    @param [out] count count of the list
    @param [out] fileList file list

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxFileOpenListByLongPath(int *count, vxLongPath **fileList);

    /**
    @ingroup zwapi_file

    Get the loaded file list, including front-open and background-loaded files.

    The list referenced by "**fileList" is allocated by this function.
    And must be deallocated by the calling procedure.

    @param [in] state 0 to get all loaded files;   
                      1 to get all files loaded and in use  
                      2 to get all loaded but unused files
    @param [out] count count of the list
    @param [out] fileList file list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxFileLoadList(const int state, int *count, vxPath **fileList);

    /**
    @ingroup zwapi_file

    Get the loaded file list, including front-open and background-loaded files.

    The list referenced by "**fileList" is allocated by this function.
    And must be deallocated by the calling procedure.

    @param [in] state 0 to get all loaded files;
                      1 to get all files loaded and in use
                      2 to get all loaded but unused files
    @param [out] count count of the list
    @param [out] fileList file list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxFileLoadListByLongPath(int state, int *count, vxLongPath **fileList);

    /**
    @ingroup zwapi_file

    Get the version of the current file.  
    If file=NULL, it means return the version of the current active file.  
    This function will return a four digits value.  
    the front two means the annual version. The last two means the upgrade.
    Like:                   
    1800 means ZW3D 2014    
    1810 means ZW3D 2014 SP  
    1900 means ZW3D 2015    
    1910 means ZW3D 2015 SP  
    ......

    @param [in] file full file path
    @param [out] version version number

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxFileVersionGet(const vxLongPath file, int *version);

    /**
    @ingroup zwapi_file

    Get modification status of the specified VX or ZW3D file.

    @see cvxRootInqMod() and cvxRootInqModSinceRegen().

    @param [in] Name VX or ZW3D file name
    @param [out] Modified 1-modified, 0-unmodified

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_FILE_ERROR
    */
    extern evxErrors cvxFileIsModified(const vxLongPath Name, int *Modified);

    /**
    @ingroup zwapi_file

    Get associated file list with the target object.This includes  
    assembly component files, drawing view files, imported files (IGES,  
    STEP,...) and links.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [out] count number of files in list
    @param [out]  fileList list of files

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxFileInqAssociatedList(int *count, vxPath **fileList);

    /**
    @ingroup zwapi_file

    Get associated file list with the target object.This includes
    assembly component files, drawing view files, imported files (IGES,
    STEP,...) and links.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [out] count number of files in list
    @param [out]  fileList list of files

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxFileInqAssociatedListByLongPath(int *count, vxLongPath **fileList);

    /**
    @ingroup zwapi_file

    Get associated file list with the target object or the specified file.This includes
    assembly component files, drawing view files, imported files (IGES, STEP,...) and links.

    If iDepth is >=0, then the link files will be ignore for the depth more than it.
    Set it as -1 to get all (ignore the depth checking).

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] fileName file name to inquire, NULL for just the active target
    @param [in] nDepth max depth to inquire the linked files, -1 to ignore (see description)
    @param [out] count number of files in list
    @param [out] fileList list of files

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxFileInqAssociatedListByName(const char *fileName, int nDepth, int *count, vxPath **fileList);

    /**
    @ingroup zwapi_file

    Get associated file list with the target object or the specified file.This includes
    assembly component files, drawing view files, imported files (IGES, STEP,...) and links.

    If iDepth is >=0, then the link files will be ignore for the depth more than it.
    Set it as -1 to get all (ignore the depth checking).

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] fileName file name to inquire, NULL for just the active target
    @param [in] nDepth max depth to inquire the linked files, -1 to ignore (see description)
    @param [out] count number of files in list
    @param [out] fileList list of files

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxFileInqAssociatedListByLongName(const char *fileName, int nDepth, int *count, vxLongPath **fileList);

    /**
    @ingroup zwapi_file

    Extract the preview bitmap from a source file.
    For example: BmpFile = "D:\\fileName.bmp".

    @param [in] SrcFile pathname to source file
    @param [in] BmpFile pathname to bitmap file to be extracted (include bitmap name and the extension)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxFilePreviewExtract(const vxLongPath SrcFile, const vxLongPath BmpFile);

    /**
    @ingroup zwapi_file

    Outputs the file name of top root object in assembly.
    Outputs "Name[0]=0" if error.

    @param [out] Name file name of top root object in assembly
    @param [in] nBytes string max size of file name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxFileInqAsm(char *Name, int nBytes);

    /**
    @ingroup zwapi_file

    Get target part's assembly mode, if no target is active, return the value in configuration.


    @retval return
    -       1 - if new assembly mode (version 17).
    -       0 - otherwise.
    */
    extern char cvxFileInqAssemMode(void);


    //====================================================================================================================
    /** @name UDF File Query/Edit */
    //====================================================================================================================
    /**
    @ingroup zwapi_file

    Determine whether a file is a UDF file.

    @param [in] path file path(NULL to use default path)
    @param [in] file file name(contains the file extension)
    @param [out] isUDF 1 is UDF file,else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxFileIsUDF(const vxLongPath path, const vxLongPath file, int *isUDF);

    /**
    @ingroup zwapi_file

    Get the associated file list of the specified UDF file.

    The calling procedure MUST deallocate the output fileList with cvxMemFree().

    @note
    This function will open the UDF file in the memory if it doesn't locate before,
    you can use cvxFileSessionClear() to remove it form the cache.

    @param [in] path file path(NULL to use default path)
    @param [in] file file name(contains the file extension)
    @param [out] count number of files in list
    @param [out]  fileList list of files

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxUDFFileInqAssociatedList(const vxPath path, const vxPath file, int *count, vxPath **fileList);

    /**
    @ingroup zwapi_file

    Get the associated file list of the specified UDF file.

    The calling procedure MUST deallocate the output fileList with cvxMemFree().

    @note
    This function will open the UDF file in the memory if it doesn't locate before,
    you can use cvxFileSessionClear() to remove it form the cache.

    @param [in] path file path(NULL to use default path)
    @param [in] file file name(contains the file extension)
    @param [out] count number of files in list
    @param [out]  fileList list of files

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxUDFFileInqAssociatedListByLongPath(const vxLongPath path, const vxLongPath file, int *count, vxLongPath **fileList);

    //====================================================================================================================
    /** @name File Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_file

    Sets description of specified file.  
    The file description here is different from the attribute "Description" of root object. 
    To set the attribute "Description" of root object, you can use the attribute setting 
    functions, such as cvxPartAtItemSet and cvxPartAtItemSetInFile.  

    @param [in] Name ZW3D or VX file name (Name[0]=0 or NULL for active file)
    @param [in] Description object description. no longer than 32 bytes.

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_FILE_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxFileDescriptionSet(const vxLongPath Name, const char *Description);

    /**
    @ingroup zwapi_file

    Gets the description of specified file.  
    The file description here is different from the attribute "Description" of root object. 
    To get the attribute "Description" of root object, you can use the attribute getting 
    functions, such as cvxPartAtItemGet and cvxPartAtItemGetInFile.

    @param [in] Name ZW3D or VX file name (Name[0]=0 or NULL for active file)
    @param [out] Description object description

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxFileDescriptionGet(const vxLongPath Name, vxLongName Description);

    /**
    @ingroup zwapi_file

    Set user custom data to an existing ZW3D or VX file.
    Program will overwrite existing custom data if file already has custom data.

    @param [in] file ZW3D or VX file name (file[0]=0 or NULL for active file)
    @param [in] data customization data
    @param [in] dataLength length of customization data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxFileCustomDataSet(const vxLongPath file, const char *data, int dataLength);

    /**
    @ingroup zwapi_file

    Get user custom data from an existing ZW3D or VX file.  
    The list referenced by "**data" is allocated by this function and must  
    be deallocated by the calling procedure by cvxMemFree() function.  
    A NULL pointer is output if no data is found.

    @param [in] file ZW3D or VX file name (file[0]=0 or NULL for active file)
    @param [out] data customization data
    @param [out] dataLength length of customization data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxFileCustomDataGet(const vxLongPath file, char **data, int *dataLength);

    /**
    @ingroup zwapi_file

    Delete user custom data from an existing ZW3D or VX file.

    @param [in] file ZW3D or VX file name (file[0]=0 or NULL for active file)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxFileCustomDataDel(const vxLongPath file);

    //====================================================================================================================
    /** @name File Print */
    //====================================================================================================================
    /******************************************************************************/ /**
@ingroup zwapi_file

Initialize the parameters of the cvxFilePrint().

@note
Do not assign a value to variable "data" before calling this function.
The cvxMemZero() is called inside the interface to empty everything.

@param [out] data file print data

@retval succeeds
-        ZW_API_NO_ERROR
@retval fail
-        ZW_API_GENERAL_ERROR
-        ZW_API_INVALID_OUTPUT
*/
    extern evxErrors cvxFilePrintInit(svxFilePrintData *data);

    /******************************************************************************/ /**
@ingroup zwapi_file

Use the function to setup ZW3D for plotting and select a printer to output. 
You can plot in a variety of formats, to a device attached to local workstation, 
network or to a file. 

@param [in] data file print data

@retval succeeds
-        ZW_API_NO_ERROR
@retval fail
-        ZW_API_GENERAL_ERROR
-        ZW_API_INVALID_INPUT
-        ZW_API_INVALID_NAME
-        ZW_API_ROOT_OBJ_ACT_FAIL
-        ZW_API_OUT_OF_RANGE
-        ZW_API_OBJ_DATA_GET_ERROR
*/
    extern evxErrors cvxFilePrint(const svxFilePrintData *data);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FILE_H */
