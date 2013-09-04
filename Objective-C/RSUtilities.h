//
//  RSUtilities.h
//  RevS
//
//  Created by Zebang Liu on 13-8-1.
//  Copyright (c) 2013年 Zebang Liu. All rights reserved.
//  Contact: the.great.lzbdd@gmail.com
/*
 This file is part of RevS.
 
 RevS is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 RevS is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with RevS.  If not, see <http://www.gnu.org/licenses/>.
 */


#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>

/*
  This class implements all kinds of utility methods.
*/

@interface RSUtilities : NSObject

/*
  Returns an array of strings containing the public and private addresses of all the neighbors.The strings are formatted like this:publicAddress,privateAddress.
*/
+ (NSArray *)localIpList;

/*
  Only returns the online neighbors' addresses.
*/
+ (NSArray *)onlineNeighbors;

/*
  Returns the neighbors with the highest probability value.The "k" value is the count of the addresses you want.
*/
+ (NSArray *)contactListWithKValue:(NSInteger)k;

/*
  Returns the local IP address in the local network.(Possibly something like 192.168.0.101)
*/
+ (NSString *)privateIpAddress;

/*
  Returns the device's public Ip address.
*/
+ (NSString *)publicIpAddress;

/*
  Returns the public IP in a string in an array returned by [RSUtilities localIpList],[RSUtilities onlineNeighbors],[RSUtilities contactListWithKValue:k]
*/
+ (NSString *)publicIpInString:(NSString *)string;

/*
 Returns the private IP in a string in an array returned by [RSUtilities localIpList],[RSUtilities onlineNeighbors],[RSUtilities contactListWithKValue:k]
 */
+ (NSString *)privateIpInString:(NSString *)string;

/*
  Returns the SHA-1 hash from the given string.
*/
+ (NSString *)hashFromString:(NSString *)string;

//+ (NSArray *)listOfHashedFilenames;
/*
  Returns a list of all the files under the "STORED_DATA_DIRECTORY" defined in RSConstants.h
*/
+ (NSArray *)listOfFilenames;

/*
  Returns the free disk space left in bytes.
*/
+ (uint64_t)freeDiskspace;

/*
  Returns the device's unique identifier,generated by hashing a string formatted like this:"localPublicIP,localPrivateIP"
*/
+ (NSString *)deviceID;

/*
  Use this method to determine whether the device's IP is different from the one the server have.
*/
+ (BOOL)ipHasChanged;

/*
  Update the saved IP hash.
*/
+ (void)updateIPHash;

/*
 
*/
+ (NSArray *)connectedAddresses;

/*
 
*/
+ (void)addConnectedAddress:(NSString *)address;

/*

*/
+ (void)removeConnectedAddress:(NSString *)address;

@end