/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2014 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.accellera.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  fx_ufix_limits_double.cpp -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

// This may look like C code, but it is really -*- C++ -*-
// 
// fx_ufix_limits.cxx -- 
// Copyright Synopsys 1998
// Author          : Ric Hilderink
// Created On      : Fri Jan  8 14:30:41 1999
// Status          : none
// 


#include <limits.h>
#include <float.h>
#include <math.h>
#define SC_INCLUDE_FX
#include "systemc.h"

#define SHOW(a) out << #a << " : " << a.to_string(SC_HEX) << "\n"
#define SHOW_EXP(a) { res = a; out << #a << " : " << res.to_string(SC_HEX) << "\n"; }


#define SHOW_EXPRS(a, b) \
  SHOW_EXP(a b zero_min);   \
  SHOW_EXP(a b zero_plus);  \
  SHOW_EXP(a b zero);       \
  SHOW_EXP(a b long_max);   \
  SHOW_EXP(a b long_min);   \
  SHOW_EXP(a b int_max);    \
  SHOW_EXP(a b int_min);    \
  SHOW_EXP(a b uint_max);   \
  SHOW_EXP(a b ulong_max);  \
  SHOW_EXP(a b double_min); \
  SHOW_EXP(a b double_max); \
  SHOW_EXP(a b float_min);  \
  SHOW_EXP(a b float_max);  

#define SHOW_EXPS(a) \
  SHOW_EXPRS(a, /) \
  SHOW_EXPRS(a, *) \
  SHOW_EXPRS(a, +) \
  SHOW_EXPRS(a, -) \
  SHOW_EXPRS(a, >)							      \
  SHOW_EXPRS(a, <)							      \
  SHOW_EXPRS(a, >=)							      \
  SHOW_EXPRS(a, <=)							      \
  SHOW_EXPRS(a, ==)							      \
  SHOW_EXPRS(a, !=)							      \
  SHOW_EXPRS(a, * a *)


void test_fx_ufix_limits_double(ostream& out)
{
  out << "****************** limits fx_ufix_double\n";

  sc_ufix zero_min("-0");     SHOW(zero_min);
  sc_ufix zero_plus("+0");    SHOW(zero_plus);
  sc_ufix zero(0);            SHOW(zero);
  
  sc_ufix long_max(LONG_MAX); SHOW(long_max);
  sc_ufix long_min(LONG_MIN); SHOW(long_min);
  sc_ufix int_max(INT_MAX);   SHOW(int_max);
  sc_ufix int_min(INT_MIN);   SHOW(int_min);
  sc_ufix uint_max(UINT_MAX); SHOW(uint_max);
  sc_ufix ulong_max(ULONG_MAX); SHOW(ulong_max);

  sc_ufix double_min(DBL_MIN); SHOW(double_min);
  sc_ufix double_max(DBL_MAX); SHOW(double_max);
  sc_ufix float_min(FLT_MIN);  SHOW(float_min);
  sc_ufix float_max(FLT_MAX);  SHOW(float_max);

  // sc_ufix res;

  // SHOW_EXPS(double_min);
  // SHOW_EXPS(double_max);
  // SHOW_EXPS(float_min);
  // SHOW_EXPS(float_max);
}
