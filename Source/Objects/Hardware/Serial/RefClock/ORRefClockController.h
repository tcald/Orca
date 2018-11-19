//--------------------------------------------------------
// ORRefClockController
// Created by Mark  A. Howe on Fri Jul 22 2005 / Julius Hartmann, KIT, November 2017
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

#pragma mark ***Imported Files

#import "ORMotoGPSController.h"
#import "ORSynClockController.h"

@class ORValueBarGroupView;

@interface ORRefClockController : OrcaObjectController
{
    IBOutlet ORMotoGPSController*  motoGPSController;
    IBOutlet ORSynClockController* synClockController;

    IBOutlet NSTextField*   portNameField;
    IBOutlet NSTextField*   portStateField;
    IBOutlet NSButton*      openPortButton;

    IBOutlet NSButton*      lockButton;
    IBOutlet NSButton*		verboseCB;
    IBOutlet NSButton*      statusPollBothCB;
    
    IBOutlet ORValueBarGroupView*    queueBarGraph;

}

#pragma mark ***Initialization
- (id) init;
- (void) awakeFromNib;


#pragma mark ***Notifications
- (void) registerNotificationObservers;
- (void) updateWindow;
- (void) setButtonStates;
- (void) checkGlobalSecurity;

#pragma mark ***Interface Management
- (void) lockChanged:(NSNotification*)aNotification;
- (void) portNameChanged:(NSNotification*)aNotification;
- (void) portStateChanged:(NSNotification*)aNotification;
- (void) verboseChanged:(NSNotification*)aNote;
- (void) statusPollChanged:(NSNotification*)aNote;

#pragma mark ***Actions
- (IBAction) openPortAction:(id)sender;
- (IBAction) lockAction:(id) sender;
- (IBAction) verboseAction:(id)sender;
- (IBAction) portNameAction:(id)sender;
- (IBAction) statusPollAction:(id)sender;

#pragma mark •••Data Source for queue
- (double) doubleValue;

@end
