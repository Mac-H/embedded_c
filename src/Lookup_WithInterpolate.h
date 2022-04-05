

#ifndef LOOKUP_WITH_INTERPOLATE_DOT_H
#define LOOKUP_WITH_INTERPOLATE_DOT_H

    #include <stdint.h>
    #include <stdbool.h>
    
    // _________________________________________________________________________________
    //    ____        _     _ _        ____        __ _       _ _   _                   .
    //   |  _ \ _   _| |__ | (_) ___  |  _ \  ___ / _(_)_ __ (_) |_(_) ___  _ __  ___   .
    //   | |_) | | | | '_ \| | |/ __| | | | |/ _ \ |_| | '_ \| | __| |/ _ \| '_ \/ __|  .
    //   |  __/| |_| | |_) | | | (__  | |_| |  __/  _| | | | | | |_| | (_) | | | \__ \  .
    //   |_|    \__,_|_.__/|_|_|\___| |____/ \___|_| |_|_| |_|_|\__|_|\___/|_| |_|___/  .
    // ---------------------------------------------------------------------------------
    //                                                                                


    #define LOOKUP_FAILURE      INT32_MIN
    #define END_OF_LIST_s32   (INT32_MIN)

    typedef enum { LI_CLIP, LI_EXTRAPOLATE, LI_GIVE_ERROR } teInterpolateEdgeBehaviour;
    #define teInterpolateEdgeBehaviour_ENUM_LIST  "LI_CLIP\0" "LI_EXTRAPOLATE\0" "LI_GIVE_ERROR\0" "\0"

    
    int32_t Utils_Sign_s32(int32_t value);
    int32_t Lookup_Interpolate(int32_t x, const int32_t* x_list, const int32_t* y_list, teInterpolateEdgeBehaviour outOfRangeBehaviour);
    
#endif


