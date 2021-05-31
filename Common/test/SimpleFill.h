#ifndef SimpleFill_H
#define SimpleFill_H

#include "NtuTool/Common/test/SimpleData.h"
#include <iostream>
// Class to fill a simple data structure with random numbers

class SimpleFill: public virtual SimpleData {

 public:

  SimpleFill() {
    srandom( 1 );
  }
  ~SimpleFill() override {
  }

  // Function to set variables
  void setData( int iRun, int iEvt ) {
    // It's assumed here that the ntuple content has been reset before 
    // calling this, so that the array is written from the first element
    // and std::vectors are empty
    i_run = iRun;
    i_evt = iEvt;
    int n = 4 + lround( 0.5 + ( random() * 4.0 / RAND_MAX ) );
    while ( n-- ) {
      int i = 15 + lround( 0.5 + ( random() * 10.0 / RAND_MAX ) );
      i_vec.push_back( i );
      float x = 6.0 - ( 8.0 * sqrt( -log( 1.0 - ( random() * 1.0 /
                                                  RAND_MAX ) ) ) *
                              cos( 2.0 * M_PI * ( random() * 1.0 /
                                                  RAND_MAX ) ) );
      f_vpt->push_back( x );
      i_arr[n_arr++] = i % 7;
    }
    return;
  }

 private:

  SimpleFill           ( const SimpleFill& x ) = delete;
  SimpleFill& operator=( const SimpleFill& x ) = delete;

};

#endif

