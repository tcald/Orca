//--------------------------------------------------------
// ORVXMModel
// Created by Mark  A. Howe on Fri Jul 22 2005
// Code partially generated by the OrcaCodeWizard. Written by Mark A. Howe.
// Copyright (c) 2005 CENPA, University of Washington. All rights reserved.
//-----------------------------------------------------------
//This program was prepared for the Regents of the University of 
//Washington at the Center for Experimental Nuclear Physics and 
//Astrophysics (CENPA) sponsored in part by the United States 
//Department of Energy (DOE) under Grant #DE-FG02-97ER41020. 
//The University has certain rights in the program pursuant to 
//the contract and the program should not be copied or distributed 
//outside your organization.  The DOE and the University of 
//Washington reserve all rights in the program. Neither the authors,
//University of Washington, or U.S. Government make any warranty, 
//express or implied, or assume any liability or responsibility 
//for the use of this software.
//-------------------------------------------------------------

#define kVXMIdle					0
#define kVXMPendingGoingHome		1
#define kVXMGoingHome				2
#define kVXMPendingRelative			3
#define kVXMMovingRelative			4
#define kVXMPendingMovingAbsolute	5
#define kVXMMovingAbsolute			6
#define kVXMStateUnknown			7

@interface ORVXMMotor : NSObject
{
    @private
		id				owner;
		int				motorId;
		int				targetPosition;
		int				motorPosition;
        int				oldMotorPosition;
		int				fullScale;
        float			conversion;
        int				motorSpeed;
		BOOL			motorEnabled;
		BOOL			absoluteMotion;
        int             motorType;
        NSString*       axis;
        BOOL            sentMotorType;
}

#pragma mark ***Accessors
- (id) initWithOwner:(id)anOwner motorNumber:(int)aMotorId;
- (id)	 owner;
- (void) setOwner:(id)anObj;
- (void) setMotorId:(int)anId;
- (int) motorId;
- (BOOL) motorEnabled;
- (void) setMotorEnabled:(BOOL)aState;
- (BOOL) absoluteMotion;
- (void) setAbsoluteMotion:(BOOL)aState;
- (float) conversion;
- (void) setConversion:(float)aStepsPerMillimeter;
- (int) fullScale;
- (void) setFullScale:(int)aFullScale;
- (int) motorPosition;
- (void) setMotorPosition:(int)aPosition;
- (int) motorSpeed;
- (void) setMotorSpeed:(int)aSpeed;
- (int) motorType;
- (void) setMotorType:(int)aType;
- (BOOL) hasMoved;
- (int) targetPosition;
- (void) setTargetPosition:(int)aPosition;
- (NSString*) axis;
- (void) setAxis:(NSString*)aString;
- (BOOL) sentMotorType;
- (void) setSentMotorType:(BOOL)aState;

@end

extern NSString* ORVXMMotorAbsMotionChanged;
extern NSString* ORVXMMotorSpeedChanged;
extern NSString* ORVXMMotorLastMotorQueryChanged;
extern NSString* ORVXMMotorEnabledChanged;
extern NSString* ORVXMMotorConversionChanged;
extern NSString* ORVXMMotorFullScaleChanged;
extern NSString* ORVXMMotorPositionChanged;
extern NSString* ORVXMMotorTargetChanged;
extern NSString* ORVXMMotorTypeChanged;
