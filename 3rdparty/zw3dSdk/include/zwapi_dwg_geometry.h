/**
@file zwapi_dwg_geometry.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing Geometry API
*/
/**
@defgroup zwapi_dwg_geometry Drawing Geometry API
@ingroup DrawingObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Drawing Geometry API
*/

#pragma once
#ifndef ZW_API_DWG_GEOMETRY_H /* this ifndef surrounds entire header */
#define ZW_API_DWG_GEOMETRY_H

#include "zwapi_dwg_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Drawing Geometry Query/Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_geometry

    Outputs a list of indices of geometry entities in the specified drawing.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idDrawing drawing id
    @param [out] count count of objects
    @param [out] idEnts list of geometry entity id's

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
    extern evxErrors cvxDwgInqGeom(int idDrawing, int *count, int **idEnts);

    /**
    @ingroup zwapi_dwg_geometry

    Outputs the id list of text entities in the specified drawing sheet.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idDrawing drawing id
    @param [in] count count of objects
    @param [in] idEnts list of text entities id's

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
    extern evxErrors cvxDwgInqText(int idDrawing, int *count, int **idEnts);

    /**
    @ingroup zwapi_dwg_geometry

    Get hatch attribute.

    @param [in] idHatch hatch id
    @param [out] HatchAttr hatch attribute

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
    extern evxErrors cvxDwgInqHatchAttr(int idHatch, svxHatchAttr *HatchAttr);

    /**
    @ingroup zwapi_dwg_geometry

    Set hatch attribute.

    @param [in] idHatch hatch id
    @param [in] HatchAttr hatch attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgHatchAttrSet(int idHatch, svxHatchAttr HatchAttr);

    /**
    @ingroup zwapi_dwg_geometry

    Get an array of associative boundary curves of given hatch entity.
    The memory for boundary curves is allocated in this function, so, the
    calling function has to deallocate it.

    @param [in] idHatch id of hatch object
    @param [out] count number of associative boundary curves
    @param [out]  AssocCrvs associative boundary curves

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxDwgHatchAssoCrvsGet(int idHatch, int *count, int **AssocCrvs);

    /**
    @ingroup zwapi_dwg_geometry

    Get hatch id by view id.

    @note
    If the hatch belong to a drawing and not to a view, the hatch id cannot be obtained.
    It can use cvxDwgInqHatchIdByDrawing in this case.

    @param [in] idView view id
    @param [out] count count of "idHatchs"
    @param [out]  idHatchs list of hatch id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgInqHatchIdByView(int idView, int *count, int **idHatchs);

    /**
    @ingroup zwapi_dwg_geometry

    Get hatch id by drawing id.

    @note
    If the hatch belong to a view and not to a drawing, the hatch id cannot be obtained.
    It can use cvxDwgInqHatchIdByView in this case.

    @param [in] idDrawing drawing id
    @param [out] count count of "idHatchs"
    @param [out]  idHatchs list of hatch id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgInqHatchIdByDrawing(int idDrawing, int *count, int **idHatchs);

    /**
    @ingroup zwapi_dwg_geometry

    Get the component or shape data that the reference object points to.

    @param [in] idRefEnt index of reference entity
    @param [out] data data of reference entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgRefEntDataGet(int idRefEnt, svxRefEntData *data);

    /**
    @ingroup zwapi_dwg_geometry

    Get index of parent view of specified geometry.

    @param [in] idGeom index of geometry in view
    @param [out] idView index of parent view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxDwgGeomGetView(int idGeom, int *idView);


    //====================================================================================================================
    /** @name View  Geometry Query/Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_geometry

    This function is to get the geometry indices list depending on the option.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    Values of option are as follows:                                            
    1: shown geometries NOT corresponding to original edges and faces, such as  
       boundary generated by Broken Section view;                               
    2: shown geometries cooresponding to original edges and faces;              
    3: hidden geometry;                                                         
    4: tangent-shown geometry;                                                  
    5: tangent-hidden geometry;                                                 
    6: cosmetic thread geometry;                                                
    7: section view cutting plane geometry, or for detail view clip boundary    
       (circle only)                                                            
    8: centerline geometry;                                                     
    9: centerline objects;                                                      
    10: 3D wireframe data;                                                      
    11: "hidden" wireframe curves;                                              
    12: "hidden" top centermarks;                                               
    13: "hidden" centerlines;                                                   
    14: "hidden" threads;                                                       
    15: 3D point data;                                                          
    16: xtra def'n stuff (thick line);                                          
    17: 3D anno text;                                                           
    18: xtra def'n stuff (arrows);                                              
    19: bend lines of sheet metal;                                              
    20: "hidden" bend lines of sheet metal;                                     
    21: thread end lines;                                                       
    22: hidden thread end lines;                                                
    23: bend notes of sheet metal;                                              
    24: hidden bend notes of sheet metal;                                       
    25: lines for weld beads in idx_beads;                                      
    26: weld beads;                                                             
    27: crop line;                                                              
    28: 3D hatch lines of cosmetic sketch                                       
    29: associated entities                                                     
    30: associated dimensions

    @param [in] viewId view index
    @param [in] option number to indicate which type of geometry to obtain.
                       Detail can refer to description.
    @param [out] count number of list
    @param [out] indices pointer to pointer of geometry indices array

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgViewGeomInqList(int viewId, int option, int *count, int **indices);

    /**
    @ingroup zwapi_dwg_geometry

    This function is to get shape id that geometry in view specified by geomId can be traced back to.
    The file name, part name or pick path is also output if one of them is no NULL.

    @param [in] geomId index of geometry in view
    @param [out] fileName file name of the component of view of line, it can be NULL
    @param [in] fileNameBytes maximum bytes that fileName can hold
    @param [out] partName part name of the component of view of line, it can be NULL
    @param [in] partNameBytes maximum bytes that partName can hold
    @param [out] pickPath pick path, it can be NULL
    @param [out] geom3DId index of geometry 3D corresponding to geomId, it can be NULL
    @param [out] shapeId shape or sketch id that geometry in view specified by geomId can
                         be traced back to, it can be NULL

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_OBJ
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_ENT_PATH_ERROR
    */
    extern evxErrors cvxDwgViewGeomGetShapeId(int geomId, char *fileName, int fileNameBytes, char *partName,
                                              int partNameBytes, svxEntPath *pickPath, int *geom3DId, int *shapeId);

    /**
    @ingroup zwapi_dwg_geometry

    Displays or hides the specified reference component in the specified view,
    Do not support section view and detail view.

    @param [in] idView view id in drawing
    @param [in] fileName file name of component
    @param [in] partName part name of component
    @param [in] show 1 to unblank component; 0 to blank

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgViewRefCompVisSet(int idView, const vxLongPath fileName, const vxRootName partName, int show);

    /**
    @ingroup zwapi_dwg_geometry

    Outputs a list of the reference entity IDs in the special view.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] viewId view id in drawing
    @param [out] count number of reference entities
    @param [out] idRefEnts list of reference entities

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgViewInqRefEnts(int viewId, int *count, int **idRefEnts);

    /**
    @ingroup zwapi_dwg_geometry

    Get the hidden state by referencing the entity id.

    @param [in] idRefEnt  index of reference entity
    @param [out] blank  status of reference entity(1 is blank,else display)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxDwgViewRefBlankGet(int idRefEnt, int *blank);

    /**
    @ingroup zwapi_dwg_geometry

    Set the hidden state by referencing the entity id.

    @param [in] idRefEnt  index of reference entity
    @param [in] blank  status of reference entity(1 is blank,else display)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxDwgViewRefBlankSet(int idRefEnt, int blank);

    /**
    @ingroup zwapi_dwg_geometry

    Gets the wireframe attributes of specified reference entity.

    @param [in] idRefEnt index of reference entity
    @param [out] clrValid 1 from attribute; 0 inherited from view
    @param [out] typeValid 1 from attribute; 0 inherited from view
    @param [out] widthValid 1 from attribute; 0 inherited from view
    @param [out] entAt wireframe attributes, attribute items that are
                       not inherit from view is valid

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgViewRefEntAtGet(int idRefEnt, int *clrValid, int *typeValid, int *widthValid, svxLineAt *entAt);

    /**
    @ingroup zwapi_dwg_geometry

    Set the wireframe attributes of specified reference entity.

    @param [in] idRefEnt index of reference entity
    @param [in] clrValid 1 to set base on attribute; 0 to inherit view
    @param [in] typeValid 1 to set base on attribute; 0 to inherit view
    @param [in] widthValid 1 to set base on attribute; 0 to inherit view
    @param [in] entAt wireframe attributes, attribute items that are
                      not inherit from view are set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_aPI_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgViewRefEntAtSet(int idRefEnt, int clrValid, int typeValid, int widthValid, const svxLineAt *entAt);

    /**
    @ingroup zwapi_dwg_geometry

    Get 3D point in part coordinates corresponding to a pick point on
    an entity in a drawing sheet view.

    The 3D coordinates are output in pnt3D.  If pzPnt is V_NULL, this
    function merely determines whether the given pick is on an entity
    that can be mapped to a 3D point.

    @param [in] pnt2DId point id in view
    @param [out] pnt3D 3D point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgViewPnt2DTo3D(int pnt2DId, svxPoint *pnt3D);

    /**
    @ingroup zwapi_dwg_geometry

    Get 2D point value in drawing sheet corresponding to a 3D point
    value in the part. The 2D coordinate is output in pnt2D and it is
    converted from the matrix of view.

    @param [in] viewId view id in drawing
    @param [in] pnt3D 3D point
    @param [out] pnt2D 2D point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgViewPnt3DTo2D(int viewId, svxPoint pnt3D, svxPoint2 *pnt2D);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DWG_GEOMETRY_H */
