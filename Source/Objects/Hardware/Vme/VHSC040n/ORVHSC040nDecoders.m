//
//  ORVHSC040nDecoders.m
//  Orca
//
//  Created by Mark Howe on Mon Sept 13,2010.
//  Copyright (c) 2010 University of North Carolina. All rights reserved.
//-----------------------------------------------------------
//This program was prepared for the Regents of the University of 
//North Carolina Physics and Department sponsored in part by the United States 
//Department of Energy (DOE) under Grant #DE-FG02-97ER41020. 
//The University has certain rights in the program pursuant to 
//the contract and the program should not be copied or distributed 
//outside your organization.  The DOE and the University of 
//North Carolina reserve all rights in the program. Neither the authors,
//University of North Carolina, or U.S. Government make any warranty, 
//express or implied, or assume any liability or responsibility 
//for the use of this software.
//-------------------------------------------------------------

#import "ORVHSC040nDecoders.h"
#import "ORDataPacket.h"
#import "ORDataSet.h"
#import "ORDataTypeAssigner.h"

//------------------------------------------------------------------------------------------------
// Data Format
//xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
//^^^^ ^^^^ ^^^^ ^^-----------------------data id
//                 ^^ ^^^^ ^^^^ ^^^^ ^^^^-length in longs
//
// xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx
//                          ^^^^ ^^^^ ^^^^- device id
// xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx  time in seconds since Jan 1, 1970
// xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx  StatusWord for channel 0
// xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx  EventStatusWord for channel 0
// xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx  actual Voltage chan 0 encoded as a float
// xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx  actual Current chan 0 encoded as a float
//channel 1-11 follow.
//-----------------------------------------------------------------------------------------------

@implementation ORVHSC040nDecoderForHVStatus

- (uint32_t) decodeData:(void*)someData fromDecoder:(ORDecoder*)aDecoder intoDataSet:(ORDataSet*)aDataSet
{
	uint32_t value = *((uint32_t*)someData);
    return ExtractLength(value);	
}

- (NSString*) dataRecordDescription:(uint32_t*)dataPtr
{
    NSString* theString =  @"VHSC040n HV Controller\n\n";               
	int ident = dataPtr[1] & 0xfff;
	theString = [theString stringByAppendingFormat:@"Unit %d\n",ident];
	
	NSDate* date = [NSDate dateWithTimeIntervalSince1970:(NSTimeInterval)dataPtr[2]];
	theString = [theString stringByAppendingFormat:@"%@\n",date];
	union {
		float asFloat;
		uint32_t asLong;
	}theData;
	
	int i;
	int index = 3;
	for(i=0;i<12;i++){
		theString = [theString stringByAppendingFormat:@"--------------------------\n"];
		theString = [theString stringByAppendingFormat:@"Channel %d\n",i];
		theString = [theString stringByAppendingFormat:@"Status Words 0x%02x  0x%02x\n",dataPtr[index],dataPtr[index+1]];
		index +=2;
		theData.asLong = dataPtr[index++]; //act Voltage 0
		theString = [theString stringByAppendingFormat:@"Act Voltage: %.1f\n",theData.asFloat];
		theData.asLong = dataPtr[index++]; //act Current 0
		theString = [theString stringByAppendingFormat:@"Act Current: %.1f\n",theData.asFloat];
	}
	return theString;
	
}

@end

