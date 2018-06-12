//------------------------------------------------------------------------
//  Copyright 2009-2010 (c) Jeff Brown <spadix@users.sourceforge.net>
//
//  This file is part of the ZBar Bar Code Reader.
//
//  The ZBar Bar Code Reader is free software; you can redistribute it
//  and/or modify it under the terms of the GNU Lesser Public License as
//  published by the Free Software Foundation; either version 2.1 of
//  the License, or (at your option) any later version.
//
//  The ZBar Bar Code Reader is distributed in the hope that it will be
//  useful, but WITHOUT ANY WARRANTY; without even the implied warranty
//  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser Public License for more details.
//
//  You should have received a copy of the GNU Lesser Public License
//  along with the ZBar Bar Code Reader; if not, write to the Free
//  Software Foundation, Inc., 51 Franklin St, Fifth Floor,
//  Boston, MA  02110-1301  USA
//
//  http://sourceforge.net/projects/zbar
//------------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "zbar.h"

#ifdef __cplusplus
using namespace zbar;
#endif

// Obj-C wrapper for ZBar result types

@interface ZBarSymbolSet
    : NSObject <NSFastEnumeration>
{
    const zbar_symbol_set_t *set;
    BOOL filterSymbols;
}

@property (readonly, nonatomic) int count;
@property (readonly, nonatomic) const zbar_symbol_set_t *zbarSymbolSet;
@property (nonatomic) BOOL filterSymbols;

- (instancetype)init NS_DESIGNATED_INITIALIZER;

- (instancetype) initWithSymbolSet: (const zbar_symbol_set_t*) set NS_DESIGNATED_INITIALIZER;

@end


@interface ZBarSymbol : NSObject
{
    const zbar_symbol_t *symbol;
}

@property (readonly, nonatomic) zbar_symbol_type_t type;
@property (weak, readonly, nonatomic) NSString *typeName;
@property (readonly, nonatomic) NSUInteger configMask;
@property (readonly, nonatomic) NSUInteger modifierMask;
@property (weak, readonly, nonatomic) NSString *data;
@property (readonly, nonatomic) int quality;
@property (readonly, nonatomic) int count;
@property (readonly, nonatomic) zbar_orientation_t orientation;
@property (weak, readonly, nonatomic) ZBarSymbolSet *components;
@property (readonly, nonatomic) const zbar_symbol_t *zbarSymbol;
@property (readonly, nonatomic) CGRect bounds;

- (instancetype)init NS_DESIGNATED_INITIALIZER;

- (instancetype) initWithSymbol: (const zbar_symbol_t*) symbol NS_DESIGNATED_INITIALIZER;

+ (NSString*) nameForType: (zbar_symbol_type_t) type;

@end
