/**
 * Project \
 */


#ifndef _EXTENDEDFEEDBACK_H
#define _EXTENDEDFEEDBACK_H

#include "SearchFeedback.h"


class ExtendedFeedback: public SearchFeedback {
public: 
    
    /**
     * @param feedback
     */
    void setFeedback(int feedback);
};

#endif //_EXTENDEDFEEDBACK_H