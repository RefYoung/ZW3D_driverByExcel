/**
@file zwapi_cmd_direct_edit_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Direct Edit Command functions.
*/
/**
@defgroup zwapi_cmd_direct_edit_data Direct Edit Commands Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the Direct Edit Command functions.
*/

#pragma once
#ifndef ZW_API_DIRECT_EDIT_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_DIRECT_EDIT_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Modify Data */
    //====================================================================================================================

    /**
    @brief part or assembly DE(Direct Edit) move or copy method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEMoveCopyType
    {
        VX_DE_MOVE_PNT_TO_PNT = 1, /**<@brief move or copy entities point to point */
        VX_DE_MOVE_ALONG_DIR  = 2, /**<@brief move or copy entities along a dirction */
        VX_DE_MOVE_FRAME      = 3, /**<@brief move or copy entities by aligning frame */
        VX_DE_MOVE_PATH       = 4, /**<@brief move or copy entities along path */
        VX_DE_MOVE_AROUND_DIR = 5, /**<@brief rotate entities around a dirction */
        VX_DE_MOVE_DYNAMIC    = 6, /**<@brief dynamic move or copy */
    } evxDEMoveCopyType;

    /**
    @brief part or assembly DE(Direct Edit) move overflow method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEFaceOverflow
    {
        VX_DE_OVERFLOW_AUTO,    /**<@brief automatic */
        VX_DE_OVERFLOW_CHANGE,  /**<@brief extend change face */
        VX_DE_OVERFLOW_STATION, /**<@brief extend stationary face */
        VX_DE_OVERFLOW_CAP,     /**<@brief extend cap face */
    } evxDEFaceOverflow;

    /**
    @brief part or assembly DE(Direct Edit) move or copy frame method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEMoveCopyFrame
    {
        VX_DE_MOVE_FRAME_NATURAL, /**<@brief natural */
        VX_DE_MOVE_FRAME_PATH,    /**<@brief at path */
        VX_DE_MOVE_FRAME_SELECT,  /**<@brief selected */
    } evxDEMoveCopyFrame;
 
    /**
    @brief part or assembly DE(Direct Edit) move or copy Z-spine method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEMoveCopyZSpine
    {
        VX_DE_MOVE_Z_NATURAL,  /**<@brief natural */
        VX_DE_MOVE_Z_SPINE,    /**<@brief spine */
        VX_DE_MOVE_Z_PARALLEL, /**<@brief parallel */
    } evxDEMoveCopyZSpine;

    /**
    @brief part or assembly DE(Direct Edit) move or copy X-orient method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEMoveCopyXOrient
    {
        VX_DE_MOVE_X_NATURAL, /**<@brief natural */
        VX_DE_MOVE_X_PLANE,   /**<@brief guide plane */
        VX_DE_MOVE_X_CURVE,   /**<@brief x-axis curve */
    } evxDEMoveCopyXOrient;

    /**
    @brief part or assembly DE(Direct Edit) move data
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef struct svxDEMove
    {
        evxDEMoveCopyType type;     /**<@brief DE(Direct Edit) move type */
        int numEnt;                 /**<@brief number of face entities need to be used DE(Direct Edit) move command */
        int *idEnts;                /**<@brief list id of face entities need to be used DE(Direct Edit) move command */
        evxDEFaceOverflow overflow; /**<@brief DE(Direct Edit) overflow type.default:VX_DE_OVERFLOW_AUTO */
        union svxDEMoveData         /**<@brief union of DE move type */
        {
            struct svxDEMoveDyn /**<@brief dynamic move type */
            {
                int handle;        /**<@brief whether to move handle only (0 = no, 1 = yes).Default:0 */
                svxPoint position; /**<@brief the position of handle direction
                                        user can adjust the handle position or move, copy, rotate entities */
                svxVector x;       /**<@brief the x axis of handle direction.default:(1,0,0) */
                svxVector y;       /**<@brief the y axis of handle direction.default:(0,1,0) */
                svxVector z;       /**<@brief the z axis of handle direction.default:(0,0,1) */
            } dynamic;
            struct svxDEMovePnt /**<@brief move entities point to point type */
            {
                svxPntOnEnt fromPnt; /**<@brief the start point of DE(Direct Edit) move */
                svxPntOnEnt toPnt;   /**<@brief the end point of DE(Direct Edit) move
                                        the relative position of toPnt and moved entities and the relative position 
                                        of fromPnt and old entities are same */
                svxPntOnEnt fromVec; /**<@brief the from vector */
                svxPntOnEnt toVec;   /**<@brief the to vector
                                        the old entities rotate from fromVec to toVec, get the move entities */
            } point;
            struct svxDEMoveDir /**<@brief move along a direction type */
            {
                svxPntOnEnt dir; /**<@brief the direction of DE(Direct Edit) move
                                        the move entities is move along the direction */
                double dist;     /**<@brief the distance of DE(Direct Edit) move.default:0
                                        the entities move distance along the direction */
                double ang;      /**<@brief the angle of DE(Direct Edit) move.default:0
                                        the entities rotation angle around the dir */
                int angOption;   /**<@brief whether to use angle (0 = no, 1 = yes) Default:1 */
            } direction;
            struct svxDEMoveRotate /**<@brief rotate around a direction type */
            {
                svxPntOnEnt dir;  /**<@brief the direction of DE(Direct Edit) move
                                        the move entities is move along the direction */
                svxPntOnEnt axis; /**<@brief the direction of rotation */
                double ang;       /**<@brief the rotate angle of rotation.default:0
                                        the entities rotate around axis about ang */
            } rotate;
            struct svxDEMoveFrame /**<@brief move by aligning frame type */
            {
                int fromFrmae; /**<@brief the from frame id of DE(Direct Edit) move */
                int toFrmae;   /**<@brief the to frame id of DE(Direct Edit) move */
            } frame;
            struct svxDEMovePath /**<@brief move along path type */
            {
                svxPntOnEnt pathPnt; /**<@brief the point on the path entities 
                                            the entities move to the point pathPnt project on entities along the path */
                svxPntOnEnt toPnt;   /**<@brief the to point of DE(Direct Edit) move*/

                evxDEMoveCopyFrame frame; /**<@brief frame type.default:VX_DE_MOVE_FRAME_PATH */
                int idSwp;                /**<@brief the id of swp frame 
                                            if frame = VX_DE_MOVE_FRAME_SELECT, the swp frame is given by idSwp
                                            other frame type can be null */

                evxDEMoveCopyZSpine zSpine; /**<@brief Z spine type.default:VX_DE_MOVE_Z_NATURAL */
                int idCrv;                  /**<@brief the curve of spine
                                            if zSpine = VX_DE_MOVE_Z_SPINE, the curve is given by idCrv
                                            other zSpine type can be null */
                svxPntOnEnt planeZ;         /**<@brief the vector of plane
                                            if zSpine = VX_DE_MOVE_Z_PARALLEL, it is the point on parallel plane
                                            other type can be null */

                evxDEMoveCopyXOrient xOrient; /**<@brief X orient type.default:VX_DE_MOVE_X_NATURAL */
                svxPntOnEnt planeX;           /**<@brief the vector of plane
                                            if xOrient = VX_DE_MOVE_X_PLANE, it is the point on guide plane
                                            other type can be null */
                svxPntOnEnt crv;              /**<@brief the point on x-axis curve entity
                                            if xOrient = VX_DE_MOVE_X_CURVE, it is the point on x-axis curve
                                            other type can be null */
            } path;
        } move;
    } svxDEMove;

    /**
    @brief part or assembly DE(Direct Edit) align move method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEAlignMoveType
    {
        VX_DE_ALIGN_MOVE_COPLANAR      = 1, /**<@brief coplanar */
        VX_DE_ALIGN_MOVE_CONCENTRIC    = 2, /**<@brief concentric */
        VX_DE_ALIGN_MOVE_TANGENT       = 3, /**<@brief tangent */
        VX_DE_ALIGN_MOVE_PARALLEL      = 4, /**<@brief parallel */
        VX_DE_ALIGN_MOVE_PERPENDICULAR = 5, /**<@brief perpendicular */
        VX_DE_ALIGN_MOVE_ANGLE         = 6, /**<@brief at angle */
        VX_DE_ALIGN_MOVE_SYMMETRY      = 7, /**<@brief symmetric */
    } evxDEAlignMoveType;

    /**
    @brief part or assembly DE(Direct Edit) align move data
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef struct svxDEAlignMove
    {
        evxDEAlignMoveType type;    /**<@brief DE(Direct Edit) align move type */
        int idMotion;               /**<@brief id of the motion face entity */
        int idStation;              /**<@brief id of the stationary entity 
                                        if type = VX_DE_ALIGN_MOVE_COPLANAR, entity should be plane face or datum plane 
                                        if type = VX_DE_ALIGN_MOVE_CONCENTRIC, entity should be circle face or curve 
                                        if type = VX_DE_ALIGN_MOVE_TANGENT, entity should be face or datum plane 
                                        if type = VX_DE_ALIGN_MOVE_PARALLEL or VX_DE_ALIGN_MOVE_PERPENDICULAR, 
                                                entity should be edge or plane face or datum plane 
                                        if type = VX_DE_ALIGN_MOVE_ANGLE or VX_DE_ALIGN_MOVE_SYMMETRY, 
                                                entity should be face or datum plane */
        int numEnt;                 /**<@brief number of motion group face entities */
        int *idEnts;                /**<@brief list id of motion group face entities, can be null */
        svxPntOnEnt thruPnt;        /**<@brief through point 
                                        if type > VX_DE_ALIGN_MOVE_CONCENTRIC and type < VX_DE_ALIGN_MOVE_SYMMETRY,
                                        the through point is given by user.
                                        other type can be null */
        double angle;               /**<@brief angle.default:0
                                        if type = VX_DE_ALIGN_MOVE_ANGLE, it is the angle of align move.
                                        other type can be null */
        int idPlane;                /**<@brief id of symmetry plane. 
                                        if type = VX_DE_ALIGN_MOVE_SYMMETRY, the symmetry plane can be face of entity or datum plane,
                                        other type can be null*/
        evxDEFaceOverflow overflow; /**<@brief DE(Direct Edit) overflow type.default:VX_DE_OVERFLOW_AUTO */
    } svxDEAlignMove;

    /**
    @brief part or assembly DE(Direct Edit) dim move method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEDimMoveType
    {
        VX_DE_DIM_LINEAR  = 1, /**<@brief linear */
        VX_DE_DIM_ANGULAR = 2, /**<@brief angular */
    } evxDEDimMoveType;

    /**
    @brief part or assembly DE(Direct Edit) dim move data
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef struct svxDEDimMove
    {
        evxDEDimMoveType type;      /**<@brief DE(Direct Edit) align move type */
        int idMotion;               /**<@brief id of the motion face entity */
        int idStation;              /**<@brief id of the stationary entity */
        int isSwitch;               /**<@brief switch point and entity.(0/1)
                                        if type=VX_DE_DIM_ANGULAR, ignore it.*/
        svxPoint stationPnt;        /**<@brief if type=VX_DE_DIM_LINEAR and isSwitch=1,apply it. else ignore it.
                                        this point must be on the surface of idStation. */
        int numEnt;                 /**<@brief number of motion group face entities */
        int *idEnts;                /**<@brief list id of motion group face entities */
        double dist;                /**<@brief the dim move distance.default:0
                                        if type = VX_DE_DIM_LINEAR, the distance is given by user
                                        other type can be null */
        svxPntOnEnt anchorPnt;      /**<@brief through point 
                                        if type = VX_DE_DIM_LINEAR, the point is given by user, can be null */
        svxPntOnEnt dir;            /**<@brief measure direction
                                        if type = VX_DE_DIM_LINEAR, the direction is given by user, can be null */
        double angle;               /**<@brief angle.default:0 
                                        if type = VX_DE_DIM_ANGULAR, it is the angle of align move
                                        other type can be null */
        evxDEFaceOverflow overflow; /**<@brief DE(Direct Edit) overflow type.default:VX_DE_OVERFLOW_AUTO */
    } svxDEDimMove;

    /**
    @brief part or assembly DE(Direct Edit) side face method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDESideFaceType
    {
        VX_DE_SIDE_FACE_NO_CREATE, /**<@brief do not create */
        VX_DE_SIDE_FACE_CREATE,    /**<@brief create */
    } evxDESideFaceType;

    /**
    @brief part or assembly DE(Direct Edit) intersection method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEIsectType
    {
        VX_DE_ISECT_NO_REMOVE, /**<@brief do not remove */
        VX_DE_ISECT_REMOVE,    /**<@brief remove */
    } evxDEIsectType;

    /**
    @brief part or assembly DE(Direct Edit) face offset data
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef struct svxDEOffset
    {
        int numEnt;                  /**<@brief number of face entities to set offset */
        int *idEnts;                 /**<@brief list id of face entities to set offset */
        double dist;                 /**<@brief the offset distance.default:0 */
        evxDESideFaceType side;      /**<@brief side face type.default:VX_DE_SIDE_FACE_CREATE */
        evxDEIsectType intersection; /**<@brief intersection.default:VX_DE_ISECT_NO_REMOVE */
        evxDEFaceOverflow overflow;  /**<@brief DE(Direct Edit) overflow type.default:VX_DE_OVERFLOW_AUTO */
    } svxDEOffset;

    /**
    @brief part or assembly DE(Direct Edit) draft about side method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEDraftSideType
    {
        VX_DE_DRAFT_SIDE_TOP,     /**<@brief top */
        VX_DE_DRAFT_SIDE_BOTTOM,  /**<@brief bottom */
        VX_DE_DRAFT_SIDE_SPILT,   /**<@brief split */
        VX_DE_DRAFT_SIDE_NEUTRAL, /**<@brief neutral */
    } evxDEDraftSideType;

    /**
    @brief part or assembly DE(Direct Edit) draft data
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef struct svxDEDraft
    {
        int numFace;                /**<@brief number of face entities to draft */
        int *idFaces;               /**<@brief list id of face entities to draft */
        int numDraft;               /**<@brief number of edge entities on the draft face*/
        int *idDrafts;              /**<@brief list id of edge entities on the draft face */
        double angle;               /**<@brief the draft angle.default:0 */
        svxPntOnEnt dir;            /**<@brief the draft direction */
        evxDEDraftSideType side;    /**<@brief the type of side to draft.default:VX_DE_DRAFT_SIDE_SPILT */
        int numEdge;                /**<@brief number of parting edge entities to terminate draft */
        int *idEgdes;               /**<@brief list id of parting edge entities to terminate draft */
        evxDEFaceOverflow overflow; /**<@brief DE(Direct Edit) overflow type.default:VX_DE_OVERFLOW_AUTO */
    } svxDEDraft;

    //====================================================================================================================
    /** @name Reuse Data */
    //====================================================================================================================

    /**
    @brief part or assembly DE(Direct Edit) copy data
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef struct svxDECopy
    {
        evxDEMoveCopyType type; /**<@brief DE(Direct Edit) copy type */
        int numEnt;             /**<@brief number of face entities need to be used DE(Direct Edit) copy command */
        int *idEnts;            /**<@brief list id of face entities need to be used DE(Direct Edit) copy command */
        union svxDECopyData     /**<@brief Union of DE copy data */
        {
            struct svxDECopyDyn /**<@brief dynamic copy type */
            {
                int handle;        /**<@brief whether to copy handle only (0 = no, 1 = yes).default:0 */
                svxPoint position; /**<@brief the position of handle direction
                                            user can adjust the handle position to move,copy or rotate entities */
                svxVector x;       /**<@brief the x axis of handle direction.default:(1,0,0) */
                svxVector y;       /**<@brief the y axis of handle direction.default:(0,1,0) */
                svxVector z;       /**<@brief the z axis of handle direction.default:(0,0,1) */
            } dynamic;
            struct svxDECopyPnt /**<@brief copy entities point to point type */
            {
                svxPntOnEnt fromPnt; /**<@brief the start point of DE(Direct Edit) copy */
                int cntToPnt;        /**<@brief count of toPnt */
                svxPntOnEnt *toPnt;  /**<@brief the end point of DE(Direct Edit) copy.
                                            the relative position of toPnt and copy entities and the relative position .
                                            of fromPnt and old entities are same */
                svxPntOnEnt fromVec; /**<@brief the from vector */
                svxPntOnEnt toVec;   /**<@brief the to vector
                                            the old entities rotate from fromVec to toVec, get the copy entities */
            } point;
            struct svxDECopyDir /**<@brief copy along a direction type */
            {
                svxPntOnEnt dir; /**<@brief the direction of DE(Direct Edit) copy.
                                            the copy entities is copy along the direction */
                double dist;     /**<@brief the distance of DE(Direct Edit) copy.default:0.
                                            the entities copy distance along the direction */
                int useAng;      /**<@brief whether to use angle (0 = no, 1 = yes).default:1 */
                double ang;      /**<@brief the angle of DE(Direct Edit) copy.default:0.
                                            the entities rotation angle around the dir */
                int useCopies;   /**<@brief whether to have more than one copies (0 = no, 1 = yes).default:1 */
                int copies;      /**<@brief the copies of DE(Direct Edit) copy.default:1 */
            } direction;
            struct svxDECopyRotate /**<@brief rotate around a direction type */
            {
                svxPntOnEnt dir; /**<@brief the direction of DE(Direct Edit) copy.
                                            the copy entities is copy along the direction */
                double ang;      /**<@brief the rotate angle of rotation.default:0
                                            the entities rotate around axis about ang */
                int useCopies;   /**<@brief whether to have more than one copies (0 = no, 1 = yes).default:1 */
                int copies;      /**<@brief the copies of DE(Direct Edit) copy.default:1 */
            } rotate;
            struct svxDECopyFrame /**<@brief copy by aligning frame type */
            {
                int fromFrmae; /**<@brief the from frame id of DE(Direct Edit) copy */
                int cnt;       /**<@brief number of toFrames */
                int *toFrmaes; /**<@brief the to frame id of DE(Direct Edit) move */
            } frame;
            struct svxDECopyPath /**<@brief copy along path type */
            {
                svxPntOnEnt pathPnt; /**<@brief the point on the path entities .
                                            the entities copy to the point pathPnt project on entities along the path */
                int numPnt;          /**<@brief number of the to point of DE(Direct Edit) copy*/
                svxPntOnEnt *toPnt;  /**<@brief list of the to point of DE(Direct Edit) copy*/

                evxDEMoveCopyFrame frame; /**<@brief frame type.default:VX_DE_MOVE_FRAME_NATURAL */
                int idSwp;                /**<@brief the id of swp frame .
                                            if frame = VX_DE_MOVE_FRAME_SELECT, the swp frame is given by idSwp
                                            other frame type can be null */

                evxDEMoveCopyZSpine zSpine; /**<@brief Z spine type.default:VX_DE_MOVE_Z_NATURAL */
                int idCrv;                  /**<@brief the curve of spine.
                                            if zSpine = VX_DE_MOVE_Z_SPINE, the curve is given by idCrv
                                            other zSpine type can be null */
                svxPntOnEnt planeZ;         /**<@brief the vector of plane.
                                            if zSpine = VX_DE_MOVE_Z_PARALLEL, it is the point on parallel plane
                                            other type can be null */

                evxDEMoveCopyXOrient xOrient; /**<@brief X orient type.default:VX_DE_MOVE_X_NATURAL */
                svxPntOnEnt planeX;           /**<@brief the vector of plane
                                            if xOrient = VX_DE_MOVE_X_PLANE, it is the point on guide plane
                                            other type can be null */
                svxPntOnEnt crv;              /**<@brief the point on x-axis curve entity.
                                            if xOrient = VX_DE_MOVE_X_CURVE, it is the point on x-axis curve.
                                            other type can be null */
            } path;
        } copy;
    } svxDECopy;

    /**
    @brief part or assembly DE(Direct Edit) mirror data
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef struct svxDEMirror
    {
        int numEnt;   /**<@brief number of face entities need to be used DE(Direct Edit) mirror command */
        int *idEnts;  /**<@brief list id of face entities need to be used DE(Direct Edit) mirror command */
        int idPlane;  /**<@brief the id of symmetric plane, it should be datum plane, planar face or sketch */
        int original; /**<@brief whether keep the original entities (0 = no, 1 = yes).default:1
                                        0 - the entities move to the symmetRic place
                                        1 - copy a symmetRic entities */
    } svxDEMirror;

    /**
    @brief part or assembly DE(Direct Edit) pattern method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEPtnType
    {
        VX_DE_PTN_LINEAR,   /**<@brief linear */
        VX_DE_PTN_CIRCULAR, /**<@brief circular */
        VX_DE_PTN_POINT,    /**<@brief point to point */
        VX_DE_PTN_PATTERN,  /**<@brief at pattern */
        VX_DE_PTN_CURVE,    /**<@brief at curve */
        VX_DE_PTN_FACE,     /**<@brief at face */
    } evxDEPtnType;

    /**
    @brief part or assembly DE(Direct Edit) pattern derive method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEPtnDerive
    {
        VX_DE_PTN_DERIVE_NONE,    /**<@brief none */
        VX_DE_PTN_DERIVE_SPACING, /**<@brief spacing */
        VX_DE_PTN_DERIVE_NUMBER,  /**<@brief number  */
    } evxDEPtnDerive;

    /**
    @brief part or assembly DE(Direct Edit) pattern at curve method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEPtnCrv
    {
        VX_DE_PTN_CRV1,     /**<@brief one curve */
        VX_DE_PTN_CRV2_TGT, /**<@brief two curves together */
        VX_DE_PTN_CRV2_ACR, /**<@brief two curves across */
        VX_DE_PTN_CRV3,     /**<@brief three or four curves */
    } evxDEPtnCrv;

    /**
    @brief part or assembly DE(Direct Edit) pattern boundary method
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef enum evxDEPtnBound
    {
        VX_DE_PTN_BOUND_AUTO,  /**<@brief auto */
        VX_DE_PTN_BOUND_PLACE, /**<@brief in place */
        VX_DE_PTN_BOUND_MOVE,  /**<@brief move */
    } evxDEPtnBound;

    /**
    @brief part or assembly DE(Direct Edit) pattern data
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef struct svxDEPattern
    {
        evxDEPtnType type; /**<@brief DE(Direct Edit) pattern type */
        int numEnt;        /**<@brief number of face entities need to be used DE(Direct Edit) pattern command */
        int *idEnts;       /**<@brief list id of face entities need to be used DE(Direct Edit) pattern command */
        union svxDEPtnData /**<@brief union of De pattern data */
        {
            struct svxDEPtnLinear /**<@brief linear DE(Direct Edit) pattern type */
            {
                svxPntOnEnt dir[2]; /**<@brief the direction of the pattern */
                int num[2];         /**<@brief the number of entity on two direction.default:(2,1) */
                double spacing[2];  /**<@brief the spacing between entity on two direction.default:(20,20) */
                int stagger;        /**<@brief whether use stagger pattern (0 = no stagger, 1 = stagger pattern).default:0 */
            } linear;
            struct svxDEPtnCircular /**<@brief circular DE(Direct Edit) pattern type */
            {
                svxPntOnEnt dir;       /**<@brief the direction of the pattern */
                double diameter;       /**<@brief the diameter between the base entity and the first entity of pattern.default:0 */
                double ang;            /**<@brief the angle between direction and next direction.default:45
                                        the next direction is given by dir and ang */
                int num[2];            /**<@brief the number of pattern.default:(2,1)
                                        the 1st number is how many direction to form pattern
                                        the 2nd number is the number of entities on all direction */
                double spacing;        /**<@brief the spacing between entities in pattern on two direction.default:20 */
                evxDEPtnDerive derive; /**<@brief the derive type.default:VX_DE_PTN_DERIVE_NONE */
                double min;            /**<@brief the minimum spacing.default:0
                                        drops out instances that do not have the minimum spacing */
                int stagger;           /**<@brief whether use stagger pattern (0 = no stagger, 1 = stagger pattern).default:0 */
                int align;             /**<@brief the alignment type(0 = align with base, 1= align with pattern).default:1 */
            } circular;
            struct svxDEPtnPoint /**<@brief point to point DE(Direct Edit) pattern type */
            {
                svxPntOnEnt fromPnt; /**<@brief the from point of pattern */
                int numTo;           /**<@brief number of to point */
                svxPntOnEnt *toPnts; /**<@brief the list of to point */
                int align;           /**<@brief the alignment type(0 = align with base, 1= align with pattern).default:1 */
                int idFace;          /**<@brief the id of on face entity.idFace<=0 to ignore.
                                        the face that you want the pattern to be located on */
            } point;
            struct svxDEPtnPattern /**<@brief at pattern DE(Direct Edit) pattern type */
            {
                int idPattern; /**<@brief the id of pattern feature */
            } pattern;
            struct svxDEPtnCurve /**<@brief at curve(s) DE(Direct Edit) pattern type */
            {
                evxDEPtnCrv crvType;   /**<@brief the curve method.default:VX_DE_PTN_CRV1 */
                int numBound;          /**<@brief number of boundary entities
                                        if type = 1, numBound = 1
                                        if type = 2 or 3, numBound = 2
                                        if type = 4, numBound = 4 */
                int *pBounds;          /**<@brief the list id of boundary entities */
                int num[2];            /**<@brief the number of entity on two direction.default:(2,1) */
                double spacing[2];     /**<@brief the spacing between entity on two direction.default:(20,20) */
                evxDEPtnDerive derive; /**<@brief the derive type.default:VX_DE_PTN_DERIVE_NONE */
                double min;            /**<@brief the minimum spacing.default:0
                                        drops out instances that do not have the minimum spacing */
                int stagger;           /**<@brief whether use stagger pattern (0 = no stagger, 1 = stagger pattern).default:0 */
                int align;             /**<@brief the alignment type(0 = align with base, 1= align with pattern).default:1 */
                int idFace;            /**<@brief the id of on face entity.idFace<=0 to ignore.
                                        the face that you want the pattern to be located on */
                int useFromPnt;        /**<@brief 1 if use fromPnt, else 0. default:0 */
                svxPntOnEnt fromPnt;   /**<@brief the from point, pick a point where the pattern starts from */
                evxDEPtnBound bound;   /**<@brief the boundary type */
            } curve;
            struct svxDEPtnFace /**<@brief at face DE(Direct Edit) pattern type */
            {
                int idFace;            /**<@brief the id of on face entity
                                        the face that you want the pattern to be located on */
                int num[2];            /**<@brief the number of entity on two direction.default:(2,1) */
                double spacing[2];     /**<@brief the spacing between entity on two direction.default:(20,20) */
                evxDEPtnDerive derive; /**<@brief the derive type.default:VX_DE_PTN_DERIVE_NONE */
                double min;            /**<@brief the minimum spacing.default:0
                                        drops out instances that do not have the minimum spacing */
                int stagger;           /**<@brief whether use stagger pattern (0 = no stagger, 1 = stagger pattern).default:0 */
                int align;             /**<@brief the alignment type(0 = align with base, 1= align with pattern).default:1 */
                int useFromPnt;        /**<@brief 1 if use fromPnt, else 0. default:0 */
                svxPntOnEnt fromPnt;   /**<@brief the from point, pick a point where the pattern starts from */
                evxDEPtnBound bound;   /**<@brief the boundary type */
            } face;
        } ptn;
        int cntSkip;          /**<@brief number of the instances to be skipped */
        int *firstTogglePos;  /**<@brief the position id of the patterned entities in the first direction (start form 0, the nTH position in the first direction)  
                                        if type = 1 or 2 or 5 or 6, it can given by user  
                                        other type can be null */
        int *secondTogglePos; /**<@brief the position id of the patterned entities in the second direction (start form 0, the nTH position in the second direction)
                                        can be null if just pattern the first direction.  
                                        such as: linear.num = {3,2}, linear.dir[0]  = {1,0,0}, linear.dir[1] = {0, 1, 0}   
                                        y    
                                        ^ O O *      if the '*' should be skipped, firstTogglePos[0] = 2, secondTogglePos[0] = 1   
                                        | O & O      if the '&' should be skipped, firstTogglePos[0] = 1, secondTogglePos[0] = 0   
                                        |-------> x    
                                     */
    } svxDEPattern;

    //====================================================================================================================
    /** @name Resize Data */
    //====================================================================================================================

    /**
    @brief part or assembly DE(Direct Edit) modify fillet data
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef struct svxDEFllt
    {
        int numEnt;    /**<@brief number of fillet entities need to be edited command */
        int *idEnts;   /**<@brief list id of fillet entities need to be edited command */
        double R;      /**<@brief the edit radius of fillet.default:5 */
        int chain;     /**<@brief whether to chain pick with same R(0 = no, 1 = yes).default:0 */
        double relief; /**<@brief the relief of fillet.default:0 */
        int arcType;   /**<@brief the arc type of fillet(0 = circular, 1 = conic).default:0 */
        double ratio;  /**<@brief the conic ratio .default:0.5.   
                                        if arcType = 1, it can be given by user .   
                                        other type can be null */
        int hold;      /**<@brief whether to hold fillet to edge(0 = no, 1 = yes).default:0 */
        int strategy;  /**<@brief closing strategy.default:0.  
                                        0 - auto.   
                                        1 - selected */
        int numEdge;   /**<@brief number of list edge or direction entities*/
        int *idEgdes;  /**<@brief list id of list edge or direction entities */
    } svxDEFllt;

    /**
    @brief part or assembly DE(Direct Edit) modify radius data
    @ingroup zwapi_cmd_direct_edit_data
    */
    typedef struct svxDERad
    {
        int numEnt;  /**<@brief number of face entities need to be edited radius command */
        int *idEnts; /**<@brief list id of face entities need to be edited radius command */
        double R;    /**<@brief the edit radius of face.default:1 */
    } svxDERad;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DATUM_DATA_H */
