/**
@file zwapi_cmd_freeform_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Free
Form Command functions.
*/
/**
@defgroup zwapi_cmd_freeform_data Free Form Commands Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the Free
Form Command functions.
*/

#pragma once
#ifndef ZW_API_FREEFORM_FTR_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_FREEFORM_FTR_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Basic Face */
    //====================================================================================================================
    /**
    @brief spine type
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxSpineType
    {
        VX_SPINE_NATURAL  = 0, /**<@brief  no drive curve is used */
        VX_SPINE_SPINE    = 1, /**<@brief  a spine curve will be used as the drive curve */
        VX_SPINE_PARALLEL = 2, /**<@brief  the face is created by moving an infinite plane containing cross-sections of the face parallel to a plane */
    } evxSpineType;

    /**
    @brief cross-section type
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxCroSecType
    {
        VX_CRO_SEC_CIRCULAR = 0, /**<@brief  create the face using circular arc cross-sections */
        VX_CRO_SEC_CONIC    = 1, /**<@brief  create the face using conic arc cross-sections */
        VX_CRO_SEC_G2BLEND  = 2, /**<@brief  create the face using G2 Blend cross-sections */
        VX_CRO_SEC_G3BLEND  = 3, /**<@brief  create the face using G3 Blend cross-sections */
    } evxCroSecType;

    /**
    @brief sewing type
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxSewingType
    {
        VX_SEWING_NOACTION = 0, /**<@brief  leave the base faces as is */
        VX_SEWING_DIVIDE   = 1, /**<@brief  divide the base faces at the fillet tangents */
        VX_SEWING_TRIM     = 2, /**<@brief  divide and trim away the base faces at the fillet tangents */
        VX_SEWING_SEW      = 3, /**<@brief  divide, trim and sew the base faces with the fillet faces */
    } evxSewingType;

    /**
    @brief capping type
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxCappingType
    {
        VX_CAPPING_MAXIMAL = 0, /**<@brief  trim the fillet to the wider pair of face boundaries */
        VX_CAPPING_MINIMAL = 1, /**<@brief  trim the fillet to the narrower pair of face boundaries */
        VX_CAPPING_TANGENT = 2, /**<@brief  create a blended curve matching the tangency of the boundaries of the two supporting faces */
    } evxCappingType;

    /**
    @brief freeForm filletBlend data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxFilletBlendData
    {
        /*  Required */
        int type;                /**<@brief  whether to create an intelligent blend face with a specified radius (0 = without radius, 1 = with radius) */
        svxPntOnEntPath from;    /*!<@brief  select the first (from) curve or face */
        svxPntOnEntPath to;      /*!<@brief  select the second (to) curve or face */
        svxPntOnEntPath through; /*!<@brief  this field is available only if type = 0. select the curve or face to pass through or you can enter a fillet radius */
        double radius;           /**<@brief  this field is available only if type = 1. if Blend with a Radius is selected, use this to specify the desired radius of the blend face */
        /*  Orientation */
        evxSpineType spineType; /**<@brief  specify the drive curve method */
        int idCurve;            /**<@brief  this field is available only if spineType = VX_SPINE_SPINE. select a curve to be used as the spine */
        svxVector plane;        /**<@brief  this field is available only if spineType = VX_SPINE_PARALLEL. select a parallel plane */
        /*  Shape of Blend */
        evxCroSecType croSecType; /**<@brief  specify the arc type that will define the cross-sectional shape of the face */
        double conicRatio;        /**<@brief  this field is available only if croSecType = VX_CRO_SEC_CONIC (the range of 0 - 1. default = 0.5) */
        double startWeight;       /**<@brief  this field is available only if croSecType = VX_CRO_SEC_G2BLEND or VX_CRO_SEC_G3BLEND */
        double endWeight;         /**<@brief  this field is available only if croSecType = VX_CRO_SEC_G2BLEND or VX_CRO_SEC_G3BLEND */
        /*  Sew */
        int sewShapes; /**<@brief  whether to sew the shapes automatically (0 = not sew, 1 = sew. default = 1) 
                                           since R2024, it doesn't sew the new shapes and if user set it to 1, it will create a 'Sew' feature to sew the shapes */
        int numShapes; /**<@brief  this field is available only if sewShapes = 1. the number of the sewed shapes */
        int *idShapes; /**<@brief  this field is available only if sewShapes = 1. the shapes to be sewed */
        /*  Settings */
        evxSewingType sewingType;   /**<@brief  options to modify the supporting faces */
        evxCappingType cappingType; /**<@brief  methods of trimming the ends of the fillets */
    } svxFilletBlendData;

    /**
    @brief N-SIDED
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxRefitOpt
    {
        VX_REFIT_NO        = 0, /**<@brief  none */
        VX_REFIT_TANGENT   = 1, /**<@brief  tangent */
        VX_REFIT_CURVATURE = 2, /**<@brief  curvature */
        VX_REFIT_DIRECT    = 3, /**<@brief  direct */
    } evxRefitOpt;

    /**
    @brief template command N-sided data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxNSidedData
    {
        int numCrv;        /**<@brief  count of the paths */
        int *pCrv;         /**<@brief  id of curves */
        int *pCrvParent;   /**<@brief  parent index of curves (-1/NULL to ignore) */
        int sewShape;      /**<@brief  flag to sew shapes or not. 1 = to sew , (default) 
                                        since R2024, it doesn't sew the new shapes and if user set it to 1, it will create a 'Sew' feature to sew the shapes */
        int numShape;      /**<@brief  count of the shapes, valid if sewShape set to 1, can be ignored */
        int *pShape;       /**<@brief  index of the shapes, valid if sewShape set to 1, can be ignored */
        int tangent;       /**<@brief  tangent at boundary , 0 = no (default), 1 = tangent */
        evxRefitOpt refit; /**<@brief  enum for Refit options, 0 = no, 1 = tangent , 2 = curvature, 3 = direct (default) */
        double dTol;       /**<@brief  Tolerance, 0.01 (default) */
    } svxNSidedData;

    /**
    @brief template command Trimmed Plane data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxTrimPlnData
    {
        int cntCrv;      /**<@brief  count of input curve(required)*/
        int *pCrvList;   /**<@brief  input curve id list(required)*/
        int idProf;      /**<@brief  id of profile if pCrvList are 2d curves, else -1/0 as the initialized value */
        char sew;        /**<@brief  flag of sew or not(1-sew, else 0)*/
        int cntBool;     /**<@brief  count of boolean shapes(0 to ignore)*/
        int *pBooolList; /**<@brief  list boolean shapes(null to ignore)*/
        int idPlane;     /**<@brief  id of reference plane(-1/0 to ignore)*/
    } svxTrimPlnData;


    /**
    @brief ruled data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxRuledData
    {
        svxPntOnEntPath firstCrv;  /*!<@brief  select the first curve */
        svxPntOnEntPath secondCrv; /*!<@brief  select the second curve */
        svxPntOnEntPath spineCrv;  /*!<@brief  select the spine curve */
        int trimPlane;             /**<@brief  whether to attempt trimmed plane (1 as default) */
    } svxRuledData;

    /**
    @brief circular bi rail method
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxCircularBiRailMethod
    {
        VX_CIRCULARBIRAIL_CONSTANT = 0, /**<@brief  with constant radius between the two path curves */
        VX_CIRCULARBIRAIL_VARIABLE,     /**<@brief  with variable radius between the two path curves */
        VX_CIRCULARBIRAIL_CENTER,       /**<@brief  radius is defined implicitly by a center curve */
        VX_CIRCULARBIRAIL_MIDDLE,       /**<@brief  radius is defined implicitly by a middle curve */
    } evxCircularBiRailMethod;

    /**
    @brief radius set data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxRadiusSetData
    {
        int idCurve;         /**<@brief  set the curve */
        svxPntOnEntPath pnt; /*!<@brief  set the point */
        double radius;       /**<@brief  set the radius */
        int radiusFlat;      /**<@brief  whether to mark the radius as flat */
    } svxRadiusSetData;

    /**
    @brief circular bi rail data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxCircularBiRailData
    {
        evxCircularBiRailMethod method; /**<@brief  method to create a new circular face (VX_CIRCULARBIRAIL_CONSTANT as default) */
        svxPntOnEntPath firstCrv;       /*!<@brief  select the first path curve */
        svxPntOnEntPath secondCrv;      /*!<@brief  select the second path curve */
        svxPntOnEntPath spineCrv;       /*!<@brief  select the spine curve */
        union evxCircularBiRailInpUnion
        {
            struct CircularBiRailConstant
            {
                double radius; /**<@brief  constant radius */
                int solution;  /**<@brief  multiple solutions will be displayed */
            } constant;
            struct CircularBiRailVariable
            {
                int solution;              /**<@brief  multiple solutions will be displayed */
                int nRadSet;               /**<@brief  the count of list */
                svxRadiusSetData *pRadSet; /**<@brief  store spines list with different radius */
            } variable;
            struct CircularBiRailCenter
            {
                svxPntOnEntPath center; /*!<@brief  select the center curve */
                int solution;           /**<@brief  multiple solutions will be displayed */
            } center;
            struct CircularBiRailMiddle
            {
                svxPntOnEntPath middle; /*!<@brief  select the middle curve */
            } middle;
        } inpUnion;
    } svxCircularBiRailData;

    /**
    @brief conic bi rail method
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxConicBiRailMethod
    {
        VX_CONICBIRAIL_CONSTANT = 0, /**<@brief  with constant radius between the two path curves */
        VX_CONICBIRAIL_VARIABLE,     /**<@brief  with variable radius between the two path curves */
        VX_CONICBIRAIL_HOLDER,       /**<@brief  using a shoulder curve.*/
        VX_CONICBIRAIL_TANGENT,      /**<@brief  using a tangent curve.*/
        VX_CONICBIRAIL_INTERSECTION, /**<@brief  using a tangent curve and a shoulder curve.*/
        VX_CONICBIRAIL_CENTER,       /**<@brief  using a center curve  */
        VX_CONICBIRAIL_TANGENTEDGES, /**<@brief  tangent to two existing face edges. */
    } evxConicBiRailMethod;

    /**
    @brief conic bi rail data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxConicBiRailData
    {
        evxConicBiRailMethod method; /**<@brief  method to create a new conic face (VX_CONICBIRAIL_CONSTANT as default) */
        svxPntOnEntPath firstCrv;    /*!<@brief  select the first path curve */
        svxPntOnEntPath secondCrv;   /*!<@brief  select the second path curve */
        svxPntOnEntPath spineCrv;    /*!<@brief  select the spine curve */
        union evxConicBiRailInpUnion
        {
            struct ConicBiRailConstant
            {
                double radius; /**<@brief  constant radius */
                double ratio;  /**<@brief  conic ratio */
                int solution;  /**<@brief  multiple solutions will be displayed */
            } constant;
            struct ConicBiRailVariable
            {
                int nRadSet;               /**<@brief  the count of list */
                svxRadiusSetData *pRadSet; /**<@brief  store spines list with different radius */
                double ratio;              /**<@brief  conic ratio */
                int solution;              /**<@brief  multiple solutions will be displayed */
            } variable;
            struct ConicBiRailHolder
            {
                svxPntOnEntPath holder; /*!<@brief  select the shoulder curve */
                double ratio;           /**<@brief  conic ratio */
            } holder;
            struct ConicBiRailTangent
            {
                svxPntOnEntPath tangent; /*!<@brief  select the tangent curve */
                double ratio;            /**<@brief  conic ratio */
            } tangent;
            struct ConicBiRailIntersection
            {
                svxPntOnEntPath holder;  /*!<@brief  select the shoulder curve */
                svxPntOnEntPath tangent; /*!<@brief  select the tangent curve */
            } intersection;
            struct ConicBiRailCenter
            {
                svxPntOnEntPath center; /**<@brief  select the center curve */
                double ratio;           /**<@brief  conic ratio */
            } center;
            struct ConicBiRailTangentEdges
            {
                double ratio; /**<@brief  conic ratio */
            } tangentEdges;
        } inpUnion;
    } svxConicBiRailData;

    //====================================================================================================================
    /** @name Edit Face */
    //====================================================================================================================
    /**
    @brief faces offset data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxFcsOffsetData
    {
        int count;     /**<@brief  count of "faces" */
        int *faces;    /**<@brief  list of face id */
        double offset; /**<@brief  offset */

        int keepSurface; /**<@brief  1 is keep original surface, else 0 */
        int keepEdge;    /**<@brief  1 is keep edge connectivity, else 0 */

        /*  variable offset */
        int cnt;            /**<@brief  count of "list", cnt=0 to ignore */
        struct svxVarOffset /**<@brief  faces offset variable data */
        {
            svxPntOnEnt pntOnEnt; /**<@brief  set point on face(or edge) */
            double pntOffset;     /**<@brief  offset */
        } *list;                  /**<@brief  NULL to ignore */
    } svxFcsOffsetData;

    /**
    @brief template command Extend Face data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxExtendData
    {
        int idFace;        /**<@brief  id face (if idFace is 0/-1, it will get from the first edge ) */
        int cntEdge;       /**<@brief  count of the extend edges(0-extend all the edges of the face and the idFace must be valid */
        int *pEdgList;     /**<@brief  the edges that belonging to the face(NUll to use idFace get all the edges) */
        double *pDistList; /**<@brief  the extend distance list, every edge can be extended with a different value (NULL to use fDist) */
        double fDist;      /**<@brief  the extend distance if pDistList is NULL */
        int iMerge;        /**<@brief  merge extended face(1-merge, 0-no, initialize 1 as the default) */
        int iKeepFace;     /**<@brief  keep the original face(1-keep, 0-no, initialize 0 as the default) */
        int iExtension;    /**<@brief  extend method(0-liner, 1-reflect, 2-circular, 4-curvature diminishing, 0-default value) */
    } svxExtendData;

    /**
    @brief trim to faces
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxTrimToFacesData
    {
        int numFace;     /**<@brief Number of faces to Trim.*/
        int *pFace;      /**<@brief Id list of faces to Trim.*/
        int numTrimming; /**<@brief Number of trimming entities.*/
        int *pTrimming;  /**<@brief Id list of trimming entities.*/

        int FlipSide;       /**<@brief flag to use "Flip side to keep", 0 default*/
        int TrimWith;       /**<@brief flag to use "Trim with all simultaneously", 0 default*/
        int ExtendTrimming; /**<@brief flag to use "Extend trimming faces", 0 default*/
        int KeepTrimming;   /**<@brief flag to use "Keep trimming faces", 1 default*/
    } svxTrimToFacesData;

    /**
    @brief projection types of "trim to curves"
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxTrimCrvsProjtype
    {
        VX_TRIMCRV_IN_PLACE,       /**<@brief  in place(none) */
        VX_TRIMCRV_FACE_NORMAL,    /**<@brief  face normal */
        VX_TRIMCRV_DIRECTED,       /**<@brief  directed */
        VX_TRIMCRV_BI_DIRECTIONAL, /**<@brief  bi-directional */
    } evxTrimCrvsProjtype;

    /**
    @brief template command Trim to Curves input data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxTrimToCurvesData
    {
        int cntFcs;         /**<@brief  count of idFaces */
        int *idFaces;       /**<@brief  list of id face */
        int cntCrvs;        /**<@brief  count of idCurves */
        int *idCurves;      /**<@brief  list of id curve */
        int toKeep;         /**<@brief  0 is faces to keep, 1 is faces to remove */
        int cntPnts;        /**<@brief  count of sides */
        svxPntOnEnt *sides; /**<@brief  point on ent */

        /*  Settings */
        evxTrimCrvsProjtype projection; /**<@brief  projection */
        svxVector *dirction;            /**<@brief  direction, NULL to ignore */
        int isCheckerboard;             /**<@brief  1 is trim to checkerboard, else 0 */
        int isExtend;                   /**<@brief  1 is extend curves to boundary, else 0 */
    } svxTrimToCurvesData;

    /**
    @brief data of explode command
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxExplodeData
    {
        int numFace; /**<@brief Number of selected faces.*/
        int *pFace;  /**<@brief Id list of faces to explode.*/

        int ConnectFc; /**<@brief flag to use Group connected faces, 0 default*/
        int RebudEdge; /**<@brief flag to use Rebuild edges along boundary, 1 default*/
    } svxExplodeData;

    /**
    @brief faces sew data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxSewData
    {
        double tol;      /**<@brief  tolerance value, default(0.01) */
        char multEdg;    /**<@brief  enable multiple edge matching or not*/
        char forceClose; /**<@brief  force object to sew into solid */
    } svxSewData;

    /**
    @brief face extension type
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxFaceExtType
    {
        VX_FACE_EXT_LINEAR = 0,                /**<@brief linear */
        VX_FACE_EXT_REFLECT,                   /**<@brief reflect */
        VX_FACE_EXT_CIRCULAR,                  /**<@brief circular */
        VX_FACE_EXT_CURVATURE_DIMINISHING = 4, /**<@brief curvature diminishing */
    } evxFaceExtType;

    /**
    @brief enlarge face data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxEnlargeFaceData
    {
        int idFace;               /**<@brief  index of face to enlarge */
        int applyAll;             /**<@brief  whether all the edges will be extended the same distance (0 as default) */
        double distance;          /**<@brief  the distance to enlarge, used only when applyAll is 1 */
        double u0;                /**<@brief  set u0 to extend one edge, used only when applyAll is 0 */
        double u1;                /**<@brief  set u1 to extend one edge, used only when applyAll is 0 */
        double v0;                /**<@brief  set v0 to extend one edge, used only when applyAll is 0 */
        double v1;                /**<@brief  set v1 to extend one edge, used only when applyAll is 0 */
        int keepOriginal;         /**<@brief  whether to keep original face (1 as default) */
        evxFaceExtType extension; /**<@brief  extension type (VX_FACE_EXTENSION_LINEAR as default) */
    } svxEnlargeFaceData;

    /**
    @brief extend shape type
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxExtendShapeMethod
    {
        VX_EXTEND_OPEN_SHAPE    = 0, /**<@brief  extend open shape */
        VX_EXTEND_GENERAL_SHAPE = 1, /**<@brief  extend general shape */
    } evxExtendShapeMethod;

    /**
    @brief edge extension type
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxEdgeExtensionType
    {
        VX_EDGE_EXTENSION_TANGENT = 0, /**<@brief  tangent */
        VX_EDGE_EXTENSION_ORTHOGONAL,  /**<@brief  orthogonal */
    } evxEdgeExtensionType;

    /**
    @brief extend face method
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxExtendFaceMethod
    {
        VX_EXTEND_FACE_NONE = 0,         /**<@brief  none */
        VX_EXTEND_FACE_CLOSE_ENTIRE_GAP, /**<@brief  close entire gap */
        VX_EXTEND_FACE_DIRECT_EDIT,      /**<@brief  direct edit */
    } evxExtendFaceMethod;

    /**
    @brief extend shape data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxExtendShapeData
    {
        evxExtendShapeMethod method; /**<@brief  method to extend shape (VX_EXTEND_OPEN_SHAPE as default) */
        double distance;             /**<@brief  specify the distance to extend. */

        union evxExtendShapeInpUnion
        {
            struct ExtendOpenShape
            {
                int nEdges;                 /**<@brief  count of edges to extend */
                int *idEdges;               /**<@brief  list of edges to extend */
                evxExtendFaceMethod option; /**<@brief  extension open face option (VX_EXTEND_FACE_NONE as default) */
                int nFaces;                 /**<@brief  count of faces to extend to (0 to ignore), used only when option is VX_EXTEND_FACE_DIRECT_EDIT */
                int *idFaces;               /**<@brief  list of faces to extend to (NULL to ignore), used only when option is VX_EXTEND_FACE_DIRECT_EDIT */
                int createFaces;            /**<@brief  whether to create new linear extension faces */
                int loftFaces;              /**<@brief  whether to create new loft extension faces */
            } open;
            struct ExtendGeneralShape
            {
                int nFaces;   /**<@brief  count of faces to extend */
                int *idFaces; /**<@brief  list of faces to extend */
                int nEdges;   /**<@brief  count of edges to extend */
                int *idEdges; /**<@brief  list of edges to extend, the edges should be the edges of the extended faces  */
            } general;
        } inpUnion;

        evxFaceExtType faceExtension;       /**<@brief  face extension type (VX_FACE_EXT_LINEAR as default) */
        evxEdgeExtensionType edgeExtension; /**<@brief  edge extension type (VX_EDGE_EXTENSION_TANGENT as default) */
    } svxExtendShapeData;

    /**
    @brief split with curve data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxSplitWithCrvData
    {
        int nFaces;                    /**<@brief  count of faces or shapes to split */
        int *idFaces;                  /**<@brief  list of faces or shapes to split */
        int nCrvs;                     /**<@brief  count of split curves (0 to use intersecting curves to split faces) */
        int *idCrvs;                   /**<@brief  list of split curves (NULL to use intersecting curves to split faces) */
        evxTrimCrvsProjtype prjMethod; /**<@brief  method to project the trimming curves onto the subject faces (VX_TRIMCRV_IN_PLACE as default) */
        svxVector direction;           /**<@brief  projection direction, used when prjMethod is VX_TRIMCRV_DIRECTED or VX_TRIMCRV_BI_DIRECTIONAL */
        int explodeEdges;              /**<@brief  whether all new edges will be unsewn from the shape (0 as default) */
        int extendCrvs;                /**<@brief  whether to automatically extend trim curves to boundary (0 as default) */
        int removeSpurs;               /**<@brief  whether to remove the excess spurs and face edges (1 as default) */
    } svxSplitWithCrvData;

    /**
    @brief curve mesh continuity type
    @ingroup zwapi_cmd_freeform_data
    */
    typedef enum evxCuveMeshCotinuityType
    {
        VX_BOUNDARY_CONSTRAINT_CONTINUITY_G0 = 0, /**<@brief  G0 */
        VX_BOUNDARY_CONSTRAINT_CONTINUITY_G1,     /**<@brief  G1 */
        VX_BOUNDARY_CONSTRAINT_CONTINUITY_G2,     /**<@brief  G2 */
        VX_BOUNDARY_CONSTRAINT_CONTINUITY_NORMAL, /**<@brief  Normal */
    } evxCuveMeshCotinuityType;

    /**
    @brief curve segment set
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxCurveSegmentSet
    {
        int numCurves;      /**<@brief  number of curve segments */
        svxEntPath *curves; /**<@brief  list of entity path of curve segments  
                                                          if the parent of the curve is a sketch or curve list, the id of sketch and curve list should be added to entity path of curve */
        int curveDir;       /**<@brief  specify the orientation of the curve (0 = from start point to end point, otherwise 1) */
    } svxCurveSegmentSet;

    /**
    @brief curve mesh data
    @ingroup zwapi_cmd_freeform_data
    */
    typedef struct svxCurveMeshData
    {
        /* Required */
        int numUCurves;              /**<@brief  number of U curves */
        svxCurveSegmentSet *uCurves; /**<@brief  list of U curves set */
        int numVCurves;              /**<@brief  number of V curves */
        svxCurveSegmentSet *vCurves; /**<@brief  list of V curves set */
        int disjointEntitiesAsNewUV; /**<@brief  whether to disjoint entities as new U/V, default as 1 */

        /* Boundary Constraint */
        evxCuveMeshCotinuityType cotinuityOfFirstU; /**<@brief  continuity type of first U face */
        int faceOfFirstU;                           /**<@brief  face id of first U */
        evxCuveMeshCotinuityType cotinuityOfLastU;  /**<@brief  continuity type of last U face */
        int faceOfLastU;                            /**<@brief  face id of last U */
        evxCuveMeshCotinuityType cotinuityOfFirstV; /**<@brief  continuity type of first V face */
        int faceOfFirstV;                           /**<@brief  face id of first V */
        evxCuveMeshCotinuityType cotinuityOfLastV;  /**<@brief  continuity type of last V face */
        int faceOfLastV;                            /**<@brief  face id of last V */

        /* Settings */
        double refitTolerance;          /**<@brief  refit tolerance, default 0.01 */
        double gapTolerance;            /**<@brief  gap tolerance, default 0.01 */
        int extendToIntersectionPoints; /**<@brief  whether to extend to intersection points, default as 1 */
    } svxCurveMeshData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FREEFORM_FTR_DATA_H */
