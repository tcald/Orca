//
//  ORLabJackT7Decoders.h
//  Orca
//
//  Created by Mark Howe on Fri Jan 20,2017.
//  Updated by Jan Behrens on Dec 21, 2020.
//  Copyright (c) 2017-2020 University of North Carolina. All rights reserved.
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


#import "ORBaseDecoder.h"

@class ORDataPacket;
@class ORDataSet;

@interface ORLabJackT7DecoderForIOData : ORBaseDecoder {
}
- (NSString*) getUnitKey:(unsigned short)aUnit;
- (uint32_t) decodeData:(void*)someData fromDecoder:(ORDecoder*)aDecoder intoDataSet:(ORDataSet*)aDataSet;
- (NSString*) dataRecordDescription:(uint32_t*)dataPtr;
@end
