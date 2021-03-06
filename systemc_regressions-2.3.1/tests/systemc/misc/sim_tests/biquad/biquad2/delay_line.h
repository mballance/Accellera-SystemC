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

  delay_line.h -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

/* Filename delay_line.h */
/* This is the interface file for synchronous process `delay_line' */

#include "systemc.h"

SC_MODULE( delay_line )
{
  SC_HAS_PROCESS( delay_line );

  sc_in_clk clk;

  sc_in<float>  in;
  sc_out<float> out;

  const int delay; //internal variable
  float *line; // delay line

  // Constructor 
  delay_line( sc_module_name NAME,
	      sc_clock& CLK,
	      sc_signal<float>& IN1,
	      sc_signal<float>& OUT1,
	      int DELAY=4 ) : delay(DELAY)
  {
    clk(CLK);
    in(IN1); out(OUT1); 
	SC_CTHREAD( entry, clk.pos() );
    line = new float[delay];
  }

  // Process functionality in member function below
  void entry();
};
