/* Interface for NSPortCoder object for distributed objects
   Copyright (C) 2000 Free Software Foundation, Inc.

   Written by:  Richard Frith-Macdonald <richard@brainstorm.co.uk>
   Date: June 2000

   This file is part of the GNUstep Base Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA.
   */

#ifndef __NSPortCoder_h
#define __NSPortCoder_h

#include <Foundation/NSCoder.h>

@class NSMutableArray;
@class NSMutableDictionary;
@class NSConnection;
@class NSPort;

@interface NSPortCoder : NSCoder
{
@private
  NSMutableArray	*_comp;
  NSConnection		*_conn;
  BOOL			_is_by_copy;
  BOOL			_is_by_ref;
// Encoding
  BOOL			_encodingRoot;
  BOOL			_initialPass;
  id			_dst;		/* Serialization destination.	*/
  IMP			_eObjImp;	/* Method to encode an id.	*/
  IMP			_eValImp;	/* Method to encode others.	*/
#ifndef	_IN_PORT_CODER_M
#define	GSIMapTable	void*
#endif
  GSIMapTable		_clsMap;	/* Class cross references.	*/
  GSIMapTable		_cIdMap;	/* Conditionally coded.		*/
  GSIMapTable		_uIdMap;	/* Unconditionally coded.	*/
  GSIMapTable		_ptrMap;	/* Constant pointers.		*/
#ifndef	_IN_PORT_CODER_M
#undef	GSIMapTable
#endif
  unsigned		_xRefC;		/* Counter for cross-reference.	*/
  unsigned		_xRefO;		/* Counter for cross-reference.	*/
  unsigned		_xRefP;		/* Counter for cross-reference.	*/
// Decoding
  id			_src;		/* Deserialization source.	*/
  IMP			_dDesImp;	/* Method to deserialize with.	*/
  void			(*_dTagImp)(id,SEL,unsigned char*,unsigned*,unsigned*);
  IMP			_dValImp;	/* Method to decode data with.	*/
#ifndef	_IN_PORT_CODER_M
#define	GSIArray	void*
#endif
  GSIArray		_clsAry;	/* Class crossreference map.	*/
  GSIArray		_objAry;	/* Object crossreference map.	*/
  GSIArray		_ptrAry;	/* Pointer crossreference map.	*/
#ifndef	_IN_PORT_CODER_M
#undef	GSIArray
#endif
  NSMutableDictionary	*_cInfo;	/* Class version information.	*/
  unsigned		_cursor;	/* Position in data buffer.	*/
  unsigned		_version;	/* Version of archiver used.	*/
  NSZone		*_zone;		/* Zone for allocating objs.	*/
}

+ (NSPortCoder*) portCoderWithReceivePort: (NSPort*)recv
				 sendPort: (NSPort*)send
			       components: (NSArray*)comp;
- (id) initWithReceivePort: (NSPort*)recv
		  sendPort: (NSPort*)send
		components: (NSArray*)comp;

- (NSConnection*) connection;
- (NSPort*) decodePortObject;
- (void) dispatch;
- (void) encodePortObject: (NSPort*)aPort;
- (BOOL) isBycopy;
- (BOOL) isByref;

@end

@interface	NSPortCoder (Private)
- (NSMutableArray*) _components;
@end


#endif /* __NSPortCoder_h */
#else
/* Interface for NSPortCoder object for distributed objects
   Copyright (C) 1997 Free Software Foundation, Inc.

   Written by:  Richard Frith-Macdonald <richard@brainstorm.co.uk>
   Date: August 1997

   This file is part of the GNUstep Base Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA.
   */

#ifndef __NSPortCoder_h
#define __NSPortCoder_h

#include <Foundation/NSCoder.h>

@class NSConnection;
@class NSPort;

@interface NSPortCoder : NSCoder
{
}

- (NSConnection*) connection;
- (NSPort*) decodePortObject;
- (void) encodePortObject: (NSPort*)aPort;
- (BOOL) isBycopy;
- (BOOL) isByref;

@end


#endif /* __NSPortCoder_h */
