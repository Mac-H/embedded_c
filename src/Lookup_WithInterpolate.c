
//+===============================
//|

#include "Lookup_WithInterpolate.h"

// _____________________________________________________________________
//  ____        _     _ _        __  __      _   _               _      .
// |  _ \ _   _| |__ | (_) ___  |  \/  | ___| |_| |__   ___   __| |___  .
// | |_) | | | | '_ \| | |/ __| | |\/| |/ _ \ __| '_ \ / _ \ / _` / __| .
// |  __/| |_| | |_) | | | (__  | |  | |  __/ |_| | | | (_) | (_| \__ \ .
// |_|    \__,_|_.__/|_|_|\___| |_|  |_|\___|\__|_| |_|\___/ \__,_|___/ .
// ---------------------------------------------------------------------


int32_t Utils_Sign_s32(int32_t value)
{
    if (value < 0) return -1;
    if (value > 0) return +1;
    return 0;

}

//
// Limits: X is monotonic in table
//
int32_t Lookup_Interpolate(int32_t x, const int32_t* x_list, const int32_t* y_list, teInterpolateEdgeBehaviour outOfRangeBehaviour)
{
    //int32_t index=0;
    if ((x_list == NULL) || (x_list[0] == END_OF_LIST_s32) ||  (x_list[1] == END_OF_LIST_s32)  ) return LOOKUP_FAILURE;
    if ((y_list == NULL) || (y_list[0] == END_OF_LIST_s32) ||  (y_list[1] == END_OF_LIST_s32)  ) return LOOKUP_FAILURE;


    if (x == x_list[0]) return y_list[0];
    if (x == x_list[1]) return y_list[1];

    if ((x < x_list[0]) ==  (x_list[0] < x_list[1]))
    {
        if (outOfRangeBehaviour == LI_GIVE_ERROR)  return LOOKUP_FAILURE;
        if (outOfRangeBehaviour == LI_CLIP)        return y_list[0];
    }

    while (true)
    {
        if (x == x_list[0]) return y_list[0];
        if (x == x_list[1]) return y_list[1];
        
        if (Utils_Sign_s32(x-x_list[0]) != Utils_Sign_s32(x-x_list[1]) )
        {
            break;
        }

        if ( (x_list[2] == END_OF_LIST_s32) || (y_list[2] == END_OF_LIST_s32) )
        {
            break;
        }
        x_list++;
        y_list++;

        //index++;
    }

    if ((x > x_list[1]) ==  (x_list[1] > x_list[0]))
    {
        if (outOfRangeBehaviour == LI_GIVE_ERROR)  return LOOKUP_FAILURE;
        if (outOfRangeBehaviour == LI_CLIP)        return y_list[0];
    }
    int x_0 = x_list[0];
    int x_1 = x_list[1];

    int y_0 = y_list[0];
    int y_1 = y_list[1];

    int32_t numerator = ((x - x_0) *(y_1 - y_0));
    
    int32_t denominator = (x_1 - x_0);

    int32_t y =  y_0 + Utils_Divide_RoundNearest_s32(numerator,denominator);

    //|if (verbose)
    //|{
    //|    Terminal_printVerbose("---| Interpolate %d -> %d     x=%d  y=%d  x0=%d y0=%d x1=%d y1=%d   index=%d\n", x,y, x_0,y_0, x_1,y_1, index);
    //|}
    return y;
}

//|
//+===============================

