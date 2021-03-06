//--------------------------------------------------------
// ORLakeShore210Controller
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

#pragma mark ***Imported Files

@class ORCompositeTimeLineView;
@class ORSerialPortController;

@interface ORLakeShore210Controller : OrcaObjectController
{
    IBOutlet NSTextField*   lockDocField;
	IBOutlet NSButton*		shipTemperaturesButton;
    IBOutlet NSTextField*   tempUnitsField;
	IBOutlet NSMatrix*		unitsTypeMatrix;
    IBOutlet NSButton*      lockButton;
    IBOutlet NSPopUpButton* pollTimePopup;
    IBOutlet NSButton*      readTempsButton;
    IBOutlet NSMatrix*      tempMatrix;
    IBOutlet NSMatrix*      timeMatrix;
	IBOutlet NSTableView*	processLimitTableView;
	IBOutlet ORCompositeTimeLineView*	plotter0;
	IBOutlet ORCompositeTimeLineView*	plotter1;
    IBOutlet ORSerialPortController* serialPortController;
}

#pragma mark ***Initialization
- (id) init;
- (void) dealloc;
- (void) awakeFromNib;

#pragma mark ***Notifications
- (void) registerNotificationObservers;
- (void) updateWindow;
- (void) setUpFormats;

#pragma mark ***Interface Management
- (void) updateTimePlot:(NSNotification*)aNotification;
- (void) scaleAction:(NSNotification*)aNotification;
- (void) shipTemperaturesChanged:(NSNotification*)aNotification;
- (void) lockChanged:(NSNotification*)aNotification;
- (void) tempChanged:(NSNotification*)aNotification;
- (void) pollTimeChanged:(NSNotification*)aNotification;
- (void) unitsTypeChanged:(NSNotification*)aNotification;
- (void) miscAttributesChanged:(NSNotification*)aNotification;
- (void) scaleAction:(NSNotification*)aNotification;
- (void) loadTempTimeValuesForIndex:(int)index;
- (void) highLimitChanged:(NSNotification*)aNote;
- (void) highAlarmChanged:(NSNotification*)aNote;

#pragma mark ***Actions
- (IBAction) shipTemperaturesAction:(id)sender;
- (IBAction) unitsTypeAction:(id)sender;
- (IBAction) lockAction:(id) sender;
- (IBAction) readTempsAction:(id)sender;
- (IBAction) pollTimeAction:(id)sender;

#pragma mark ***Plotter Data Source
- (int) numberPointsInPlot:(id)aPlotter;
- (void) plotter:(id)aPlotter index:(int)i x:(double*)xValue y:(double*)yValue;

#pragma mark ***Pressure Table Data Source
- (NSInteger)numberOfRowsInTableView:(NSTableView *)aTableView;
- (id) tableView:(NSTableView *) aTableView objectValueForTableColumn:(NSTableColumn *) aTableColumn
			 row:(NSInteger) rowIndex;

@end


