/*=========================================================================

  Program:   OpenIGTLink Library
  Module:    $HeadURL: http://svn.na-mic.org/NAMICSandBox/trunk/OpenIGTLink2_beta/Source/igtlSensorMessage.h $
  Language:  C++
  Date:      $Date: 2009-12-16 23:58:02 -0500 (Wed, 16 Dec 2009) $
  Version:   $Revision: 5466 $

  Copyright (c) Insight Software Consortium. All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#ifndef __igtlSensorMessage_h
#define __igtlSensorMessage_h

#include <string>

#include "igtlObject.h"
#include "igtlMath.h"
#include "igtlMessageBase.h"
#include "igtlTypes.h"

#include "igtlUnit.h"

namespace igtl
{

class IGTLCommon_EXPORT SensorMessage: public MessageBase
{
public:
  typedef SensorMessage                  Self;
  typedef MessageBase                    Superclass;
  typedef SmartPointer<Self>             Pointer;
  typedef SmartPointer<const Self>       ConstPointer;

  igtlTypeMacro(igtl::SensorMessage, igtl::MessageBase);
  igtlNewMacro(igtl::SensorMessage);

public:

  int          SetLength(unsigned int n);
  unsigned int GetLength();

  //int        SetStatus(int i);
  int          SetUnit(igtlUnit unit);
  int          SetUnit(igtl::Unit * unit);
  igtlUnit     GetUnit();
  int          GetUnit(igtl::Unit * unit);

  int          SetValue(igtlFloat64 * data);       // Set sensor values from array of 64-bit floating data
  int          SetValue(unsigned int i, igtlFloat64 value); // Set i-th sensor value
  igtlFloat64  GetValue(unsigned int i);      // Get i-th sensor value

protected:
  SensorMessage();
  ~SensorMessage();
  
protected:

  virtual int  GetBodyPackSize();
  virtual int  PackBody();
  virtual int  UnpackBody();
  
  igtlUint8    m_Length;  // Length of sensor array
  igtlUint8    m_Status;  // Sensor status (Reserved)
  igtlUnit     m_Unit;    // Unit (generated by igtl::Unit::Pack())
  
  std::vector<igtlFloat64> m_Array;

};


} // namespace igtl

#endif // _igtlSensorMessage_h


