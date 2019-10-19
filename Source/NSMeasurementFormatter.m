
/* Implementation of class NSMeasurementFormatter
   Copyright (C) 2019 Free Software Foundation, Inc.
   
   By: heron
   Date: Mon Sep 30 15:58:21 EDT 2019

   This file is part of the GNUstep Library.
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02111 USA.
*/

#include <Foundation/NSMeasurementFormatter.h>
#include <Foundation/NSLocale.h>
#include <Foundation/NSMeasurement.h>
#include <Foundation/NSNumberFormatter.h>
#include <Foundation/NSUnit.h>

@implementation NSMeasurementFormatter

- (NSMeasurementFormatterUnitOptions) unitOptions
{
  return _unitOptions;
}

- (void) setUnitOptions: (NSMeasurementFormatterUnitOptions) unitOptions
{
  _unitOptions = unitOptions;
}
  
- (NSFormattingUnitStyle) unitStyle
{
  return _unitStyle;
}

- (void) setUnitStyle: (NSFormattingUnitStyle)style
{
  _unitStyle = style;
}

- (NSLocale *) locale
{
  return _locale;
}

- (void) setLocale: (NSLocale *)locale
{
  ASSIGNCOPY(_locale, locale);
}

- (NSNumberFormatter *) numberFormatter
{
  return _numberFormatter;
}

- (void) setNumberFormatter: (NSNumberFormatter *)numberFormatter
{
  ASSIGNCOPY(_numberFormatter, numberFormatter);
}
  
- (NSString *)stringFromMeasurement: (NSMeasurement *)measurement
{
  return nil;
}

- (NSString *)stringFromUnit: (NSUnit *)unit
{
  return nil;
}


@end
