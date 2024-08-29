/**
@file zwapi_part_facets.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Facets/Part Block API
*/
/**
@defgroup zwapi_part_facets Part Facets/Block
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Facets/Part Block API
*/

#pragma once
#ifndef ZW_API_FACETS_H /* this ifndef surrounds entire header */
#define ZW_API_FACETS_H

#include "zwapi_part_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Block Creation */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_facets

    Adds a 3D point block to the active part. If "idEnt" is not NULL, the id of the new block is output.

    The active point attribute color is assigned to the new point block.

    This function will only add point blocks to parts for which explicit (i.e. history free)  
    point cloud management is enabled (the default mode for parts created with version 18 or later).

    @param [in] Name point block name
    @param [in] Count number of points
    @param [in] Points list of points
    @param [out] idEnt id of new point block (input NULL to ignore this output)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    @retval other
    -       -1 - explicit mode is not enabled
    */
    extern int cvxPartPntBlock(vxLongName Name, int Count, svxPointf *Points, int *idEnt);

    /**
    @ingroup zwapi_part_facets

    Creates an explicit (i.e. non-historical) 3D Block containing the input  
    3D facet data and adds it to the active part.

    If "idBlock" is not NULL, the id of the 3D Block created  
    by this function is output via "idBlock".

    If this function successfully creates the Block, the Block takes  
    ownership of the memory referenced by the vertex data fields in the  
    "Facets" structure (Vertex, Normal, etc.).  This function assigns NULL  
    to fields that refer to memory that has been transferred to the Block.  
    After this function returns, use the cvxFacetsFree() function to release  
    any remaining memory still referenced by the "Facets" structure.

    @see cvxPartFacetsMod() for a function that can modify the facet data of
    an existing 3D Block.

    @param [in] Name block name
    @param [in,out] Facets set of 3D triangular facets
    @param [out] idBlock id of new 3D Block of triangular facets

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartFacets(vxLongName Name, svxFacets *Facets, int *idBlock);

    /**
    @ingroup zwapi_part_facets

    Creates an 3D Block and adds it to the active part.

    If "idBlock" is not NULL, the id of the 3D Block created  
    by this function is output via "idBlock".

    Due to the lack of some data in svxSTL, I treat each triangle  
    as a strip and store it in the facet.

    @param [in] name block name
    @param [in] stl STL facets
    @param [out] idBlock id of new 3D Block

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartFacetsBySTL(const vxLongName name, const svxSTL *stl, int *idBlock);


    //====================================================================================================================
    /** @name Block Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_facets

    Outputs a list of database id's of 3D blocks of the specified type within the  
    active part. If there are no blocks, "*Count" is output as zero and "*Blocks"  
    as NULL.

    This function allocates memory for the array output via "Blocks". The calling  
    procedure is responsible for deallocating the memory.

    @param [out] Count number of 3D blocks in the active part
    @param [out] Blocks list of id's of 3D blocks in the active part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqBlocks(int *Count, int **Blocks);

    /**
    @ingroup zwapi_part_facets

    Outputs a list of points in the specified 3D Point Block.  
    Memory for the point list is allocated by this function and output  
    via "Points".  It must be deallocated by the calling procedure  
    with cvxMemFree().

    @param [in] idBlock id of point block in active part
    @param [out] Count number of points
    @param [out] Points list of points

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
    extern evxErrors cvxPartInqBlockPnts(int idBlock, int *Count, svxPointf **Points);

    /**
    @ingroup zwapi_part_facets

    Outputs the id of the parent feature of the specified entity
    in the active part.

    @param [in] idBlock 3D block id
    @param [out] Type block type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqBlockType(int idBlock, evxBlockType *Type);

    /**
    @ingroup zwapi_part_facets

    Outputs a list of triangular facets of the specified STL.

    Memory for the STL facets is allocated by this function and  
    assigned to the input data structure (Stl).  It MUST be  
    deallocated by the calling procedure using cvxStlFree().

    @param [in] idBlock STL id
    @param [out] Stl STL facets

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartInqFacets(int idBlock, svxSTL *Stl);

    /**
    @ingroup zwapi_part_facets

    Outputs the facets stored in the specified 3D block.

    This function allocates memory for lists inside the  
    input "Facets" structure. The calling procedure is  
    responsible to free the lists using cvxFacetsFree(Facets).

    It is assumed the specified 3D block (idBlock) resides
    in the active part.

    @see the description of cvxPartInqFaceFacets2() for
    additional information.

    @param [in] idBlock 3D block id
    @param [out] Facets facet data set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqFacets2(int idBlock, svxFacets *Facets);

    /**
    @ingroup zwapi_part_facets

    Outputs path to the original image file if a texture map has been  
    applied to a facet block.  Unlike cvxPartInqFacets2(), which outputs  
    the path to a copy of the original image file that ZW3D has put in its  
    temp directory, this function outputs the path that was originally  
    used to create the texture map.  The file might no longer exist,  
    although the image may still exist as an embedded object.

    It is assumed the specified block (idBlock) resides in the active
    part.

    @see cvxPartInqFacets2() for a function that outputs all texture map
    attributes.

    @param [in] idBlock 3D block id
    @param [out] Path path to texture map's original image file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartInqFacetsTxFile(int idBlock, vxPath Path);

    /**
    @ingroup zwapi_part_facets

    Outputs path to the original image file if a texture map has been
    applied to a facet block.  Unlike cvxPartInqFacets2(), which outputs
    the path to a copy of the original image file that ZW3D has put in its
    temp directory, this function outputs the path that was originally
    used to create the texture map.  The file might no longer exist,
    although the image may still exist as an embedded object.

    It is assumed the specified block (idBlock) resides in the active
    part.

    A Path that is too long (longer than "sizePath") is truncated.

    It is assumed that the input "Path" is no longer than 512 bytes.

    @see cvxPartInqFacets2() for a function that outputs all texture map
    attributes.

    @param [in] idBlock 3D block id
    @param [out] Path path to texture map's original image file
    @param [in] sizePath max size of Path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartInqFacetsTxFileByLongPath(int idBlock, char *Path, int sizePath);

    //====================================================================================================================
    /** @name Facets Block Edit */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_facets

    Modify an explicit (i.e. non-historical) 3D Block in the active part,  
    replacing the Block's prior triangle and vertex data with data from  
    the given "Facets" input.

    If this function successfully updates the Block, the Block takes  
    ownership of the memory referenced by the vertex data fields in the  
    "Facets" structure (Vertex, Normal, etc.).  This function assigns NULL  
    to fields that refer to memory that has been transferred to the Block.  
    After this function returns, use the cvxFacetsFree() function to release  
    any remaining memory still referenced by the "Facets" structure.

    This function ignores the At, Tx and Sh fields in the "Facets"  
    structure.  It does not update the Block's display attributes, texture  
    map attributes, or shader attributes.  The cvxPartFacetsSetAt() and  
    cvxPartFacetsSetTx() functions can be used to modify a Block's display  
    attributes and texture map attributes.  Shader attributes are not  
    currently used by 3D Blocks.

    @see cvxPartFacets() for a function that can create a 3D Block from facet
    data.

    @param [in] idBlock id of 3D Block of triangular facets
    @param [in,out] Facets set of 3D triangular facets

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
    extern evxErrors cvxPartFacetsMod(int idBlock, svxFacets *Facets);

    /**
    @ingroup zwapi_part_facets

    Modifies display attributes of the specified block.  It is assumed the  
    specified block resides in the active part.

    @param [in] idBlock id of 3D Block
    @param [in] At display attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartFacetsSetAt(int idBlock, const svxFaceAt *At);

    /**
    @ingroup zwapi_part_facets

    Modifies texture map attributes of the specified block.  It is assumed  
    the specified block (idBlock) resides in the active part.

    If the "file" field of the svxTextureAt structure is empty (a  
    zero-length string), the texture map attributes are not saved and any  
    prior texture map assigned to the block is removed.

    The "opt" field of the svxTextureAt structure is not currently
    supported.

    @param [in] idBlock id of 3D Block
    @param [in] Tx texture map attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartFacetsSetTx(int idBlock, const svxTextureAt *Tx);

    /**
    @ingroup zwapi_part_facets

    Project the STL to a plane, to get its boundary curve.  
    Output new boundary curve via "idCurve".

    @param [in] idStl STL id
    @param [in] idPln plane id
    @param [in] tol refit tolerance
    @param [in] smth refit smooth
    @param [out] idCurve id of STL boundary curve (NULL to ignore)

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
    extern evxErrors cvxPartProjStl(int idStl, int idPln, double tol, double smth, int *idCurve);

    //====================================================================================================================
    /** @name Face Facets */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_facets

    Outputs a list of the triangular facets used to display
    the specified face.

    Memory for "Facets" is allocated by this function. It  
    MUST be deallocated by the calling procedure with cvxMemFree().

    It is assumed the specified face (idFace) resides in the active part.

    @param [in] idFace face id
    @param [out] Count number of triangular facets
    @param [out] Facets list of triangular facets

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqFaceFacets(int idFace, int *Count, svxTriangle **Facets);

    /**
    @ingroup zwapi_part_facets

    Outputs the facets used to display the specified face along with  
    display, texture or shader attributes that may be defined for the  
    face.

    This function allocates memory for lists inside the  
    input "Facets" structure. The calling procedure is  
    responsible to free the lists using cvxFacetsFree(Facets).

    It is assumed the specified face (idFace) resides in the active part.

    The following is sample code for retrieving and traversing a face's
    facet data:

    @code
       void TestApi(void){
       int k= 0, num, i1, i2, i3, idFace;
       svxFacets Fct;
       svxPointf v1, v2, v3;
       svxPointf n1, n2, n3;
       svxPoint p1, p2;

       // get a face selection
       if (cvxGetEnt("Select face",VX_INP_FACE,0,&idFace)) return;

       // retrieve the face's facet data
       cvxPartInqFaceFacets2(idFace, &Fct);

       // traverse the triangles defined in the facet data
       for (int i=0, k=0; i < Fct.numTriStrip; i++){
          // get the number of vertices in the next triangle strip
          num = Fct.TriStrip[k++];

          // get each triangle in the triangle strip
          for (int j=0; j < (num-2); j++){
             // get the vertex indices that define the next triangle
             i1 = Fct.TriStrip[k];
             i2 = Fct.TriStrip[k+1];
             i3 = Fct.TriStrip[k+2];

             // get the triangle's vertices
             v1 = Fct.Vertex[i1];
             v2 = Fct.Vertex[i2];
             v3 = Fct.Vertex[i3];

             // get the normal at each vertex
             n1 = Fct.Normal[i1];
             n2 = Fct.Normal[i2];
             n3 = Fct.Normal[i3];

             // increment counter to start of next triangle
             ++k;
             }

          // increment counter to start of next triangle strip
          k += 2;
          }

       // free the facet data
       cvxFacetsFree(&Fct);

       return;
       }
    @endcode

    @param [in] idFace face id
    @param [out] Facets facet data set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqFaceFacets2(int idFace, svxFacets *Facets);

    /**
    @ingroup zwapi_part_facets

    Outputs a list of the triangular facets used to display
    the specified face at specified chord height.

    Memory for "Facets" is allocated by this function. It  
    MUST be deallocated by the calling procedure with cvxMemFree().

    It is assumed the specified face (idFace) resides in the active part.

    @note
    if the idFace is planar,  ChordHeight is invalid for this function.

    @param [in] idFace face id
    @param [in] ChordHeight chord height for facet generation(min = 0.001, )
    @param [out] Count number of triangular facets
    @param [out]  Facets list of triangular facets

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqFaceFacetsByChord(int idFace, double ChordHeight, int *Count, svxTriangle **Facets);

    /**
    @ingroup zwapi_part_facets

    Initialize the parameters of the cvxPartInqFaceFacets2ByTol().

    @note
    Do not assign a value to variable "data" before calling this function.  
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data refine facets data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartRefineFacetsInit(svxRefineFacets *data);

    /**
    @ingroup zwapi_part_facets

    Outputs the facets used to display the specified face along with  
    display, texture or shader attributes that may be defined for the  
    specified face at specifies RefineData.

    This function allocates memory for lists inside the  
    input "Facets" structure. The calling procedure is  
    responsible to free the lists using cvxFacetsFree(Facets).

    It is assumed the specified face (RefineData.listFaceId) resides in the active part.

    If the value of chord height and angle exceeds the specified range,  
    the default value will be used instead.

    @note
    If the face is planar,  ChordHeight(VX_FACETS_TOL_DISTANCE,VX_FACETS_TOL_PIXEL)
    and angle(VX_FACETS_TOL_ANGLE) are ignored.

    Structure svxRefineFacets can be initialized through interface cvxPartRefineFacetsInit().

    @param [in] RefineData refine facets data 
    @param [out] Facets facet data set 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqFaceFacets2ByTol(svxRefineFacets *RefineData, svxFacets *Facets);

#ifdef _WIN64
    /**
    @ingroup zwapi_part_facets

    Outputs a list of the triangular facets used to display  
    the specified face at specified chord control type and side length.

    Memory for "pnts" is allocated by this function. It  
    MUST be deallocated by the calling procedure with cvxMemFree().

    It is assumed the specified face (idFace) resides in the active part.

    @note
    this function outputs only the points of triangles, the Normal
    of svxTriangle is not output.

    @param [in] idFace index of face
    @param [in] chord chordal control type(0.01 as default, 0.01-1)
    @param [in] sideSize the side length
    @param [out] count count of svxTriangle
    @param [out]  pnts points of triangle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartFaceMesh(int idFace, double chord, double sideSize, int *count, svxTriangle **pnts);

    /**
    @ingroup zwapi_part_facets

    Outputs a list of the triangular facets' points of the specified face  
    at specified chord control type and side length. (no repeat points)

    Memory for "pnts" is allocated by this function. It  
    MUST be deallocated by the calling procedure with cvxMemFree().

    It is assumed the specified face (idFace) resides in the active part.

    @param [in] idFace index of face
    @param [in] chord chordal control type(0.01 as default, 0.01-1)
    @param [in] sideSize the side length
    @param [out] count count of points
    @param [out] pnts points list of all triangles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartFaceMeshPnts(int idFace, double chord, double sideSize, int *count, svxPoint **pnts);
#endif

    //====================================================================================================================
    /** @name svxFacets and svxSTL Convert*/
    //====================================================================================================================

    /**
    @ingroup zwapi_part_facets

    The structure svxFacets is converted into the structure svxSTL.

    @param [in] facets facet data
    @param [out] stl STL data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartFacetsConvertToSTL(const svxFacets *facets, svxSTL *stl);

    /**
    @ingroup zwapi_part_facets

    Structures svxFacets and svxSTL are converted to each other.

    @param [in] stl STL data
    @param [out] facets facet data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartSTLConvertToFacets(const svxSTL *stl, svxFacets *facets);

    //====================================================================================================================
    /** @name Facets Free */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_facets

    Frees memory associated with the specified facets structure.

    @param [in] Facets 3D facets data structure

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxFacetsFree(svxFacets *Facets);

    /**
    @ingroup zwapi_part_facets

    Frees memory associated with the specified STL structure.

    @param [in] Stl 3D "STL" triangle mesh data structure

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxStlFree(svxSTL *Stl);

    //====================================================================================================================
    /** @name Edge Display data */
    //====================================================================================================================

    /**
    @ingroup zwapi_part_facets

    Get the display data of the edge in different modes.

    @note
    The calling procedure MUST deallocate the output(data) with cvxPartEdgeDispDataFree().

    @param [in] idEdge  edge id
    @param [out] data   display data of edge

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
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartEdgeDispData(int idEdge, svxEdgeDispData *data);

    /**
    @ingroup zwapi_part_facets

    Frees memory associated with the specified svxEdgeDispData structure.

    @param [in] data   display data of edge

    */
    extern void cvxPartEdgeDispDataFree(svxEdgeDispData *data);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FACETS_H */
